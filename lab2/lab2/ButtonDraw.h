#pragma once
#include "Button.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class ButtonDraw :
	public Button
{
	using Button::button;

	bool is_picture;
	Texture texture;
	Sprite sprite;

	bool is_text;
	Font font;
	Text text;

public:

	ButtonDraw(string button_name, int w, int h, int s_w, int s_t, bool for_picture, string picture_name, bool for_text);

	void draw(RenderWindow &window);

	~ButtonDraw();
};

