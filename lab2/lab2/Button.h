#pragma once
#include <string>

using namespace std;

struct characteristic_of_button
{
	string button_name;

	int position_width, position_height;
	int width, height;

	bool is_released, is_pressed, is_under_cursor;
	characteristic_of_button();
};


class Button
{

protected:
	characteristic_of_button button;

public:
	Button();
	~Button();
};

