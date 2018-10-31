#pragma once
#include "Person.h"
#include "Crowd.h"
#include "Laws.h"

#include <iostream>
#include <algorithm>

using namespace std;

class Party
{
protected:
	Crowd members;
	int own_value;

	vector<int> vote_for;
	vector<int> vote_against;
	vector<int> criterion;
public:
	Party();
	Party(Laws law,int x);
	void add_the_most(Crowd &people, int n);
	int compare(vector<int> a, vector<int> b);
	void output();
	~Party();
};

