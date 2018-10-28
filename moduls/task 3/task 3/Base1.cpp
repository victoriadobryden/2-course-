#include "Base1.h"

int Base1::alpha_size = 1;
int Base1::beta_size = 1;

Base1::Base1()
{
}


Base1::~Base1()
{
	S = 3 * S + N + 41;
	x_val_base2.reset();
	y_val_base2.reset();
	val_base1.reset();
}
