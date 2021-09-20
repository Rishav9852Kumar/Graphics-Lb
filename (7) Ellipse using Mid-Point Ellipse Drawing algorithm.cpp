#include<stdio.h>//Mid point Ellipse drawing Algorithm //
#include<conio.h>
#include<graphics.h>
#include<math.h>

void fourrepeats(int xc,int yc,int x,int y)
{
    putpixel(xc+x,yc+y,1);
    putpixel(xc-x,yc-y,2);
    putpixel(xc+x,yc-y,3);
    putpixel(xc-x,yc+y,4);
}
void midpoint(int xc,int yc,int a,int b)
{
    int x=0,y=b,p;
    int fx=2*b*b*x,fy=2*a*a*y;
    line(xc,yc,xc+a,yc);
    line(xc,yc,xc,yc+b);
    line(xc,yc,xc-a,yc);
    line(xc,yc,xc,yc-b);

    p=b*b-(a*a*b)+((a*a)*0.25);//Initial Decision Parameter//
    while(fx<fy) //This part working correctly //
    {
         fourrepeats(xc,yc,x,y);


        if(p<0){
            p=p+fx+b*b;
        }else{
            y--;
            p=p+fx+(b*b)-fy;
            fy=fy-(2*a*a);

        }
         x++;
         fx=fx+(2*b*b);
    }

     float temp1 =(x+0.5)*(x+0.5);
     float temp2=(y-1)*(y-1);
     float b2=b*b;
     float a2=a*a;


     p=b2*temp1+a2*temp2-(a2*b2);// Second Initial Parameter//

   while(fy>0){
        fourrepeats(xc,yc,x,y);


        if(p>=0)
        {
            p=p-fy+a*a;
        }else{
            x++;
            p=p+fx-fy+(a*a);
            fx=fx+(2*b*b);
        }
        printf("x = %d  \ty = %d\n",x,y);

        y--;
        fy=fy-(2*a*a);
    }
}
int main()
{
    int xc,yc,a,b,gdriver=DETECT,gmode;
    initgraph(&gdriver, &gmode, (char *)" ");
    printf("Please >>>> Rishav <<<<< Enter the x and Y coordinates of center and length of major and minor axis of your Desired Ellipse :- ");
    scanf("%d %d %d %d",&xc,&yc,&a,&b);
    midpoint(xc,yc,a,b);
     printf("------------------------------------The next ellipse  --------------------------------------\n");
    midpoint(xc,yc,a-1,b-1);
     printf("------------------------------------The next ellipse  --------------------------------------\n");
    midpoint(xc,yc,a-2,b-2);
     printf("------------------------------------The next ellipse  --------------------------------------\n");
    midpoint(xc,yc,a-3,b-3);
     printf("------------------------------------The next ellipse  --------------------------------------\n");
    midpoint(xc,yc,a-4,b-4);
     printf("------------------------------------The next ellipse  --------------------------------------\n");
    midpoint(xc,yc,a-5,b-5);
     printf("------------------------------------     End   --------------------------------------\n");
    printf(" To make the assignment more interesting i drew 5 Ellipse (the outermost Ellipse is the true one ) ");
    printf("------------------------------------Thanks and have a nice day --------------------------------------");
    _getch();
 return 0;
}
