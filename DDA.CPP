//DDA
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void main()
{
    float x, y, x1, y1, x2, y2, dx, dy, m;
    int i, gd = DETECT, gm, steps;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter x1, y1, x2, y2: ");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if (dx != 0) {
        m = dy / dx;
    } else {
        m = 0;
    }

    x = x1;
    y = y1;

    if (fabs(dx) >= fabs(dy)) {
        steps = fabs(dx);
    } else {
        steps = fabs(dy);
    }

    for (i = 0; i <= steps; i++) {
	putpixel((int)(x + 0.5), (int)(y + 0.5), RED);  // Manually round off by adding 0.5

	if (fabs(m) <= 1) {
	    x = x + 1;
	    y = y + m;

	} else {
	    x = x + (1 / m);
	    y = y + 1;
	}
    }

    getch();
    closegraph();
}
