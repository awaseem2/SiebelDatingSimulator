#pragma once
#include "tile.h"
#include "pugixml.hpp"
#include "npc.h"
#include "item.h"
#include <string>
#include <vector>

using std::vector;

class Map
{
private:
	Npc npc;
	Item item;
	vector<Tile> tiles;
	int width = 32;
	int height = 32;
	int kTileSize = 32;
	ofImage map_image_;
	std::string map_collisions;
	std::string next_room;
	std::string previous_room;

public:
	void LoadMap(const std::string &file_name);
	vector<Tile> GetTiles();
	void DrawMap();
	std::string GetNextRoom();
	std::string GetPreviousRoom();
	Npc GetNpc();
};