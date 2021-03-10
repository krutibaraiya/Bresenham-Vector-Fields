#include <bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"
#include "BresenhamLine.h"
using namespace std;
using namespace std::chrono;

/**
 * Structure to measure the running time of the algorithm
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
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);


}
/**
 * Method to display the line vector field
 */
void myDisplay() {
    Timer timer("Vector Field");
    glClear(GL_COLOR_BUFFER_BIT);
    //glViewport(200,200,GLsizei(1000), GLsizei(1000));
    for(int i = -250; i < 250; i+=50) {
        for(int j = -250; j < 250; j+=50) {
            BresenhamLine bresenhamLine = BresenhamLine(Point(i,j),Point(i + ((i)) ,j  +((j))));
            bresenhamLine.draw_line();
        }
    }
    glFlush();
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main(int argc, char **argv) {

    /// Initialising window and running the vector field drawing algorithm
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(-500, -500);
    glutCreateWindow("Vector Field visualization");
    glutDisplayFunc(myDisplay);
    myInit();


    glutMainLoop();
}
