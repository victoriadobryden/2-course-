#pragma once
#include "Base2.h"

class Base1
{
protected:
	static int N;
	Base1 *val_base1;
	Base2 *x_val_base2, *y_val_base2;
public:
	Base1();
	virtual ~Base1();
};

