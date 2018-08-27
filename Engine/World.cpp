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

Vec2 World::Block::GetLocation()
{
	return loc;
}

World::World()
{
	//Surface generation
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> seeding(0, 100000.0f); //You can change 100000 with any number you want
																 //But if it's a small number there are big chances that there
																 //Might be similarities with previous or next maps
																 //So with a big number, this chance gets smaller

	float seed = seeding(rng); //Taking a random seed/xoffset in time;

	for (int i = 0; i < Grid::Width; i++, seed += 0.2000000f) //If you change 0.2f with bigger numbers, it will get suddenly random
	{
		float j = Noise::PerlinNoise_1D(seed, 3.5f, 3); //Taking a random noise value based on the seed
														//With a frequency of 3.5f, that's what I thought would be the best one
														//And with a amplitude of 3, you can change the freq and the ampl if u want

		j += float(Grid::Height / 2 - 1);				//The perlin values are between 0 and double the amplitude
														//So I just translate it to the middle of the y plane

		Block terrainSurface = Block(Vec2(float(i), j), Block::BlockType::Dirt);

		blocks.push_back(terrainSurface);
	}
	//Surface generation
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
