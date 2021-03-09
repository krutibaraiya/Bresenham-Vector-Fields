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

Point Start, End;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void myDisplay() {
	Timer timer("Line Drawing");
    glClear(GL_COLOR_BUFFER_BIT);
    BresenhamLine bresenhamLine = BresenhamLine(Start, End);
    bresenhamLine.draw_line();
    glFlush();
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main(int argc, char **argv) {


    cout << "Enter the x coordinate of the starting point" << endl;
    cin >> Start.x;
    cout << "Enter the y coordinate of the starting point" << endl;
    cin >> Start.y;
    cout << "Enter the x coordinate of the ending point" << endl;
    cin >> End.x;
    cout << "Enter the y coordinate of the ending point" << endl;
    cin >> End.y;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(-500, -550);
    glutCreateWindow("Bresenham's Line Drawing");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
