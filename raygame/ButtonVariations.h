#pragma once
#include "Button.h"
#include "Player.h"

// The button used as the cells on the actual Tic Tac Toe board.
class TTT :
	public Button
{
public:
	TTT();
	TTT(Texture2D tex, Vector2 pos, float scale, Color color, Vector2 ID);
	~TTT();

	void Draw() override;
	void Update(Player player, bool &turnEnd);

	Vector2 cellID;
	int claimedBy;
};

// The buttons used to change the size of the board on the main menu.
class GridSizeSelect : 
	public Button
{
public:
	GridSizeSelect(Texture2D tex, Vector2 pos, float scale, Color color, int size);
	~GridSizeSelect();

	void Draw() override;
	void Update(int &sizeToChange);

	void setGridSize(int &size);

private:
	int grid;
};

// Buttons used to change the color of the customizable character.
class PlayerColorSelect :
	public Button
{
public:
	PlayerColorSelect();
	PlayerColorSelect(Texture2D tex, Vector2 pos, float scale, Color color);
	~PlayerColorSelect();

	void Draw() override;
	void Update(Player &playerToChange);

private:
	Color baseColor;
};

// Buttons used to change the shape of the customizable character.
class PlayerShapeSelect :
	public Button
{
public:
	PlayerShapeSelect();
	PlayerShapeSelect(Texture2D tex, Vector2 pos, float scale, Color color, std::string baseName);
	~PlayerShapeSelect();

	void Draw() override;
	void Update(Player &playerToChange);

private:
	Texture2D baseTex;
	std::string baseTexName;
};

// Button that toggles on or off a given bool. Used for Continue and Quit buttons.
class Toggle :
	public Button
{
public:
	Toggle(Texture2D tex, Vector2 pos, float scale, Color color);
	~Toggle();

	void Draw() override;
	void Update(bool &toOverride);
};