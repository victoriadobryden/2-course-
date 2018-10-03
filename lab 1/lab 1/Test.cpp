#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"
#include "Tree.h"
#include "Triangle.h"
#include "Tetragon.h"
#include "Pentagon.h"

using std::cin;

template<typename T>
void check(Graph<T> &graph)
{
	cout << "You will work with Classes Graph and Tree.\n";
	cout << "0 - exit\n1 - add vertex\n2 - add edge\n3 - size of graph\n4 - output graph\n5 - find spanning tree\n";
	int x;
	while (true)
	{
		cin >> x;
		if (x == 0)
			break;
		if (x == 1)
		{
			cout << "There are " << graph.size_gr() << "vertexes. Input with which vertexes it has to be connected.\n";
			cout << "First is number of vertex, next is data, end of inputing data and end of input is \"-1\":\n";
			int v;
			vector<pair<int, T> > neighbours;
			while (cin >> v)
			{
				if (v == -1)
					break;
				T val;
				cin >> val;
				neighbours.push_back({ v,val });
			}
		}
	}
}
