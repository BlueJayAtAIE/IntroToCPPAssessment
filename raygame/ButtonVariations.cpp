#include "ButtonVariations.h"
#include <iostream>

TTT::TTT() : Button() { }

TTT::TTT(const char filename[], Vector2 pos, float scale, Color color, Vector2 ID) : Button(filename, pos, scale, color) 
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

void TTT::Update()
{
	if (CheckForClick() && clickable)
	{
		// change playerDone to true
		clickable = false;
		// TODO, claimed will change to the number of the player whose turn it is.
		claimedBy = 1;
		// TODO, the symbol will change to the symbol prefered by the player whose turn it is.
		Image temp = LoadImage("X.png");
		texture = LoadTextureFromImage(temp);
		UnloadImage(temp);
		// TODO, the color will change to the color prefered by the player whose turn it is.
		spriteColor = GREEN;
	}

	// On being hovered over and unclicked before, the color will change.
	if (CheckForHover() && clickable)
	{
		// TODO placeholder maybe?
		spriteColor = YELLOW;
	}
	else
	{
		spriteColor = GRAY;
	}
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
	DrawTextureEx(texture, Vector2{ x, y }, 0, spriteScale, spriteColor);
}

void GridSizeSelect::Update()
{
	// Once one of the buttons has changed the grid size, this will disable all the others.
	//if (game.gridSize > 0)
	//{
	//	clickable = false;
	//}

	// On being clicked, set the grid size accordingly.
	if (CheckForClick() && clickable)
	{
		//game.gridSize = -1;
		//std::cout << "gggggggggggg" << game.gridSize << std::endl;
		std::cout << "ggg" << std::endl;
		//setGridSize(game.gridSize);
	}

	// On being hovered over and unclicked before, the color will change.
	if (CheckForHover() && clickable)
	{
		spriteColor = LIGHTGRAY;
	}
	else
	{
		spriteColor = GRAY;
	}
}

void GridSizeSelect::setGridSize(int &final)
{
	std::cout << "gridSize should now be " << grid << std::endl;
	final = grid;
	//std::cout << "gridSize is ACTUALLY " << game.gridSize << std::endl;
}

