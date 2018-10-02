#pragma once
#include <vector>

using std::vector;
using std::cout;
using std::pair;

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
public:
	Graph();
	Graph(int n);
	void add_vertex(vector<pair<int, T> > neigb);
	void add_edge(int index1, int index2, T value);
	void output();
	int size_gr();
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
void Graph<T>::add_vertex(vector<pair<int, T> > neighb)
{
	Tvertex<T> *new_vertex = new Tvertex<T>(length);
	cout << length << '\n';
	++length;
	for (size_t i = 0; i < neighb.size(); ++i)	
	{
		cout << neighb[i].first << ' ';
		new_vertex->neighbours.push_back({vertex[neighb[i].first], neighb[i].second});
		vertex[neighb[i].first]->neighbours.push_back({ new_vertex, neighb[i].second});
	}
	cout << '\n';
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
void Graph<T>::output()
{
	cout << "Size of graph: " << length << "\n";
	for (int i = 0; i < length; ++i)
	{
		cout << "Vertex #" << i << ", neighbours: ";
		for (size_t j = 0;j < vertex[i]->neighbours.size(); ++j)
			cout << "{ " << vertex[i]->neighbours[j].first->ind << ',' << vertex[i]->neighbours[j].second << " } ";
		cout << '\n';
	}
}

template<typename T>
int Graph<T>::size_gr()
{
	return length;
}

template<typename T>
Graph<T>::~Graph()
{
	for (int i = 0; i < length; ++i)
		delete vertex[i];
	vertex.clear();
}