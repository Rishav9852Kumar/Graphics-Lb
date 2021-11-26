#include <stdio.h>//Polygon filling Algorithm using Flood Fill Algorithm//Rishav Kumar 2019UGCS058R//
#include<conio.h>
#include<graphics.h>
void flood(int x,int y,int fillColor, int defaultColor) // Funtion That actually does the colouring//
{
    if(getpixel(x,y)==defaultColor)//Checks if the current chosen pixel colour is same as default colour [t.e Black (Inside part of polygon )]//
        // Provided by the user or not ,   //
    {
        delay(0);
        putpixel(x,y,fillColor);//If both colour are same then the current pixel is colored with the choose n color of user//
        flood(x+1,y,fillColor,defaultColor);//And same operations are done on the pixels on right left ,//
        flood(x-1,y,fillColor,defaultColor);//top and bottom of current pixel is done.//
        flood(x,y+1,fillColor,defaultColor);
        flood(x,y-1,fillColor,defaultColor);

    }
}
int main()
{
    int gd=DETECT,gm;
    int a,b,c,d,f;    //Declaration of all Variables to be used //
    initgraph(&gd,&gm,"");
    printf("Enter the cordinates of your rectangle scree to be filled \n");
    scanf("%d %d %d %d",&a,&b,&c,&d);// Taking the xmin,ymin,xmax,ymax of the rectagular boundary from user//
    rectangle(a,b,c,d);// Drawing Four rectangle with distance of 1 bit apart to make the combined polygon look bright //
    rectangle(a-1,b-1,c+1,d+1);//or to increse the breadth//
    rectangle(a-2,b-2,c+2,d+2);
    printf("enter the colour of your choice to be filled with \n");
    scanf("%d",&f);//Take the colour from user with witch he wants to fill the polygon//
    cleardevice();
    rectangle(a,b,c,d);
    rectangle(a-1,b-1,c+1,d+1);
    rectangle(a-2,b-2,c+2,d+2);
    _getch();
    int x=0;
    while(f>0){ //Here I am using a loop to colour the polygon multiple times with diffrent colours//
    flood(a+1,b+1,f,x);
    x=f;          //Starting with the user colour i coulred the polygon then //
    f--;          //I again run the loop until the colour dight reaches 1 (black)//
    _getch();
    }

    return 0;
}

