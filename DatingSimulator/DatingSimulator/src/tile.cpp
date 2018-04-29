#include "tile.h"

Tile::Tile(int x, int y, int width, int height, char collision_type) :
	x_(x),
	y_(y),
	width_(width),
	height_(height)
{
	//switch case?
	if (collision_type == '*')
	{
		can_walk_through = false;
	}
	else
	{
		can_walk_through = true;

		if (collision_type == '+')
		{
			next_room = true;

		}
		else if (collision_type == '-')
		{
			previous_room = true;
		}
		else if (collision_type == '!')
		{
			has_npc = true;
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

ofRectangle Tile::GetRectangle()
{
	ofRectangle rect;
	rect.setX(x_);
	rect.setY(y_);
	rect.setSize(width_, height_);
	return rect;
}





