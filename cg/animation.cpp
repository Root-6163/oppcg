//7.animation using c++
//7rainfal
#include <graphics.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class WalkingMan {
    int rhx, rhy;

public:
    void draw(int i);         // Draw the walking man
    void draw(int x, int y);  // Draw the raindrops
};

// Method to draw the walking man animation
void WalkingMan::draw(int i) {
    // Draw platform
    line(20, 380, 580, 380);

    // Alternating leg movements
    if (i % 2 == 0) {
        // Left leg forward, right leg backward
        line(25 + i, 380, 35 + i, 340); // Left leg
        line(45 + i, 380, 35 + i, 340); // Right leg
        line(35 + i, 310, 25 + i, 330); // Left hand
    } else {
        // Both legs together
        line(35 + i, 380, 35 + i, 340);
        line(35 + i, 310, 40 + i, 330); // Right hand
    }

    delay(20);

    // Body and head
    line(35 + i, 340, 35 + i, 310); // Body
    circle(35 + i, 300, 10);        // Head

    // Umbrella
    line(35 + i, 310, 50 + i, 330); // Hand holding umbrella
    line(50 + i, 330, 50 + i, 280); // Umbrella stick
    line(15 + i, 280, 85 + i, 280); // Umbrella top
    arc(50 + i, 280, 180, 360, 35); // Umbrella curve
    arc(55 + i, 330, 0, 180, 5);    // Umbrella handle
}

// Method to draw raindrops
void WalkingMan::draw(int x, int y) {
    rhx = x;
    rhy = y;

    // Draw random raindrops
    for (int j = 0; j < 100; j++) {
        outtextxy(rand() % rhx, rand() % (rhy - 50), "|");
        setcolor(WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    int rhx, rhy;

    WalkingMan obj;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Seed random number generator for raindrops
    srand(time(0));

    // Animation loop
    for (int i = 0; i < 500; i += 5) {
        obj.draw(i);                // Draw walking man
        rhx = getmaxx();            // Get screen width
        rhy = getmaxy();            // Get screen height
        obj.draw(rhx, rhy);         // Draw raindrops
        delay(150);                 // Frame rate control
        cleardevice();              // Clear screen for next frame
    }

    getch();
    closegraph(); // Close graphics mode
    return 0;
}

