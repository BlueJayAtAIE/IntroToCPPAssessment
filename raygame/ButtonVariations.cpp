#include "ButtonVariations.h"

// Tic-Tac-Toe Cell Button.
TTT::TTT() : Button() { }

TTT::TTT(Texture2D tex, Vector2 pos, float scale, Color color, Vector2 ID) : Button(tex, pos, scale, color)
{ 
	cellID.x = ID.x;
	cellID.y = ID.y;
	claimedBy = 0;
}

TTT::~TTT() { }

void TTT::Draw()
{
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void TTT::Update(Player player, bool &turnEnd)
{
	// On being clicked, it disables itself from being clicked again, "claims" the cell, and ends the turn.
	if (CheckForClick() && clickable)
	{
		clickable = false;

		claimedBy = player.playerNumber;
		spriteColor = player.playerColor;
		texture = player.playerShape;
		turnEnd = true;
	}

	// On being hovered over and unclicked before, the color will change.
	if (CheckForHover() && clickable)
	{
		// TODO placeholder maybe?
		spriteColor = YELLOW;
	}
	else if (clickable)
	{
		spriteColor = LIGHTGRAY;
	}
}

// -----------------------------------------------------------------------------------------------------------------------------
// Grid size configuration button.
GridSizeSelect::GridSizeSelect(Texture2D tex, Vector2 pos, float scale, Color color, int size) : Button(tex, pos, scale, color)
{
	grid = size;
}

GridSizeSelect::~GridSizeSelect() { }

void GridSizeSelect::Draw()
{
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void GridSizeSelect::Update(int &sizeToChange)
{
	// Once one of the buttons has changed the grid size, this will disable all the others.
	if (sizeToChange > 0)
	{
		clickable = false;
	}
	else
	{
		clickable = true;
	}

	// On being clicked, set the grid size accordingly.
	if (CheckForClick() && clickable)
	{
		setGridSize(sizeToChange);
	}

	// On being hovered over and unclicked before, the color will change.
	if (CheckForHover() && clickable)
	{
		spriteColor = YELLOW;
	}
	else
	{
		spriteColor = LIGHTGRAY;
	}
}

void GridSizeSelect::setGridSize(int &final)
{
	final = grid;
}

// -----------------------------------------------------------------------------------------------------------------------
// Player configuration button: color.
PlayerColorSelect::PlayerColorSelect() { }

PlayerColorSelect::PlayerColorSelect(Texture2D tex, Vector2 pos, float scale, Color color) : Button(tex, pos, scale, color) 
{ 
	baseColor = color;
}

PlayerColorSelect::~PlayerColorSelect() { }

void PlayerColorSelect::Draw()
{
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void PlayerColorSelect::Update(Player &playerToChange)
{
	if (playerToChange.playerColor != baseColor)
	{
		clickable = true;
		spriteColor = baseColor;
	}

	if ((CheckForClick() && clickable) || playerToChange.playerColor == baseColor)
	{
		playerToChange.playerColor = baseColor;
		clickable = false;
		spriteColor = DARKGRAY;
	}

	if (CheckForHover() && clickable)
	{
		spriteColor = LIGHTGRAY;
	}
	else if (clickable)
	{
		spriteColor = baseColor;
	}
}

// -------------------------------------------------------------------------------------------------------------------------
PlayerShapeSelect::PlayerShapeSelect() { }

PlayerShapeSelect::PlayerShapeSelect(Texture2D tex, Vector2 pos, float scale, Color color, std::string baseName) : Button(tex, pos, scale, color)
{
	baseTex = tex;
	baseTexName = baseName;
}

PlayerShapeSelect::~PlayerShapeSelect() { }

void PlayerShapeSelect::Draw()
{
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void PlayerShapeSelect::Update(Player & playerToChange)
{
	if (playerToChange.playerShapeName != baseTexName)
	{
		clickable = true;
		spriteColor = GRAY;
	}

	if ((CheckForClick() && clickable) || playerToChange.playerShapeName == baseTexName)
	{
		playerToChange.playerShape = baseTex;
		playerToChange.playerShapeName = baseTexName;
		clickable = false;
		spriteColor = DARKGRAY;
	}

	if (CheckForHover() && clickable)
	{
		spriteColor = LIGHTGRAY;
	}
	else if (clickable)
	{
		spriteColor = GRAY;
	}
}
