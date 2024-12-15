#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void draw_circle(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, RED);
	putpixel(xc+y, yc+x, RED);
	putpixel(xc-y, yc+x, GREEN);
	putpixel(xc-x, yc+y, GREEN);
	putpixel(xc-x, yc-y, BLUE);
	putpixel(xc-y, yc-x, BLUE);
	putpixel(xc+y, yc-x, WHITE);
	putpixel(xc+x, yc-y, WHITE);
}

void bresenhams_circle(int x_cent, int y_cent, int rad)
{
	int dp, nx, ny;

	nx=0;
	ny=rad;
	dp=3-2*rad;

	while(nx<=ny)
	{
		draw_circle(x_cent, y_cent, nx, ny);
		if(dp<0)
		{
			dp=dp+(4*nx)+6;
		}
		else
		{
			dp=dp+4*(nx-ny)+10;
			ny--;
		}
		nx++;
		delay(40);
	}
}

void main()
{
	int x, y, r;
	int gm, gd=DETECT;
	clrscr();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	printf("\nEnter the x and y coordinates of the center of the circle:");
	scanf("%d %d", &x, &y);

	printf("Enter the radius of the circle:");
	scanf("%d", &r);

	bresenhams_circle(x, y, r);

	getch();
	//closegraph();
}
