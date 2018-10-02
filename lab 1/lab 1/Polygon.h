#pragma once
#include <string>
#include <cmath>

struct Tpoint { double x, y; };

using std::string;
using std::pair;

class Polygon
{
public:
	virtual double square() = 0;
	virtual double perimetr() = 0;
	virtual string regular() = 0;
};
