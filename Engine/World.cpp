#include "World.h"

World::Block::Block(Vec2 in_loc, BlockType in_type)
	:
	loc(in_loc),
	type(in_type)
{
	switch (type)
	{
	case Block::BlockType::Dirt:
	{
		c = { 153, 102, 51 };
		break;
	}
	case Block::BlockType::Stone:
	{
		c = { 77, 77, 77 };
		break;
	}
	case Block::BlockType::Water:
	{
		c = { 0, 204, 136 };
		break;
	}
	}
}

void World::Block::Draw(Grid & grd)
{
	grd.DrawCell(loc, c);
}

World::World()
{
	for (int j = Grid::Height - 1; j > Grid::Height - 3; j--)
	{
		for (int i = 0; i < Grid::Width; i++)
		{
			World::Block block = World::Block(Vec2(float(i), float(j)), World::Block::BlockType::Dirt);
			blocks.push_back(block);
		}
	}
}

void World::DrawBackground(Grid & grd)
{
	for (int i = 0; i < Grid::Width; i++)
	{
		for (int j = 0; j < Grid::Height; j++)
		{
			Color skyColor = { 204, 255, 238 };
			grd.DrawCell({float(i), float(j)}, skyColor);
		}
	}
}
