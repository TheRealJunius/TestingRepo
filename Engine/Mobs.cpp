#include "Mobs.h"

Mobs::Mobs(Mobs::MobType type, Vec2 loc)
	:
	type(type),
	loc(loc)
{
}

void Mobs::Draw(Grid& grd)
{
	grd.DrawCell(loc, Colors::Green);
}
