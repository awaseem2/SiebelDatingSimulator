#pragma once
#include "ofMain.h"
#include <string>

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

public:
	Tile(int uv_x, int uv_y, int x, int y, int width, int height);
	void Draw();
};

