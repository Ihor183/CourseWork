#include "Menu.h"

Menu::Menu() { }

Menu::~Menu() { }

Menu::Menu(RenderWindow& window) {
	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text[3];
	string NewGame = "New Game";
	string Options = "Options";
	string Exit = "Exit";

	for (int i = 0; i < 3; i++) {
		text[i].setFont(fnt_Arial);
		text[i].setCharacterSize(30);
		text[i].setStyle(Text::Bold);
		text[i].setFillColor(Color::Black);
	}

	text[0].setString(NewGame);
	text[0].setPosition(80, 300);
	text[1].setString(Options);
	text[1].setPosition(80, 360);
	text[2].setString(Exit);
	text[2].setPosition(80, 420);

	Texture menuBackground;
	menuBackground.loadFromFile("images/intro.tga");

	Sprite menuBg(menuBackground);
	menuBg.setPosition(0, 0);
	menuBg.setScale(Vector2f(1.7f, 1.225f));

	bool isMenu = 1;
	int menuNum = 0;

	while (window.isOpen() && isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		for (int i = 0; i < 3; i++) 
			text[i].setFillColor(Color::Black);

		menuNum = 0;

		window.clear();
		if (IntRect(80, 300, 300, 50).contains(Mouse::getPosition(window))) { text[0].setFillColor(Color::White); menuNum = 1; }
		if (IntRect(80, 360, 300, 50).contains(Mouse::getPosition(window))) { text[1].setFillColor(Color::Green); menuNum = 2; }
		if (IntRect(80, 420, 300, 50).contains(Mouse::getPosition(window))) { text[2].setFillColor(Color::Blue); menuNum = 3; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				NewMenu(window);
				isMenu = false;
			}
			if (menuNum == 2) { /*window.draw(menu2);*/ window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }
		}
		window.draw(menuBg);
		for (int i = 0; i < 3; i++)
			window.draw(text[i]);
		window.display();

	}
}

