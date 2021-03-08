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
    gluOrtho2D(-250, 250, -250, 250);
}
void myDisplay() {
    int k = 10, x = 128, y = 128;
    while(k--) {
        int x1 = y/2, y1 = -x;
        BresenhamLine bresenhamLine = BresenhamLine(Point(x,y), Point(x1,y1));
        bresenhamLine.draw_line();
        x = x1;
        y = y1;
    }

    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(-250, -250);
    glutCreateWindow("Vector Polyline Visualization");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
