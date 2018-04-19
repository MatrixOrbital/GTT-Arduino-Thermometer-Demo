#include "usb_gtt.h"
#include <libusb.h>
#include <stdlib.h>
#include "gtt_device.h"

int usb_gtt_init()
{
	if (libusb_init(NULL) < 0)
		return 0;
	else
		return 1;
}

int usb_write(gtt_device *device, uint8_t *data, size_t length)
{
	int bytesWritten = 0;
	if (libusb_bulk_transfer((libusb_device_handle *) device->Context, GTT_WRITE_EP, data, length, &bytesWritten, 0) < 0)
		return -1;
	else
		return bytesWritten; 
}

int usb_read(gtt_device *device)
{
	unsigned char Result;
	int BytesRead;
	if (libusb_bulk_transfer((libusb_device_handle *)device->Context, GTT_READ_EP, &Result, 1, &BytesRead, 10) < 0)
		return -1;
	else
	{
		return BytesRead ? Result : -1;
	}
	
}

libusb_device_handle *usb_gtt_open_device(int index)
{
	libusb_device **devs;
	libusb_device_handle *device_handle = NULL;
	if (libusb_get_device_list(NULL, &devs) < 0)
		return NULL;

	struct libusb_device *dev;
	int i = 0;
	int count = 0;
	while ((dev = devs[i++]) != NULL)
	{
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0)
			continue;

		if ((desc.idVendor == VENDOR_MATRIXORBITAL) && (desc.idProduct >> 8 == PRODUCT_GTT))
		{
			if (count == index)
			{
				if (libusb_open(dev, &device_handle) < 0)
					return NULL;
				else
				{
					libusb_claim_interface(device_handle, 0);
					return device_handle;
				}

			}
			count++;
		}
	}
	return NULL;
}

gtt_device* usb_gtt_open(size_t index, size_t rx_buffer_size, size_t tx_buffer_size)
{
	libusb_device_handle *device = usb_gtt_open_device(index);
	if (device)
	{
		gtt_device * result = (gtt_device *)calloc(1, sizeof(gtt_device));
		result->Context = device;
		result->Read = usb_read;
		result->Write = usb_write;
		result->rx_buffer = (uint8_t*)malloc(rx_buffer_size);
		result->rx_buffer_size = rx_buffer_size;
		result->tx_buffer = (uint8_t*)malloc(tx_buffer_size);
		result->tx_buffer_size = tx_buffer_size;
		return result;
	}
	else
		return NULL;

}
