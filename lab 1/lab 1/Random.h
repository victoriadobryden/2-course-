#pragma once
#include "Triangle.h"
#include "Tetragon.h"
#include "Pentagon.h"

#include <random>
#include <string>
#include <vector>

using std::string;
using std::vector;

template<typename T>
T getrandom(T value);

template<>
int getrandom(int value)
{
	return rand() % 200 - 100;
}

template<>
double getrandom(double value)
{
	return (double)rand() / RAND_MAX * 200.0 - 100;
}

template<>
string getrandom(string value)
{
	int len = rand()%30;
	value = "";
	for (int i = 0; i < len; ++i)
	{
		char c = rand() % 26+'a';
		value += c;
	}
	return value;
}

template<>
Triangle getrandom(Triangle value)
{
	value.my_rand();
	return value;
}

template<>
Tetragon getrandom(Tetragon value)
{
	value.my_rand();
	return value;
}

template<>
Pentagon getrandom(Pentagon value)
{
	value.my_rand();
	return value;
}

template<typename T>
vector<T> getrandom(vector<T> value)
{
	int len = rand() % 30;
	value.clear();
	for (int i = 0; i < len; ++i)
	{
		T cur;
		cur = getrandom(cur);
		value.push_back(cur);
	}
	return value;
}



