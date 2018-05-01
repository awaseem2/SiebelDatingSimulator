#pragma once
#include "tile.h"
#include "pugixml.hpp"
#include "npc.h"
#include "item.h"
#include "globalConstants.h"
#include <string>
#include <vector>
#include <tuple>

using std::vector;
using std::tuple;

class Map
{
private:
	Npc npc;
	Item item;
	vector<Tile> tiles;
	ofImage map_image_;

	pugi::xml_node map;
	std::string map_collisions;
	std::string name;
	int number_of_rows;
	int number_of_cols;
	std::string next_room;
	std::string previous_room;
	tuple<int, int> next_room_coordinates;
	tuple<int, int> previous_room_coordinates;

public:
	void LoadNewMap(const std::string &file_name);
	void ParseFile(const std::string &file_name);
	vector<Tile> GetTiles();
	void DrawMap();
	std::string GetNextRoom();
	tuple<int, int> GetNextRoomCoordinates();
	std::string GetPreviousRoom();
	tuple<int, int> GetPreviousRoomCoordinates();
	Npc& GetNpc();
	std::string GetName();
};