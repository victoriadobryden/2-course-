#pragma once
#include <vector>

using namespace std;

template<typename T>
struct Tvertex{
	T value;
	vector<Tvertex *> neighbours;
};

template<typename T>
class Graph
{
	vector<Tvertex<T> *> vertex;
	int length;
public:
	Graph();
	Graph(int n);
	~Graph();
};

template<typename T>
Graph<T>::Graph()
{
	vertex.clear();
	length = 0;
}

template<typename T>
Graph<T>::Graph(int n)
{
	vertex.resize(n);
	length = n;
}

template<typename T>
Graph<T>::~Graph()
{
	for (int i = 0; i < length; ++i)
		delete vertex[i];
	vertex.clear();
}