#include <bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"
#include "BresenhamLine.h"

using namespace std;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 250, -250, 250);
}

void myDisplay() {

    for(int i = -1000; i < 1000; i+=20) {
        for(int j = -1000; j < 1000; j+=20) {
            BresenhamLine bresenhamLine = BresenhamLine(Point(i,j),Point(i - j,j + i));
            bresenhamLine.draw_line();
        }
    }
    glFlush();
}

int main(int argc, char **argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(-500, -500);
    glutCreateWindow("Vector Field visualization");
    myInit();
    glutDisplayFunc(myDisplay);


    glutMainLoop();
}
