#pragma once
#include <iostream>
#include "utils.h" 
#include "raylib.h"

class Sprite : public Vector2
{
public:
	Sprite();
	Sprite(Texture2D tex, Vector2 pos, float scale, Color color);
	~Sprite();

	virtual void Draw();
	virtual void Update();

protected:
	Texture2D texture;
	float spriteScale;
	Color spriteColor;
};

