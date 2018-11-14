#include "Work_with_window.h"


void Work_with_window::create_fields(int number)
{
	int temp_number_buttons = (int)buttons.size();
	for (int i = (int)fields.size() - 1; i > 1; --i)
		fields.pop_back();
	for (int i = (int)buttons.size() - 1; i > 5; --i)
		buttons.pop_back();
	number_of_created_windows_type_2 = number;
	int cur = 130, step = 30, hash_pos = get_pos_base_button("#");
	for (int i = 0; i < number; ++i)
	{
		shared_ptr<Input_field> temp_type_2 = shared_ptr<Input_field>(new Input_field(base_fields[1]));
		shared_ptr<ButtonDraw> temp_num = shared_ptr<ButtonDraw>(new ButtonDraw(base_buttons[hash_pos]));
		temp_type_2.get()->set_position(cur, 35);
		temp_num.get()->set_position(cur, 5);
		temp_num.get()->set_text(i + 1, false);
		fields.push_back(temp_type_2);
		temp_type_2.reset();
		temp_type_2 = shared_ptr<Input_field>(new Input_field(base_fields[3]));
		temp_type_2.get()->set_position(cur, 35 + 115);
		fields.push_back(temp_type_2);
		buttons.push_back(temp_num);
		cur += step;
	}
	hash_pos = get_pos_base_button("Enter values");
	shared_ptr<ButtonDraw> temp_num = shared_ptr<ButtonDraw>(new ButtonDraw(base_buttons[hash_pos]));
	temp_num.get()->set_position(cur, 35);
	buttons.push_back(temp_num);
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
	int need_to_add;
	fin >> width >> height;
	window = shared_ptr<RenderWindow>(new RenderWindow(VideoMode(height, width), window_name, Style::None));

	fin >> number_of_buttons;
	for (int i = 0; i < number_of_buttons; ++i)
	{
		shared_ptr<ButtonDraw> temp = shared_ptr<ButtonDraw>(new ButtonDraw(fin, window_name));
		base_buttons.push_back(temp);
		fin >> need_to_add;
		if (need_to_add)
			buttons.push_back(base_buttons[i]);
	}
	int hash_pos = get_pos_base_button("Go!");
	if (hash_pos != -1) 
	{
		cout << "qw3eq2we";
		shared_ptr<ButtonDraw> temp_num = shared_ptr<ButtonDraw>(new ButtonDraw(base_buttons[hash_pos]));
		temp_num.get()->set_text("Go!");
		buttons.push_back(temp_num);
	}

	int number_of_fields;
	fin >> number_of_fields;
	for (int i = 0; i < number_of_fields; ++i)
	{
		shared_ptr<Input_field> temp = shared_ptr<Input_field>(new Input_field(fin, window_name));
		base_fields.push_back(temp);
		if (base_fields[i].get()->get_field_name() == "Save" || base_fields[i].get()->get_field_name() == "Open")
			base_fields[i].get()->set_position(-1, 2);
	}
	if (number_of_fields != 0) {
		fields.push_back(base_fields[0]);
	}
	if (information == "Data\\Simple Probability information.dat")
		fields.push_back(base_fields[5]);
	fin.close();
}

void Work_with_window::work()
{
	Event event;
	//if (information == )
	if (window->pollEvent(event))
	{
		if (window.get()->hasFocus())
		{

			if (event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::BackSpace))
				check_fields_backspace();
			if (event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Tab))
				check_fields_tab();
			
			if (event.type == Event::MouseMoved)
			{
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
				if (event.text.unicode >= 48 && event.text.unicode <= 57 || event.text.unicode >= 97 && event.text.unicode <= 122)
				{
					check_fields_save_open(event.text.unicode);
				}
			}
			
			check_fields_on_last_dot();
			check_last_prob_field();
		}
		else {
			for (int i = 0; i < (int)buttons.size(); ++i)
			{
				buttons[i].get()->unpress();
				buttons[i].get()->unfocus();
			}
			for (int i = 0; i < (int)fields.size(); ++i)
				fields[i].get()->unfocus();
		}
	}
	window.get()->clear(Color(40, 40, 40));
	draw();
	window.get()->display();
}

