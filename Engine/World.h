#pragma once

#include "Vec2.h"
#include "Colors.h"
#include <vector>
#include "Noise.h"
#include <random>
#include "Graphics.h"

class Grid
{
private:
	Graphics& gfx;
public:
	//World class
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
				Water,
				Coal,
				Iron,
				Diamond
			};
		public:
			//Functions
			Block(Vec2 in_loc, BlockType in_type);
			void Draw(Grid& grd);
			Vec2 GetLocation();
			BlockType GetType();
			void SetType(BlockType _type);
			//Functions
		private:
			//Data
			Vec2 loc;
			BlockType type;
			//Data
		};
		//Block class

		//Mob class
		class Mob
		{
		public:
			enum class MobType
			{
				ShortSergiu,
				LongSergiu,
				WeirdSergiu,
			};
		public:
			//Functions
			Mob(Mob::MobType type, Vec2 loc);
			void Draw(Grid& grd);
			//Functions
		private:
			//Data
			Vec2 loc;
			MobType type;
			//Data
		};
		//Mob class
	public:
		//Functions
		World();
		void DrawBackground(Grid& grd);
		void Update(float dt);
		//Functions
	private:
		//Functions
		void AddOres(Block::BlockType type, std::vector<Block>& b, float chanceOfSpawningOnEachBlock);
		//Functions
	public:
		//Data
		std::vector<Block> blocks;
		//Data
	private:
		//Data
		Color skyColor = { 204, 255, 238 };
		bool reverseColor = false;

		float timeWorld = 0.0f;
		//Data
	};
	//World class

	World world;
public:
	static constexpr int Width = 128; //64
	static constexpr int Height = 64; //32
	static constexpr int CellDimensions = 8; //16
	static constexpr int Spacing = 0; //2

	Grid(Graphics& gfx);
	void DrawCell(Vec2 loc, Color c);
	void DrawCell(Vec2 loc, World::Block::BlockType type);
	void DrawCell(Vec2 loc, World::Mob::MobType type);
};
