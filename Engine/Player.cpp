#include "Player.h"

void Player::ClampToScreen()
{
	if (loc.x >= Grid::Width)
	{
		loc.x = Grid::Width - 1;
	}
	if (loc.x < 0)
	{
		loc.x = 0;
	}
	if (loc.y >= Grid::Height)
	{
		loc.y = Grid::Height - 1;
	}
	if (loc.y < 0)
	{
		loc.y = 0;
	}
}

void Player::PlayerWithBlocksCollision(Vec2& dl, std::vector<World::Block> b)
{
	//Checking if there is a block on the player's right/left/down/up/diagonals and respond by changing the delta_loc
	if ((dl.x != 0 && dl.y == 0) || (dl.x == 0 && dl.y != 0) || (dl.x != 0 && dl.y != 0))
	{
		for (int i = 0; i < b.size(); i++)
		{
			if (b.at(i).GetLocation() == loc + dl)
			{
				dl = { 0,0 };
			}
		}
	}
}

Player::Player(const Vec2 in_loc)
{
	loc = in_loc;
}

void Player::MoveBy(const Vec2 delta_loc)
{
	loc += delta_loc;
}

void Player::Draw(Grid & grd) const
{
	grd.DrawCell(loc, c);
}

void Player::Update(Keyboard& kbd, std::vector<World::Block> b)
{
	Vec2 delta_loc = { 0,0 };

	//Horizontal movement
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		delta_loc += { 1, 0 };
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		delta_loc += { -1, 0 };
	}
	//Horizontal movement

	if (moveCounter++ == movePeriod)
	{
		moveCounter = 0; //Reset moveCounter

		//Jump mechanism
		if (kbd.KeyIsPressed(VK_UP))
		{
			if (jumping)
			{
				if (jumpForce != 0) //Jumping
				{
					delta_loc += {0, -1};
					jumpForce--;
				}
				else //Falling
				{
					jumping = false;

					delta_loc += {0, 1};

					//Checking if the player has a block under it so it can stop falling
					Vec2 underBlock = { 0, 1 };
					for (int i = 0; i < b.size(); i++)
					{
						if (b.at(i).GetLocation() == loc + underBlock)
						{
							jumpForce = 4; //Reseting the jumpForce
							delta_loc += {0, -1}; //This will make the delta loc 0,0
							break;
						}
					}
				}
			}
			else
			{
				//Checking if the player has a block under it so it can jump
				Vec2 underBlock = { 0, 1 };
				for (int i = 0; i < b.size(); i++)
				{
					if (b.at(i).GetLocation() == loc + underBlock)
					{
						jumping = true;
						break;
					}
				}
			}
		}

		if (jumping)
		{
			if (jumpForce != 0) //Jumping
			{
				delta_loc += {0, -1};
				jumpForce--;
			}
			else //Falling
			{
				jumping = false;
			}
		}
		else //This was added because even if the player doesn't hold of the up key anymore
						 //The player would still fall, of course
						 //By the way, this is just copied from above of the //Falling sector
		{
			delta_loc += {0, 1};

			//Checking if the player has a block under it so it can stop falling
			Vec2 underBlock = { 0, 1 };
			for (int i = 0; i < b.size(); i++)
			{
				if (b.at(i).GetLocation() == loc + underBlock)
				{
					jumpForce = 4; //Reseting the jumpForce
					delta_loc += {0, -1}; //This will make the delta loc 0,0
					break;
				}
			}
		}
		//Jump mechanism

		PlayerWithBlocksCollision(delta_loc, b);
		MoveBy(delta_loc);
		ClampToScreen();
	}
}
