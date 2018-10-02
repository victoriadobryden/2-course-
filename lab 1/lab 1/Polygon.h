#pragma once
#include <string>
#include <cmath>
#include <iostream>

struct Tpoint { double x, y; };

using std::string;
using std::pair;
using std::cout;
using std::ostream;

class Polygon
{
public:
	virtual double square() = 0;
	virtual double perimetr() = 0;
	virtual string regular() = 0;
};
