#include <GL/glut.h>
#include <bits/stdc++.h>
#include "../Point.h"
#include "BresenhamCircle.h"

using namespace std;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = -1000; i < 1000; i+=50) {
        for(int j = -1000; j < 1000; j+=50) {
            BresenhamCircle midPointCircle = BresenhamCircle(Point((i+j)/2,(j-i)/2),sqrt(2*(i*i + j*j)));
            midPointCircle.MidPointCircle();
        }
    }
    glFlush();
}


int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(-500, 500);
    glutCreateWindow("Vector Circle Visualization");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
