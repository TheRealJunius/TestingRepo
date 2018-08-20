#include "Grid.h"

Grid::Grid(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Grid::DrawCell(Location loc, Color c)
{
	for (int X = loc.x * CellDimensions + Spacing; X < loc.x * CellDimensions + CellDimensions; X++)
	{
		for (int Y = (CellDimensions * loc.y + Spacing); Y < loc.y * CellDimensions + CellDimensions; Y++)
		{
			gfx.PutPixel(X, Y, c);
		}
	}
}
