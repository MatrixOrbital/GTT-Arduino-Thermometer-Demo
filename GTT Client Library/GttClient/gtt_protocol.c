#include "gtt_protocol.h"
#include "gtt_packet_builder.h"

gtt_get_protocol_version_return gtt_get_protocol_version(gtt_device *device)
{
	gtt_get_protocol_version_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,0);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 0);

	result.Major = gtt_parser_getU8(device,index, &index);
	result.Minor = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_reset(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,1);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_wait(gtt_device *device, uint16_t Time)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,2);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_get_display_metrics_return gtt_get_display_metrics(gtt_device *device)
{
	gtt_get_display_metrics_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,3);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 3);

	result.Width = gtt_parser_getU16(device,index, &index);
	result.Height = gtt_parser_getU16(device,index, &index);
	result.BitsRed = gtt_parser_getU8(device,index, &index);
	result.BitsGreen = gtt_parser_getU8(device,index, &index);
	result.BitsBlue = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_enter_mass_storage_mode(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,4);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_default_channel(gtt_device *device, eChannel Channel)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,5);
	gtt_packetbuilder_writeU8(device,Channel);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_get_ambient_light_return gtt_get_ambient_light(gtt_device *device)
{
	gtt_get_ambient_light_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,9);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 9);

	result.Result = gtt_parser_getU8(device,index, &index);
	result.Value = gtt_parser_getU16(device,index, &index);

	return result;
}

void gtt_create_label(gtt_device *device, uint8_t LabelID, int16_t X, int16_t Y, int16_t Width, int16_t Height, int16_t Rot, eFontAlignVertical VJst, eFontAlignHorizontal HJst, uint8_t Font, uint8_t R, uint8_t G, uint8_t B)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,16);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,Width);
	gtt_packetbuilder_writeS16(device,Height);
	gtt_packetbuilder_writeS16(device,Rot);
	gtt_packetbuilder_writeU8(device,VJst);
	gtt_packetbuilder_writeU8(device,HJst);
	gtt_packetbuilder_writeU8(device,Font);
	gtt_packetbuilder_writeU8(device,R);
	gtt_packetbuilder_writeU8(device,G);
	gtt_packetbuilder_writeU8(device,B);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_update_label(gtt_device *device, uint8_t LabelID, char * Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,17);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_writeU8(device,0);
	gtt_packetbuilder_writeStringASCII(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_update_label_unicode(gtt_device *device, uint8_t LabelID, wchar_t * Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,17);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_writeU8(device,1);
	gtt_packetbuilder_writeStringUnicode(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_update_label_utf8(gtt_device *device, uint8_t LabelID, char * Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,17);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_writeU8(device,2);
	gtt_packetbuilder_writeStringUTF8(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_set_label_activation(gtt_device *device, uint8_t LabelID, eActivation State)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,19);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_writeU8(device,State);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 19);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

gtt_get_label_activation_return gtt_get_label_activation(gtt_device *device, uint8_t LabelID)
{
	gtt_get_label_activation_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,20);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 20);

	result.Result = gtt_parser_getU8(device,index, &index);
	result.State = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_set_label_colour(gtt_device *device, uint8_t LabelID, uint8_t R, uint8_t G, uint8_t B)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,21);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_writeU8(device,R);
	gtt_packetbuilder_writeU8(device,G);
	gtt_packetbuilder_writeU8(device,B);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 21);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

gtt_get_label_colour_return gtt_get_label_colour(gtt_device *device, uint8_t LabelID)
{
	gtt_get_label_colour_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,22);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 22);

	result.Result = gtt_parser_getU8(device,index, &index);
	result.R = gtt_parser_getU8(device,index, &index);
	result.G = gtt_parser_getU8(device,index, &index);
	result.B = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_set_label_size(gtt_device *device, uint8_t LabelID, uint8_t Size)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,23);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_writeU8(device,Size);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 23);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

gtt_get_label_size_return gtt_get_label_size(gtt_device *device, uint8_t LabelID)
{
	gtt_get_label_size_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,24);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 24);

	result.Result = gtt_parser_getU8(device,index, &index);
	result.Size = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_set_label_background_colour(gtt_device *device, uint8_t LabelID, uint8_t R, uint8_t G, uint8_t B)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,25);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_writeU8(device,R);
	gtt_packetbuilder_writeU8(device,G);
	gtt_packetbuilder_writeU8(device,B);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 25);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

gtt_get_label_background_colour_return gtt_get_label_background_colour(gtt_device *device, uint8_t LabelID)
{
	gtt_get_label_background_colour_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,26);
	gtt_packetbuilder_writeU8(device,LabelID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 26);

	result.Result = gtt_parser_getU8(device,index, &index);
	result.R = gtt_parser_getU8(device,index, &index);
	result.G = gtt_parser_getU8(device,index, &index);
	result.B = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_cache_font_characters(gtt_device *device, uint8_t FontID, uint8_t PtSize, int16_t Rot, char * Value)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,27);
	gtt_packetbuilder_writeU8(device,FontID);
	gtt_packetbuilder_writeU8(device,PtSize);
	gtt_packetbuilder_writeS16(device,Rot);
	gtt_packetbuilder_writeU8(device,0);
	gtt_packetbuilder_writeStringASCII(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 27);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_cache_font_characters_unicode(gtt_device *device, uint8_t FontID, uint8_t PtSize, int16_t Rot, wchar_t * Value)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,27);
	gtt_packetbuilder_writeU8(device,FontID);
	gtt_packetbuilder_writeU8(device,PtSize);
	gtt_packetbuilder_writeS16(device,Rot);
	gtt_packetbuilder_writeU8(device,1);
	gtt_packetbuilder_writeStringUnicode(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 27);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_cache_font_characters_utf8(gtt_device *device, uint8_t FontID, uint8_t PtSize, int16_t Rot, char * Value)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,27);
	gtt_packetbuilder_writeU8(device,FontID);
	gtt_packetbuilder_writeU8(device,PtSize);
	gtt_packetbuilder_writeS16(device,Rot);
	gtt_packetbuilder_writeU8(device,2);
	gtt_packetbuilder_writeStringUTF8(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 27);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_clear_cached_characters(gtt_device *device, uint8_t FontID, uint8_t PtSize, int16_t Rot)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,28);
	gtt_packetbuilder_writeU8(device,FontID);
	gtt_packetbuilder_writeU8(device,PtSize);
	gtt_packetbuilder_writeS16(device,Rot);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 28);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_clear_all_cached_characters(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,29);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 29);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_print_unicode(gtt_device *device, wchar_t * Text)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,36);
	gtt_packetbuilder_writeStringUnicode(device,Text);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_print_utf8(gtt_device *device, char * Text)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,37);
	gtt_packetbuilder_writeStringUTF8(device,Text);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_control_character_mode(gtt_device *device, eControlCharacterMode Mode)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,38);
	gtt_packetbuilder_writeU8(device,Mode);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_get_control_character_mode(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,39);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 39);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_load_font(gtt_device *device, uint8_t FontID, char * FileName)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,40);
	gtt_packetbuilder_writeU8(device,FontID);
	gtt_packetbuilder_writeStringASCII(device,FileName);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 40);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

gtt_get_string_extents_return gtt_get_string_extents(gtt_device *device, char * Text)
{
	gtt_get_string_extents_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,42);
	gtt_packetbuilder_writeStringASCII(device,Text);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 42);

	result.Width = gtt_parser_getU16(device,index, &index);
	result.Height = gtt_parser_getU16(device,index, &index);

	return result;
}

void gtt_set_font_window(gtt_device *device, int16_t X, int16_t Y, uint16_t Width, uint16_t Height)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,43);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_get_font_window_return gtt_get_font_window(gtt_device *device)
{
	gtt_get_font_window_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,44);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 44);

	result.X = gtt_parser_getS16(device,index, &index);
	result.Y = gtt_parser_getS16(device,index, &index);
	result.Width = gtt_parser_getU16(device,index, &index);
	result.Height = gtt_parser_getU16(device,index, &index);

	return result;
}

void gtt_reset_font(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,45);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_font_color(gtt_device *device, uint8_t R, uint8_t G, uint8_t B)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,46);
	gtt_packetbuilder_writeU8(device,R);
	gtt_packetbuilder_writeU8(device,G);
	gtt_packetbuilder_writeU8(device,B);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_get_font_color_return gtt_get_font_color(gtt_device *device)
{
	gtt_get_font_color_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,47);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 47);

	result.R = gtt_parser_getU8(device,index, &index);
	result.G = gtt_parser_getU8(device,index, &index);
	result.B = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_get_current_font(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,48);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 48);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_set_current_font(gtt_device *device, uint8_t FontID)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,49);
	gtt_packetbuilder_writeU8(device,FontID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 49);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_panel_orientation(gtt_device *device, ePanelOrientation Orientation)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,50);
	gtt_packetbuilder_writeU8(device,Orientation);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_font_size(gtt_device *device, uint8_t PtSize)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,51);
	gtt_packetbuilder_writeU8(device,PtSize);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_customer_data(gtt_device *device, gtt_bytearray_l8  Data)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,52);
	gtt_packetbuilder_writeByteArrayL8(device,Data);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_bytearray_l8  gtt_get_customer_data(gtt_device *device)
{
	gtt_bytearray_l8  result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,53);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 53);

	result = gtt_parser_getByteArrayL8(device,index, &index);

	return result;
}

uint16_t gtt_get_module_type(gtt_device *device)
{
	uint16_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,55);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 55);

	result = gtt_parser_getU16(device,index, &index);

	return result;
}

char * gtt_get_module_string(gtt_device *device)
{
	char * result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,56);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 56);

	result = gtt_parser_getStringASCII(device,index, &index);

	return result;
}

