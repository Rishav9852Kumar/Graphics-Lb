#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main() {
  int gd=DETECT, gm,color;
  initgraph(&gd, &gm, (char *)" ");

rectangle(80,200,230,400);//main face wall//
setfillstyle(10,14);
 floodfill(80+56,301,WHITE);

rectangle(232,200,450,400);//side wall//
 setfillstyle(9,2);
 floodfill(235,201,WHITE);

rectangle(80,400,450,440);//Ground
setfillstyle(SOLID_FILL,RED);
 floodfill(84,410,WHITE);

rectangle(80+55,300,80+95,400);//gate
setfillstyle(1,11);
 floodfill(80+56,301,WHITE);

 rectangle(80+50,295,80+100,400);//gate outline//
setfillstyle(DASHED_LINE,11);
 floodfill(80+54,299,WHITE);

circle(80+75,150,10);
circle(80+75,150,8);
setfillstyle(8,9);
 floodfill(80+75,150,WHITE);

 setfillstyle(9,10);
 floodfill(170,301,WHITE);

 setfillstyle(8,9);
 floodfill(80+56,301,WHITE);

ellipse(110,250,0,180,20,30);
ellipse(110,250,0,180,15,25);
line(95,250,125,250);
setfillstyle(8,9);
 floodfill(110,249,WHITE);

ellipse(110+90,250,0,180,20,30);
ellipse(110+90,250,0,180,15,25);
line(95+90,250,125+90,250);
setfillstyle(8,9);
 floodfill(200,249,WHITE);

line(80,200,155,110);//1
line(155,110,230,200);//2
line(155,110,232,200);//2
line(155,110,401,110);//3
line(400,110,450,200);//4
//line(400,110,360,200);//5
line(360,200,360,400);
line(450,80,450,400);//6
line(430,80,430,165);//7


ellipse(440,80,0,360,11,6);
setfillstyle(SOLID_FILL,YELLOW);
 floodfill(440,80,WHITE);

setfillstyle(9,14);//ceiling
 floodfill(160,115,WHITE);
  _getch();
  return 0;
}
