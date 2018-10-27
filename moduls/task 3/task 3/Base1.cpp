#include "Base1.h"

int Base1::N = 1;

Base1::Base1()
{
	++N;
}


Base1::~Base1()
{
	S = 3 * S + N + 41;
}
