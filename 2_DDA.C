#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void dda_lda(int x0, int y0, int xn, int yn)
{
	float dx, dy, steps, xinc, yinc, nx, ny;
	int i;

	dx=xn-x0;
	dy=yn-y0;

	if(abs(dx)>=abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);

	xinc=dx/steps;
	yinc=dy/steps;

	for(nx=x0, ny=y0, i=0;i<=steps;nx+=xinc, ny+=yinc,i++) {
		//putpixel(nx, ny, RED);
		//delay(20);
		printf("dx=%f dy=%f step=%d x=%f y=%f\n", dx, dy, i, nx, ny);
	}
}

void main()
{
	int gd=DETECT, gm;
	int x0, y0, xn, yn;

	clrscr();

	initgraph(&gd, &gm, "C:\\TC\\BGI");

	do{
		printf("Enter the x & y coordinates of starting point:");
		scanf("%d %d", &x0, &y0);
		printf("Enter the x & y coordinates of ending point:");
		scanf("%d %d", &xn, &yn);
	}while(x0==xn && y0==yn);

	dda_lda(x0, y0, xn, yn);

	getch();
}