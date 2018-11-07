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

void Input_field::convert_to_int()
{
	int_value = 0;
	for (int i = 0;i < text_value.length(); ++i)
		int_value = (int_value * 10 + text_value[i] - '0');
}

bool Input_field::convert_to_double()
{
	int dots = 0;
	double step = 1;
	double_value = 0;
	for (int i = 0; i < text_value.length(); ++i) {
		if (text_value[i] == '.') {
			++dots;
			if (dots > 1)
				return false;
		}
		else
		{
			double_value = (double_value * 10 + text_value[i] - '0');
			if (dots)
				step *= 10;
		}
	}
	double_value = double_value / step;
	return true;
}

Input_field::Input_field(shared_ptr<Input_field> base)
{
	button = base.get()->get_button();
	font = base.get()->get_font();
	texture = base.get()->get_texture();
	texture_in_action = base.get()->get_texture_in_action();

	sprite = shared_ptr<Sprite>(new Sprite);
	text = shared_ptr<Text>(new Text);
	text.get()->setFont(*font);
	text.get()->setCharacterSize(base.get()->get_text_size());
	text.get()->setStyle(Text::Regular);
	text.get()->setString("");
}


Input_field::Input_field(ifstream &fin, string window_name)
{
	getline(fin, button.button_name);
	getline(fin, button.button_name);
	getline(fin, button.button_name);
	button.window_name = window_name;
	text_value = "";
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
	text.get()->setString("");
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
	text.get()->setFillColor(Color(button.color_r, button.color_g, button.color_b));
	window.get()->draw(*text);
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
		has_focus = true;
	else
		has_focus = false;
}

bool Input_field::_has_focus()
{
	return has_focus;
}

void Input_field::unfocus()
{
	has_focus = false;
}

void Input_field::gain_focus()
{
	has_focus = true;
}

int Input_field::_int_value()
{
	return int_value;
}

void Input_field::add_text(char c)
{
	if (c != '.' && button.button_name == "Number of events")
	{
		text_value += c;
		convert_to_int();
		if (int_value == 0 || int_value > 15)
		{
			text_value.pop_back();
			convert_to_int();
		}
	}
	else if (button.button_name == "Events" && text_value.length() < 6)
	{
		if (text_value.length() == 0 && c == '.')
			return;
		if (text_value.length() == 1 && text_value[0] == '0' && c != '.')
			return;
		text_value += c;
		if (!convert_to_double() || double_value > 100)
		{
			text_value.pop_back();
			convert_to_double();
		}
	}
	cout << ' ' << text_value << '\n';
	text.get()->setString(text_value);
	text.get()->setOrigin(-button.height + (float)text_value.size() * 13.f, 0);
}

void Input_field::del_el_string()
{
	if (text_value.length() > 0) {
		text_value.pop_back();
		if (button.button_name == "Events")
			convert_to_double();
		else
			convert_to_int();
		cout << "lololo\n";
		text.get()->setString(text_value);
		text.get()->setOrigin(-button.height + (float)text_value.size() * 13.f, 0);
	}
}

void Input_field::check_on_dot()
{
	if (text_value.size() > 0)
	{
		if (text_value[text_value.size() - 1] == '.') {
			cout << "qweqw qwe \n";
			del_el_string();
		}
		if (button.button_name == "Events") 
		{
			if (text_value.length() == 1)
				text_value += ".0000";
			else if (text_value.length() == 2)
				text_value += ".000";
			else if (text_value == "100")
				text_value += ".00";
			else
				while (text_value.length() < 6)
					text_value += '0';
			text.get()->setString(text_value);
			text.get()->setOrigin(-button.height + (float)text_value.size() * 13.f, 0);
		}
	}
}

void Input_field::set_position(int pos_w, int pos_h)
{
	button.position_height = pos_h;
	button.position_width = pos_w;
	
	sprite.get()->setPosition(Vector2f((float)pos_h, (float)pos_w));
	text.get()->setPosition(Vector2f((float)pos_h, (float)pos_w));
}

characteristic_of_button Input_field::get_button()
{
	return button;
}

shared_ptr<Texture> Input_field::get_texture()
{
	return texture;
}

shared_ptr<Texture> Input_field::get_texture_in_action()
{
	return texture_in_action;
}

shared_ptr<Font> Input_field::get_font()
{
	return font;
}

int Input_field::get_text_size()
{
	return text.get()->getCharacterSize();
}

int Input_field::get_text_value_length()
{
	return text_value.length();
}

double Input_field::get_double_value()
{
	return double_value;
}



Input_field::~Input_field()
{
}
