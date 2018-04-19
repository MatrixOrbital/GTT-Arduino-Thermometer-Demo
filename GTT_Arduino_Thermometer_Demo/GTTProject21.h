#ifndef __GTTPROJECT21_H
#define __GTTPROJECT21_H

#include <gtt_protocol.h>

/* Objects for screen : Screen1 */
#define id_screen1_static_text_1 1
#define id_screen1_image_toggle_1 2
#define id_screen1_static_text_2 3
#define id_screen1_bar_graph_1 4
#define id_screen1_dynamic_label_2 5
#define id_screen1_image_toggle_2 6
#define id_screen1_static_text_3 7
#define id_screen1_image_toggle_3 8
#define id_screen1_circle_button_1 9
#define id_screen1_static_text_4 10
#define id_screen1_circle_button_2 11
#define id_screen1_circle_button_3 12
#define id_screen1_circle_button_4 13
#define id_screen1_dynamic_label_1 14
#define id_screen1_dynamic_label_3 15
#define id_screen1_a_l_a_r_m 16
#define id_screen1_static_text_5 17
#define id_screen1_static_text_6 18


eStatusCode gtt_get_screen1_static_text_1_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_static_text_1_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_static_text_1_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_1_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_1_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_1_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_1_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_1_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_1_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_1_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_1_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_1_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_1_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_1_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_image_toggle_1_state(gtt_device* device, eButtonState *value);
eStatusCode gtt_set_screen1_image_toggle_1_state(gtt_device* device, eButtonState value);
eStatusCode gtt_get_screen1_static_text_2_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_static_text_2_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_static_text_2_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_2_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_2_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_2_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_2_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_2_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_2_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_2_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_2_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_2_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_2_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_2_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_bar_graph_1_value(gtt_device* device, int16_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_value(gtt_device* device, int16_t value);
eStatusCode gtt_get_screen1_bar_graph_1_minimum(gtt_device* device, int16_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_minimum(gtt_device* device, int16_t value);
eStatusCode gtt_get_screen1_bar_graph_1_maximum(gtt_device* device, int16_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_maximum(gtt_device* device, int16_t value);
eStatusCode gtt_get_screen1_bar_graph_1_label_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_label_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_bar_graph_1_label_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_label_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_bar_graph_1_label_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_label_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_bar_graph_1_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_bar_graph_1_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_bar_graph_1_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_bar_graph_1_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_bar_graph_1_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_bar_graph_1_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_bar_graph_1_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_2_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_dynamic_label_2_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_dynamic_label_2_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_2_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_2_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_2_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_2_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_2_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_2_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_2_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_2_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_2_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_2_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_2_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_image_toggle_2_state(gtt_device* device, eButtonState *value);
eStatusCode gtt_set_screen1_image_toggle_2_state(gtt_device* device, eButtonState value);
eStatusCode gtt_get_screen1_static_text_3_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_static_text_3_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_static_text_3_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_3_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_3_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_3_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_3_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_3_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_3_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_3_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_3_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_3_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_3_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_3_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_image_toggle_3_state(gtt_device* device, eButtonState *value);
eStatusCode gtt_set_screen1_image_toggle_3_state(gtt_device* device, eButtonState value);
eStatusCode gtt_get_screen1_circle_button_1_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_circle_button_1_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_circle_button_1_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_1_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_1_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_1_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_1_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_1_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_4_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_static_text_4_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_static_text_4_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_4_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_4_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_4_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_4_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_4_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_4_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_4_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_4_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_4_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_4_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_4_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_2_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_circle_button_2_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_circle_button_2_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_2_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_2_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_2_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_2_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_2_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_3_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_circle_button_3_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_circle_button_3_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_3_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_3_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_3_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_3_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_3_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_4_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_circle_button_4_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_circle_button_4_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_4_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_4_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_4_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_circle_button_4_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_circle_button_4_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_1_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_dynamic_label_1_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_dynamic_label_1_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_1_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_1_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_1_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_1_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_1_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_1_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_1_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_1_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_1_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_1_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_1_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_3_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_dynamic_label_3_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_dynamic_label_3_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_3_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_3_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_3_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_3_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_3_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_3_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_3_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_3_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_3_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_dynamic_label_3_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_dynamic_label_3_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_a_l_a_r_m_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_a_l_a_r_m_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_a_l_a_r_m_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_a_l_a_r_m_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_a_l_a_r_m_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_a_l_a_r_m_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_a_l_a_r_m_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_a_l_a_r_m_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_a_l_a_r_m_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_a_l_a_r_m_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_a_l_a_r_m_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_a_l_a_r_m_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_a_l_a_r_m_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_a_l_a_r_m_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_5_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_static_text_5_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_static_text_5_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_5_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_5_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_5_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_5_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_5_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_5_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_5_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_5_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_5_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_5_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_5_background_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_6_text(gtt_device* device, gtt_text  *value);
eStatusCode gtt_set_screen1_static_text_6_text(gtt_device* device, gtt_text  value);
eStatusCode gtt_get_screen1_static_text_6_foreground_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_6_foreground_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_6_foreground_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_6_foreground_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_6_foreground_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_6_foreground_b(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_6_background_r(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_6_background_r(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_6_background_g(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_6_background_g(gtt_device* device, uint8_t value);
eStatusCode gtt_get_screen1_static_text_6_background_b(gtt_device* device, uint8_t *value);
eStatusCode gtt_set_screen1_static_text_6_background_b(gtt_device* device, uint8_t value);

#endif
