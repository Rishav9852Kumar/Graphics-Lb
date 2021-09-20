#include <stdio.h>
#include<graphics.h>
#include<conio.h>

int main()
{
 int gd=DETECT,gm,n;
 float x,y,dx,dy,steps;
 int x0,x1,y1,y0;
 initgraph(&gd,&gm,(char*) " ");

 setbkcolor(WHITE);
printf("\t\t\t\tTo Draw your line using DAA algorithm \n\t\t\t\t\t(by- Rishav Kumar 2019UGCS058R)\n\n");
printf("Enter the coordinates of starting point ");
scanf("%d%d",&x0,&y0);
printf("Enter the coordinates of ending point ");
scanf("%d%d",&x1,&y1);
 dx=float(x1-x0);
 dy=float(y1-y0);

 if(dx>dy)
 {
     steps=dx;
 }else
 {
     steps=dy;
 }
 dx=dx/steps;
 dy=dy/steps;
 x=x0+0.5;
 y=y0+0.5;
 n=1;
 while(n<=steps)
 {
     putpixel(x,y,YELLOW);
     x=x+dx;
     y=y+dy;
     n=n+1;
     printf("X = %f Y = %f\n",x,y);
 }
 getch();
 return 0;
}

