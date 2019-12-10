#pragma once
#include <iostream>
#include "raylib.h"

class textureLibrary
{
public:
	Texture2D blank;
	Texture2D diamond;
	Texture2D o;
	Texture2D square;
	Texture2D star;
	Texture2D triangle;
	Texture2D x;

	Texture2D fadeScreen;
	Texture2D button;

	Texture2D mainMenuBG;
	Texture2D level3x3BG;
	Texture2D level4x4BG;
	Texture2D level5x5BG;
	Texture2D scrollingBG;

	textureLibrary();
};


struct gameVariableHolder
{
	// The dimentions of both sides of the square board.
	static int gridSize;

	// Records the player who won, to print it to the screen and add to the w/l ratio.
	static int playerWin;

	// Allows the round to keep looping between player turns.
	static bool loopTurns;

	// Toggles upon the claiming of the cell, to push on to the next turn.
	static bool playerDone;

	// Keeps track of who's turn it currently is. 0 = Player one, 1 = Player 2.
	static bool playerOnesTurn;

	// Stops the game from closing unless a Quit Button is pressed.
	static bool gameOn;
};

int ** newGrid(size_t size);

bool operator==(const Color lhs, const Color rhs);
bool operator!=(const Color lhs, const Color rhs);

// These are used in setting up the player customization buttons.
Color pickColor(const size_t i);

// Controls the scrolling dots in the background.
void scroll(float &X, float &Y, const float originalX, const float originalY);