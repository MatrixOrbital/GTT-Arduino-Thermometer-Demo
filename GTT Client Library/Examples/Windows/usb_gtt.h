#ifndef _USB_GTT_H
#define _USB_GTT_H
#include "gtt_device.h"

#define VENDOR_MATRIXORBITAL 0x1b3d
#define PRODUCT_GTT          0xfe
#define GTT_WRITE_EP         0x02
#define GTT_READ_EP          0x82

int usb_gtt_init();
gtt_device* usb_gtt_open(size_t index, size_t rx_buffer_size, size_t tx_buffer_size);

#endif