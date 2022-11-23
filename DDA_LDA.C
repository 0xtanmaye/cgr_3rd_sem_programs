#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void dda_lda(float, float, float, float);

void main()
{
	int gd=DETECT, gm;
	float x0, y0, xn, yn;

	clrscr();

	initgraph(&gd, &gm, "C:\\TC\\BGI");

	do{
		printf("Enter the x & y coordinates of starting point:");
		scanf("%f %f", &x0, &y0);
		printf("Enter the x & y coordinates of ending point:");
		scanf("%f %f", &xn, &yn);
	}while(x0==xn && y0==yn);

	dda_lda(x0, y0, xn, yn);

	getch();
}

void dda_lda(float x0, float y0, float xn, float yn)
{
	float dx, dy, steps, xinc, yinc, nx, ny;
	int i;

	dx=abs(xn-x0);
	dy=abs(yn-y0);

	if(dx>=dy)
		steps=dx;
	else
		steps=dy;

	xinc=dx/steps;
	yinc=dy/steps;

	for(nx=x0, ny=y0, i=0;i<steps;nx+=xinc, ny+=yinc,i++) {
		putpixel(nx, ny, RED);
		delay(20);
	}
}