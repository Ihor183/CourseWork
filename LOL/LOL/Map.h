#pragma once
#include<iostream>
#include<fstream>
#include"Coordinate.h"

const int SIZE = 40;

using namespace std;

class Map {
private:
	Coordinate SqMap[SIZE];
public:
	Map();
	~Map();
	friend ifstream& operator >>(ifstream &, Map &);
};

