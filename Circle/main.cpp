#include <GL/glut.h>
#include <bits/stdc++.h>
#include "../Point.h"
#include "BresenhamCircle.h"

using namespace std;
using namespace std::chrono;

struct Timer {
    string name{""};
    time_point<high_resolution_clock> end, start{high_resolution_clock::now()};
    duration<float, std::milli> duration;
    Timer() = default;
    Timer(string name): name(name) {}
    ~Timer() {
        end = high_resolution_clock::now(); duration = end - start;
        cout << "@" << name << "> " << duration.count() << " ms" << '\n';
    }
};

Point center;
int radius;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}


void myDisplay() {
	Timer timer("Circle Drawing");
    glClear(GL_COLOR_BUFFER_BIT);
    BresenhamCircle midPointCircle = BresenhamCircle(center,radius);
    midPointCircle.MidPointCircle();
    glFlush();
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main(int argc, char **argv) {

    cout << "Enter the x coordinate of the center" << endl;
    cin >> center.x;

    cout << "Enter the y coordinate of the center" << endl;
    cin >> center.y;

    cout << "Enter the radius of the circle" << endl;
    cin >> radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(-500, 500);
    glutCreateWindow("Bresenham's Circle Drawing");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