void gtt_set_baud_rate(gtt_device *device, uint32_t BaudRate)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,57);
	gtt_packetbuilder_writeU32(device,BaudRate);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_flow_control(gtt_device *device, eFlowControl FlowControl)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,58);
	gtt_packetbuilder_writeU8(device,FlowControl);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_get_font_size(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,61);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 61);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_clear_key_buffer(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,69);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_clear_a_scripted_key(gtt_device *device, uint8_t Row, uint8_t Column)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,70);
	gtt_packetbuilder_writeU8(device,Row);
	gtt_packetbuilder_writeU8(device,Column);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_clear_all_scripted_keys(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,71);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_move_home(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,72);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_gpo(gtt_device *device, uint8_t Number, eGPOSetting Setting)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,73);
	gtt_packetbuilder_writeU8(device,Number);
	gtt_packetbuilder_writeU8(device,Setting);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_led_indicator_state(gtt_device *device, uint8_t Number, eIndicatorState State)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,74);
	gtt_packetbuilder_writeU8(device,Number);
	gtt_packetbuilder_writeU8(device,State);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_key_auto_tx(gtt_device *device, eOnOff AutoTransmit)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,79);
	gtt_packetbuilder_writeU8(device,AutoTransmit);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_debounce_time(gtt_device *device, uint8_t Mode)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,85);
	gtt_packetbuilder_writeU8(device,Mode);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_background_drawing_color(gtt_device *device, uint8_t R, uint8_t G, uint8_t B)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,86);
	gtt_packetbuilder_writeU8(device,R);
	gtt_packetbuilder_writeU8(device,G);
	gtt_packetbuilder_writeU8(device,B);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_get_background_drawing_color_return gtt_get_background_drawing_color(gtt_device *device)
{
	gtt_get_background_drawing_color_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,87);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 87);

	result.R = gtt_parser_getU8(device,index, &index);
	result.G = gtt_parser_getU8(device,index, &index);
	result.B = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_clear_screen(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,88);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_scroll(gtt_device *device, int16_t X, int16_t Y, int16_t Width, int16_t Height, int16_t MoveX, int16_t MoveY)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,89);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,Width);
	gtt_packetbuilder_writeS16(device,Height);
	gtt_packetbuilder_writeS16(device,MoveX);
	gtt_packetbuilder_writeS16(device,MoveY);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_manual_flush(gtt_device *device, eEnable Enable)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,90);
	gtt_packetbuilder_writeU8(device,Enable);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_manual_flush(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,91);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_flush_region(gtt_device *device, int16_t X, int16_t Y, int16_t Width, int16_t Height)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,92);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,Width);
	gtt_packetbuilder_writeS16(device,Height);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_run_script(gtt_device *device, char * FileName)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,93);
	gtt_packetbuilder_writeStringASCII(device,FileName);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_read_screen_rectangle_return gtt_read_screen_rectangle(gtt_device *device, uint16_t X, uint16_t Y, uint16_t Width, uint16_t Height, ePixelFormat Format)
{
	gtt_read_screen_rectangle_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,94);
	gtt_packetbuilder_writeU16(device,X);
	gtt_packetbuilder_writeU16(device,Y);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_writeU8(device,Format);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 94);

	result.Result = gtt_parser_getU8(device,index, &index);
	result.Format = gtt_parser_getU8(device,index, &index);
	result.Data = gtt_parser_getByteArrayL16(device,index, &index);

	return result;
}

uint8_t gtt_load_bitmap(gtt_device *device, uint8_t BitmapID, char * FileName)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,95);
	gtt_packetbuilder_writeU8(device,BitmapID);
	gtt_packetbuilder_writeStringASCII(device,FileName);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 95);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_copy_screen_rectangle(gtt_device *device, uint8_t BitmapID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,96);
	gtt_packetbuilder_writeU8(device,BitmapID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_display_bitmap(gtt_device *device, uint8_t BitmapID, int16_t X, int16_t Y)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,97);
	gtt_packetbuilder_writeU8(device,BitmapID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 97);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_set_bitmap_transparency(gtt_device *device, uint8_t BitmapID, uint8_t R, uint8_t G, uint8_t B)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,98);
	gtt_packetbuilder_writeU8(device,BitmapID);
	gtt_packetbuilder_writeU8(device,R);
	gtt_packetbuilder_writeU8(device,G);
	gtt_packetbuilder_writeU8(device,B);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 98);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_drawing_color(gtt_device *device, uint8_t R, uint8_t G, uint8_t B)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,99);
	gtt_packetbuilder_writeU8(device,R);
	gtt_packetbuilder_writeU8(device,G);
	gtt_packetbuilder_writeU8(device,B);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_get_drawing_color_return gtt_get_drawing_color(gtt_device *device)
{
	gtt_get_drawing_color_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,100);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 100);

	result.R = gtt_parser_getU8(device,index, &index);
	result.G = gtt_parser_getU8(device,index, &index);
	result.B = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_continue_line(gtt_device *device, int16_t X, int16_t Y)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,101);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_define_plain_bar_graph(gtt_device *device, uint8_t BarID, int16_t Min, int16_t Max, int16_t X, int16_t Y, int16_t Width, int16_t Height, uint8_t FGR, uint8_t FGG, uint8_t FGB, uint8_t BGR, uint8_t BGG, uint8_t BGB, eBargraphOrientation D)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,103);
	gtt_packetbuilder_writeU8(device,BarID);
	gtt_packetbuilder_writeS16(device,Min);
	gtt_packetbuilder_writeS16(device,Max);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,Width);
	gtt_packetbuilder_writeS16(device,Height);
	gtt_packetbuilder_writeU8(device,FGR);
	gtt_packetbuilder_writeU8(device,FGG);
	gtt_packetbuilder_writeU8(device,FGB);
	gtt_packetbuilder_writeU8(device,BGR);
	gtt_packetbuilder_writeU8(device,BGG);
	gtt_packetbuilder_writeU8(device,BGB);
	gtt_packetbuilder_writeU8(device,D);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_define9_slice_bar_graph(gtt_device *device, uint8_t BarID, int16_t Min, int16_t Max, int16_t X, int16_t Y, int16_t Width, int16_t Height, uint8_t BFG, uint8_t BBG, eBargraphOrientation D)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,104);
	gtt_packetbuilder_writeU8(device,BarID);
	gtt_packetbuilder_writeS16(device,Min);
	gtt_packetbuilder_writeS16(device,Max);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,Width);
	gtt_packetbuilder_writeS16(device,Height);
	gtt_packetbuilder_writeU8(device,BFG);
	gtt_packetbuilder_writeU8(device,BBG);
	gtt_packetbuilder_writeU8(device,D);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_update_value(gtt_device *device, uint8_t BarID, int16_t Value)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,105);
	gtt_packetbuilder_writeU8(device,BarID);
	gtt_packetbuilder_writeS16(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 105);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_set_multiple_bargraph_values(gtt_device *device, uint8_t BarID, int16_t * Values)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,106);
	gtt_packetbuilder_writeU8(device,BarID);
	gtt_packetbuilder_writeSignedWordArrayL8(device,Values);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 106);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_clear_all_bargraphs(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,107);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_draw_line(gtt_device *device, int16_t X1, int16_t Y1, int16_t X2, int16_t Y2)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,108);
	gtt_packetbuilder_writeS16(device,X1);
	gtt_packetbuilder_writeS16(device,Y1);
	gtt_packetbuilder_writeS16(device,X2);
	gtt_packetbuilder_writeS16(device,Y2);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_reset_a_trace_value(gtt_device *device, uint8_t TraceID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,109);
	gtt_packetbuilder_writeU8(device,TraceID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_reset_multiple_trace_values(gtt_device *device, uint8_t TraceID, uint8_t Number)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,110);
	gtt_packetbuilder_writeU8(device,TraceID);
	gtt_packetbuilder_writeU8(device,Number);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_pixel(gtt_device *device, int16_t X, int16_t Y)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,112);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_draw_rectangle(gtt_device *device, int16_t X, int16_t Y, uint16_t Width, uint16_t Height)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,114);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_initialize_trace(gtt_device *device, uint8_t TraceID, int16_t X, int16_t Y, int16_t Width, int16_t Height, int16_t Min, int16_t Max, uint8_t Step, eTraceTypeandDirection Style, uint8_t Red, uint8_t Green, uint8_t Blue)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,116);
	gtt_packetbuilder_writeU8(device,TraceID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,Width);
	gtt_packetbuilder_writeS16(device,Height);
	gtt_packetbuilder_writeS16(device,Min);
	gtt_packetbuilder_writeS16(device,Max);
	gtt_packetbuilder_writeU8(device,Step);
	gtt_packetbuilder_writeU8(device,Style);
	gtt_packetbuilder_writeU8(device,Red);
	gtt_packetbuilder_writeU8(device,Green);
	gtt_packetbuilder_writeU8(device,Blue);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_update_trace(gtt_device *device, uint8_t TraceID, int16_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,117);
	gtt_packetbuilder_writeU8(device,TraceID);
	gtt_packetbuilder_writeS16(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_update_multiple_traces(gtt_device *device, uint8_t TraceID, int16_t * Values)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,118);
	gtt_packetbuilder_writeU8(device,TraceID);
	gtt_packetbuilder_writeSignedWordArrayL8(device,Values);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 118);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_clear_alltraces(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,119);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_fill_rectangle(gtt_device *device, int16_t X, int16_t Y, uint16_t Width, uint16_t Height)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,120);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_cursor(gtt_device *device, int16_t X, int16_t Y)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,121);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_get_cursor_return gtt_get_cursor(gtt_device *device)
{
	gtt_get_cursor_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,122);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 122);

	result.X = gtt_parser_getS16(device,index, &index);
	result.Y = gtt_parser_getS16(device,index, &index);

	return result;
}

