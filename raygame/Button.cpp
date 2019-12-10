#include "Button.h"

// Default constructor.
Button::Button() : Sprite() { }

// Paramiterized constructor.
Button::Button(Texture2D tex, Vector2 pos, float scale, Color color) : Sprite(tex, pos, scale, color)
{ 
	hitbox.x = x;
	hitbox.y = y;
	hitbox.height = texture.height * scale;
	hitbox.width = texture.width * scale;
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
