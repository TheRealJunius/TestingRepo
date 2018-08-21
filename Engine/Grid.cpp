#include "Grid.h"

Grid::Grid(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Grid::DrawCell(Vec2 loc, Color c)
{
	for (int X = loc.x * CellDimensions + Spacing; X < loc.x * CellDimensions + CellDimensions; X++)
	{
		for (int Y = (CellDimensions * loc.y + Spacing); Y < loc.y * CellDimensions + CellDimensions; Y++)
		{
			gfx.PutPixel(X, Y, c);
		}
	}
}

void Grid::DrawCell(Vec2 loc, World::Block::BlockType type)
{
	Color BlockColor;

	switch (type)
	{
	case World::Block::BlockType::Dirt:
	{
		BlockColor = { 153, 102, 51 };
		break;
	}
	case World::Block::BlockType::Stone:
	{
		BlockColor = { 77, 77, 77 };
		break;
	}
	case World::Block::BlockType::Water:
	{
		BlockColor = { 0, 204, 136 };
		break;
	}
	}

	for (int X = loc.x * CellDimensions + Spacing; X < loc.x * CellDimensions + CellDimensions; X++)
	{
		for (int Y = (CellDimensions * loc.y + Spacing); Y < loc.y * CellDimensions + CellDimensions; Y++)
		{
			gfx.PutPixel(X, Y, BlockColor);
		}
	}
}
