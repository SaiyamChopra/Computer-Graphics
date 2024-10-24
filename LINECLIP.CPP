// LINE CLIPPING

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
void main()
{
    int gd = DETECT, gm, x1, x2, y1, y2, i;
    float xmin, ymin, xmax, ymax;
    float t1, t2, a[4], b[4], c[4], X1, X2, Y1, Y2;
    clrscr();
    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    // Input for the line's endpoints
    printf("\nEnter the coordinates of the first point (x1, y1):\n");
    scanf("%d%d", &x1, &y1);

    printf("\nEnter the coordinates of the second point (x2, y2):\n");
    scanf("%d%d", &x2, &y2);

    // Input for the window (clipping rectangle) coordinates
    printf("\nEnter the window coordinates (xmin, ymin, xmax, ymax):\n");
    scanf("%f%f%f%f", &xmin, &ymin, &xmax, &ymax);

    // Draw the clipping rectangle
    rectangle(xmin, ymin, xmax, ymax);

    // Draw the original line
    line(x1, y1, x2, y2);
    delay(1000);
    setcolor(BLACK);
    line(x1, y1, x2, y2);

    // Parametric clipping calculations
    a[0] = -(x2 - x1);  // Left
    a[1] = x2 - x1;     // Right
    a[2] = -(y2 - y1);  // Bottom
    a[3] = y2 - y1;     // Top

    b[0] = (x1 - xmin); // Left boundary
    b[1] = (xmax - x1); // Right boundary
    b[2] = (y1 - ymin); // Bottom boundary
    b[3] = (ymax - y1); // Top boundary

    t1 = 0;
    t2 = 1;

    // Clipping against all boundaries
    for (i = 0; i < 4; i++) {
        if (a[i] != 0) {
            c[i] = b[i] / a[i];
            if (a[i] < 0) 
            { // Entering segment
                if (c[i] > t1)
                    t1 = c[i];
            }
            else
            { // Leaving segment
                if (c[i] < t2)
                    t2 = c[i];
            }
        }
    }

    // If the line is within the clipping boundaries
    if (t1 < t2) {
        X1 = x1 + t1 * (x2 - x1);
        X2 = x1 + t2 * (x2 - x1);
        Y1 = y1 + t1 * (y2 - y1);
        Y2 = y1 + t2 * (y2 - y1);

        // Set a new color for the clipped line
        setcolor(5);

        // Draw the clipped line
        line(X1, Y1, X2, Y2);
    }
    getch();
    closegraph();
}
