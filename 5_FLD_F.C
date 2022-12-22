#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void flood_fill(int x, int y, int defaultcolor, int fillcolor)
{
	if(getpixel(x, y)==defaultcolor)
	{
		delay(10);
		putpixel(x, y, fillcolor);
		flood_fill(x+1, y, defaultcolor, YELLOW);
		flood_fill(x-1, y, defaultcolor, GREEN);
		flood_fill(x, y+1, defaultcolor, RED);
		flood_fill(x, y-1, defaultcolor, WHITE);
	}
}

void main()
{
	int gd=DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	rectangle(50, 50, 100, 100);
	flood_fill(51, 51, 0, BLUE);

	getch();
}