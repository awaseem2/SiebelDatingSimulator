#include "tile.h"

Tile::Tile(int x, int y, int width, int height, char collision_type, string tile_sheet) :
	x_(x),
	y_(y),
	width_(width),
	height_(height),
	tile_sheet_(tile_sheet)
{
	if (collision_type == '*')
	{
		can_walk_through = false;
	}
	else
	{
		can_walk_through = true;
	}
}

bool Tile::CanWalkThrough()
{
	return can_walk_through;
}

ofRectangle Tile::GetRectangle()
{
	ofRectangle rect;
	rect.setX(x_);
	rect.setY(y_);
	rect.setSize(width_, height_);
	return rect;
}





