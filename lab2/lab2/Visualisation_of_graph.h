#pragma once
#include "Algorithm_graph.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Visualisation_of_graph
{
	shared_ptr<RenderTexture> image;
	vector<shared_ptr<CircleShape> > vertexes;
	vector<shared_ptr<Text> > number;
	vector<shared_ptr<RectangleShape> > edges;
	shared_ptr<CircleShape> pointer;	
	shared_ptr<Font> font;

	void next_values(double &x, double &y, double center_x, double center_y, double len, double rad);
public:
	Visualisation_of_graph(shared_ptr<Algorithm_graph> graph);
	void draw(shared_ptr<RenderWindow> window);
	~Visualisation_of_graph();
};

