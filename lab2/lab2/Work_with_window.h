#pragma once
#include "ButtonDraw.h"
#include "Input_field.h"

#include <SFML/Graphics.hpp>
#include <fstream>

using namespace sf;
using namespace std;

class Work_with_window
{
	shared_ptr<RenderWindow> window;
	vector<shared_ptr<ButtonDraw> > buttons;
	vector<shared_ptr<Input_field> > base_fields;
	vector<shared_ptr<Input_field> > fields;
	string information;
	int need_to_create_window;
	int number_of_created_windows_type_2;

	void create_fields(int number);
public:
	Work_with_window();
	Work_with_window(string &file);
	void work();
	void check_buttons_under_cursor(int pos_w, int pos_h);
	void check_buttons_is_pressed(int pos_w, int pos_h, bool is_pressed);
	void check_buttons_is_released(int pos_w, int pos_h);
	void check_fields_under_cursor(int pos_w, int pos_h);
	void check_fields_is_released(int pos_w, int pos_h);
	void check_fields_entered_text(char temp);
	void check_fields_enter();
	void draw_frame_for_window(shared_ptr<RenderWindow> window);
	void draw();
	int need_new_window();
	bool is_open();
	~Work_with_window();
};

