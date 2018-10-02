#include "Triangle.h"



Triangle::Triangle()
{
	for (int i = 0; i < 3; ++i)
		points[i].x = points[i].y = 0;
}

double Triangle::size_of_side(Tpoint a, Tpoint b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void Triangle::set_points(int x1, int y1, int x2, int y2, int x3, int y3)
{
	points[0].x = x1;
	points[1].x = x2;
	points[2].x = x3;
	points[0].y = y1;
	points[1].y = y2;
	points[2].y = y3;
	side[0] = size_of_side(points[0], points[1]);
	side[1] = size_of_side(points[1], points[2]);
	side[2] = size_of_side(points[2], points[0]);
}

void Triangle::set_points(pair<double, double> p[3])
{
	for (int i = 0; i < 3; ++i) {
		points[i].x = p[i].first;
		points[i].y = p[i].second;
		side[i] = size_of_side(points[i], points[(i+1)%3]);
	}
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
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

bool Triangle::check_for_90(int x)
{
	if ((points[(x + 2) % 3].x - points[x].x)*(points[(x + 1) % 3].x - points[x].x) +
		(points[(x + 2) % 3].x - points[x].x)*(points[(x + 1) % 3].x - points[x].x) == 0)
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

Triangle::~Triangle()
{
}
