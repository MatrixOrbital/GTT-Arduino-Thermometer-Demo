#include "serial.h"

#ifdef __GNUC__
//Unix Functions
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

int port;

uint32_t CreateInterface(char port_name[])
{
	port = open(port_name, O_RDWR | O_NOCTTY);
	if (port < 0)
	{
		return -1;
	}
	return 0;
}

uint32_t SetInterfaceParameters(uint32_t baudRate)
{
	struct termios term;
	term.c_cflag = baudRate | CS8 | CSTOPB | CLOCAL | CREAD;
	term.c_iflag = 0;
	term.c_oflag = 0;
	term.c_lflag = 0;
	tcflush(port, TCIFLUSH);
	tcsetattr(port, TCSANOW, &term);
	return 0;
}

uint32_t SetInterfaceTimeouts(uint32_t readIntervalTimeout)
{
	struct termios term;
	tcgetattr(port, &term);
	term.c_cc[VTIME] = readIntervalTimeout;
	tcsetattr(port, TCSANOW, &term);
	return 0;
}

uint32_t DestroyInterface(void)
{
	close(port);
}

uint32_t Write(uint8_t data[], uint32_t length)
{
	write(port, data, length);
	return length;
}

uint32_t Read(uint8_t data[], uint32_t length)
{
	return read(port, data, length);
}

#else
//Windows Functions
#include <windows.h>

HANDLE port;

uint32_t CreateInterface(const char *port_name)
{
	port = CreateFileA(port_name, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (port == INVALID_HANDLE_VALUE)
	{
		DWORD error_code = GetLastError();
		return error_code;
	}
	return 0;
}

uint32_t SetInterfaceParameters(uint32_t baudRate)
{
	DCB serial_parameters = { 0 };
	serial_parameters.DCBlength = sizeof(serial_parameters);
	serial_parameters.fInX = 0;
	serial_parameters.fOutxCtsFlow = 1;
	serial_parameters.fOutxDsrFlow = 1;
	serial_parameters.fDsrSensitivity = 1;
	serial_parameters.fRtsControl = RTS_CONTROL_HANDSHAKE;
	serial_parameters.fDtrControl = DTR_CONTROL_HANDSHAKE;
	
	if (GetCommState(port, &serial_parameters) == 0)
	{
		uint32_t error_code = GetLastError();
		DestroyInterface();
		return error_code;
	}
	serial_parameters.BaudRate = baudRate;
	serial_parameters.ByteSize = 8;
	serial_parameters.Parity = 0;
	serial_parameters.StopBits = 0;
	if (SetCommState(port, &serial_parameters) == 0)
	{
		uint32_t error_code = GetLastError();
		DestroyInterface();
		return error_code;
	}
	return 0;
}

uint32_t SetInterfaceTimeouts(uint32_t readIntervalTimeout)
{
	COMMTIMEOUTS serial_timeouts = { 0 };
	serial_timeouts.ReadIntervalTimeout = readIntervalTimeout;
	serial_timeouts.ReadTotalTimeoutConstant = 1;
	serial_timeouts.ReadTotalTimeoutMultiplier = 1;
	serial_timeouts.WriteTotalTimeoutConstant = 1;
	serial_timeouts.WriteTotalTimeoutMultiplier = 1;
	if (SetCommTimeouts(port, &serial_timeouts) == 0)
	{
		uint32_t error_code = GetLastError();
		DestroyInterface();
		return error_code;
	}
	return 0;
}

uint32_t DestroyInterface(void)
{
	if (!CloseHandle(port))
	{
		return GetLastError();
	}
	return 0;
}

uint32_t Write(uint8_t data[], uint32_t length)
{
	uint32_t bytes_written = 0;
	WriteFile(port, data, length, (LPDWORD)&bytes_written, NULL);
	FlushFileBuffers(port);
	return bytes_written;
}

uint32_t Read(uint8_t data[], uint32_t length)
{
	uint32_t bytes_read = 0;
	ReadFile(port, data, length, (LPDWORD)&bytes_read, NULL);
	return bytes_read;
}

#endif