void gtt_draw_circle(gtt_device *device, int16_t X, int16_t Y, uint16_t Radius)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,123);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Radius);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_fill_circle(gtt_device *device, int16_t X, int16_t Y, uint16_t Radius)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,124);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Radius);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_draw_ellipse(gtt_device *device, int16_t X, int16_t Y, uint16_t XRadius, uint16_t YRadius)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,125);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,XRadius);
	gtt_packetbuilder_writeU16(device,YRadius);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_fill_ellipse(gtt_device *device, int16_t X, int16_t Y, uint16_t XRadius, uint16_t YRadius)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,126);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,XRadius);
	gtt_packetbuilder_writeU16(device,YRadius);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_draw_rounded_rectangle(gtt_device *device, int16_t X, int16_t Y, int16_t Width, int16_t Height, uint16_t Radius)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,127);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,Width);
	gtt_packetbuilder_writeS16(device,Height);
	gtt_packetbuilder_writeU16(device,Radius);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_fill_rounded_rectangle(gtt_device *device, int16_t X, int16_t Y, int16_t Width, int16_t Height, uint16_t Radius)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,128);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,Width);
	gtt_packetbuilder_writeS16(device,Height);
	gtt_packetbuilder_writeU16(device,Radius);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_draw_triangle(gtt_device *device, int16_t X1, int16_t Y1, int16_t X2, int16_t Y2, int16_t X3, int16_t Y3)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,129);
	gtt_packetbuilder_writeS16(device,X1);
	gtt_packetbuilder_writeS16(device,Y1);
	gtt_packetbuilder_writeS16(device,X2);
	gtt_packetbuilder_writeS16(device,Y2);
	gtt_packetbuilder_writeS16(device,X3);
	gtt_packetbuilder_writeS16(device,Y3);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_fill_triangle(gtt_device *device, int16_t X1, int16_t Y1, int16_t X2, int16_t Y2, int16_t X3, int16_t Y3)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,130);
	gtt_packetbuilder_writeS16(device,X1);
	gtt_packetbuilder_writeS16(device,Y1);
	gtt_packetbuilder_writeS16(device,X2);
	gtt_packetbuilder_writeS16(device,Y2);
	gtt_packetbuilder_writeS16(device,X3);
	gtt_packetbuilder_writeS16(device,Y3);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_create_scripted_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, uint16_t W, uint16_t H, uint8_t UpBitmap, uint8_t DownBitmap, char * UpScript, char * DownScript)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,131);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,W);
	gtt_packetbuilder_writeU16(device,H);
	gtt_packetbuilder_writeU8(device,UpBitmap);
	gtt_packetbuilder_writeU8(device,DownBitmap);
	gtt_packetbuilder_writeStringASCII(device,UpScript);
	gtt_packetbuilder_writeStringASCII(device,DownScript);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_setup_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height, uint8_t Up, uint8_t Down)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,132);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_writeU8(device,Up);
	gtt_packetbuilder_writeU8(device,Down);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_clear_touch_region(gtt_device *device, uint8_t RegionID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,133);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_clear_all_regions(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,134);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_change_reporting_style(gtt_device *device, eTouchReportingType ReportingType)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,135);
	gtt_packetbuilder_writeU8(device,ReportingType);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_get_reporting_style_return gtt_get_reporting_style(gtt_device *device)
{
	gtt_get_reporting_style_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,136);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 136);

	result.Result = gtt_parser_getU8(device,index, &index);
	result.ReportingType = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_dragging_threshold(gtt_device *device, uint16_t Threshold)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,137);
	gtt_packetbuilder_writeU16(device,Threshold);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_create_scripted_key(gtt_device *device, uint8_t KeyID, uint8_t Row, uint8_t Col, char * UpScript, char * DownScript)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,138);
	gtt_packetbuilder_writeU8(device,KeyID);
	gtt_packetbuilder_writeU8(device,Row);
	gtt_packetbuilder_writeU8(device,Col);
	gtt_packetbuilder_writeStringASCII(device,UpScript);
	gtt_packetbuilder_writeStringASCII(device,DownScript);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_calibrate(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,139);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 139);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_load_region_file(gtt_device *device, char * FileName)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,140);
	gtt_packetbuilder_writeStringASCII(device,FileName);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 140);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_restore_calibration(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,141);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 141);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_out_of_region_setting(gtt_device *device, eOnOff Setting)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,142);
	gtt_packetbuilder_writeU8(device,Setting);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_get_out_of_region_setting(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,143);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 143);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_load_nine_slice(gtt_device *device, uint8_t NineSliceID, char * Filename)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,144);
	gtt_packetbuilder_writeU8(device,NineSliceID);
	gtt_packetbuilder_writeStringASCII(device,Filename);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 144);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_draw_nine_slice(gtt_device *device, uint8_t NineSliceID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,145);
	gtt_packetbuilder_writeU8(device,NineSliceID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_set_region_activate_state(gtt_device *device, uint8_t RegionID, eEnable Enable)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,146);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_writeU8(device,Enable);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 146);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_get_region_activate_state(gtt_device *device, uint8_t RegionID)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,147);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 147);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_trace_min_max(gtt_device *device, uint8_t TraceID, int16_t Min, int16_t Max)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,148);
	gtt_packetbuilder_writeU8(device,TraceID);
	gtt_packetbuilder_writeS16(device,Min);
	gtt_packetbuilder_writeS16(device,Max);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_get_trace_min_max_return gtt_get_trace_min_max(gtt_device *device, uint8_t TraceID)
{
	gtt_get_trace_min_max_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,149);
	gtt_packetbuilder_writeU8(device,TraceID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 149);

	result.Min = gtt_parser_getS16(device,index, &index);
	result.Max = gtt_parser_getS16(device,index, &index);

	return result;
}

uint8_t gtt_create_toggle_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height, uint8_t OffID, uint8_t OnID)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,150);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_writeU8(device,OffID);
	gtt_packetbuilder_writeU8(device,OnID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 150);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_keypad_backlight_time(gtt_device *device, uint8_t Minutes)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,151);
	gtt_packetbuilder_writeU8(device,Minutes);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_get_keypad_backlight_time(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,152);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 152);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_backlight(gtt_device *device, uint8_t Brightness)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,153);
	gtt_packetbuilder_writeU8(device,Brightness);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_get_backlight(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,154);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 154);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_keypad_brightness(gtt_device *device, uint8_t Brightness)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,155);
	gtt_packetbuilder_writeU8(device,Brightness);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_get_keypad_brightness(gtt_device *device)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,156);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 156);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_auto_backlight(gtt_device *device, eAutoBacklight Setting)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,157);
	gtt_packetbuilder_writeU8(device,Setting);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_typematic_interval(gtt_device *device, uint16_t Interval)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,158);
	gtt_packetbuilder_writeU16(device,Interval);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_typematic_delay(gtt_device *device, uint16_t Delay)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,159);
	gtt_packetbuilder_writeU16(device,Delay);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_motor(gtt_device *device, uint16_t Frequency, uint16_t Duration)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,160);
	gtt_packetbuilder_writeU16(device,Frequency);
	gtt_packetbuilder_writeU16(device,Duration);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_create_slider_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, int16_t LT, int16_t RB, uint16_t TrkWidth, uint16_t TrkHeight, uint16_t BtnWidth, uint16_t BtnHeight, uint8_t TrkID, uint8_t BtnID, eSliderStyles Style)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,161);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,LT);
	gtt_packetbuilder_writeS16(device,RB);
	gtt_packetbuilder_writeU16(device,TrkWidth);
	gtt_packetbuilder_writeU16(device,TrkHeight);
	gtt_packetbuilder_writeU16(device,BtnWidth);
	gtt_packetbuilder_writeU16(device,BtnHeight);
	gtt_packetbuilder_writeU8(device,TrkID);
	gtt_packetbuilder_writeU8(device,BtnID);
	gtt_packetbuilder_writeU8(device,Style);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 161);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_create_scripted_toggle_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height, uint8_t OffID, uint8_t OnID, char * OffScript, char * OnScript)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,162);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_writeU8(device,OffID);
	gtt_packetbuilder_writeU8(device,OnID);
	gtt_packetbuilder_writeStringASCII(device,OffScript);
	gtt_packetbuilder_writeStringASCII(device,OnScript);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 162);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

uint8_t gtt_create_filled_slider(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, int16_t LT, int16_t RB, uint16_t TrkWidth, uint16_t TrkHeight, uint16_t BtnWidth, uint16_t BtnHeight, uint8_t TrkID, uint8_t FilID, uint8_t BtnID, eSliderStyles Style)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,163);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_writeS16(device,LT);
	gtt_packetbuilder_writeS16(device,RB);
	gtt_packetbuilder_writeU16(device,TrkWidth);
	gtt_packetbuilder_writeU16(device,TrkHeight);
	gtt_packetbuilder_writeU16(device,BtnWidth);
	gtt_packetbuilder_writeU16(device,BtnHeight);
	gtt_packetbuilder_writeU8(device,TrkID);
	gtt_packetbuilder_writeU8(device,FilID);
	gtt_packetbuilder_writeU8(device,BtnID);
	gtt_packetbuilder_writeU8(device,Style);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 163);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_set_auto_repeat(gtt_device *device, eKeypadRepeatMode Mode)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,165);
	gtt_packetbuilder_writeU8(device,Mode);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_set_slider_value(gtt_device *device, uint8_t RegionID, int16_t Value)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,166);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_writeS16(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 166);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

gtt_get_slider_value_return gtt_get_slider_value(gtt_device *device, uint8_t RegionID)
{
	gtt_get_slider_value_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,167);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 167);

	result.Result = gtt_parser_getU8(device,index, &index);
	result.Value = gtt_parser_getS16(device,index, &index);

	return result;
}

uint8_t gtt_set_toggle_state(gtt_device *device, uint8_t RegionID, uint8_t State)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,170);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_writeU8(device,State);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 170);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

