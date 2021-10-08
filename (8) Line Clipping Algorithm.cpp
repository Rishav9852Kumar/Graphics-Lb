#include <stdio.h>
#include<graphics.h>
#include<conio.h>

void step(char c[4], float x, float y){
     if(x<200)
          c[0] = '1';
     else
          c[0] = '0';
     if(x>350)
          c[1] = '1';
     else
          c[1] = '0';
     if(y<200)
          c[2] = '1';
     else
          c[2] = '0';
     if(y>350)
          c[3] = '1';
     else
          c[3] = '0';
}
void clip(char c[], char d[], float* px, float* py, float m,float xmin,float ymin,float xmax,float ymax){
     float x = *px, y = *py;
     bool flag = true;
     for(int i=0; i<4; i++){
          if(c[i] != '0' && d[i] != '0'){
               flag = false;
               break;
          }
          if(flag){
               if(c[0] != '0'){
                    y = m*(xmin-x)+y;
                    x=xmin;
               }
               else if(c[1] != '0'){
                    y = m*(xmax-x) + y;
                    x = xmax;
               }
               else if(c[2] != '0'){
                    x = ((ymin-y)/m)+x;
                    y = ymin;
               }
               else if(c[3] != '0'){
                    x = ((ymax-y)/m)+x;
                    y=ymax;
               }
          }
          if(!flag)
               printf("\nLine is  lying completely  outside.\n");
     }
     *px = x, *py = y;
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd, &gm," ");
    int xmin=150,ymin=250,ymax=450,xmax=350;
    printf("Hello Rishav Enter the border dimentions xmin,xmax,ymin,ymax :- ");
    scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
    printf("xmin=%d\nymin=%d\nxmax=%d\nymax=%d\n",xmin,ymin,xmax,ymax);
    rectangle(xmin,ymin,xmax,ymax);
    rectangle(xmin-10,ymin-10,xmax+10,ymax+10);
    setfillstyle(10,14);
    floodfill(xmin-5,ymin-5,WHITE);
     setfillstyle(9,9);
    floodfill(0,0,WHITE);
     _getch();
    // Now the line clipping part starts //
     float x1, y1, x2, y2;
     float m;
     char c1[4], c2[4];
     printf("Enter initial co-ordinates of line: ");
     scanf("%f%f",&x1,&y1);
     printf("Enter End co-ordinates of line: ");
     scanf("%f%f",&x2,&y2);
    printf("\nNow You can see the unclipped line in the figure right now :");
    line(x1,y1,x2,y2);
    printf("\nYour Initial cordinates of points are :- x1= %f y1 = %f\nx2= %f  y2= %f \n",x1,y1,x2,y2);
     _getch();
     cleardevice();
     rectangle(xmin,ymin,xmax,ymax);
    rectangle(xmin-10,ymin-10,xmax+10,ymax+10);
    setfillstyle(10,14);
    floodfill(xmin-5,ymin-5,WHITE);
     setfillstyle(9,9);
    floodfill(0,0,WHITE);
    printf("\nTo see the intersection points and clipped line press any key : - ");
    _getch();

    printf("\nNow You can see the clipped line in the figure right now :");
    step(c1, x1, y1);
    step(c2, x2, y2);
    m = float((y2-y1)/(x2-x1));
    float a,b,c,d;
    a=float(xmin);
    b=float(ymin);
    c=float(xmax);
    d=float(ymax);
    clip(c1,c2,&x1,&y1,m,a,b,c,d);
    clip(c2,c1,&x2,&y2,m,a,b,c,d);
    printf("\nYour new final x1= %f y1 = %f\nx2= %f  y2= %f \n",x1,y1,x2,y2);
    line(x1,y1,x2,y2);
     _getch();




    return 0;
}

