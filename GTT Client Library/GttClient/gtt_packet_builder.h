#ifndef _GTT_PACKET_WRITER_H
#define _GTT_PACKET_WRITER_H
#include <stdint.h>
#include "gtt_device.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GTT_SECURED_PACKET_START 251

void gtt_packetbuilder_start(gtt_device *device);
void gtt_packetbuilder_end(gtt_device *device);
void gtt_packetbuilder_send(gtt_device *device);
void gtt_packetbuilder_writeU8(gtt_device *device, uint8_t value);
void gtt_packetbuilder_writeU16(gtt_device *device, uint16_t value);
void gtt_packetbuilder_writeU32(gtt_device *device, uint32_t value);

 //TODO!!
void gtt_packetbuilder_writeFloat(gtt_device *device, float value);
void gtt_packetbuilder_writeS16(gtt_device *device, int16_t value);
void gtt_packetbuilder_writeStringASCII(gtt_device *device, char *value);
void gtt_packetbuilder_writeStringUTF8(gtt_device *device, char *value);
void gtt_packetbuilder_writeStringUnicode(gtt_device *device, uint16_t *value);
void gtt_packetbuilder_writeText(gtt_device *device, gtt_text value);
void gtt_packetbuilder_writeByteArrayL8(gtt_device *device, gtt_bytearray_l8 value);
void gtt_packetbuilder_writeByteArrayL16(gtt_device *device, gtt_bytearray_l16 value);
void gtt_packetbuilder_writeSignedWordArrayL8(gtt_device *device, int16_t *value);
void gtt_packetbuilder_writeNumber(gtt_device *device, float value);

#ifdef __cplusplus
}
#endif


#endif
