#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"Coordinate.h"
#include"DescriptionOfRectangles.h"
#include"CoordGo.h"

const int SIZE = 40;
const int FOUR = 4;

using namespace std;

class Map : public DescriptionOfRectangles{
private:
	Coordinate SqMap[SIZE];
	vector<DescriptionOfRectangles> map;
	CoordGo go[FOUR][SIZE];

public:
	Map();
	~Map();
	friend ifstream& operator >>(ifstream &, Map &);
};

