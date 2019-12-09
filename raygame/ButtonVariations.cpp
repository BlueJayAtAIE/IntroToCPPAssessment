#include "ButtonVariations.h"

TTT::TTT() : Button() { }

TTT::TTT(Texture2D tex, Vector2 pos, float scale, Color color, Vector2 ID) : Button(tex, pos, scale, color)
{ 
	cellID.x = ID.x;
	cellID.y = ID.y;
	claimedBy = 0;
}

TTT::~TTT()
{ }

void TTT::Draw()
{
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void TTT::Update(Player player, bool &turnEnd)
{
	if (CheckForClick() && clickable)
	{
		clickable = false;

		turnEnd = true;
		claimedBy = player.playerNumber;
		spriteColor = player.playerColor;
		texture = player.playerShape;
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

GridSizeSelect::GridSizeSelect()
{

}

GridSizeSelect::GridSizeSelect(Texture2D tex, Vector2 pos, float scale, Color color, int size) : Button(tex, pos, scale, color)
{
	grid = size;
}

GridSizeSelect::~GridSizeSelect()
{
	UnloadTexture(texture);
}

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

