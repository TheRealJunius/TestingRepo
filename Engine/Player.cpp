#include "Player.h"
#include <assert.h>

Player::Player(const Location in_loc)
{
	loc = in_loc;
}

void Player::MoveBy(const Location delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Player::Draw(Grid & grd) const
{
	grd.DrawCell(loc, c);
}
