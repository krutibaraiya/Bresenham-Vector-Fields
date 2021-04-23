# Assignment-1
Visualisation of 2D Vector fields using Bresenham's algorithms

Course Assignment for IS F311- Computer Graphics @ BITS Pilani, Hyderabad Campus.

## Objective:
* Implementing Bresenham's midpoint line and circle algorithm.
* To make a crude visualisation of vector fields made using Bresenham's lines and circles.
* To try out different samplings of the 2D space and record the results.

## Vector fields:
![Vector field using Bresenham's lines](https://github.com/krutibaraiya/Graphics-Assignment-1/blob/master/images/j-ismall.PNG)

![Vector field using Bresenham's circle](https://github.com/krutibaraiya/Graphics-Assignment-1/blob/master/images/circlejinew.PNG)

[More images..](https://github.com/krutibaraiya/Graphics-Assignment-1/tree/master/images)

[HTML documentation of the experiments](https://github.com/krutibaraiya/Graphics-Assignment-1/tree/master/Result%20pages)

[Doxygen documentation](https://github.com/krutibaraiya/Graphics-Assignment-1/tree/master/html)

## How to run:
* The project is tested on Linux and built in C++ using the following libraries:
    * `GL`
    * `GLUT`
    * `CMake`
* To build : `g++ <main>.cpp -lGL -lglut -lGLU`
* Run the output executable : `./a.out`


## Challenges faced:
* For non-linear input functions, the vector field takes time to render on the screen.
* For polynomial functions with higher degree the contraints need to be changed accordingly to render the output in lesser time.
* For sine and cosine functions the algorithm rounds values to integers -1,0,1.
* It may round the values of center and radius depending upon the function

## Team members:
* [Jay Patel](https://github.com/pjay20301)
* [Kruti Baraiya](https://github.com/krutibaraiya)
* [Sristi Sharma](https://github.com/judyhopps24)

