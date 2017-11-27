#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"Coordinate.h"
#include"DescriptionOfRectangles.h"

const int SIZE = 40;

using namespace std;

class Map : protected DescriptionOfRectangles{
private:
	Coordinate SqMap[SIZE];
	//DescriptionOfRectangles *map;
	vector<DescriptionOfRectangles> map;

public:
	Map();
	~Map();
	friend ifstream& operator >>(ifstream &, Map &);
	void DescRect();
};

