#include "Player.h"
#include <assert.h>

Player::Player(const Location in_loc)
{
	loc = in_loc;
}

void Player::MoveBy(const Location delta_loc)
{
	//assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Player::Draw(Grid & grd) const
{
	grd.DrawCell(loc, c);
}

void Player::Update(Keyboard& kbd, int& mC, int mP, float dt)
{
	Location delta_loc = { 0,0 };

	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		delta_loc = { 1,0 };
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		delta_loc = { -1,0 };
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		delta_loc = { 0,1 };
	}
	if (kbd.KeyIsPressed(VK_UP))
	{
		delta_loc = { 0,-1 };
	}

	++mC;

	if (mC >= mP)
	{
		mC = 0;
		MoveBy(delta_loc);
	}
}
