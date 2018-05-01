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
	Npc npc_;
	Item item_;
	vector<Tile> tiles_;
	ofImage map_image_;

	std::string map_collisions_;
	std::string name_;
	int number_of_rows_;
	int number_of_cols_;
	std::string next_room_;
	std::string previous_room_;

	tuple<int, int> next_room_coordinates_;
	tuple<int, int> previous_room_coordinates_;

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