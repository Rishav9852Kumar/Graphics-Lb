#include <stdio.h>//Line Drawing using BRESENHAM'S Algorithm //Rishav Kumar 2019UGCS058R//
#include <conio.h>
#include<graphics.h>

int main(){
int gd=DETECT,gm,n,i,j,k,dy,dx,x,y,temp;
int a[20][2],xi[20];
float m[20];
printf("Enter the no of vertices in your polygon :- ");
scanf("%d",&n);
printf("Now enter the cordinates of each polygons (t.e it's x cordinate and y ordinate :-  )");
for(i=0;i<n;i++)
{
 scanf("%d%d",&a[i][0],&a[i][1]);
 }
 a[n][0]=a[0][0];
 a[n][1]=a[0][1];
 detectgraph(&gd,&gm);
initgraph(&gd,&gm," ");
for(i=0;i<n;i++)
{
line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
}

for(i=0;i<n;i++)
{
dy=a[i+1][1]-a[i][1];
dx=a[i+1][0]-a[i][0];
if(dy==0)
 m[i]=1.0;
if(dx==0)
 m[i]=0.0;
if((dy!=0)&&(dx!=0))
{
    m[i]=(float) dy/dx;
}
}
for(y=0;y<480;y++)
{
k=0;
for(i=0;i<n;i++)
{
    if(((a[i][1]<=y)&&(a[i+1][1]>y))||((a[i][1]>y)&&(a[i+1][1]<=y)))
    {
        xi[k]=(int)(a[i][0]+m[i]*(y-a[i][1]));
        k++;
    }
}
for(j=0;j<k-1;j++)
for(i=0;i<k-1;i++)
{
    if(xi[i]>xi[i+1])
    {
        temp=xi[i];
        xi[i]=xi[i+1];
        xi[i+1]=temp;
    }
}
setcolor(5);
for(i=0;i<k;i+2)
{
    line(xi[i],y,xi[i+1]+1,y);

}
}

return 0;
}
