#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void bresenhams_lda(int x0, int y0, int xn, int yn)
{
	int dx, dy, pk, npk, nx, ny, i;

	dx=abs(xn-x0);
	dy=abs(yn-y0);
	pk=(2*dy)-dx;

	npk=pk;
	nx=x0;
	ny=y0;

	for(i=0;i<=dx;i++)
	{
		//delay(20);
		//putpixel(nx, ny, WHITE);
		printf("dx=%d dy=%d 2dx=%d 2dy=%d x=%d y=%d\n", dx, dy, 2*dx, 2*dy, nx, ny);
		if(npk>=0)
		{
			npk=npk+(2*dy)-(2*dx);
			nx>xn?nx--:nx++;
			ny>yn?ny--:ny++;
		}
		else
		{
			npk=npk+(2*dy);
			nx>xn?nx--:nx++;
		}
	}
}

void main()
{
	int x0, y0, xn, yn, gd=DETECT, gm;
	clrscr();

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	printf("\nEnter the x & y coordinates of starting point:");
	scanf("%d %d", &x0, &y0);
	printf("\nEnter the x & y coordinates of ending point:");
	scanf("%d %d", &xn, &yn);

	bresenhams_lda(x0, y0, xn, yn);

	getch();
}



