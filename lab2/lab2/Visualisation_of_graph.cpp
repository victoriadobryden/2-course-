#include "Visualisation_of_graph.h"

const double pi = 3.1415926535;

void Visualisation_of_graph::next_values(double &x, double &y, double center_x, double center_y, double len, double rad)
{
	if (abs(center_x - x) < 0.0001)
	{
		y = (len*len - rad * rad) / (2 * (center_y - y)) + (center_y + y)/2;
		x = sqrt(rad*rad - (y - center_y)*(y - center_y)) + center_x;		
		bool ok = true;
		for (int j = 0; j < vertexes.size(); ++j)
		{
			Vector2f vec = vertexes[j].get()->getPosition();
			if (abs(vec.x - x) < 0.0001 && abs(vec.y - y) < 0.0001)
			{
				ok = false;
				break;
			}
		}
		if (!ok)
			x = -sqrt(rad*rad - (y - center_y)*(y - center_y)) + center_x;
	}
	else if (abs(center_y - y) < 0.0001)
	{
		x = (len*len - rad * rad) / (2 * (center_x - x)) + (center_x + x)/2;
		y = sqrt(rad*rad - (x - center_x)*(x - center_x)) + center_y;
		bool ok = true;
		for (int j = 0; j < vertexes.size(); ++j)
		{
			Vector2f vec = vertexes[j].get()->getPosition();
			if (abs(vec.x - x) < 0.0001 && abs(vec.y - y) < 0.0001)
			{
				ok = false;
				break;
			}
		}
		if (!ok)
			y = -sqrt(rad*rad - (x - center_x)*(x - center_x)) + center_y;
	}
	else
	{
		double temp = rad * rad - len * len + y * y - center_y * center_y + x * x - center_x * center_x;
		double l = -(y - center_y) / (x - center_x), m = temp / (2 * (x - center_x))- center_x;
		double z = (l*l + 1),
			p = 2 * (l*m - center_y),
			q = m * m + center_y * center_y - rad * rad;
		double D = p * p - 4 * q*z;
		D = sqrt(D);
		y = (-p + D) / (2 * z);
		x = m + center_x + y * l;
		bool ok = true;
		for (int j = 0; j < vertexes.size(); ++j)
		{
			Vector2f vec = vertexes[j].get()->getPosition();
			if (abs(vec.x - x) < 0.0001 && abs(vec.y - y) < 0.0001)
			{
				ok = false;
				break;
			}
		}
		if (!ok)
		{
			y = (-p - D) / (2 * z);
			x = m + center_x + y * l;
		}
	}
}

Visualisation_of_graph::Visualisation_of_graph(shared_ptr<Algorithm_graph> graph)
{
	image = shared_ptr<RenderTexture>(new RenderTexture);
	image.get()->create(450, 450);
	int n = graph.get()->get_size();
	double len = 65, rad = (n == 1 ? 0 : len / (2 * sin(pi / n))), angle = 2 * pi / n;
	double x = 225, y = 225-rad, center_x = 225, center_y = 225;
	shared_ptr<CircleShape> temp;
	shared_ptr<Text> temp_text;
	font = shared_ptr<Font>(new Font);
	font.get()->loadFromFile("arial.ttf");
	for (int i = 0; i < n; ++i)
	{
		cout << x << ' ' << y << '\n';
		temp = shared_ptr<CircleShape>(new CircleShape);
		temp.get()->setRadius(14.f);
		temp.get()->setOutlineThickness(2.f);
		temp.get()->setFillColor(Color(0, 0, 0, 0));
		temp.get()->setOutlineColor(Color(0,200,200));
		temp.get()->setOrigin(14.f, 14.f);
		temp.get()->setPosition(x, y);
		vertexes.push_back(temp);
	
		temp_text = shared_ptr<Text>(new Text);
		temp_text.get()->setFont(*font);
		temp_text.get()->setString(to_string(i + 1));
		temp_text.get()->setCharacterSize(20);
		if (i + 1 < 10)
			temp_text.get()->setOrigin(6.f, 12.f);
		else if (i + 1 < 20)
			temp_text.get()->setOrigin(12.5f, 12.f);
		else
			temp_text.get()->setOrigin(11.f, 12.f);


		temp_text.get()->setPosition(x, y);
		number.push_back(temp_text);

		next_values(x, y, center_x, center_y, len, rad);
	}
	//for (int i = 0; )
}

void Visualisation_of_graph::draw(shared_ptr<RenderWindow> window)
{
	image.get()->clear(Color(10,10,10,0));
	for (int i = 0; i < (int)vertexes.size(); ++i) 
	{
		image.get()->draw(*vertexes[i]);
		image.get()->draw(*number[i]);
	}
	image.get()->display();
	Texture temp_texture;
	temp_texture = image.get()->getTexture();
	Sprite temp_sprite;
	temp_sprite.setTexture(temp_texture);
	temp_sprite.setPosition(340,50);
	window.get()->draw(temp_sprite);
}


Visualisation_of_graph::~Visualisation_of_graph()
{
	for (int i = (int)vertexes.size()-1;i >= 0; --i)
	{
		vertexes[i].reset();
		number[i].reset();
		vertexes.pop_back();
		number.pop_back();
	}
	for (int j = (int)edges.size() - 1; j >= 0; --j) 
	{
		edges[j].reset();
		edges.pop_back();
	}
	image.reset();
	font.reset();
	pointer.reset();
}
