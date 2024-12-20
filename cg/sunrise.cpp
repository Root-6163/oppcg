//6. implementation of opengl
//sunrise 
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

// Ball position and color
float ballX = -0.8f;
float ballY = -0.3f;
float ballZ = -1.2f;
float colR = 3.0;
float colG = 1.5;
float colB = 1.0;

// Background color
float bgColR = 0.0;
float bgColG = 0.0;
float bgColB = 0.0;

static int flag = 1;

// Function to draw the ball
void drawBall() {
    glColor3f(colR, colG, colB);       // Set ball color
    glTranslatef(ballX, ballY, ballZ); // Move it toward the screen
    glutSolidSphere(0.05, 30, 30);     // Create the ball
}

// Function to draw a polygon resembling a mountain (Mount Avarest)
void drawAv() {
    glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 1.0); // Set color for the mountain

    glVertex3f(-0.9, -0.7, -1.0);
    glVertex3f(-0.5, -0.1, -1.0);
    glVertex3f(-0.2, -1.0, -1.0);
    glVertex3f(0.5, 0.0, -1.0);
    glVertex3f(0.6, -0.2, -1.0);
    glVertex3f(0.9, -0.7, -1.0);

    glEnd();
}

// Placeholder for drawing clouds
void drawClouds() {
    // Future implementation of clouds can go here
}

// Function to handle keyboard input for moving the ball
void keyPress(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        ballX -= 0.05f;
    }
    if (key == GLUT_KEY_LEFT) {
        ballX += 0.05f;
    }
    glutPostRedisplay();
}

// Initialize rendering settings
void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);    // Enable lighting
    glEnable(GL_LIGHT0);      // Enable light #0
    glEnable(GL_LIGHT1);      // Enable light #1
    glEnable(GL_NORMALIZE);   // Automatically normalize normals
}

// Handle window resizing
void handleResize(int w, int h) {
    glViewport(0, 0, w, h); // Set viewport to window dimensions

    glMatrixMode(GL_PROJECTION); // Switch to camera perspective
    glLoadIdentity();            // Reset the camera
    gluPerspective(45.0,         // Camera angle
                   (double)w / (double)h, // Aspect ratio
                   1.0,          // Near clipping coordinate
                   200.0);       // Far clipping coordinate
}

// Main drawing function
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(bgColR, bgColG, bgColB, 0.0); // Set background color

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Add ambient light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    // Add positioned light
    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    // Add directed light
    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    // Draw the ball (Sun)
    glPushMatrix();
    drawBall();
    glPopMatrix();

    // Draw the mountain
    glPushMatrix();
    drawAv();
    glPopMatrix();

    // Draw clouds
    glPushMatrix();
    drawClouds();
    glPopMatrix();

    glutSwapBuffers();
}

// Update function for ball animation
void update(int value) {
    if (ballX > 0.9f) {
        ballX = -0.8f;
        ballY = -0.3f;
        flag = 1;
        colR = 2.0;
        colG = 1.50;
        colB = 1.0;
        bgColB = 0.0;
    }

    if (flag) {
        ballX += 0.001f;
        ballY += 0.0007f;
        colR -= 0.001;
        colB += 0.005;
        bgColB += 0.001;

        if (ballX > 0.01) {
            flag = 0;
        }
    }

    if (!flag) {
        ballX += 0.001f;
        ballY -= 0.0007f;
        colR += 0.001;
        colB -= 0.01;
        bgColB -= 0.001;

        if (ballX < -0.3) {
            flag = 1;
        }
    }

    glutPostRedisplay(); // Trigger redraw
    glutTimerFunc(25, update, 0); // Call update again in 25 milliseconds
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Sun Animation");

    initRendering();

    glutDisplayFunc(drawScene);
    glutFullScreen();
    glutSpecialFunc(keyPress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);

    glutMainLoop(); // Start the main loop

    return 0;
}

