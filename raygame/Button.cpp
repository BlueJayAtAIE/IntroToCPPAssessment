#include "Button.h"

// Default constructor.
Button::Button() : Sprite() { }

// Paramiterized constructor.
Button::Button(const char filename[], Vector2 pos, float scale, Color color) : Sprite(filename, pos, scale, color)
{ 
	hitbox.x = x;
	hitbox.y = y;
	hitbox.height = texture.height;
	hitbox.width = texture.width;
}

Button::~Button()
{
	UnloadTexture(texture);
}

void Button::Draw()
{
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

bool Button::CheckForClick()
{
	bool temp = false;
	if (CheckCollisionPointRec(GetMousePosition(), hitbox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		temp = true;
	}
	return temp;
}
