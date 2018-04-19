#include <gtt_packet_builder.h>
#include <gtt_protocol.h>


unsigned reverse(uint32_t x) {
	x = ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
	x = ((x & 0x33333333) << 2) | ((x >> 2) & 0x33333333);
	x = ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F);
	x = (x << 24) | ((x & 0xFF00) << 8) |
		((x >> 8) & 0xFF00) | (x >> 24);
	return x;
}

uint32_t crc32a(uint8_t *data, size_t length) {
	int j;
	unsigned int byte, crc;
	crc = (unsigned int)0xFFFFFFFF;
	for (size_t i = 0; i < length; i++)
	{
		byte = data[i];            // Get next byte.
		byte = reverse(byte);         // 32-bit reversal.
		for (j = 0; j <= 7; j++) {    // Do eight times.
			if ((int)(crc ^ byte) < 0)
				crc = (crc << 1) ^ 0x04C11DB7;
			else crc = crc << 1;
			byte = byte << 1;          // Ready next msg bit.
		}
	}
	return reverse(~crc);
}

int packetStarted = 0;
void gtt_packetbuilder_start(gtt_device *device)
{
	device->tx_index = 0;
	if (device->secured_packets)
	{
		gtt_packetbuilder_writeU8(device,GTT_SECURED_PACKET_START);
		gtt_packetbuilder_writeU16(device, 0); //Dummy length, to be filled in later.
	}
}

void gtt_packetbuilder_end(gtt_device *device)
{
	if (device->secured_packets)
	{
		size_t len = device->tx_index - 3;    //Start_of_packet + length
		//Patch up the length at the start of the packet.
		device->tx_buffer[1] = (len >> 8) & 0xff;
		device->tx_buffer[2] = (len & 0xff);
		//Calculate the crc
		uint32_t crc = crc32a(device->tx_buffer, device->tx_index);
		//add the crc to the packet.
		gtt_packetbuilder_writeU32(device, crc); 
	}
}

void gtt_packetbuilder_send(gtt_device *device)
{
	if (device->secured_packets)
	{
		do
		{
			device->Write(device, device->tx_buffer, device->tx_index);
			gtt_parser_waitpacket(device, 251);
		} while (device->rx_buffer[0] != 0);
	}
	else
	{
		device->Write(device, device->tx_buffer, device->tx_index);
	}
	packetStarted = 0;
}

void gtt_packetbuilder_writeU8(gtt_device *device, uint8_t value)
{
	device->tx_buffer[device->tx_index++] = value;
}

void gtt_packetbuilder_writeU16(gtt_device *device, uint16_t value)
{
	device->tx_buffer[device->tx_index++] = (value >> 8) & 0xff;
	device->tx_buffer[device->tx_index++] = (value & 0xff);
}

void gtt_packetbuilder_writeU32(gtt_device *device, uint32_t value)
{
	device->tx_buffer[device->tx_index++] = (value & 0xff000000) >> 24;
	device->tx_buffer[device->tx_index++] = (value & 0xff0000) >> 16;
	device->tx_buffer[device->tx_index++] = (value & 0xff00) >> 8;
	device->tx_buffer[device->tx_index++] = (value & 0xff) ;
}

void gtt_packetbuilder_writeFloat(gtt_device *device, float value)
{
	uint32_t val = *(uint32_t*)&value;
	gtt_packetbuilder_writeU32(device, val);
}

void gtt_packetbuilder_writeS16(gtt_device *device, int16_t value)
{
	uint16_t val = (uint16_t)value;
	device->tx_buffer[device->tx_index++] = (val >> 8) & 0xff;
	device->tx_buffer[device->tx_index++] = (val & 0xff);
}

void gtt_packetbuilder_writeStringASCII(gtt_device *device, char *value)
{
	if (value)
	{
		while (*value)
		{
			device->tx_buffer[device->tx_index++] = *value;
			value++;
		}
		device->tx_buffer[device->tx_index++] = *value;
	}
	else
		device->tx_buffer[device->tx_index++] = 0;

}

void gtt_packetbuilder_writeStringUTF8(gtt_device *device, char *value)
{
	gtt_packetbuilder_writeStringASCII(device, value);
}

void gtt_packetbuilder_writeStringUnicode(gtt_device *device, uint16_t *value)
{
	size_t len = 0;
	uint16_t *tmp = value;
	if (tmp)
	{
		while (*tmp++) len++;
	}
	gtt_packetbuilder_writeU16(device, len);
	for (size_t i = 0; i < len; i++)
	{
		device->tx_buffer[device->tx_index++] = (value[i] & 0xff);
		device->tx_buffer[device->tx_index++] = (value[i] >> 8) & 0xff;
	}
}

void gtt_packetbuilder_writeText(gtt_device *device, gtt_text value)
{
	gtt_packetbuilder_writeU8(device,value.Encoding);
	gtt_packetbuilder_writeU16(device, value.Length);
	uint8_t *val = (uint8_t *)value.Data;
	for (int i = 0; i < value.Length; i++)
	{
		gtt_packetbuilder_writeU8(device, val[i]);
	}
}

void gtt_packetbuilder_writeByteArrayL8(gtt_device *device, gtt_bytearray_l8 value)
{
	gtt_packetbuilder_writeU8(device, value.length);
	for (size_t i = 0; i < value.length; i++)
		gtt_packetbuilder_writeU8(device, value.Data[i]);
}

void gtt_packetbuilder_writeByteArrayL16(gtt_device *device, gtt_bytearray_l16 value)
{
	gtt_packetbuilder_writeU16(device, value.length);
	for (size_t i = 0; i < value.length; i++)
		gtt_packetbuilder_writeU8(device, value.Data[i]);
}

void gtt_packetbuilder_writeSignedWordArrayL8(gtt_device *device, int16_t *value)
{

}

void gtt_packetbuilder_writeNumber(gtt_device *device, float value)
{

}
