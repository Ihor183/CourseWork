#pragma once
#include<iostream>
#include<map>
#include"Coordinate.h"
#include<fstream>

using namespace std;

class Tokens {
private:
	map<Coordinate, bool> tokens;
	map<Coordinate, bool>::iterator itokens;

public:
	Tokens();
	~Tokens();
	friend ifstream& operator >>(ifstream &, Tokens &);
	void getToken(int*, int*, int*, int*, double*, double*);
};

