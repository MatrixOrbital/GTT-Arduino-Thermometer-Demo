#ifndef _GTT_TEXT_H
#define _GTT_TEXT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct gtt_text 
{ 
	uint8_t Encoding; 
	uint16_t Length; 
	void* Data; 
} gtt_text;

gtt_text gtt_make_text_ascii(char* data);
gtt_text gtt_make_text_utf8(char* data);
gtt_text gtt_make_text_unicode(wchar_t* data);

#ifdef __cplusplus
}
#endif


#endif
