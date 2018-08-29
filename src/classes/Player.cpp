#include "Player.h"

extern int MAP_WIDTH;
extern int MAP_HEIGHT;

Player::Player(int a, int b) {
	id = 3;
	disp = '@';
	priority = 99;
	x = a;
	y = b;
}

void Player::move(int deltaX, int deltaY) {
	if ((0 <= x + deltaX && x + deltaX < MAP_WIDTH) && true == true /*if it doesn't collide with anything*/) {
		x += deltaX;
	}

	if ((0 <= y + deltaY && y + deltaY < MAP_HEIGHT) && true == true /*if it doesn't collide with anything*/) {
		y += deltaY;
	}

}
