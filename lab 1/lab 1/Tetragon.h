#pragma once
#include "Polygon.h"

class Tetragon : public Polygon
{
	Tpoint points[4];
	double side[4];
	double angle(int x);
	double size_of_side(Tpoint a, Tpoint b);
public:
	Tetragon();
	Tetragon(pair<double, double> p[4]);
	Tetragon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	void set_points(pair<double, double> p[4]);
	void set_points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	double square();
	double perimetr();
	string regular();
	~Tetragon();
};

