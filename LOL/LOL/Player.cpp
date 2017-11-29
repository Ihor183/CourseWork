#include "Player.h"

Player::Player() {
	money = 2000;
	position = 0;
	start = false;
}

Player::~Player() { }

void Player::setMoney(int money) { this->money = money;  }
void Player::setPosition(int position) { 
	if(this->position + position < 40)
		this->position = position;  
	else {
		this->position += position;
		this->position -= 40;
	}
}