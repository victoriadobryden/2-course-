#pragma once
#include "Button.h"

class Input_field :
	public Button
{
	using Button::button;

public:

	Input_field();
	~Input_field();
};

