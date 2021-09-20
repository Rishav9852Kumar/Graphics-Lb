#include<stdio.h>//Bresenhhams Circle drawing Algorithm //
#include<conio.h>
#include<graphics.h>
#include<math.h>

void eightrepeats(int xc,int yc,int x,int y)
{
    putpixel(x+xc,y+yc,1);
    putpixel(x+xc,-y+yc,2);
    putpixel(-x+xc,-y+yc,3);
    putpixel(-x+xc,y+yc,4);
    putpixel(y+xc,x+yc,5);
    putpixel(y+xc,-x+yc,6);
    putpixel(-y+xc,-x+yc,7);
    putpixel(-y+xc,x+yc,8);
}
void Brhcircle(int xc,int yc,int r)
{
    int x=0,y=r,d=3-(2*r);
    line(xc,yc,xc+r,yc);
    line(xc,yc,xc,yc+r);
    line(xc,yc,xc-r,yc);
    line(xc,yc,xc,yc-r);
    line(xc,yc,xc+r/sqrt(2),yc+r/sqrt(2));
    line(xc,yc,xc+r/sqrt(2),yc-r/sqrt(2));
    line(xc,yc,xc-r/sqrt(2),yc+r/sqrt(2));
    line(xc,yc,xc-r/sqrt(2),yc-r/sqrt(2));
    eightrepeats(xc,yc,x,y);
    while(x<=y)
          {
           if(d<=0)
                {
                    d=d+(4*x)+6;
                }else
                {
                    d=d+(4*x)-(4*y)+10;
                    y=y-1;
                }
             x=x+1;
            eightrepeats(xc,yc,x,y);
            printf("your x = %d, y = %d\n",x, y);
          }
}
int main()
{
    int xc,yc,r,gdriver=DETECT,gmode;
    initgraph(&gdriver, &gmode, (char *)" ");
    printf("Please >>>> Rishav <<<<< Enter the x and Y coordinates of center and Radius of your Desired Circle :- ");
    scanf("%d %d %d",&xc,&yc,&r);
    Brhcircle(xc,yc,r);
    Brhcircle(xc,yc,r-1);
    Brhcircle(xc,yc,r-2);
    Brhcircle(xc,yc,r-3);
    Brhcircle(xc,yc,r-4);
    Brhcircle(xc,yc,r-5);
    printf("--To make the assignment more interesting i drew 5 circles (the outermost circle is the true one ) --------------------");
    printf("------------------------------------Thanks and have a nice day --------------------------------------");
    _getch();
 return 0;
}
