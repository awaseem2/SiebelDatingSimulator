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
	bool can_walk_through;

public:
	Tile(int x, int y, int width, int height, char collision_type, string tile_sheet);
	bool CanWalkThrough();
	ofRectangle GetRectangle();
};

