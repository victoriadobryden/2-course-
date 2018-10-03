#pragma once
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
		else if (x == 1)
		{
			cout << "There are " << graph.size_gr() << "vertexes. Input with which vertexes it has to be connected.\n";
			cout << "First is number of vertex, next is data, end of input is \"-1\":\n";
			int v;
			vector<pair<int, T> > neighbours;
			while (cin >> v)
			{
				if (v == -1)
					break;
				if (v >= graph.size_gr() || v < 0)
				{
					cout << "It's non existing vertex. Input other data!\n";
					continue;
				}
				T val;
				cin >> val;
				neighbours.push_back({ v,val });
			}
			graph.add_vertex(neighbours);
		}
		else if (x == 2)
		{
			cout << "Input vertexes that you want to connect. If they were connected before this operation, nothing would happen\n";
			int x1, x2;
			while (cin >> x1 >> x2)
			{
				if (x1 >= graph.size_gr() || x1 < 0 || x2 < 0 || x2 >= graph.size_gr())
				{
					cout << "This vertexes don't exist. Input other.\n";
					continue;
				}
				break;
			}
			T val;
			cin >> val;
			graph.add_edge(x1, x2, val);
		}
		else if (x == 3)
		{
			cout << "Size is " << graph.size_gr();
		}
		else if (x == 4)
		{
			graph.output();
		}
		else if (x == 5)
		{
			Tree<T> tree;
			if (tree.find_ostov(graph) == -1)
				cout << "There are several trees\n";
			else
				cout << "Yeah we found a tree\n";
			tree.output();
		}

		cout << "\n --------------------------------------------------\n\n";
	}
}