void Work_with_window::check_buttons_under_cursor(int pos_w, int pos_h)
{
	for (int i = 0; i < buttons.size(); ++i)
		buttons[i].get()->mouse_is_there(pos_w, pos_h);
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
		if (buttons[i].get()->get_name() == "Enter values" && buttons[i].get()->in_it(pos_w, pos_h))
		{
			if (button_enter_values())
			{
				help_enter_values();
			}
		}
		else if (buttons[i].get()->get_name() == "Save" && buttons[i].get()->in_it(pos_w, pos_h))
		{
			for (int j = 0; j < fields.size(); ++j)
				if (fields[j].get()->get_field_name() == "Save")
				{
					if (fields[j].get()->get_text_value().length() != 0)
					{
						ofstream fout(fields[j].get()->get_text_value() + ".dat");
						algo_simple.get()->output(fout);
					}
					break;
				}
		}
		else if (buttons[i].get()->get_name() == "Open" && buttons[i].get()->in_it(pos_w, pos_h))
		{
			for (int j = 0; j < fields.size(); ++j)
				if (fields[j].get()->get_field_name() == "Open")
				{
					if (fields[j].get()->get_text_value().length() != 0)
					{
						ifstream fin(fields[j].get()->get_text_value() + ".dat");
						if (fin)
						{
							render_opened_file(fin);
						}
						break;
					}
				}

		}
		else if (buttons[i].get()->get_name() == "Go!" && buttons[i].get()->in_it(pos_w, pos_h))
			if (information == "Data\\Simple Probability information.dat")
				check_button_go_simple(i > 5);
			else
				check_button_go_in_graph(i);
		else			
			buttons[i].get()->mouse_is_released(pos_w, pos_h, window, need_to_create_window);
	}
}

void Work_with_window::check_button_go_simple(bool what)
{
	if (fields.size() > 0)
	{
		if (what == 0) 
		{
			if (fields[0].get()->_int_value() != 0)
				create_fields(fields[0].get()->_int_value());
		}
		else {
			for (int i = 1; i < fields.size(); ++i)
				if ((fields[i].get()->get_field_name() == "Number of tests")
					&& fields[i].get()->_int_value() != 0)
				{
					delete_buttons_simple(i);
					create_tests(fields[i].get()->_int_value());
				}
		}
	}
}

void Work_with_window::check_button_go_in_graph(int index)
{
	int n = 0;
	for (int i = 0; i < index; ++i)
		if (buttons[i].get()->get_name() == "Go!")
			++n;
	if (n == 0)
	{
		delete_buttons_in_graph(n);
		int hash_pos = get_pos_base_button("Number of edges:");
		shared_ptr<ButtonDraw> temp_button = shared_ptr<ButtonDraw>(new ButtonDraw(base_buttons[hash_pos]));
		temp_button.get()->set_text("Number of edges:");
		buttons.push_back(temp_button);
		hash_pos = get_pos_base_fields("Number of edges");
		shared_ptr<Input_field> temp_field = shared_ptr<Input_field>(new Input_field(base_fields[hash_pos]));
		fields.push_back(temp_field);
		hash_pos = get_pos_base_button("Go!");
		temp_button = shared_ptr<ButtonDraw>(new ButtonDraw(base_buttons[hash_pos]));
		temp_button.get()->set_position(126, 110);
		temp_button.get()->set_text("Go!");
		buttons.push_back(temp_button);
	}
	else if (n == 1)
	{
		delete_buttons_in_graph(n);
		int num = fields[1].get()->_int_value();
		//create_fields(num, n);
	}
}

