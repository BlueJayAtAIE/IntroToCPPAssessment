#include "Player.h"

Player::Player(std::string playerFile, Texture2D shape, std::string shapeName, Color color, int number)
{
	// TODO, learn reading from file for name and w/l ratio.

	playerShape = shape;
	playerShapeName = shapeName;
	playerColor = color;
	playerNumber = number;
}

Player::~Player()
{
}
