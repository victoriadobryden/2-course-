#include "Visualisation_of_graph.h"



Visualisation_of_graph::Visualisation_of_graph(shared_ptr<Algorithm_graph> graph)
{
	image = shared_ptr<RenderTexture>(new RenderTexture);
	image.get()->create(450,450);
	image.get()->clear(Color(15, 15, 15));
//	for (int i = 0;i)
}

void Visualisation_of_graph::draw(shared_ptr<RenderWindow> window)
{
	image.get()->display();
	Texture temp_texture;;
	temp_texture = image.get()->getTexture();
	Sprite temp_sprite;
	temp_sprite.setTexture(temp_texture);
	temp_sprite.setPosition(340,50);
	window.get()->draw(temp_sprite);
}


Visualisation_of_graph::~Visualisation_of_graph()
{
}
