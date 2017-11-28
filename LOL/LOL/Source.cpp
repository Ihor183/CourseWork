#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include"Menu.h"
#include"Map.h"
#include"Dice.h"
#include"Player.h"

using namespace sf;
using namespace std;

std::string toStr(int var)
{
	std::stringstream tmp; tmp << var; return tmp.str();
}

int main() {
	RenderWindow App;
	App.create(VideoMode::getDesktopMode(), "Monopoly");
	int pos = 570, left = 300, top = 0, menuNum = 0;
	//Menu menu(App);

	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text("", fnt_Arial, 20);
	text.setStyle(Text::Bold);

	Texture txt_map, tex_tokens, tex_background, tex_Token[4], tex_Dice[6], tex_Button[10];
	txt_map.loadFromFile("images/map.png");
	tex_tokens.loadFromFile("images/tokens.tga");
	tex_background.loadFromFile("images/back.png");
	for (int i = 0; i < 10; i++)  tex_Button[i].loadFromFile("images/button" + toStr(i + 1) + ".png");
	for (int i = 0; i < 4; i++)   tex_Token[i].loadFromFile("images/tokens.tga");
	for (int i = 0; i < 6; i++)   tex_Dice[i].loadFromFile("images/de" + toStr(i + 1) + ".png");


	Sprite spr_tokens, spr_backgr, spr_map, spr_Token[4], spr_Dice[6], spr_Button[10];
	spr_tokens.setTexture(tex_tokens);
	spr_backgr.setTexture(tex_background);
	spr_map.setTexture(txt_map);
	spr_backgr.setPosition(0, 0);
    spr_map.setScale(Vector2f(0.45f, 0.45f));
	spr_map.setPosition(385, 6);

	for (int i = 0; i < 4; i++)  { spr_Token[i].setTexture(tex_Token[i]);  spr_Token[i].setPosition(990, pos += 20); }
	for (int i = 0; i < 6; i++)    spr_Dice[i].setTexture(tex_Dice[i]); 
	for (int i = 0; i < 10; i++) { spr_Button[i].setTexture(tex_Button[i]); spr_Button[i].setPosition(left, top += 60); }
	
	//spr_Dice[0].setPosition(600, 300); spr_Dice[1].setPosition(700, 300);

	ifstream ifs;
	Map map;
	ifs.open("Coordinat Map.txt", ios::in);
	if (!ifs)
		return -1;

	ifs >> map;
	ifs.close();
   // Menu menu(App);

	int a[4], b[4], c[4], d[4], control[2], j = 0;
	double e[4], f[4];

	//menu.GetDataTokens(a, b, c, d, e, f);

	for (int i = 0; i < 4; i++) if (a[i] == 0) { control[j] = i + 1; j++; }
	
	for (int i = 0; i < 4; i++) {
		 spr_Token[i].setTextureRect(IntRect(a[i], b[i], c[i], d[i]));
		 spr_Token[i].setScale(e[i] / 2, f[i] / 2);
	}

	int point[2];
	Dice dice;

	Player player;
	//player.GetStart();

	while (App.isOpen())
	{
		Event event;
		while (App.pollEvent(event))
		{
			if (event.type == Event::Closed)
				App.close();
		}
		menuNum = 0;

		App.clear();
		App.draw(spr_backgr);
		App.draw(spr_map);
		
		if (Keyboard::isKeyPressed(Keyboard::Num1)) {
			dice.ThrowDice(point);
			if (point[0] != point[1]) {
				spr_Dice[point[0] - 1].setPosition(600, 300);
				spr_Dice[point[1] - 1].setPosition(700, 300);
				App.draw(spr_Dice[point[0] - 1]);
				App.draw(spr_Dice[point[1] - 1]);
			}
			else {
				spr_Dice[point[0] - 1].setPosition(600, 300);
				App.draw(spr_Dice[point[0] - 1]);
				spr_Dice[point[0] - 1].setPosition(700, 300);
				App.draw(spr_Dice[point[1] - 1]);
			}
			

			/*sleep(*new Time(milliseconds(200)));*/
		}

		if (IntRect(300, 60, 58, 58).contains(Mouse::getPosition(App)))   menuNum = 1;
		if (IntRect(300, 120, 58, 58).contains(Mouse::getPosition(App)))   menuNum = 2;
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (menuNum == 1) {
				dice.ThrowDice(point);

				if (point[0] != point[1]) {
					spr_Dice[point[0] - 1].setPosition(600, 300);
					spr_Dice[point[1] - 1].setPosition(700, 300);
					App.draw(spr_Dice[point[0] - 1]);
					App.draw(spr_Dice[point[1] - 1]);
				}
				else {
					spr_Dice[point[0] - 1].setPosition(600, 300);
					App.draw(spr_Dice[point[0] - 1]);
					spr_Dice[point[0] - 1].setPosition(700, 300);
					App.draw(spr_Dice[point[1] - 1]);
				}
			}
			if (menuNum == 2) {

			}
		}

		/*if (player.GetStart() == false) {
			App.draw(spr_Button[0]);
			App.draw(spr_Button[7]);
			App.draw(spr_Button[8]);
			App.draw(spr_Button[9]);
		}*/
		
		for (int i = 0; i < 10; i++)
			App.draw(spr_Button[i]);

		/*for (int i = 0; i < 4; i++)
		App.draw(spr_Token[i]);
		*/

		App.display();
		sleep(*new Time(milliseconds(200)));
	}

	return 0;
}

