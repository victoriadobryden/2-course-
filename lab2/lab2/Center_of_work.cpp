#include "Center_of_work.h"
#include <vector>

void main_part()
{
	vector<shared_ptr<Work_with_window> > all_windows;
	string s = "Data\\Main window\\information.dat";
	shared_ptr<Work_with_window> main_window = shared_ptr<Work_with_window>(new Work_with_window(s));
	all_windows.push_back(main_window);

	while (all_windows.size())
	{
		for (int i = 0; i < all_windows.size(); ++i)
		{
			all_windows[i].get()->work();
			if (!all_windows[i].get()->is_open())
			{
				all_windows[i].reset();
				for (int j = i; j < all_windows.size() - 1; ++j)
					all_windows[j] = move(all_windows[j + 1]);
				all_windows.pop_back();
			}
		}
	}

}
