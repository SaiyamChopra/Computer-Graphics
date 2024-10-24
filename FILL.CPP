// 1.Boundary Fill-4  2.Flood Fill-4  3.Boundary Fill-8  4.Flood Fill-8

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<conio.h>

// 4-connected boundary fill algorithm
void boundaryFill4(int x, int y, int fillColor, int bColor)
{
    if(getpixel(x,y) != bColor && getpixel(x,y) != fillColor)
    {
        delay(10);
        putpixel(x, y, fillColor);
        boundaryFill4(x+1, y, fillColor, bColor);
        boundaryFill4(x, y+1, fillColor, bColor);
        boundaryFill4(x-1, y, fillColor, bColor);
        boundaryFill4(x, y-1, fillColor, bColor);
    }
}

// 8-connected boundary fill algorithm
void boundaryFill8(int x, int y, int fillColor, int bColor)
{
    if(getpixel(x,y) != bColor && getpixel(x,y) != fillColor)
    {
        delay(10);
        putpixel(x, y, fillColor);
        boundaryFill8(x+1, y, fillColor, bColor);
        boundaryFill8(x, y+1, fillColor, bColor);
        boundaryFill8(x-1, y, fillColor, bColor);
        boundaryFill8(x, y-1, fillColor, bColor);
        boundaryFill8(x+1, y-1, fillColor, bColor);
        boundaryFill8(x+1, y+1, fillColor, bColor);
        boundaryFill8(x-1, y+1, fillColor, bColor);
        boundaryFill8(x-1, y-1, fillColor, bColor);
    }
}

// 4-connected flood fill algorithm
void floodFill4(int x, int y, int newColor, int oldColor)
{
    if(getpixel(x,y) == oldColor)
    {
        delay(10);
        putpixel(x, y, newColor);
        floodFill4(x+1, y, newColor, oldColor);
        floodFill4(x, y+1, newColor, oldColor);
        floodFill4(x-1, y, newColor, oldColor);
        floodFill4(x, y-1, newColor, oldColor);
    }
}

// 8-connected flood fill algorithm
void floodFill8(int x, int y, int newColor, int oldColor)
{
    if(getpixel(x,y) == oldColor)
    {
        delay(10);
        putpixel(x, y, newColor);
        floodFill8(x+1, y, newColor, oldColor);
        floodFill8(x, y+1, newColor, oldColor);
        floodFill8(x-1, y, newColor, oldColor);
        floodFill8(x, y-1, newColor, oldColor);
        floodFill8(x+1, y-1, newColor, oldColor);
        floodFill8(x+1, y+1, newColor, oldColor);
        floodFill8(x-1, y+1, newColor, oldColor);
        floodFill8(x-1, y-1, newColor, oldColor);
    }
}

int main(){
    int choice, cochoice;
    int gDriver = DETECT, gMode;
    initgraph(&gDriver, &gMode, "C:\\Turboc3\\BGI");

    printf("Enter the choice of fill algorithm:\n");
    printf("1. Boundary Fill-4\n2. Flood Fill-4\n3. Boundary Fill-8\n4. Flood Fill-8\n");
    scanf("%d", &choice);

    printf("Enter the choice of color:\n");
    printf("1. Red\n2. Green\n3. Blue\n");
    scanf("%d", &cochoice);

    int fillColor = (cochoice == 1) ? 4 : (cochoice == 2) ? 2 : 1; // Map color choices to color codes

    switch(choice){
        case 1: // Boundary Fill-4
            rectangle(100, 150, 150, 200);
            boundaryFill4(125, 175, fillColor, 15); // 15 is the boundary color
            break;
        case 2: // Flood Fill-4
            rectangle(150, 250, 200, 300);
            floodFill4(175, 275, fillColor, 0); // 0 is the background color
            break;
        case 3: // Boundary Fill-8
            rectangle(100, 150, 150, 200);
            boundaryFill8(125, 175, fillColor, 15); // 15 is the boundary color
            break;
        case 4: // Flood Fill-8
            rectangle(150, 250, 200, 300);
            floodFill8(175, 275, fillColor, 0); // 0 is the background color
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    delay(1000);
    closegraph();
    return 0;
}

















/*
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void boundaryFill4(int x, int y, int fillColor, int bColor){
if(getpixel(x,y)!=bColor && getpixel(x,y)!=fillColor){
delay(10);
putpixel(x, y, fillColor);
boundaryFill4(x+1, y, fillColor, bColor);
boundaryFill4(x, y+1, fillColor, bColor);
boundaryFill4(x-1, y, fillColor, bColor);
boundaryFill4(x, y-1, fillColor, bColor);
}
}
void floodFill4(int x, int y, int newColor, int oldColor){
if(getpixel(x,y) == oldColor){
delay(10);
putpixel(x, y, newColor);
floodFill4(x+1, y, newColor, oldColor);
floodFill4(x, y+1, newColor, oldColor);
floodFill4(x-1, y, newColor, oldColor);
floodFill4(x, y-1, newColor, oldColor);
}
}
int main(){
int choice, cochoice;
int gDriver = DETECT, gMode, xc, yc, radius;
initgraph(&gDriver, &gMode, "c:\\turboc3\\bgi");
printf("Enter the choice of fill algorithm:\n");
printf("1.Boundary Fill\n 2. Flood Fill\n");
scanf("%d", &choice);
printf("Enter the choice of color:\n");
printf("1.Red\n 2.Green\n 3.Blue\n");
scanf("%d", &cochoice);
switch(choice){
case 1:
switch(cochoice){
case 1:
rectangle(100,150,150, 200);
boundaryFill4(125,175, 4, 15);
break;
case 2:
rectangle(100, 150, 150, 200);
boundaryFill4(125, 175, 2, 15);
break;
case 3:
rectangle(100, 150, 150, 200);
boundaryFill4(125, 175, 1, 15);
break;
}
break;
case 2:
switch(cochoice){
case 1:
rectangle(150, 250, 200, 300);
floodFill4(175, 275, 4, 0);
break;
case 2:
rectangle(150, 250, 200, 300);
floodFill4(175, 275, 2, 0);
break;
case 3:
rectangle(150, 250, 200, 300);
floodFill4(175, 275, 1, 0);
break;
}
break;
}
delay(1000);
closegraph();
return 0;
}*/
