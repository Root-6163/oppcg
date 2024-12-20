//5.curve and fractals 
//snow flake
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

// Class to generate a fractal pattern
class Fractal {
    int x1, y1, x2, y2, x3, y3, n;

public:
    void initGraphics();  // Initialize graphics mode
    void closeGraphics(); // Close graphics mode
    void koch(int iteration, int x1, int y1, int x5, int y5); // Generate Koch curve
    void draw();          // Draw the snowflake fractal
};

// Function to initialize graphics
void Fractal::initGraphics() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
}

// Function to close graphics
void Fractal::closeGraphics() {
    getch();
    closegraph();
}

// Function to generate Koch curve recursively
void Fractal::koch(int iteration, int x1, int y1, int x5, int y5) {
    int deltaX, deltaY, x2, y2, x3, y3, x4, y4;

    if (iteration == 0) {
        // Draw line for the base case
        line(x1, y1, x5, y5);
    } else {
        deltaX = x5 - x1;
        deltaY = y5 - y1;

        // Divide the line segment into three parts
        x2 = x1 + deltaX / 3;
        y2 = y1 + deltaY / 3;

        x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6);
        y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);

        x4 = x1 + 2 * deltaX / 3;
        y4 = y1 + 2 * deltaY / 3;

        // Recursively draw smaller Koch curves
        koch(iteration - 1, x1, y1, x2, y2);
        koch(iteration - 1, x2, y2, x3, y3);
        koch(iteration - 1, x3, y3, x4, y4);
        koch(iteration - 1, x4, y4, x5, y5);
    }
}

// Function to draw the snowflake fractal
void Fractal::draw() {
    cout << "\n\tEnter the number of iterations: ";
    cin >> n;

    // Draw three Koch curves to form a snowflake
    koch(n, 280, 280, 150, 20);
    koch(n, 20, 280, 280, 280);
    koch(n, 150, 20, 20, 280);
}

int main() {
    Fractal fractalObj;

    fractalObj.initGraphics(); // Initialize graphics mode
    fractalObj.draw();         // Draw the fractal
    fractalObj.closeGraphics(); // Close graphics mode

    return 0;
}

