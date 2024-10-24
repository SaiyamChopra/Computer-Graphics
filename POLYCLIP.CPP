// POLYGON CLIPPING
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int outcode;
outcode CompOutCode(float x, float y);

enum { TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8 };
float xmin, xmax, ymin, ymax;

void clip(float x0, float y0, float x1, float y1) {
    outcode outcode0, outcode1, outcodeOut;
    int accept = FALSE, done = FALSE;

    outcode0 = CompOutCode(x0, y0);
    outcode1 = CompOutCode(x1, y1);

    do {
        if (!(outcode0 | outcode1)) { // Trivially accept
            accept = TRUE;
            done = TRUE;
        } else if (outcode0 & outcode1) { // Trivially reject
            done = TRUE;
        } else {
            float x, y;
            outcodeOut = outcode0 ? outcode0 : outcode1;

            if (outcodeOut & TOP) { // Clip against top
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            } else if (outcodeOut & BOTTOM) { // Clip against bottom
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            } else if (outcodeOut & RIGHT) { // Clip against right
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            } else { // Clip against left
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            if (outcodeOut == outcode0) {
                x0 = x;
                y0 = y;
                outcode0 = CompOutCode(x0, y0);
            } else {
                x1 = x;
                y1 = y;
                outcode1 = CompOutCode(x1, y1);
            }
        }
    } while (!done);

    if (accept) {
        line(x0, y0, x1, y1);
        outtextxy(150, 20, "POLYGON AFTER CLIPPING");
    }

    rectangle(xmin, ymin, xmax, ymax);
}

outcode CompOutCode(float x, float y) {
    outcode code = 0;

    if (y > ymax)
        code |= TOP;
    else if (y < ymin)
        code |= BOTTOM;

    if (x > xmax)
        code |= RIGHT;
    else if (x < xmin)
        code |= LEFT;

    return code;
}

void main() {
    float x1, y1, x2, y2;
    int gdriver = DETECT, gmode, n, poly[14], i;

    clrscr();
    printf("SUTHERLAND HODGEMAN POLYGON CLIPPING ALGORITHM");
    printf("\n--------------------------------------------");
    printf("\nENTER THE NO.OF SIDES FOR POLYGON:\n");
    scanf("%d", &n);
    printf("ENTER THE COORDINATES FOR POLYGON:\n");

    for (i = 0; i < 2 * n; i++) {
        scanf("%d", &poly[i]);
    }

    poly[2 * n] = poly[0];
    poly[2 * n + 1] = poly[1];

    printf("\n--------------------------------------------\n");
    printf("ENTER THE RECTANGULAR COORDINATES FOR CLIPPING WINDOW:\n");
    scanf("%f%f%f%f", &xmin, &ymin, &xmax, &ymax);

    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

    outtextxy(150, 20, "POLYGON BEFORE CLIPPING");
    drawpoly(n + 1, poly);
    rectangle(xmin, ymin, xmax, ymax);
    getch();
    cleardevice();

    for (i = 0; i < n; i++) {
        clip(poly[2 * i], poly[(2 * i) + 1], poly[(2 * i) + 2], poly[(2 * i) + 3]);
    }
   
    getch();
    restorecrtmode();
}