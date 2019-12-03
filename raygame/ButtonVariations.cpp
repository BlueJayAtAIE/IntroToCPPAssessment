#include "ButtonVariations.h"
#include <iostream>

TTT::TTT() : Button() { }

TTT::TTT(const char filename[], Vector2 pos, float scale, Color color, Vector2 ID) : Button(filename, pos, scale, color) 
{ 
	cellID.x = ID.x;
	cellID.y = ID.y;
}

TTT::~TTT()
{
	UnloadTexture(texture);
}

void TTT::Draw()
{
	if (CheckForClick() && clickable)
	{
		clickable = false;
		// TODO, the symbol will change to the symbol prefered by the player whose turn it is.
		Image temp = LoadImage("X.png");
		texture = LoadTextureFromImage(temp);
		UnloadImage(temp);
		// TODO, the color will change to the color prefered by the player whose turn it is.
		spriteColor = GREEN;
	}
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

GridSizeSelect::GridSizeSelect()
{

}

GridSizeSelect::GridSizeSelect(const char filename[], Vector2 pos, float scale, Color color, int size) : Button(filename, pos, scale, color)
{
	grid = size;
}

GridSizeSelect::~GridSizeSelect()
{
	UnloadTexture(texture);
}

void GridSizeSelect::Draw()
{
	if (gridSize > 0)
	{
		clickable = false;
	}
	if (CheckForClick() && clickable)
	{
		setGridSize(gridSize);
	}
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void GridSizeSelect::setGridSize(int &final)
{
	std::cout << "gridSize should now be " << grid << std::endl;
	final = grid;
	std::cout << "gridSize is ACTUALLY " << gridSize << std::endl;
}

