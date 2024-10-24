// 2D TRANSFORMATION
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
 int gd=DETECT;
 int gm,i,opt;
 float dx,dy,theta;
 int poly[]={320,150,420,300,250,300,320,150};
 int poly1[]={320,150,420,300,250,300,320,150};
 clrscr();
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 printf("\nORIGINAL IMAGE IS:");
 drawpoly(4,poly);
 do
 {
  printf("\n 1.TRANSLATION \n 2.SCALING \n 3.ROTATION \n 4.QUIT");
  printf("\nENTER YOUR OPTION:");
  scanf("%d",&opt);
  switch(opt)
  {
  case 1:
	  drawpoly(4,poly1);
	  printf("\nENTER TRANSLATING FACTOR IN THE FORM (x,y)");
	  scanf("%f%f",&dx,&dy);
	  printf("\nTRANSLATION:");
	  for(i=0;i<=7;i++)
	  {
	    if(i%2==0)
	      poly[i]=poly[i]+dx;
	    else
	      poly[i]=poly[i]+dy;
	  }
	  setcolor(RED);
	  drawpoly(4,poly);
	  break;

  case 2: setcolor(WHITE);
	  drawpoly(4,poly1);
	  setcolor(GREEN);
	  printf("\nENTER SCALING FACTOR IN THE FORM (x,y)");
	  scanf("%f%f",&dx,&dy);
	  cleardevice();
	  printf("\nSCALING:");
	  for(i=0;i<=7;i++)
	  {
	    if(i%2==0)
	     poly[i]=poly[i]*dx;
	    else
	     poly[i]=poly[i]*dy;
	   }
	   drawpoly(4,poly);
	   break;
  case 3:  setcolor(WHITE);
	   drawpoly(4,poly1);

	   printf("\nENTER THE ROTATING FACTOR ");
	   scanf("%f",&theta);
	   printf("\nROTATION:");
	   for(i=0;i<=7;i++)
	   {
	    if(i%2==0)
	     poly[i]=poly[i]*cos(theta)-poly[i+1]*sin(theta);
	    else
	     poly[i]=poly[i-1]*sin(theta)+poly[i]*cos(theta);
	    }
	    setcolor(RED);
	    drawpoly(4,poly);

	   break;
  case 4:  break;
 }
 }while(opt!=4);
 getch();
}