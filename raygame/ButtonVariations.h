#pragma once
#include "Button.h"
#include "Player.h"

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

class GridSizeSelect : 
	public Button
{
public:
	GridSizeSelect();
	GridSizeSelect(Texture2D tex, Vector2 pos, float scale, Color color, int size);
	~GridSizeSelect();

	void Draw() override;
	void Update(int &sizeToChange);

	void setGridSize(int &size);

private:
	int grid;
};