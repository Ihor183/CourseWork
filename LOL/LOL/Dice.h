#pragma once
class Dice {
private:
	int points[2];
public:
	Dice();
	~Dice();
	void ThrowDice(int*);
};

