#ifndef _GTT_DEVICE_H
#define _GTT_DEVICE_H
#include <stdint.h>
#include "gtt_enum.h"

#ifdef __cplusplus
extern "C" {
#endif
 
struct gtt_device;

#include "gtt_parser.h"
#include "gtt_events.h"
//this function must write a single byte to the device.
//returns 1 for success, -1 for failure
typedef int(*gtt_write)(gtt_device* device,uint8_t *data, size_t length);

//this bytes reads a byte from the device 
//if no data is available it must return -1 otherwise it should return the databyte
typedef int(*gtt_read)(gtt_device* device);

typedef struct gtt_waitlist_item
{
	uint8_t Done;            /* out: Has this packet been recieved */
	uint8_t Command;         /* in: Packet Type to look for */
	uint16_t SubCommand;     /* in: for 2.5 packets, the sub command to look for */
	size_t PacketStart;      /* out: Index in the RX Buffer where this data starts */
	size_t Length;           /* out: Length of this packet */
} gtt_waitlist_item;

typedef struct gtt_device
{
	void* Context;            /* device depended storage */
	gtt_write Write;          /* Function for writing data */
	gtt_read Read;            /* Function for reading data */
	uint8_t secured_packets;  /* 0 = regular protocol, 1 = wrap all outgoing packets with crc protection*/
	
	/* The fields below are internal and shall NOT be used by the read/write functions */
	
	gtt_parser Parser;        /* Protocol parser data */
	uint8_t *rx_buffer;       /* Buffer for incoming data */
	size_t rx_buffer_size;    /* size of the rx buffer in elements */
	uint8_t *tx_buffer;       /* Buffer for outgoing data */
	size_t tx_buffer_size;    /* size of the tx buffer in elements */
	size_t tx_index;          /* current index for the packet writer */
	gtt_events events;        /* Event Callbacks */
	size_t wait_idx;          /* Current Packet Index for the waitlist */
	gtt_waitlist_item waitlist[8]; /* Packet recieve waitlists */
} gtt_device;

#define NIWARN 

#ifdef __cplusplus
}
#endif

#endif