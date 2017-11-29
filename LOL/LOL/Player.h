#pragma once
#include<vector>
#include"Dice.h"

using namespace std;

class Player : public Dice {
private:
	bool start;
	long money;
	int position;
	//vector<int> firm;

public:
	Player();
	~Player();
	void setMoney(int);
	void setPosition(int);
};

