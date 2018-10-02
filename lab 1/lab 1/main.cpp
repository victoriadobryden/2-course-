#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"
//using namespace std;
int main()
{
	Graph<int> mas;
	vector<pair<int,int> > temp;
	temp.clear();
	srand(time(NULL));
	for (int i = 0; i <= 3; ++i)
	{
		for (size_t i = 0; i < temp.size(); ++i)
			temp[i].second = rand() % 100;
		mas.add_vertex(temp);
		if (rand() % 3 == 1) {
			temp.push_back({ i,rand()%100 });
		}
	}
	mas.output();
	int x = rand() % mas.size_gr(), y = rand() % mas.size_gr();
	cout << x << ' ' << y << '\n';
	mas.add_edge(x, y, x*y+1);
	mas.output();
	cout << mas.size_gr();
	system("pause");
}