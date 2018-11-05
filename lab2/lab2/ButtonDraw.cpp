#include "ButtonDraw.h"

ButtonDraw::ButtonDraw(ifstream &fin)
{
	getline(fin, button.button_name);
	getline(fin, button.button_name);
	getline(fin, button.button_name);
	fin >> button.position_width >> button.position_height >> button.width >> button.height;
	fin >> is_picture;
	string file_picture_name;
	if (is_picture) {
		getline(fin, file_picture_name);
		getline(fin, file_picture_name);
		texture = shared_ptr<Texture>(new Texture);
		texture.get()->loadFromFile(file_picture_name);
		sprite = shared_ptr<Sprite>(new Sprite);
		sprite.get()->setTexture(*texture);
		sprite.get()->setPosition(Vector2f((float)button.position_height, (float)button.position_width));
	}
	else
		file_picture_name = "";
	fin >> is_text;
	if (is_text)
	{
		font = shared_ptr<Font>(new Font);
		font.get()->loadFromFile("arial.ttf");
		text = shared_ptr<Text>(new Text);
		text.get()->setFont(*font);
		int size_font;
		fin >> size_font;
		text.get()->setCharacterSize(size_font);
		text.get()->setString(button.button_name);
		text.get()->setStyle(Text::Regular);
		text.get()->setPosition(Vector2f((float)button.position_height, (float)button.position_width));
		fin >> button.color_r >> button.color_g >> button.color_b;
		fin >> button.color_undcur_r >> button.color_undcur_g >> button.color_undcur_b;
	}
}

void ButtonDraw::unpress()
{
	button.is_pressed = false;
}

void ButtonDraw::draw(shared_ptr<RenderWindow> window)
{
	if (is_picture)
		window.get()->draw(*sprite);
	if (is_text)
	{
		if (button.is_under_cursor)
			text.get()->setFillColor(Color(button.color_undcur_r,button.color_undcur_g,button.color_undcur_b));
		else
			text.get()->setFillColor(Color(button.color_r,button.color_g,button.color_b));
		window.get()->draw(*text);
	}
	//window.reset();
}

void ButtonDraw::mouse_is_there(int pos_w, int pos_h, shared_ptr<RenderWindow> window)
{
	if (in_it(pos_w, pos_h))
	{
		button.is_under_cursor = true;
	}
	else
		button.is_under_cursor = false;
}

void ButtonDraw::mouse_is_pressed(int pos_w, int pos_h, shared_ptr<RenderWindow> window, bool is_pressed)
{
	cout << is_pressed << ' ' << button.is_pressed << '\n';
	if (is_pressed || button.is_pressed) 
	{
		//cout << pos_w << ' ' << pos_h << '\n';
		if (in_it(pos_w, pos_h))
		{
		//	cout << "Qwe qw QW\n";
			if (button.button_name == "Probability" || button.button_name == "Simple probability")
			{
				if (!button.is_pressed) {
					button.prev_pos_mouse_h = pos_h;
					button.prev_pos_mouse_w = pos_w;
				}
				button.is_pressed = true;
	//			cout << "qweqwe \n";
	//			Mouse::setPosition(Vector2i(200, 10), *window);
				window.get()->setPosition(Vector2i(Mouse::getPosition().x-button.prev_pos_mouse_h,Mouse::getPosition().y-button.prev_pos_mouse_w));
				button.prev_pos_mouse_h = Mouse::getPosition(*window).x;
				button.prev_pos_mouse_w = Mouse::getPosition(*window).y;
			}
		}
	}
}

void ButtonDraw::mouse_is_released(int pos_w, int pos_h, shared_ptr<RenderWindow> window, int & need_to_create_window)
{
	if (in_it(pos_w, pos_h)) 
	{
		if (button.button_name == "Cross")
			window.get()->close();
		else if (button.button_name == "Simple Probability")
			need_to_create_window = 1;
	}
}

ButtonDraw::~ButtonDraw()
{
	text.reset();
	font.reset();
	sprite.reset();
	texture.reset();
}