gtt_get_toggle_state_return gtt_get_toggle_state(gtt_device *device, uint8_t RegionID)
{
	gtt_get_toggle_state_return result = { 0 };

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,171);
	gtt_packetbuilder_writeU8(device,RegionID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 171);

	result.Result = gtt_parser_getU8(device,index, &index);
	result.State = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_input_beep(gtt_device *device, eKeypadInputOutputType InputOutputType, uint16_t DownFrequency, uint16_t UpFrequency)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,182);
	gtt_packetbuilder_writeU8(device,InputOutputType);
	gtt_packetbuilder_writeU16(device,DownFrequency);
	gtt_packetbuilder_writeU16(device,UpFrequency);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_activate_motor_buzzer(gtt_device *device, uint16_t Frequency, uint16_t Duration)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,183);
	gtt_packetbuilder_writeU16(device,Frequency);
	gtt_packetbuilder_writeU16(device,Duration);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_buzzer_beep(gtt_device *device, uint16_t Frequency, uint16_t Duration)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,187);
	gtt_packetbuilder_writeU16(device,Frequency);
	gtt_packetbuilder_writeU16(device,Duration);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_default_buzzer_beep(gtt_device *device, uint16_t Frequency, uint16_t Duration)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,188);
	gtt_packetbuilder_writeU16(device,Frequency);
	gtt_packetbuilder_writeU16(device,Duration);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_load_animation(gtt_device *device, uint8_t AnimationID, char * Filename)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,192);
	gtt_packetbuilder_writeU8(device,AnimationID);
	gtt_packetbuilder_writeStringASCII(device,Filename);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_up_animation(gtt_device *device, uint8_t AnimationID, uint8_t AnimationInstance, int16_t X, int16_t Y)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,193);
	gtt_packetbuilder_writeU8(device,AnimationID);
	gtt_packetbuilder_writeU8(device,AnimationInstance);
	gtt_packetbuilder_writeS16(device,X);
	gtt_packetbuilder_writeS16(device,Y);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_start_stop_animation(gtt_device *device, uint8_t AnimationInstance, eAnimationState State)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,194);
	gtt_packetbuilder_writeU8(device,AnimationInstance);
	gtt_packetbuilder_writeU8(device,State);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_animation_state(gtt_device *device, uint8_t AnimationInstance, uint8_t Frame)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,195);
	gtt_packetbuilder_writeU8(device,AnimationInstance);
	gtt_packetbuilder_writeU8(device,Frame);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

uint8_t gtt_get_animation_state(gtt_device *device, uint8_t AnimationInstance)
{
	uint8_t result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,196);
	gtt_packetbuilder_writeU8(device,AnimationInstance);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 196);

	result = gtt_parser_getU8(device,index, &index);

	return result;
}

void gtt_stop_all_animations(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,198);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_clear_animation(gtt_device *device, uint8_t AnimationInstance)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,199);
	gtt_packetbuilder_writeU8(device,AnimationInstance);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_clear_all_animations(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,200);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_resume_all_animations(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,201);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_write_scratch_pad(gtt_device *device, uint16_t Index, gtt_bytearray_l16  Data)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,204);
	gtt_packetbuilder_writeU16(device,Index);
	gtt_packetbuilder_writeByteArrayL16(device,Data);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

gtt_bytearray_l16  gtt_read_scratch_pad(gtt_device *device, uint16_t Index, uint16_t Size)
{
	gtt_bytearray_l16  result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,205);
	gtt_packetbuilder_writeU16(device,Index);
	gtt_packetbuilder_writeU16(device,Size);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 205);

	result = gtt_parser_getByteArrayL16(device,index, &index);

	return result;
}

void gtt_clear_a_buffer(gtt_device *device, eBuffers Type, uint8_t ID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,208);
	gtt_packetbuilder_writeU8(device,Type);
	gtt_packetbuilder_writeU8(device,ID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_clear_all_buffers(gtt_device *device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,209);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_font_render_style(gtt_device *device, eFontRenderType RenderType)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,211);
	gtt_packetbuilder_writeU8(device,RenderType);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_font_anchor(gtt_device *device, eAnchorType AnchorType)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,212);
	gtt_packetbuilder_writeU8(device,AnchorType);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_assign_key_codes(gtt_device *device, gtt_bytearray_l8  KeyCodes)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,213);
	gtt_packetbuilder_writeByteArrayL8(device,KeyCodes);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

void gtt_set_i2c_address(gtt_device *device, uint8_t I2Caddress)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,247);
	gtt_packetbuilder_writeU8(device,I2Caddress);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
}

char * gtt_echo(gtt_device *device, char * Message)
{
	char * result;

	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,255);
	gtt_packetbuilder_writeStringASCII(device,Message);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket(device, 255);

	result = gtt_parser_getStringASCII(device,index, &index);

	return result;
}

eStatusCode gtt25_baseobject_create(gtt_device* device, eObjectType ObjectType, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_Create);
	gtt_packetbuilder_writeU16(device,ObjectType);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_Create);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_destroy(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_Destroy);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_Destroy);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_begin_update(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_BeginUpdate);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_BeginUpdate);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_end_update(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_EndUpdate);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_EndUpdate);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_set_property_u8(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, uint8_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_SetPropertyU8);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU8(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_SetPropertyU8);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_get_property_u8(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, uint8_t* out_Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_GetPropertyU8);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_GetPropertyU8);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Value = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_set_property_u16(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, uint16_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_SetPropertyU16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU16(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_SetPropertyU16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_get_property_u16(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, uint16_t* out_Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_GetPropertyU16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_GetPropertyU16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Value = gtt_parser_getU16(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_set_property_s16(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, int16_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_SetPropertyS16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeS16(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_SetPropertyS16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_get_property_s16(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, int16_t* out_Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_GetPropertyS16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_GetPropertyS16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Value = gtt_parser_getS16(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_set_property_text(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, gtt_text  Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_SetPropertyText);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeText(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_SetPropertyText);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_get_property_text(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, gtt_text * out_Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_GetPropertyText);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_GetPropertyText);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Value = gtt_parser_getText(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_set_property_eval(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, gtt_text  Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_SetPropertyEval);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeText(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_SetPropertyEval);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_destroy_all(gtt_device* device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_DestroyAll);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_DestroyAll);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_get_object_type(gtt_device* device, uint16_t ObjectID, eObjectType* out_ObjectType)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_GetObjectType);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_GetObjectType);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_ObjectType = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_append_property_text(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, gtt_text  Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_AppendPropertyText);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeText(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_AppendPropertyText);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_set_event_handler(gtt_device* device, uint16_t ObjectID, eEventID EventID, uint16_t EventGraphObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_SetEventHandler);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,EventID);
	gtt_packetbuilder_writeU16(device,EventGraphObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_SetEventHandler);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_set_property_float(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, float Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_SetPropertyFloat);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeFloat(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_SetPropertyFloat);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_get_property_float(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, float* out_Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_GetPropertyFloat);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_GetPropertyFloat);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Value = gtt_parser_getFloat(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_baseobject_process_changes(gtt_device* device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_BaseObject_ProcessChanges);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_BaseObject_ProcessChanges);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_baseobject_protected(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_BaseObject_Protected,(uint8_t*)result);
}

eStatusCode gtt25_set_baseobject_protected(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_BaseObject_Protected,value);
}

eStatusCode gtt25_visualobject_invalidate(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_VisualObject_Invalidate);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_VisualObject_Invalidate);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_visualobject_add_dependency(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_VisualObject_AddDependency);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_VisualObject_AddDependency);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_visualobject_set_focus(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_VisualObject_SetFocus);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_VisualObject_SetFocus);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_visualobject_next_focus(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_VisualObject_NextFocus);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_VisualObject_NextFocus);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_visualobject_prev_focus(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_VisualObject_PrevFocus);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_VisualObject_PrevFocus);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_visualobject_global_next_focus(gtt_device* device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_VisualObject_GlobalNextFocus);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_VisualObject_GlobalNextFocus);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_visualobject_global_prev_focus(gtt_device* device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_VisualObject_GlobalPrevFocus);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_VisualObject_GlobalPrevFocus);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_visualobject_invalidated(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_VisualObject_Invalidated,(uint8_t*)result);
}

eStatusCode gtt25_set_visualobject_invalidated(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_VisualObject_Invalidated,value);
}

eStatusCode gtt25_get_visualobject_left(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_VisualObject_Left,(int16_t*)result);
}

eStatusCode gtt25_set_visualobject_left(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_VisualObject_Left,value);
}

eStatusCode gtt25_get_visualobject_top(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_VisualObject_Top,(int16_t*)result);
}

eStatusCode gtt25_set_visualobject_top(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_VisualObject_Top,value);
}

eStatusCode gtt25_get_visualobject_width(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_VisualObject_Width,(uint16_t*)result);
}

eStatusCode gtt25_set_visualobject_width(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_VisualObject_Width,value);
}

eStatusCode gtt25_get_visualobject_height(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_VisualObject_Height,(uint16_t*)result);
}

eStatusCode gtt25_set_visualobject_height(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_VisualObject_Height,value);
}

eStatusCode gtt25_get_visualobject_can_focus(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_VisualObject_CanFocus,(uint8_t*)result);
}

eStatusCode gtt25_set_visualobject_can_focus(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_VisualObject_CanFocus,value);
}

eStatusCode gtt25_get_visualobject_has_focus(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_VisualObject_HasFocus,(uint8_t*)result);
}

eStatusCode gtt25_set_visualobject_has_focus(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_VisualObject_HasFocus,value);
}

eStatusCode gtt25_get_visualobject_enabled(gtt_device * device, uint16_t ObjectID, eOnOff* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_VisualObject_Enabled,(uint8_t*)result);
}

eStatusCode gtt25_set_visualobject_enabled(gtt_device * device, uint16_t ObjectID, eOnOff value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_VisualObject_Enabled,value);
}

eStatusCode gtt25_get_gauge_min_value(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Gauge_MinValue,(int16_t*)result);
}

eStatusCode gtt25_set_gauge_min_value(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Gauge_MinValue,value);
}

eStatusCode gtt25_get_gauge_max_value(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Gauge_MaxValue,(int16_t*)result);
}

eStatusCode gtt25_set_gauge_max_value(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Gauge_MaxValue,value);
}

eStatusCode gtt25_get_gauge_value(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Gauge_Value,(int16_t*)result);
}

eStatusCode gtt25_set_gauge_value(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Gauge_Value,value);
}

eStatusCode gtt25_get_gauge_start_angle(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Gauge_StartAngle,(int16_t*)result);
}

eStatusCode gtt25_set_gauge_start_angle(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Gauge_StartAngle,value);
}

eStatusCode gtt25_get_gauge_end_angle(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Gauge_EndAngle,(int16_t*)result);
}

eStatusCode gtt25_set_gauge_end_angle(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Gauge_EndAngle,value);
}

