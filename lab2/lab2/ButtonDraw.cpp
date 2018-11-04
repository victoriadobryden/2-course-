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

ButtonDraw::~ButtonDraw()
{
	text.reset();
	font.reset();
	sprite.reset();
	texture.reset();
}