void Work_with_window::check_last_on_neg_simple(int index)
{
	double counter = 0;
	for (int i = 2; i <= 1 + 2 * number_of_created_windows_type_2 - 2; i += 2)
		if (fields[i].get()->get_text_value_length() != 0)
			counter += fields[i].get()->get_double_value();
	if (100.0 - counter < -0.000001)
		fields[index].get()->del_el_string();
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
		if (fields[i].get()->_has_focus() && fields[i].get()->get_field_name() != "Save" && fields[i].get()->get_field_name() != "Open")
		{
			if (information == "Data\\Simple Probability information.dat") {
				fields[i].get()->add_text(temp, 0);
				check_last_on_neg_simple(i);
			}
			else
			{
				if (i == 0)
					fields[i].get()->add_text(temp, 1);
				else
					fields[i].get()->add_text(temp, 1, fields[0].get()->_int_value());
			}
		}
}

void Work_with_window::check_fields_save_open(char temp)
{
	for (int i = 0; i < fields.size(); ++i)
		if ((fields[i].get()->get_field_name() == "Open" || fields[i].get()->get_field_name() == "Save") && 
			fields[i].get()->_has_focus())
		{
			fields[i].get()->add_char_text(temp);
		}
}

void Work_with_window::check_fields_backspace()
{
	for (int i = 0; i < fields.size(); ++i)
	{
		if (fields[i].get()->_has_focus())
		{
			fields[i].get()->del_el_string();
			if (fields[i].get()->get_field_name() != "Save" && fields[i].get()->get_field_name() != "Open")
				delete_buttons_simple(i);
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

void Work_with_window::check_last_prob_field()
{
	bool all_filled = true;
	double counter = 0;
	for (int i = 2; i <= 1 + 2 * number_of_created_windows_type_2 - 2; i += 2)
		if (fields[i].get()->get_text_value_length() == 0)
			all_filled = false;
		else
			counter += fields[i].get()->get_double_value();
	if (number_of_created_windows_type_2 > 0)
		fields[2 * number_of_created_windows_type_2].get()->last_field_counter(counter, all_filled);
}

bool Work_with_window::button_enter_values()
{
	double counter = 0;
	vector<double> values;
	vector<double> probs;
	for (int i = 2; i <= 1 + 2*number_of_created_windows_type_2; ++i)
	{
		if (fields[i].get()->get_text_value_length() == 0)
			return false;
		if (fields[i].get()->get_field_name() == "Prob.")
		{
			counter += fields[i].get()->get_double_value();
			probs.push_back(fields[i].get()->get_double_value());
		}
		else {
			values.push_back(fields[i].get()->get_double_value());
		}
	}
	
	if (abs(counter - 100) > 0.0001)
		return false;
	algo_simple = shared_ptr<Algorithm_simple_probability>(new Algorithm_simple_probability(number_of_created_windows_type_2, probs, values));
	return true;
}

void Work_with_window::help_enter_values()
{
	for (int j = buttons.size() - 1; j > 0; --j)
		if (buttons[j].get()->get_name() == "Enter values")
			break;
		else if (buttons[j].get()->get_name() == "Number of tests:")
		{
			buttons.pop_back();
			fields[fields.size() - 1].get()->clear_text();
			fields.pop_back();
		}
		else
			buttons.pop_back();

	for (int j = 0; j < base_buttons.size(); ++j)
		if (base_buttons[j].get()->get_name() == "Expected value:")
		{
			buttons.push_back(base_buttons[j]);
			buttons[buttons.size() - 1].get()->add_value(algo_simple.get()->get_expected_value());
		}
		else if (base_buttons[j].get()->get_name() == "Variance:")
		{
			buttons.push_back(base_buttons[j]);
			buttons[buttons.size() - 1].get()->add_value(algo_simple.get()->get_variance());
		}
		else if (base_buttons[j].get()->get_name() == "Number of tests:")
		{
			buttons.push_back(base_buttons[j]);
			fields.push_back(base_fields[2]);
		}
		else if (base_buttons[j].get()->get_name() == "Go!")
		{
			buttons.push_back(base_buttons[j]);
			buttons[buttons.size() - 1].get()->set_position(172, 360);
		}
		else if (base_buttons[j].get()->get_name() == "Save")
		{
			buttons.push_back(base_buttons[j]);
			fields.push_back(base_fields[4]);
		}
}

int Work_with_window::get_pos_base_button(string val)
{
	for (int i = 0; i < base_buttons.size(); ++i)
		if (base_buttons[i].get()->get_name() == val)
			return i;
	return -1;
}

int Work_with_window::get_pos_base_fields(string val)
{
	for (int i = 0; i < base_fields.size(); ++i)
		if (base_fields[i].get()->get_field_name() == val)
			return i;
	return -1;
}


void Work_with_window::create_tests(int number)
{
	algo_simple.get()->generate_tests(number);
	help_create_tests();
}

void Work_with_window::help_create_tests()
{
	vector<double> temp = algo_simple.get()->get_tests();
	int hash_test = get_pos_base_button("Test#"), hash_val = get_pos_base_button("Values"), cur = 210, step = 35;
	for (int i = 0; i < (int)temp.size(); ++i)
	{
		shared_ptr<ButtonDraw> temp_button = shared_ptr<ButtonDraw>(new ButtonDraw(base_buttons[hash_test]));
		temp_button.get()->set_position(cur, 280);
		temp_button.get()->set_text(i + 1, true);
		buttons.push_back(temp_button);
		temp_button.reset();
		temp_button = shared_ptr<ButtonDraw>(new ButtonDraw(base_buttons[hash_val]));
		temp_button.get()->set_position(cur, 280 + 180);
		temp_button.get()->set_text(temp[i], false, false);
		buttons.push_back(temp_button);
		cur += step;
	}
}

void Work_with_window::delete_buttons_simple(int i)
{
	if (algo_simple != nullptr && fields[i].get()->get_field_name() != "Number of tests" && fields[i].get()->get_field_name() != "Save")
	{
		cout << i << '\n';
		algo_simple.reset();
		for (int j = buttons.size() - 1; j > 0; --j)
		{
			string temp = buttons[j].get()->get_name();
			if (temp == "#")
				break;
			else if (temp == "Save" || temp == "Number of tests:")
			{
				buttons.pop_back();
				fields[fields.size() - 1].get()->clear_text();
				fields.pop_back();
			}
			else if (temp == "Variance:" || temp == "Expected value:" || temp == "Test#" || temp == "Values" || temp == "Go!")
				buttons.pop_back();
		}
	}
	else if (fields[i].get()->get_field_name() == "Number of tests")
	{
		for (int j = buttons.size() - 1; j > 0; --j)
		{
			string temp = buttons[j].get()->get_name();
			cout << '\n' << temp << '\n';
			if (temp == "Go!")
				break;
			if (temp == "Test#" || temp == "Values")
				buttons.pop_back();
		}
	}
}

void Work_with_window::delete_buttons_in_graph(int number)
{
	if (number == 0)
	{
		int i = 0;
		while (buttons[i].get()->get_name() != "Go!")
			++i;
		++i;
		while (buttons.size() > i)
			buttons.pop_back();
		while (fields.size() > 1)
			fields.pop_back();
	}
}

void Work_with_window::render_opened_file(ifstream &fin)
{
	int n;
	fin >> n;
	fields[0].get()->set_text(to_string(n));
	create_fields(n);
	double prob, my_event;
	for (int i = 0; i < n; ++i)
	{
		fin >> prob >> my_event;
		string s;
		if (i < n - 1)
		{
			prob *= 100.0;
			s = to_string(prob);
			while (s.length() > 6)
				s.pop_back();
			if (s[s.length() - 1] == '.')
				s.pop_back();
			fields[2 * i + 2].get()->set_text(s,false);
		}
		else
			check_last_prob_field();
		s = to_string(my_event);
		while (s.length() > 6)
			s.pop_back();
		if (s[s.length() - 1] == '.')
			s.pop_back();
		fields[2 * i + 3].get()->set_text(s,false);
	}
	if (button_enter_values())
	{
		help_enter_values();
		fin >> n;
		if (n != 0) 
		{
			for (int i = 0; i < fields.size(); ++i)
				if (fields[i].get()->get_field_name() == "Number of tests")
				{
					fields[i].get()->set_text(to_string(n));
					break;
				}
			algo_simple.get()->set_tests(fin, n);
			help_create_tests();
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
	int temp = need_to_create_window;
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
