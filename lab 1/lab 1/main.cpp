#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"
#include "Tree.h"
#include "Triangle.h"
//using namespace std;
int main()
{
	//-----------------------------GRAPH---------------------------C
	Graph<int> mas;
	vector<pair<int,int> > temp;
	temp.clear();
	srand(time(NULL));
	for (int i = 0; i <= 3; ++i)
	{
		for (size_t j = 0; j < i; ++j) {
			if (rand() % 2 == 1)
				temp.push_back({ j,rand() % 100 });
		}
		mas.add_vertex(temp);
		temp.clear();
	}
	mas.output();
	int x = rand() % mas.size_gr(), y = rand() % mas.size_gr();
	cout << x << ' ' << y << '\n';
	mas.add_edge(x, y, x*y+1);
	mas.output();
	cout << mas.size_gr() << '\n';

	Tree<int> tree;
	if (tree.find_ostov(mas) == 1)
		cout << "It's tree!!!\n";
	else
		cout << "It's consist of several trees\n";
	tree.output();
	cout << "-----------------------------POLYGON---------------------------\n";
	Triangle *A = new Triangle(1, 0, 0, 1, 0, 0);
	cout << A->perimetr() << '\n' << A->square() << '\n';
	system("pause");
}