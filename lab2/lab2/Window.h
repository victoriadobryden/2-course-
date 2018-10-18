#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

void main_part()
{
	RenderWindow window(VideoMode(1200, 600), "Probability theory", Style::None);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		window.clear();
		window.display();
	}

}