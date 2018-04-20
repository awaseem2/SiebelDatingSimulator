#include "tile.h"

Tile::Tile(int uv_x, int uv_y, int x, int y, int width, int height, char collision_type) :
	uv_x_(uv_x),
	uv_y_(uv_y),
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
	}
}

void Tile::Draw()
{
	ofImage image;
	image.load(texture);
	image.drawSubsection(x_ + 8, y_ + 32, width_, height_, uv_x_, uv_y_, width_, height_);
}

bool Tile::CanWalkThrough()
{
	return can_walk_through;
}

void Tile::SetCanWalkThrough(bool boolean)
{
	can_walk_through = boolean;
}


