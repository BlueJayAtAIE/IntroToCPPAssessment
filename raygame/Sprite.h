#pragma once
#include "raylib.h"
#include "utils.h"
#include <iostream>

class Sprite : public Vector2
{
public:
	Sprite();
	Sprite(const char filename[], Vector2 pos, float scale, Color color);
	~Sprite();

	virtual void Draw();

protected:
	Texture2D texture;
	float spriteScale;
	Color spriteColor;
};

