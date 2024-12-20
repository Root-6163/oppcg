//3.pattern drawing using line and circle
//user dda line and bresenhm circle drawing algorithm
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

// Class to handle individual pixel drawing
class Pixel {
    int X, Y, c;
public:
    void drawPixel(int x, int y, int color) {
        X = x;
        Y = y;
        c = color;
        putpixel(X, Y, c);
    }
};

// Class for line drawing algorithm (inherits from Pixel)
class LineAlgo : public Pixel {
    int x1, x2, y1, y2;
public:
    LineAlgo(int X1, int Y1, int X2, int Y2) {
        x1 = X1;
        y1 = Y1;
        x2 = X2;
        y2 = Y2;
    }
    void drawLine(int color);
    int sign(float arg);
};

// Function to calculate the sign of a number
int LineAlgo::sign(float arg) {
    if (arg < 0) return -1;
    else if (arg == 0) return 0;
    else return 1;
}

// Function to draw a line using the Bresenham algorithm
void LineAlgo::drawLine(int color) {
    int s1, s2, exchange, i;
    float dx, dy, p, temp;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    s1 = sign(x2 - x1);
    s2 = sign(y2 - y1);

    if (dy > dx) {
        temp = dx;
        dx = dy;
        dy = temp;
        exchange = 1;
    } else {
        exchange = 0;
    }

    p = 2 * dy - dx;
    int x = x1, y = y1;

    for (i = 1; i <= dx; i++) {
        drawPixel(x, y, color);

        while (p >= 0) {
            if (exchange == 1)
                x += s1;
            else
                y += s2;

            p -= 2 * dx;
        }

        if (exchange == 1)
            y += s2;
        else
            x += s1;

        p += 2 * dy;
    }
}

// Class for circle drawing algorithm (inherits from Pixel)
class CircleAlgo : public Pixel {
    int x, y, r;
public:
    CircleAlgo(int X, int Y, int R) {
        x = X;
        y = Y;
        r = R;
    }
    void drawCircle();
};

// Function to draw a circle using the midpoint algorithm
void CircleAlgo::drawCircle() {
    int d, x1, y1;
    x1 = 0;
    y1 = r;
    drawPixel(x, y, 2);
    d = 3 - (2 * r);

    while (x1 <= y1) {
        if (d <= 0) {
            d = d + (4 * x1) + 6;
            x1++;
        } else {
            d = d + 4 * (x1 - y1) + 10;
            x1++;
            y1--;
        }

        drawPixel(x + x1, y - y1, 2);
        drawPixel(x - x1, y - y1, 2);
        drawPixel(x + x1, y + y1, 2);
        drawPixel(x - x1, y + y1, 2);
        drawPixel(x + y1, y - x1, 2);
        drawPixel(x - y1, y - x1, 2);
        drawPixel(x + y1, y + x1, 2);
        drawPixel(x - y1, y + x1, 2);
    }
}

int main() {
    int l, xc, yc, a, b, c, u, v, r1, r2;

    cout << "\nEnter the length of the equilateral triangle: ";
    cin >> l;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    xc = 640 / 2;
    yc = 480 / 2;

    r1 = (float)(sqrt(3) * l) / 6;
    a = xc - (float)(l / 2);
    b = yc + r1;
    c = xc + (float)(l / 2);
    r2 = (float)(sqrt((a - xc) * (a - xc) + (b - yc) * (b - yc)));

    // Draw triangle sides
    LineAlgo l1(a, b, c, b);
    l1.drawLine(3);
    delay(200);

    u = xc;
    v = float(yc - r2);

    LineAlgo l2(a, b, u, v);
    l2.drawLine(3);
    delay(200);

    LineAlgo l3(c, b, u, v);
    l3.drawLine(3);
    delay(200);

    // Draw inner and outer circles
    CircleAlgo c1(xc, yc, r1);
    c1.drawCircle();
    delay(200);

    CircleAlgo c2(xc, yc, r2);
    c2.drawCircle();
    delay(200);

    getch();
    closegraph();
    return 0;
}

