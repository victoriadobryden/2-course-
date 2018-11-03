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
	int height, width, number_of_buttons, size_x, size_y;
	bool flag_for_picture, flag_for_text;
	fin >> width >> height;
	window.create(VideoMode(width,height),name,Style::None);

	fin >> number_of_buttons;
	for (int i = 0; i < number_of_buttons; ++i)
	{
		fin >> name;
		fin >> width >> height >> size_x >> size_y;
		fin >> flag_for_picture;
		if (flag_for_picture)
			getline(fin, file_picture_name);
		fin >> flag_for_text;
		cout << name << ' ' << width << ' ' << height << ' ' << size_x << ' ' << size_y << ' ' << flag_for_picture << ' ';
		cout << file_picture_name << ' ' << flag_for_text << '\n';
		ButtonDraw temp(name, width, height, size_x, size_y, flag_for_picture, file_picture_name, flag_for_text);
	}
}

void Work_with_window::work()
{
	if (window.hasFocus())
	{
		Event event;
		if (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed || event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}
	}
	window.clear(Color(30, 30, 30));
	draw();
	window.display();
}

void Work_with_window::draw()
{
	for (int i = 0; i < buttons.size(); ++i)
	{
		buttons[i].draw(window);
	}
}

bool Work_with_window::is_open()
{
	return window.isOpen();
}


Work_with_window::~Work_with_window()
{
}
