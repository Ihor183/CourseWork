#pragma once
#include<iostream>

using namespace std;

struct Coordinate
{
	int x, y;
	int Wight, Height;
	int leftPx, topPx;
	double vec2f1, vec2f2;

	bool operator < (const Coordinate &point) const; 
	bool operator == (const Coordinate &point) const; 
};

