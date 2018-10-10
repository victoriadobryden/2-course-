#pragma once
#include "Polygon.h"

class Pentagon :
	public Polygon
{
	Polygon::eps;
	Polygon::points;
	Polygon::side;
	double size_of_side(Tpoint a, Tpoint b);
	double angle(int x);
	bool crossed_line(int x, int w);
	bool point_in_line_segment(int x, Tpoint p);
public:
	Pentagon();
	Pentagon(pair<double, double> p[5]);
	Pentagon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5);
	void set_points(pair<double, double> p[5]);
	void set_points(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5);
	double square();
	double perimetr();
	string regular();
	void my_rand();
	friend ostream& operator<<(ostream& os, const Pentagon& value);
	friend istream& operator>>(istream& is, Pentagon& value);
	~Pentagon();
};

