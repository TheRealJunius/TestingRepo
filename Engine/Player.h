#pragma once

#include "Grid.h"
#include "Location.h"
#include "Colors.h"
#include "Keyboard.h"

class Player
{
private:
	void ClampToScreen();
public:
	Player(const Location in_loc);
	void MoveBy(const Location delta_loc);
	void Draw(Grid& grd) const;
	void Update(Keyboard& kbd, int& mC, int mP, float dt);
private:
	Location loc;
	Color c = Colors::Magenta;
};