#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main() {
  int gd=DETECT, gm;
  initgraph(&gd, &gm, (char *)" ");

  circle(250,200,100);//circle(x,y,radius)//
  circle(250,200,102);//circle(x,y,radius)//
  circle(250,200,114);//circle(x,y,radius)//
  circle(250,200,116);//circle(x,y,radius)//
  circle(250,200,118);//circle(x,y,radius)//
  circle(220,180,2);//circle(x,y,radius)//
  circle(280,180,2);//circle(x,y,radius)//
  circle(250,240,15);//circle(x,y,radius)//
  circle(250,240,14);//circle(x,y,radius)//
  circle(250,240,12);//circle(x,y,radius)//
  circle(250,240,10);//circle(x,y,radius)//
  circle(250,240,8);//circle(x,y,radius)//
  circle(250,240,6);//circle(x,y,radius)//
  circle(250,240,4);//circle(x,y,radius)//
  circle(250,240,2);//circle(x,y,radius)//
  ellipse(220, 170, 10, 180, 20, 7);//ellipse(x,y,a1,a2,Rx,Ry)//
  ellipse(280, 170, 0, 180, 20, 7);//ellipse(x,y(centre),a1,a2(starting and ending angles),Rx,Ry(radius in x and y axis))//
  ellipse(220, 180, 10, 360, 20, 7);//ellipse(x,y,a1,a2,Rx,Ry)//
  ellipse(280, 180, 0, 360, 20, 7);//ellipse(x,y,a1,a2,Rx,Ry)//
  line(250,200,250,220);//line(x1,y1,x2,y2)//
  line(220,240,280,240);
  rectangle(120,70,120+260,70+260);//rectangale(x1,y1,x2,y2)//
  bar(100,50,110,90+260);//bar(x1,y1,x2,y2)//
  bar(130+260,50,140+260,90+260);//bar(x1,y1,x2,y2)//
  bar(110,50,130+260,60);//bar(x1,y1,x2,y2)//
  bar(110,80+260,130+260,90+260);//bar(x1,y1,x2,y2)//
  rectangle(90,40,150+260,100+260);//rectangale(x1,y1,x2,y2)//
  rectangle(80,30,160+260,110+260);//rectangale(x1,y1,x2,y2)//
  rectangle(80,370,160+260,370+40);//rectangale(x1,y1,x2,y2)//

  _getch();
  return 0;
}
