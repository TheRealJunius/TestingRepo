#pragma once

#include "Grid.h"
#include "Location.h"
#include "Colors.h"

class Player
{
public:
	Player(const Location in_loc);
	void MoveBy(const Location delta_loc);
	void Draw(Grid& grd) const;
private:
	Location loc;
	Color c;
};