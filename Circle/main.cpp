#include <GL/glut.h>
#include <bits/stdc++.h>
#include "../Point.h"
#include "BresenhamCircle.h"

using namespace std;

Point center;
int radius;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}


void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    BresenhamCircle midPointCircle = BresenhamCircle(center,radius);
    midPointCircle.MidPointCircle();
    glFlush();
}

int main(int argc, char **argv) {

    cout << "Enter the x coordinate of the center" << endl;
    cin >> center.x;

    cout << "Enter the y coordinate of the center" << endl;
    cin >> center.y;

    cout << "Enter the radius of the circle" << endl;
    cin >> radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(-500, 500);
    glutCreateWindow("Bresenham's Circle Drawing");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
