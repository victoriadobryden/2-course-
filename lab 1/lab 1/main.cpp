#include <iostream>
#include <cstdlib>
#include "Graph.h"

int main()
{
	Graph<int> mas;
	vector<int> temp;
	temp.clear();
	for (int i = 0; i <= 3; ++i)
	{
		mas.add_vertex((i + 4) * 3, temp);
		if (rand() % 2 == 1)
			temp.push_back(i);
	}
	mas.output();
	cout << mas.size_gr();
	system("pause");
}