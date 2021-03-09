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
void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.412, 0.412, 0.412,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void myDisplay() {
	Timer timer("Vector Circle");
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = -1000; i < 1000; i+=50) {
        for(int j = -1000; j < 1000; j+=50) {
        	
            BresenhamCircle midPointCircle = BresenhamCircle(Point((i+j)/2,(j+i)/2),sqrt(2*(i*i + j*j)));
            midPointCircle.MidPointCircle();
        }
    }
    glFlush();
    this_thread::sleep_for(chrono::milliseconds(100));
}


int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(-500, 500);
    glutCreateWindow("Vector Circle Visualization");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
