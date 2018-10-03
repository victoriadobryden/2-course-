#pragma once
#include "Polygon.h"

class Triangle: public Polygon
{
	Tpoint points[3];
	double side[3];
	double size_of_side(Tpoint a, Tpoint b);
	bool check_for_90(int x);
	Polygon::eps;
public:
	Triangle();
	Triangle(pair<double, double> p[3]);
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
	void set_points(pair<double, double> p[3]);
	void set_points(double x1, double y1, double x2, double y2, double x3, double y3);
	double square();
	double perimetr();
	string regular();
	void my_rand();
	friend ostream& operator<<(ostream& os, const Triangle& value);
	friend istream& operator>>(istream& is, Triangle& value);
	~Triangle();
};

