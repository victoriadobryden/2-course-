#pragma once
#include "Person.h"
#include "Laws.h"

class Party
{
protected:
	vector<Person> members;

	vector<int> vote_for;
	vector<int> vote_against;
	vector<int> criterion;

public:
	Party();
	Party(Laws law);
	~Party();
};

