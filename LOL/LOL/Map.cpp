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
