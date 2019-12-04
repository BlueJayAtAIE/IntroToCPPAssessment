#include "utils.h"

int gameVariableHolder::gridSize;
int gameVariableHolder::playerWin;
bool gameVariableHolder::gameOn;
bool gameVariableHolder::playerDone;

// TEXTURE BANK ------------------------
// TODO Currently doesn't work. It'd be nice if this was done before turn-in but 
// you might have the use the horribly ineffiecnt way just to save some time.

void textureSetup()
{
	Texture2D blank = LoadTexture("80x80Blank.png");
	Texture2D diamond = LoadTexture("Diamond.png");
	Texture2D o = LoadTexture("O.png");
	Texture2D square = LoadTexture("Square.png");
	Texture2D star = LoadTexture("Star.png");
	Texture2D triangle = LoadTexture("Triangle.png");
	Texture2D x = LoadTexture("X.png");
}

Texture2D getTexture(std::string filename)
{
	if (filename == "80x80Blank.png")
	{
		return blank;
	}
	if (filename == "Diamond.png")
	{
		return diamond;
	}
	if (filename == "O.png")
	{
		return o;
	}
	if (filename == "Square.png")
	{
		return square;
	}
	if (filename == "Star.png")
	{
		return star;
	}
	if (filename == "Triangle.png")
	{
		return triangle;
	}
	if (filename == "X.png")
	{
		return x;
	}
	return Texture2D();
}
// -------------------------------------

// TODO edit this to make a 2D array- whops
int ** newGrid(size_t size)
{
	int** arr = new int*[size];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = new int[size];

		for (size_t i = 0; i < size; i++)
		{
			// put zeros in each cell here.
		}
	}

	return arr;
}

