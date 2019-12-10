#pragma once
#include <iostream>
#include <string>
#include "raylib.h"

class Player
{
public:
	Player(std::string playerFile, Texture2D shape, std::string shapeName, Color color, int number);
	~Player();

	Texture2D playerShape;
	std::string playerShapeName;
	Color playerColor;
	int playerNumber;
};

