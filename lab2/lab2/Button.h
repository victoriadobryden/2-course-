#pragma once

struct characteristic_of_button
{
	int position_width, position_height;
	int width, height;

	bool is_released, is_pressed;
	characteristic_of_button();
};

characteristic_of_button::characteristic_of_button()
{
	position_height = position_width = width = height = is_pressed = is_released = 0;
}


class Button
{
	characteristic_of_button button;

public:
	Button();
	~Button();
};

