#include <GL/glut.h>
#include <bits/stdc++.h>
#include "../Point.h"
#include "BresenhamCircle.h"

using namespace std;
using namespace std::chrono;

/**
 * Structure to measure the running time of algorithm
 */
struct Timer {
    string name{""};
    time_point<high_resolution_clock> end, start{high_resolution_clock::now()};
    std::chrono::duration<float, std::milli> duration;
    Timer() = default;
    Timer(string name): name(name) {}
    ~Timer() {
        end = high_resolution_clock::now(); duration = end - start;
        cout << "@" << name << "> " << duration.count() << " ms" << '\n';
    }
};

/**
 * Method to initialise the window
 */
void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0.4,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}
/**
 * Method to display the vector field using circle
 */
void myDisplay() {
    Timer timer("Vector Circle");
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(200,200,GLsizei(1000), GLsizei(1000));
    for(int i = -500; i < 500; i+=50) {
        for(int j = -500; j < 500; j+=50) {

            BresenhamCircle midPointCircle = BresenhamCircle(Point((i+(j*j))/2,(j+(i*i))/2),(sqrt(2*(i*i + j*j))));
            midPointCircle.MidPointCircle();
        }
    }
    glFlush();
    this_thread::sleep_for(chrono::milliseconds(100));
}


int main(int argc, char **argv) {

    /// Initialising window and running line drawing algorithm
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(-500, 500);
    glutCreateWindow("Vector Circle Visualization");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
