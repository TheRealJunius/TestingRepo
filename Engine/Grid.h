#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Colors.h"

class Grid
{
private:
	Graphics& gfx;
public:
	static constexpr int Width = 64; //32
	static constexpr int Height = 32; //16
	static constexpr int CellDimensions = 16; //32
	static constexpr int Spacing = 0; //2

	Grid(Graphics& gfx);
	void DrawCell(Vec2 loc, Color c);
};