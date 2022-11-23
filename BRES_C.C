#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void draw_circle(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, RED);    //q1
	putpixel(xc+y, yc+x, RED);    //q2
	putpixel(xc-y, yc+x, GREEN);    //q3
	putpixel(xc-x, yc+y, GREEN);    //q4
	putpixel(xc-x, yc-y, BLUE);    //q5
	putpixel(xc-y, yc-x, BLUE);    //q6
	putpixel(xc+y, yc-x, WHITE);    //q7
	putpixel(xc+x, yc-y, WHITE);    //q8
}

void bresenhams_circle(int x_cent, int y_cent, int rad)
{
	int dp, nx, ny;

	nx=0;
	ny=rad;
	dp=3-2*rad;

	draw_circle(x_cent, y_cent, nx, ny);

	while(nx<=ny)
	{
		nx++;

		if(dp<0)
			dp=dp+(4*nx)+6;
		else
		{
			ny--;
			dp=dp+4*(nx-ny)+10;
		}

		draw_circle(x_cent, y_cent, nx, ny);
		delay(40);
	}
}

void main()
{
	int x, y, r;
	int gm, gd=DETECT;
	clrscr();
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	printf("\nEnter the x and y coordinates of the center of the circle:");
	scanf("%d %d", &x, &y);

	printf("Enter the radius of the circle:");
	scanf("%d", &r);

	bresenhams_circle(x, y, r);

	getch();
	//closegraph();
}