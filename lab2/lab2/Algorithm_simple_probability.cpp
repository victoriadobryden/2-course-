#include "Algorithm_simple_probability.h"



Algorithm_simple_probability::Algorithm_simple_probability(int n, vector<double> values) :number_of_probabilities(n), probabilities(values)
{
	double counter = 0;
	for (int i = 0; i < probabilities.size(); ++i)
	{
		probabilities[i] /= 100.0;
		counter += probabilities[i];
	}
	if (!(abs(counter - 1.0) < 0.001))
	{
		probabilities.push_back(1.0 - counter);
		other = true;
	}
	else
		other = false;
	count_expected_value();
	count_variance();
}

double Algorithm_simple_probability::get_expected_value()
{
	return expected_value;
}

double Algorithm_simple_probability::get_variance()
{
	return variance;
}

vector<int> Algorithm_simple_probability::get_tests()
{
	return tests;
}

void Algorithm_simple_probability::generate_tests(int number)
{
	tests.clear();
	double temp;
	for (int i = 0; i < number; ++i)
	{
		temp = (double)rand() / (double)RAND_MAX;
		double cur_sum = 0;
		for (int j = 0; j < probabilities.size(); ++j)
		{
			cur_sum += probabilities[j];
			if (cur_sum > temp - 0.0001)
			{
				tests.push_back(j);
				break;
			}
		}
	}
}

void Algorithm_simple_probability::count_expected_value()
{
	expected_value = 0;
	for (int i = 0; i < probabilities.size(); ++i)
		expected_value += probabilities[i] * (i + 1);
}

void Algorithm_simple_probability::count_variance()
{
	variance = 0;
	variance = -expected_value;
	for (int i = 0; i < probabilities.size(); ++i)
		variance += (i + 1)*(i + 1)*probabilities[i];
}


Algorithm_simple_probability::~Algorithm_simple_probability()
{
}