eStatusCode gtt25_get_gauge_needle_color_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleColorR,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_needle_color_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleColorR,value);
}

eStatusCode gtt25_get_gauge_needle_color_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleColorG,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_needle_color_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleColorG,value);
}

eStatusCode gtt25_get_gauge_needle_color_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleColorB,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_needle_color_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleColorB,value);
}

eStatusCode gtt25_get_gauge_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_BackgroundR,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_BackgroundR,value);
}

eStatusCode gtt25_get_gauge_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_BackgroundG,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_BackgroundG,value);
}

eStatusCode gtt25_get_gauge_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_BackgroundB,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_BackgroundB,value);
}

eStatusCode gtt25_get_gauge_needle_width(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleWidth,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_needle_width(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleWidth,value);
}

eStatusCode gtt25_get_gauge_background_image(gtt_device * device, uint16_t ObjectID, gtt_text * result)
{
	return gtt25_baseobject_get_property_text(device,ObjectID,ePropertyID_Gauge_BackgroundImage,(gtt_text *)result);
}

eStatusCode gtt25_set_gauge_background_image(gtt_device * device, uint16_t ObjectID, gtt_text  value)
{
	return gtt25_baseobject_set_property_text(device,ObjectID,ePropertyID_Gauge_BackgroundImage,value);
}

eStatusCode gtt25_get_gauge_animation_speed(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Gauge_AnimationSpeed,(uint16_t*)result);
}

eStatusCode gtt25_set_gauge_animation_speed(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Gauge_AnimationSpeed,value);
}

eStatusCode gtt25_get_gauge_base_radius(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_BaseRadius,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_base_radius(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_BaseRadius,value);
}

eStatusCode gtt25_get_gauge_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Gauge_LabelFontObject,(uint16_t*)result);
}

eStatusCode gtt25_set_gauge_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Gauge_LabelFontObject,value);
}

eStatusCode gtt25_get_gauge_label_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_LabelR,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_label_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_LabelR,value);
}

eStatusCode gtt25_get_gauge_label_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_LabelG,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_label_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_LabelG,value);
}

eStatusCode gtt25_get_gauge_label_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_LabelB,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_label_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_LabelB,value);
}

eStatusCode gtt25_get_gauge_label_text(gtt_device * device, uint16_t ObjectID, gtt_text * result)
{
	return gtt25_baseobject_get_property_text(device,ObjectID,ePropertyID_Gauge_LabelText,(gtt_text *)result);
}

eStatusCode gtt25_set_gauge_label_text(gtt_device * device, uint16_t ObjectID, gtt_text  value)
{
	return gtt25_baseobject_set_property_text(device,ObjectID,ePropertyID_Gauge_LabelText,value);
}

eStatusCode gtt25_get_gauge_label_left(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Gauge_LabelLeft,(uint16_t*)result);
}

eStatusCode gtt25_set_gauge_label_left(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Gauge_LabelLeft,value);
}

eStatusCode gtt25_get_gauge_label_top(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Gauge_LabelTop,(uint16_t*)result);
}

eStatusCode gtt25_set_gauge_label_top(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Gauge_LabelTop,value);
}

eStatusCode gtt25_get_gauge_label_width(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Gauge_LabelWidth,(uint16_t*)result);
}

eStatusCode gtt25_set_gauge_label_width(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Gauge_LabelWidth,value);
}

eStatusCode gtt25_get_gauge_label_height(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Gauge_LabelHeight,(uint16_t*)result);
}

eStatusCode gtt25_set_gauge_label_height(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Gauge_LabelHeight,value);
}

eStatusCode gtt25_get_gauge_needle_x(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Gauge_NeedleX,(int16_t*)result);
}

eStatusCode gtt25_set_gauge_needle_x(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Gauge_NeedleX,value);
}

eStatusCode gtt25_get_gauge_needle_y(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Gauge_NeedleY,(int16_t*)result);
}

eStatusCode gtt25_set_gauge_needle_y(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Gauge_NeedleY,value);
}

eStatusCode gtt25_get_gauge_needle_start_radius(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Gauge_NeedleStartRadius,(int16_t*)result);
}

eStatusCode gtt25_set_gauge_needle_start_radius(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Gauge_NeedleStartRadius,value);
}

eStatusCode gtt25_get_gauge_needle_end_radius(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Gauge_NeedleEndRadius,(int16_t*)result);
}

eStatusCode gtt25_set_gauge_needle_end_radius(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Gauge_NeedleEndRadius,value);
}

eStatusCode gtt25_get_gauge_needle_location(gtt_device * device, uint16_t ObjectID, eNeedleLocation* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleLocation,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_needle_location(gtt_device * device, uint16_t ObjectID, eNeedleLocation value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleLocation,value);
}

eStatusCode gtt25_get_gauge_needle_mode(gtt_device * device, uint16_t ObjectID, eNeedleMode* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleMode,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_needle_mode(gtt_device * device, uint16_t ObjectID, eNeedleMode value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleMode,value);
}

eStatusCode gtt25_get_gauge_needle_width_tip(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleWidthTip,(uint8_t*)result);
}

eStatusCode gtt25_set_gauge_needle_width_tip(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Gauge_NeedleWidthTip,value);
}

eStatusCode gtt25_get_gauge_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Gauge_LabelFontSize,(uint16_t*)result);
}

eStatusCode gtt25_set_gauge_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Gauge_LabelFontSize,value);
}

eStatusCode gtt25_strokepad_clear(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StrokePad_Clear);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StrokePad_Clear);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_strokepad_get_stroke_count(gtt_device* device, uint16_t ObjectID, uint32_t* out_Count)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StrokePad_GetStrokeCount);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StrokePad_GetStrokeCount);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Count = gtt_parser_getU32(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_strokepad_get_stroke(gtt_device* device, uint16_t ObjectID, uint32_t StrokeID, gtt_wordarray_l32* out_StrokeData)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StrokePad_GetStroke);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU32(device,StrokeID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StrokePad_GetStroke);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_StrokeData = gtt_parser_getWordArrayL32(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_strokepad_stroke_color_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_StrokePad_StrokeColorR,(uint8_t*)result);
}

eStatusCode gtt25_set_strokepad_stroke_color_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_StrokePad_StrokeColorR,value);
}

eStatusCode gtt25_get_strokepad_stroke_color_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_StrokePad_StrokeColorG,(uint8_t*)result);
}

eStatusCode gtt25_set_strokepad_stroke_color_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_StrokePad_StrokeColorG,value);
}

eStatusCode gtt25_get_strokepad_stroke_color_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_StrokePad_StrokeColorB,(uint8_t*)result);
}

eStatusCode gtt25_set_strokepad_stroke_color_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_StrokePad_StrokeColorB,value);
}

eStatusCode gtt25_get_strokepad_color_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_StrokePad_ColorR,(uint8_t*)result);
}

eStatusCode gtt25_set_strokepad_color_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_StrokePad_ColorR,value);
}

eStatusCode gtt25_get_strokepad_color_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_StrokePad_ColorG,(uint8_t*)result);
}

eStatusCode gtt25_set_strokepad_color_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_StrokePad_ColorG,value);
}

eStatusCode gtt25_get_strokepad_color_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_StrokePad_ColorB,(uint8_t*)result);
}

eStatusCode gtt25_set_strokepad_color_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_StrokePad_ColorB,value);
}

eStatusCode gtt25_storyboard_set_value_u8(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint8_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_SetValueU8);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_writeU8(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_SetValueU8);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_set_value_u16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint16_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_SetValueU16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_writeU16(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_SetValueU16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_set_value_s16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, int16_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_SetValueS16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_writeS16(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_SetValueS16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_set_value_u32(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint32_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_SetValueU32);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_writeU32(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_SetValueU32);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_start(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_Start);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_Start);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_stop(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_Stop);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_Stop);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_animate_value_u8(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint16_t Duration, uint8_t Value, eEasing Easing)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_AnimateValueU8);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_writeU16(device,Duration);
	gtt_packetbuilder_writeU8(device,Value);
	gtt_packetbuilder_writeU8(device,Easing);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_AnimateValueU8);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_animate_value_s16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint16_t Duration, int16_t Value, eEasing Easing)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_AnimateValueS16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_writeU16(device,Duration);
	gtt_packetbuilder_writeS16(device,Value);
	gtt_packetbuilder_writeU8(device,Easing);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_AnimateValueS16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_set_value_string(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, gtt_text  Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_SetValueString);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_writeText(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_SetValueString);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_beep(gtt_device* device, uint16_t ObjectID, uint16_t Time, uint16_t Frequency, uint16_t Duration)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_Beep);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_writeU16(device,Frequency);
	gtt_packetbuilder_writeU16(device,Duration);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_Beep);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_storyboard_animate_value_u16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint16_t Duration, uint16_t Value, eEasing Easing)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_StoryBoard_AnimateValueU16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,PropertyID);
	gtt_packetbuilder_writeU16(device,Time);
	gtt_packetbuilder_writeU16(device,Duration);
	gtt_packetbuilder_writeU16(device,Value);
	gtt_packetbuilder_writeU8(device,Easing);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_StoryBoard_AnimateValueU16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_storyboard_duration(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_StoryBoard_Duration,(uint16_t*)result);
}

eStatusCode gtt25_set_storyboard_duration(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_StoryBoard_Duration,value);
}

eStatusCode gtt25_get_storyboard_loops(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_StoryBoard_Loops,(uint16_t*)result);
}

eStatusCode gtt25_set_storyboard_loops(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_StoryBoard_Loops,value);
}

eStatusCode gtt25_get_rectangle_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Rectangle_BackgroundR,(uint8_t*)result);
}

eStatusCode gtt25_set_rectangle_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Rectangle_BackgroundR,value);
}

eStatusCode gtt25_get_rectangle_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Rectangle_BackgroundG,(uint8_t*)result);
}

eStatusCode gtt25_set_rectangle_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Rectangle_BackgroundG,value);
}

eStatusCode gtt25_get_rectangle_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Rectangle_BackgroundB,(uint8_t*)result);
}

