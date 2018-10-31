#include "Laws.h"
#include "Person.h"
#include "Crowd.h"
#include "Party.h"
#include "Parlament.h"

#include <iostream>



int main()
{
	Laws law;
	law.fill_laws();
	law.output();
	Crowd people(40, law);
	Crowd will_be_in_party = people.who_want_to_be_in_party();
	people.output();
	will_be_in_party.output();
	cout << will_be_in_party.msize() << '\n';


	system("pause");
}