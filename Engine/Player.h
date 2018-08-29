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
	void Jump(Keyboard& kbd, Vec2& dl, std::vector<World::Block> b);
	void MoveBy(const Vec2 delta_loc);
public:
	Player(const Vec2 in_loc);
	void Draw(Grid& grd) const;
	void Update(Keyboard& kbd, std::vector<World::Block> b);
private:
	Vec2 loc;
	Color c = Colors::Magenta;
	static constexpr int movePeriod = 5;
	int moveCounter = 0;
	bool jumping = false;
	int jumpForce = 3; //Number of blocks the player can jump
};