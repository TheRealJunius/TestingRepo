#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Grid
{
private:
	Graphics& gfx;
public:
	static constexpr int Rows = 32; //16
	static constexpr int Columns = 16; //12
	static constexpr int CellDimensions = 32; //50
	static constexpr int Spacing = 2; //0

	Grid(Graphics& gfx);
	void DrawCell(Location loc, Color c);
};