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
	virtual void Update() override;

	bool CheckForClick();
	bool CheckForHover();

protected:
	Rectangle hitbox;
	bool clickable = true;
};

