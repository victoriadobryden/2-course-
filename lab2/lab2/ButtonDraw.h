#pragma once
#include "Button.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>

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

	ButtonDraw(ifstream &fin, string window_name);
	void unpress();
	void draw(shared_ptr<RenderWindow> window);
	void mouse_is_there(int pos_w, int pos_h, shared_ptr<RenderWindow> window);
	void mouse_is_pressed(int pos_w, int pos_h, shared_ptr<RenderWindow> window, bool is_pressed);
	void mouse_is_released(int pos_w, int pos_h, shared_ptr<RenderWindow> window, int &need_to_create_window);
	~ButtonDraw();
};

