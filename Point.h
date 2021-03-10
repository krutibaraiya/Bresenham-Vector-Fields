#ifndef POINT
#define POINT

#include<bits/stdc++.h>

using namespace std;

/*
 * Structure to represent a point
 */
struct Point {
	int x;   //!< The x coordinate of the point
	int y;   //!< The y coordinate of the point

/**
 * Constructor for Point class
 * Initialize x and y to 0
 */
	Point() {
		x = 0;
		y = 0;
	}
/**
 * Parameterized constructor of Point Class
 * @param x The x coordinate of the point
 * @param y The y coordinate of the point
 */
	Point(int x, int y) {
		this -> x = x;
		this -> y = y;
	}
/**
 * Assignment operator overloaded for Point class
 * @param p The point to be assigned
 */
	void operator = (const Point &p) {
		x = p.x;
		y = p.y;
	}
/**
 * Addition operator overloaded for Point class
 * @param p The point to be added
 * @return A point after the coordinates are added
 */
	Point operator + (const Point &p) {
		return Point(x + p.x, y + p.y);
	}
/**
 * Subtraction operator overloaded for Point class
 * @param p The point to be subtracted
 * @return A point after the coordinates are subtracted
 */
	Point operator - (const Point &p) {
		return Point (x - p.x, y - p.y);
	}
/**
 * Equality operator overloaded for Point class
 * @param p The point to be compared
 * @return True, if points are equal else False
 */
	bool operator == (const Point &p) {
		return ((x == p.x) && (y == p.y));
	}
/**
 * Inequality operator overloaded for Point class
 * @param p The point to be compared
 * @return True, if points are not equal else False
 */
	bool operator != (const Point &p) {
		return ((x != p.x) || (y != p.y));
	}
};

#endif
