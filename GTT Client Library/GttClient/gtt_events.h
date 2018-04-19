#ifndef _GTT_EVENTS_H
#define _GTT_EVENTS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct gtt_device gtt_device;

typedef void(*gtt_event_key)(gtt_device* device, uint8_t key, eKeypadRepeatMode type);
typedef void(*gtt_event_sliderchange)(gtt_device* device, eTouchReportingType type, uint8_t slider, int16_t value);
typedef void(*gtt_event_touch)(gtt_device* device, eTouchReportingType type, uint16_t x , uint16_t y);
typedef void(*gtt_event_regiontouch)(gtt_device* device, eTouchReportingType type, uint8_t region);
typedef void(*gtt_event_baseobject_on_property_change)(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID);
typedef void(*gtt_event_visualobject_on_key)(gtt_device* device, uint16_t ObjectID, uint8_t Row, uint8_t Col, uint8_t ScanCode, uint8_t Down);
typedef void(*gtt_event_button_click)(gtt_device* device, uint16_t ObjectID, uint8_t State);
typedef struct gtt_events {
	gtt_event_key key;
	gtt_event_sliderchange sliderchange;
	gtt_event_touch touch;
	gtt_event_regiontouch regiontouch;
	gtt_event_baseobject_on_property_change baseobject_on_property_change;
	gtt_event_visualobject_on_key visualobject_on_key;
	gtt_event_button_click button_click;
} gtt_events;

void process_gtt25events(gtt_device* device);
void gtt_set_keyhandler(gtt_device *device, gtt_event_key handler);
void gtt_set_touch_sliderchangehandler(gtt_device *device, gtt_event_sliderchange handler);
void gtt_set_touch_handler(gtt_device *device, gtt_event_touch handler);
void gtt_set_regiontouch_handler(gtt_device *device, gtt_event_regiontouch handler);
void gtt_set_baseobject_on_property_changehandler(gtt_device *device, gtt_event_baseobject_on_property_change handler);
void gtt_set_visualobject_on_keyhandler(gtt_device *device, gtt_event_visualobject_on_key handler);
void gtt_set_button_clickhandler(gtt_device *device, gtt_event_button_click handler);

#ifdef __cplusplus
}
#endif

#endif
