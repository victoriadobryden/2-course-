#pragma once
#include "Polygon.h"
#include <cmath>
using std::pair;

class Triangle: public Polygon
{
	Tpoint points[3];
	double side[3];
	double size_of_side(Tpoint a, Tpoint b);
public:
	Triangle();
	Triangle(pair<double, double> p[3]);
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	void set_points(pair<double, double> p[3]);
	void set_points(int x1, int y1, int x2, int y2, int x3, int y3);
	double square();
	double perimetr();
	string regular();
	~Triangle();
};

