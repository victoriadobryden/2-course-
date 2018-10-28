#pragma once
#include "Base1.h"
#include "externs.h"

#include <memory>

using namespace std;

class Base2
{
protected:
	static int gamma_size;
	static int delta_size;
	int N;
	unique_ptr<Base1> val_base1;
	unique_ptr<Base2> x_val_base2;
	unique_ptr<Base2> y_val_base2;
public:
	Base2();
	virtual ~Base2();
};

