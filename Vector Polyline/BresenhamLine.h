#ifndef BRESENHAM_LINE
#define BRESENHAM_LINE

#include <bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"

using namespace std;
/**
 *  Class to implements Bresenham's Line Drawing Algorithm
 */
class BresenhamLine {
private:
    Point P; //!< Starting point of the line
    Point Q; //!<Ending point of the line

/**
 * Method to draw a pixel at a given point
 * @param point The point to be plotted
 */
    void draw_pixel(Point point) {
        glColor3f(1,1,1);
        glPointSize(2);
        glBegin(GL_POINTS);
        glVertex2i(point.x, point.y);
        glEnd();
    }

public:
/***
 * Parametrized Constructor of the class BresenhamLine
 * @param p Starting point of the line to be drawn
 * @param q Ending point of the line to be drawn
 */
    BresenhamLine(Point p, Point q) {
        P = p;
        Q = q;
    }
/**
 * Method to draw the line using Bresenham's Line drawing algorithm
 */
    void draw_line() {
        /// When starting point and ending point are same
        if (P == Q) {
            draw_pixel(P);
            return;
        }

        /// Ensuring that point P is having x coordinate less than point Q, so that we can move from left to right
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

        /// Line parallel to x-axis
        if (dy == 0) {
            while (current != Q) {
                draw_pixel(current);
                current.x = current.x + 1;
            }
            draw_pixel(Q);
        }
            /// Line parallel to y-axis
        else if (dx == 0) {
            while (current != Q) {
                draw_pixel(current);
                if (dy > 0)
                    current.y = current.y + 1;
                else
                    current.y = current.y - 1;
            }
            draw_pixel(Q);
        }
            /// Slope > 0
        else if (dy > 0) {
            /// Slope < 1
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
            }
                /// Slope > 1
            else {
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
        }
            /// Slope < 0
        else {
            /// Slope > -1
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
            }
                /// Slope < -1
            else {
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
