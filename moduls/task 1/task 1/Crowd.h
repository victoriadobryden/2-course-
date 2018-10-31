#pragma once
#include "Person.h"
#include "Laws.h"

class Crowd
{
	vector<Person> people;
public:
	Crowd();
	Crowd(int n, Laws law);
	void output();
	Crowd who_want_to_be_in_party();
	void add(Person p);
	int msize();
	~Crowd();
};

