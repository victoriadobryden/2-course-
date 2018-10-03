#pragma once
#include "Polygon.h"

class Tetragon : public Polygon
{
	Polygon::eps;
	Tpoint points[4];
	double side[4];
	double angle(int x);
	double size_of_side(Tpoint a, Tpoint b);
	bool point_in_line_segment(int x, Tpoint p);
	bool crossed_line(int x, int w);
public:
	Tetragon();
	Tetragon(pair<double, double> p[4]);
	Tetragon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
	void set_points(pair<double, double> p[4]);
	void set_points(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
	double square();
	double perimetr();
	string regular();
	void my_rand();
	friend ostream& operator<<(ostream& os, const Tetragon* value);
	friend istream& operator>>(istream& is, Tetragon* value);
	~Tetragon();
};

