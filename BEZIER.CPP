//BEZEIR
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    int gd = DETECT, gm;
    float x0, y0, x1, y1, x2, y2, x3, y3, t = 0.0, i, x, y;

    // Clear screen
    clrscr();

    // Get input points
    printf("Enter first point (P0): ");
    scanf("%f %f", &x0, &y0);
    printf("Enter second point (P1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter third point (P2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter fourth point (P3): ");
    scanf("%f %f", &x3, &y3);

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    // Loop to draw the Bézier curve using parametric equations
    for (t = 0; t <= 1; t += 0.001)
    {
        i = 1 - t;
        x = i * i * i * x0 + 3 * t * i * i * x1 + 3 * t * t * i * x2 + t * t * t * x3;
        y = i * i * i * y0 + 3 * t * i * i * y1 + 3 * t * t * i * y2 + t * t * t * y3;
        putpixel(x, y, YELLOW);
    }

    // Wait for user input
    getch();
    closegraph();
}
