#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "Grid.h"
#include <vector>

class World
{
public:
	class Block
	{
	public:
		enum class BlockType
		{
			Dirt,
			Stone,
			Water
		};
	public:
		Block(Vec2 in_loc, BlockType in_type);
		void Draw(Grid& grd);
	private:
		Vec2 loc;
		BlockType type;
		Color c;
	};
public:
	World();
	std::vector<Block> blocks;
	void DrawBackground(Grid& grd);
};
