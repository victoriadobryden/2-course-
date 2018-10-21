#pragma once
#include "Button.h"

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using std::string;

class ButtonDraw :
	public Button
{
	using Button::button;
	Texture texture;
	Sprite sprite;
public:
	ButtonDraw();
	void set_information(string name,int pos_width,int pos_height);
	void draw(RenderWindow &window);
	void output();
	~ButtonDraw();
};

