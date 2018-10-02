#include "Tetragon.h"
#include <iostream>
using std::cout;
Tetragon::Tetragon()
{
	for (int i = 0; i < 4; ++i)
		points[i].x = points[i].y = 0;
}

double Tetragon::size_of_side(Tpoint a, Tpoint b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void Tetragon::set_points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	points[0].x = x1;
	points[1].x = x2;
	points[2].x = x3;
	points[3].x = x4;
	points[0].y = y1;
	points[1].y = y2;
	points[2].y = y3;
	points[3].y = y4;
	side[0] = size_of_side(points[0], points[1]);
	side[1] = size_of_side(points[1], points[2]);
	side[2] = size_of_side(points[2], points[3]);
	side[3] = size_of_side(points[3], points[0]);
}

void Tetragon::set_points(pair<double, double> p[4])
{
	for (int i = 0; i < 4; ++i) {
		points[i].x = p[i].first;
		points[i].y = p[i].second;
		side[i] = size_of_side(points[i], points[(i + 1) % 4]);
	}
}

Tetragon::Tetragon(int x1, int y1, int x2, int y2, int x3, int y3, int x4,int y4)
{
	set_points(x1, y1, x2, y2, x3, y3, x4, y4);
}
Tetragon::Tetragon(pair<double, double> p[4])
{
	set_points(p);
}

double Tetragon::square()
{
	double p = (side[0] + side[1] + side[2] + side[3]) / 2;
	return sqrt((p - side[0])*(p - side[1])*(p - side[2])*(p-side[3]));
}

double Tetragon::perimetr()
{
	return side[0] + side[1] + side[2] + side[3];
}

double Tetragon::angle(int x)
{
	return (points[(x + 3) % 4].x - points[x].x)*(points[(x + 1) % 4].x - points[x].x) +
		(points[(x + 3) % 4].y - points[x].y)*(points[(x + 1) % 4].y - points[x].y)/(side[x]*side[(x+1)%4]);
}

string Tetragon::regular()
{
	if (side[1] + side[2] + side[3] == side[0] ||
		side[2] + side[3] + side[0] == side[1] ||
		side[3] + side[0] + side[1] == side[2] ||
		side[0] + side[1] + side[2] == side[3])
		return "Degenerated";
	else if (side[0] == side[1] && side[1] == side[2] && side[2] == side[3]) {
		if (angle(0) == angle(1))
			return "Square";
		else
			return "Rhombus";
	}
	else if (side[0] == side[2] && side[1] == side[3]) {
		if (angle(1) == 0)
			return "Rectangle";
		else
			return "Parallelogram";
	}
	else if (angle(3) == -angle(4) && angle(1) == -angle(2) ||
		angle(2) == -angle(3) && angle(0) == -angle(1))
		return "Trapezoid";
//	cout << angle(0) << ' ' << angle(1) << ' ' << angle(2) << ' ' << angle(3) << '\n';
	return "Other";
}


Tetragon::~Tetragon()
{
}
