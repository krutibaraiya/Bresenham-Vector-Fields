#include <bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"
#include "BresenhamLine.h"
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
 


void myInit() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 250, -250, 250);
}

void myDisplay() {
    Timer timer("Vector Field");
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = -1000; i < 1000; i+=20) {
        for(int j = -1000; j < 1000; j+=20) {
            BresenhamLine bresenhamLine = BresenhamLine(Point(i,j),Point(i + j ,j  + i ));
            bresenhamLine.draw_line();
        }
    }
    glFlush();
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main(int argc, char **argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(-500, -500);
    glutCreateWindow("Vector Field visualization");
    glutDisplayFunc(myDisplay);
    myInit();


    glutMainLoop();
}
