#include "Parlament.h"
#include <iostream>

int main()
{
	Laws law;
	law.fill_laws();
	law.output();
	vector<Person> crowd;
	for (int i = 0; i < 10; ++i)
	{
		Person temp(law);
		crowd.push_back(temp);
	}
	for (int i = 0; i < crowd.size(); ++i) 
	{
		cout << "Person #" << i << '\n';
		crowd[i].output();
	}
	system("pause");
}