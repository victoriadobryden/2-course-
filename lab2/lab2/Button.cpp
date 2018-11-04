#include "Button.h"

characteristic_of_button::characteristic_of_button()
{
	position_height = position_width = width = height = 0;
	is_pressed = is_released = is_under_cursor = false;
	color_r = color_g = color_b = 0;
	color_undcur_r = color_undcur_g = color_undcur_b = 0;
}

Button::Button()
{
}

Button::~Button()
{
}
