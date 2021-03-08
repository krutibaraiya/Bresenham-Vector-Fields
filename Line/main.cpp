#include <bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"
#include "BresenhamLine.h"

using namespace std;

Point Start, End;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void myDisplay() {
    BresenhamLine bresenhamLine = BresenhamLine(Start, End);
    bresenhamLine.draw_line();
    glFlush();
}

int main(int argc, char **argv) {


    cout << "Enter the x coordinate of the starting point" << endl;
    cin >> Start.x;
    cout << "Enter the y coordinate of the starting point" << endl;
    cin >> Start.y;
    cout << "Enter the x coordinate of the ending point" << endl;
    cin >> End.x;
    cout << "Enter the y coordinate of the ending point" << endl;
    cin >> End.y;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(-500, -550);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
