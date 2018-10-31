#pragma once
#include "Laws.h"

class Person
{
protected:
	vector<int> vote_for;
	vector<int> vote_against;
	vector<int> criterion;

	int own_value;
	int mood;
	int strategy_of_voting;
	bool want_to_be_in_party;
	int number_of_party;
	
public:
	Person();
	Person(Laws law, int x);
	bool get_want_to_be();
	int get_own_value();
	vector<int> get_vote_for();
	void output();
	~Person();
};

