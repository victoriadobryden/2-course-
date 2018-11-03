#include "Center_of_work.h"
#include <vector>

void main_part()
{
	vector<Work_with_window> all_windows;
	string s = "Data\\Main window\\information.dat";
	Work_with_window main_window(s);
	all_windows.push_back(main_window);

	while (all_windows.size())
	{
		for (int i = 0; i < all_windows.size(); ++i)
		{
			all_windows[i].work();
			if (!all_windows[i].is_open())
			{
		//		all_windows.erase(all_windows.begin()+i);
			}
		}
	}

}
