#include <GL/glut.h>
#include <iostream>
using namespace std;



void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 250, -250, 250);
}

void draw_pixel(int x, int y) {
    glColor3f(1,1,1);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int y1, int x2, int y2) {
    if (x1 == x2 and y1 == y2) {
        draw_pixel(x1, y1);
        return;
    }

    if (x1 == x2) {
        if (y1 > y2) {
            swap(x1, x2);
            swap(y1, y2);
        }

    } else {
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }

    }

    int x = x1, y = y1;

    int dy = y2 - y1;
    int dx = x2 - x1;

    if (dy == 0) {
        while (x != x2 or y != y2) {
            draw_pixel(x, y);
            x++;
        }
        draw_pixel(x2, y2);
    } else if (dx == 0) {
        while (x != x2 or y != y2) {
            draw_pixel(x, y);
            if (dy > 0)
                y++;
            else
                y--;
        }
        draw_pixel(x2, y2);
    } else if (dy > 0) {
        if (dx >= dy) {
            int d = 2 * dy - dx;
            int incrE = 2 * dy;
            int incrNE = 2 * (dy - dx);

            draw_pixel(x1, y1);

            while (x < x2) {
                if (d <= 0)
                    d += incrE;
                else {
                    d += incrNE;
                    y++;
                }
                x++;
                draw_pixel(x, y);
            }
        } else {
            int d = dy - 2 * dx;
            int incrN = -2 * dx;
            int incrNE = 2 * (dy - dx);

            draw_pixel(x1, y1);

            while (y < y2) {
                if (d > 0)
                    d += incrN;
                else {
                    d += incrNE;
                    x++;
                }
                y++;
                draw_pixel(x, y);
            }
        }
    } else {

        if (dx >= -dy) {
            int d = 2 * dy + dx;
            int incrE = 2 * dy;
            int incrSE = 2 * (dy + dx);
            draw_pixel(x1, y1);

            while (x < x2) {
                if (d >= 0)
                    d += incrE;
                else {
                    d += incrSE;
                    y--;
                }
                x++;
                draw_pixel(x, y);
            }
        } else {
            int d = dy + 2 * dx;
            int incrS = 2 * dx;
            int incrSE = 2 * (dy + dx);

            draw_pixel(x1, y1);

            while (y > y2) {
                if (d <= 0)
                    d += incrS;
                else {
                    d += incrSE;
                    x++;
                }
                y--;
                draw_pixel(x, y);

            }

        }

    }
}

void myDisplay() {
    for(int i = -100; i < 100; i+=20) {
        for(int j = -100; j < 100; j+=20) {
            draw_line(i, j, j, -i);
        }
    }
    glFlush();
}

int main(int argc, char **argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(-250, -250);
    glutCreateWindow("Vector Field visualization");
    myInit();
    glutDisplayFunc(myDisplay);


    glutMainLoop();
}