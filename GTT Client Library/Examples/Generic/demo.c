#include <gtt_protocol.h>
#include <gtt_device.h>

// Buffer for incoming data
uint8_t rx_buffer[512];

// Buffer for outgoing data
uint8_t tx_buffer[512];

int generic_write(gtt_device *device, uint8_t *data, size_t length)
{
	//TODO: This function is a platform dependend write function that
	//      transfer 'length' bytes of 'data' to the unit. 
	//      this function returns the number of bytes written 
	return 0;
	
}

int generic_read(gtt_device *device)
{
	//TODO: This function is a platform dependend read function that 
	//      reads a single byte from the unit. 
	//      this function returns the byte read when data is available
	//      and returns -1 if no data is currently available. 
	return -1;
}


// The gtt_device structre keeps the state of the gtt protocol and allows
// the library to talk to several devices connected to the same system
// it needs a platform depenend read/write function and some basic 
// information about the size and location of the instance specific rx/tx buffers. 
gtt_device gtt_device_instance = {
	.Write = generic_write,
	.Read = generic_read,
	.rx_buffer = rx_buffer,
	.rx_buffer_size = sizeof(rx_buffer),
	.tx_buffer = tx_buffer,
	.tx_buffer_size = sizeof(tx_buffer),
};

int main(int argc, char** argv)
{
	gtt_device *gtt = &gtt_device_instance;
	
	//Clear the screen
	gtt_clear_screen(gtt);

	//Draw a line in the default drawing color
	gtt_draw_line(gtt, 0, 0, 480, 272);
	
	//Process any data coming in	
	while (1)
	{
		gtt_parser_process(gtt);
	}

	return 0;
}

