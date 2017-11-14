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

void newGame(RenderWindow &window) {
	Texture menuTexture1, menuTexture4, menuBackground;
	menuTexture1.loadFromFile("images/1color.png");
	menuTexture4.loadFromFile("images/4.png");
	menuBackground.loadFromFile("images/back1.png");
	Sprite menu1(menuTexture1), menu2(menuTexture4), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setTextureRect(IntRect(55, 104, 58, 58));
	menu1.setPosition(80, 100);
	menu2.setPosition(80, 360);
	menuBg.setPosition(0, 0);
	menuBg.setScale(Vector2f(1.7f, 1.225f));
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::Red);
		menu2.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));
		if (Mouse::isButtonPressed(Mouse::Left) && IntRect(80, 100, 300, 50).contains(Mouse::getPosition(window))) {
			menu1.setTextureRect(IntRect(130, 104, 58, 58));
		}
		if (IntRect(80, 360, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {

				isMenu = false;
			}//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.close(); isMenu = false; }
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.display();
	}
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
	//spr_tokens.setTextureRect(IntRect(44, 44, 149, 149));
	//spr_tokens.setScale(Vector2f(0.3f, 0.3f));
	//spr_tokens.setPosition(990, 585);
	

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

		/*if (Keyboard::isKeyPressed(Keyboard::Left)) { spr_tokens.move(-0.5, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { spr_tokens.move(0.5, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { spr_tokens.move(0, 0.5); }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { spr_tokens.move(0, -0.5); }*/

		/*if (Mouse::isButtonPressed(Mouse::Left))
			spr_tokens.move(-1, 0);*/

		App.clear(/*Color::Color(0, 0, 0)*/);
		//App.draw(text);
		//if (Keyboard::isKeyPressed(Keyboard::Num2)) {
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