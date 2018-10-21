#include "Button.h"

characteristic_of_button::characteristic_of_button()
{
	position_height = position_width = width = height = 0;
	is_pressed = is_released = is_under_cursor = false;
}

Button::Button()
{
}

void Button::set_values(int w, int h, int pos_w, int pos_h)
{
	button.height = h;
	button.width = w;
	button.position_height = pos_h;
	button.position_width = pos_w;
}


Button::~Button()
{
}
