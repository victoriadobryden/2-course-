#include "Party.h"



int Party::compare(vector<int> a, vector<int> b)
{
	int counter = 0;
	for (size_t i = 0; i < a.size(); ++i)
	{
		int l = 0, r = (int) b.size();
		while (r - l > 1)
		{
			int mid = (r + l) >> 1;
			if (b[mid] > a[i])
				r = mid;
			else
				l = mid;
		}
		if (a[i] == b[l])
			++counter;
	}
	return counter;
}

Party::Party()
{
	own_value = -1;
	vote_against.clear();
	vote_for.clear();
	criterion.clear();
}

Party::Party(Laws law, int x)
{
	own_value = x;
	law.fill_vote_for_and_against(vote_for,vote_against,criterion);
}

void Party::add_the_most(Crowd &people, int n)
{
	vector<pair<int, int> > most_usefull;
	most_usefull.clear();
	for (int i = 0; i < people.msize(); ++i)
	{
		int res = compare(people.elem_vote_for(i), vote_for);
		most_usefull.push_back({ res,people.get_own_value(i) });
	}
	sort(most_usefull.begin(), most_usefull.end());
	for (int i = most_usefull.size() - 1; i >= max((int)0, (int)most_usefull.size() - n); --i) {
		members.add(people.get_person(most_usefull[i].second));
		people.del(most_usefull[i].second);
	}
	
}

void Party::output()
{
	cout << "Party #" << own_value << '\n';
	cout << "Members:\n";
	members.output();
	cout << "Vote for:\n";
	for (size_t i = 0; i < vote_for.size(); ++i)
		cout << "\tLaw #" << vote_for[i] << ", "  << criterion[vote_for[i]] << ";\n";
	cout << "Vote against: \n";
	for (size_t i = 0; i < vote_against.size(); ++i)
		cout << "\tLaw #" << vote_against[i] << ", " << criterion[vote_against[i]] << ";\n";

}


Party::~Party()
{
}
