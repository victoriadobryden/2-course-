#include "Work_with_window.h"


Work_with_window::Work_with_window()
{

}

Work_with_window::Work_with_window(string &file)
{
	information = file;
	ifstream fin(file);
	string name, file_picture_name = "";
	getline(fin,name);
	int height, width, number_of_buttons;
	fin >> width >> height;
	window = shared_ptr<RenderWindow>(new RenderWindow(VideoMode(height,width),name,Style::None));

	fin >> number_of_buttons;
	for (int i = 0; i < number_of_buttons; ++i)
	{
		shared_ptr<ButtonDraw> temp = shared_ptr<ButtonDraw>(
			new ButtonDraw(fin));
		buttons.push_back(temp);
	}
	fin.close();
}

void Work_with_window::work()
{
	if (window.get()->hasFocus())
	{
		Event event;
		if (window->pollEvent(event)) 
		{
			if (event.type == Event::Closed || event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape))
				window.get()->close();
			if (event.type == Event::MouseMoved)
			{
				check_buttons_under_cursor(event.mouseMove.y, event.mouseMove.x);
				cout << event.mouseMove.x << ' ' << event.mouseMove.y << '\n';
			}
			if (event.type == Event::MouseButtonPressed)
			{
				cout << "pressed\n";
				check_buttons_is_pressed(event.mouseButton.y, event.mouseButton.x);
				cout << event.mouseButton.x << ' ' << event.mouseButton.y << '\n';		
			}
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

void Work_with_window::check_buttons_is_pressed(int pos_w, int pos_h)
{
	for (int i = 0; i < buttons.size(); ++i)
	{
		buttons[i].get()->mouse_is_pressed(pos_w,pos_h,window);
	}
}

void Work_with_window::draw()
{
	for (int i = 0; i < buttons.size(); ++i)
	{
		buttons[i].get()->draw(window);
	}
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
