#include<stdio.h>//Mid point Ellipse drawing Algorithm //
#include<conio.h>
#include<graphics.h>
#include<math.h>

void fourrepeats(int xc,int yc,int x,int y)
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
void midpoint(int xc,int yc,int a,int b)
{
    int x=0,y=b,p=b*b-a*a*b+a*a*4,fx=0,fy=2*a*a*b;
    line(xc,yc,xc+a,yc);
    line(xc,yc,xc,yc+b);
    line(xc,yc,xc-a,yc);
    line(xc,yc,xc,yc-b);


    while(fx<fy)
    {
         fourrepeats(xc,yc,x,y);
        x++;
        fx=fx+2*b*b;
        if(p<0){
            p=p+fx+b*b;
        }else{
            y--;
            fy=fy-2*a*a;
            p=p+fx+b*b-fy;
        }

        fourrepeats(xc,yc,x,y);
    }

    p=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*b*b;
    while(y>0){
        y--;
        fy=fy-2*a*a;
        if(p>=0)
        {
            p=p+fy+a*a;
        }else{
            x++;
            fx=fx+2*b*b;
            p=p+fx-fy+a*a;
        }

        fourrepeats(xc,yc,x,y);
    }
}
int main()
{
    int xc,yc,a,b,gdriver=DETECT,gmode;
    initgraph(&gdriver, &gmode, (char *)" ");
    printf("Please >>>> Rishav <<<<< Enter the x and Y coordinates of center and length of major and minor axis of your Desired Ellipse :- ");
    scanf("%d %d %d %d",&xc,&yc,&a,&b);
    midpoint(xc,yc,a,b);
    midpoint(xc,yc,a-1,b-1);
    midpoint(xc,yc,a-2,b-2);
    midpoint(xc,yc,a-3,b-3);
    midpoint(xc,yc,a-4,b-4);
    midpoint(xc,yc,a-5,b-5);
    printf(" To make the assignment more interesting i drew 5 Ellipse (the outermost Ellipse is the true one ) ");
    printf("------------------------------------Thanks and have a nice day --------------------------------------");
    _getch();
 return 0;
}

