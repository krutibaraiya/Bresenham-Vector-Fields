#ifndef BRESENHAM_CIRCLE
#define BRESENHAM_CIRCLE

#include<bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"

using namespace std;
/**
 * Class to implement Bresenham's Circle drawing algorithm
 */
class BresenhamCircle {
private:
    Point center;  //!< Center of the circle
    int radius;    //!< Radius of the circle
/**
 * Method to draw a pixel at a given point
 * @param point The point to be plotted
 */
    void draw_circle(Point point) {
        glColor3f(1,0,0);
        glPointSize(2);
        glBegin(GL_POINTS);
        glVertex2i(center.x + point.x, center.y + point.y);
        glEnd();
    }

public:
/**
 * Parametrized constructor of BresenhamCircle class
 * @param Center Center of the circle to be drawn
 * @param Radius Radius of the circle to be drawn
 */
    BresenhamCircle(Point Center, int Radius) {
        center = Center;
        radius = Radius;
    }
/**
 * Method to draw circle using Bresenham's Circle drawing algorithm
 */
    void MidPointCircle() {
        /**
         * We shift the center of the circle to origin in the Bresenham's circle drawing algorithm
         * and then shift it back to its original location before plotting the pixel in draw_pixel function
         */

        /// Starting from the topmost point of the circle
        Point current = Point(0,radius);
        /// To avoid any floating point calculations, we multiply everything with 4
        double d = 1 - radius;
        int deltaE = 3;
        int deltaSE = -2*radius + 5;

        draw_circle(current);
        while(current.y > current.x) {
            if(d < 0) {
                d += deltaE;
                deltaE += 2;
                deltaSE += 2;
            } else {
                d += deltaSE;
                deltaE += 2;
                deltaSE += 4;
                current.y = current.y - 1;
            } current.x = current.x + 1;

            /// 8 way symmetry to draw the entire circle
            draw_circle(Point(current.x,current.y));
            draw_circle(Point(current.x,-current.y));
            draw_circle(Point(-current.x,-current.y));
            draw_circle(Point(-current.x,current.y));
            draw_circle(Point(current.y, current.x));
            draw_circle(Point(-current.y,current.x));
            draw_circle(Point(-current.y,-current.x));
            draw_circle(Point(current.y,-current.x));
        }
    }
};
#endif
