#include "Base2.h"

int S = 0;

int Base2::gamma_size = 1;
int Base2::delta_size = 1;

Base2::Base2()
{
}


Base2::~Base2()
{
	S = S / 2 - N;
	x_val_base2.reset();
	y_val_base2.reset();
	val_base1.reset();
}
