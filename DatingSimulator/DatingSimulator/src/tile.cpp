#include "tile.h"

Tile::Tile(int x, int y, int width, int height, char collision_type) :
	x_(x),
	y_(y),
	width_(width),
	height_(height)
{
	if (collision_type == '*')
	{
		can_walk_through_ = false;
	}
	else
	{
		can_walk_through_ = true;
		switch (collision_type)
		{
		case '+':
			next_room_ = true;
			break;

		case '-':
			previous_room_ = true;
			break;

		case '!':
			has_npc_ = true;
			break;
		}
	}
}

bool Tile::CanWalkThrough()
{
	return can_walk_through_;
}

bool Tile::NextRoom()
{
	return next_room_;
}

bool Tile::PreviousRoom()
{
	return previous_room_;
}

bool Tile::HasNpc()
{
	return has_npc_;
}