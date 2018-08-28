#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "Grid.h"
#include <vector>
#include "Noise.h"
#include <random>

class World
{
public:
	//Block class
	class Block
	{
	public:
		enum class BlockType
		{
			Grass,
			Dirt,
			Stone,
			Water
		};
	public:
		//Functions
		Block(Vec2 in_loc, BlockType in_type);
		void Draw(Grid& grd);
		Vec2 GetLocation();
		//Functions
	private:
		//Data
		Vec2 loc;
		BlockType type;
		Color c;
		//Data
	};
	//Block class
public:
	//Functions
	World();
	void DrawBackground(Grid& grd);
	//Functions
public:
	//Data
	std::vector<Block> blocks;
	//Data
};
