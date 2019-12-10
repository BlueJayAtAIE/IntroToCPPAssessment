/*******************************************************************************************
*
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
	gameVariableHolder game;
	game.gridSize = 0;
	game.playerWin = 0;
	game.loopTurns = true;
	game.playerDone = false;
	game.playerOnesTurn = true;

	game.gameOn = true;

	// Set up grid size select buttons.
	GridSizeSelect gridButton3(texLib.blank, Vector2{ 190, 150 }, 1.5, WHITE, 3);
	GridSizeSelect gridButton4(texLib.blank, Vector2{ 340, 150 }, 1.5, WHITE, 4);
	GridSizeSelect gridButton5(texLib.blank, Vector2{ 490, 150 }, 1.5, WHITE, 5);

	// Set up player customization buttons.
	const int maxColors = 8;
	const int maxShapes = 6;

	// Player one COLOR (left hand side).
	PlayerColorSelect playerOneColors[maxColors];
	for (size_t i = 0; i < maxColors; i++)
	{
		float y = 340;
		if (i > 3) y = 390;
		playerOneColors[i] = PlayerColorSelect(texLib.blank, Vector2{ 20 + (50 * (float)(i % 4)), y }, 0.5f, pickColor(i));
	}

	// Player two COLOR (right hand side).
	PlayerColorSelect playerTwoColors[maxColors];
	for (size_t i = 0; i < maxColors; i++)
	{
		float y = 340;
		if (i > 3) y = 390;
		playerTwoColors[i] = PlayerColorSelect(texLib.blank, Vector2{ 590 + (50 * (float)(i % 4)), y }, 0.5f, pickColor(i));
	}

	// Player one SHAPE (left hand side).
	PlayerShapeSelect playerOneShapes[maxShapes];
	playerOneShapes[0] = PlayerShapeSelect(texLib.diamond,  Vector2{ 20,  160 }, 0.5f, GRAY, "Diamond");
	playerOneShapes[1] = PlayerShapeSelect(texLib.o, Vector2{ 80, 160 }, 0.5f, GRAY, "O");
	playerOneShapes[2] = PlayerShapeSelect(texLib.square, Vector2{ 20,  220 }, 0.5f, GRAY, "Square");
	playerOneShapes[3] = PlayerShapeSelect(texLib.star, Vector2{ 80, 220 }, 0.5f, GRAY, "Star");
	playerOneShapes[4] = PlayerShapeSelect(texLib.triangle, Vector2{ 20,  280 }, 0.5f, GRAY, "Triangle");
	playerOneShapes[5] = PlayerShapeSelect(texLib.x, Vector2{ 80, 280 }, 0.5f, GRAY, "X");

	// Player two SHAPE (right hand side).
	PlayerShapeSelect playerTwoShapes[maxShapes];
	playerTwoShapes[0] = PlayerShapeSelect(texLib.diamond, Vector2{ 680, 160 }, 0.5f, GRAY, "Diamond");
	playerTwoShapes[1] = PlayerShapeSelect(texLib.o, Vector2{ 740, 160 }, 0.5f, GRAY, "O");
	playerTwoShapes[2] = PlayerShapeSelect(texLib.square, Vector2{ 680, 220 }, 0.5f, GRAY, "Square");
	playerTwoShapes[3] = PlayerShapeSelect(texLib.star, Vector2{ 740, 220 }, 0.5f, GRAY, "Star");
	playerTwoShapes[4] = PlayerShapeSelect(texLib.triangle, Vector2{ 680, 280 }, 0.5f, GRAY, "Triangle");
	playerTwoShapes[5] = PlayerShapeSelect(texLib.x, Vector2{ 740, 280 }, 0.5f, GRAY, "X");

	// Continue n' Quit buttons to be displayed at the end.
	Toggle continueButton(texLib.button, Vector2{ 120, 280 }, 1.3f, WHITE);
	Toggle quitButton(texLib.button, Vector2{ 420, 280 }, 1.3f, WHITE);

	// Set up the scrolling background.
	float scrollOneX = -800;
	float scrollOneY = 0;
	float scrollTwoX = -800;
	float scrollTwoY = -600;
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose() && game.gameOn)    // Detect window close button or ESC key
	{
		// START GAME
		//----------------------------------------------------------------------------------
		// These variables are set here again in the case of the game looping.
		game.loopTurns = true;
		game.playerWin = 0;
		game.playerOnesTurn = true;

		while (game.gridSize < 3 && !WindowShouldClose())
		{
			// Update
			//----------------------------------------------------------------------------------
			// Allows the grid select buttons to be clickable.
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

			// Update the scrolling BG.
			scroll(scrollOneX, scrollOneY, -800, -600);
			scroll(scrollTwoX, scrollTwoY, -800, -600);
			//----------------------------------------------------------------------------------

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground(JAYBLUE);
			
			// Draw the two layers of scrolling BG.
			DrawTextureEx(texLib.scrollingBG, Vector2{ scrollOneX, scrollOneY }, 0, 1, SKYBLUE);
			DrawTextureEx(texLib.scrollingBG, Vector2{ scrollTwoX, scrollTwoY }, 0, 1, SKYBLUE);

			// Draw the Main BG.
			DrawTextureEx(texLib.mainMenuBG, Vector2{ 0, 0 }, 0, 1, WHITE);

			DrawFPS(3, 0);

			// Let players preview their symbol and color combo.
			DrawTextureEx(player1.playerShape, Vector2{ 245, 425 }, 0, 0.8f, player1.playerColor);
			DrawTextureEx(player2.playerShape, Vector2{ 480, 425 }, 0, 0.8f, player2.playerColor);
			DrawText("Player 1", 20, 450, 46, player1.playerColor);
			DrawText("Player 2", 580, 450, 46, player2.playerColor);

			// Draw grid buttons with text.
			gridButton3.Draw();
			DrawText("3", 236, 186, 60, BLACK);
			gridButton4.Draw();
			DrawText("4", 386, 186, 60, BLACK);
			gridButton5.Draw();
			DrawText("5", 536, 186, 60, BLACK);
			DrawText("Select Your Board Size!", 155, 90, 40, BLACK);

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
			float scale = 1 - (game.gridSize * 0.05f);

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
		while (game.loopTurns && !WindowShouldClose())
		{
			// Wait for the player to make a valid move.
			while (!game.playerDone && !WindowShouldClose())
			{
				// Update
				//----------------------------------------------------------------------------------
				// Depending on whose turn it is, update the buttons accordingly.
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

				// Update the scrolling BG.
				scroll(scrollOneX, scrollOneY, -800, -600);
				scroll(scrollTwoX, scrollTwoY, -800, -600);
				//----------------------------------------------------------------------------------

				// Draw
				//----------------------------------------------------------------------------------
				BeginDrawing();

				ClearBackground(JAYBLUE);

				// Draw the two layers of scrolling BG.
				DrawTextureEx(texLib.scrollingBG, Vector2{ scrollOneX, scrollOneY }, 0, 1, SKYBLUE);
				DrawTextureEx(texLib.scrollingBG, Vector2{ scrollTwoX, scrollTwoY }, 0, 1, SKYBLUE);

				// Draw the main BG.
				if (game.gridSize == 3)
				{
					DrawTextureEx(texLib.level3x3BG, Vector2{ 0, 0 }, 0, 1, WHITE);
				}
				else if (game.gridSize == 4)
				{
					DrawTextureEx(texLib.level4x4BG, Vector2{ 0, 0 }, 0, 1, WHITE);
				}
				else
				{
					DrawTextureEx(texLib.level5x5BG, Vector2{ 0, 0 }, 0, 1, WHITE);
				}

				DrawFPS(3, 0);

				// Let players preview their symbol and color combo. Also displays whose turn it is.
				if (game.playerOnesTurn)
				{
					DrawTextureEx(player1.playerShape, Vector2{ 20, 380 }, 0, 0.8f, player1.playerColor);
					DrawTextureEx(player2.playerShape, Vector2{ 710, 380 }, 0, 0.8f, BLACK);
					DrawText("Player 1", 20, 450, 46, player1.playerColor);
					DrawText("Player 2", 580, 450, 46, BLACK);
				}
				else
				{
					DrawTextureEx(player1.playerShape, Vector2{ 20, 380 }, 0, 0.8f, BLACK);
					DrawTextureEx(player2.playerShape, Vector2{ 710, 380 }, 0, 0.8f, player2.playerColor);
					DrawText("Player 1", 20, 450, 46, BLACK);
					DrawText("Player 2", 580, 450, 46, player2.playerColor);
				}

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
			// It's also so that playerToTrack and count stay in the scope of the while only.
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


				// Columns
				playerToTrack = 0;
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


				// Rows
				playerToTrack = 0;
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
			if (game.playerWin > 0)
			{
				game.loopTurns = false;
				//std::cout << "Player " << game.playerWin << " has won!!" << std::endl;
			}
			//----------------------------------------------------------------------------------
		}

		// END GAME
		//----------------------------------------------------------------------------------
		bool continueGame = false;

		// Disable all the grid cells, even if blank, so they can't be changed on the reults scren.
		for (size_t i = 0; i < game.gridSize * game.gridSize; i++)
		{
			cells[i].disable();
 		}

		while ((!WindowShouldClose() && !continueGame) && game.gameOn)
		{
			// Update
			//----------------------------------------------------------------------------------
			// Give the option to continue or quit.
			continueButton.Update(continueGame);
			quitButton.Update(game.gameOn);

			// Update the scrolling BG.
			scroll(scrollOneX, scrollOneY, -800, -600);
			scroll(scrollTwoX, scrollTwoY, -800, -600);
			//----------------------------------------------------------------------------------

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground(JAYBLUE);

			// Draw the two layers of scrolling BG.
			DrawTextureEx(texLib.scrollingBG, Vector2{ scrollOneX, scrollOneY }, 0, 1, SKYBLUE);
			DrawTextureEx(texLib.scrollingBG, Vector2{ scrollTwoX, scrollTwoY }, 0, 1, SKYBLUE);

			// Draw the main BG.
			if (game.gridSize == 3)
			{
				DrawTextureEx(texLib.level3x3BG, Vector2{ 0, 0 }, 0, 1, WHITE);
			}
			else if (game.gridSize == 4)
			{
				DrawTextureEx(texLib.level4x4BG, Vector2{ 0, 0 }, 0, 1, WHITE);
			}
			else
			{
				DrawTextureEx(texLib.level5x5BG, Vector2{ 0, 0 }, 0, 1, WHITE);
			}

			// Draw board from previous game.
			for (size_t i = 0; i < game.gridSize * game.gridSize; i++)
			{
				cells[i].Draw();
			}

			// The turn preview from the previous session. Changes color depending on who won instead.
			if (game.playerWin == 1)
			{
				DrawTextureEx(player1.playerShape, Vector2{ 20, 380 }, 0, 0.8f, player1.playerColor);
				DrawTextureEx(player2.playerShape, Vector2{ 710, 380 }, 0, 0.8f, BLACK);
				DrawText("Player 1", 20, 450, 46, player1.playerColor);
				DrawText("Player 2", 580, 450, 46, BLACK);
			}
			else if (game.playerWin == 2)
			{
				DrawTextureEx(player1.playerShape, Vector2{ 20, 380 }, 0, 0.8f, BLACK);
				DrawTextureEx(player2.playerShape, Vector2{ 710, 380 }, 0, 0.8f, player2.playerColor);
				DrawText("Player 1", 20, 450, 46, BLACK);
				DrawText("Player 2", 580, 450, 46, player2.playerColor);
			}
			else
			{
				DrawTextureEx(player1.playerShape, Vector2{ 20, 380 }, 0, 0.8f, BLACK);
				DrawTextureEx(player2.playerShape, Vector2{ 710, 380 }, 0, 0.8f, BLACK);
				DrawText("Player 1", 20, 450, 46, BLACK);
				DrawText("Player 2", 580, 450, 46, BLACK);
			}

			// The blur effect over the board.
			DrawTexture(texLib.fadeScreen, 0, 0, WHITE);

			DrawFPS(3, 0);

			// Display the Retry/Quit buttons.
			continueButton.Draw();
			DrawText("Rematch!", 140, 310, 50, BLACK);
			quitButton.Draw();
			DrawText("Quit", 500, 310, 50, BLACK);


			// Display who won.
			if (game.playerWin == 1)
			{
				DrawText("Player One Wins!", 113, 88, 71, WHITE);
				DrawText("Player One Wins!", 115, 90, 70, player1.playerColor);
			}
			else if (game.playerWin == 2)
			{
				DrawText("Player Two Wins!", 113, 88, 71, WHITE);
				DrawText("Player Two Wins!", 115, 90, 70, player2.playerColor);
			}
			else
			{
				DrawText("Tie Game.", 238, 88, 70, WHITE);
				DrawText("Tie Game.", 240, 90, 70, BLACK);
			}
			EndDrawing();
			//----------------------------------------------------------------------------------
		}

		// IMPORTANT: Delete all dynamic objects here.
		delete[] cells;
		for (size_t i = 0; i < game.gridSize; i++)
		{
			delete[] gameBoard[i];
		}
		delete[] gameBoard;
		game.gridSize = 0;
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}