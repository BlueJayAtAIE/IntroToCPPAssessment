#pragma once
#include "Sprite.h"

class Button :
	public Sprite
{
public:
	Button();
	Button(const char filename[], Vector2 pos, float scale, Color color);
	~Button();

	virtual void Draw() override;

	bool CheckForClick();

protected:
	Rectangle hitbox;
	bool clickable = true;
};

