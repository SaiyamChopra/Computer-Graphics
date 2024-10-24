//CIRCLE
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, YELLOW);  // Octant 1
    putpixel(xc - x, yc + y, YELLOW);  // Octant 2
    putpixel(xc + x, yc - y, YELLOW);  // Octant 3
    putpixel(xc - x, yc - y, YELLOW);  // Octant 4
    putpixel(xc + y, yc + x, YELLOW);  // Octant 5
    putpixel(xc - y, yc + x, YELLOW);  // Octant 6
    putpixel(xc + y, yc - x, YELLOW);  // Octant 7
    putpixel(xc - y, yc - x, YELLOW);  // Octant 8
}

void main() {
    int gd = DETECT, gm;
    int xc, yc, r, x, y, p;

    clrscr();
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Enter the center of circle (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    x = 0;
    y = r;
    p = 1 - r;  // Initial decision parameter

    // Plot the initial points
    drawCircle(xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else 
        {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }
        drawCircle(xc, yc, x, y);  // Plot points for each iteration
        delay(50);
    }
    getch();
   closegraph();
}