#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Grid
{
public:
	static constexpr int Rows = 16; //32
	static constexpr int Columns = 12; //16
	static constexpr int CellDimensions = 50; //32
	static constexpr int Spacing = 0; //6

	void DrawCell(Graphics& gfx, Location loc, Color c);
};