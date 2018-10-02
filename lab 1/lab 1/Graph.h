#pragma once
#include <vector>

using std::vector;
using std::cout;

template<typename T>
struct Tvertex{
	T value; 
	int ind;
	vector<Tvertex *> neighbours;
	Tvertex(T n,int index);
};

template<typename T>
Tvertex<T>::Tvertex(T n, int index)
{
	value = n;
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
	void add_vertex(T value, vector<int> neigbours);
	void add_edge(int index1, int index2);
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
void Graph<T>::add_vertex(T value, vector<int> neighb)
{
	Tvertex<T> *new_vertex = new Tvertex<T>(value,length);
	++length;
	cout << value << '\n';
	for (size_t i = 0; i < neighb.size(); ++i)	
	{
		cout << neighb[i] << ' ';
		new_vertex->neighbours.push_back(vertex[neighb[i]]);
		vertex[neighb[i]]->neighbours.push_back(new_vertex);
	}
	cout << '\n';
	vertex.push_back(new_vertex);
}

template<typename T>
void Graph<T>::add_edge(int index1, int index2) 
{
	vector<Tvertex<T> *> vert1 = vertex[index1]->neighbours, *vert2 = vertex[index2]->neigbours;
	bool flag = true;
	for (int i = 0;i < vert1.size(); ++i)
		if (vert1[i]->ind == index2)
		{
			flag = false;
			break;
		}
	if (flag)
	{
		vertex[index1]->neighbours.push_back(vertex[index2]);
		vertex[index2]->neighbours.push_back(vertex[index1]);
	}
}

template<typename T>
void Graph<T>::output()
{
	cout << "Size of graph: " << length << "\n";
	for (int i = 0; i < length; ++i)
	{
		cout << "Vertex #" << i << ", value = " << vertex[i]->value << ", neighbours: ";
		for (int j = 0;j < vertex[i]->neighbours.size(); ++j)
			cout << vertex[i]->neighbours[j]->ind << ' ';
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