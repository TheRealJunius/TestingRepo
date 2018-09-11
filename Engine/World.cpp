#include "World.h"
#include <assert.h>

Grid::Grid::World::Block::Block(Vec2 in_loc, Grid::Grid::World::Block::BlockType in_type)
	:
	loc(in_loc),
	type(in_type)
{
}

void Grid::Grid::World::Block::Draw(Grid & grd)
{
	grd.DrawCell(loc, type);
}

Vec2 Grid::Grid::World::Block::GetLocation()
{
	return loc;
}

Grid::World::Block::BlockType Grid::World::Block::GetType()
{
	return type;
}

void Grid::World::Block::SetType(BlockType _type)
{
	type = _type;
}

Grid::World::World()
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> seeding(0, 100000.0f); //You can change 100000 with any number you want
																 //But if it's a small number there are big chances that there
																 //Might be similarities with previous or next maps
																 //So with a big number, this chance gets smaller
	std::uniform_int_distribution<int> dirtLayer(2, 4);

	//Surface generation
	float seed = seeding(rng); //Taking a random seed/xoffset in time;

	for (int i = 0; i < Grid::Width; i++, seed += 0.0800000f) //If you change 0.2f with bigger numbers, it will get suddenly random
	{
		float j = Noise::PerlinNoise_1D(seed, 2.7182818f, 6.2831853f); //Taking a random noise value based on the seed
														//With a frequency of 3.5f, that's what I thought would be the best one
														//And with a amplitude of 3, you can change the freq and the ampl if u want

		j += float(Grid::Height / 2 - 1);				//The perlin values are between 0 and double the amplitude
															//So I just translate it to the middle of the y plane

		Block terrainSurface = Block(Vec2(float(i), float(int(j))), Block::BlockType::Grass);

		blocks.push_back(terrainSurface);
	}
	//Surface generation

	//Underground filling
	for (int i = 0; i < Grid::Width; i++)
	{
		int surfaceBlock = 0;

		//Finding the surfaceBlock's y location
		for (int testForBlock = 0; testForBlock < blocks.at(i).GetLocation().y + 2; testForBlock++)
		{
			surfaceBlock = testForBlock;
		}

		const int dLayer = dirtLayer(rng);

		//Adding the underground blocks
		for (int j = surfaceBlock; j < Grid::Height; j++)
		{
			if (j <= surfaceBlock + dLayer)
			{
				Block underGroundBlock = Block(Vec2(float(i), float(j)), Grid::World::Block::BlockType::Dirt);
				blocks.push_back(underGroundBlock);
			}
			else
			{
				Block underGroundBlock = Block(Vec2(float(i), float(j)), Grid::World::Block::BlockType::Stone);
				blocks.push_back(underGroundBlock);
			}
		}
	}

	AddOres(Block::BlockType::Coal, blocks, 2.5000000f);
	AddOres(Block::BlockType::Iron, blocks, 2.3333333f);
	AddOres(Block::BlockType::Diamond, blocks, 0.05f);
	//Underground filling

	//Checking for errors
	for (int i = 0; i < blocks.size(); i++)
	{
		for (int I = 0; I < blocks.size(); I++)
		{
			if (i != I)
			{
				Vec2 block1Loc = blocks.at(i).GetLocation();
				Vec2 block2Loc = blocks.at(I).GetLocation();
				assert(!(block1Loc == block2Loc));
			}
		}
	}
	//Checking for errors
}

void Grid::World::DrawBackground(Grid & grd)
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

void Grid::World::AddOres(Block::BlockType type, std::vector<Block>& b, float chanceOfSpawningOnEachBlock)
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> randomNumber(0, 100000.0f);

	//Create the ores
	for (int i = 0; i < b.size(); i++)
	{
		if ((b.at(i).GetType() != Block::BlockType::Grass) && 
			(b.at(i).GetType() != Block::BlockType::Dirt) &&
			(float(fmod(randomNumber(rng), 100)) < chanceOfSpawningOnEachBlock))
		{
			b.at(i).SetType(type);
		}
	}
}

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

void Grid::DrawCell(Vec2 loc, World::Block::BlockType type)
{
	Color blockColor;

	switch (type)
	{
	case Grid::World::Block::BlockType::Grass:
	{
		blockColor = { 124, 181, 0 };
		break;
	}
	case Grid::World::Block::BlockType::Dirt:
	{
		blockColor = { 153, 102, 51 };
		break;
	}
	case Grid::World::Block::BlockType::Stone:
	{
		blockColor = { 77, 77, 77 };
		break;
	}
	case Grid::World::Block::BlockType::Water:
	{
		blockColor = { 0, 153, 255 };
		break;
	}
	case Grid::World::Block::BlockType::Coal:
	{
		blockColor = { 51, 26, 0 };
		break;
	}
	case Grid::World::Block::BlockType::Iron:
	{
		blockColor = { 255, 217, 179 };
		break;
	}
	case Grid::World::Block::BlockType::Diamond:
	{
		blockColor = { 26, 255, 209 };
		break;
	}
	}

	for (int X = int(loc.x) * CellDimensions + Spacing; X < int(loc.x) * CellDimensions + CellDimensions; X++)
	{
		for (int Y = int(loc.y) * CellDimensions + Spacing; Y < int(loc.y) * CellDimensions + CellDimensions; Y++)
		{
			gfx.PutPixel(X, Y, blockColor);
		}
	}
}
