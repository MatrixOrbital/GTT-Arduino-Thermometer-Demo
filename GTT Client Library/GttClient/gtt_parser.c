#include <gtt_parser.h>
#include <gtt_device.h>
#include <stdio.h>
#include "gtt_protocol.h"
#include "gtt_events.h"

uint8_t gtt_process_packet(gtt_device *device, size_t packetstart)
{
	size_t originalstart = device->Parser.PacketStart;
	uint8_t WaitingPacket = 0;
	uint8_t Result = 0;
	for (size_t i = 0; i < device->wait_idx; i++)
	{
		if (!device->waitlist[i].Done)
		{
			if (device->waitlist[i].Command == device->Parser.Command)
			{
				if (device->Parser.Command == 250)
				{
					size_t index = device->Parser.PacketStart;
					uint16_t SubCommand = gtt_parser_getU16(device, index, &index);
					if (SubCommand == device->waitlist[i].SubCommand)
					{
						device->waitlist[i].Done = 1;
						WaitingPacket = 1;
					}
				}
				else
				{
					device->waitlist[i].Done = 1;
					WaitingPacket = 1;
				}
			}
			if (WaitingPacket)
				device->waitlist[i].Length = device->Parser.Length;
			break;
		}
	}
	if (device->Parser.Command == 135)
	{
		size_t index = device->Parser.PacketStart;
		eTouchReportingType type = (eTouchReportingType)gtt_parser_getU8(device, index, &index);
		if (device->Parser.Length == 2)
		{
			uint8_t Region = gtt_parser_getU8(device, index, &index);
			if (device->events.regiontouch)
			{
				device->events.regiontouch(device,type, Region);
			}
		} 
		else 
			if (device->Parser.Length == 4)
			{
				uint8_t Region = gtt_parser_getU8(device, index, &index);
				int16_t Value = gtt_parser_getS16(device, index, &index);
				if (device->events.sliderchange)
				{
					device->events.sliderchange(device, type, Region, Value);
				}
			} 
			else
			if (device->Parser.Length == 5)
			{
				uint16_t X = gtt_parser_getU16(device, index, &index);
				uint16_t Y = gtt_parser_getU16(device, index, &index);
				if (device->events.touch)
				{
					device->events.touch(device, type, X, Y);
				}
			}
	}
	if (device->Parser.Command == 165)
	{ 
		if (device->events.key)
		{
			device->events.key(device, device->rx_buffer[1], device->rx_buffer[0]);
		}
		Result = 1;
	}
	else if (device->Parser.Command == 235) //gtt 25 event
	{
		process_gtt25events(device);
		Result = 1;
	}
	if (Result || !WaitingPacket)
	{
		device->Parser.Index = originalstart;
	}
	return Result;
}

void gtt_out_of_bounds(gtt_device* device, uint8_t data)
{
}

uint8_t gtt_parser_process(gtt_device *device)
{
	int Res = device->Read(device);
	if (Res != -1)
	{
		switch (device->Parser.state)
		{
		case GTT_PARSER_IDLE:
			if (Res == 252)
				device->Parser.state = GTT_PARSER_COMMAND;
			else
				gtt_out_of_bounds(device,Res);
			break;
		case GTT_PARSER_COMMAND:
			device->Parser.Command = Res;
			device->Parser.state = GTT_PARSER_LENGTH_1;
			break;
		case GTT_PARSER_LENGTH_1:
			device->Parser.Length = Res << 8;
			device->Parser.state = GTT_PARSER_LENGTH_2;
			break;
		case GTT_PARSER_LENGTH_2:
			device->Parser.Length |= Res;
			if (device->Parser.Length)
			{
				device->Parser.PacketStart = device->Parser.Index;
				device->Parser.state = GTT_PARSER_DATA;
			}
			else
			{
				 device->Parser.state = GTT_PARSER_IDLE;
				 uint8_t Result = gtt_process_packet(device, device->Parser.PacketStart);
				 if (Result)
					 return 0;
				 else
					 return 1;

			}
			break;
		case GTT_PARSER_DATA:
			device->rx_buffer[(device->Parser.Index++)] = Res;
			if (device->Parser.Index - device->Parser.PacketStart == device->Parser.Length)
			{
				device->Parser.state = GTT_PARSER_IDLE;
				uint8_t Result = gtt_process_packet(device, device->Parser.PacketStart);
				if (Result)
					return 0;
				else
					return 1;
			}
			break;
		}
	}
	return 0;
}

