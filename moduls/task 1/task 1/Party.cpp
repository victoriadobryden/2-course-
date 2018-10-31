#include "Party.h"



Party::Party()
{
	members.clear();
	vote_against.clear();
	vote_for.clear();
	criterion.clear();
}

Party::Party(Laws law)
{
	law.fill_vote_for_and_against(vote_for,vote_against,criterion);
	members.clear();
}


Party::~Party()
{
}
