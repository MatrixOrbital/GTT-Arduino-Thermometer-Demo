#ifndef __GTTPROJECT17_H
#define __GTTPROJECT17_H

#include <gtt_protocol.h>

/* Objects for screen : Screen1 */
#define id_screen1_main_label 1
#define id_screen1_btn_screen2 2
#define id_screen1_button_a 4
#define id_screen1_button_b 6
#define id_screen1_button_b_1 8
#define id_screen1_button_b_2 9
#define id_screen1_button_b_3 10

/* Objects for screen : Screen2 */
#define id_screen2_main_label 3
#define id_screen2_btn_screen1 5

/* Objects for screen : Loader */
#define id_loader_static_text_1 7
#define id_loader_slice_graph_1 65000

/* Objects for screen : Screen3 */
#define id_screen3_button_a 11
#define id_screen3_btn_screen2 12
#define id_screen3_main_label 13
#define id_screen3_button_b 14
#define id_screen3_button_b_1 15
#define id_screen3_button_b_2 16
#define id_screen3_button_b_3 17

/* Objects for screen : Screen4 */
#define id_screen4_button_a 18
#define id_screen4_btn_screen2 19
#define id_screen4_main_label 20
#define id_screen4_button_b 21
#define id_screen4_button_b_1 22
#define id_screen4_button_b_2 23
#define id_screen4_button_b_3 24


eStatusCode gtt_get_screen1_main_label_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_main_label_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_main_label_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_main_label_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_main_label_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_main_label_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_main_label_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_main_label_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_main_label_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_main_label_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_main_label_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_main_label_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_main_label_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_main_label_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_btn_screen2_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_btn_screen2_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_btn_screen2_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_btn_screen2_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_btn_screen2_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_btn_screen2_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_btn_screen2_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_btn_screen2_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_btn_screen2_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_btn_screen2_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_btn_screen2_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_btn_screen2_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_btn_screen2_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen1_btn_screen2_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen1_btn_screen2_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_btn_screen2_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__a_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__a_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__a_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__a_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__a_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__a_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__a_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__a_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__a_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__a_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__a_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__a_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__a_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen1_button__a_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen1_button__a_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__a_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen1_button__b_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen1_button__b_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_1_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_1_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_1_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_1_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_1_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_1_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_1_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_1_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_1_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_1_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_1_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_1_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_1_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen1_button__b_1_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen1_button__b_1_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_1_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_2_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_2_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_2_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_2_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_2_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_2_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_2_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_2_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_2_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_2_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_2_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_2_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_2_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen1_button__b_2_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen1_button__b_2_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_2_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_3_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_3_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_3_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_3_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_3_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_3_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_3_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_3_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_3_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_3_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_3_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_3_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_button__b_3_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen1_button__b_3_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen1_button__b_3_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_button__b_3_font_size(gtt_device* device, uint8_t value);

eStatusCode gtt_get_screen2_main_label_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen2_main_label_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen2_main_label_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_main_label_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_main_label_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_main_label_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_main_label_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_main_label_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_main_label_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_main_label_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_main_label_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_main_label_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_main_label_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_main_label_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_btn_screen1_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_btn_screen1_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_btn_screen1_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_btn_screen1_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_btn_screen1_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_btn_screen1_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_btn_screen1_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_btn_screen1_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_btn_screen1_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_btn_screen1_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_btn_screen1_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_btn_screen1_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen2_btn_screen1_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen2_btn_screen1_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen2_btn_screen1_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen2_btn_screen1_font_size(gtt_device* device, uint8_t value);

