#include "Person.h"



Person::Person(Laws law)
{
	law.fill_vote_for_and_against(vote_for,vote_against,criterion);
	mood = 0;
	strategy_of_voting = rand() % 3;
	int index = rand() % primes.size();
	want_to_be_in_party = rand() % primes[index] % 2;
}

void Person::output()
{
	cout << ' ' << mood << ' ' << (bool)want_to_be_in_party << ' ' << strategy_of_voting << '\n';
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
