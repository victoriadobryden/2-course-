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
		texture.loadFromFile(picture_name);
		sprite.setTexture(texture);
	}
	is_text = for_text;
	if (is_text)
	{
		font.loadFromFile("arial.ttf");
		text.setFont(font);
		text.setCharacterSize(30);
		text.setStyle(Text::Italic);
		text.setString(button_name);
	}
}

void ButtonDraw::draw(RenderWindow & window)
{
	if (is_picture)
		window.draw(sprite);
	if (is_text)
	{
		if (button.is_under_cursor)
			text.setFillColor(Color::Yellow);
		else
			text.setFillColor(Color::White);
		
	}
}

ButtonDraw::~ButtonDraw()
{
}
