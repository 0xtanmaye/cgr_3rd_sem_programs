#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void boundary_fill(int x, int y, int bd_color, int fillcolor)
{
	if(getpixel(x, y)!=bd_color && getpixel(x, y)!=fillcolor)
	{
		delay(10);
		putpixel(x, y, fillcolor);
		boundary_fill(x+1, y, bd_color, fillcolor);
		boundary_fill(x-1, y, bd_color, fillcolor);
		boundary_fill(x, y+1, bd_color, fillcolor);
		boundary_fill(x, y-1, bd_color, fillcolor);
	}
}

void main()
{
	int gd=DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	rectangle(50, 50, 100, 100);
	boundary_fill(51, 51, WHITE, BLUE);

	getch();
}
