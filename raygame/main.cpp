/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Sprite.h"
#include "ButtonVariations.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe!");

	SetTargetFPS(60);

	//textureSetup();

	gridSize = 0;
	playerWin = 0;
	gameOn = true;
	playerDone = false;
	
	GridSizeSelect testD("80x80Blank.png", Vector2{ 250, 200 }, 1, GRAY, 3);
	GridSizeSelect testE("80x80Blank.png", Vector2{ 350, 200 }, 1, GRAY, 4);
	GridSizeSelect testF("80x80Blank.png", Vector2{ 450, 200 }, 1, GRAY, 5);

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// START GAME
		//----------------------------------------------------------------------------------
		while (gridSize < 3)
		{
			// Display Grid Choices.
			BeginDrawing();

			ClearBackground(RAYWHITE);

			testD.Draw();
			DrawText("3", 280, 220, 48, BLACK);
			testE.Draw();
			DrawText("4", 380, 220, 48, BLACK);
			testF.Draw();
			DrawText("5", 480, 220, 48, BLACK);

			// Let players edit profile.
			// TODO

			EndDrawing();

			//std::cout << "gridSize is ACTUALLY " << gridSize << std::endl;
		}
		int* gameBoard = newGrid(gridSize);

		// Run through player turns.
		//----------------------------------------------------------------------------------
		while (gameOn)
		{
			// Wait for the player to make a valid move.
			while (!playerDone)
			{
				// Update
				//----------------------------------------------------------------------------------

				//----------------------------------------------------------------------------------

				// Draw
				//----------------------------------------------------------------------------------
				BeginDrawing();

				ClearBackground(RAYWHITE);

				// Draw grid and cells.
				// TODO

				EndDrawing();
				//----------------------------------------------------------------------------------
			}

			// Check
			//----------------------------------------------------------------------------------
			// Itterate through grid, checking for win
			// (refer to notepad for hypothesis on this).

			// If a win is detected, change the playerWin accordingly and set gameOn to false;
			// TODO
			
			//----------------------------------------------------------------------------------
			playerDone = false;
		}
		// END GAME
		//----------------------------------------------------------------------------------
		// Display who won. Add to win/lose ratio accordingly.

		gridSize = 0;
		delete[] gameBoard;

		// Give the option to continue or quit
		// TODO
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}