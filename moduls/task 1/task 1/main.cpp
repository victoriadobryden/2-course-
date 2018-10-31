#include "Laws.h"
#include "Person.h"
#include "Crowd.h"
#include "Party.h"
#include "All_parties.h"
#include "Parlament.h"

#include <iostream>



int main()
{
	Laws law;
	law.fill_laws();
	law.output();
	int ALL_NUM = 40;
	Crowd people(ALL_NUM, law);
	Crowd will_be_in_party = people.who_want_to_be_in_party();
	people.output();
	will_be_in_party.output();
	cout << will_be_in_party.msize() << '\n';
	All_parties parties((int)cbrt(ALL_NUM), law, will_be_in_party, ALL_NUM);
	parties.output();
	Parlament parlament(ALL_NUM,law);
	parlament.election_to_Parlament(parties, people);
	parlament.adopt_law(0);
	parlament.output();
	system("pause");
	return 0;
}