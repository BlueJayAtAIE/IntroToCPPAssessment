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

	textureLibrary();
};


struct gameVariableHolder
{
	// The dimentions of both sides of the square board.
	static int gridSize;

	// Records the player who won, to print it to the screen and add to the w/l ratio.
	static int playerWin;

	// Allows the round to keep looping between player turns.
	static bool gameOn;

	// Toggles upon the claiming of the cell, to push on to the next turn.
	static bool playerDone;

	// Keeps track of who's turn it currently is. 0 = Player one, 1 = Player 2.
	static bool playerOnesTurn;
};

int ** newGrid(size_t size);

bool operator==(const Color lhs, const Color rhs);
bool operator!=(const Color lhs, const Color rhs);

// These are used in setting up the player customization buttons.
Color pickColor(const size_t i);