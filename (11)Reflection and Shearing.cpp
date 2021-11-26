#include<stdio.h>//2 D transformation: Reflection and Shearing//
#include<graphics.h>
#include<conio.h>
#include<math.h>
int main(){
    int n,gm,gd=DETECT;
    printf("Please enter the no of vertices's in your polygon ");
    scanf("%d",&n);
    int x[n],y[n],nx[n],ny[n],c,sx,sy,xt,yt,r;
    float t;
    initgraph(&gd,&gm," ");
    line(10,250,550,250);//Xaxis
    line(70,450,70,50);//Yaxis
    printf("Printing Initial Polygon \n");
    printf("Make sure that the polygon lies in between (xmin=70, Ymax=250)\n");
    printf("Enter the X and Y coordinates of each vertex in your polygon:- \n");

    for(int i=0;i<n;i++)
    {
    scanf("%d %d",&x[i],&y[i]);
    if(i<n-1){
    printf("Enter the x and y of next vertex \n");
    }
    }
    setfillstyle(9,2);
    for(int i=0;i<n-1;i++)
    {setcolor(i+3);
    line(x[i],y[i],x[i+1],y[i+1]);
    }
    setcolor(8);
    line(x[n-1],y[n-1],x[0],y[0]);
    //floodfill(x[0]+2,y[0]+2,WHITE);
    int sh;

    printf("\n Press any key to see your polygon's reflection with respect to x axis ");
    _getch();
    for(int i=0;i<n-1;i++)  // Reflection With Respect to xaxis (t.e y=250)
    { setcolor(i+3);
    line(x[i],250+(250-y[i]),x[i+1],250+(250-y[i+1]));
    }
    setcolor(8);
    line(x[n-1],250+(250-y[n-1]),x[0],250+(250-y[0]));
    _getch();
    printf("\nEnter the distance by which you want to sheer with respect to x axis:-  ");
    scanf("%d",&sh);
    int m=0;//maximum y cordinate out of all input vertices.//
    for(int i=0;i<n;i++)
    {
        if(y[i]>m)
        {
            m=y[i]; //Here I will store the min value of y cordinate out of all vertices input y coordinates.
        }

    }
    for(int i=0;i<n;i++)
    {
        if(y[i]<m) //all those cordinates which are away from the base will only get sheered//
        {
            x[i]=x[i]+sh;//Shifting the xcordinates sh units to the right//
        }
    }
     for(int i=0;i<n-1;i++)  // Sheering with respect to x axis//
    {setcolor(i+3);
    line(x[i],y[i],x[i+1],y[i+1]);
    }
    setcolor(8);
    line(x[n-1],y[n-1],x[0],y[0]);
    _getch();
    return 0;

}
