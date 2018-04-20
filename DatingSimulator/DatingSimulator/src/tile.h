#pragma once
#include <string>
#include "ofMain.h"

class Tile
{

private:
	std::string texture = "assets/OutsideSiebelTileSheet.png";
	int x_;
	int y_;
	int width_;
	int height_;
	int uv_x_;
	int uv_y_;
	bool can_walk_through;

public:
	Tile(int uv_x, int uv_y, int x, int y, int width, int height, char collision_type);
	void Draw();
	bool CanWalkThrough();
	void SetCanWalkThrough(bool boolean);
};

