#ifndef _GTT_PARSER_H
#define _GTT_PARSER_H
#include <stdint.h>
#include <stddef.h>
#include "gtt_ext_types.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct gtt_device gtt_device;

#define GTT_PARSER_IDLE       0
#define GTT_PARSER_COMMAND    1
#define GTT_PARSER_LENGTH_1   2
#define GTT_PARSER_LENGTH_2   3
#define GTT_PARSER_DATA       4

typedef struct 
{
	uint8_t state;
	uint8_t Command;
	size_t Length;
	size_t Index;
	size_t PacketStart;

} gtt_parser;

uint8_t gtt_process_packet(gtt_device *device, size_t packetstart);
uint8_t gtt_parser_process(gtt_device *device);
size_t gtt_parser_waitpacket(gtt_device *device, int packetType);
size_t gtt_parser_waitpacket_250(gtt_device *device, uint16_t commandID);

uint16_t gtt_parser_getU16(gtt_device* device, size_t index, size_t *outIndex);
uint8_t gtt_parser_getU8(gtt_device* device, size_t index, size_t *outIndex);
uint32_t gtt_parser_getU32(gtt_device* device, size_t index, size_t *outIndex);

//TODO

float gtt_parser_getFloat(gtt_device* device, size_t index, size_t *outIndex);
float gtt_parser_getNumber(gtt_device* device, size_t index, size_t *outIndex);
int16_t gtt_parser_getS16(gtt_device* device, size_t index, size_t *outIndex);
gtt_bytearray_l8 gtt_parser_getByteArrayL8(gtt_device* device, size_t index, size_t *outIndex);
gtt_bytearray_l16 gtt_parser_getByteArrayL16(gtt_device* device, size_t index, size_t *outIndex);
char* gtt_parser_getStringASCII(gtt_device* device, size_t index, size_t *outIndex);
gtt_text gtt_parser_getText(gtt_device* device, size_t index, size_t *outIndex);
gtt_wordarray_l32 gtt_parser_getWordArrayL32(gtt_device* device, size_t index, size_t *outIndex);

#ifdef __cplusplus
}
#endif

#endif

