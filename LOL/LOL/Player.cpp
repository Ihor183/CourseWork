#include "Player.h"



Player::Player() {
	money = 2000;
	position = 0;
	start = false;
}

Player::~Player() { }

bool Player::GetStart() {
	return start;
}