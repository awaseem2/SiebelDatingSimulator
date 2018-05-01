#include "tile.h"

Tile::Tile(int x, int y, int width, int height, char collision_type) :
	x_(x),
	y_(y),
	width_(width),
	height_(height)
{
	if (collision_type == '*')
	{
		can_walk_through = false;
	}
	else
	{
		can_walk_through = true;
		switch (collision_type)
		{
		case '+':
			next_room = true;
			break;

		case '-':
			previous_room = true;
			break;

		case '!':
			has_npc = true;
			break;
		}
	}
}

bool Tile::CanWalkThrough()
{
	return can_walk_through;
}

bool Tile::NextRoom()
{
	return next_room;
}

bool Tile::PreviousRoom()
{
	return previous_room;
}

bool Tile::HasNpc()
{
	return has_npc;
}