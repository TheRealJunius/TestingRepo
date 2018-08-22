#include "Grid.h"

Grid::Grid(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Grid::DrawCell(Vec2 loc, Color c)
{
	for (int X = int(loc.x) * CellDimensions + Spacing; X < int(loc.x) * CellDimensions + CellDimensions; X++)
	{
		for (int Y = int(loc.y) * CellDimensions + Spacing; Y < int(loc.y) * CellDimensions + CellDimensions; Y++)
		{
			gfx.PutPixel(X, Y, c);
		}
	}
}