eStatusCode gtt25_set_rectangle_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Rectangle_BackgroundB,value);
}

eStatusCode gtt25_trigger_create_trigger(gtt_device* device, uint16_t ObjectID, uint16_t ConditionId, uint8_t ConditionTrue, eAction Action, uint16_t ExtraData)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Trigger_CreateTrigger);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,ConditionId);
	gtt_packetbuilder_writeU8(device,ConditionTrue);
	gtt_packetbuilder_writeU8(device,Action);
	gtt_packetbuilder_writeU16(device,ExtraData);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Trigger_CreateTrigger);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_trigger_set_property_eval(gtt_device* device, uint16_t ObjectID, uint16_t ConditionId, uint8_t ConditionTrue, uint16_t TargetObject, ePropertyID TargetProperty, gtt_text  Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Trigger_SetPropertyEval);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,ConditionId);
	gtt_packetbuilder_writeU8(device,ConditionTrue);
	gtt_packetbuilder_writeU16(device,TargetObject);
	gtt_packetbuilder_writeU16(device,TargetProperty);
	gtt_packetbuilder_writeText(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Trigger_SetPropertyEval);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_condition_create_property_u8(gtt_device* device, uint16_t ObjectID, uint16_t TargetObject, ePropertyID TargetProperty, eComparison Comparison, uint8_t CompareValue)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Condition_CreatePropertyU8);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObject);
	gtt_packetbuilder_writeU16(device,TargetProperty);
	gtt_packetbuilder_writeU8(device,Comparison);
	gtt_packetbuilder_writeU8(device,CompareValue);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Condition_CreatePropertyU8);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_condition_create_property_u16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObject, ePropertyID TargetProperty, eComparison Comparison, uint16_t CompareValue)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Condition_CreatePropertyU16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetObject);
	gtt_packetbuilder_writeU16(device,TargetProperty);
	gtt_packetbuilder_writeU8(device,Comparison);
	gtt_packetbuilder_writeU16(device,CompareValue);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Condition_CreatePropertyU16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_condition_create_logical(gtt_device* device, uint16_t ObjectID, uint16_t ConditionA, uint16_t ConditionB, eLogicalComparison Comparison)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Condition_CreateLogical);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,ConditionA);
	gtt_packetbuilder_writeU16(device,ConditionB);
	gtt_packetbuilder_writeU8(device,Comparison);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Condition_CreateLogical);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_condition_value(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Condition_Value,(uint8_t*)result);
}

eStatusCode gtt25_set_condition_value(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Condition_Value,value);
}

eStatusCode gtt25_get_label_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Label_BackgroundR,(uint8_t*)result);
}

eStatusCode gtt25_set_label_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Label_BackgroundR,value);
}

eStatusCode gtt25_get_label_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Label_BackgroundG,(uint8_t*)result);
}

eStatusCode gtt25_set_label_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Label_BackgroundG,value);
}

eStatusCode gtt25_get_label_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Label_BackgroundB,(uint8_t*)result);
}

eStatusCode gtt25_set_label_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Label_BackgroundB,value);
}

eStatusCode gtt25_get_label_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Label_ForegroundR,(uint8_t*)result);
}

eStatusCode gtt25_set_label_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Label_ForegroundR,value);
}

eStatusCode gtt25_get_label_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Label_ForegroundG,(uint8_t*)result);
}

eStatusCode gtt25_set_label_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Label_ForegroundG,value);
}

eStatusCode gtt25_get_label_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Label_ForegroundB,(uint8_t*)result);
}

eStatusCode gtt25_set_label_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Label_ForegroundB,value);
}

eStatusCode gtt25_get_label_text(gtt_device * device, uint16_t ObjectID, gtt_text * result)
{
	return gtt25_baseobject_get_property_text(device,ObjectID,ePropertyID_Label_Text,(gtt_text *)result);
}

eStatusCode gtt25_set_label_text(gtt_device * device, uint16_t ObjectID, gtt_text  value)
{
	return gtt25_baseobject_set_property_text(device,ObjectID,ePropertyID_Label_Text,value);
}

eStatusCode gtt25_get_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Label_FontObject,(uint16_t*)result);
}

eStatusCode gtt25_set_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Label_FontObject,value);
}

eStatusCode gtt25_get_label_h_align(gtt_device * device, uint16_t ObjectID, eLabelHorizontalAlignment* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Label_HAlign,(uint8_t*)result);
}

eStatusCode gtt25_set_label_h_align(gtt_device * device, uint16_t ObjectID, eLabelHorizontalAlignment value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Label_HAlign,value);
}

eStatusCode gtt25_get_label_v_align(gtt_device * device, uint16_t ObjectID, eLabelVerticalAlignment* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Label_VAlign,(uint8_t*)result);
}

eStatusCode gtt25_set_label_v_align(gtt_device * device, uint16_t ObjectID, eLabelVerticalAlignment value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Label_VAlign,value);
}

eStatusCode gtt25_get_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Label_FontSize,(uint16_t*)result);
}

eStatusCode gtt25_set_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Label_FontSize,value);
}

eStatusCode gtt25_get_label_objid__background(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Label_ObjID_Background,(uint16_t*)result);
}

eStatusCode gtt25_set_label_objid__background(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Label_ObjID_Background,value);
}

eStatusCode gtt25_get_label_grayscale(gtt_device * device, uint16_t ObjectID, eOnOff* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Label_Grayscale,(uint8_t*)result);
}

eStatusCode gtt25_set_label_grayscale(gtt_device * device, uint16_t ObjectID, eOnOff value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Label_Grayscale,value);
}

eStatusCode gtt25_get_slider_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_BackgroundR,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_BackgroundR,value);
}

eStatusCode gtt25_get_slider_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_BackgroundG,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_BackgroundG,value);
}

eStatusCode gtt25_get_slider_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_BackgroundB,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_BackgroundB,value);
}

eStatusCode gtt25_get_slider_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_ForegroundR,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_ForegroundR,value);
}

eStatusCode gtt25_get_slider_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_ForegroundG,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_ForegroundG,value);
}

eStatusCode gtt25_get_slider_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_ForegroundB,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_ForegroundB,value);
}

eStatusCode gtt25_get_slider_minimum(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Slider_Minimum,(int16_t*)result);
}

eStatusCode gtt25_set_slider_minimum(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Slider_Minimum,value);
}

eStatusCode gtt25_get_slider_maximum(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Slider_Maximum,(int16_t*)result);
}

eStatusCode gtt25_set_slider_maximum(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Slider_Maximum,value);
}

eStatusCode gtt25_get_slider_value(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Slider_Value,(int16_t*)result);
}

eStatusCode gtt25_set_slider_value(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Slider_Value,value);
}

eStatusCode gtt25_get_slider_label_text(gtt_device * device, uint16_t ObjectID, gtt_text * result)
{
	return gtt25_baseobject_get_property_text(device,ObjectID,ePropertyID_Slider_LabelText,(gtt_text *)result);
}

eStatusCode gtt25_set_slider_label_text(gtt_device * device, uint16_t ObjectID, gtt_text  value)
{
	return gtt25_baseobject_set_property_text(device,ObjectID,ePropertyID_Slider_LabelText,value);
}

eStatusCode gtt25_get_slider_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_LabelFontObject,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_LabelFontObject,value);
}

eStatusCode gtt25_get_slider_label_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_LabelR,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_label_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_LabelR,value);
}

eStatusCode gtt25_get_slider_label_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_LabelG,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_label_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_LabelG,value);
}

eStatusCode gtt25_get_slider_label_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_LabelB,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_label_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_LabelB,value);
}

eStatusCode gtt25_get_slider_style(gtt_device * device, uint16_t ObjectID, eSliderStyle* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_Style,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_style(gtt_device * device, uint16_t ObjectID, eSliderStyle value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_Style,value);
}

eStatusCode gtt25_get_slider_objid__nine_fore_ground(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_NineForeGround,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_objid__nine_fore_ground(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_NineForeGround,value);
}

eStatusCode gtt25_get_slider_objid__nine_back_ground(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_NineBackGround,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_objid__nine_back_ground(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_NineBackGround,value);
}

eStatusCode gtt25_get_slider_objid__nine_button(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_NineButton,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_objid__nine_button(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_NineButton,value);
}

eStatusCode gtt25_get_slider_button_width(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ButtonWidth,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_button_width(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ButtonWidth,value);
}

eStatusCode gtt25_get_slider_button_height(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ButtonHeight,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_button_height(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ButtonHeight,value);
}

eStatusCode gtt25_get_slider_enable_touch(gtt_device * device, uint16_t ObjectID, eOnOff* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_EnableTouch,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_enable_touch(gtt_device * device, uint16_t ObjectID, eOnOff value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_EnableTouch,value);
}

eStatusCode gtt25_get_slider_direction(gtt_device * device, uint16_t ObjectID, eSliderDirection* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_Direction,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_direction(gtt_device * device, uint16_t ObjectID, eSliderDirection value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_Direction,value);
}

eStatusCode gtt25_get_slider_track_size(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_TrackSize,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_track_size(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_TrackSize,value);
}

eStatusCode gtt25_get_slider_objid__background(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_Background,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_objid__background(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_Background,value);
}

eStatusCode gtt25_get_slider_objid__bitmap_fore_ground(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_BitmapForeGround,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_objid__bitmap_fore_ground(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_BitmapForeGround,value);
}

eStatusCode gtt25_get_slider_objid__bitmap_back_ground(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_BitmapBackGround,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_objid__bitmap_back_ground(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_BitmapBackGround,value);
}

eStatusCode gtt25_get_slider_objid__bitmap_button(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_BitmapButton,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_objid__bitmap_button(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_BitmapButton,value);
}

eStatusCode gtt25_get_slider_button_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_ButtonR,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_button_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_ButtonR,value);
}

eStatusCode gtt25_get_slider_button_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_ButtonG,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_button_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_ButtonG,value);
}

eStatusCode gtt25_get_slider_button_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_ButtonB,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_button_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_ButtonB,value);
}

