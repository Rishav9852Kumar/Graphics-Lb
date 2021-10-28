#include <iostream>//Implementation of Sutherland Hodgeman Polygon Clipping Algorithm
#include <conio.h>
#include <graphics.h>
#define round(a) ((int)(a+0.5))

using namespace std;
int k;
float xmin,ymin,xmax,ymax,arr[20],m;
void clipl(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1>= xmin && x2>=xmin)//wholly inside, exit point
    {
        arr[k]=x2;//exit point x cordinate//
        arr[k+1]=y2; //exit point y cordinate//
        k+=2;//one for x dimension value and one for y dimention value
    }
    if(x1<xmin && x2>=xmin)//Inward direction Intersection point //
        {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        arr[k+2]=x2;//Exit point x cordinate //
        arr[k+3]=y2;//exit point ycordinate//
        k+=4;
        }
    if(x1>=xmin && x2< xmin)//outward direction intersection point//
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        k+=2;
    }
}
void clipt(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=1000000;
    if(y1<=ymax && y2<=ymax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1>=ymax && y2<=ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1< ymax && y2>ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        k+=2;
    }
}
void clipr(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1<=xmax && x2<=xmax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1>xmax & x2<=xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1<=xmax && x2>xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        k+=2;
    }
}
void clipb(float x1, float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=1000000;
    if(y1>=ymin && y2>=ymin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1<ymin && y2>=ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1>=ymin && y2<ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        k+=2;
    }
}



int main()
{
    int gdriver=DETECT,gmode,n,poly[20],i;
    float xi,yi,xf,yf,polyy[20];
    cout<<"Rishav Enter the Coordinates of the xmin and ymin cordinate rectangular clip window "<<endl;
    cin>>xmin>>ymin;
    cout<<"\nRishav Enter the Coordinates of the xmax and ymax cordinate rectangular clip window "<<endl;
    cin>>xmax>>ymax;
    cout<<"\nRishav plese Enter the Number of sides of the Polygon to be clipped"<<endl;
    cin>>n;
    cout<<"Rishav Enter the x and y Coordinates of each vertex of your polygon  "<<endl;
    for(i=0;i<2*n;i++)
        cin>>polyy[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    for(int i=0;i<2*n+2;i++)
        poly[i]=round(polyy[i]);
    initgraph(&gdriver,&gmode,"");
    setcolor(RED);
    rectangle(xmin-1,ymax+1,xmax+1,ymin-1);
    rectangle(xmin-2,ymax+2,xmax+2,ymin-2);
    rectangle(xmin-3,ymax+3,xmax+3,ymin-3);
    rectangle(xmin-4,ymax+4,xmax+4,ymin-4);
    cout<<"\n You could see your Unclipped Polygon Rishav! \n";
    setcolor(WHITE);
    fillpoly(n,poly);
    _getch();
    cleardevice();
    k=0;
    for(i=0;i<2*n;i+=2)
       clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    cout<<"ok "<<endl;
   // k=n/2;
    for(i=0;i<k;i++)
        polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0;i<2*n;i+=2)
       clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
     cout<<"ok "<<endl;
    //k=n/2;
    for(i=0;i<k;i++)
        polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0;i<2*n;i+=2)
        clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    //k=n/2;
     cout<<"ok "<<endl;
    n=k/2;
    for(i=0;i<k;i++)
        polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0;i<2*n;i+=2)
        clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    cout<<"ok "<<endl;
    _getch();
    for(i=0;i<k;i++)
        poly[i]=round(arr[i]);
    _getch();
    if(k)
        fillpoly(k/2,poly);
    setcolor(RED);
    rectangle(xmin,ymax,xmax,ymin);
    rectangle(xmin-2,ymax+2,xmax+2,ymin-2);
    rectangle(xmin-3,ymax+3,xmax+3,ymin-3);
    rectangle(xmin-4,ymax+4,xmax+4,ymin-4);
    cout<<"\nYou could see your clipped Polygon Rishav! \n";
    _getch();
    closegraph();
    return 0;
}
