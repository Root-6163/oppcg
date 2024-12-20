//basic 2d transformation
//4 
#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

class Polygon {
    float p[10][3];  // Store vertices in homogeneous coordinates
    int m;           // Number of vertices

public:
    void getPolygon();
    void displayPolygon();
    void drawPolygon();
    Polygon matMul(const Polygon&);
    Polygon operator+(const Polygon&); // Translation
    Polygon operator*(const Polygon&); // Scaling
    Polygon operator/(const Polygon&); // Clockwise rotation
    Polygon operator-(const Polygon&); // Anticlockwise rotation
};

void Polygon::getPolygon() {
    cout << "Enter the number of vertices: ";
    cin >> m;

    cout << "Enter the polygon coordinates (x y):\n";
    for (int i = 0; i < m; i++) {
        cin >> p[i][0] >> p[i][1];
        p[i][2] = 1; // Homogeneous coordinate
    }
}

void Polygon::displayPolygon() {
    cout << "The polygon is as follows:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

void Polygon::drawPolygon() {
    for (int i = 0; i < m - 1; i++) {
        line(p[i][0] + 320, 240 - p[i][1], p[i + 1][0] + 320, 240 - p[i + 1][1]);
    }
    // Close the polygon
    line(p[m - 1][0] + 320, 240 - p[m - 1][1], p[0][0] + 320, 240 - p[0][1]);
}

Polygon Polygon::matMul(const Polygon& transformation) {
    Polygon result;
    result.m = m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            result.p[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result.p[i][j] += p[i][k] * transformation.p[k][j];
            }
        }
    }

    return result;
}

Polygon Polygon::operator+(const Polygon& transformation) {
    Polygon result;
    Polygon translation;

    cout << "Enter translation factors (tx ty): ";
    cin >> translation.p[2][0] >> translation.p[2][1];
    
    translation.p[0][0] = 1; translation.p[0][1] = 0; translation.p[0][2] = 0;
    translation.p[1][0] = 0; translation.p[1][1] = 1; translation.p[1][2] = 0;
    translation.p[2][2] = 1;

    result = matMul(translation);
    return result;
}

Polygon Polygon::operator*(const Polygon& transformation) {
    Polygon result;
    Polygon scaling;

    cout << "Enter scaling factors (sx sy): ";
    cin >> scaling.p[0][0] >> scaling.p[1][1];

    scaling.p[0][1] = scaling.p[0][2] = 0;
    scaling.p[1][0] = scaling.p[1][2] = 0;
    scaling.p[2][0] = scaling.p[2][1] = 0;
    scaling.p[2][2] = 1;

    result = matMul(scaling);
    return result;
}

Polygon Polygon::operator/(const Polygon& transformation) {
    Polygon result;
    Polygon rotation;
    float angle, radians;

    cout << "Enter rotation angle (clockwise): ";
    cin >> angle;
    radians = angle * (M_PI / 180);

    rotation.p[0][0] = cos(radians); rotation.p[0][1] = -sin(radians); rotation.p[0][2] = 0;
    rotation.p[1][0] = sin(radians); rotation.p[1][1] = cos(radians); rotation.p[1][2] = 0;
    rotation.p[2][0] = 0; rotation.p[2][1] = 0; rotation.p[2][2] = 1;

    result = matMul(rotation);
    return result;
}

Polygon Polygon::operator-(const Polygon& transformation) {
    Polygon result;
    Polygon rotation;
    float angle, radians;

    cout << "Enter rotation angle (anticlockwise): ";
    cin >> angle;
    radians = angle * (M_PI / 180);

    rotation.p[0][0] = cos(radians); rotation.p[0][1] = sin(radians); rotation.p[0][2] = 0;
    rotation.p[1][0] = -sin(radians); rotation.p[1][1] = cos(radians); rotation.p[1][2] = 0;
    rotation.p[2][0] = 0; rotation.p[2][1] = 0; rotation.p[2][2] = 1;

    result = matMul(rotation);
    return result;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Polygon p1, p2, p3;
    p1.getPolygon();
    p1.displayPolygon();
    p1.drawPolygon();

    int choice;
    do {
        cout << "\n\n**** MENU ****";
        cout << "\n1. Translation\n2. Scaling\n3. Clockwise Rotation\n4. Anticlockwise Rotation\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p3 = p1 + p2;
            break;
        case 2:
            p3 = p1 * p2;
            break;
        case 3:
            p3 = p1 / p2;
            break;
        case 4:
            p3 = p1 - p2;
            break;
        case 5:
            closegraph();
            return 0;
        default:
            cout << "Invalid choice!";
        }

        cleardevice();
        p3.displayPolygon();
        p3.drawPolygon();
    } while (choice != 5);

    return 0;
}

