#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include "Tokens.h"

using namespace sf;
using namespace std;

class Menu {
private:


public:
	Menu();
	Menu(RenderWindow &);
	~Menu();
	void NewMenu(RenderWindow &);
};

