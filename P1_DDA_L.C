#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void dda_lda_1(float x0, float y0, float xn, float yn)
{
	int dx, dy, steps, i;
	float xinc, yinc, nx, ny;

	dx=xn-x0;
	dy=yn-y0;

	if(dx>=dy)
		steps=abs(dx);
	else
		steps=abs(dy);

	xinc=(float)dx/steps;
	yinc=(float)dy/steps;

	//printf("steps=%d, dx=%d, dy=%d\n", steps, dx, dy);
	for(nx=x0, ny=y0, i=0;i<steps;nx=nx+xinc, ny=ny+yinc, i++)
	{	putpixel(nx, ny, RED);
		//printf("x%d=%f and y%d=%f\n", i+1, nx, i+1, ny);
	}
}

/* void dda_lda_2(float x0, float y0, float xn, float yn)
{
	int dx, dy, steps;

	dx=xn-x0;
	dy=yn-y0;

	if(abs(dx)>=abs(dy))
		steps=dx;
	else
		steps=dy;

}
*/
void main()
{
	float x0, y0, xn, yn;
	int gd=DETECT, gm;

	clrscr();
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	printf("\nEnter the x & y co-ordinates of the starting point:");
	scanf("%f %f", &x0, &y0);
	printf("\nEnter the x & y co-ordinates of the ending point:");
	scanf("%f %f", &xn, &yn);

	dda_lda_1(x0, y0, xn, yn);

	getch();
}
