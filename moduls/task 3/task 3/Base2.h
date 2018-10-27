#pragma once
#include "Base1.h"
int S = 0;

class Base2
{
protected:
	static int N;
	Base1 *val_base1;
	Base2 *x_val_base2, *y_val_base2;
public:
	Base2();
	virtual ~Base2();
};

