#include "Work_with_window.h"


void Work_with_window::create_fields(int number)
{
	int temp_number_buttons = buttons.size();
	for (int i = (int)fields.size() - 1; i > 0; --i)
	{
		fields.pop_back();
		buttons.pop_back();
	}
	number_of_created_windows_type_2 = number;
	int cur = 140, step = 30;
	for (int i = 0; i < number; ++i)
	{
		shared_ptr<Input_field> temp_type_2 = shared_ptr<Input_field>(new Input_field(base_fields[1]));
		shared_ptr<ButtonDraw> temp_num = shared_ptr<ButtonDraw>(new ButtonDraw(base_buttons[base_buttons.size()-1]));
		temp_type_2.get()->set_position(cur, 35);
		temp_num.get()->set_position(cur, 5, i + 1);
		cout << cur << ' ' << i << '\n';
		cur += step;
		fields.push_back(temp_type_2);
		buttons.push_back(temp_num);
	}
	cout << fields.size() << '\n';
}

Work_with_window::Work_with_window()
{

}

Work_with_window::Work_with_window(string &file)
{
	information = file;
	ifstream fin(file);
	string window_name;
	getline(fin,window_name);
	int height, width, number_of_buttons;
	fin >> width >> height;
	window = shared_ptr<RenderWindow>(new RenderWindow(VideoMode(height, width), window_name, Style::None));

	fin >> number_of_buttons;
	for (int i = 0; i < number_of_buttons; ++i)
	{
		shared_ptr<ButtonDraw> temp = shared_ptr<ButtonDraw>(new ButtonDraw(fin, window_name));
		base_buttons.push_back(temp);
		if(base_buttons[i].get()->get_name() != "#")
			buttons.push_back(base_buttons[i]);
	}
	int number_of_fields;
	fin >> number_of_fields;
	for (int i = 0; i < number_of_fields; ++i)
	{
		shared_ptr<Input_field> temp = shared_ptr<Input_field>(new Input_field(fin, window_name));
		base_fields.push_back(temp);
	}
	if (number_of_fields != 0)
		fields.push_back(base_fields[0]);
	fin.close();
}

void Work_with_window::work()
{
	if (window.get()->hasFocus())
	{
		Event event;
		if (window->pollEvent(event)) 
		{

			if (event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Enter))
				check_fields_enter();
			if (event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::BackSpace))
				check_fields_backspace();
			if (event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Tab))
				check_fields_tab();
			
			if (event.type == Event::MouseMoved)
			{
				cout << event.mouseMove.y << ' ' << event.mouseMove.x << '\n';
				check_buttons_under_cursor(event.mouseMove.y, event.mouseMove.x);
				check_fields_under_cursor(event.mouseMove.y, event.mouseMove.x);
			}

			if (event.type == Event::MouseButtonPressed)
				check_buttons_is_pressed(event.mouseButton.y, event.mouseButton.x, true);
			else 
				check_buttons_is_pressed(event.mouseMove.y, event.mouseMove.x, false);
			if (event.type == Event::MouseButtonReleased)
			{
				check_buttons_is_released(event.mouseButton.y, event.mouseButton.x);
				check_fields_is_released(event.mouseButton.y, event.mouseButton.x);
				for (int i = 0; i < buttons.size(); ++i)
					buttons[i].get()->unpress();
			}

			if (event.type == Event::TextEntered)
			{
				if (event.text.unicode >= 48 && event.text.unicode <= 57 || event.text.unicode == '.')
				{
					check_fields_entered_text(event.text.unicode);
				}
			}
			
			check_fields_on_last_dot();
		}
	}
	window.get()->clear(Color(40, 40, 40));
	draw();
	window.get()->display();
}

void Work_with_window::check_buttons_under_cursor(int pos_w, int pos_h)
{
	for (int i = 0; i < buttons.size(); ++i)
		buttons[i].get()->mouse_is_there(pos_w, pos_h,window);
}

void Work_with_window::check_buttons_is_pressed(int pos_w, int pos_h, bool is_pressed)
{
	for (int i = 0; i < buttons.size(); ++i)
	{
		buttons[i].get()->mouse_is_pressed(pos_w,pos_h,window,is_pressed);
	}
}

void Work_with_window::check_buttons_is_released(int pos_w, int pos_h)
{
	for (int i = 0; i < buttons.size(); ++i)
	{
		buttons[i].get()->mouse_is_released(pos_w, pos_h, window, need_to_create_window);
	}
}

void Work_with_window::check_fields_under_cursor(int pos_w, int pos_h)
{
	for (int i = 0; i < fields.size(); ++i)
	{
		fields[i].get()->is_under_cursor(pos_w, pos_h);
	}
}

void Work_with_window::check_fields_is_released(int pos_w, int pos_h)
{
	for (int i = 0; i < fields.size(); ++i)
		fields[i].get()->mouse_is_released(pos_w, pos_h);
}

void Work_with_window::check_fields_entered_text(char temp)
{
	for (int i = 0;i < fields.size(); ++i)
		if (fields[i].get()->_has_focus())
		{
			fields[i].get()->add_text(temp);
		}
}

void Work_with_window::check_fields_enter()
{
	if (fields.size() > 0) 
	{
		if (fields[0].get()->_has_focus())
		{
			if (fields[0].get()->_int_value() != 0)
			{
				create_fields(fields[0].get()->_int_value());
			}
		}
	}
}

void Work_with_window::check_fields_backspace()
{
	for (int i = 0; i < fields.size(); ++i)
	{
		if (fields[i].get()->_has_focus())
		{
			fields[i].get()->del_el_string();
		}
	}
}

void Work_with_window::check_fields_tab()
{
	for (int i = 0; i < fields.size(); ++i)
	{
		if (fields[i].get()->_has_focus())
		{
			fields[i].get()->unfocus();
			fields[(i+1)%fields.size()].get()->gain_focus();
			break;
		}
	}
}

void Work_with_window::check_fields_on_last_dot()
{
	for (int i = 0; i < fields.size(); ++i)
	{
		if (!fields[i].get()->_has_focus())
		{
			fields[i].get()->check_on_dot();
		}
	}
}

void Work_with_window::draw_frame_for_window(shared_ptr<RenderWindow> window) 
{
	VertexArray lines(LineStrip, 5);
	lines[0].color = lines[1].color = lines[2].color = lines[3].color = lines[4].color = Color(0, 0, 25);
	lines[0].position = Vector2f(0.5f, 0.5f);
	lines[1].position = Vector2f((float)window.get()->getSize().x-0.5f, 0.5f);
	lines[2].position = Vector2f((float)window.get()->getSize().x-0.5f,  (float)window.get()->getSize().y);
	lines[3].position = Vector2f(0.5f, (float)window.get()->getSize().y);
	lines[4].position = Vector2f(0.5f, 0.5f);
	window.get()->draw(lines);	
}

void Work_with_window::draw()
{
	for (int i = 0; i < buttons.size(); ++i)
	{
		buttons[i].get()->draw(window);
	}
	for (int i = 0; i < fields.size(); ++i)
		fields[i].get()->draw(window);

	draw_frame_for_window(window);
	
}

int Work_with_window::need_new_window()
{
	bool temp = need_to_create_window;
	need_to_create_window = 0;
	return temp;
}

bool Work_with_window::is_open()
{
	return window.get()->isOpen();
}


Work_with_window::~Work_with_window()
{
	window.reset();
	for (int i = 0; i < buttons.size(); ++i)
		buttons[i].reset();
}
