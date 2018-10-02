#include "Pentagon.h"
#include "Tetragon.h"
#include "Triangle.h"

using namespace std;


Pentagon::Pentagon()
{
	for (int i = 0; i < 5; ++i)
		points[i].x = points[i].y = 0;
}

double Pentagon::size_of_side(Tpoint a, Tpoint b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void Pentagon::set_points(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5)
{
	points[0].x = x1; points[1].x = x2; points[2].x = x3; points[3].x = x4; points[4].x = x5;
	points[0].y = y1; points[1].y = y2; points[2].y = y3; points[3].y = y4;	points[4].y = y5; 
	for (int i = 0; i < 5; ++i) 
		side[i] = size_of_side(points[i], points[(i + 1) % 5]);
}

void Pentagon::set_points(pair<double, double> p[5])
{
	for (int i = 0; i < 5; ++i) {
		points[i].x = p[i].first;
		points[i].y = p[i].second;
		side[i] = size_of_side(points[i], points[(i + 1) % 5]);
	}
}

Pentagon::Pentagon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5,double y5)
{
	set_points(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5);
}
Pentagon::Pentagon(pair<double, double> p[5])
{
	set_points(p);
}

double Pentagon::square()
{
	Triangle *A = new Triangle(points[0].x, points[0].y, points[1].x, points[1].y, points[2].x, points[2].y);
	Tetragon *B = new Tetragon(points[2].x, points[2].y, points[3].x, points[3].y, points[4].x, points[4].y,
								points[0].x, points[0].y);
	double ans = A->square() + B->square();
	delete A;
	delete B;
	return ans;
}

double Pentagon::perimetr()
{
	return side[0] + side[1] + side[2] + side[3] + side[4];
}

double Pentagon::angle(int x)
{
	return (points[(x + 4) % 5].x - points[x].x)*(points[(x + 1) % 5].x - points[x].x) +
		(points[(x + 4) % 5].y - points[x].y)*(points[(x + 1) % 5].y - points[x].y) / (side[x] * side[(x + 4) % 5]);
}

string Pentagon::regular()
{
	if (side[0] == side[1] && side[1] == side[2] && side[2] == side[3] &&
		angle(0) == angle(1) && angle(1) == angle(2) && angle(2) == angle(3) &&
		angle(3) == angle(4))
		return "Convex";
	else 
		return "Other";
}

Pentagon::~Pentagon()
{
}

ostream & operator<<(ostream & os, const Pentagon *value)
{
	os << "( " << value->points[0].x << ";" << value->points[0].y << " )";
	for (int i = 1; i < 5; ++i)
		os << ",( " << value->points[i].x << ";" << value->points[i].y << " )";
	return os;
}
