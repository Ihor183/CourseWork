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
//private: 
	

public:
	coordinate SqMap[SIZE];
	//friend ofstream& operator << (ofstream &, String &);
	friend ifstream& operator >>(ifstream &, Map &);
	Map getCoordinate() {
		
	}
	Sprite BuildMap(Texture *txt_map, Sprite *spr_map) {
		SqMap[0].x = 1305;
		SqMap[0].y = 1305;
		SqMap[0].Wight = 200;
		SqMap[0].Height = 200;
		SqMap[0].leftPx = 945;
		SqMap[0].topPx = 600;
		spr_map[0].setTexture(*txt_map);
		spr_map[0].setTextureRect(IntRect(SqMap[0].x, SqMap[0].y, SqMap[0].Wight, SqMap[0].Height));
		spr_map[0].setScale(Vector2f(0.45f, 0.45f));
		spr_map[0].setPosition(SqMap[0].leftPx, SqMap[0].topPx);
		
		for (int i = 1; i < SIZE; i++) {
			if (i < 10)
			{
				SqMap[i].x = SqMap[i - 1].x - 123;
				SqMap[i].y = SqMap[i - 1].y;
				SqMap[i].Wight = SqMap[0].Wight - 76;
				SqMap[i].Height = SqMap[i - 1].Height;
				spr_map[i].setTexture(*txt_map);
				spr_map[i].setTextureRect(IntRect(SqMap[i].x, SqMap[i].y, SqMap[i].Wight, SqMap[i].Height));
				spr_map[i].setScale(Vector2f(0.45f, 0.45f));
				spr_map[i].setPosition(SqMap[i].leftPx = SqMap[i - 1].leftPx - 55.8, SqMap[i].topPx = SqMap[0].topPx);
			}
		    if (i == 10) {
				SqMap[i].x = SqMap[i - 1].x - 198;
				SqMap[i].y = SqMap[i - 1].y;
				SqMap[i].Wight = SqMap[0].Wight;
				SqMap[i].Height = SqMap[i - 1].Height;
				spr_map[i].setTexture(*txt_map);
				spr_map[i].setTextureRect(IntRect(SqMap[i].x, SqMap[i].y, SqMap[i].Wight, SqMap[i].Height));
				spr_map[i].setScale(Vector2f(0.45f, 0.45f));
				spr_map[i].setPosition(SqMap[i].leftPx = SqMap[i - 1].leftPx - 90, SqMap[i].topPx = SqMap[0].topPx);
			}

			if (i > 10 && i < 20) {
				SqMap[i].x = SqMap[10].x;  // = 0
				SqMap[i].y = SqMap[i - 1].y - 123;  // 1305 - 123 = 1182
				SqMap[i].Wight = SqMap[i - 1].Wight;  
				SqMap[i].Height = SqMap[0].Height - 76;
				spr_map[i].setTexture(*txt_map);
				spr_map[i].setTextureRect(IntRect(SqMap[i].x, SqMap[i].y, SqMap[i].Wight, SqMap[i].Height));
				spr_map[i].setScale(Vector2f(0.45f, 0.45f));
				spr_map[i].setPosition(SqMap[i].leftPx = SqMap[10].leftPx, SqMap[i].topPx = SqMap[i - 1].topPx - 55.8);
			}

			if (i == 20) {
				SqMap[i].x = SqMap[10].x;
				SqMap[i].y = SqMap[i - 1].y - 198;
				SqMap[i].Wight = SqMap[0].Wight;
				SqMap[i].Height = SqMap[0].Height;
				spr_map[i].setTexture(*txt_map);
				spr_map[i].setTextureRect(IntRect(SqMap[i].x, SqMap[i].y, SqMap[i].Wight, SqMap[i].Height));
				spr_map[i].setScale(Vector2f(0.45f, 0.45f));
				spr_map[i].setPosition(SqMap[i].leftPx = SqMap[10].leftPx/* + 34.2*/, SqMap[i].topPx = SqMap[i - 1].topPx - 90);
				SqMap[i].leftPx += 34.2;
			}

			if (i > 20 && i < 30) {
				SqMap[i].x = SqMap[i - 1].x + 123;  // = 
				SqMap[21].x = 198;
				SqMap[i].y = SqMap[10].x;  // = 0
				SqMap[i].Wight = SqMap[0].Wight - 76;
				SqMap[i].Height = SqMap[i - 1].Height;
				spr_map[i].setTexture(*txt_map);
				spr_map[i].setTextureRect(IntRect(SqMap[i].x, SqMap[i].y, SqMap[i].Wight, SqMap[i].Height));
				spr_map[i].setScale(Vector2f(0.45f, 0.45f));
				spr_map[i].setPosition(SqMap[i].leftPx = SqMap[i - 1].leftPx + 56.8, SqMap[i].topPx = SqMap[20].topPx);
			}

			if (i == 30) {
				SqMap[i].x = SqMap[0].x;
				SqMap[i].y = SqMap[10].x ;
				SqMap[i].Wight = SqMap[0].Wight;
				SqMap[i].Height = SqMap[0].Height;
				spr_map[i].setTexture(*txt_map);
				spr_map[i].setTextureRect(IntRect(SqMap[i].x, SqMap[i].y, SqMap[i].Wight, SqMap[i].Height));
				spr_map[i].setScale(Vector2f(0.45f, 0.45f));
				spr_map[i].setPosition(SqMap[i].leftPx = SqMap[i - 1].leftPx + 55.8, SqMap[i].topPx = SqMap[20].topPx /*+ 34.2*/);
				SqMap[i].topPx += 34.2;
			}

			if (i > 30 && i < 40) {
				SqMap[i].x = SqMap[0].x;  // = 0
				SqMap[i].y = SqMap[i - 1].y + 123;  // 1305 - 123 = 1182
				SqMap[31].y = 198;
				SqMap[i].Wight = SqMap[i - 1].Wight;
				SqMap[i].Height = SqMap[0].Height - 76;
				spr_map[i].setTexture(*txt_map);
				spr_map[i].setTextureRect(IntRect(SqMap[i].x, SqMap[i].y, SqMap[i].Wight, SqMap[i].Height));
				spr_map[i].setScale(Vector2f(0.45f, 0.45f));
				spr_map[i].setPosition(SqMap[i].leftPx = SqMap[30].leftPx, SqMap[i].topPx = SqMap[i - 1].topPx + 56.8);
			}

			/*if (i == 40) {
				SqMap[i].x = 200;
				SqMap[i].y = 200;
				SqMap[i].Wight = 1110;
				SqMap[i].Height = 1110;
				spr_map[i].setTexture(*txt_map);
				spr_map[i].setTextureRect(IntRect(SqMap[i].x, SqMap[i].y, SqMap[i].Wight, SqMap[i].Height));
				spr_map[i].setScale(Vector2f(0.45f, 0.45f));
				spr_map[i].setPosition(444, 99);
			}*/

		}

		return *spr_map;
	}
};

