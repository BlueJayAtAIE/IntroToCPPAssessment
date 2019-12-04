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

	gameVariableHolder game;// { 0, 0, true, false };
	gameVariableHolder::gridSize = 0;
	gameVariableHolder::playerWin = 0;
	gameVariableHolder::gameOn = true;
	gameVariableHolder::playerDone = false;

	GridSizeSelect testD("80x80Blank.png", Vector2{ 250, 200 }, 1, GRAY, 3);
	GridSizeSelect testE("80x80Blank.png", Vector2{ 350, 200 }, 1, GRAY, 4);
	GridSizeSelect testF("80x80Blank.png", Vector2{ 450, 200 }, 1, GRAY, 5);

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// START GAME
		//----------------------------------------------------------------------------------
		while (game.gridSize < 3 && !WindowShouldClose())
		{
			// Update
			//----------------------------------------------------------------------------------
			testD.Update();
			testE.Update();
			testF.Update();
			//----------------------------------------------------------------------------------

			// Draw
			//----------------------------------------------------------------------------------
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

			// TEMP ========================
			game.gridSize = 3;
			// TEMP ========================

			//----------------------------------------------------------------------------------
		}
		int ** gameBoard = newGrid(game.gridSize);

		TTT * cells = new TTT[game.gridSize * game.gridSize];
		for (size_t i = 0, j = 0; i < game.gridSize * game.gridSize; i++)
		{
			float x = i % 3;
			float y = j;
			cells[i] = TTT("80x80Blank.png", Vector2{ 100 + (x * 100), 50 + (y * 100) }, 1, GRAY, Vector2{ x, y });
			if (i == 2 || i == 5)
			{
				j++;
			}
		}

		// Run through player turns.
		//----------------------------------------------------------------------------------
		while (game.gameOn && !WindowShouldClose())
		{
			// Wait for the player to make a valid move.
			while (!game.playerDone && !WindowShouldClose())
			{
				// Update
				//----------------------------------------------------------------------------------
				for (size_t i = 0; i < game.gridSize * game.gridSize; i++)
				{
					cells[i].Update();

					//TEMP
					int tempX = cells[i].cellID.x;
					int tempY = cells[i].cellID.y;
					if (cells[i].claimedBy != gameBoard[tempX][tempY]) gameBoard[tempX][tempY] == cells[i].claimedBy;
				}
				//----------------------------------------------------------------------------------

				// Draw
				//----------------------------------------------------------------------------------
				BeginDrawing();

				ClearBackground(RAYWHITE);

				// Draw grid and cells.
				for (size_t i = 0; i < game.gridSize * game.gridSize; i++)
				{
					cells[i].Draw();
				}
				// TODO

				EndDrawing();
				//----------------------------------------------------------------------------------
			}
			game.playerDone = false;

			for (size_t i = 0; i < game.gridSize * game.gridSize; i++)
			{
				int tempX = cells[i].cellID.x;
				int tempY = cells[i].cellID.y;
				if (cells[i].claimedBy != gameBoard[tempX][tempY]) gameBoard[tempX][tempY] == cells[i].claimedBy;
			}
			// Check
			//----------------------------------------------------------------------------------
			// Itterate through grid, checking for win
			// (refer to notepad for hypothesis on this).

			// If a win is detected, change the playerWin accordingly and set gameOn to false;
			// TODO
			
			//----------------------------------------------------------------------------------
			game.playerDone = false;
		}
		// END GAME
		//----------------------------------------------------------------------------------
		// Display who won. Add to win/lose ratio accordingly.

		delete[] cells;
		for (size_t i = 0; i < game.gridSize; i++)
		{
			delete[] gameBoard[i];
		}
		delete[] gameBoard;
		game.gridSize = 0;

		// Give the option to continue or quit
		// TODO
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}