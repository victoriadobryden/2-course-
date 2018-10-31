#pragma once
#include "Party.h"
#include "All_parties.h"
#include "Crowd.h"
#include "Laws.h"

class Parlament 
{
protected:
	All_parties parties;
	vector<pair<int,int> > number_of_members_for_each_party;
	Party main_party;

	vector<int> need_to_adopt;
	vector<int> adopted;
	vector<int> regulate_work_of_parlament;
	vector<int> need_to_change;

	int period;
	int number_of_members;
	int how_to_choose_law;
	int part_of_votes;

public:
	Parlament(int n);
	void election_to_Parlament(All_parties &all_parties, Crowd &people);
	void output();
	~Parlament();
};

