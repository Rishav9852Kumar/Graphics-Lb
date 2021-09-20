#include <stdio.h>//Line Drawing using BRESENHAM'S Algorithm //Rishav Kumar 2019UGCS058R//
#include <conio.h>
#include<graphics.h>

void drawline(int x0,int y0,int x1,int y1)
{   int p,x,y,dx,dy;
    dx=x1-x0;
    dy=y1-y0;
    x=x0;
    y=y0;
    p=2*dy-dx;
    while(x<x1)
    {   if(p>=0)
        {   putpixel(x,y,YELLOW);
            x=x+1;
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {  putpixel(x,y,YELLOW);
            x=x+1;
            p=p*+2*dy;
        }
        printf("x = %d, y=%d\n",x,y);
    }}
int main(){
int gdriver=DETECT,gmode,error,x0,y0,x1,y1;
initgraph(&gdriver,&gmode," ");
printf("\t\t\t\tTo Draw your line using BRESENHAM'S LINE algorithm \n\t\t\t\t\t(by- Rishav Kumar 2019UGCS058R)\n\n");
printf("Enter the coordinates of starting point ");
scanf("%d%d",&x0,&y0);
printf("Enter the coordinates of ending point ");
scanf("%d%d",&x1,&y1);
drawline(x0,y0,x1,y1);
getch();
return 0;





}


