#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Grid
{
public:
	static constexpr int CellDimensions = 32;
	static constexpr int Spacing = 6;

	void DrawCell(Graphics& gfx, Location loc, Color c);
};