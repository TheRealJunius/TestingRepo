#include "Grid.h"

void Grid::DrawCell(Graphics & gfx, Location loc, Color c)
{
	int test = 8 * CellDimensions + Spacing;
	for (int X = loc.x * CellDimensions + Spacing; X < loc.x * CellDimensions + CellDimensions; X++)
	{
		for (int Y = (CellDimensions * loc.y + Spacing); Y < loc.y * CellDimensions + CellDimensions; Y++)
		{
			gfx.PutPixel(X, Y, c);
		}
	}
}
