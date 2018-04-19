#ifndef _GTT_EXTTYPES_H
#define _GTT_EXTTYPES_H
#include <gtt_text.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct gtt_bytearray_l8
{
	uint8_t length;
	uint8_t* Data;
} gtt_bytearray_l8;

typedef struct gtt_bytearray_l16
{
	uint16_t length;
	uint8_t* Data;
} gtt_bytearray_l16;

typedef struct gtt_wordarray_l32
{
	uint32_t length;
	int16_t* Data;
} gtt_wordarray_l32;

gtt_bytearray_l8 gtt_make_bytearray_l8(uint8_t length, uint8_t *data);
gtt_bytearray_l16 gtt_make_bytearray_l16(uint16_t length, uint8_t *data);
gtt_wordarray_l32 gtt_make_gtt_wordarray_l32(uint32_t length, int16_t *data);

#ifdef __cplusplus
}
#endif


#endif
