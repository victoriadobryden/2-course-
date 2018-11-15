#include "Algorithm_graph.h"

Algorithm_graph::Algorithm_graph(vector<pair<int, int> > &edges)
{
	for (int i = 0; i < edges.size(); ++i) {
		Tedge e(edges[i].second, i, -1.0);
		vertex[edges[i].first].push_back(e);
		graph_size = max(graph_size, edges[i].first);
		graph_size = max(graph_size, edges[i].second);
	}
	for (int i = 1; i <= graph_size; ++i)
	{
		for (int j = 0; j < vertex[i].size(); ++j)
			cout << i << "->" << vertex[i][j].to << ' ' << vertex[i][j].number << ' ' << vertex[i][j].val << '\n';
	}
}

vector<pair<int, double> > Algorithm_graph::get_last_values()
{
	vector<pair<int, double> > ans;
	for (int i = 1; i <= graph_size; ++i)
	{
		bool ok = true;
		double counter = 0;
		for (int j = 0; j < (int)vertex[i].size()-1; ++j)
		{
			if (vertex[i][j].val == -1) {
				ok = false;
				break;
			}
			counter += vertex[i][j].val;
		}
		if (ok && vertex[i].size() > 0) {
			vertex[i][vertex[i].size() - 1].val = 100.0 - counter;
			ans.push_back({ vertex[i][vertex[i].size() - 1].number,vertex[i][vertex[i].size()-1].val });
		}
		else if (!ok && vertex[i].size() > 0)
			vertex[i][vertex[i].size() - 1].val = -1;
	}
	return ans;
}

void Algorithm_graph::give_value(int index, double val)
{
	for (int i = 1; i <= graph_size; ++i)
	{
		for (int j = 0; j < vertex[i].size(); ++j)
		{
			if (vertex[i][j].number == index)
			{
				if (j != vertex[i].size() - 1)
				{
					vertex[i][j].val = val;
				}
				else
					break;
			}
		}
	}
}

vector<int> Algorithm_graph::need_to_clear()
{
	vector<int> ans;
	for (int i = 1; i <= graph_size; ++i)
	{
		for (int j = 0; j < vertex[i].size(); ++j)
		{
			if (vertex[i][j].val == -1)
				ans.push_back(vertex[i][j].number);
		}
	}
	return ans;
}

bool Algorithm_graph::check_fields_non_negative(double val, int edge)
{
	int which_line = -1;
	for (int i = 1; i <= graph_size; ++i)
	{
		for (int j = 0; j < (int)vertex[i].size(); ++j)
		{
			if (vertex[i][j].number == edge)
			{
				which_line = i;
				break;
			}
		}
		if (which_line != -1)
			break;
	}
	double counter = 0;
	for (int j = 0; j < (int)vertex[which_line].size()-1; ++j)
	{
		if (vertex[which_line][j].val > 0)
		{
			if (vertex[which_line][j].number == edge)
				counter += val;
			else
				counter += vertex[which_line][j].val;
		}
	}
	if (100.0 - counter < -0.000001)
		return false;
	else
		return true;
}

Algorithm_graph::~Algorithm_graph()
{
}

Tedge::Tedge(int to, int number, double val) :to(to), number(number), val(val)
{

}