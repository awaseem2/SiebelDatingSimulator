#pragma once
#include "tile.h";
#include <string>
#include <vector>

using std::vector;

class Map
{
private:
	vector<Tile> tiles;

public:
	void LoadMap(std::string file_name);
	void DrawMap();
	vector<Tile> GetTiles();
};

