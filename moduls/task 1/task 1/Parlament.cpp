#include "Parlament.h"



Parlament::Parlament(int n)
{
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
	int counter = 0;
	int index = number_of_votes[number_of_votes.size() - 1].second;



	int winer_number = min(all_parties.get_party_number_N(index).get_number_of_members(), number_of_members / part_of_votes);
	int winer_votes = number_of_votes[number_of_votes.size() - 1].first;
	main_party = all_parties.get_party_number_N(index);
	for (int i = number_of_votes.size() - 1; i >= 0 && counter < number_of_members; --i)
	{
		cout << number_of_votes[i].first << ' ' << number_of_votes[i].second << '\n';
		index = number_of_votes[i].second;
		int temp_number = all_parties.get_party_number_N(index).get_number_of_members();
		int temp_votes = number_of_votes[i].first;
		int will_add = min(temp_votes*winer_number / winer_votes, number_of_members / 2);
		if (counter + will_add > number_of_members)
			will_add = counter - number_of_members;
		//if (will_add == 0)
			
		parties.add(all_parties.get_party_number_N(index));
		number_of_members_for_each_party.push_back({ index, will_add });
		counter += will_add;
	}
	if (counter < number_of_members)
	{
		//while (counter)
	}
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
}


Parlament::~Parlament()
{
}
