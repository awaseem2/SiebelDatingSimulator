#pragma once
#include "tile.h"
#include "pugixml.hpp"
#include <string>
#include <vector>

using std::vector;

class Map
{
private:
	vector<Tile> tiles;

public:
	void LoadMap(const std::string &file_name);
	void DrawMap();
	vector<Tile> GetTiles();
};