eStatusCode gtt_get_loader_static__text_1_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_loader_static__text_1_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_loader_static__text_1_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_loader_static__text_1_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_loader_static__text_1_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_loader_static__text_1_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_loader_static__text_1_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_loader_static__text_1_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_loader_static__text_1_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_loader_static__text_1_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_loader_static__text_1_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_loader_static__text_1_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_loader_static__text_1_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_loader_static__text_1_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_loader_slice__graph_1_value(gtt_device* device, int16_t *value);
eStatusCode gtt_set_loader_slice__graph_1_value(gtt_device* device, int16_t value);
eStatusCode gtt_get_loader_slice__graph_1_minimum(gtt_device* device, int16_t *value);
eStatusCode gtt_set_loader_slice__graph_1_minimum(gtt_device* device, int16_t value);
eStatusCode gtt_get_loader_slice__graph_1_maximum(gtt_device* device, int16_t *value);
eStatusCode gtt_set_loader_slice__graph_1_maximum(gtt_device* device, int16_t value);
eStatusCode gtt_get_loader_slice__graph_1_label_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_loader_slice__graph_1_label_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_loader_slice__graph_1_label_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_loader_slice__graph_1_label_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_loader_slice__graph_1_label_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_loader_slice__graph_1_label_b(gtt_device* device, uint8_t value);

eStatusCode gtt_get_screen3_button__a_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__a_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__a_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__a_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__a_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__a_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__a_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__a_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__a_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__a_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__a_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__a_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__a_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen3_button__a_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen3_button__a_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__a_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_btn_screen2_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_btn_screen2_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_btn_screen2_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_btn_screen2_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_btn_screen2_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_btn_screen2_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_btn_screen2_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_btn_screen2_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_btn_screen2_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_btn_screen2_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_btn_screen2_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_btn_screen2_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_btn_screen2_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen3_btn_screen2_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen3_btn_screen2_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_btn_screen2_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_main_label_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen3_main_label_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen3_main_label_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_main_label_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_main_label_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_main_label_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_main_label_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_main_label_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_main_label_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_main_label_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_main_label_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_main_label_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_main_label_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_main_label_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen3_button__b_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen3_button__b_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_1_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_1_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_1_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_1_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_1_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_1_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_1_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_1_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_1_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_1_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_1_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_1_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_1_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen3_button__b_1_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen3_button__b_1_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_1_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_2_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_2_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_2_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_2_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_2_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_2_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_2_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_2_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_2_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_2_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_2_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_2_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_2_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen3_button__b_2_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen3_button__b_2_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_2_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_3_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_3_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_3_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_3_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_3_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_3_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_3_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_3_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_3_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_3_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_3_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_3_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen3_button__b_3_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen3_button__b_3_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen3_button__b_3_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen3_button__b_3_font_size(gtt_device* device, uint8_t value);

eStatusCode gtt_get_screen4_button__a_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__a_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__a_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__a_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__a_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__a_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__a_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__a_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__a_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__a_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__a_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__a_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__a_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen4_button__a_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen4_button__a_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__a_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_btn_screen2_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_btn_screen2_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_btn_screen2_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_btn_screen2_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_btn_screen2_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_btn_screen2_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_btn_screen2_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_btn_screen2_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_btn_screen2_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_btn_screen2_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_btn_screen2_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_btn_screen2_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_btn_screen2_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen4_btn_screen2_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen4_btn_screen2_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_btn_screen2_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_main_label_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen4_main_label_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen4_main_label_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_main_label_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_main_label_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_main_label_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_main_label_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_main_label_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_main_label_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_main_label_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_main_label_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_main_label_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_main_label_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_main_label_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen4_button__b_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen4_button__b_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_1_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_1_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_1_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_1_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_1_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_1_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_1_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_1_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_1_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_1_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_1_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_1_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_1_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen4_button__b_1_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen4_button__b_1_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_1_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_2_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_2_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_2_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_2_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_2_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_2_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_2_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_2_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_2_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_2_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_2_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_2_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_2_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen4_button__b_2_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen4_button__b_2_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_2_font_size(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_3_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_3_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_3_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_3_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_3_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_3_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_3_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_3_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_3_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_3_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_3_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_3_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen4_button__b_3_font_object(gtt_device* device, uint16_t *value);
eStatusCode gtt_set_screen4_button__b_3_font_object(gtt_device* device, uint16_t value);
eStatusCode gtt_get_screen4_button__b_3_font_size(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen4_button__b_3_font_size(gtt_device* device, uint8_t value);

#endif
