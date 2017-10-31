#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>

const int SIZE = 40;

using namespace sf;
using namespace std;

struct coordinate {
	int y, x, Wight, Height;
	int leftPx, topPx;
};

class Map {
private: 
	coordinate SqMap[SIZE];

public:
	friend ifstream& operator >>(ifstream &, Map &);
};

ifstream& operator >> (ifstream &ifs, Map &obj)
{
	for (int i = 0; i < SIZE; i++) {
		ifs >> obj.SqMap[i].x;
		ifs >> obj.SqMap[i].y;
		ifs >> obj.SqMap[i].Wight;
		ifs >> obj.SqMap[i].Height;
		ifs >> obj.SqMap[i].leftPx;
		ifs >> obj.SqMap[i].topPx;
	}

	return ifs;
}

int main() {
	RenderWindow App; 
	App.create(VideoMode::getDesktopMode(), "Monopoly");

	Font fnt_Arial;
	if (!fnt_Arial.loadFromFile("fonts/arial.ttf"))
	{
		cout << "Cannot load font fonts/arial.ttf" << endl;
	}
	Text text("", fnt_Arial, 20);
	text.setStyle(Text::Bold);

	Texture txt_map;
	if (!txt_map.loadFromFile("images/map.png"))
	{
		cout << "Cannot load images/map.png" << endl;
	}
	txt_map.setSmooth(false);
	txt_map.setRepeated(true);

	ifstream ifs;
	Map map;
	ifs.open("Coordinat Map.txt", ios::in);

	if (!ifs)
	{
		cout << "Error, file is not founded\n";
		return -1;
	}

	ifs >> map;

	ifs.close();

	Sprite spr_map;
	spr_map.setTexture(txt_map);
	spr_map.setScale(Vector2f(0.45f, 0.45f));
	spr_map.setPosition(385, 6);


	while (App.isOpen())
	{
		Event event;
		while (App.pollEvent(event))
		{
			if (event.type == Event::Closed)
				App.close();
		}

		App.clear(Color::Color(128,193,243));
		App.draw(spr_map);
		App.display();
	}

	return 0;
}