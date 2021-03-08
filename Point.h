#ifndef POINT
#define POINT

#include<bits/stdc++.h>

using namespace std;

struct Point {
	int x;
	int y;


	Point() {
		x = 0;
		y = 0;
	}

	Point(int x, int y) {
		this -> x = x;
		this -> y = y;
	}

	void operator = (const Point &p) {
		x = p.x;
		y = p.y;
	}

	Point operator + (const Point &p) {
		return Point(x + p.x, y + p.y);
	}

	Point operator - (const Point &p) {
		return Point (x - p.x, y - p.y);
	}

	bool operator == (const Point &p) {
		return ((x == p.x) && (y == p.y));
	}

	bool operator != (const Point &p) {
		return ((x != p.x) || (y != p.y));
	}
};

#endif
