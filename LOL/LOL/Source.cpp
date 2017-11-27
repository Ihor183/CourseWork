#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include"Menu.h"
#include"Map.h"
#include"Dice.h"

using namespace sf;
using namespace std;

std::string toStr(int var)
{
	std::stringstream tmp; tmp << var; return tmp.str();
}

int main() {
	RenderWindow App;
	App.create(VideoMode::getDesktopMode(), "Monopoly");
	int pos = 570;
	//Menu menu(App);

	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text("", fnt_Arial, 20);
	text.setStyle(Text::Bold);

	Texture txt_map, tex_tokens, tex_background, tex_Token[4], tex_Dice[6];
	txt_map.loadFromFile("images/map.png");
	tex_tokens.loadFromFile("images/tokens.tga");
	tex_background.loadFromFile("images/back.png");
	for (int i = 0; i < 4; i++)   tex_Token[i].loadFromFile("images/tokens.tga");
	for (int i = 0; i < 6; i++)   tex_Dice[i].loadFromFile("images/de" + toStr(i + 1) + ".png");


	Sprite spr_tokens, spr_backgr, spr_map, spr_Token[4], spr_Dice[6];
	spr_tokens.setTexture(tex_tokens);
	spr_backgr.setTexture(tex_background);
	spr_map.setTexture(txt_map);
	spr_backgr.setPosition(0, 0);
    spr_map.setScale(Vector2f(0.45f, 0.45f));
	spr_map.setPosition(385, 6);
	for (int i = 0; i < 4; i++) { spr_Token[i].setTexture(tex_Token[i]);  spr_Token[i].setPosition(990, pos += 20); }
	for (int i = 0; i < 6; i++)   spr_Dice[i].setTexture(tex_Dice[i]);

	ifstream ifs;
	Map map;
	ifs.open("Coordinat Map.txt", ios::in);
	if (!ifs)
		return -1;

	ifs >> map;
	ifs.close();
   // Menu menu(App);

	int a[4], b[4], c[4], d[4];
	double e[4], f[4];

	//menu.GetDataTokens(a, b, c, d, e, f);
	
	for (int i = 0; i < 4; i++) {
		 spr_Token[i].setTextureRect(IntRect(a[i], b[i], c[i], d[i]));
		 spr_Token[i].setScale(e[i] / 2, f[i] / 2);
	}

		/*for (int i = 0; i < 4; i++)
			App.draw(spr_Token[i]);
*/
	int point[2];
	Dice dice;

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
		/*spr_tokens.setTextureRect(IntRect(227, 18, 183, 167));
		spr_tokens.setScale(Vector2f(0.3f, 0.3f));
		spr_tokens.setPosition(990, 585);
		App.draw(spr_tokens);

		spr_tokens.setTextureRect(IntRect(44, 44, 149, 149));
		spr_tokens.setScale(Vector2f(0.3f, 0.3f));
		spr_tokens.setPosition(990, 610);
		App.draw(spr_tokens);*/
		if (Keyboard::isKeyPressed(Keyboard::Num1)) {
			dice.ThrowDice(point);
			App.draw(spr_Dice[point[0] - 1]);
			App.draw(spr_Dice[point[1] - 1]);
		}
		
		

		/*for (int i = 0; i < 4; i++)
			App.draw(spr_Token[i]);*/
		App.display();
		//sleep(*new Time(milliseconds(1000)));
	}

	return 0;
}

