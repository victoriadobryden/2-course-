#include "Triangle.h"



Triangle::Triangle()
{
	for (int i = 0; i < 3; ++i)
		points[i].x = points[i].y = 0;
}

void Triangle::set_points(double x1, double y1, double x2, double y2, double x3, double y3)
{
	points[0].x = x1;
	points[1].x = x2;
	points[2].x = x3;
	points[0].y = y1;
	points[1].y = y2;
	points[2].y = y3;
	for (int i = 0; i < 3; ++i)
		side[i] = size_of_side(points[i], points[(i + 1) % 3]);
}

void Triangle::set_points(pair<double, double> p[3])
{
	for (int i = 0; i < 3; ++i) {
		points[i].x = p[i].first;
		points[i].y = p[i].second;
		side[i] = size_of_side(points[i], points[(i+1)%3]);
	}
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	set_points(x1, y1, x2, y2, x3, y3);
}
Triangle::Triangle(pair<double, double> p[3])
{
	set_points(p);
}

double Triangle::square()
{
	double p = (side[0] + side[1] + side[2]) / 2;
	return sqrt(p*(p - side[0])*(p - side[1])*(p - side[2]));
}

double Triangle::perimetr()
{
	return side[0] + side[1] + side[2];
}

double Triangle::size_of_side(Tpoint a, Tpoint b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool Triangle::check_for_90(int x)
{
	if ((points[(x + 2) % 3].x - points[x].x)*(points[(x + 1) % 3].x - points[x].x) +
		(points[(x + 2) % 3].y - points[x].y)*(points[(x + 1) % 3].y - points[x].y) == 0)
		return 1;
	return 0;
}

string Triangle::regular()
{
	if (side[1] + side[2] == side[0] ||
		side[2] + side[0] == side[1] ||
		side[0] + side[1] == side[2])
		return "Degenerated";
	else if (side[0] == side[1] && side[1] == side[2])
		return "Equilateral";
	else if (side[0] == side[1] && check_for_90(1) ||
		side[1] == side[2] && check_for_90(2) ||
		side[2] == side[0] && check_for_90(0) == 0)
		return "Isosceles Right";
	else if (side[0] == side[1] || side[1] == side[2] || side[2] == side[0])
		return "Isosceles";
	else if (check_for_90(0) || check_for_90(1) || check_for_90(2))
		return "Right";
	else 
		return "Simple";
}


ostream & operator<<(ostream & os, const Triangle * value)
{
	os << "( " << value->points[0].x << ";" << value->points[0].y << " )";
	for (int i = 1; i < 3; ++i)
		os << ",( " << value->points[i].x << ";" << value->points[i].y << " )";
	return os;
}


Triangle::~Triangle()
{
}