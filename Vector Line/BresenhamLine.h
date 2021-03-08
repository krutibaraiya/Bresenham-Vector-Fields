#ifndef BRESENHAM_LINE
#define BRESENHAM_LINE

#include <bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"

using namespace std;

class BresenhamLine {
private:
    Point P,Q;
    
    GLfloat randomFloat() {
        return (GLfloat)rand() / RAND_MAX;
    }


    void draw_pixel(Point point) {
        glColor3f(randomFloat(),randomFloat(),randomFloat());
        glPointSize(2);
        glBegin(GL_POINTS);
        glVertex2i(point.x, point.y);
        glEnd();
    }

public:

    BresenhamLine(Point p, Point q) {
        P = p;
        Q = q;
    }

    void draw_line() {
        if (P == Q) {
            draw_pixel(P);
            return;
        }
        if (P.x == Q.x) {
            if (P.y > Q.y) {
                swap(P,Q);
            }

        } else {
            if (P.x > Q.x) {
                swap(P,Q);
            }

        }

        Point current = P;

        int dy = Q.y - P.y;
        int dx = Q.x - P.x;


        if (dy == 0) {
            while (current != Q) {
                draw_pixel(current);
                current.x = current.x + 1;
            }
            draw_pixel(Q);
        } else if (dx == 0) {
            while (current != Q) {
                draw_pixel(current);
                if (dy > 0)
                    current.y = current.y + 1;
                else
                    current.y = current.y - 1;
            }
            draw_pixel(Q);
        } else if (dy > 0) {

            if (dx >= dy) {
                int d = 2 * dy - dx;
                int incrE = 2 * dy;
                int incrNE = 2 * (dy - dx);

                draw_pixel(P);

                while (current.x < Q.x) {
                    if (d <= 0)
                        d += incrE;
                    else {
                        d += incrNE;
                        current.y = current.y + 1;
                    }
                    current.x = current.x + 1;
                    draw_pixel(current);
                }
            } else {
                int d = dy - 2 * dx;
                int incrN = -2 * dx;
                int incrNE = 2 * (dy - dx);

                draw_pixel(P);

                while (current.y < Q.y) {
                    if (d > 0)
                        d += incrN;
                    else {
                        d += incrNE;
                        current.x = current.x + 1;
                    }
                    current.y = current.y + 1;
                    draw_pixel(current);
                }
            }
        } else {
            if (dx >= -dy) {
                int d = 2 * dy + dx;
                int incrE = 2 * dy;
                int incrSE = 2 * (dy + dx);
                draw_pixel(P);

                while (current.x < Q.x) {
                    if (d >= 0)
                        d += incrE;
                    else {
                        d += incrSE;
                        current.y = current.y - 1;
                    }
                    current.x = current.x + 1;
                    draw_pixel(current);
                }
            } else {
                int d = dy + 2 * dx;
                int incrS = 2 * dx;
                int incrSE = 2 * (dy + dx);

                draw_pixel(P);

                while (current.y > Q.y) {
                    if (d <= 0)
                        d += incrS;
                    else {
                        d += incrSE;
                        current.x = current.x + 1;
                    }
                    current.y = current.y - 1;
                    draw_pixel(current);

                }

            }

        }
    }

};
#endif
