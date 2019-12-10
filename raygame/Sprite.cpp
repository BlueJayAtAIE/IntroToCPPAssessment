#include "Sprite.h"


Sprite::Sprite() { }

Sprite::Sprite(Texture2D tex, Vector2 pos, float scale, Color color)
{
	texture = tex;
	x = pos.x;
	y = pos.y;
	spriteScale = scale;
	spriteColor = color;
}

Sprite::~Sprite() { }

void Sprite::Draw()
{
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void Sprite::Update() { }
