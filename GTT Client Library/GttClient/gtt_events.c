#include "gtt_device.h"

void process_gtt25events(gtt_device* device)
{
	size_t index = 0;
	eEventID eventID = (eEventID)gtt_parser_getU16(device, index, &index);
	uint16_t ObjectID = gtt_parser_getU16(device, index, &index);
	switch (eventID)
	{
		case eEventID_BaseObject_OnPropertyChange:
			if(device->events.baseobject_on_property_change)
			{
				uint16_t PropertyID =  gtt_parser_getU16(device, index, &index);
				device->events.baseobject_on_property_change(device, ObjectID, PropertyID);
			}
			break;
		case eEventID_VisualObject_OnKey:
			if(device->events.visualobject_on_key)
			{
				uint8_t Row =  gtt_parser_getU8(device, index, &index);
				uint8_t Col =  gtt_parser_getU8(device, index, &index);
				uint8_t ScanCode =  gtt_parser_getU8(device, index, &index);
				uint8_t Down =  gtt_parser_getU8(device, index, &index);
				device->events.visualobject_on_key(device, ObjectID, Row, Col, ScanCode, Down);
			}
			break;
		case eEventID_Button_Click:
			if(device->events.button_click)
			{
				uint8_t State =  gtt_parser_getU8(device, index, &index);
				device->events.button_click(device, ObjectID, State);
			}
			break;
	}
}

void gtt_set_keyhandler(gtt_device *device, gtt_event_key handler)
{
	device->events.key = handler;
}
void gtt_set_touch_sliderchangehandler(gtt_device *device, gtt_event_sliderchange handler)
{
	device->events.sliderchange = handler;
}
void gtt_set_touch_handler(gtt_device *device, gtt_event_touch handler)
{
	device->events.touch = handler;
}
void gtt_set_regiontouch_handler(gtt_device *device, gtt_event_regiontouch handler)
{
	device->events.regiontouch = handler;
}
void gtt_set_baseobject_on_property_changehandler(gtt_device *device, gtt_event_baseobject_on_property_change handler)
{
	device->events.baseobject_on_property_change = handler;
}
void gtt_set_visualobject_on_keyhandler(gtt_device *device, gtt_event_visualobject_on_key handler)
{
	device->events.visualobject_on_key = handler;
}
void gtt_set_button_clickhandler(gtt_device *device, gtt_event_button_click handler)
{
	device->events.button_click = handler;
}
