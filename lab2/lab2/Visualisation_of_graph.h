#pragma once
#include "Algorithm_graph.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Visualisation_of_graph
{
	shared_ptr<RenderTexture> image;
	vector<shared_ptr<CircleShape> > vertexes;
	vector<shared_ptr<RectangleShape> > edges;
	shared_ptr<CircleShape> pointer;	

public:
	Visualisation_of_graph(shared_ptr<Algorithm_graph> graph);
	void draw(shared_ptr<RenderWindow> window);
	~Visualisation_of_graph();
};

