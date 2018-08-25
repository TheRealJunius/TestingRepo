#pragma once

#include "Grid.h"
#include "Vec2.h"
#include "Colors.h"
#include "Keyboard.h"
#include "World.h"

class Player
{
private:
	void ClampToScreen();
	void PlayerWithBlocksCollision(Vec2& dl, std::vector<World::Block> b);
public:
	Player(const Vec2 in_loc);
	void MoveBy(const Vec2 delta_loc);
	void Draw(Grid& grd) const;
	void Update(float dt, Keyboard& kbd, std::vector<World::Block> b);
private:
	Vec2 loc;
	Color c = Colors::Magenta;
	bool jumping = false;
	int jumpForce = 4; //Number of blocks the player can jump
};