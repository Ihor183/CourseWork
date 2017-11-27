#include "Map.h"

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

	return ifs;
}

void Map::DescRect() {
	//map = new DescriptionOfRectangles[SIZE];
	int temp;
	bool var = false;

	for (int i = 0; i < SIZE; i++) {
		switch (i) {
		case 0: temp = 200; break;
		case 1: temp = 200; break;
		case 3: temp = 200; break;
		case 4: temp = 200; break;
		case 5: temp = 200; break;
		case 6: temp = 200; break;
		case 8: temp = 200; break;
		case 9: temp = 200; break;
		case 11: temp = 200; break;
		case 12: temp = 200; break;
		case 13: temp = 200; break;
		case 14: temp = 200; break;
		case 15: temp = 200; break;
		case 16: temp = 200; break;
		case 18: temp = 200; break;
		case 19: temp = 200; break;
		case 21: temp = 200; break;
		case 23: temp = 200; break;
		case 24: temp = 200; break;
		case 25: temp = 200; break;
		case 26: temp = 200; break;
		case 27: temp = 200; break;
		case 28: temp = 200; break;
		case 29: temp = 200; break;
		case 31: temp = 200; break;
		case 32: temp = 200; break;
		case 34: temp = 200; break;
		case 35: temp = 200; break;
		case 37: temp = 200; break;
		case 38: temp = 200; break;
		case 39: temp = 200; break;
		
		}
		


	    map[i].setdata(temp);

	}
}
