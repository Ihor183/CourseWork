#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include"Menu.h"
#include"Map.h"

using namespace sf;
using namespace std;


int main() {
	RenderWindow App;
	App.create(VideoMode::getDesktopMode(), "Monopoly");
	Menu menu(App);

	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text("", fnt_Arial, 20);
	text.setStyle(Text::Bold);

	Texture txt_map, tex_tokens, tex_background;
	txt_map.loadFromFile("images/map.png");
	tex_tokens.loadFromFile("images/tokens.tga");
	tex_background.loadFromFile("images/back.png");

	Sprite spr_tokens, spr_backgr, spr_map;
	spr_tokens.setTexture(tex_tokens);
	spr_backgr.setTexture(tex_background);
	spr_map.setTexture(txt_map);
	spr_backgr.setPosition(0, 0);
    spr_map.setScale(Vector2f(0.45f, 0.45f));
	spr_map.setPosition(385, 6);
	
	ifstream ifs;
	Map map;
	ifs.open("Coordinat Map.txt", ios::in);
	if (!ifs)
		return -1;

	ifs >> map;
	ifs.close();

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
		


		App.display();
	}

	return 0;
}

