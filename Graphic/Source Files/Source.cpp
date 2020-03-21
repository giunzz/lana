#include<dos.h>
#include<iostream>
#include"graphics.h"
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(void)
{
	int midx, midy;
	initwindow(800, 600);
	srand(time(NULL));
	float x = 0, r = 100, x1 = 200, y1 = 100, set = 0;
	for (float i = 0; i < 1000; i = i + 0.003)
	{
		if (kbhit())
		{
			exit(0);
		}
		float b = +100 * cos(i * 10);
		int a1 = x1 + r + (b)*sin(i);
		int b1 = y1 + r + (b)*cos(i);
		int clr=0;
		set++;
		if (set == 4000)
		{
			set = 0;
			clr = rand() % 16;
		}
		putpixel(a1, b1 - 100, rand() % 15);
		putpixel(a1 - 200, b1 - 100, (clr + 1));
		putpixel(a1 + 200, b1 - 100, (clr + 2));

		putpixel(a1, b1 + 150, (clr + 5));
		putpixel(a1 - 200, b1 + 150, (clr - 1));
		putpixel(a1 + 200, b1 + 150, (clr - 2));
		x = x + 0.5;
		delay(1.5);
	}

}