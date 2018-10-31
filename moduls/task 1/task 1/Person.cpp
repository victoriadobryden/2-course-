#include "Person.h"



Person::Person()
{
	own_value = -1;
	mood = strategy_of_voting = want_to_be_in_party = number_of_party = 0;
	vote_for.clear();
	vote_against.clear();
	criterion.clear();
}

Person::Person(Laws law,int x)
{
	own_value = x;
	law.fill_vote_for_and_against(vote_for,vote_against,criterion);
	mood = 0;
	int index = rand() % primes.size();
	strategy_of_voting = rand() % primes[index] % 3;
	index = rand() % primes.size();
	want_to_be_in_party = rand() % primes[index] % 2;
	number_of_party = -1;
}

bool Person::get_want_to_be()
{
	return want_to_be_in_party;
}

int Person::get_own_value()
{
	return own_value;
}

vector<int> Person::get_vote_for()
{
	return vote_for;
}

void Person::output()
{
	cout << '#' << own_value << ' ' << mood << ' ' << (bool)want_to_be_in_party << ' ' << strategy_of_voting << '\n';
	cout << "Laws for:\n";
	for (size_t i = 0; i < vote_for.size(); ++i)
		cout << "\tLaw #" << vote_for[i] << " " << criterion[vote_for[i]] << ";\n";

	cout << "Laws against:\n";
	for (size_t i = 0; i < vote_against.size(); ++i)
		cout << "\tLaw #" << vote_against[i] << " " << criterion[vote_against[i]] << ";\n";
}


Person::~Person()
{
}
