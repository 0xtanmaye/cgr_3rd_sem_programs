#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	putpixel(50,50,RED);
	outtextxy(30,55,"PIXEL");
	line(100,70,200,100);
	outtextxy(130,105,"LINE");
	circle(250,60,50);
	outtextxy(230,115,"CIRCLE");
	rectangle(310,40,400,100);
	outtextxy(320,110,"RECTANGLE");
	ellipse(520,125,0,360,100,120);
	outtextxy(490,250,"ELLIPSE");
	getch();
}