#pragma once
#include "ButtonDraw.h"

#include <SFML/Graphics.hpp>
#include <fstream>

using namespace sf;
using namespace std;

class Work_with_window
{
	shared_ptr<RenderWindow> window;
	vector<shared_ptr<ButtonDraw> > buttons;
	string information;

public:
	Work_with_window();
	Work_with_window(string &file);
	void work();
	void check_buttons_under_cursor(int pos_w, int pos_h);
	void check_buttons_is_pressed(int pos_w, int pos_h);
	void draw();
	bool is_open();
	~Work_with_window();
};

