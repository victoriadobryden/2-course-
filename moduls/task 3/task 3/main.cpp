#include "Base1.h"
#include "Base2.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
#include "Delta.h"
#include <iostream>

using namespace std;

int main()
{
	unique_ptr<Base1> temp;
	unique_ptr<Base2> temp2;
	temp = unique_ptr<Base1>(new Alpha);
	cout << "QWeqw";
	unique_ptr<Base1> lol = move(temp);
	temp.reset();
	lol.reset();
	cout << "qweqwe";
	int c;
	cin >> c;
	return 0;
}