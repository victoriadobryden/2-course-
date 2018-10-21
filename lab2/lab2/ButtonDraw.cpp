#include "ButtonDraw.h"
#include <iostream>

using namespace std;

ButtonDraw::ButtonDraw()
{
}

void ButtonDraw::set_information(string name, int pos_width, int pos_height)
{
	cout << name << '\n';
	texture.loadFromFile(name);
	sprite.setTexture(texture);
	sprite.setPosition(Vector2f ({ (float) pos_width,(float) pos_height }));
	set_values(texture.getSize().x, texture.getSize().y, pos_width, pos_height);
}

void ButtonDraw::draw(RenderWindow & window)
{
	window.draw(sprite);
}

void ButtonDraw::output()
{
	cout << button.width << "  " << button.height << ' ' << button.position_height << ' ' << button.position_width << '\n';
}

ButtonDraw::~ButtonDraw()
{
}
