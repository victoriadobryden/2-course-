#include "Input_field.h"


void Input_field::render_texture(ifstream &fin, shared_ptr<RenderTexture> temp_render)
{
	temp_render.get()->create(button.height, button.width);
	VertexArray lines(LineStrip, 5);
	int color_r, color_g, color_b;
	fin >> color_r >> color_g >> color_b;
	lines[0].color = lines[1].color = lines[2].color = lines[3].color = lines[4].color = Color(color_r, color_g, color_b);
	lines[0].position = Vector2f(0.5f, 0.5f);
	lines[1].position = Vector2f((float)button.height - 0.5f, 0.5f);
	lines[2].position = Vector2f((float)button.height - 0.5f, (float)button.width-0.5f);
	lines[3].position = Vector2f(0.5f, (float)button.width - 0.5f);
	lines[4].position = Vector2f(0.5f, 0.5f);
	fin >> color_r >> color_g >> color_b;
	temp_render.get()->clear(Color(color_r, color_g, color_b));
	temp_render.get()->draw(lines);
	temp_render.get()->display();
}

Input_field::Input_field(ifstream &fin, string window_name)
{
	getline(fin, button.button_name);
	getline(fin, button.button_name);
	getline(fin, button.button_name);
	button.window_name = window_name;
	fin >> button.position_width >> button.position_height >> button.width >> button.height;

	shared_ptr<RenderTexture> frame = shared_ptr<RenderTexture>(new RenderTexture);
	render_texture(fin, frame);
	texture = shared_ptr<Texture>(new Texture(frame.get()->getTexture()));

	frame.reset(); frame = shared_ptr<RenderTexture>(new RenderTexture);
	render_texture(fin, frame);
	texture_in_action = shared_ptr<Texture>(new Texture(frame.get()->getTexture()));

	sprite = shared_ptr<Sprite>(new Sprite);
	sprite.get()->setTexture(*texture);
	sprite.get()->setPosition(Vector2f((float)button.position_height, (float)button.position_width));
	
	font = shared_ptr<Font>(new Font);
	font.get()->loadFromFile("arial.ttf");
	text = shared_ptr<Text>(new Text);
	text.get()->setFont(*font);
	int size_font;

	fin >> size_font;
	text.get()->setCharacterSize(size_font);
	text.get()->setStyle(Text::Regular);
	text.get()->setPosition(Vector2f((float)button.position_height, (float)button.position_width));

	fin >> button.color_r >> button.color_g >> button.color_b;
}

void Input_field::draw(shared_ptr<RenderWindow> window)
{
	if (button.is_under_cursor || has_focus) 
	{
		sprite.get()->setTexture(*texture_in_action);
		window.get()->draw(*sprite);
	}
	else
	{
		sprite.get()->setTexture(*texture);
		window.get()->draw(*sprite);
	}
	if (is_text)
	{
		text.get()->setFillColor(Color(button.color_r, button.color_g, button.color_b));
		window.get()->draw(*text);
	}
}

void Input_field::is_under_cursor(int pos_w, int pos_h)
{
	if (in_it(pos_w, pos_h))
		button.is_under_cursor = true;
	else
		button.is_under_cursor = false;
}

void Input_field::mouse_is_released(int pos_w, int pos_h)
{
	if (in_it(pos_w, pos_h))
		is_text = has_focus = true;
	else
		is_text = has_focus = false;
}



Input_field::~Input_field()
{
}
