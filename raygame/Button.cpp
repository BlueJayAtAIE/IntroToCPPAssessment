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
	if (CheckCollisionPointRec(GetMousePosition(), hitbox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		return true;
	}
	return false;
}

bool Button::CheckForHover()
{
	if (CheckCollisionPointRec(GetMousePosition(), hitbox))
	{
		return true;
	}
	return false;
}

void Button::disable()
{
	clickable = false;
}
