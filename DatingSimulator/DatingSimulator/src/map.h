#pragma once
#include "tile.h";
#include <string>
#include <vector>

using std::vector;

class Map
{
private:
	vector<Tile> tiles;
	int map_width;
	int map_height;

public:
	void LoadMap(std::string file_name);
	void DrawMap();
};

