#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>

const int SIZE = 40;

using namespace sf;
using namespace std;

struct coordinate {
	int x, y;
	int Wight, Height;
	int leftPx, topPx;
	double vec2f1, vec2f2;
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

class Player {
private:
	//coordinate 
	long Money;
	int Factories;
	string Name;

public:
	Player();
	Player(string);
};

Player::Player() {
	Money = 2000;
	Name = "Player";
}

Player::Player(string Name) {
	Money = 2000;
	this->Name = Name;
}

class Tokens {
private:
	coordinate CoorTok[6];

public:
	friend ifstream& operator >>(ifstream &, Tokens &);
};

ifstream& operator >> (ifstream &ifs, Tokens &obj)
{
	for (int i = 0; i < 6; i++) {
		ifs >> obj.CoorTok[i].x;
		ifs >> obj.CoorTok[i].y;
		ifs >> obj.CoorTok[i].Wight;
		ifs >> obj.CoorTok[i].Height;
		ifs >> obj.CoorTok[i].leftPx;
		ifs >> obj.CoorTok[i].topPx;

	}

	return ifs;
}

void newGame(RenderWindow &window) {
	Texture tex_Plcol[14];/*, tex_Plcol2, tex_Plcol3, tex_Plcol4*/
	for (int i = 0; i < 14; i++) {
		if (i < 4)
			tex_Plcol[i].loadFromFile("images/color.png");
		if (i > 3 && i < 8)
			tex_Plcol[i].loadFromFile("images/Back3.png");
		if (i > 7)
			tex_Plcol[i].loadFromFile("images/tokens.tga");
	}

	Sprite spr_Plcol[14];
	for (int i = 0; i < 14; i++) 
			spr_Plcol[i].setTexture(tex_Plcol[i]);
	
	for (int i = 0; i < 14; i++) {
		if (i == 0) {
			spr_Plcol[i].setTextureRect(IntRect(55, 104, 58, 58));
			spr_Plcol[i].setPosition(80, 100);
		}

		if (i == 1) {
			spr_Plcol[i].setTextureRect(IntRect(130, 104, 58, 58));
			spr_Plcol[i].setPosition(1228, 100);
		}

		if (i == 2) {
			spr_Plcol[i].setTextureRect(IntRect(205, 104, 58, 58));
			spr_Plcol[i].setPosition(80, 200);
		}

		if (i == 3) {
			spr_Plcol[i].setTextureRect(IntRect(281, 104, 58, 58));
			spr_Plcol[i].setPosition(1228, 200);
		}

		if (i > 3 && i < 8) {
			spr_Plcol[i].setTextureRect(IntRect(0, 0, 120, 58));
			
			if (i == 4)
				spr_Plcol[i].setPosition(138, 100);
			if (i == 5)
				spr_Plcol[i].setPosition(1108, 100);
			if (i == 6)
				spr_Plcol[i].setPosition(138, 200);
			if (i == 7)
				spr_Plcol[i].setPosition(1108, 200);
		}

		if (i == 8) {
			spr_Plcol[i].setTextureRect(IntRect(74, 65, 103, 106));
			spr_Plcol[i].setScale(Vector2f(0.56f, 0.547f));
			spr_Plcol[i].setPosition(80, 100);
		}

		if (i == 9) {
			spr_Plcol[i].setTextureRect(IntRect(231, 26, 171, 156));
			spr_Plcol[i].setScale(Vector2f(0.34f, 0.37f));
			spr_Plcol[i].setPosition(1228, 100);
		}

		if (i == 10) {
			spr_Plcol[i].setTextureRect(IntRect(486, 75, 113,87));
			spr_Plcol[i].setScale(Vector2f(0.513f, 0.666f));
			spr_Plcol[i].setPosition(80, 200);
		}

		if (i == 11) {
			spr_Plcol[i].setTextureRect(IntRect(30, 195, 140, 123));
			spr_Plcol[i].setScale(Vector2f(0.414f, 0.47f));
			spr_Plcol[i].setPosition(1228, 200);
		}

		if (i == 12) {
			spr_Plcol[i].setTextureRect(IntRect(251, 237, 123, 74));
			spr_Plcol[i].setScale(Vector2f(0.47f, 0.783f));
			//spr_Plcol[i].setPosition(80, 100);
		}

		if (i == 13) {
			spr_Plcol[i].setTextureRect(IntRect(480, 225, 155, 81));
			spr_Plcol[i].setScale(Vector2f(0.374f, 0.716f));
			//spr_Plcol[i].setPosition(80, 100);
		}
	}

	Texture menuTexture4, menuBackground;
	menuTexture4.loadFromFile("images/4.png");
	menuBackground.loadFromFile("images/back1.png");
	Sprite menu2(menuTexture4), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0, i = 0;

	menu2.setPosition(80, 360);
	menuBg.setPosition(0, 0);

	string Play = "Play", NotPlay = "Not Selecting" ;

	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text1("", fnt_Arial, 14), text2("", fnt_Arial, 14), text3("", fnt_Arial, 14), text4("", fnt_Arial, 14);
	
	
	//text.setColor(Color::White);
	text1.setStyle(Text::Bold);
	text1.setString(NotPlay);
	text1.setPosition(150, 120);

	text2.setStyle(Text::Bold);
	text2.setString(NotPlay);
	text2.setPosition(1110, 120);

	text3.setStyle(Text::Bold);
	text3.setString(NotPlay);
	text3.setPosition(150, 220);

	text4.setStyle(Text::Bold);
	text4.setString(NotPlay);
	text4.setPosition(1110, 220);

	int i = 0;

	while (isMenu) {
		menuNum = 0;
		window.clear();

		if (IntRect(80, 100, 58, 58).contains(Mouse::getPosition(window))) 
			menuNum = 1;
		if	(IntRect(1228, 100, 58, 58).contains(Mouse::getPosition(window)))
			menuNum = 2;
		if	(IntRect(80, 200, 58, 58).contains(Mouse::getPosition(window)))
			menuNum = 3;
		if	(IntRect(1228, 200, 58, 58).contains(Mouse::getPosition(window)))
			menuNum = 4;
		
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (menuNum == 1) {
				i++;
				if (i == 6)
					i = 0;
				if()

			}

			if (menuNum == 2) {

			}

			if (menuNum == 3) {

			}

			if (menuNum == 4) {

			}
		}

		window.draw(menuBg);
		window.draw(menu2);

		for(int i = 0; i < 12; i++)
		window.draw(spr_Plcol[i]);

		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		
		window.display();

	}

	
	
