#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Algorithm_simple_probability
{
	int number_of_probabilities;
	double expected_value, variance;
	vector<double> probabilities;
	vector<double> events;
	vector<int> tests;

	void count_expected_value();
	void count_variance();
public:
	Algorithm_simple_probability(int n, vector<double> probs, vector<double> values);
	double get_expected_value();
	double get_variance();
	vector<int> get_tests();
	void generate_tests(int number);
	~Algorithm_simple_probability();
};

