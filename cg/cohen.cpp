//2.polygon clipping using cohen southerland line clipping algorithm
#include <iostream>
#include <graphics.h>
#include <math.h>
#include <X11/Xlib.h> // For compatibility on certain platforms
using namespace std;

// Constants for region codes
static const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int xl, yl, xh, yh;

// Function to calculate region code
int getcode(int x, int y) {
    int code = 0;
    if (y > yh) code |= TOP;
    if (y < yl) code |= BOTTOM;
    if (x < xl) code |= LEFT;
    if (x > xh) code |= RIGHT;
    return code;
}

int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);

    setcolor(BLUE);

    // Input for clipping window
    cout << "Enter bottom-left and top-right coordinates of the window: ";
    cin >> xl >> yl >> xh >> yh;

    // Draw the clipping window
    rectangle(xl, yl, xh, yh);

    // Input for line endpoints
    int x1, y1, x2, y2;
    cout << "Enter the endpoints of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the line
    line(x1, y1, x2, y2);
    getch();

    // Calculate region codes for endpoints
    int outcode1 = getcode(x1, y1), outcode2 = getcode(x2, y2);
    int accept = 0;

    // Cohen-Sutherland Line Clipping Algorithm
    while (1) {
        float m = (float)(y2 - y1) / (x2 - x1);

        // Case: Both endpoints inside the window
        if (outcode1 == 0 && outcode2 == 0) {
            accept = 1;
            break;
        }
        // Case: Both endpoints outside the window, same region
        else if ((outcode1 & outcode2) != 0) {
            break;
        }
        // Case: Line partially inside the window
        else {
            int x, y;
            int temp;

            // Determine which point to clip
            if (outcode1 != 0)
                temp = outcode1;
            else
                temp = outcode2;

            // Find intersection point
            if (temp & TOP) {
                x = x1 + (yh - y1) / m;
                y = yh;
            } else if (temp & BOTTOM) {
                x = x1 + (yl - y1) / m;
                y = yl;
            } else if (temp & LEFT) {
                x = xl;
                y = y1 + m * (xl - x1);
            } else if (temp & RIGHT) {
                x = xh;
                y = y1 + m * (xh - x1);
            }

            // Update the clipped point
            if (temp == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }

    setcolor(15); // Set color for clipped line

    // Display the result
    cout << "After clipping:" << endl;
    if (accept) {
        line(x1, y1, x2, y2);
    } else {
        cout << "Line is completely outside the clipping window." << endl;
    }

    getch();
    closegraph();
    return 0;
}

