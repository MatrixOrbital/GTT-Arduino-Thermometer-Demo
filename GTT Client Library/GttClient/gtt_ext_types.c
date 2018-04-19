#include <gtt_protocol.h>
#include <gtt_ext_types.h>

gtt_bytearray_l8 gtt_make_bytearray_l8(uint8_t length, uint8_t *data)
{
	gtt_bytearray_l8 res;
	res.length = length;
	res.Data = data;
	return res;
}

gtt_bytearray_l16 gtt_make_bytearray_l16(uint16_t length, uint8_t *data)
{
	gtt_bytearray_l16 res;
	res.length = length;
	res.Data = data;
	return res;
}