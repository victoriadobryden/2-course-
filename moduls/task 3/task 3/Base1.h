#pragma once
#include "Base2.h"
#include "externs.h"
#include <memory>

using namespace std;

class Base1
{
protected:
	static int alpha_size;
	static int beta_size;
	int	N;
	unique_ptr<Base1> val_base1;
	unique_ptr<Base2> x_val_base2;
	unique_ptr<Base2> y_val_base2;
public:
	Base1();
	virtual ~Base1();
};

