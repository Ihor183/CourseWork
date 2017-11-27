#pragma once
#include<vector>

using namespace std;

class Player {
private:
	long money;
	int position;
	vector<int> firm;
	int cubes;

public:
	Player();
	~Player();
};

