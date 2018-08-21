#pragma once

#include "Grid.h"
#include "Vec2.h"
#include "Colors.h"
#include "Keyboard.h"

class Player
{
private:
	void ClampToScreen();
public:
	Player(const Vec2 in_loc);
	void MoveBy(const Vec2 delta_loc);
	void Draw(Grid& grd) const;
	void Update(Keyboard& kbd);
private:
	Vec2 loc;
	Color c = Colors::Magenta;
	static constexpr int MovePeriod = 5;
	int MoveCounter = 0;
};