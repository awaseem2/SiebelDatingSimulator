#include "tile.h"

Tile::Tile(int uv_x, int uv_y, int x, int y, int width, int height, char collision_type, string tile_sheet) :
	uv_x_(uv_x),
	uv_y_(uv_y),
	x_(x),
	y_(y),
	width_(width),
	height_(height),
	tile_sheet_(tile_sheet)
{
	if (collision_type == '*' || collision_type == '!')
	{
		can_walk_through = false;

		if (collision_type == '!') 
		{
			npc = true;
		}
	}
	else
	{
		can_walk_through = true;
	}
}

void Tile::Draw()
{
	ofImage image;
	image.load(tile_sheet_);
	image.drawSubsection(x_ + 8, y_ + 32, width_, height_, uv_x_, uv_y_, width_, height_);
}

bool Tile::CanWalkThrough()
{
	return can_walk_through;
}

bool Tile::ContainsNpc()
{
	return npc;
}



