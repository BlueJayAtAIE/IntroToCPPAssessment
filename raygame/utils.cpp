#include "utils.h"

int gameVariableHolder::gridSize;
int gameVariableHolder::playerWin;
bool gameVariableHolder::gameOn;
bool gameVariableHolder::playerDone;
bool gameVariableHolder::playerOnesTurn;

// TEXTURE BANK ------------------------
// TODO Currently doesn't work. It'd be nice if this was done before turn-in but 
// you might have the use the horribly ineffiecnt way just to save some time.

textureLibrary::textureLibrary()
{
	blank = LoadTexture("80x80Blank.png");
	diamond = LoadTexture("Diamond.png");
	o = LoadTexture("O.png");
	square = LoadTexture("Square.png");
	star = LoadTexture("Star.png");
	triangle = LoadTexture("Triangle.png");
	x = LoadTexture("X.png");
}

// -------------------------------------

int ** newGrid(size_t size)
{
	int** arr = new int*[size];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = new int[size];

		for (size_t j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}

	return arr;
}


