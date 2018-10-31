#pragma once
#include "Party.h"
#include "Laws.h"

class Parlament 
{
protected:
	vector<Party> parties;
	Party main_party;
	vector<int> need_to_adopt;
	vector<int> adopted;
	vector<int> regulate_work_of_parlament;
	vector<int> need_to_change;

	int number_of_members;
	int how_to_choose_law;

public:
	Parlament();
	~Parlament();
};

