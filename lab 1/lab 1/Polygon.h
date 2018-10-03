#pragma once
#include <string>
#include <cmath>
#include <iostream>
#include <ctime>
#include <random>

struct Tpoint { double x, y; };

using std::string;
using std::pair;
using std::cout;
using std::ostream;
using std::istream;

class Polygon
{
protected:
	const double eps = 0.00001;
public:
	virtual double square() = 0;
	virtual double perimetr() = 0;
	virtual string regular() = 0;
	virtual void my_rand() = 0;
};
