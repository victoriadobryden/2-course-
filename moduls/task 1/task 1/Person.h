#pragma once
#include "Laws.h"

class Person
{
protected:
	vector<int> vote_for;
	vector<int> vote_against;
	vector<int> criterion;

	int mood;
	int strategy_of_voting;
	bool want_to_be_in_party;
	
public:
	Person(Laws law);
	void output();
	~Person();
};

