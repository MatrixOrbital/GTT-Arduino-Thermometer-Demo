#ifndef _SERIAL_GTT_H
#define _SERIAL_GTT_H

#include <gtt_device.h>

gtt_device* serial_gtt_open(const char* port, uint32_t baudrate, size_t rx_buffer_size, size_t tx_buffer_size);

#endif