size_t gtt_parser_waitpacket(gtt_device *device,int packetType)
{
	gtt_waitlist_item *item = &device->waitlist[device->wait_idx++];
	item->Command = packetType;
	item->SubCommand = 0;
	item->Done = 0;
	while (!item->Done)
		gtt_parser_process(device);
	size_t result = item->PacketStart;
	device->Parser.Index = item->PacketStart;
	device->wait_idx--;
	return result;
}

size_t gtt_parser_waitpacket_250(gtt_device *device, uint16_t commandID)
{
	gtt_waitlist_item *item;
	item = &device->waitlist[device->wait_idx++];
	item->Command = 250;
	item->SubCommand = commandID;
	item->Done = 0;
	while (!item->Done)
		gtt_parser_process(device);
	device->wait_idx--;
	size_t result = device->Parser.PacketStart;
	device->Parser.Index = item->PacketStart;
	return result+2;
}


#define swap32(a)                    \
	((((a) >> 24) & 0x000000ff) | \
	(((a) >> 8) & 0x0000ff00) | \
	(((a) << 8) & 0x00ff0000) | \
	(((a) << 24) & 0xff000000))


#define swap16(a) ((((a) >> 8) & 0x00ff) | (((a) << 8) & 0xff00))

uint32_t gtt_parser_getU32(gtt_device* device, size_t index, size_t *outIndex)
{
	uint32_t data = *(uint32_t*)&device->rx_buffer[index];
	*outIndex = index + 4;
	return swap32(data);
}

uint16_t gtt_parser_getU16(gtt_device* device, size_t index, size_t *outIndex)
{
	uint16_t data = *(uint16_t*)&device->rx_buffer[index];
	*outIndex = index + 2;
	return swap16(data);
}

int16_t gtt_parser_getS16(gtt_device* device, size_t index, size_t *outIndex)
{
	int16_t data = *(int16_t*)&device->rx_buffer[index];
	*outIndex = index + 2;
	return swap16(data);
}


uint8_t gtt_parser_getU8(gtt_device* device, size_t index, size_t *outIndex)
{
	*outIndex = index + 1;
	return device->rx_buffer[index];
}

float gtt_parser_getFloat(gtt_device* device, size_t index, size_t *outIndex)
{
	uint32_t val;
	val = gtt_parser_getU32(device, index, outIndex);
	float res = *(float*)&val;
	return res;
}

float gtt_parser_getNumber(gtt_device* device, size_t index, size_t *outIndex)
{
	NIWARN
	return 0;
}


gtt_bytearray_l8 gtt_parser_getByteArrayL8(gtt_device* device, size_t index, size_t *outIndex)
{
	gtt_bytearray_l8 res = { 0 };
	res.length = device->rx_buffer[index];
	res.Data = &device->rx_buffer[index+1];
	*outIndex = 1 + res.length;
	return res;
}


gtt_bytearray_l16 gtt_parser_getByteArrayL16(gtt_device* device, size_t index, size_t *outIndex)
{
	gtt_bytearray_l16 res = { 0 };
	res.length = gtt_parser_getU16(device, index, &index);
	res.Data = &device->rx_buffer[index]; 
	*outIndex = index + res.length;
	return res;
}

gtt_wordarray_l32 gtt_parser_getWordArrayL32(gtt_device* device, size_t index, size_t *outIndex)
{
	gtt_wordarray_l32 res = { 0 };
	res.length = gtt_parser_getU32(device, index, &index);
	res.Data = (int16_t*) &device->rx_buffer[index];
	for (size_t i = 0; i < res.length; i++)
	{
		res.Data[i] = gtt_parser_getS16(device, index, &index);
	}
	*outIndex = index;
	return res;

	return res;
}

char* gtt_parser_getStringASCII(gtt_device* device, size_t index, size_t *outIndex)
{
	char* Result = &device->rx_buffer[index];
	while (device->rx_buffer[index] != 0)
		index++;
	*outIndex = index+1;
	return Result;
} 

gtt_text gtt_parser_getText(gtt_device* device, size_t index, size_t *outIndex)
{
	gtt_text result = { 0 };
	result.Encoding = gtt_parser_getU8(device, index, &index);
	result.Length = gtt_parser_getU16(device, index, &index);
	result.Data = &device->rx_buffer[index];
	*outIndex = index + result.Length;
	return result;
}
