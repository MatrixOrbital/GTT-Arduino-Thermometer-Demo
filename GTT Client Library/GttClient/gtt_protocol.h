/**
 *  @file	gtt_protocol.h
 *  @brief	this file contains all the function definitions for the gtt gtt client library
 */
#ifndef _GTT_PROTOCOL_H
#define _GTT_PROTOCOL_H

#include <stdint.h>
#include "gtt_device.h"
#include "gtt_enum.h"

#define GTT_PREFIX 254
#define GTT_SECURED_PACKET_START 251

#ifdef __cplusplus
extern "C" {
#endif

/**
* A structure to represent the return for gtt_get_protocol_version
*/
typedef struct gtt_get_protocol_version_return
{
	uint8_t Major; /*!< Major revision of the protocol used. */
	uint8_t Minor; /*!< Minor revision of the protocol used. */
} gtt_get_protocol_version_return;

/**
* A structure to represent the return for gtt_get_display_metrics
*/
typedef struct gtt_get_display_metrics_return
{
	uint16_t Width; /*!< The width of the current display resolution in pixels. */
	uint16_t Height; /*!< The height of the current display resolution in pixels. */
	uint8_t BitsRed; /*!< The number of bits used in the red channel.  When less than 8 bits, byte length colour commands use the highest bits. */
	uint8_t BitsGreen; /*!< The number of bits used in the green channel.  When less than 8 bits, byte length colour commands use the highest bits. */
	uint8_t BitsBlue; /*!< The number of bits used in the blue channel.  When less than 8 bits, byte length colour commands use the highest bits. */
} gtt_get_display_metrics_return;

/**
* A structure to represent the return for gtt_get_ambient_light
*/
typedef struct gtt_get_ambient_light_return
{
	uint8_t Result; /*!< Outcome of Get Ambient Light command, as per eStatusCode. */
	uint16_t Value; /*!< The current measurement of ambient light, between 0 and 4096. */
} gtt_get_ambient_light_return;

/**
* A structure to represent the return for gtt_get_label_activation
*/
typedef struct gtt_get_label_activation_return
{
	uint8_t Result; /*!< Outcome of Get Label Activation command, as per eStatusCode. */
	uint8_t State; /*!< Current label activation state, as per eActivation. */
} gtt_get_label_activation_return;

/**
* A structure to represent the return for gtt_get_label_colour
*/
typedef struct gtt_get_label_colour_return
{
	uint8_t Result; /*!< Outcome of Get Label Font Colour command, as per eStatusCode. */
	uint8_t R; /*!< Intensity of red, 0 to 255, limited to display metrics. */
	uint8_t G; /*!< Intensity of green, 0 to 255, limited to display metrics. */
	uint8_t B; /*!< Intensity of blue, 0 to 255, limited to display metrics. */
} gtt_get_label_colour_return;

/**
* A structure to represent the return for gtt_get_label_size
*/
typedef struct gtt_get_label_size_return
{
	uint8_t Result; /*!< Outcome of Set Label Font Size command, as per eStatusCode. */
	uint8_t Size; /*!< Current label size. */
} gtt_get_label_size_return;

/**
* A structure to represent the return for gtt_get_label_background_colour
*/
typedef struct gtt_get_label_background_colour_return
{
	uint8_t Result; /*!< Outcome of Get Label Background Colour command, as per eStatusCode. */
	uint8_t R; /*!< Intensity of red, 0 to 255, limited to display metrics. */
	uint8_t G; /*!< Intensity of green, 0 to 255, limited to display metrics. */
	uint8_t B; /*!< Intensity of blue, 0 to 255, limited to display metrics. */
} gtt_get_label_background_colour_return;

/**
* A structure to represent the return for gtt_get_string_extents
*/
typedef struct gtt_get_string_extents_return
{
	uint16_t Width; /*!< Width of the rendered string. */
	uint16_t Height; /*!< Height of the rendered string. */
} gtt_get_string_extents_return;

/**
* A structure to represent the return for gtt_get_font_window
*/
typedef struct gtt_get_font_window_return
{
	int16_t X; /*!< Leftmost coordinate of the text window. */
	int16_t Y; /*!< Topmost coordinate of the text window. */
	uint16_t Width; /*!< Height of the text window. */
	uint16_t Height; /*!< Height of the text window. */
} gtt_get_font_window_return;

/**
* A structure to represent the return for gtt_get_font_color
*/
typedef struct gtt_get_font_color_return
{
	uint8_t R; /*!< Intensity of red, 0 to 255, limited to display metrics. */
	uint8_t G; /*!< Intensity of green, 0 to 255, limited to display metrics. */
	uint8_t B; /*!< Intensity of blue, 0 to 255, limited to display metrics. */
} gtt_get_font_color_return;

/**
* A structure to represent the return for gtt_get_background_drawing_color
*/
typedef struct gtt_get_background_drawing_color_return
{
	uint8_t R; /*!< Intensity of red, 0 to 255, limited to display metrics. */
	uint8_t G; /*!< Intensity of green, 0 to 255, limited to display metrics. */
	uint8_t B; /*!< Intensity of blue, 0 to 255, limited to display metrics. */
} gtt_get_background_drawing_color_return;

/**
* A structure to represent the return for gtt_read_screen_rectangle
*/
typedef struct gtt_read_screen_rectangle_return
{
	uint8_t Result; /*!< Outcome of the Read Screen Rectangle command, as per eStatusCode. */
	uint8_t Format; /*!< Pixel format of the screen data, as per ePixelFormat. */
	gtt_bytearray_l16  Data; /*!< Current pixel data for every point within the specific rectangle, as per ePixelFormat.  Values start at the top left of the rectangle, moving right, then down. */
} gtt_read_screen_rectangle_return;

/**
* A structure to represent the return for gtt_get_drawing_color
*/
typedef struct gtt_get_drawing_color_return
{
	uint8_t R; /*!< Intensity of red, 0 to 255, limited to display metrics. */
	uint8_t G; /*!< Intensity of green, 0 to 255, limited to display metrics. */
	uint8_t B; /*!< Intensity of blue, 0 to 255, limited to display metrics. */
} gtt_get_drawing_color_return;

/**
* A structure to represent the return for gtt_list_all_bar_graphs
*/
typedef struct gtt_list_all_bar_graphs_return
{
	uint8_t BarType; /*!< Type of bargraph entry. */
	int16_t BarValue; /*!< Current value of bargraph entry. */
} gtt_list_all_bar_graphs_return;

/**
* A structure to represent the return for gtt_list_all_traces
*/
typedef struct gtt_list_all_traces_return
{
	uint8_t TraceID; /*!< Trace index number.  One for each entry.  0 signifies an undefined entry. */
	int16_t Value; /*!< Current value of the trace.  One for each entry. */
} gtt_list_all_traces_return;

/**
* A structure to represent the return for gtt_get_cursor
*/
typedef struct gtt_get_cursor_return
{
	int16_t X; /*!< Current leftmost coordinate of the insertion point. */
	int16_t Y; /*!< Current topmost coordinate of the insertion point. */
} gtt_get_cursor_return;

/**
* A structure to represent the return for gtt_get_reporting_style
*/
typedef struct gtt_get_reporting_style_return
{
	uint8_t Result; /*!< Outcome of Get Touch Reporting Style command, as per eStatusCode. */
	uint8_t ReportingType; /*!< Current touch reporting style, as per eTouchReportingType. */
} gtt_get_reporting_style_return;

/**
* A structure to represent the return for gtt_get_trace_min_max
*/
typedef struct gtt_get_trace_min_max_return
{
	int16_t Min; /*!< The min value of the trace specified. */
	int16_t Max; /*!< The max value of the trace specified. */
} gtt_get_trace_min_max_return;

/**
* A structure to represent the return for gtt_get_slider_value
*/
typedef struct gtt_get_slider_value_return
{
	uint8_t Result; /*!< Outcome of the Get Slider Value command, as per eStatusCode. */
	int16_t Value; /*!< Current value of the specified slider. */
} gtt_get_slider_value_return;

/**
* A structure to represent the return for gtt_get_toggle_state
*/
typedef struct gtt_get_toggle_state_return
{
	uint8_t Result; /*!< Outcome of the Get Toggle State command, as per eStatusCode. */
	uint8_t State; /*!< Current state of the specified toggle region. */
} gtt_get_toggle_state_return;

/*!
 Get Protocol Revision
@param[in] gtt_device the target gtt device
*/
gtt_get_protocol_version_return gtt_get_protocol_version(gtt_device *device);
/*!
 Reset Module
@param[in] gtt_device the target gtt device
*/
void gtt_reset(gtt_device *device);
/*!
 Delay
@param[in] gtt_device the target gtt device
@param[in] Time Length of delay in milliseconds.
*/
void gtt_wait(gtt_device *device, uint16_t Time);
/*!
 Get Display Metrics
@param[in] gtt_device the target gtt device
*/
gtt_get_display_metrics_return gtt_get_display_metrics(gtt_device *device);
/*!
 Enter Mass Storage Mode
@param[in] gtt_device the target gtt device
*/
void gtt_enter_mass_storage_mode(gtt_device *device);
/*!
 Set Communication Channel
@param[in] gtt_device the target gtt device
@param[in] Channel Communication channel type, as per eChannel.
*/
void gtt_set_default_channel(gtt_device *device, eChannel Channel);
/*!
 Get Ambient Light
@param[in] gtt_device the target gtt device
*/
gtt_get_ambient_light_return gtt_get_ambient_light(gtt_device *device);
/*!
 Create a Label
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
@param[in] X Leftmost coordinate of the label region.
@param[in] Y Topmost coordinate of the label region.
@param[in] Width Width of the label region in pixels.
@param[in] Height Height of the label region in pixels.
@param[in] Rot Rotation of the text within the label.
@param[in] VJst Vertical justification of text within the label, as per eFontAlignVertical.
@param[in] HJst Horizontal justification of text within the label, as per eFontAlignHorizontal.
@param[in] Font Font index of a previously loaded font to be used for the label.
@param[in] R Intensity of red, 0 to 255, used for label font colour.
@param[in] G Intensity of green, 0 to 255, used for label font colour.
@param[in] B Intensity of blue, 0 to 255, used for label font colour.
*/
void gtt_create_label(gtt_device *device, uint8_t LabelID, int16_t X, int16_t Y, int16_t Width, int16_t Height, int16_t Rot, eFontAlignVertical VJst, eFontAlignHorizontal HJst, uint8_t Font, uint8_t R, uint8_t G, uint8_t B);
/*!
 Update a Label (ASCII)
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
@param[in] Value New ASCII formatted string to display within the label.  String should be a single line in height.
*/
void gtt_update_label(gtt_device *device, uint8_t LabelID, char * Value);
/*!
 Update a Label (Unicode)
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
@param[in] Value New Unicode string to display within the label.  String should be a single line in height.
*/
void gtt_update_label_unicode(gtt_device *device, uint8_t LabelID, wchar_t * Value);
/*!
 Update a Label (UTF8)
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
@param[in] Value New UTF-8 string to display within the label.  String should be a single line in height.
*/
void gtt_update_label_utf8(gtt_device *device, uint8_t LabelID, char * Value);
/*!
 Set Label Activation State
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
@param[in] State New label activation state, as per eActivation.
*/
uint8_t gtt_set_label_activation(gtt_device *device, uint8_t LabelID, eActivation State);
/*!
 Get Label Activation State
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
*/
gtt_get_label_activation_return gtt_get_label_activation(gtt_device *device, uint8_t LabelID);
/*!
 Set Label Font Colour
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
@param[in] R Intensity of red, 0 to 255, limited to display metrics.
@param[in] G Intensity of green, 0 to 255, limited to display metrics.
@param[in] B Intensity of blue, 0 to 255, limited to display metrics.
*/
uint8_t gtt_set_label_colour(gtt_device *device, uint8_t LabelID, uint8_t R, uint8_t G, uint8_t B);
/*!
 Get Label Font Colour
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
*/
gtt_get_label_colour_return gtt_get_label_colour(gtt_device *device, uint8_t LabelID);
/*!
 Set Label Font Size
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
@param[in] Size New label size.
*/
uint8_t gtt_set_label_size(gtt_device *device, uint8_t LabelID, uint8_t Size);
/*!
 Get Label Font Size
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
*/
gtt_get_label_size_return gtt_get_label_size(gtt_device *device, uint8_t LabelID);
/*!
 Set Label Background Colour
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
@param[in] R Intensity of red, 0 to 255, limited to display metrics.
@param[in] G Intensity of green, 0 to 255, limited to display metrics.
@param[in] B Intensity of blue, 0 to 255, limited to display metrics.
*/
uint8_t gtt_set_label_background_colour(gtt_device *device, uint8_t LabelID, uint8_t R, uint8_t G, uint8_t B);
/*!
 Get Label Background Colour
@param[in] gtt_device the target gtt device
@param[in] LabelID Index used to identify this label in the label list.
*/
gtt_get_label_background_colour_return gtt_get_label_background_colour(gtt_device *device, uint8_t LabelID);
/*!
 Cache Font Characters (ASCII)
@param[in] gtt_device the target gtt device
@param[in] FontID Font index used to identify the desired font file in the font buffer.
@param[in] PtSize Point size of the desired characters to cache.
@param[in] Rot Rotation of the text to cache.
@param[in] Value ASCII String of characters to be cached.
*/
uint8_t gtt_cache_font_characters(gtt_device *device, uint8_t FontID, uint8_t PtSize, int16_t Rot, char * Value);
/*!
 Cache Font Characters (Unicode)
@param[in] gtt_device the target gtt device
@param[in] FontID Font index used to identify the desired font file in the font buffer.
@param[in] PtSize Point size of the desired characters to cache.
@param[in] Rot Rotation of the text to cache.
@param[in] Value Unicode String of characters to be cached.
*/
uint8_t gtt_cache_font_characters_unicode(gtt_device *device, uint8_t FontID, uint8_t PtSize, int16_t Rot, wchar_t * Value);
/*!
 Cache Font Characters (UTF8)
@param[in] gtt_device the target gtt device
@param[in] FontID Font index used to identify the desired font file in the font buffer.
@param[in] PtSize Point size of the desired characters to cache.
@param[in] Rot Rotation of the text to cache.
@param[in] Value UTF8 String of characters to be cached.
*/
uint8_t gtt_cache_font_characters_utf8(gtt_device *device, uint8_t FontID, uint8_t PtSize, int16_t Rot, char * Value);
/*!
 Clear Cached Characters
@param[in] gtt_device the target gtt device
@param[in] FontID Font index used to identify the desired font file in the font buffer.
@param[in] PtSize Point size of the desired characters to clear.
@param[in] Rot Rotation of the text to clear.
*/
uint8_t gtt_clear_cached_characters(gtt_device *device, uint8_t FontID, uint8_t PtSize, int16_t Rot);
/*!
 Clear All Cached Characters
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_clear_all_cached_characters(gtt_device *device);
/*!
 Print Unicode String
@param[in] gtt_device the target gtt device
@param[in] Text Unicode formatted string.
*/
void gtt_print_unicode(gtt_device *device, wchar_t * Text);
/*!
 Print UTF-8 String
@param[in] gtt_device the target gtt device
@param[in] Text UTF-8 formatted string.
*/
void gtt_print_utf8(gtt_device *device, char * Text);
/*!
 Set Control Character Mode
@param[in] gtt_device the target gtt device
@param[in] Mode Desired control character mode, as per eControlCharacterMode.
*/
void gtt_set_control_character_mode(gtt_device *device, eControlCharacterMode Mode);
/*!
 Get Control Character Mode
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_get_control_character_mode(gtt_device *device);
/*!
 Load Font
@param[in] gtt_device the target gtt device
@param[in] FontID Index used to identify the font. Specific to fonts.
@param[in] FileName Filename, including path from the root folder, of the font file to load.
*/
uint8_t gtt_load_font(gtt_device *device, uint8_t FontID, char * FileName);
/*!
 Get String Extents
@param[in] gtt_device the target gtt device
@param[in] Text String whose extents are desired.
*/
gtt_get_string_extents_return gtt_get_string_extents(gtt_device *device, char * Text);
/*!
 Set Text Window
@param[in] gtt_device the target gtt device
@param[in] X Leftmost coordinate of the text window.
@param[in] Y Topmost coordinate of the text window.
@param[in] Width Width of the text window.
@param[in] Height Height of the text window.
*/
void gtt_set_font_window(gtt_device *device, int16_t X, int16_t Y, uint16_t Width, uint16_t Height);
/*!
 Get Text Window
@param[in] gtt_device the target gtt device
*/
gtt_get_font_window_return gtt_get_font_window(gtt_device *device);
/*!
 Reset Font
@param[in] gtt_device the target gtt device
*/
void gtt_reset_font(gtt_device *device);
/*!
 Set Text Colour
@param[in] gtt_device the target gtt device
@param[in] R Intensity of red, 0 to 255, limited to display metrics.
@param[in] G Intensity of green, 0 to 255, limited to display metrics.
@param[in] B Intensity of blue, 0 to 255, limited to display metrics.
*/
void gtt_set_font_color(gtt_device *device, uint8_t R, uint8_t G, uint8_t B);
/*!
 Get Text Colour
@param[in] gtt_device the target gtt device
*/
gtt_get_font_color_return gtt_get_font_color(gtt_device *device);
/*!
 Get Font
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_get_current_font(gtt_device *device);
/*!
 Set Font
@param[in] gtt_device the target gtt device
@param[in] FontID Font index used to identify the desired font file in the font buffer.
*/
uint8_t gtt_set_current_font(gtt_device *device, uint8_t FontID);
/*!
 Set Screen Orientation
@param[in] gtt_device the target gtt device
@param[in] Orientation Desired screen orientation, as per ePanelOrientation.
*/
void gtt_set_panel_orientation(gtt_device *device, ePanelOrientation Orientation);
/*!
 Set Font Size
@param[in] gtt_device the target gtt device
@param[in] PtSize Desired point size for the current font.
*/
void gtt_set_font_size(gtt_device *device, uint8_t PtSize);
/*!
 Set Customer Data
@param[in] gtt_device the target gtt device
@param[in] Data Data to be written to the SD card.
*/
void gtt_set_customer_data(gtt_device *device, gtt_bytearray_l8  Data);
/*!
 Get Customer Data
@param[in] gtt_device the target gtt device
*/
gtt_bytearray_l8  gtt_get_customer_data(gtt_device *device);
/*!
 Get Module Type
@param[in] gtt_device the target gtt device
*/
uint16_t gtt_get_module_type(gtt_device *device);
/*!
 Get Module String
@param[in] gtt_device the target gtt device
*/
char * gtt_get_module_string(gtt_device *device);
/*!
 Set Baud Rate
@param[in] gtt_device the target gtt device
@param[in] BaudRate The desired baud rate value.
*/
void gtt_set_baud_rate(gtt_device *device, uint32_t BaudRate);
/*!
 Set Flow Control Mode
@param[in] gtt_device the target gtt device
@param[in] FlowControl Flow control setting, as per eFlowControl.
*/
void gtt_set_flow_control(gtt_device *device, eFlowControl FlowControl);
/*!
 Get Font Size
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_get_font_size(gtt_device *device);
/*!
 Clear Key Buffer
@param[in] gtt_device the target gtt device
*/
void gtt_clear_key_buffer(gtt_device *device);
/*!
 Clear a Scripted Key
@param[in] gtt_device the target gtt device
@param[in] Row Row index of the scripted key to be cleared.
@param[in] Column Column index of the scripted key to be cleared.
*/
void gtt_clear_a_scripted_key(gtt_device *device, uint8_t Row, uint8_t Column);
/*!
 Clear All Scripted Keys
@param[in] gtt_device the target gtt device
*/
void gtt_clear_all_scripted_keys(gtt_device *device);
/*!
 Go Home
@param[in] gtt_device the target gtt device
*/
void gtt_move_home(gtt_device *device);
/*!
 Set GPO State
@param[in] gtt_device the target gtt device
@param[in] Number GPO to be controlled.
@param[in] Setting GPO state, as per eGPOSetting.
*/
void gtt_set_gpo(gtt_device *device, uint8_t Number, eGPOSetting Setting);
/*!
 Set LED Indicator State
@param[in] gtt_device the target gtt device
@param[in] Number Number of the LED Indicator to be set.
@param[in] State Desired Indicator State, as per eIndicatorState.
*/
void gtt_set_led_indicator_state(gtt_device *device, uint8_t Number, eIndicatorState State);
/*!
 Set Keypad Transmit Mode
@param[in] gtt_device the target gtt device
@param[in] AutoTransmit Auto transmit mode, as per eOnOff.
*/
void gtt_set_key_auto_tx(gtt_device *device, eOnOff AutoTransmit);
/*!
 Set Debounce Time
@param[in] gtt_device the target gtt device
@param[in] Mode Debounce time in milliseconds.
*/
void gtt_set_debounce_time(gtt_device *device, uint8_t Mode);
/*!
 Set Background Drawing Colour
@param[in] gtt_device the target gtt device
@param[in] R Intensity of red, 0 to 255, limited to display metrics.
@param[in] G Intensity of green, 0 to 255, limited to display metrics.
@param[in] B Intensity of blue, 0 to 255, limited to display metrics.
*/
void gtt_set_background_drawing_color(gtt_device *device, uint8_t R, uint8_t G, uint8_t B);
/*!
 Get Background Drawing Colour
@param[in] gtt_device the target gtt device
*/
gtt_get_background_drawing_color_return gtt_get_background_drawing_color(gtt_device *device);
/*!
 Clear Screen
@param[in] gtt_device the target gtt device
*/
void gtt_clear_screen(gtt_device *device);
/*!
 Scroll Screen
@param[in] gtt_device the target gtt device
@param[in] X Leftmost coordinate of the scroll window.
@param[in] Y Topmost coordinate of the scroll window.
@param[in] Width Width of the scroll window.
@param[in] Height Height of the scroll window.
@param[in] MoveX Number of pixels to scroll horizontally.
@param[in] MoveY Number of pixels to scroll vertically.
*/
void gtt_scroll(gtt_device *device, int16_t X, int16_t Y, int16_t Width, int16_t Height, int16_t MoveX, int16_t MoveY);
/*!
 Enable Manual Update
@param[in] gtt_device the target gtt device
@param[in] Enable Desired manual update setting, as per eEnable. 
*/
void gtt_set_manual_flush(gtt_device *device, eEnable Enable);
/*!
 Manual Update
@param[in] gtt_device the target gtt device
*/
void gtt_manual_flush(gtt_device *device);
/*!
 Flush Region
@param[in] gtt_device the target gtt device
@param[in] X Leftmost coordinate of the flush window.
@param[in] Y Topmost coordinate of the flush window.
@param[in] Width Width of the flush window.
@param[in] Height Height of the flush window.
*/
void gtt_flush_region(gtt_device *device, int16_t X, int16_t Y, int16_t Width, int16_t Height);
/*!
 Run Script File
@param[in] gtt_device the target gtt device
@param[in] FileName Filename, and path from the root folder, of the script file to run.
*/
void gtt_run_script(gtt_device *device, char * FileName);
/*!
 Read Screen Rectangle
@param[in] gtt_device the target gtt device
@param[in] X Leftmost coordinate of the screen rectangle to read.
@param[in] Y Topmost coordinate of the screen rectangle to read.
@param[in] Width Width of the screen rectangle to read.
@param[in] Height Height of the screen rectangle to read.
@param[in] Format Pixel format of the screen data, as per ePixelFormat.
*/
gtt_read_screen_rectangle_return gtt_read_screen_rectangle(gtt_device *device, uint16_t X, uint16_t Y, uint16_t Width, uint16_t Height, ePixelFormat Format);
/*!
 Load Bitmap
@param[in] gtt_device the target gtt device
@param[in] BitmapID Index used to identify the bitmap. Specific to bitmaps, and screen rectangles.
@param[in] FileName Filename, and path from the root folder, of the bitmap file to load.
*/
uint8_t gtt_load_bitmap(gtt_device *device, uint8_t BitmapID, char * FileName);
/*!
 Copy Screen Rectangle
@param[in] gtt_device the target gtt device
@param[in] BitmapID Index used to identify the screen section.  Specific to bitmaps and screen rectangles.
@param[in] X Leftmost coordinate.
@param[in] Y Topmost coordinate.
@param[in] Width Width of the screen section.
@param[in] Height Height of the screen section.
*/
void gtt_copy_screen_rectangle(gtt_device *device, uint8_t BitmapID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height);
/*!
 Display Bitmap
@param[in] gtt_device the target gtt device
@param[in] BitmapID Index used to identify the desired file in the bitmap buffer.
@param[in] X Leftmost coordinate.
@param[in] Y Topmost coordinate.
*/
uint8_t gtt_display_bitmap(gtt_device *device, uint8_t BitmapID, int16_t X, int16_t Y);
/*!
 Set Bitmap Transparency
@param[in] gtt_device the target gtt device
@param[in] BitmapID Index used to identify the desired file in the bitmap buffer.
@param[in] R Intensity of red, 0 to 255, limited to display metrics.
@param[in] G Intensity of green, 0 to 255, limited to display metrics.
@param[in] B Intensity of blue, 0 to 255, limited to display metrics.
*/
uint8_t gtt_set_bitmap_transparency(gtt_device *device, uint8_t BitmapID, uint8_t R, uint8_t G, uint8_t B);
/*!
 Set Drawing Colour
@param[in] gtt_device the target gtt device
@param[in] R Intensity of red, 0 to 255, limited to display metrics.
@param[in] G Intensity of green, 0 to 255, limited to display metrics.
@param[in] B Intensity of blue, 0 to 255, limited to display metrics.
*/
void gtt_set_drawing_color(gtt_device *device, uint8_t R, uint8_t G, uint8_t B);
/*!
 Get Drawing Colour
@param[in] gtt_device the target gtt device
*/
gtt_get_drawing_color_return gtt_get_drawing_color(gtt_device *device);
/*!
 Continue Line
@param[in] gtt_device the target gtt device
@param[in] X Horizontal coordinate of line terminus.
@param[in] Y Vertical coordinate of line terminus.
*/
void gtt_continue_line(gtt_device *device, int16_t X, int16_t Y);
/*!
 List All Bargraphs
@param[in] gtt_device the target gtt device
*/
gtt_list_all_bar_graphs_return gtt_list_all_bar_graphs(gtt_device *device);
/*!
 Define a Plain Bargraph
@param[in] gtt_device the target gtt device
@param[in] BarID Index used to identify this bargraph in the bargraph list.
@param[in] Min Minimum bargraph value.
@param[in] Max Maximum bargraph value.
@param[in] X Leftmost coordinate of the bargraph.
@param[in] Y Topmost coordinate of the bargraph.
@param[in] Width Width of the bargraph.
@param[in] Height Height of the bargraph.
@param[in] FGR Red component of the foreground colour.
@param[in] FGG Green component of the foreground colour.
@param[in] FGB Blue component of the foreground colour.
@param[in] BGR Red component of the background colour.
@param[in] BGG Green component of the background colour.
@param[in] BGB Blue component of the background colour.
@param[in] D Direction that the bargraph will take, as per eBargraphOrientation.
*/
void gtt_define_plain_bar_graph(gtt_device *device, uint8_t BarID, int16_t Min, int16_t Max, int16_t X, int16_t Y, int16_t Width, int16_t Height, uint8_t FGR, uint8_t FGG, uint8_t FGB, uint8_t BGR, uint8_t BGG, uint8_t BGB, eBargraphOrientation D);
/*!
 Define a 9-Slice Bargraph
@param[in] gtt_device the target gtt device
@param[in] BarID Index used to identify this bargraph in the bargraph list.
@param[in] Min Minimum bargraph value.
@param[in] Max Maximum bargraph value.
@param[in] X Leftmost coordinate of the bargraph.
@param[in] Y Topmost coordinate of the bargraph.
@param[in] Width Width of the bargraph.
@param[in] Height Height of the bargraph.
@param[in] BFG 9-Slice buffer index of the foreground image.
@param[in] BBG 9-Slice buffer index of the background image.
@param[in] D Direction that the bargraph will take, as per eBargraphOrientation.
*/
void gtt_define9_slice_bar_graph(gtt_device *device, uint8_t BarID, int16_t Min, int16_t Max, int16_t X, int16_t Y, int16_t Width, int16_t Height, uint8_t BFG, uint8_t BBG, eBargraphOrientation D);
/*!
 Update a Bargraph Value
@param[in] gtt_device the target gtt device
@param[in] BarID Index used to identify this bargraph in the bargraph list.
@param[in] Value Current value of the bargraph.
*/
uint8_t gtt_update_value(gtt_device *device, uint8_t BarID, int16_t Value);
/*!
 Update Multiple Bargraph Values
@param[in] gtt_device the target gtt device
@param[in] BarID Index used to identify the first bargraph to be updated in the bargraph list.
@param[in] Values Current values, one for each bargraph index to be updated.
*/
uint8_t gtt_set_multiple_bargraph_values(gtt_device *device, uint8_t BarID, int16_t * Values);
/*!
 Clear All Bargraphs
@param[in] gtt_device the target gtt device
*/
void gtt_clear_all_bargraphs(gtt_device *device);
/*!
 Draw Line
@param[in] gtt_device the target gtt device
@param[in] X1 Horizontal coordinate of first line terminus.
@param[in] Y1 Vertical coordinate of first line terminus.
@param[in] X2 Horizontal coordinate of second line terminus.
@param[in] Y2 Vertical coordinate of second line terminus.
*/
void gtt_draw_line(gtt_device *device, int16_t X1, int16_t Y1, int16_t X2, int16_t Y2);
/*!
 Reset a Trace Value
@param[in] gtt_device the target gtt device
@param[in] TraceID Index used to identify this trace in the trace list.
*/
void gtt_reset_a_trace_value(gtt_device *device, uint8_t TraceID);
/*!
 Reset Multiple Trace Values
@param[in] gtt_device the target gtt device
@param[in] TraceID Index used to identify the first trace to be reset in the trace list.
@param[in] Number Number of trace entries to be reset.
*/
void gtt_reset_multiple_trace_values(gtt_device *device, uint8_t TraceID, uint8_t Number);
/*!
 Draw Pixel
@param[in] gtt_device the target gtt device
@param[in] X Horizontal position of pixel to be drawn.
@param[in] Y Vertical position of pixel to be drawn.
*/
void gtt_set_pixel(gtt_device *device, int16_t X, int16_t Y);
/*!
 Draw Rectangle
@param[in] gtt_device the target gtt device
@param[in] X Leftmost coordinate of the rectangle.
@param[in] Y Topmost coordinate of the rectangle.
@param[in] Width Width of the rectangle.
@param[in] Height Height of the rectangle.
*/
void gtt_draw_rectangle(gtt_device *device, int16_t X, int16_t Y, uint16_t Width, uint16_t Height);
/*!
 List All Traces
@param[in] gtt_device the target gtt device
*/
gtt_list_all_traces_return gtt_list_all_traces(gtt_device *device);
/*!
 Initialize a Trace
@param[in] gtt_device the target gtt device
@param[in] TraceID Index used to identify this trace in the trace list.
@param[in] X Leftmost coordinate of the trace region.
@param[in] Y Topmost coordinate of the trace region.
@param[in] Width Width of the trace region.
@param[in] Height Height of the trace region.
@param[in] Min Value displayed at the lowest point of the trace.
@param[in] Max Value displayed at the highest point of the trace.
@param[in] Step Number of pixels shifted when a trace is updated.
@param[in] Style Orientation and Direction of the trace, as per eTraceTypeandDirection.  A style is created by summing values of individual attributes.  For example, a Line with a Bottom Left origin, Shifting right has a Style value of 129.
@param[in] Red Intensity of red for trace colour, 0 to 255, limited to display metrics.
@param[in] Green Intensity of green for trace colour, 0 to 255, limited to display metrics.
@param[in] Blue Intensity of blue for trace colour, 0 to 255, limited to display metrics.
*/
void gtt_initialize_trace(gtt_device *device, uint8_t TraceID, int16_t X, int16_t Y, int16_t Width, int16_t Height, int16_t Min, int16_t Max, uint8_t Step, eTraceTypeandDirection Style, uint8_t Red, uint8_t Green, uint8_t Blue);
/*!
 Update a Trace
@param[in] gtt_device the target gtt device
@param[in] TraceID Index used to identify this trace in the trace list.
@param[in] Value Current value of the specified trace.
*/
void gtt_update_trace(gtt_device *device, uint8_t TraceID, int16_t Value);
/*!
 Update Multiple Traces
@param[in] gtt_device the target gtt device
@param[in] TraceID Index used to identify the first trace to be updated in the trace list.
@param[in] Values Current values, one for each of the trace index to be updated.
*/
uint8_t gtt_update_multiple_traces(gtt_device *device, uint8_t TraceID, int16_t * Values);
/*!
 Clear All Traces
@param[in] gtt_device the target gtt device
*/
void gtt_clear_alltraces(gtt_device *device);
/*!
 Draw Filled Rectangle
@param[in] gtt_device the target gtt device
@param[in] X Leftmost coordinate of the rectangle.
@param[in] Y Topmost coordinate of the rectangle.
@param[in] Width Width of the rectangle.
@param[in] Height Height of the rectangle.
*/
void gtt_fill_rectangle(gtt_device *device, int16_t X, int16_t Y, uint16_t Width, uint16_t Height);
/*!
 Set Text Insertion Point
@param[in] gtt_device the target gtt device
@param[in] X Desired leftmost coordinate of the insertion point.
@param[in] Y Desired topmost coordinate of the insertion point.
*/
void gtt_set_cursor(gtt_device *device, int16_t X, int16_t Y);
/*!
 Get Text Insertion Point
@param[in] gtt_device the target gtt device
*/
gtt_get_cursor_return gtt_get_cursor(gtt_device *device);
/*!
 Draw Circle
@param[in] gtt_device the target gtt device
@param[in] X Horizontal coordinate of circle centre.
@param[in] Y Vertical coordinate of circle centre.
@param[in] Radius Radius of the circle.
*/
void gtt_draw_circle(gtt_device *device, int16_t X, int16_t Y, uint16_t Radius);
/*!
 Draw Filled Circle
@param[in] gtt_device the target gtt device
@param[in] X Horizontal coordinate of circle centre.
@param[in] Y Vertical coordinate of circle centre.
@param[in] Radius Radius of the circle.
*/
void gtt_fill_circle(gtt_device *device, int16_t X, int16_t Y, uint16_t Radius);
/*!
 Draw an Ellipse
@param[in] gtt_device the target gtt device
@param[in] X Horizontal coordinate of ellipse centre.
@param[in] Y Vertical coordinate of ellipse centre.
@param[in] XRadius Horizontal Radius of the ellipse.
@param[in] YRadius Vertical Radius of the ellipse.
*/
void gtt_draw_ellipse(gtt_device *device, int16_t X, int16_t Y, uint16_t XRadius, uint16_t YRadius);
/*!
 Draw a Filled Ellipse
@param[in] gtt_device the target gtt device
@param[in] X Horizontal coordinate of ellipse centre.
@param[in] Y Vertical coordinate of ellipse centre.
@param[in] XRadius Horizontal Radius of the ellipse.
@param[in] YRadius Vertical Radius of the ellipse.
*/
void gtt_fill_ellipse(gtt_device *device, int16_t X, int16_t Y, uint16_t XRadius, uint16_t YRadius);
/*!
 Draw Rounded Rectangle
@param[in] gtt_device the target gtt device
@param[in] X Leftmost coordinate of the rectangle.
@param[in] Y Topmost coordinate of the rectangle.
@param[in] Width Width of the rectangle.
@param[in] Height Height of the rectangle.
@param[in] Radius Radius of the rounded corners.
*/
void gtt_draw_rounded_rectangle(gtt_device *device, int16_t X, int16_t Y, int16_t Width, int16_t Height, uint16_t Radius);
/*!
 Draw Filled Rounded Rectangle
@param[in] gtt_device the target gtt device
@param[in] X Leftmost coordinate of the rectangle.
@param[in] Y Topmost coordinate of the rectangle.
@param[in] Width Width of the rectangle.
@param[in] Height Height of the rectangle.
@param[in] Radius Radius of the rounded corners.
*/
void gtt_fill_rounded_rectangle(gtt_device *device, int16_t X, int16_t Y, int16_t Width, int16_t Height, uint16_t Radius);
/*!
 Draw Triangle
@param[in] gtt_device the target gtt device
@param[in] X1 Horizontal coordinate of the first point.
@param[in] Y1 Vertical coordinate of the first point.
@param[in] X2 Horizontal coordinate of the second point.
@param[in] Y2 Vertical coordinate of the second point.
@param[in] X3 Horizontal coordinate of the third point.
@param[in] Y3 Vertical coordinate of the third point.
*/
void gtt_draw_triangle(gtt_device *device, int16_t X1, int16_t Y1, int16_t X2, int16_t Y2, int16_t X3, int16_t Y3);
/*!
 Draw Filled Triangle
@param[in] gtt_device the target gtt device
@param[in] X1 Horizontal coordinate of the first point.
@param[in] Y1 Vertical coordinate of the first point.
@param[in] X2 Horizontal coordinate of the second point.
@param[in] Y2 Vertical coordinate of the second point.
@param[in] X3 Horizontal coordinate of the third point.
@param[in] Y3 Vertical coordinate of the third point.
*/
void gtt_fill_triangle(gtt_device *device, int16_t X1, int16_t Y1, int16_t X2, int16_t Y2, int16_t X3, int16_t Y3);
/*!
 Create a Scripted Region
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify this scripted region in the touch region list.  Region 255 is reserved for out of region responses.
@param[in] X Leftmost coordinate of the scripted touch region.
@param[in] Y Topmost coordinate of the scripted touch region.
@param[in] W Width of the scripted touch region.
@param[in] H Height of the scripted touch region.
@param[in] UpBitmap Index of the loaded bitmap displayed when the region is released.
@param[in] DownBitmap Index of the loaded bitmap displayed when the region is pressed.
@param[in] UpScript Filename of the script to be executed when the region is released.
@param[in] DownScript Filename of the script to be executed when the region is pressed.
*/
void gtt_create_scripted_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, uint16_t W, uint16_t H, uint8_t UpBitmap, uint8_t DownBitmap, char * UpScript, char * DownScript);
/*!
 Create a Touch Region
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify this touch region in the touch region list.  Region 255 is reserved for out of region responses.
@param[in] X Leftmost coordinate of the touch region.
@param[in] Y Topmost coordinate of the touch region.
@param[in] Width Width of the touch region.
@param[in] Height Height of the touch region.
@param[in] Up Index of the loaded bitmap displayed when the region is released.
@param[in] Down Index of the loaded bitmap displayed when the region is touched.
*/
void gtt_setup_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height, uint8_t Up, uint8_t Down);
/*!
 Clear a Touch Region
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify this touch region in the touch region list.
*/
void gtt_clear_touch_region(gtt_device *device, uint8_t RegionID);
/*!
 Clear All Touch Regions
@param[in] gtt_device the target gtt device
*/
void gtt_clear_all_regions(gtt_device *device);
/*!
 Change Touch Reporting Style
@param[in] gtt_device the target gtt device
@param[in] ReportingType Desired touch reporting style, as per eTouchReportingType.
*/
void gtt_change_reporting_style(gtt_device *device, eTouchReportingType ReportingType);
/*!
 Get Touch Reporting Style
@param[in] gtt_device the target gtt device
*/
gtt_get_reporting_style_return gtt_get_reporting_style(gtt_device *device);
/*!
 Set Dragging Threshold
@param[in] gtt_device the target gtt device
@param[in] Threshold Dragging threshold value.  Default is 3 pixels.
*/
void gtt_set_dragging_threshold(gtt_device *device, uint16_t Threshold);
/*!
 Create a Scripted Key
@param[in] gtt_device the target gtt device
@param[in] KeyID Index used to identify this scripted key in the key list.
@param[in] Row Row index of the scripted key.
@param[in] Col Column index of the scripted key.
@param[in] UpScript Filename of the script to be executed when the key is released.
@param[in] DownScript Filename of the script to be executed when the key is pressed.
*/
void gtt_create_scripted_key(gtt_device *device, uint8_t KeyID, uint8_t Row, uint8_t Col, char * UpScript, char * DownScript);
/*!
 Calibrate Touch Screen
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_calibrate(gtt_device *device);
/*!
 Load Region File
@param[in] gtt_device the target gtt device
@param[in] FileName Filename, and path from the root folder, of the region file to load.
*/
uint8_t gtt_load_region_file(gtt_device *device, char * FileName);
/*!
 Restore Touch Calibration
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_restore_calibration(gtt_device *device);
/*!
 Set Out of Region Setting
@param[in] gtt_device the target gtt device
@param[in] Setting Desired out of region setting, as per eOnOff. Default is Off.
*/
void gtt_set_out_of_region_setting(gtt_device *device, eOnOff Setting);
/*!
 Get Out of Region Setting
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_get_out_of_region_setting(gtt_device *device);
/*!
 Load 9-Slice
@param[in] gtt_device the target gtt device
@param[in] NineSliceID Index used to identify the 9-slice.  Specific to 9-slices.
@param[in] Filename Filename, and path from the root folder, of the 9-Slice file to load.
*/
uint8_t gtt_load_nine_slice(gtt_device *device, uint8_t NineSliceID, char * Filename);
/*!
 Display 9-Slice
@param[in] gtt_device the target gtt device
@param[in] NineSliceID Index used to identify the desired file in the 9-slice buffer.
@param[in] X Leftmost coordinate.
@param[in] Y Topmost coordinate.
@param[in] Width Width of the 9-slice.
@param[in] Height Height of the 9-slice.
*/
void gtt_draw_nine_slice(gtt_device *device, uint8_t NineSliceID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height);
/*!
 Set Region Activate State
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify the touch region in the touch region list.
@param[in] Enable Activation state, as per eEnable.
*/
uint8_t gtt_set_region_activate_state(gtt_device *device, uint8_t RegionID, eEnable Enable);
/*!
 Get Region Activate State
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify the touch region in the touch region list.
*/
uint8_t gtt_get_region_activate_state(gtt_device *device, uint8_t RegionID);
/*!
 Set Trace Min and Max Values
@param[in] gtt_device the target gtt device
@param[in] TraceID Index used to identify the previously defined trace.  Specific to Traces.
@param[in] Min The new minimum value for the trace as specified by TraceIndex.
@param[in] Max The new maximum value for the trace as specified by TraceIndex.
*/
void gtt_set_trace_min_max(gtt_device *device, uint8_t TraceID, int16_t Min, int16_t Max);
/*!
 Get Trace Min and Max Values
@param[in] gtt_device the target gtt device
@param[in] TraceID Index used to identify the previously defined trace.  Specific to Traces.
*/
gtt_get_trace_min_max_return gtt_get_trace_min_max(gtt_device *device, uint8_t TraceID);
/*!
 Create a Toggle Region
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify this toggle region in the touch region list.  Region 255 is reserved for out of region responses.
@param[in] X Leftmost coordinate of the toggle region.
@param[in] Y Topmost coordinate of the toggle region.
@param[in] Width Width of the toggle region.
@param[in] Height Height of the toggle region.
@param[in] OffID Index of the loaded bitmap displayed when the region is in an inactive state.
@param[in] OnID Index of the loaded bitmap displayed when the region is in a toggled state.
*/
uint8_t gtt_create_toggle_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height, uint8_t OffID, uint8_t OnID);
/*!
 Set Keypad Backlight Time
@param[in] gtt_device the target gtt device
@param[in] Minutes Number of minutes to leave the keypad backlight on.  Send 0 to keep the keypad backlight on indefinitely.
*/
void gtt_set_keypad_backlight_time(gtt_device *device, uint8_t Minutes);
/*!
 Get Keypad Backlight Time
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_get_keypad_backlight_time(gtt_device *device);
/*!
 Set Backlight Brightness
@param[in] gtt_device the target gtt device
@param[in] Brightness The backlight brightness, a value between 0 (off) and 255 (maximum).
*/
void gtt_set_backlight(gtt_device *device, uint8_t Brightness);
/*!
 Get Backlight Brightness
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_get_backlight(gtt_device *device);
/*!
 Set Keypad Brightness
@param[in] gtt_device the target gtt device
@param[in] Brightness Keypad brightness, a value between 0 (off) and 255 (maximum). Default is 255.
*/
void gtt_set_keypad_brightness(gtt_device *device, uint8_t Brightness);
/*!
 Get Keypad Brightness
@param[in] gtt_device the target gtt device
*/
uint8_t gtt_get_keypad_brightness(gtt_device *device);
/*!
 Set Auto Backlight
@param[in] gtt_device the target gtt device
@param[in] Setting Auto Backlight setting, as per eAutoBacklight.
*/
void gtt_set_auto_backlight(gtt_device *device, eAutoBacklight Setting);
/*!
 Set Typematic Interval
@param[in] gtt_device the target gtt device
@param[in] Interval Time between key reports, in ms, default is 200ms.
*/
void gtt_set_typematic_interval(gtt_device *device, uint16_t Interval);
/*!
 Set Typematic Delay
@param[in] gtt_device the target gtt device
@param[in] Delay Time key must be held to trigger typematic reports, in ms, default is 1000ms.
*/
void gtt_set_typematic_delay(gtt_device *device, uint16_t Delay);
/*!
 Activate Motor
@param[in] gtt_device the target gtt device
@param[in] Frequency Frequency of the vibration in Hertz.
@param[in] Duration Duration of the vibration in milliseconds.
*/
void gtt_set_motor(gtt_device *device, uint16_t Frequency, uint16_t Duration);
/*!
 Create a Slider
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify this slider in the touch region list.  Region 255 is reserved for out of region responses.
@param[in] X Leftmost coordinate of the slider region.
@param[in] Y Topmost coordinate of the slider region.
@param[in] LT Leftmost/Topmost value returned by the slider region.  This is the default initial button location.
@param[in] RB Rightmost/Bottommost value returned by the slider region.
@param[in] TrkWidth Width of the slider track region.
@param[in] TrkHeight Height of the slider track region.
@param[in] BtnWidth Width of the slider button region.
@param[in] BtnHeight Height of the slider button region.
@param[in] TrkID Index of the loaded 9-slice file displayed within the track region.
@param[in] BtnID Index of the loaded 9-slice file displayed within the button region.
@param[in] Style Style of the slider, as per eSliderStyles.
*/
uint8_t gtt_create_slider_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, int16_t LT, int16_t RB, uint16_t TrkWidth, uint16_t TrkHeight, uint16_t BtnWidth, uint16_t BtnHeight, uint8_t TrkID, uint8_t BtnID, eSliderStyles Style);
/*!
 Create a Scripted Toggle Region
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify this scripted toggle region in the touch region list.  Region 255 is reserved for out of region responses.
@param[in] X Leftmost coordinate of the scripted toggle region.
@param[in] Y Topmost coordinate of the scripted toggle region.
@param[in] Width Width of the scripted toggle region.
@param[in] Height Height of the scripted toggle region.
@param[in] OffID Index of the loaded bitmap displayed when the region is in an inactive state.
@param[in] OnID Index of the loaded bitmap displayed when the region is in a toggled state.
@param[in] OffScript Filename of the script to be executed when the region is first placed in an inactive state.
@param[in] OnScript Filename of the script to be executed when the region is first placed in a toggled state.
*/
uint8_t gtt_create_scripted_toggle_region(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, uint16_t Width, uint16_t Height, uint8_t OffID, uint8_t OnID, char * OffScript, char * OnScript);
/*!
 Create a Filled Slider
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify this filled slider in the touch region list.  Region 255 is reserved for out of region responses.
@param[in] X Leftmost coordinate of the filled slider region.
@param[in] Y Topmost coordinate of the filled slider region.
@param[in] LT Leftmost/Topmost value returned by the filled slider region.  This is the default initial button location.
@param[in] RB Rightmost/Bottommost value returned by the filled slider region.  Invert LT/RB values to swap the location of the fill.
@param[in] TrkWidth Width of the slider track region.
@param[in] TrkHeight Height of the slider track region.
@param[in] BtnWidth Width of the slider button region.
@param[in] BtnHeight Height of the slider button region.
@param[in] TrkID Index of the loaded 9-slice file displayed within the empty track region.
@param[in] FilID Index of the loaded 9-slice file displayed within the filled track region.
@param[in] BtnID Index of the loaded 9-slice file displayed within the button region.
@param[in] Style Style of the slider, as per eSliderStyles.
*/
uint8_t gtt_create_filled_slider(gtt_device *device, uint8_t RegionID, int16_t X, int16_t Y, int16_t LT, int16_t RB, uint16_t TrkWidth, uint16_t TrkHeight, uint16_t BtnWidth, uint16_t BtnHeight, uint8_t TrkID, uint8_t FilID, uint8_t BtnID, eSliderStyles Style);
/*!
 Set Auto Repeat Mode
@param[in] gtt_device the target gtt device
@param[in] Mode Desired keypad auto repeat mode, as per eKeypadRepeatMode.
*/
void gtt_set_auto_repeat(gtt_device *device, eKeypadRepeatMode Mode);
/*!
 Set Slider Value
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify the slider in the touch region list.
@param[in] Value Desired value for the specified slider.
*/
uint8_t gtt_set_slider_value(gtt_device *device, uint8_t RegionID, int16_t Value);
/*!
 Get Slider Value
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify the slider in the touch region list.
*/
gtt_get_slider_value_return gtt_get_slider_value(gtt_device *device, uint8_t RegionID);
/*!
 Set Toggle State
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify the toggle region in the touch region list.
@param[in] State Desired state for the specified toggle region.
*/
uint8_t gtt_set_toggle_state(gtt_device *device, uint8_t RegionID, uint8_t State);
/*!
 Get Toggle State
@param[in] gtt_device the target gtt device
@param[in] RegionID Index used to identify the toggle region in the touch region list.
*/
gtt_get_toggle_state_return gtt_get_toggle_state(gtt_device *device, uint8_t RegionID);
/*!
 Set Input Feedback
@param[in] gtt_device the target gtt device
@param[in] InputOutputType Desired input event and output response types, as per eKeypadInputOutputType.  Multiple events and/or responses can be selected by summing values.
@param[in] DownFrequency Frequency of the down event in Hertz.
@param[in] UpFrequency Frequency of the up event in Hertz.
*/
void gtt_input_beep(gtt_device *device, eKeypadInputOutputType InputOutputType, uint16_t DownFrequency, uint16_t UpFrequency);
/*!
 Activate Buzzer and Motor
@param[in] gtt_device the target gtt device
@param[in] Frequency Frequency of the beep and vibration in Hertz.
@param[in] Duration Duration of the beep in milliseconds.
*/
void gtt_activate_motor_buzzer(gtt_device *device, uint16_t Frequency, uint16_t Duration);
/*!
 Activate Buzzer
@param[in] gtt_device the target gtt device
@param[in] Frequency Frequency of the beep in Hertz.
@param[in] Duration Duration of the beep in milliseconds.
*/
void gtt_buzzer_beep(gtt_device *device, uint16_t Frequency, uint16_t Duration);
/*!
 Set Default Buzzer Beep
@param[in] gtt_device the target gtt device
@param[in] Frequency Frequency of the beep in Hertz.
@param[in] Duration Duration of the beep in milliseconds.
*/
void gtt_set_default_buzzer_beep(gtt_device *device, uint16_t Frequency, uint16_t Duration);
/*!
 Load Animation
@param[in] gtt_device the target gtt device
@param[in] AnimationID Index used to identify this animation file. Specific to animations.
@param[in] Filename Filename, and path from the root folder, of the animation file to load.
*/
void gtt_load_animation(gtt_device *device, uint8_t AnimationID, char * Filename);
/*!
 Set Up Animation
@param[in] gtt_device the target gtt device
@param[in] AnimationID Index where an animation file has been loaded.
@param[in] AnimationInstance Index used to identify this animation instance in the animation list.
@param[in] X Leftmost coordinate.
@param[in] Y Topmost coordinate.
*/
void gtt_set_up_animation(gtt_device *device, uint8_t AnimationID, uint8_t AnimationInstance, int16_t X, int16_t Y);
/*!
 Start/Stop Animation
@param[in] gtt_device the target gtt device
@param[in] AnimationInstance Index used to identify this animation instance in the animation list.
@param[in] State Desired animation state, as per eAnimationState.
*/
void gtt_start_stop_animation(gtt_device *device, uint8_t AnimationInstance, eAnimationState State);
/*!
 Set Animation Frame
@param[in] gtt_device the target gtt device
@param[in] AnimationInstance Index used to identify this animation instance in the animation list.
@param[in] Frame Number of the frame to be displayed.
*/
void gtt_set_animation_state(gtt_device *device, uint8_t AnimationInstance, uint8_t Frame);
/*!
 Get Animation Frame
@param[in] gtt_device the target gtt device
@param[in] AnimationInstance Index used to identify this animation instance in the animation list.
*/
uint8_t gtt_get_animation_state(gtt_device *device, uint8_t AnimationInstance);
/*!
 Stop All Animations
@param[in] gtt_device the target gtt device
*/
void gtt_stop_all_animations(gtt_device *device);
/*!
 Clear Animation
@param[in] gtt_device the target gtt device
@param[in] AnimationInstance Index used to identify this animation instance in the animation list.
*/
void gtt_clear_animation(gtt_device *device, uint8_t AnimationInstance);
/*!
 Clear All Animations
@param[in] gtt_device the target gtt device
*/
void gtt_clear_all_animations(gtt_device *device);
/*!
 Resume All Animations
@param[in] gtt_device the target gtt device
*/
void gtt_resume_all_animations(gtt_device *device);
/*!
 Write ScratchPad
@param[in] gtt_device the target gtt device
@param[in] Index Starting index of the data to be written.
@param[in] Data Data to temporarily save in volatile memory.
*/
void gtt_write_scratch_pad(gtt_device *device, uint16_t Index, gtt_bytearray_l16  Data);
/*!
 Read ScratchPad
@param[in] gtt_device the target gtt device
@param[in] Index Starting index of the data to be read.
@param[in] Size Length of the data requested.
*/
gtt_bytearray_l16  gtt_read_scratch_pad(gtt_device *device, uint16_t Index, uint16_t Size);
/*!
 Clear a Buffer
@param[in] gtt_device the target gtt device
@param[in] Type Type of buffer to clear, as per eBuffers.
@param[in] ID Index of the file to be cleared from buffer memory.
*/
void gtt_clear_a_buffer(gtt_device *device, eBuffers Type, uint8_t ID);
/*!
 Clear All Buffers
@param[in] gtt_device the target gtt device
*/
void gtt_clear_all_buffers(gtt_device *device);
/*!
 Set Font Rendering Style
@param[in] gtt_device the target gtt device
@param[in] RenderType Rendertype, as per eFontRenderType.
*/
void gtt_set_font_render_style(gtt_device *device, eFontRenderType RenderType);
/*!
 Set Font Anchor Style
@param[in] gtt_device the target gtt device
@param[in] AnchorType Type of anchor, as per eAnchor.
*/
void gtt_set_font_anchor(gtt_device *device, eAnchorType AnchorType);
/*!
 Assign Keypad Codes
@param[in] gtt_device the target gtt device
@param[in] KeyCodes A list of byte values for each key to be defined.  Default values are 65 through 90.
*/
void gtt_assign_key_codes(gtt_device *device, gtt_bytearray_l8  KeyCodes);
/*!
 Set I2C Address
@param[in] gtt_device the target gtt device
@param[in] I2Caddress I2C write address, must be an even value.
*/
void gtt_set_i2c_address(gtt_device *device, uint8_t I2Caddress);
/*!
 Echo
@param[in] gtt_device the target gtt device
@param[in] Message An arbitrary string that the module will return.  Limited to 4KB in length.
*/
char * gtt_echo(gtt_device *device, char * Message);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectType 
@param[in] ObjectID 
*/
eStatusCode gtt25_baseobject_create(gtt_device* device, eObjectType ObjectType, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_baseobject_destroy(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_baseobject_begin_update(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_baseobject_end_update(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
@param[in] Value 
*/
eStatusCode gtt25_baseobject_set_property_u8(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, uint8_t Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
*/
eStatusCode gtt25_baseobject_get_property_u8(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, uint8_t* out_Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
@param[in] Value 
*/
eStatusCode gtt25_baseobject_set_property_u16(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, uint16_t Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
*/
eStatusCode gtt25_baseobject_get_property_u16(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, uint16_t* out_Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
@param[in] Value 
*/
eStatusCode gtt25_baseobject_set_property_s16(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, int16_t Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
*/
eStatusCode gtt25_baseobject_get_property_s16(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, int16_t* out_Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
@param[in] Value 
*/
eStatusCode gtt25_baseobject_set_property_text(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, gtt_text  Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
*/
eStatusCode gtt25_baseobject_get_property_text(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, gtt_text * out_Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
@param[in] Value 
*/
eStatusCode gtt25_baseobject_set_property_eval(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, gtt_text  Value);


/*!
 
@param[in] gtt_device the target gtt device
*/
eStatusCode gtt25_baseobject_destroy_all(gtt_device* device);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_baseobject_get_object_type(gtt_device* device, uint16_t ObjectID, eObjectType* out_ObjectType);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
@param[in] Value 
*/
eStatusCode gtt25_baseobject_append_property_text(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, gtt_text  Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] EventID 
@param[in] EventGraphObjectID 
*/
eStatusCode gtt25_baseobject_set_event_handler(gtt_device* device, uint16_t ObjectID, eEventID EventID, uint16_t EventGraphObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
@param[in] Value 
*/
eStatusCode gtt25_baseobject_set_property_float(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, float Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] PropertyID 
*/
eStatusCode gtt25_baseobject_get_property_float(gtt_device* device, uint16_t ObjectID, uint16_t PropertyID, float* out_Value);


/*!
 
@param[in] gtt_device the target gtt device
*/
eStatusCode gtt25_baseobject_process_changes(gtt_device* device);


eStatusCode gtt25_get_baseobject_protected(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_baseobject_protected(gtt_device * device, uint16_t ObjectID, uint8_t value);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_visualobject_invalidate(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObjectID 
@param[in] PropertyID 
*/
eStatusCode gtt25_visualobject_add_dependency(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_visualobject_set_focus(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_visualobject_next_focus(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_visualobject_prev_focus(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
*/
eStatusCode gtt25_visualobject_global_next_focus(gtt_device* device);


/*!
 
@param[in] gtt_device the target gtt device
*/
eStatusCode gtt25_visualobject_global_prev_focus(gtt_device* device);


eStatusCode gtt25_get_visualobject_invalidated(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_visualobject_invalidated(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_visualobject_left(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_visualobject_left(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_visualobject_top(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_visualobject_top(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_visualobject_width(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_visualobject_width(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_visualobject_height(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_visualobject_height(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_visualobject_can_focus(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_visualobject_can_focus(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_visualobject_has_focus(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_visualobject_has_focus(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_visualobject_enabled(gtt_device * device, uint16_t ObjectID, eOnOff* result);
eStatusCode gtt25_set_visualobject_enabled(gtt_device * device, uint16_t ObjectID, eOnOff value);
eStatusCode gtt25_get_gauge_min_value(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_gauge_min_value(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_gauge_max_value(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_gauge_max_value(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_gauge_value(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_gauge_value(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_gauge_start_angle(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_gauge_start_angle(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_gauge_end_angle(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_gauge_end_angle(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_gauge_needle_color_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_needle_color_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_needle_color_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_needle_color_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_needle_color_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_needle_color_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_needle_width(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_needle_width(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_background_image(gtt_device * device, uint16_t ObjectID, gtt_text * result);
eStatusCode gtt25_set_gauge_background_image(gtt_device * device, uint16_t ObjectID, gtt_text  value);
eStatusCode gtt25_get_gauge_animation_speed(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_gauge_animation_speed(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_gauge_base_radius(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_base_radius(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_gauge_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_gauge_label_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_label_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_label_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_label_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_label_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_label_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_label_text(gtt_device * device, uint16_t ObjectID, gtt_text * result);
eStatusCode gtt25_set_gauge_label_text(gtt_device * device, uint16_t ObjectID, gtt_text  value);
eStatusCode gtt25_get_gauge_label_left(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_gauge_label_left(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_gauge_label_top(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_gauge_label_top(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_gauge_label_width(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_gauge_label_width(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_gauge_label_height(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_gauge_label_height(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_gauge_needle_x(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_gauge_needle_x(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_gauge_needle_y(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_gauge_needle_y(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_gauge_needle_start_radius(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_gauge_needle_start_radius(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_gauge_needle_end_radius(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_gauge_needle_end_radius(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_gauge_needle_location(gtt_device * device, uint16_t ObjectID, eNeedleLocation* result);
eStatusCode gtt25_set_gauge_needle_location(gtt_device * device, uint16_t ObjectID, eNeedleLocation value);
eStatusCode gtt25_get_gauge_needle_mode(gtt_device * device, uint16_t ObjectID, eNeedleMode* result);
eStatusCode gtt25_set_gauge_needle_mode(gtt_device * device, uint16_t ObjectID, eNeedleMode value);
eStatusCode gtt25_get_gauge_needle_width_tip(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gauge_needle_width_tip(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_gauge_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_gauge_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t value);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_strokepad_clear(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_strokepad_get_stroke_count(gtt_device* device, uint16_t ObjectID, uint32_t* out_Count);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] StrokeID 
*/
eStatusCode gtt25_strokepad_get_stroke(gtt_device* device, uint16_t ObjectID, uint32_t StrokeID, gtt_wordarray_l32* out_StrokeData);


eStatusCode gtt25_get_strokepad_stroke_color_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_strokepad_stroke_color_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_strokepad_stroke_color_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_strokepad_stroke_color_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_strokepad_stroke_color_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_strokepad_stroke_color_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_strokepad_color_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_strokepad_color_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_strokepad_color_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_strokepad_color_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_strokepad_color_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_strokepad_color_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObjectID 
@param[in] PropertyID 
@param[in] Time 
@param[in] Value 
*/
eStatusCode gtt25_storyboard_set_value_u8(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint8_t Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObjectID 
@param[in] PropertyID 
@param[in] Time 
@param[in] Value 
*/
eStatusCode gtt25_storyboard_set_value_u16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint16_t Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObjectID 
@param[in] PropertyID 
@param[in] Time 
@param[in] Value 
*/
eStatusCode gtt25_storyboard_set_value_s16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, int16_t Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObjectID 
@param[in] PropertyID 
@param[in] Time 
@param[in] Value 
*/
eStatusCode gtt25_storyboard_set_value_u32(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint32_t Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_storyboard_start(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_storyboard_stop(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObjectID 
@param[in] PropertyID 
@param[in] Time 
@param[in] Duration 
@param[in] Value 
@param[in] Easing 
*/
eStatusCode gtt25_storyboard_animate_value_u8(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint16_t Duration, uint8_t Value, eEasing Easing);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObjectID 
@param[in] PropertyID 
@param[in] Time 
@param[in] Duration 
@param[in] Value 
@param[in] Easing 
*/
eStatusCode gtt25_storyboard_animate_value_s16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint16_t Duration, int16_t Value, eEasing Easing);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObjectID 
@param[in] PropertyID 
@param[in] Time 
@param[in] Value 
*/
eStatusCode gtt25_storyboard_set_value_string(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, gtt_text  Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] Time 
@param[in] Frequency 
@param[in] Duration 
*/
eStatusCode gtt25_storyboard_beep(gtt_device* device, uint16_t ObjectID, uint16_t Time, uint16_t Frequency, uint16_t Duration);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObjectID 
@param[in] PropertyID 
@param[in] Time 
@param[in] Duration 
@param[in] Value 
@param[in] Easing 
*/
eStatusCode gtt25_storyboard_animate_value_u16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObjectID, uint16_t PropertyID, uint16_t Time, uint16_t Duration, uint16_t Value, eEasing Easing);


eStatusCode gtt25_get_storyboard_duration(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_storyboard_duration(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_storyboard_loops(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_storyboard_loops(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_rectangle_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_rectangle_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_rectangle_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_rectangle_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_rectangle_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_rectangle_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] ConditionId 
@param[in] ConditionTrue 
@param[in] Action 
@param[in] ExtraData 
*/
eStatusCode gtt25_trigger_create_trigger(gtt_device* device, uint16_t ObjectID, uint16_t ConditionId, uint8_t ConditionTrue, eAction Action, uint16_t ExtraData);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] ConditionId 
@param[in] ConditionTrue 
@param[in] TargetObject 
@param[in] TargetProperty 
@param[in] Value 
*/
eStatusCode gtt25_trigger_set_property_eval(gtt_device* device, uint16_t ObjectID, uint16_t ConditionId, uint8_t ConditionTrue, uint16_t TargetObject, ePropertyID TargetProperty, gtt_text  Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObject 
@param[in] TargetProperty 
@param[in] Comparison 
@param[in] CompareValue 
*/
eStatusCode gtt25_condition_create_property_u8(gtt_device* device, uint16_t ObjectID, uint16_t TargetObject, ePropertyID TargetProperty, eComparison Comparison, uint8_t CompareValue);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetObject 
@param[in] TargetProperty 
@param[in] Comparison 
@param[in] CompareValue 
*/
eStatusCode gtt25_condition_create_property_u16(gtt_device* device, uint16_t ObjectID, uint16_t TargetObject, ePropertyID TargetProperty, eComparison Comparison, uint16_t CompareValue);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] ConditionA 
@param[in] ConditionB 
@param[in] Comparison 
*/
eStatusCode gtt25_condition_create_logical(gtt_device* device, uint16_t ObjectID, uint16_t ConditionA, uint16_t ConditionB, eLogicalComparison Comparison);


eStatusCode gtt25_get_condition_value(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_condition_value(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_label_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_label_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_label_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_label_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_label_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_label_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_label_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_label_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_label_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_label_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_label_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_label_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_label_text(gtt_device * device, uint16_t ObjectID, gtt_text * result);
eStatusCode gtt25_set_label_text(gtt_device * device, uint16_t ObjectID, gtt_text  value);
eStatusCode gtt25_get_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_label_h_align(gtt_device * device, uint16_t ObjectID, eLabelHorizontalAlignment* result);
eStatusCode gtt25_set_label_h_align(gtt_device * device, uint16_t ObjectID, eLabelHorizontalAlignment value);
eStatusCode gtt25_get_label_v_align(gtt_device * device, uint16_t ObjectID, eLabelVerticalAlignment* result);
eStatusCode gtt25_set_label_v_align(gtt_device * device, uint16_t ObjectID, eLabelVerticalAlignment value);
eStatusCode gtt25_get_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_label_objid__background(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_label_objid__background(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_label_grayscale(gtt_device * device, uint16_t ObjectID, eOnOff* result);
eStatusCode gtt25_set_label_grayscale(gtt_device * device, uint16_t ObjectID, eOnOff value);
eStatusCode gtt25_get_slider_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_minimum(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_slider_minimum(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_slider_maximum(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_slider_maximum(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_slider_value(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_slider_value(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_slider_label_text(gtt_device * device, uint16_t ObjectID, gtt_text * result);
eStatusCode gtt25_set_slider_label_text(gtt_device * device, uint16_t ObjectID, gtt_text  value);
eStatusCode gtt25_get_slider_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_label_font_object(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_label_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_label_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_label_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_label_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_label_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_label_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_style(gtt_device * device, uint16_t ObjectID, eSliderStyle* result);
eStatusCode gtt25_set_slider_style(gtt_device * device, uint16_t ObjectID, eSliderStyle value);
eStatusCode gtt25_get_slider_objid__nine_fore_ground(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_objid__nine_fore_ground(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_objid__nine_back_ground(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_objid__nine_back_ground(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_objid__nine_button(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_objid__nine_button(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_button_width(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_button_width(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_button_height(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_button_height(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_enable_touch(gtt_device * device, uint16_t ObjectID, eOnOff* result);
eStatusCode gtt25_set_slider_enable_touch(gtt_device * device, uint16_t ObjectID, eOnOff value);
eStatusCode gtt25_get_slider_direction(gtt_device * device, uint16_t ObjectID, eSliderDirection* result);
eStatusCode gtt25_set_slider_direction(gtt_device * device, uint16_t ObjectID, eSliderDirection value);
eStatusCode gtt25_get_slider_track_size(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_track_size(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_objid__background(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_objid__background(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_objid__bitmap_fore_ground(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_objid__bitmap_fore_ground(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_objid__bitmap_back_ground(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_objid__bitmap_back_ground(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_objid__bitmap_button(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_objid__bitmap_button(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_button_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_button_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_button_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_button_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_button_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_slider_button_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_slider_draw_button(gtt_device * device, uint16_t ObjectID, eOnOff* result);
eStatusCode gtt25_set_slider_draw_button(gtt_device * device, uint16_t ObjectID, eOnOff value);
eStatusCode gtt25_get_slider_pad_button(gtt_device * device, uint16_t ObjectID, eOnOff* result);
eStatusCode gtt25_set_slider_pad_button(gtt_device * device, uint16_t ObjectID, eOnOff value);
eStatusCode gtt25_get_slider_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_label_font_size(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_slider_label_on_button(gtt_device * device, uint16_t ObjectID, eOnOff* result);
eStatusCode gtt25_set_slider_label_on_button(gtt_device * device, uint16_t ObjectID, eOnOff value);
eStatusCode gtt25_get_slider_origin(gtt_device * device, uint16_t ObjectID, eSliderOrigin* result);
eStatusCode gtt25_set_slider_origin(gtt_device * device, uint16_t ObjectID, eSliderOrigin value);
eStatusCode gtt25_get_slider_offset(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_slider_offset(gtt_device * device, uint16_t ObjectID, int16_t value);
eStatusCode gtt25_get_slider_objid__bitmap_mask(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_slider_objid__bitmap_mask(gtt_device * device, uint16_t ObjectID, uint16_t value);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] SourceObjectID 
@param[in] SourcePropertyID 
@param[in] TargetObjectID 
@param[in] TargetPropertyID 
*/
eStatusCode gtt25_databinding_setup_binding(gtt_device* device, uint16_t ObjectID, uint16_t SourceObjectID, ePropertyID SourcePropertyID, uint16_t TargetObjectID, ePropertyID TargetPropertyID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] SourceObjectID 
@param[in] SourcePropertyID 
@param[in] TargetObjectID 
@param[in] TargetPropertyID 
@param[in] Equation 
*/
eStatusCode gtt25_databinding_setup_eval_binding(gtt_device* device, uint16_t ObjectID, uint16_t SourceObjectID, ePropertyID SourcePropertyID, uint16_t TargetObjectID, ePropertyID TargetPropertyID, gtt_text  Equation);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] Path 
*/
eStatusCode gtt25_nineslice_load(gtt_device* device, uint16_t ObjectID, gtt_text  Path);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] Path 
*/
eStatusCode gtt25_bitmap_load(gtt_device* device, uint16_t ObjectID, gtt_text  Path);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] Left 
@param[in] Top 
@param[in] Width 
@param[in] Height 
*/
eStatusCode gtt25_bitmap_capture(gtt_device* device, uint16_t ObjectID, uint16_t Left, uint16_t Top, uint16_t Width, uint16_t Height);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] Path 
*/
eStatusCode gtt25_font_load(gtt_device* device, uint16_t ObjectID, gtt_text  Path);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] FontSize 
@param[in] GreyScale 
@param[in] Text 
*/
eStatusCode gtt25_font_cache(gtt_device* device, uint16_t ObjectID, uint8_t FontSize, eOnOff GreyScale, gtt_text  Text);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] FontSize 
*/
eStatusCode gtt25_font_clear_cache(gtt_device* device, uint16_t ObjectID, uint8_t FontSize);


/*!
 
@param[in] gtt_device the target gtt device
*/
eStatusCode gtt25_font_clear_cache_all(gtt_device* device);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Size 
*/
eStatusCode gtt25_font_set_auto_cache_size_limit(gtt_device* device, uint32_t Size);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
*/
eStatusCode gtt25_filesystem_get_file_size(gtt_device* device, gtt_text  Path, uint32_t* out_Size);


/*!
 Read the current amount of available space on the SD card.
@param[in] gtt_device the target gtt device
*/
eStatusCode gtt25_filesystem_get_free_space(gtt_device* device, uint32_t* out_Size);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] FromPath 
@param[in] ToPath 
*/
eStatusCode gtt25_filesystem_move(gtt_device* device, gtt_text  FromPath, gtt_text  ToPath);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
*/
eStatusCode gtt25_filesystem_get_crc(gtt_device* device, gtt_text  Path, uint32_t* out_CRC);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
*/
eStatusCode gtt25_filesystem_get_files(gtt_device* device, gtt_text  Path, gtt_bytearray_l16* out_Result);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
*/
eStatusCode gtt25_filesystem_create_folder(gtt_device* device, gtt_text  Path);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
@param[in] Recursive 
*/
eStatusCode gtt25_filesystem_delete_folder(gtt_device* device, gtt_text  Path, uint8_t Recursive);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
@param[in] Index 
@param[in] FileData 
*/
eStatusCode gtt25_filesystem_file_write(gtt_device* device, gtt_text  Path, uint32_t Index, gtt_bytearray_l16 FileData);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
@param[in] Index 
@param[in] Length 
*/
eStatusCode gtt25_filesystem_file_read(gtt_device* device, gtt_text  Path, uint32_t Index, uint16_t Length, gtt_bytearray_l16* out_FileData);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
*/
eStatusCode gtt25_filesystem_file_delete(gtt_device* device, gtt_text  Path);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
@param[in] Length 
*/
eStatusCode gtt25_filesystem_start_xmodem_upload(gtt_device* device, gtt_text  Path, uint32_t Length);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Path 
*/
eStatusCode gtt25_filesystem_test_method(gtt_device* device, gtt_text  Path, uint32_t* out_Size);


eStatusCode gtt25_get_tracebinding_trace_slot(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_tracebinding_trace_slot(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_tracebinding_value(gtt_device * device, uint16_t ObjectID, int16_t* result);
eStatusCode gtt25_set_tracebinding_value(gtt_device * device, uint16_t ObjectID, int16_t value);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] NodeID 
@param[in] NodeType 
*/
eStatusCode gtt25_eventgraph_create_node(gtt_device* device, uint16_t ObjectID, uint16_t NodeID, eEventNodeType NodeType);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] SourceNodeID 
@param[in] SourceOutput 
@param[in] TargetNodeID 
@param[in] TargetInput 
*/
eStatusCode gtt25_eventgraph_add_link(gtt_device* device, uint16_t ObjectID, uint16_t SourceNodeID, eEventNodeSocket SourceOutput, uint16_t TargetNodeID, eEventNodeSocket TargetInput);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetNodeID 
@param[in] TargetInput 
@param[in] Value 
*/
eStatusCode gtt25_eventgraph_set_node_value_text(gtt_device* device, uint16_t ObjectID, uint16_t TargetNodeID, eEventNodeSocket TargetInput, gtt_text  Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetNodeID 
@param[in] TargetInput 
@param[in] Value 
*/
eStatusCode gtt25_eventgraph_set_node_value_u8(gtt_device* device, uint16_t ObjectID, uint16_t TargetNodeID, eEventNodeSocket TargetInput, uint8_t Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetNodeID 
@param[in] TargetInput 
@param[in] Value 
*/
eStatusCode gtt25_eventgraph_set_node_value_u16(gtt_device* device, uint16_t ObjectID, uint16_t TargetNodeID, eEventNodeSocket TargetInput, uint16_t Value);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] TargetNodeID 
@param[in] TargetInput 
@param[in] Value 
*/
eStatusCode gtt25_eventgraph_set_node_value_float(gtt_device* device, uint16_t ObjectID, uint16_t TargetNodeID, eEventNodeSocket TargetInput, float Value);


eStatusCode gtt25_get_button_background_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_background_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_background_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_background_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_background_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_background_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_text(gtt_device * device, uint16_t ObjectID, gtt_text * result);
eStatusCode gtt25_set_button_text(gtt_device * device, uint16_t ObjectID, gtt_text  value);
eStatusCode gtt25_get_button_font_object(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_button_font_object(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_button_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_foreground_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_foreground_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_foreground_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_font_size(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_font_size(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_up_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_button_up_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_button_down_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_button_down_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_button_focus_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_button_focus_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_button_state(gtt_device * device, uint16_t ObjectID, eButtonState* result);
eStatusCode gtt25_set_button_state(gtt_device * device, uint16_t ObjectID, eButtonState value);
eStatusCode gtt25_get_button_button_type(gtt_device * device, uint16_t ObjectID, eButtonType* result);
eStatusCode gtt25_set_button_button_type(gtt_device * device, uint16_t ObjectID, eButtonType value);
eStatusCode gtt25_get_button_disabled_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_button_disabled_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_button_button_group(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_button_button_group(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_button_disabled_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_disabled_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_disabled_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_disabled_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_disabled_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_disabled_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_down_r(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_down_r(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_down_g(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_down_g(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_down_b(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_button_down_b(gtt_device * device, uint16_t ObjectID, uint8_t value);
eStatusCode gtt25_get_button_corner_radius(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_button_corner_radius(gtt_device * device, uint16_t ObjectID, uint16_t value);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] X 
@param[in] Y 
@param[in] W 
@param[in] H 
@param[in] PixelFormat 
@param[in] Buffered 
*/
eStatusCode gtt25_gttmodule_setup_usb_direct_write(gtt_device* device, uint16_t X, uint16_t Y, uint16_t W, uint16_t H, eDirectWritePixelFormat PixelFormat, eOnOff Buffered);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] X 
*/
eStatusCode gtt25_gttmodule_setup_usb_direct_write_palette(gtt_device* device, gtt_bytearray_l16 X);


/*!
 
@param[in] gtt_device the target gtt device
*/
eStatusCode gtt25_gttmodule_get_last_startup_flag(gtt_device* device, eStartupMode* out_Mode);


/*!
 
@param[in] gtt_device the target gtt device
*/
eStatusCode gtt25_gttmodule_reset(gtt_device* device);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] Magic 
@param[in] MACAddress 
*/
eStatusCode gtt25_gttmodule_set_m_a_c_address_method(gtt_device* device, uint32_t Magic, gtt_bytearray_l16 MACAddress);


/*!
 
@param[in] gtt_device the target gtt device
*/
eStatusCode gtt25_gttmodule_get_m_a_c_address_method(gtt_device* device, gtt_bytearray_l16* out_MACAddress);


eStatusCode gtt25_get_gttmodule_backlight(gtt_device * device, uint16_t ObjectID, uint8_t* result);
eStatusCode gtt25_set_gttmodule_backlight(gtt_device * device, uint16_t ObjectID, uint8_t value);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] ItemID 
*/
eStatusCode gtt25_objectlist_add(gtt_device* device, uint16_t ObjectID, uint16_t ItemID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] ItemID 
*/
eStatusCode gtt25_objectlist_remove(gtt_device* device, uint16_t ObjectID, uint16_t ItemID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_objectlist_count(gtt_device* device, uint16_t ObjectID, uint32_t* out_Count);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] ItemIndex 
*/
eStatusCode gtt25_objectlist_get(gtt_device* device, uint16_t ObjectID, uint32_t ItemIndex, uint16_t* out_ItemID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_objectlist_clear(gtt_device* device, uint16_t ObjectID);


eStatusCode gtt25_get_visualbitmap_source(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_visualbitmap_source(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_visualbitmap_source_index(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_visualbitmap_source_index(gtt_device * device, uint16_t ObjectID, uint16_t value);
/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
@param[in] ItemID 
@param[in] Duration 
*/
eStatusCode gtt25_animation_add_frame(gtt_device* device, uint16_t ObjectID, uint16_t ItemID, uint16_t Duration);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_animation_start(gtt_device* device, uint16_t ObjectID);


/*!
 
@param[in] gtt_device the target gtt device
@param[in] ObjectID 
*/
eStatusCode gtt25_animation_stop(gtt_device* device, uint16_t ObjectID);


eStatusCode gtt25_get_animation_master(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_animation_master(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_animation_master_mode(gtt_device * device, uint16_t ObjectID, eAnimationMaterMode* result);
eStatusCode gtt25_set_animation_master_mode(gtt_device * device, uint16_t ObjectID, eAnimationMaterMode value);
eStatusCode gtt25_get_animation_current_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_animation_current_bitmap(gtt_device * device, uint16_t ObjectID, uint16_t value);
eStatusCode gtt25_get_animation_loops(gtt_device * device, uint16_t ObjectID, uint16_t* result);
eStatusCode gtt25_set_animation_loops(gtt_device * device, uint16_t ObjectID, uint16_t value);
#ifdef __cplusplus
}
#endif
#endif

