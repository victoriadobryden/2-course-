#pragma once
#include "my_func.h"

#include <iostream>

using namespace std;

void checker()
{
	int inp;
	cout << "0 - exit\n1 - input your own values\n2 - input from file\n";
	while (true)
	{
		cin >> inp;
		bool flag = false;
		if (inp == 0)			//exit
		{
			cout << "See you next time\n";
			break;
		}
		else if (inp == 1)	
		{
			cout << "What type of values do you want to add:\n";
			cout << "	1 - positive numbers\n	2 - negative numbers\n	3 - double numbers\n	4 - string\n	5 - pair<a,b>\n	6 - list\n";

		}
		else if (inp == 2)
		{

		}
	}

}
