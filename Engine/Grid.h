#pragma once
#include "Graphics.h"

struct Grid
{
private:
	static constexpr int nCellsOnALine = 16;
	static constexpr int cellWidth = Graphics::ScreenWidth / nCellsOnALine;
	static constexpr int cellHeight = Graphics::ScreenHeight / nCellsOnALine;
public:
	void DrawCell(Graphics& gfx, int x, int y, int r, int g, int b)
	{

		for (int j = y * nCellsOnALine; j < nCellsOnALine * ( y + 1); j++)
		{
			for (int i = x * nCellsOnALine; i < nCellsOnALine * (x + 1); i++)
			{
				gfx.PutPixel(i, j, r, g, b);
			}
		}
	}
};