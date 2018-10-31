#pragma once
#include "Party.h"
#include "Laws.h"
#include "Crowd.h"

class All_parties
{
	vector<Party> parties;
public:
	All_parties();
	All_parties(int n, Laws &law, Crowd people, int number_of_all_people);
	int msize();
	void output();
	~All_parties();
};

