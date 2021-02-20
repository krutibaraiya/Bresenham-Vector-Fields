#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;


void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 250,-250 , 250);
}

void draw_pixel(int x, int y) {
    glColor3f(0,0,1);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_circle(int x, int y, int radius) {
    x = 0;
    y = radius;
    double d = 1 - radius;
    int deltaE = 3;
    int deltaSE = -2*radius + 5;

    draw_pixel(x,y);
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
        draw_pixel(x,y);
        draw_pixel(x,-y);
        draw_pixel(-x,-y);
        draw_pixel(-x,y);
        draw_pixel(y,x);
        draw_pixel(-y,x);
        draw_pixel(-y,-x);
        draw_pixel(y,-x);
    }



}

void myDisplay() {
    for(int i = -100; i < 100; i+=10) {
        for(int j = -100; j < 100; j+=10) {
            draw_circle((i+j)/2,(j-i)/2,sqrt(2*(i*i + j*j)));
        }
    }
    glFlush();
}

int main(int argc, char **argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(-250, -250);
    glutCreateWindow("Vector Field Circle Visualization");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}