#include "Sprite.h"


Sprite::Sprite()
{
	// Default placeholder Magenta square.
	Image temp = LoadImage("Square.png");
	texture = LoadTextureFromImage(temp);
	x = 0;
	y = 0;
	spriteScale = 1;
	spriteColor = MAGENTA;
}

Sprite::Sprite(const char filename[], Vector2 pos, float scale, Color color)
{
	Image temp = LoadImage(filename);
	texture = LoadTextureFromImage(temp);
	UnloadImage(temp);
	x = pos.x;
	y = pos.y;
	spriteScale = scale;
	spriteColor = color;
}

Sprite::~Sprite()
{
	UnloadTexture(texture);
}

void Sprite::Draw()
{
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void Sprite::Update()
{

}
