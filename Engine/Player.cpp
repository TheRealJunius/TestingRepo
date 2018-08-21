#include "Player.h"
#include <assert.h>

void Player::ClampToScreen()
{
	if (loc.x >= Grid::Rows)
	{
		loc.x = Grid::Rows - 1;
	}
	if (loc.x < 0)
	{
		loc.x = 0;
	}
	if (loc.y >= Grid::Columns)
	{
		loc.y = Grid::Columns - 1;
	}
	if (loc.y < 0)
	{
		loc.y = 0;
	}
}

Player::Player(const Vec2 in_loc)
{
	loc = in_loc;
}

void Player::MoveBy(const Vec2 delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) > 1);
	loc += delta_loc;
}

void Player::Draw(Grid & grd) const
{
	grd.DrawCell(loc, c);
}

void Player::Update(Keyboard& kbd)
{
	Vec2 delta_loc = { 0,0 };

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

	++MoveCounter;

	if (MoveCounter >= MovePeriod)
	{
		MoveCounter = 0;
		MoveBy(delta_loc);
		ClampToScreen();
	}
}
