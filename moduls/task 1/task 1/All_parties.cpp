#include "All_parties.h"



All_parties::All_parties()
{
}

All_parties::All_parties(int n, Laws &law, Crowd people, int number_of_all_people)
{
	for (int i = 0; i < n; ++i)
	{
		Party temp(law, i);
		temp.add_the_most(people, (int) sqrt(number_of_all_people));
		parties.push_back(temp);
	}
}

int All_parties::msize()
{
	return parties.size();
}

void All_parties::output()
{
	for (size_t i = 0; i < parties.size(); ++i)
		parties[i].output();
}


All_parties::~All_parties()
{
}