	//Texture menuTexture1, menuTexture4, menuBackground;
	//menuTexture1.loadFromFile("images/1color.png");
	//menuTexture4.loadFromFile("images/4.png");
	//menuBackground.loadFromFile("images/back1.png");
	//Sprite menu1, menu2(menuTexture4), menuBg(menuBackground);
	//menu1.setTexture(menuTexture1);
	//bool isMenu = 1;
	//int menuNum = 0, i = 0;

	//menu1.setTextureRect(IntRect(55, 104, 58, 58));
	//menu1.setPosition(80, 100);
	//menu2.setPosition(80, 360);
	//menuBg.setPosition(0, 0);
	////////////////////////////////МЕНЮ///////////////////
	//menu1.setColor(Color::Blue);
	//while (isMenu)
	//{
	//	menu2.setColor(Color::White);
	//	menuNum = 0;
	//	window.clear();
	//	if (IntRect(80, 100, 58, 58).contains(Mouse::getPosition(window))) {
	//		menuNum = 1;
	//	}
	//	if (IntRect(80, 360, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
	//	if (Mouse::isButtonPressed(Mouse::Left))
	//	{
	//		if (menuNum == 1) {
	//			i++;
	//			if (i > 3)
	//				i = 0;
	//			if (i == 0)
	//				menu1.setColor(Color::Blue);
	//			if (i == 1)
	//				menu1.setColor(Color::Red);
	//			if (i == 2)
	//				menu1.setColor(Color::Yellow);
	//			if (i == 3)
	//				menu1.setColor(Color::Green);
	//			
	//			sleep(*new Time(milliseconds(200)));

	//		}//если нажали первую кнопку, то выходим из меню 
	//		if (menuNum == 2) { window.close(); isMenu = false; }
	//	}
	//	window.draw(menuBg);
	//	window.draw(menu1);
	//	window.draw(menu2);
	//	window.display();
	//}
}

void menu(RenderWindow &window) {
	Texture menuTexture1, menuTexture2, menuTexture3, menuBackground;
	menuTexture1.loadFromFile("images/1.png");
	menuTexture2.loadFromFile("images/2.png");
	menuTexture3.loadFromFile("images/3.png");
	menuBackground.loadFromFile("images/intro.tga");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(80, 300);
	menu2.setPosition(80, 360);
	menu3.setPosition(80, 420);
	menuBg.setPosition(0, 0);
	menuBg.setScale(Vector2f(1.7f, 1.225f));
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));
		if (IntRect(80, 300, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(80, 360, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(80, 420, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { 
				newGame(window);
				isMenu = false; }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(menu2); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}

int main() {
	RenderWindow App; 
	App.create(VideoMode::getDesktopMode(), "Monopoly");
	menu(App);

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

	Texture tex_tokens;
	if (!tex_tokens.loadFromFile("images/tokens.tga"))
	{
		cout << "Cannot load images/tokens.tga" << endl;
	}

	Texture tex_background;
	tex_background.loadFromFile("images/back.png");

	string num_player = "Select number player :\n Press 2, 3 or 4\n";
	text.setString(num_player);

	Sprite spr_tokens, spr_backgr;
	spr_tokens.setTexture(tex_tokens);
	spr_backgr.setTexture(tex_background);
	spr_backgr.setPosition(0, 0);
	

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

		App.clear();
		App.draw(spr_backgr);
			App.draw(spr_map);
			spr_tokens.setTextureRect(IntRect(227, 18, 183, 167));
			spr_tokens.setScale(Vector2f(0.3f, 0.3f));
			spr_tokens.setPosition(990, 585);
			App.draw(spr_tokens);

			spr_tokens.setTextureRect(IntRect(44, 44, 149, 149));
			spr_tokens.setScale(Vector2f(0.3f, 0.3f));
			spr_tokens.setPosition(990, 610);
			App.draw(spr_tokens);
		//}
		
		
		App.display();
	}

	return 0;
}