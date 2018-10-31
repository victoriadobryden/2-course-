#include "Crowd.h"



Crowd::Crowd()
{
	people.clear();
}

Crowd::Crowd(int n, Laws &law)
{
	for (int i = 0; i < n; ++i) {
		Person temp(law,i);
		people.push_back(temp);
	}
}

void Crowd::output()
{
	for (int i = 0; i < people.size(); ++i)
		cout << "\tPerson #" << people[i].get_own_value() << '\n';
}

Crowd Crowd::who_want_to_be_in_party()
{
	Crowd temp;
	for (int i = 0; i < people.size(); ++i)
		if (people[i].get_want_to_be())
			temp.add(people[i]);
	return temp;
}

void Crowd::add(Person p)
{
	people.push_back(p);
}

int Crowd::msize()
{
	return (int)people.size();
}

vector<int> Crowd::elem_vote_for(int index)
{
	return people[index].get_vote_for();
}

Person Crowd::get_person(int index)
{
	for (int i = 0; i < people.size(); ++i)
		if (people[i].get_own_value() == index)
			return people[i];
	Person temp;
	return temp;
}

int Crowd::get_own_value(int index)
{
	return people[index].get_own_value();
}

void Crowd::del(int index)
{
	for (int i = 0;i < people.size(); ++i)
		if (people[i].get_own_value() == index)
		{
			for (int j = i; j < people.size() - 1; ++j)
				people[j] = people[j + 1];
			people.pop_back();
			return;
		}
}


Crowd::~Crowd()
{
}
