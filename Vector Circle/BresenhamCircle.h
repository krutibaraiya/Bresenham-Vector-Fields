#ifndef BRESENHAM_CIRCLE
#define BRESENHAM_CIRCLE

#include<bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"

using namespace std;

class BresenhamCircle {
private:
    Point center;
    int radius;

    void draw_circle(Point point) {
        glColor3f(1,0,0);
        glPointSize(0);
        glBegin(GL_POINTS);
        glVertex2i(center.x + point.x, center.y + point.y);
        glEnd();
    }

public:

    BresenhamCircle(Point Center, int Radius) {
        center = Center;
        radius = Radius;
    }

    void MidPointCircle() {
        Point current = Point(0,radius);
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
