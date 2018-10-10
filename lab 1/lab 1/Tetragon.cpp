#include "Tetragon.h"

Tetragon::Tetragon()
{
	for (int i = 0; i < 4; ++i)
		points[i].x = points[i].y = 0;
}

double Tetragon::size_of_side(Tpoint a, Tpoint b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void Tetragon::set_points(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	points[0].x = x1;
	points[1].x = x2;
	points[2].x = x3;
	points[3].x = x4;
	points[0].y = y1;
	points[1].y = y2;
	points[2].y = y3;
	points[3].y = y4;
	for (int i = 0; i < 4; ++i)
		side[i] = size_of_side(points[i], points[(i + 1) % 4]);
}

void Tetragon::set_points(pair<double, double> p[4])
{
	for (int i = 0; i < 4; ++i) {
		points[i].x = p[i].first;
		points[i].y = p[i].second;
	}
	for (int i = 0;i < 4; ++i)
		side[i] = size_of_side(points[i], points[(i + 1) % 4]);
}

Tetragon::Tetragon(double x1, double y1, double x2, double y2, double x3, double y3, double x4,double y4)
{
	set_points(x1, y1, x2, y2, x3, y3, x4, y4);
}
Tetragon::Tetragon(pair<double, double> p[4])
{
	set_points(p);
}

double Tetragon::square()
{
	double sum = 0;
	for (int i = 0; i < 4; ++i)
		sum += points[i].x*points[(i + 1) % 4].y - points[i].y * points[(i + 1) % 4].x;
	return abs(0.5*sum);
}

double Tetragon::perimetr()
{
	return side[0] + side[1] + side[2] + side[3];
}

double Tetragon::angle(int x)
{
	return (points[(x + 3) % 4].x - points[x].x)*(points[(x + 1) % 4].x - points[x].x) +
		(points[(x + 3) % 4].y - points[x].y)*(points[(x + 1) % 4].y - points[x].y)/(side[x]*side[(x+3)%4]);
}

string Tetragon::regular()
{
	if (abs(side[1] + side[2] + side[3] - side[0] < eps) ||
		abs(side[2] + side[3] + side[0] - side[1] < eps) ||
		abs(side[3] + side[0] + side[1] - side[2] < eps)||
		abs(side[0] + side[1] + side[2] - side[3] < eps))
		return "Degenerated";
	else if (abs(side[0] - side[1]) < eps && abs(side[1] - side[2]) < eps && abs(side[2] - side[3]) < eps)
	{
		if (abs(angle(0) - angle(1)) < eps)
			return "Square";
		else
			return "Rhombus";
	}
	else if (abs(side[0] - side[2]) < eps &&  abs(side[1] - side[3]) < eps)
	{
		if (abs(angle(1)) < eps)
			return "Rectangle";
		else
			return "Parallelogram";
	}
	else if (abs(angle(3) + angle(4)) < eps && abs(angle(1) + angle(2)) < eps ||
		abs(angle(2) + angle(3)) < eps && abs(angle(0) + angle(1)) < eps)
		return "Trapezoid";
	return "Other";
}


bool Tetragon::point_in_line_segment(int x, Tpoint p)
{
	return (points[x].x <= p.x && p.x <= points[(x + 1) % 5].x ||
		points[(x + 1) % 5].x <= p.x && p.x <= points[x].x) &&
		(points[x].y <= p.y && p.y <= points[(x + 1) % 5].y ||
			points[(x + 1) % 5].y <= p.y && p.y <= points[x].y);
}

bool Tetragon::crossed_line(int x, int w)
{
	Tpoint temp;
	double a1 = (points[(x + 1) % 5].y - points[x].y), b1 = (points[x].x - points[(x + 1) % 5].x), c1 = -a1 * points[x].x - b1 * points[x].y;
	double a2 = (points[(w + 1) % 5].y - points[w].y), b2 = (points[w].x - points[(w + 1) % 5].x), c2 = -a2 * points[w].x - b2 * points[w].y;
	temp.x = (b2*c1 - b1 * c2) / (a2*b1 - a1 * b2);
	temp.y = (b1 != 0 ? (-a1 * temp.x - c1) / b1 : (-a2 * temp.x - c2) / b2);
	return point_in_line_segment(x, temp) && point_in_line_segment(w, temp);
}

void Tetragon::my_rand()
{
	for (int i = 0; i < 4; ++i) 
	{
		points[i].x = (double)rand() / RAND_MAX * 100.0;
		points[i].y = (double)rand() / RAND_MAX * 100.0;
	}
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (j == i || j == (i + 1) % 4 || j == (i + 3) % 4)
					continue;
				if (crossed_line(i, j))
				{
					points[(j + 1) % 4].x = (double)rand() / RAND_MAX * 100.0;
					points[(j + 1) % 4].y = (double)rand() / RAND_MAX * 100.0;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
	}
	for (int i = 0; i < 4; ++i)
		side[i] = size_of_side(points[i], points[(i + 1) % 4]);
}


Tetragon::~Tetragon()
{
}

ostream & operator<<(ostream & os, const Tetragon & value)
{
	os << "( " << value.points[0].x << ";" << value.points[0].y << " )";
	for (int i = 1; i < 4; ++i)
		os << ",( " << value.points[i].x << ";" << value.points[i].y << " )";
	return os;
}

istream & operator>>(istream & is, Tetragon & value)
{
	for (int i = 0; i < 4; ++i)
		is >> value.points[i].x >> value.points[i].y;
	for (int i = 0; i < 4; ++i)
		value.side[i] = value.size_of_side(value.points[i], value.points[(i + 1) % 4]);
	return is;
}
