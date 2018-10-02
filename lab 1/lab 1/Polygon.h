#pragma once
#include <string>

struct Tpoint { double x, y; };

using std::string;

class Polygon
{
public:
	virtual long square() = 0;
	virtual long perimetr() = 0;
	virtual string regular() = 0;
};


