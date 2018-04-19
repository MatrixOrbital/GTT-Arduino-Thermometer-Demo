#ifndef _SERIAL_H
#define _SERIAL_H
#include <stdint.h>
uint32_t CreateInterface(const char *port_name);
uint32_t DestroyInterface(void);
uint32_t SetInterfaceParameters(uint32_t baudRate);
uint32_t SetInterfaceTimeouts(uint32_t readIntervalTimeout);
uint32_t Write(uint8_t *data, uint32_t length);
uint32_t Read(uint8_t *data, uint32_t length);
#endif