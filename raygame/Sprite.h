#pragma once
#include "raylib.h"
#include "utils.h" 
#include <iostream>
//extern int gridSize;
//extern int playerWin;
//extern bool gameOn;
//extern bool playerDone;

class Sprite : public Vector2
{
public:
	Sprite();
	Sprite(const char filename[], Vector2 pos, float scale, Color color);
	~Sprite();

	virtual void Draw();
	virtual void Update();

protected:
	Texture2D texture;
	float spriteScale;
	Color spriteColor;
};