ifstream& operator >> (ifstream &ifs, Map &obj)
{
	for (int i = 0; i < SIZE; i++) {
		ifs >> obj.SqMap[i].x;
		ifs >> obj.SqMap[i].y;
		ifs >> obj.SqMap[i].Wight;
		ifs >> obj.SqMap[i].Height;
	}

	return ifs;
}

int main() {
	RenderWindow App; 
	App.create(VideoMode::getDesktopMode(), "Monopoly");

	ifstream ifs;

	Font fnt_Arial;
	if (!fnt_Arial.loadFromFile("fonts/arial.ttf"))
	{
		cout << "Cannot load font fonts/arial.ttf" << endl;
	}
	Text text("", fnt_Arial, 20);
	//text.setColor(Color::Red);
	text.setStyle(Text::Bold);

	Texture txt_map;
	if (!txt_map.loadFromFile("images/map.png"))
	{
		cout << "Cannot load images/map.png" << endl;
	}

	/*Map map;
	ifs.open("Coordinat Map.txt", ios::in);

	if (!ifs)
	{
		cout << "Error, file is not founded\n";
		return -1;
	}

	ifs >> map;

	ifs.close();*/

	/*int i = 0;
	text.setString(to_string(i));*/

	txt_map.setSmooth(false);
	txt_map.setRepeated(true);

	Sprite *spr_map = new Sprite[SIZE];

	while (App.isOpen())
	{
		Event event;
		while (App.pollEvent(event))
		{
			if (event.type == Event::Closed)
				App.close();
		}

		App.clear(Color::Color(128,193,243));
		Map map;
		map.BuildMap(&txt_map, spr_map);

		/*for (int i = 0; i < SIZE; i++) {
			App.draw(spr_map[i]);
		}*/
		for (int i = 0; i < SIZE; i++) {
			text.setPosition(0, i * 17);
			text.setString(to_string(map.SqMap[i].y));
			App.draw(text);
		}

		//App.draw(text);
		
		App.display();
	}

	return 0;
}