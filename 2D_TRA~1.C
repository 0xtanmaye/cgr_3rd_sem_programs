#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

float *xa_ptr;
float *ya_ptr;
int no_v=0;

void drawlines()
{
	int i=0, j=0;
	for(i=0;i<no_v-1;i=j)
	{
		j=i+1;
		line(xa_ptr[i], ya_ptr[i], xa_ptr[j], ya_ptr[j]);
	}
	line(xa_ptr[j], ya_ptr[j], xa_ptr[0], ya_ptr[0]);
}

void translate(int tx, int ty)
{
	int i;
	for(i=0;i<no_v;i++)
	{
		xa_ptr[i]=xa_ptr[i]+tx;
		ya_ptr[i]=xa_ptr[i]+ty;
	}
}

void scale(int sx, int sy)
{
	int i;
	for(i=0;i<no_v;i++)
	{
		xa_ptr[i]=xa_ptr[i]*sx;
		ya_ptr[i]=ya_ptr[i]*sy;
	}
}

int main()
{
	int gd=DETECT, gm, i, choice;
	float tx, ty, sx, sy;
	clrscr();
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	printf("Enter the number of vertices:");
	scanf("%d", &no_v);
	xa_ptr=(float *)calloc(no_v, sizeof(float));
	ya_ptr=(float *)calloc(no_v, sizeof(float));

	for(i=0;i<no_v;i++)
	{
		printf("Enter the x & y coordinates of vertex %d:", i+1);
		scanf("%f %f", &xa_ptr[i], &ya_ptr[i]);
	}

	drawlines();

	do
	{
		fflush(stdin);
		printf("\nEnter the transformation operation you want to perform(1-translation, 2-scaling, 3-rotation):");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the translation factor for x:");
				scanf("%d", &tx);
				printf("\nEnter the translation factor for y:");
				scanf("%d", &ty);
				translate(tx, ty);
				drawlines();
				break;
			case 2:
				printf("\nEnter the scaling factor for x:");
				scanf("%d", &sx);
				printf("\nEnter the scaling factor for y:");
				scanf("%d", &sy);
				scale(sx, sy);
				drawlines();
				break;
			
			default:
				printf("\nEnter a valid choice(1-translation, 2-scaling, 3-rotation)\n");
		}
	}while(choice!=4);
	
	return 0;
}