eStatusCode gtt25_get_slider_draw_button(gtt_device * device, uint16_t ObjectID, eOnOff* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_DrawButton,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_draw_button(gtt_device * device, uint16_t ObjectID, eOnOff value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_DrawButton,value);
}

eStatusCode gtt25_get_slider_pad_button(gtt_device * device, uint16_t ObjectID, eOnOff* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_PadButton,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_pad_button(gtt_device * device, uint16_t ObjectID, eOnOff value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_PadButton,value);
}

eStatusCode gtt25_get_slider_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_LabelFontSize,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_LabelFontSize,value);
}

eStatusCode gtt25_get_slider_label_on_button(gtt_device * device, uint16_t ObjectID, eOnOff* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_LabelOnButton,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_label_on_button(gtt_device * device, uint16_t ObjectID, eOnOff value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_LabelOnButton,value);
}

eStatusCode gtt25_get_slider_origin(gtt_device * device, uint16_t ObjectID, eSliderOrigin* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Slider_Origin,(uint8_t*)result);
}

eStatusCode gtt25_set_slider_origin(gtt_device * device, uint16_t ObjectID, eSliderOrigin value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Slider_Origin,value);
}

eStatusCode gtt25_get_slider_offset(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_Slider_Offset,(int16_t*)result);
}

eStatusCode gtt25_set_slider_offset(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_Slider_Offset,value);
}

eStatusCode gtt25_get_slider_objid__bitmap_mask(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_BitmapMask,(uint16_t*)result);
}

eStatusCode gtt25_set_slider_objid__bitmap_mask(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Slider_ObjID_BitmapMask,value);
}

eStatusCode gtt25_databinding_setup_binding(gtt_device* device, uint16_t ObjectID, uint16_t SourceObjectID, ePropertyID SourcePropertyID, uint16_t TargetObjectID, ePropertyID TargetPropertyID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_DataBinding_SetupBinding);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,SourceObjectID);
	gtt_packetbuilder_writeU16(device,SourcePropertyID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,TargetPropertyID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_DataBinding_SetupBinding);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_databinding_setup_eval_binding(gtt_device* device, uint16_t ObjectID, uint16_t SourceObjectID, ePropertyID SourcePropertyID, uint16_t TargetObjectID, ePropertyID TargetPropertyID, gtt_text  Equation)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_DataBinding_SetupEvalBinding);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,SourceObjectID);
	gtt_packetbuilder_writeU16(device,SourcePropertyID);
	gtt_packetbuilder_writeU16(device,TargetObjectID);
	gtt_packetbuilder_writeU16(device,TargetPropertyID);
	gtt_packetbuilder_writeText(device,Equation);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_DataBinding_SetupEvalBinding);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_nineslice_load(gtt_device* device, uint16_t ObjectID, gtt_text  Path)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_NineSlice_Load);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_NineSlice_Load);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_bitmap_load(gtt_device* device, uint16_t ObjectID, gtt_text  Path)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Bitmap_Load);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Bitmap_Load);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_bitmap_capture(gtt_device* device, uint16_t ObjectID, uint16_t Left, uint16_t Top, uint16_t Width, uint16_t Height)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Bitmap_Capture);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,Left);
	gtt_packetbuilder_writeU16(device,Top);
	gtt_packetbuilder_writeU16(device,Width);
	gtt_packetbuilder_writeU16(device,Height);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Bitmap_Capture);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_font_load(gtt_device* device, uint16_t ObjectID, gtt_text  Path)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Font_Load);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Font_Load);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_font_cache(gtt_device* device, uint16_t ObjectID, uint8_t FontSize, eOnOff GreyScale, gtt_text  Text)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Font_Cache);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU8(device,FontSize);
	gtt_packetbuilder_writeU8(device,GreyScale);
	gtt_packetbuilder_writeText(device,Text);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Font_Cache);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_font_clear_cache(gtt_device* device, uint16_t ObjectID, uint8_t FontSize)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Font_ClearCache);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU8(device,FontSize);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Font_ClearCache);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_font_clear_cache_all(gtt_device* device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Font_ClearCacheAll);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Font_ClearCacheAll);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_font_set_auto_cache_size_limit(gtt_device* device, uint32_t Size)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Font_SetAutoCacheSizeLimit);
	gtt_packetbuilder_writeU32(device,Size);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Font_SetAutoCacheSizeLimit);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_get_file_size(gtt_device* device, gtt_text  Path, uint32_t* out_Size)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_GetFileSize);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_GetFileSize);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Size = gtt_parser_getU32(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_get_free_space(gtt_device* device, uint32_t* out_Size)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_GetFreeSpace);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_GetFreeSpace);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Size = gtt_parser_getU32(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_move(gtt_device* device, gtt_text  FromPath, gtt_text  ToPath)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_Move);
	gtt_packetbuilder_writeText(device,FromPath);
	gtt_packetbuilder_writeText(device,ToPath);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_Move);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_get_crc(gtt_device* device, gtt_text  Path, uint32_t* out_CRC)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_GetCRC);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_GetCRC);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_CRC = gtt_parser_getU32(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_get_files(gtt_device* device, gtt_text  Path, gtt_bytearray_l16* out_Result)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_GetFiles);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_GetFiles);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Result = gtt_parser_getByteArrayL16(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_create_folder(gtt_device* device, gtt_text  Path)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_CreateFolder);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_CreateFolder);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_delete_folder(gtt_device* device, gtt_text  Path, uint8_t Recursive)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_DeleteFolder);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_writeU8(device,Recursive);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_DeleteFolder);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_file_write(gtt_device* device, gtt_text  Path, uint32_t Index, gtt_bytearray_l16 FileData)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_FileWrite);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_writeU32(device,Index);
	gtt_packetbuilder_writeByteArrayL16(device,FileData);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_FileWrite);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_file_read(gtt_device* device, gtt_text  Path, uint32_t Index, uint16_t Length, gtt_bytearray_l16* out_FileData)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_FileRead);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_writeU32(device,Index);
	gtt_packetbuilder_writeU16(device,Length);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_FileRead);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_FileData = gtt_parser_getByteArrayL16(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_file_delete(gtt_device* device, gtt_text  Path)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_FileDelete);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_FileDelete);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_start_xmodem_upload(gtt_device* device, gtt_text  Path, uint32_t Length)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_StartXmodemUpload);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_writeU32(device,Length);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_StartXmodemUpload);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_filesystem_test_method(gtt_device* device, gtt_text  Path, uint32_t* out_Size)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_FileSystem_TestMethod);
	gtt_packetbuilder_writeText(device,Path);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_FileSystem_TestMethod);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Size = gtt_parser_getU32(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_tracebinding_trace_slot(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_TraceBinding_TraceSlot,(uint8_t*)result);
}

eStatusCode gtt25_set_tracebinding_trace_slot(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_TraceBinding_TraceSlot,value);
}

eStatusCode gtt25_get_tracebinding_value(gtt_device * device, uint16_t ObjectID, int16_t* result)
{
	return gtt25_baseobject_get_property_s16(device,ObjectID,ePropertyID_TraceBinding_Value,(int16_t*)result);
}

eStatusCode gtt25_set_tracebinding_value(gtt_device * device, uint16_t ObjectID, int16_t value)
{
	return gtt25_baseobject_set_property_s16(device,ObjectID,ePropertyID_TraceBinding_Value,value);
}

eStatusCode gtt25_eventgraph_create_node(gtt_device* device, uint16_t ObjectID, uint16_t NodeID, eEventNodeType NodeType)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_EventGraph_CreateNode);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,NodeID);
	gtt_packetbuilder_writeU16(device,NodeType);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_EventGraph_CreateNode);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_eventgraph_add_link(gtt_device* device, uint16_t ObjectID, uint16_t SourceNodeID, eEventNodeSocket SourceOutput, uint16_t TargetNodeID, eEventNodeSocket TargetInput)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_EventGraph_AddLink);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,SourceNodeID);
	gtt_packetbuilder_writeU16(device,SourceOutput);
	gtt_packetbuilder_writeU16(device,TargetNodeID);
	gtt_packetbuilder_writeU16(device,TargetInput);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_EventGraph_AddLink);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_eventgraph_set_node_value_text(gtt_device* device, uint16_t ObjectID, uint16_t TargetNodeID, eEventNodeSocket TargetInput, gtt_text  Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_EventGraph_SetNodeValueText);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetNodeID);
	gtt_packetbuilder_writeU16(device,TargetInput);
	gtt_packetbuilder_writeText(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_EventGraph_SetNodeValueText);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_eventgraph_set_node_value_u8(gtt_device* device, uint16_t ObjectID, uint16_t TargetNodeID, eEventNodeSocket TargetInput, uint8_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_EventGraph_SetNodeValueU8);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetNodeID);
	gtt_packetbuilder_writeU16(device,TargetInput);
	gtt_packetbuilder_writeU8(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_EventGraph_SetNodeValueU8);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_eventgraph_set_node_value_u16(gtt_device* device, uint16_t ObjectID, uint16_t TargetNodeID, eEventNodeSocket TargetInput, uint16_t Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_EventGraph_SetNodeValueU16);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetNodeID);
	gtt_packetbuilder_writeU16(device,TargetInput);
	gtt_packetbuilder_writeU16(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_EventGraph_SetNodeValueU16);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_eventgraph_set_node_value_float(gtt_device* device, uint16_t ObjectID, uint16_t TargetNodeID, eEventNodeSocket TargetInput, float Value)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_EventGraph_SetNodeValueFloat);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,TargetNodeID);
	gtt_packetbuilder_writeU16(device,TargetInput);
	gtt_packetbuilder_writeFloat(device,Value);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_EventGraph_SetNodeValueFloat);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_button_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_BackgroundR,(uint8_t*)result);
}

eStatusCode gtt25_set_button_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_BackgroundR,value);
}

eStatusCode gtt25_get_button_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_BackgroundG,(uint8_t*)result);
}

eStatusCode gtt25_set_button_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_BackgroundG,value);
}

eStatusCode gtt25_get_button_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_BackgroundB,(uint8_t*)result);
}

eStatusCode gtt25_set_button_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_BackgroundB,value);
}

