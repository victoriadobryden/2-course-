#pragma once
#include <vector>
#include <iostream>
#include "Polygon.h"

using std::vector;
using std::cout;
using std::pair;



///for vector
template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
	int n;
	is >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		is >> v[i];
	return is;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "( ";
	if (v.size() != 0)
		os << v[0];
	for (size_t i = 1; i < v.size(); ++i)
		os << ', ' << v[i];
	os << " )";
	return os;
}


template<typename T>
struct Tvertex{
	int ind;
	vector<pair<Tvertex *, T> > neighbours;
	Tvertex(int index);
};

template<typename T>
Tvertex<T>::Tvertex(int index)
{
	ind = index;
}


template<typename T>
class Graph
{
protected:
	vector<Tvertex<T> *> vertex;
	int length;
	template<typename T1>
	void help_output(T value);
public:
	Graph();
	Graph(int n);
	void add_vertex(vector<pair<int, T> > neigb);
	void add_edge(int index1, int index2, T value);
	void output();
	int size_gr();
	vector<Tvertex<T> *> vertexes();
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
	vertex.clear();
	length = n;
	for (int i = 0; i < n; ++i) {
		Tvertex<T> *cur = new Tvertex<T>(i);
		vertex.push_back(cur);
	}
}

template<typename T>
void Graph<T>::add_vertex(vector<pair<int, T> > neighb)
{
	Tvertex<T> *new_vertex = new Tvertex<T>(length);
	++length;
	for (size_t i = 0; i < neighb.size(); ++i)	
	{
		new_vertex->neighbours.push_back({vertex[neighb[i].first], neighb[i].second});
		vertex[neighb[i].first]->neighbours.push_back({ new_vertex, neighb[i].second});
	}
	vertex.push_back(new_vertex);
}

template<typename T>
void Graph<T>::add_edge(int index1, int index2, T value) 
{
	vector<pair<Tvertex<T> *,T> > vert1 = vertex[index1]->neighbours;
	bool flag = true;
	for (size_t i = 0;i < vert1.size(); ++i)
		if (vert1[i].first->ind == index2)
		{
			flag = false;
			break;
		}
	if (flag)
	{
		if (index1 != index2) {
			vertex[index1]->neighbours.push_back({ vertex[index2], value });
			vertex[index2]->neighbours.push_back({ vertex[index1], value });
		}
		else
			vertex[index1]->neighbours.push_back({ vertex[index2], value });
	}
}

template<typename T>
template<typename T1>
void Graph<T>::help_output(T value)
{
	if (typeid(T) == typeid(vector<T1>))
	{
		cout << "(";
		for (int i = 0; i < value.size(); ++i)
			cout << value[i] << ' ';
		cout << ")";
	}
	else 
		cout << value;
}

template<typename T>
void Graph<T>::output()
{
	if (length == 0) {
		cout << "Graph is empty!!! Fill it, please.)";
		return;
	}
	cout << "Size of graph: " << length << "\n";
	for (int i = 0; i < length; ++i)
	{
		cout << "Vertex #" << i << ", neighbours: ";
		for (size_t j = 0; j < vertex[i]->neighbours.size(); ++j) {
			cout << "{ " << vertex[i]->neighbours[j].first->ind << ';';
			help_output(vertex[i]->neighbours[j].second);
			cout << " } ";
		}
		cout << '\n';
	}
}

template<typename T>
int Graph<T>::size_gr()
{
	return length;
}

template<typename T>
vector<Tvertex<T> *> Graph<T>::vertexes()
{
	vector<Tvertex<T> *> temp;
	for (size_t i = 0;i < vertex.size(); ++i)
	{
		Tvertex<T> *cur = new Tvertex<T>(i);
		for (size_t j = 0; j < vertex[i]->neighbours.size(); ++j)
		{
			size_t to = vertex[i]->neighbours[j].first->ind;
			T val = vertex[i]->neighbours[j].second;
			if (to < i)
			{
				cur->neighbours.push_back({ temp[to],val });
				temp[to]->neighbours.push_back({ cur,val });
			}
			else if (to == i)
				cur->neighbours.push_back({ cur,val });

		}
		temp.push_back(cur);
	}
	return temp;
}

template<typename T>
Graph<T>::~Graph()
{
	for (size_t i = 0; i < vertex.size(); ++i)
		delete vertex[i];
	vertex.clear();
}

