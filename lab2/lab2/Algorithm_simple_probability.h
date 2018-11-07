#pragma once
#include <vector>

using namespace std;

class Algorithm_simple_probability
{
	int number_of_probabilities;
	double expected_value, variance;
	vector<double> probabilities;
	bool other;

	void count_expected_value();
	void count_variance();
public:
	Algorithm_simple_probability(int n, vector<double> values);
	double get_expected_value();
	double get_variance();
	~Algorithm_simple_probability();
};

