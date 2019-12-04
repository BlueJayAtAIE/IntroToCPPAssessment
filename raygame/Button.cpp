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
{ }

void Button::Draw()
{
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void Button::Update()
{

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

bool Button::CheckForHover()
{
	bool temp = false;
	if (CheckCollisionPointRec(GetMousePosition(), hitbox))
	{
		temp = true;
	}
	return temp;
}
