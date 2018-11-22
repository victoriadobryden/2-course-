#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
const int MAX_SIZE_GRAPH = 21;

struct Tedge {
	int to, number;
	double val;
	Tedge(int to, int number, double val);
};

class Algorithm_graph
{
	vector<Tedge> vertex[MAX_SIZE_GRAPH];
	int graph_size;
public:
	Algorithm_graph(vector<pair<int,int> > &edges, int n);
	vector<pair<int, double> > get_last_values();
	void give_value(int index, double val);
	vector<int> need_to_clear();
	int get_size();
	bool check_fields_non_negative(double val, int edge);
	~Algorithm_graph();
};
