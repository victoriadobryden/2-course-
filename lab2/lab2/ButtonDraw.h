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
	shared_ptr<Texture> texture;
	shared_ptr<Sprite> sprite;

	bool is_text;
	shared_ptr<Font> font;
	shared_ptr<Text> text;

public:

	ButtonDraw(string button_name, int w, int h, int s_w, int s_t, bool for_picture, string picture_name, bool for_text);

	void draw(shared_ptr<RenderWindow> window);

	~ButtonDraw();
};

