#include "ButtonDraw.h"

ButtonDraw::ButtonDraw(string button_name, int w, int h, int s_w, int s_h, bool for_picture, string picture_name, bool for_text)
{
	button.button_name = button_name;
	button.position_width = w;
	button.position_height = h;
	button.width = s_w;
	button.height = s_h;
	is_picture = for_picture;
	if (is_picture)
	{
		texture = shared_ptr<Texture>(new Texture);
		texture.get()->loadFromFile(picture_name);
		sprite = shared_ptr<Sprite>(new Sprite);
		sprite.get()->setTexture(*texture);
		sprite.get()->setPosition(Vector2f(h, w));
	}
	is_text = for_text;
	if (is_text)
	{
		font = shared_ptr<Font>(new Font);
		font.get()->loadFromFile("arial.ttf");
		text = shared_ptr<Text>(new Text);
		text.get()->setFont(*font);
		if (button_name == "Title") 
		{
			text.get()->setCharacterSize(15);
			text.get()->setString("Probability");
		}
		else
		{
			text.get()->setCharacterSize(20);
			text.get()->setString(button_name);
		}
		text.get()->setStyle(Text::Regular);
		text.get()->setPosition(Vector2f(h, w));
	}
}

void ButtonDraw::draw(shared_ptr<RenderWindow> window)
{
	if (is_picture)
		window.get()->draw(*sprite);
	if (is_text)
	{
		if (button.is_under_cursor)
			text.get()->setFillColor(Color::Yellow);
		else
			text.get()->setFillColor(Color::White);
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
