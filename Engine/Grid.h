#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Grid
{
private:
	Graphics& gfx;
public:
	static constexpr int Rows = 16; //32
	static constexpr int Columns = 12; //16
	static constexpr int CellDimensions = 50; //32
	static constexpr int Spacing = 0; //6

	Grid(Graphics& gfx);
	void DrawCell(Location loc, Color c);
};