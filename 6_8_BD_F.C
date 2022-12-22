#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void flood_fill_8(int x, int y, int bd_color, int fl_color)
{
	if(getpixel(x, y)!=bd_color && getpixel(x, y)!=fl_color)
	{
		delay(5);
		putpixel(x, y, fl_color);
		flood_fill_8(x+1, y, bd_color, fl_color);
		flood_fill_8(x, y+1, bd_color, fl_color);
		flood_fill_8(x-1, y, bd_color, fl_color);
		flood_fill_8(x, y-1, bd_color, fl_color);
		flood_fill_8(x+1, y+1, bd_color, fl_color);
		flood_fill_8(x-1, y-1, bd_color, fl_color);
		flood_fill_8(x-1, y+1, bd_color, fl_color);
		flood_fill_8(x+1, y-1, bd_color, fl_color);
	}
}

void main()
{
	int gd=DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	circle(50,50, 25);
	//rectangle(50, 50, 100, 100);
	flood_fill_8(51, 51, WHITE, GREEN);

	getch();
	closegraph();
}