#pragma once
#include "tile.h"
#include "pugixml.hpp"
#include "npc.h"
#include "item.h"
#include <string>
#include <vector>
#include <tuple>

using std::vector;
using std::tuple;

class Map
{
private:
	pugi::xml_node map;
	Npc npc;
	Item item;
	vector<Tile> tiles;
	int width = 32;
	int height = 32;
	int kTileSize = 32;
	ofImage map_image_;
	std::string map_collisions;
	std::string name;
	std::string next_room;
	std::string previous_room;
	tuple<int, int> next_room_coordinates;
	tuple<int, int> previous_room_coordinates;

public:
	void LoadNewMap(const std::string &file_name);
	vector<Tile> GetTiles();
	void DrawMap();
	std::string GetNextRoom();
	tuple<int, int> GetNextRoomCoordinates();
	std::string GetPreviousRoom();
	tuple<int, int> GetPreviousRoomCoordinates();
	Npc& GetNpc();
	std::string GetName();
};