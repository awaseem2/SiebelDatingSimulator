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
	int width = 32;
	int height = 32;
	int kTileSize = 32;
	ofImage map_image_;
	std::string map_collisions;
	std::string next_room;

public:
	void LoadMap(const std::string &file_name);
	vector<Tile> GetTiles();
	void DrawMap();
	std::string GetNextRoom();
};