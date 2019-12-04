#pragma once
#include "Button.h"

class TTT :
	public Button
{
public:
	TTT();
	TTT(const char filename[], Vector2 pos, float scale, Color color, Vector2 ID);
	~TTT();

	void Draw() override;
	void Update() override;

	Vector2 cellID;
	int claimedBy;
};

class GridSizeSelect : 
	public Button
{
public:
	GridSizeSelect();
	GridSizeSelect(const char filename[], Vector2 pos, float scale, Color color, int size);
	~GridSizeSelect();

	void Draw() override;
	void Update() override;

	void setGridSize(int &size);

private:
	int grid;
};