#pragma once
#include "Button.h"

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Input_field :
	public Button
{
	using Button::button;

	shared_ptr<Texture> texture;
	shared_ptr<Texture> texture_in_action;
	shared_ptr<Sprite> sprite;
	
	bool has_focus;
	bool is_text;

	string text_value;
	int int_value;
	double double_value;
	shared_ptr<Text> text;
	shared_ptr<Font> font;

	void render_texture(ifstream &fin, shared_ptr<RenderTexture> temp_render);


public:

	Input_field(shared_ptr<Input_field> base);
	Input_field(ifstream &fin, string window_name);
	void draw(shared_ptr<RenderWindow> window);
	void is_under_cursor(int pos_w, int pos_h);
	void mouse_is_released(int pos_w, int pos_h);
	bool _has_focus();
	int _int_value();
	void add_text(char c);
	void set_position(int pos_w, int pos_h);
	characteristic_of_button get_button();
	shared_ptr<Texture> get_texture();
	shared_ptr<Texture> get_texture_in_action();
	shared_ptr<Font> get_font();
	int get_text_size();

	~Input_field();
};

