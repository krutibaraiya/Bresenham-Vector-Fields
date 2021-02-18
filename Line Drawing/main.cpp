#include <GL/glut.h>
#include <iostream>
using namespace std;

int X1, Y1, X2, Y2;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
    glColor3f(0,0,1);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
    int dx, dy;

    dx = x2-x1;
    dy = y2-y1;

    int d = 2*dy - dx;
    int incrE = 2*dy;
    int incrNE = 2*(dy-dx);
    int x = x1, y = y1;
    draw_pixel(x,y);

    while(x < x2) {
        if(d <= 0) {
            d += incrE;
        } else {
            d += incrNE;
            y++;
        }
        x++;
        draw_pixel(x,y);
    }


}


void myDisplay() {
    draw_line(X1, X2, Y1, Y2);
    glFlush();
}

int main(int argc, char **argv) {

    cin >> X1 >> Y1 >> X2 >> Y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
