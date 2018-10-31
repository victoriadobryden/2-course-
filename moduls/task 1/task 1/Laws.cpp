#include "Laws.h"

vector<int> Laws::laws;
vector<int> Laws::time_need_to_adopt;

Laws::Laws()
{
}


void Laws::fill_laws()
{
	resheto();
	int number = rand() % 13 + 5;
	for (int i = 0; i < number; ++i)
	{
		time_need_to_adopt.push_back(rand() % 37 + i % 53 + 2);
		laws.push_back((i + time_need_to_adopt[i] + rand()) % 1009 + 5);
	}
}

void Laws::fill_vote_for_and_against(vector<int> &vote_for, vector<int> &vote_against, vector<int> &criterion)
{
	vote_for.clear();
	vote_against.clear();
	criterion.clear();
	for (size_t i = 0; i < laws.size(); ++i)
	{
		criterion.push_back(primes[(rand() + primes.size()) % primes.size()]);
		int temp = laws[i] % criterion[i];
		if (temp % 2 == rand() % 2)
			vote_for.push_back((int)i);
		else
			vote_against.push_back((int)i);
	}
}

void Laws::output()
{
	for (size_t i = 0; i < laws.size(); ++i)
	{
		cout << "Law #" << i << ": ";
		cout << laws[i] << ", " << time_need_to_adopt[i] << ";\n";
	}
}



Laws::~Laws()
{
}
