#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ButtonDraw.h"

#include <vector>
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int NMAX = 1;

void render(ButtonDraw temp_buttons[])
{
	string name;
	int pos_h, pos_w;
	freopen("Data\\Buttons\\information.txt", "r", stdin);
	int k = 0;
	while (cin >> name >> pos_w >> pos_h && k < NMAX)
	{
		name = "Data\\Buttons\\" + name;
		temp_buttons[k].set_information(name,pos_w,pos_h);
		++k;
	}
	temp_buttons[0].output();
	fclose(stdin);
}

void main_part()
{
	ButtonDraw buttons[NMAX];
	render(buttons);

	RenderWindow window(VideoMode(1200, 600), "Probability theory", Style::None);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		window.clear(Color(128,128,128));
		for (int i = 0;i < NMAX; ++i)
			buttons[i].draw(window);
		window.display();
	}
	
	window.clear();
}