#pragma once
#include "Person.h"
#include "Laws.h"

class Crowd
{
	vector<Person> people;
public:
	Crowd();
	Crowd(int n, Laws &law);
	void output();
	Crowd who_want_to_be_in_party();
	void add(Person p);
	int msize();
	vector<int> elem_vote_for(int index);
	Person get_person_in_arr(int index);
	Person get_person_number_N(int index);
	int get_own_value(int index);
	void del(int index);
	~Crowd();
};

