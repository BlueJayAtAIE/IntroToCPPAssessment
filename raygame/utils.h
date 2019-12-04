#pragma once
#include "raylib.h"
#include <iostream>

//class textureLibrary
//{
//public:
//	static Texture2D blank;
//	static Texture2D diamond;
//	static Texture2D o;
//	static Texture2D square;
//	static Texture2D star;
//	static Texture2D triangle;
//	static Texture2D x;
//
//	void textureSetup();
//
//	Texture2D getTexture(std::string filename);
//};

class gameVariableHolder
{
public:
	static int gridSize;
	static int playerWin;
	static bool gameOn;
	static bool playerDone;
};

int ** newGrid(size_t size);