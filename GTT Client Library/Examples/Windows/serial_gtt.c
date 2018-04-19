#include "serial_gtt.h"
#include "serial.h"
#include <stdio.h>

#ifdef __GNUC__	
//Linux Libraries
#include <termios.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/signal.h> 
#include <sys/types.h> 
#define sprintf_s snprintf
#else	
//Windows Libraries	
#include <windows.h>
#include <conio.h>
#include <stdint.h>
#endif

int serial_write(gtt_device *device, uint8_t *data, size_t length)
{
	return Write(data, length);
}

int serial_read(gtt_device *device)
{
	uint8_t data;
	int res = Read(&data, 1);
	if (res != 1)
		return -1;
	else
	{
		return data;
	}
		
}

gtt_device* serial_gtt_open(const char* port, uint32_t baudrate, size_t rx_buffer_size, size_t tx_buffer_size)
{
	uint32_t error = CreateInterface(port);
	if (error != 0)
	{
		fprintf(stderr, "Error opening port!\n");
		return NULL;
	}
	error = SetInterfaceParameters(baudrate);
	if (error != 0)
	{
		fprintf(stderr, "Error setting port parameters!\n");
		return NULL;
	}
	error = SetInterfaceTimeouts(100);
	if (error != 0)
	{
		fprintf(stderr, "Error setting port timeouts!\n");
		return NULL;
	}
	gtt_device * result = (gtt_device *)calloc(1, sizeof(gtt_device));
	result->Context = NULL;
	result->Read = serial_read;
	result->Write = serial_write;
	result->rx_buffer = (uint8_t*)malloc(rx_buffer_size);
	result->rx_buffer_size = rx_buffer_size;
	result->tx_buffer = (uint8_t*)malloc(tx_buffer_size);
	result->tx_buffer_size = tx_buffer_size;
	return result;

}