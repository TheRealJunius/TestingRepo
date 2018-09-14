#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "World.h"

class Mobs
{
public:
	enum class MobType
	{
		ClassicSergiu, //Zombie
		LongSergiu, //Skeleton
		WeirdSergiu, //Creeper
	};
public:
	//Functions
	Mobs(Mobs::MobType type, Vec2 loc);
	void Draw(Grid& grd);
	//Functions
private:
	//Functions
	Vec2 loc;
	MobType type;
	//Functions
};