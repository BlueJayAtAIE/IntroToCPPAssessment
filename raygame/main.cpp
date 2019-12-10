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
	int screenHeight = 500;

	InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe!");

	SetTargetFPS(60);

	// Setup the texture library.
	textureLibrary texLib;

	// Set up the players.
	Player player1("player1.txt", texLib.x, "X", RED, 1);
	Player player2("player2.txt", texLib.o, "O", BLUE, 2);

	// Set up the game variables.
	gameVariableHolder game; // { 0, 0, true, false };
	gameVariableHolder::gridSize = 0;
	gameVariableHolder::playerWin = 0;
	gameVariableHolder::gameOn = true;
	gameVariableHolder::playerDone = false;
	gameVariableHolder::playerOnesTurn = true;

	// Set up grid size select buttons.
	GridSizeSelect gridButton3(texLib.blank, Vector2{ 250, 200 }, 1, GRAY, 3);
	GridSizeSelect gridButton4(texLib.blank, Vector2{ 350, 200 }, 1, GRAY, 4);
	GridSizeSelect gridButton5(texLib.blank, Vector2{ 450, 200 }, 1, GRAY, 5);

	// Set up player customization buttons.
	const int maxColors = 8;
	const int maxShapes = 6;

	// Player one COLOR (left hand side).
	PlayerColorSelect playerOneColors[maxColors];

	for (size_t i = 0; i < maxColors; i++)
	{
		float y = 360;
		if (i > 3) y = 410;
		playerOneColors[i] = PlayerColorSelect(texLib.blank, Vector2{ 40 + (50 * (float)(i % 4)), y }, 0.5f, pickColor(i));
	}

	// Player two COLOR (right hand size).
	PlayerColorSelect playerTwoColors[maxColors];

	for (size_t i = 0; i < maxColors; i++)
	{
		float y = 360;
		if (i > 3) y = 410;
		playerTwoColors[i] = PlayerColorSelect(texLib.blank, Vector2{ 570 + (50 * (float)(i % 4)), y }, 0.5f, pickColor(i));
	}

	// Player one SHAPE (left hand side).
	PlayerShapeSelect playerOneShapes[maxShapes];
	playerOneShapes[0] = PlayerShapeSelect(texLib.diamond,  Vector2{ 40,  160 }, 0.5f, GRAY, "Diamond");
	playerOneShapes[1] = PlayerShapeSelect(texLib.o, Vector2{ 100, 160 }, 0.5f, GRAY, "O");
	playerOneShapes[2] = PlayerShapeSelect(texLib.square, Vector2{ 40,  220 }, 0.5f, GRAY, "Square");
	playerOneShapes[3] = PlayerShapeSelect(texLib.star, Vector2{ 100, 220 }, 0.5f, GRAY, "Star");
	playerOneShapes[4] = PlayerShapeSelect(texLib.triangle, Vector2{ 40,  280 }, 0.5f, GRAY, "Triangle");
	playerOneShapes[5] = PlayerShapeSelect(texLib.x, Vector2{ 100, 280 }, 0.5f, GRAY, "X");

	// Player two SHAPE (right hand side).
	PlayerShapeSelect playerTwoShapes[maxShapes];
	playerTwoShapes[0] = PlayerShapeSelect(texLib.diamond, Vector2{ 660, 160 }, 0.5f, GRAY, "Diamond");
	playerTwoShapes[1] = PlayerShapeSelect(texLib.o, Vector2{ 720, 160 }, 0.5f, GRAY, "O");
	playerTwoShapes[2] = PlayerShapeSelect(texLib.square, Vector2{ 660, 220 }, 0.5f, GRAY, "Square");
	playerTwoShapes[3] = PlayerShapeSelect(texLib.star, Vector2{ 720, 220 }, 0.5f, GRAY, "Star");
	playerTwoShapes[4] = PlayerShapeSelect(texLib.triangle, Vector2{ 660, 280 }, 0.5f, GRAY, "Triangle");
	playerTwoShapes[5] = PlayerShapeSelect(texLib.x, Vector2{ 720, 280 }, 0.5f, GRAY, "X");

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// START GAME
		//----------------------------------------------------------------------------------
		game.gameOn = true;
		game.playerWin = 0;
		game.playerOnesTurn = true;

		while (game.gridSize < 3 && !WindowShouldClose())
		{
			// Update
			//----------------------------------------------------------------------------------
			gridButton3.Update(game.gridSize);
			gridButton4.Update(game.gridSize);
			gridButton5.Update(game.gridSize);

			// Let the players customize themselves.
			for (size_t i = 0; i < maxColors; i++)
			{
				playerOneColors[i].Update(player1);
				playerTwoColors[i].Update(player2);
			}

			for (size_t i = 0; i < maxShapes; i++)
			{
				playerOneShapes[i].Update(player1);
				playerTwoShapes[i].Update(player2);
			}

			// If the players pick the same color and shape, reset them :^)
			if (player1.playerColor == player2.playerColor && player1.playerShapeName == player2.playerShapeName)
			{
				player1.playerColor = RED;
				player2.playerColor = BLUE;

				player1.playerShape = texLib.x;
				player2.playerShape = texLib.o;
				player1.playerShapeName = "X";
				player2.playerShapeName = "O";
			}

			//----------------------------------------------------------------------------------

			// Draw
			//----------------------------------------------------------------------------------
			// Display Grid Choices.
			BeginDrawing();

			ClearBackground(RAYWHITE);

			// Let players preview their symbol and color combo.
			DrawTextureEx(player1.playerShape, Vector2{ 250, 365 }, 0, 1, player1.playerColor);
			DrawTextureEx(player2.playerShape, Vector2{ 460, 365 }, 0, 1, player2.playerColor);

			// Draw grid buttons with text.
			gridButton3.Draw();
			DrawText("3", 280, 220, 48, BLACK);
			gridButton4.Draw();
			DrawText("4", 380, 220, 48, BLACK);
			gridButton5.Draw();
			DrawText("5", 480, 220, 48, BLACK);

			// Draw color buttons.
			for (size_t i = 0; i < maxColors; i++)
			{
				playerOneColors[i].Draw();
				playerTwoColors[i].Draw();
			}

			// Draw shape buttons.
			for (size_t i = 0; i < maxShapes; i++)
			{
				playerOneShapes[i].Draw();
				playerTwoShapes[i].Draw();
			}

			EndDrawing();
			//----------------------------------------------------------------------------------
		}

		// Set up game board.
		int ** gameBoard = newGrid(game.gridSize);

		// Spawning the buttons that make up the Tic-Tac-Toe grid.
		TTT * cells = new TTT[game.gridSize * game.gridSize];
		for (size_t i = 0, j = 0; i < game.gridSize * game.gridSize; i++)
		{
			float x = i % game.gridSize;
			float y = j;
			float scale = 1 - (game.gridSize * 0.05);

			cells[i] = TTT(texLib.blank, Vector2{ (300 * scale) + (x * (100 * scale)), (110 * (scale * scale)) + (y * (100 * scale)) }, scale, GRAY, Vector2{ x, y });

			// If 'i' is equal to the boundairy of the current row, go to the next one.
			// Practical example: grid is 3x3. Once i = 2, add to j. When i = 5, add to j.
			// Another example: grid is 4x4. Once i = 3, add to j. When i = 7, add to j. And so on.
			if (i == (game.gridSize * (j + 1)) - 1)
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

			// Update the gameboard to be claimed by the correct players.
			for (size_t i = 0; i < game.gridSize * game.gridSize; i++)
			{
				if (cells[i].claimedBy != gameBoard[(int)cells[i].cellID.x][(int)cells[i].cellID.y])
				{
					gameBoard[(int)cells[i].cellID.x][(int)cells[i].cellID.y] = cells[i].claimedBy;

					// KEEP COMMENTED
					//std::cout << "cells[" << i << "]: " << cells[i].claimedBy << " == " << gameBoard[(int)cells[i].cellID.x][(int)cells[i].cellID.y] << " ???"
					//	<< " ( x =  " << (int)cells[i].cellID.x << ", y = " << (int)cells[i].cellID.y << ")" << std::endl;
				}
			}
			// KEEP COMMENTED
			//std::cout << "--------------------------------------" << std::endl;

			// Check
			//----------------------------------------------------------------------------------
			// Itterate through grid, checking for win.

			// This while allows for the other for loops to be skipped if a condition is met that matches before the others.
			// If a win is detected, change the playerWin accordingly.
			while (true)
			{
				int playerToTrack = 0;
				int count = 0;

				// Diagonal (Upper Left to Lower Right)
				playerToTrack = gameBoard[0][0];
				for (size_t i = 0; i < game.gridSize; i++)
				{
					if (gameBoard[i][i] == playerToTrack)
					{
						count++;
					}
				}
				if (count == game.gridSize)
				{
					game.playerWin = playerToTrack;
					break;
				}

				// Diagonal (Lower Left to Upper Right)
				playerToTrack = gameBoard[game.gridSize - 1][0];
				count = 0;
				for (size_t i = 0; i < game.gridSize; i++)
				{
					if (gameBoard[game.gridSize - i - 1][i] == playerToTrack)
					{
						count++;
					}
				}
				if (count == game.gridSize)
				{
					game.playerWin = playerToTrack;
					break;
				}

				playerToTrack = 0;

				// Columns
				for (size_t i = 0; i < game.gridSize; i++)
				{
					count = 0;
					playerToTrack = gameBoard[i][0];
					for (size_t j = 0; j < game.gridSize; j++)
					{
						if (gameBoard[i][j] == playerToTrack)
						{
							count++;
						}
						if (count == game.gridSize)
						{
							game.playerWin = playerToTrack;
							break;
						}
					}

					// If it detects a win, it needs this extra break.
					if (game.playerWin > 0)
					{
						break;
					}
				}
				// Same as above.
				if (game.playerWin > 0)
				{
					break;
				}

				playerToTrack = 0;

				// Rows
				for (size_t i = 0; i < game.gridSize; i++)
				{
					count = 0;
					playerToTrack = gameBoard[0][i];
					for (size_t j = 0; j < game.gridSize; j++)
					{
						if (gameBoard[j][i] == playerToTrack)
						{
							count++;
						}
						if (count == game.gridSize)
						{
							game.playerWin = playerToTrack;
							break;
						}
					}

					// If it detects a win, it needs this extra break.
					if (game.playerWin > 0)
					{
						break;
					}
				}
				// Same as above.
				if (game.playerWin > 0)
				{
					break;
				}


				// Cats Game
				playerToTrack = 0;
				count = 0;
				for (size_t i = 0; i < game.gridSize; i++)
				{
					for (size_t j = 0; j < game.gridSize; j++)
					{
						if (gameBoard[i][j] != 0)
						{
							count++;
						}
					}
				}
				if (count == game.gridSize * game.gridSize)
				{
					game.playerWin = 3;
					break;
				}

				// Even if none of the conditions are met: break.
				// Just don't edit playerWin.
				break;
			}


			// Setting gameOn to false ends the round, and brings up the quit/continue screen.
			// Here should also be where the win and loss are added to each player. TODO
			if (game.playerWin > 0)
			{
				game.gameOn = false;
				std::cout << "Player " << game.playerWin << " has won!!" << std::endl;
			}

			//----------------------------------------------------------------------------------
		}

		// END GAME
		//----------------------------------------------------------------------------------
		// Display who won. Add to win/lose ratio accordingly. TODO

		delete[] cells;
		for (size_t i = 0; i < game.gridSize; i++)
		{
			delete[] gameBoard[i];
		}
		delete[] gameBoard;
		game.gridSize = 0;

		// Give the option to continue or quit. TODO
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}