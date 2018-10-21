#pragma once

struct characteristic_of_button
{
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
	void set_values(int w, int h, int pos_w, int pos_h);
	~Button();
};

