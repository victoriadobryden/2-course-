#pragma once
#include "Laws.h"
#include "Person.h"
#include "Crowd.h"
#include "Party.h"
#include "All_parties.h"
#include "Parlament.h"

#include <iostream>
#include <fstream>

using namespace std;

void work()
{
	Laws law;
	law.fill_laws();
	int ALL_NUM = 100;
	Crowd people(ALL_NUM, law);
	Crowd will_be_in_party = people.who_want_to_be_in_party();
	cout << "Current values are in files";
	ofstream fout("All_current_data.txt");
	law.output(fout);
	people.output(fout);
	All_parties parties((int)cbrt(ALL_NUM), law, will_be_in_party, ALL_NUM);
	parties.output(fout);
	Parlament parlament(ALL_NUM, law);
	int start_time = 0, end_time = 1000;
	while (start_time < end_time)
	{
		parlament.election_to_Parlament(parties, people);
		parlament.adopt_law(0);
		parlament.output();
		start_time += parlament.get_period();
	}
	system("pause");
}