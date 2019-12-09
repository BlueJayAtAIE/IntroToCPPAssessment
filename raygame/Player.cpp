#include "Player.h"

Player::Player(std::string playerFile, Texture2D shape, Color color, int number)
{
	// TODO, learn reading from file for name and w/l ratio.
	std::string test = "test";
	int testInt = test.length();
	playerShape = shape;
	playerColor = color;
	playerNumber = number;
}

Player::~Player()
{
}