eStatusCode gtt25_get_button_text(gtt_device * device, uint16_t ObjectID, gtt_text * result)
{
	return gtt25_baseobject_get_property_text(device,ObjectID,ePropertyID_Button_Text,(gtt_text *)result);
}

eStatusCode gtt25_set_button_text(gtt_device * device, uint16_t ObjectID, gtt_text  value)
{
	return gtt25_baseobject_set_property_text(device,ObjectID,ePropertyID_Button_Text,value);
}

eStatusCode gtt25_get_button_font_object(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Button_FontObject,(uint16_t*)result);
}

eStatusCode gtt25_set_button_font_object(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Button_FontObject,value);
}

eStatusCode gtt25_get_button_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_ForegroundR,(uint8_t*)result);
}

eStatusCode gtt25_set_button_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_ForegroundR,value);
}

eStatusCode gtt25_get_button_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_ForegroundG,(uint8_t*)result);
}

eStatusCode gtt25_set_button_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_ForegroundG,value);
}

eStatusCode gtt25_get_button_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_ForegroundB,(uint8_t*)result);
}

eStatusCode gtt25_set_button_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_ForegroundB,value);
}

eStatusCode gtt25_get_button_font_size(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_FontSize,(uint8_t*)result);
}

eStatusCode gtt25_set_button_font_size(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_FontSize,value);
}

eStatusCode gtt25_get_button_up_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Button_UpBitmap,(uint16_t*)result);
}

eStatusCode gtt25_set_button_up_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Button_UpBitmap,value);
}

eStatusCode gtt25_get_button_down_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Button_DownBitmap,(uint16_t*)result);
}

eStatusCode gtt25_set_button_down_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Button_DownBitmap,value);
}

eStatusCode gtt25_get_button_focus_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Button_FocusBitmap,(uint16_t*)result);
}

eStatusCode gtt25_set_button_focus_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Button_FocusBitmap,value);
}

eStatusCode gtt25_get_button_state(gtt_device * device, uint16_t ObjectID, eButtonState* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_State,(uint8_t*)result);
}

eStatusCode gtt25_set_button_state(gtt_device * device, uint16_t ObjectID, eButtonState value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_State,value);
}

eStatusCode gtt25_get_button_button_type(gtt_device * device, uint16_t ObjectID, eButtonType* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_ButtonType,(uint8_t*)result);
}

eStatusCode gtt25_set_button_button_type(gtt_device * device, uint16_t ObjectID, eButtonType value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_ButtonType,value);
}

eStatusCode gtt25_get_button_disabled_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Button_DisabledBitmap,(uint16_t*)result);
}

eStatusCode gtt25_set_button_disabled_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Button_DisabledBitmap,value);
}

eStatusCode gtt25_get_button_button_group(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Button_ButtonGroup,(uint16_t*)result);
}

eStatusCode gtt25_set_button_button_group(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Button_ButtonGroup,value);
}

eStatusCode gtt25_get_button_disabled_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_DisabledR,(uint8_t*)result);
}

eStatusCode gtt25_set_button_disabled_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_DisabledR,value);
}

eStatusCode gtt25_get_button_disabled_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_DisabledG,(uint8_t*)result);
}

eStatusCode gtt25_set_button_disabled_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_DisabledG,value);
}

eStatusCode gtt25_get_button_disabled_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_DisabledB,(uint8_t*)result);
}

eStatusCode gtt25_set_button_disabled_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_DisabledB,value);
}

eStatusCode gtt25_get_button_down_r(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_DownR,(uint8_t*)result);
}

eStatusCode gtt25_set_button_down_r(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_DownR,value);
}

eStatusCode gtt25_get_button_down_g(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_DownG,(uint8_t*)result);
}

eStatusCode gtt25_set_button_down_g(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_DownG,value);
}

eStatusCode gtt25_get_button_down_b(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Button_DownB,(uint8_t*)result);
}

eStatusCode gtt25_set_button_down_b(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Button_DownB,value);
}

eStatusCode gtt25_get_button_corner_radius(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Button_CornerRadius,(uint16_t*)result);
}

eStatusCode gtt25_set_button_corner_radius(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Button_CornerRadius,value);
}

eStatusCode gtt25_gttmodule_setup_usb_direct_write(gtt_device* device, uint16_t X, uint16_t Y, uint16_t W, uint16_t H, eDirectWritePixelFormat PixelFormat, eOnOff Buffered)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_GTTModule_SetupUSBDirectWrite);
	gtt_packetbuilder_writeU16(device,X);
	gtt_packetbuilder_writeU16(device,Y);
	gtt_packetbuilder_writeU16(device,W);
	gtt_packetbuilder_writeU16(device,H);
	gtt_packetbuilder_writeU8(device,PixelFormat);
	gtt_packetbuilder_writeU8(device,Buffered);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_GTTModule_SetupUSBDirectWrite);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_gttmodule_setup_usb_direct_write_palette(gtt_device* device, gtt_bytearray_l16 X)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_GTTModule_SetupUSBDirectWritePalette);
	gtt_packetbuilder_writeByteArrayL16(device,X);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_GTTModule_SetupUSBDirectWritePalette);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_gttmodule_get_last_startup_flag(gtt_device* device, eStartupMode* out_Mode)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_GTTModule_GetLastStartupFlag);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_GTTModule_GetLastStartupFlag);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Mode = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_gttmodule_reset(gtt_device* device)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_GTTModule_Reset);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_GTTModule_Reset);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_gttmodule_set_m_a_c_address_method(gtt_device* device, uint32_t Magic, gtt_bytearray_l16 MACAddress)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_GTTModule_SetMACAddressMethod);
	gtt_packetbuilder_writeU32(device,Magic);
	gtt_packetbuilder_writeByteArrayL16(device,MACAddress);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_GTTModule_SetMACAddressMethod);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_gttmodule_get_m_a_c_address_method(gtt_device* device, gtt_bytearray_l16* out_MACAddress)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_GTTModule_GetMACAddressMethod);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_GTTModule_GetMACAddressMethod);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_MACAddress = gtt_parser_getByteArrayL16(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_gttmodule_backlight(gtt_device * device, uint16_t ObjectID, uint8_t* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_GTTModule_Backlight,(uint8_t*)result);
}

eStatusCode gtt25_set_gttmodule_backlight(gtt_device * device, uint16_t ObjectID, uint8_t value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_GTTModule_Backlight,value);
}

eStatusCode gtt25_objectlist_add(gtt_device* device, uint16_t ObjectID, uint16_t ItemID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_ObjectList_Add);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,ItemID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_ObjectList_Add);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_objectlist_remove(gtt_device* device, uint16_t ObjectID, uint16_t ItemID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_ObjectList_Remove);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,ItemID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_ObjectList_Remove);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_objectlist_count(gtt_device* device, uint16_t ObjectID, uint32_t* out_Count)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_ObjectList_Count);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_ObjectList_Count);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_Count = gtt_parser_getU32(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_objectlist_get(gtt_device* device, uint16_t ObjectID, uint32_t ItemIndex, uint16_t* out_ItemID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_ObjectList_Get);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU32(device,ItemIndex);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_ObjectList_Get);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	*out_ItemID = gtt_parser_getU16(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_objectlist_clear(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_ObjectList_Clear);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_ObjectList_Clear);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_visualbitmap_source(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_VisualBitmap_Source,(uint16_t*)result);
}

eStatusCode gtt25_set_visualbitmap_source(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_VisualBitmap_Source,value);
}

eStatusCode gtt25_get_visualbitmap_source_index(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_VisualBitmap_SourceIndex,(uint16_t*)result);
}

eStatusCode gtt25_set_visualbitmap_source_index(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_VisualBitmap_SourceIndex,value);
}

eStatusCode gtt25_animation_add_frame(gtt_device* device, uint16_t ObjectID, uint16_t ItemID, uint16_t Duration)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Animation_AddFrame);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_writeU16(device,ItemID);
	gtt_packetbuilder_writeU16(device,Duration);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Animation_AddFrame);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_animation_start(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Animation_Start);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Animation_Start);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_animation_stop(gtt_device* device, uint16_t ObjectID)
{
	gtt_packetbuilder_start(device);
	gtt_packetbuilder_writeU8(device,GTT_PREFIX);
	gtt_packetbuilder_writeU8(device,250);
	gtt_packetbuilder_writeU16(device,eGtt25Command_Animation_Stop);
	gtt_packetbuilder_writeU16(device,ObjectID);
	gtt_packetbuilder_end(device);

	gtt_packetbuilder_send(device);
	size_t index = gtt_parser_waitpacket_250(device,eGtt25Command_Animation_Stop);

	uint8_t status = gtt_parser_getU8(device,index,&index);
	return (eStatusCode)status;
}

eStatusCode gtt25_get_animation_master(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Animation_Master,(uint16_t*)result);
}

eStatusCode gtt25_set_animation_master(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Animation_Master,value);
}

eStatusCode gtt25_get_animation_master_mode(gtt_device * device, uint16_t ObjectID, eAnimationMaterMode* result)
{
	return gtt25_baseobject_get_property_u8(device,ObjectID,ePropertyID_Animation_MasterMode,(uint8_t*)result);
}

eStatusCode gtt25_set_animation_master_mode(gtt_device * device, uint16_t ObjectID, eAnimationMaterMode value)
{
	return gtt25_baseobject_set_property_u8(device,ObjectID,ePropertyID_Animation_MasterMode,value);
}

eStatusCode gtt25_get_animation_current_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Animation_CurrentBitmap,(uint16_t*)result);
}

eStatusCode gtt25_set_animation_current_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Animation_CurrentBitmap,value);
}

eStatusCode gtt25_get_animation_loops(gtt_device * device, uint16_t ObjectID, uint16_t* result)
{
	return gtt25_baseobject_get_property_u16(device,ObjectID,ePropertyID_Animation_Loops,(uint16_t*)result);
}

eStatusCode gtt25_set_animation_loops(gtt_device * device, uint16_t ObjectID, uint16_t value)
{
	return gtt25_baseobject_set_property_u16(device,ObjectID,ePropertyID_Animation_Loops,value);
}

