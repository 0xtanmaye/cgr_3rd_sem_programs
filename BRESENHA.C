#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void bresenhams_lda(int x0, int y0, int xn, int yn)
{
	int dx, dy, pk, npk, nx, ny;

	dx=abs(xn-x0);
	dy=abs(yn-y0);
	pk=(2*dy)-(2*dx);
	npk=pk;
	nx=x0;
	ny=y0;

	while(nx!=xn && ny!=yn)
	{
		if(npk>=0)
		{
			npk=npk+(2*dy)-(2*dx);
			if(nx>xn)
				nx--;
			else
				nx++;

			if(ny>yn)
				ny--;
			else
				ny++;
		}
		else
		{
			npk=npk+(2*dy);
			if(nx>xn)
				nx--;
			else
				nx++;
		}
		delay(20);
		putpixel(n	x, ny, RED);
	}
}

void main()
{
	int x0, y0, xn, yn, gd=DETECT, gm;
	clrscr();

	initgraph(&gd, &gm, "C:\\TC\\BGI");

	printf("\nEnter the x & y coordinates of starting point:");
	scanf("%d %d", &x0, &y0);
	printf("\nEnter the x & y coordinates of ending point:");
	scanf("%d %d", &xn, &yn);

	bresenhams_lda(x0, y0, xn, yn);

	getch();
}



