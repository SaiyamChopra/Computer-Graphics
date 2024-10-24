//BRESENHAM
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int gdriver=DETECT,gmode,error,x0,y0,x1,y1,dx,dy,x,y,p;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
printf("ENTER X0,Y0,X1,Y1=");
scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
dx=x1-x0;
dy=y1-y0;
x=x0;
y=y0;
p=2*dy-dx;
while(x<=x1)
{
putpixel(x,y,YELLOW);
if(p>=0)
{
y=y+1;
x=x+1;
p=p+2*dy-2*dx;
}
else
{
p=p+2*dy;
x=x+1;
}
}
getch();
closegraph();
}