void Menu :: NewMenu(RenderWindow& window) {
	Texture tex_Plcol[8], tex_Token[4], menuBackground;
	menuBackground.loadFromFile("images/back1.png");
	for (int i = 0; i < 8; i++) {
		if (i < 4) {
			tex_Token[i].loadFromFile("images/tokens.tga");
			tex_Plcol[i].loadFromFile("images/color.png");
		}
		if (i > 3) tex_Plcol[i].loadFromFile("images/Back3.png");
	}

	Sprite spr_Plcol[8], spr_Token[4]/*, menu2(menuTexture4)*/, menuBg(menuBackground);
	//menu2.setPosition(80, 360);
	menuBg.setPosition(0, 0);
	for (int i = 0; i < 8; i++) {
		if (i < 4) {
			spr_Plcol[i].setTexture(tex_Plcol[i]);
			spr_Token[i].setTexture(tex_Token[i]);
		}else spr_Plcol[i].setTexture(tex_Plcol[i]);
	}

	for (int i = 0; i < 8; i++) {
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

		if (i > 3) { spr_Plcol[i].setTextureRect(IntRect(0, 0, 120, 58));

			if (i == 4) spr_Plcol[i].setPosition(138, 100);
			if (i == 5) spr_Plcol[i].setPosition(1108, 100);
			if (i == 6) spr_Plcol[i].setPosition(138, 200);
			if (i == 7) spr_Plcol[i].setPosition(1108, 200);
		}
	}
	int a[4], b[4], c[4], d[4];
	double e[4], f[4];

	for (int i = 0; i < 4; i++){
		a[i] = 0, b[i] = 0, c[i] = 1, d[i] = 1, e[i] = 0.0, f[i] = 0.0;
	}

	for (int i = 0; i < 4; i++) {
		spr_Token[i].setTextureRect(IntRect(a[i], b[i], c[i], d[i]));
		if (i == 0) spr_Token[i].setPosition(80, 100);
		if (i == 1) spr_Token[i].setPosition(1228, 100);
		if (i == 2) spr_Token[i].setPosition(80, 200);
		if (i == 3) spr_Token[i].setPosition(1228, 200);
	}

	Tokens tokens;
	ifstream ifs;
	ifs.open("Tokens.txt", ios::in);
	if (!ifs)
		return;

	ifs >> tokens;
	ifs.close();

	bool isMenu = 1;
	int menuNum = 0, i = 0;

	string Select = "Select";
	string NotSelect = "Not Selecting";
	string Play = "Play";
	string Back = "Back";

	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text[6];
	for (int i = 0; i < 6; i++) {
		if (i > 3) {
			text[i].setFont(fnt_Arial);
			text[i].setCharacterSize(30);
			text[i].setStyle(Text::Bold);

			if (i == 4) {
				text[i].setString(Play);
				text[i].setPosition(600, 300);
			}
			if (i == 5) {
				text[i].setString(Back);
				text[i].setPosition(600, 360);
			}

			continue;
		}
		text[i].setFont(fnt_Arial);
		text[i].setCharacterSize(14);
		text[i].setStyle(Text::Bold);
		text[i].setString(NotSelect);
	}

	text[0].setPosition(150, 120);
	text[1].setPosition(1110, 120);
	text[2].setPosition(150, 220);
	text[3].setPosition(1110, 220);

	int isSelect[4] = { 0, 0, 0, 0 };

	while (window.isOpen() && isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
        menuNum = 0;
		window.clear();

		for (int i = 0; i < 6; i++) 
			text[i].setFillColor(Color::Black);

		if (IntRect(138, 100, 120, 58).contains(Mouse::getPosition(window))) {
			text[0].setFillColor(Color::White);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (isSelect[0] == 0) {
					isSelect[0] = 1;
					text[0].setString(Select);
				}
				else {
					isSelect[0] = 0;
					text[0].setString(NotSelect);

					a[0] = 0, b[0] = 0, c[0] = 1, d[0] = 1, e[0] = 0.0, f[0] = 0.0;
					spr_Token[0].setTextureRect(IntRect(a[0], b[0], c[0], d[0]));
					spr_Token[0].setPosition(80, 100);
				}
			}
			sleep(*new Time(milliseconds(150)));
		}

		if (IntRect(1108, 100, 120, 58).contains(Mouse::getPosition(window))) {
			text[1].setFillColor(Color::White);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (isSelect[1] == 0) {
					isSelect[1] = 1;
					text[1].setString(Select);
				}
				else {
					isSelect[1] = 0;
					text[1].setString(NotSelect);

					a[1] = 0, b[1] = 0, c[1] = 1, d[1] = 1, e[1] = 0.0, f[1] = 0.0;
					spr_Token[1].setTextureRect(IntRect(a[1], b[1], c[1], d[1]));
					spr_Token[1].setPosition(1228, 100);
				}
			}
			sleep(*new Time(milliseconds(150)));
		}

		if (IntRect(138, 200, 120, 58).contains(Mouse::getPosition(window))) {
			text[2].setFillColor(Color::White);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (isSelect[2] == 0) {
					isSelect[2] = 1;
					text[2].setString(Select);
				}
				else {
					isSelect[2] = 0;
					text[2].setString(NotSelect);

					a[2] = 0, b[2] = 0, c[2] = 1, d[2] = 1, e[2] = 0.0, f[2] = 0.0;
					spr_Token[2].setTextureRect(IntRect(a[2], b[2], c[2], d[2]));
					spr_Token[2].setPosition(80, 200);
				}
			}
			sleep(*new Time(milliseconds(150)));
		}

		if (IntRect(1108, 200, 120, 58).contains(Mouse::getPosition(window))) {
			text[3].setFillColor(Color::White);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (isSelect[3] == 0) {
					isSelect[3] = 1;
					text[3].setString(Select);
				}
				else {
					isSelect[3] = 0;
					text[3].setString(NotSelect);

					a[3] = 0, b[3] = 0, c[3] = 1, d[3] = 1, e[3] = 0.0, f[3] = 0.0;
					spr_Token[3].setTextureRect(IntRect(a[3], b[3], c[3], d[3]));
					spr_Token[3].setPosition(1228, 200);
				}
			}
			sleep(*new Time(milliseconds(150)));
		}

		if (IntRect(80, 100, 58, 58).contains(Mouse::getPosition(window)))   menuNum = 1;
		if (IntRect(1228, 100, 58, 58).contains(Mouse::getPosition(window))) menuNum = 2;
		if (IntRect(80, 200, 58, 58).contains(Mouse::getPosition(window)))   menuNum = 3;
		if (IntRect(1228, 200, 58, 58).contains(Mouse::getPosition(window))) menuNum = 4;
		
		if (IntRect(600, 300, 300, 50).contains(Mouse::getPosition(window))) { 
			text[4].setFillColor(Color::White);
			int count = 0, countT = 0;
			for (int i = 0; i < 4; i++) {
				if (isSelect[i] == 1) count++;
				if (a[i] != 0)        countT++;
			}
			if(count >= 2 && countT >= 2) menuNum = 5;
		}
		
		if (IntRect(600, 360, 300, 50).contains(Mouse::getPosition(window))) { text[5].setFillColor(Color::White); menuNum = 6; }
        if (Mouse::isButtonPressed(Mouse::Left)) {
			
			if (menuNum == 1 && isSelect[0] == 1) {
				tokens.getToken(&a[0], &b[0], &c[0], &d[0], &e[0], &f[0]);
				spr_Token[0].setTextureRect(IntRect(a[0], b[0], c[0], d[0]));
				spr_Token[0].setScale(Vector2f(e[0], f[0]));
				spr_Token[0].setPosition(80, 100);
				sleep(*new Time(milliseconds(200)));
			}

			if (menuNum == 2 && isSelect[1] == 1) {
				tokens.getToken(&a[1], &b[1], &c[1], &d[1], &e[1], &f[1]);
				spr_Token[1].setTextureRect(IntRect(a[1], b[1], c[1], d[1]));
				spr_Token[1].setScale(Vector2f(e[1], f[1]));
				spr_Token[1].setPosition(1228, 100);
				sleep(*new Time(milliseconds(200)));
			}

			if (menuNum == 3 && isSelect[2] == 1) {
				tokens.getToken(&a[2], &b[2], &c[2], &d[2], &e[2], &f[2]);
				spr_Token[2].setTextureRect(IntRect(a[2], b[2], c[2], d[2]));
				spr_Token[2].setScale(Vector2f(e[2], f[2]));
				spr_Token[2].setPosition(80, 200);
				sleep(*new Time(milliseconds(200)));
			}

			if (menuNum == 4 && isSelect[3] == 1) {
				tokens.getToken(&a[3], &b[3], &c[3], &d[3], &e[3], &f[3]);
				spr_Token[3].setTextureRect(IntRect(a[3], b[3], c[3], d[3]));
				spr_Token[3].setScale(Vector2f(e[3], f[3]));
				spr_Token[3].setPosition(1228, 200);
				sleep(*new Time(milliseconds(200)));
			}

			if (menuNum == 5) { 
				for (int i = 0; i < 4; i++) {
					DataTokens[i].x = a[i];
					DataTokens[i].y = b[i];
					DataTokens[i].Wight = c[i];
					DataTokens[i].Height = d[i];
					DataTokens[i].vec2f1 = e[i];
					DataTokens[i].vec2f2 = f[i];
				}
				 isMenu = false; 
				}

			if (menuNum == 6) window.close(); 
			
		}

		window.draw(menuBg);

		for (int i = 0; i < 8; i++) window.draw(spr_Plcol[i]);
        for (int i = 0; i < 4; i++) window.draw(spr_Token[i]);
		for (int i = 0; i < 6; i++) window.draw(text[i]);

		window.display();
	}
}

void Menu::GetDataTokens(int* a, int* b, int* c, int* d, double* e, double* f) {
	for (int i = 0; i < 4; i++) {
		a[i] = DataTokens[i].x;
		b[i] = DataTokens[i].y;
		c[i] = DataTokens[i].Wight;
		d[i] = DataTokens[i].Height;
		e[i] = DataTokens[i].vec2f1;
		f[i] = DataTokens[i].vec2f2;
	}
}