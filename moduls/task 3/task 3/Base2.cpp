#include "Base2.h"

int Base2::N = 1;

Base2::Base2()
{
	++N;
}


Base2::~Base2()
{
	S = S / 2 - N;
}
