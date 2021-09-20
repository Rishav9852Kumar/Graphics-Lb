#include<stdio.h>//Mid point Circle drawing Algorithm //
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
void midpoint(int xc,int yc,int r)
{
    int x=0,y=r,f=1-r;
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
          {  x=x+1;
           if(f>=0)
                {
                f=f+2*x-2*y+1;
                y=y-1;
                }else
                {
                    f=f+2*x+1;
                    y=y;
                }

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
    midpoint(xc,yc,r);
    midpoint(xc,yc,r-1);
    midpoint(xc,yc,r-2);
    midpoint(xc,yc,r-3);
    midpoint(xc,yc,r-4);
    midpoint(xc,yc,r-5);
    printf("--Sorry but,To make the assignment more interesting i drew 5 circles (the outermost circle is the true one ) --------------------");
    printf("------------------------------------Thanks and have a nice day --------------------------------------");
    _getch();
 return 0;
}

