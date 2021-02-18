#include <GL/glut.h>
#include <iostream>
using namespace std;

int Radius, X, Y;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_circle(int x, int y) {
    glColor3f(0,0,1);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x+X, y+Y);
    glEnd();
}

void MidPointCircle(int radius, int x, int y) {
    x = 0;
    y = radius;
    double d = 1 - radius;
    int deltaE = 3;
    int deltaSE = -2*radius + 5;

    draw_circle(x,y);
    while(y > x) {
        if(d < 0) {
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;
        } else {
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            y--;
        } x++;
        draw_circle(x,y);
        draw_circle(x,-y);
        draw_circle(-x,-y);
        draw_circle(-x,y);
        draw_circle(y,x);
        draw_circle(-y,x);
        draw_circle(-y,-x);
        draw_circle(y,-x);
    }



}

void myDisplay() {
    MidPointCircle(Radius, X, Y);
    glFlush();
}

int main(int argc, char **argv) {

    cin >> X >> Y >> Radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Circle Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}