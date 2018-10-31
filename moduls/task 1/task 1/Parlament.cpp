#include "Parlament.h"



Parlament::Parlament(int n, Laws law)
{
	for (int i = 0; i < law.get_n(); ++i)
		if (rand() % primes[rand() % primes.size()] % 3 == 1)
			adopted.push_back(i);
	period = 400;
	number_of_members = (int) cbrt(n)*cbrt(n);
	part_of_votes = 3;
	how_to_choose_law = rand() % primes[rand() % primes.size()] % 3;
}

void Parlament::election_to_Parlament(All_parties & all_parties, Crowd & people)
{
	vector<pair<int, int> > number_of_votes;
	for (int i = 0; i < all_parties.msize(); ++i)
		number_of_votes.push_back({ 0,all_parties.get_party_in_arr(i).get_own_value() });

	for (int i = 0; i < people.msize(); ++i)
	{
		Person temp_person = people.get_person_in_arr(i);
		int max_person = -1, max_index = -1;
		for (int j = 0; j < all_parties.msize(); ++j) 
		{
			Party temp_party = all_parties.get_party_in_arr(j);
			int cur = temp_party.compare(temp_person.get_vote_for(), temp_party.get_vote_for());
			if (cur > max_person)
			{
				max_person = cur;
				max_index = j;
			}
		}
		++number_of_votes[max_index].first;
	}
	sort(number_of_votes.begin(), number_of_votes.end());
	vector<int> count_members;
	for (int i = 0; i < all_parties.msize(); ++i) {
		count_members.push_back(number_of_votes[i].first*number_of_members / people.msize());
		cout << count_members[i] << '\n';
	}
	int counter = 0;
	bool flag = false;
	for (int i = count_members.size()-1;i >= 0; --i)
	{
		int k = i - 1;
		while (count_members[i] > number_of_members / part_of_votes && k >= 0)
		{
			++count_members[k];
			--count_members[i];
			--k;
			if (k == -1)
				k = i - 1;
		}
		if (counter + count_members[i] > number_of_members)
		{
			count_members[i] = number_of_members - counter;
			flag = true;
		}
		parties.add(all_parties.get_party_number_N(number_of_votes[i].second));
		number_of_members_for_each_party.push_back({ number_of_votes[i].second,count_members[i] });
		counter += count_members[i];
		if (flag)
			break;
	}
	if (counter < number_of_members)
	{
		int i = 0;
		while (counter < number_of_members)
		{
			++number_of_members_for_each_party[i].second;
			++i;
			++counter;
		}
	}
	main_party = parties.get_party_in_arr(0);
}

bool Parlament::adopt_law(int cur_law)
{
	int cur_vote_for = 0;
	for (int k = 0; k < parties.msize(); ++k)
	{
		Party cur_party = parties.get_party_in_arr(k);
		Crowd people = cur_party.get_members();
		for (int i = 0; i < number_of_members_for_each_party[k].second; ++i)
		{
			if (people.get_person_in_arr(i).get_strategy_of_voting() == 2)
			{
				if (rand() % primes[rand() % primes.size()] % 2 == rand() % primes[rand() % primes.size()] % 2)
					++cur_vote_for;
			}
			else 
			{
				vector<int> temp;
				if (people.get_person_in_arr(i).get_strategy_of_voting() == 0)
					temp = people.get_person_in_arr(i).get_vote_for();
				else 
					temp = cur_party.get_vote_for();
				for (int j = 0; j < temp.size(); ++j)
					if (temp[j] == cur_law)
					{
						++cur_vote_for;
						break;
					}
			}
		}
	}
	if (cur_vote_for >= part_of_votes)
	{
		adopted.push_back(cur_law);
		return true;
	}
	return false;
}

int Parlament::get_period()
{
	return period;
}

void Parlament::output()
{
	cout << "Number of parties: " << parties.msize() << '\n';
	cout << "Number of members: " << number_of_members << '\n';
	for (int i = 0; i < parties.msize(); ++i)
	{
		cout << "\tParty #" << number_of_members_for_each_party[i].first << ", " << number_of_members_for_each_party[i].second << '\n';
	}
	cout << "Main party:\n";
	cout << "\tParty #" << main_party.get_own_value() << '\n';
	cout << "Adopted laws:\n";
	for (int i = 0; i < adopted.size(); ++i)
		cout << adopted[i] << ", ";
	cout << '\n';

}


Parlament::~Parlament()
{
}
