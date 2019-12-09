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
#include "Player.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe!");

	SetTargetFPS(60);

	textureLibrary texLib;

	Player player1("player1.txt", texLib.x, RED, 1);
	Player player2("player2.txt", texLib.o, BLUE, 2);

	gameVariableHolder game; // { 0, 0, true, false };
	gameVariableHolder::gridSize = 0;
	gameVariableHolder::playerWin = 0;
	gameVariableHolder::gameOn = true;
	gameVariableHolder::playerDone = false;
	gameVariableHolder::playerOnesTurn = true;

	GridSizeSelect testD(texLib.blank, Vector2{ 250, 200 }, 1, GRAY, 3);
	GridSizeSelect testE(texLib.blank, Vector2{ 350, 200 }, 1, GRAY, 4);
	GridSizeSelect testF(texLib.blank, Vector2{ 450, 200 }, 1, GRAY, 5);

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
			testD.Update(game.gridSize);
			testE.Update(game.gridSize);
			testF.Update(game.gridSize);
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
			//----------------------------------------------------------------------------------
		}

		// Set up game board.
		int ** gameBoard = newGrid(game.gridSize);

		// TODO edit this to work with grids other than 3x3.
		TTT * cells = new TTT[game.gridSize * game.gridSize];
		for (size_t i = 0, j = 0; i < game.gridSize * game.gridSize; i++)
		{
			float x = i % 3;
			float y = j;
			cells[i] = TTT(texLib.blank, Vector2{ 100 + (x * 100), 50 + (y * 100) }, 1, GRAY, Vector2{ x, y });
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
					if (game.playerOnesTurn)
					{
						cells[i].Update(player1, game.playerDone);
					}
					else
					{
						cells[i].Update(player2, game.playerDone);
					}
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

				EndDrawing();
				//----------------------------------------------------------------------------------
			}

			// Toggle playerDone to catch in the above loop again after the check. Then toggle whos turn it is.
			game.playerDone = false;
			game.playerOnesTurn = !game.playerOnesTurn;

			// TEMP ============
			if (game.playerOnesTurn)
			{
				std::cout << "bup! it's player one's turn!" << std::endl;
			}
			else
			{
				std::cout << "bup! it's player two's turn!" << std::endl;
			}
			// =================

			for (size_t i = 0; i < game.gridSize * game.gridSize; i++)
			{
				if (cells[i].claimedBy != gameBoard[(int)cells[i].cellID.x][(int)cells[i].cellID.y])
				{
					// KEEP COMMENTED
					//std::cout << "cells[" << i << "]: " << cells[i].claimedBy << " == " << gameBoard[(int)cells[i].cellID.x][(int)cells[i].cellID.y] << " ???"
					//	<< " ( x =  " << (int)cells[i].cellID.x << ", y = " << (int)cells[i].cellID.y << ")" << std::endl;

					gameBoard[(int)cells[i].cellID.x][(int)cells[i].cellID.y] = cells[i].claimedBy;
				}
			}
			// KEEP COMMENTED
			//std::cout << "--------------------------------------" << std::endl;

			// Check
			//----------------------------------------------------------------------------------
			// Itterate through grid, checking for win
			// (Refer to notepad for hypothesis on this).

			// If a win is detected, change the playerWin accordingly and set gameOn to false;
			// TODO
			
			//----------------------------------------------------------------------------------
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