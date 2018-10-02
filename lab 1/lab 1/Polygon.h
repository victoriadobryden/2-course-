#pragma once
#include <string>

struct Tpoint { double x, y; };

using std::string;

class Polygon
{
public:
	virtual double square() = 0;
	virtual double perimetr() = 0;
	virtual string regular() = 0;
};


