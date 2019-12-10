#include "utils.h"

int gameVariableHolder::gridSize;
int gameVariableHolder::playerWin;
bool gameVariableHolder::gameOn;
bool gameVariableHolder::playerDone;
bool gameVariableHolder::playerOnesTurn;

// -------------------------------------
// TEXTURE BANK

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

bool operator==(const Color lhs, const Color rhs)
{
	if (lhs.r != rhs.r || lhs.g != rhs.g || lhs.b != rhs.b || lhs.a != rhs.a) return false;
	return true;
}

bool operator!=(const Color lhs, const Color rhs)
{
	if (lhs.r != rhs.r || lhs.g != rhs.g || lhs.b != rhs.b || lhs.a != rhs.a) return true;
	return false;
}

Color pickColor(const size_t i)
{
	switch (i)
	{
	case 0:
		return RED;
		break;
	case 1:
		return ORANGE;
		break;
	case 2:
		return GOLD;
		break;
	case 3:
		return GREEN;
		break;
	case 4:
		return LIME;
		break;
	case 5:
		return BLUE;
		break;
	case 6:
		return PURPLE;
		break;
	case 7:
		return PINK;
		break;
	default:
		return GRAY;
		break;
	}
}