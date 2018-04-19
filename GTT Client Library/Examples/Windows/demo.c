#include "serial_gtt.h"
#include "GTTProject17.h"
#include <stdio.h>
#include <Windows.h>

int CurrentScreen = 0;

void MyButtonClick(gtt_device* device, uint16_t ObjectID, uint8_t State)
{
	if (State == 1)
	{
		if (ObjectID == id_screen1_button_a)
		{
			printf("Writing Hello World\n");
			gtt_set_screen1_main_label_text(device, gtt_make_text_ascii("Hello World!"));
		}
		if (ObjectID == id_screen1_button_b)
		{
			printf("Writing testing\n");
			gtt_set_screen1_main_label_text(device, gtt_make_text_ascii("Testing 123!"));
		}
		if (ObjectID == id_screen1_btn_screen2)
		{
			printf("Screen change 1\n");
			CurrentScreen = 1;
		}
		if (ObjectID == id_screen2_btn_screen1)
		{
			printf("Screen change 0\n");
			CurrentScreen = 0;
		}
	}
}

int main(int argc, char** argv)
{
	gtt_device *gtt = serial_gtt_open("\\\\.\\COM5", 19200,512,512);
	if (!gtt)
	{
		printf("No gtt detected\n");
		return 1;
	}
	gtt_set_button_clickhandler(gtt, MyButtonClick);
	char buffer[128];
	int counter = 1;
	uint64_t ticks = GetTickCount64();
	while (1)
	{
		if (GetTickCount64() - ticks > 500)
		{
			sprintf(buffer, "Mainloop : %d\n", counter++);

			if (CurrentScreen == 0)
				gtt_set_screen1_main_label_text(gtt, gtt_make_text_ascii(buffer));
			else
				gtt_set_screen2_main_label_text(gtt, gtt_make_text_ascii(buffer));

			ticks = GetTickCount64();
		}
		gtt_parser_process(gtt);
	}
	return 0;
}

