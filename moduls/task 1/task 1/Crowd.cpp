#include "Crowd.h"



Crowd::Crowd()
{
	people.clear();
}

Crowd::Crowd(int n, Laws law)
{
	for (int i = 0; i < n; ++i) {
		Person temp(law,i);
		people.push_back(temp);
	}
}

void Crowd::output()
{
	for (int i = 0; i < people.size(); ++i)
	{
		cout << "Person #" << people[i].get_own_value() << '\n';
		people[i].output();
	}
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


Crowd::~Crowd()
{
}
