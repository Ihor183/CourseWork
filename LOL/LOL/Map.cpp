#include "Map.h"
#include<fstream>

Map::Map() { }


Map::~Map() { }

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

	for (int i = 0; i < SIZE; i++) {
		if (i != 0 && i != 2 && i != 4 && i != 5 && i != 7 && i != 10 &&
			i != 12 && i != 15 && i != 17 && i != 20 && i != 22 && i != 25 &&
			i != 28 && i != 30 && i != 33 && i != 35 && i != 36 && i != 38) {

			ifs >> obj.price;
			for (int j = 0; j < 6; j++)
				ifs >> obj.rent[j];

			ifs >> obj.housePrice >> obj.hotelPrice >> obj.mortgageValue;
			obj.money = 0;
			obj.buy = false;

		}
		else if (i == 0) {
			obj.money = 200;
			obj.price = 0;
			for (int j = 0; j < 6; j++) obj.rent[j] = 0;
			obj.housePrice = 0;
			obj.hotelPrice = 0;
			obj.mortgageValue = 0;
		}
		else if (i == 2 || i == 7 || i == 10 || i == 17 || i == 20 || i == 22 || i == 30 || i == 33 || i == 36) {
			obj.money = 0;
			obj.price = 0;
			for (int j = 0; j < 6; j++) obj.rent[j] = 0;
			obj.housePrice = 0;
			obj.hotelPrice = 0;
			obj.mortgageValue = 0;
		}
		else if (i == 4 || i == 38) {
			if (i == 4) obj.money = -200;
			else       obj.money = -100;
			obj.price = 0;
			for (int j = 0; j < 6; j++) obj.rent[j] = 0;
			obj.housePrice = 0;
			obj.hotelPrice = 0;
			obj.mortgageValue = 0;
		}

		else if (i == 5 || i == 15 || i == 25 || i == 35) {
			obj.price = 200;
			double k = 12.5;
			for (int j = 0; j < 6; j++) {
				if (j < 4) obj.rent[j] = k *= 2;
				else obj.rent[j] = 0;
			}
			obj.housePrice = 0;
			obj.hotelPrice = 0;
			obj.money = 0;
			obj.mortgageValue = 100;
		}
		obj.map.push_back(obj);
	}

	for (int i = 0; i < FOUR; i++) 
		for (int j = 0; j < SIZE; j++) 
			ifs >> obj.go[i][j].x >> obj.go[i][j].y;
		

	return ifs;
}

