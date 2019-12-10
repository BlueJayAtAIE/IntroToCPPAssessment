#include "utils.h"

int gameVariableHolder::gridSize;
int gameVariableHolder::playerWin;
bool gameVariableHolder::loopTurns;
bool gameVariableHolder::playerDone;
bool gameVariableHolder::playerOnesTurn;
bool gameVariableHolder::gameOn;

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

	fadeScreen = LoadTexture("FadeScreen.png");
	button = LoadTexture("200x80Blank.png");

	mainMenuBG = LoadTexture("MainMenu.png");
	level3x3BG = LoadTexture("LevelBG3x3.png");
	level4x4BG = LoadTexture("LevelBG4x4.png");
	level5x5BG = LoadTexture("LevelBG5x5.png");
	scrollingBG = LoadTexture("ScrollingBG.png");
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
		return VIOLET;
		break;
	case 7:
		return PINK;
		break;
	default:
		return GRAY;
		break;
	}
}

void scroll(float & X, float & Y, const float originalX, const float originalY)
{
	if (Y > 600)
	{
		X = originalX;
		Y = originalY;
	}
	X += 0.5f;
	Y += 0.5f;
}