#pragma once
#include <string>
#include "ofMain.h"

class Tile
{

private:
	string texture = "assets/OutsideSiebelTileSheet.png";
	string tile_sheet_;
	int x_;
	int y_;
	int width_;
	int height_;
	int uv_x_;
	int uv_y_;
	bool can_walk_through;
	bool npc;

public:
	Tile(int uv_x, int uv_y, int x, int y, int width, int height, char collision_type, string tile_sheet);
	void Draw();
	bool CanWalkThrough();
	bool ContainsNpc();
};

