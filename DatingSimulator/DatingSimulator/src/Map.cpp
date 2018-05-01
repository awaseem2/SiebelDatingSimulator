#include "map.h"

void Map::LoadNewMap(const std::string &file_name)
{
	tiles.clear();
	pugi::xml_document doc;
	doc.load_file(file_name.c_str());

	map = doc.first_child();

	map_collisions = map.attribute("Collisions").value();
	map_image_.load(map.attribute("MapImagePath").value());
	name = map.attribute("Name").value();
	next_room = map.attribute("NextRoomPath").value();
	previous_room = map.attribute("PreviousRoomPath").value();

	int number_of_rows = map.attribute("Rows").as_int();
	int number_of_cols = map.attribute("Columns").as_int();

	std::ifstream file(map_collisions);
	std::string curr_coordinates;

	for (int row = 0; row < number_of_rows; row++)
	{
		for (int col = 0; col < number_of_cols; col++)
		{
			file >> curr_coordinates;
			Tile tile((col) * kTileSize, (row) * kTileSize, width, height, curr_coordinates[0]);
			tiles.push_back(tile);
		}
	}

	npc.LoadNpc(file_name);
	item.LoadItem(file_name);

	next_room_coordinates = std::make_tuple(map.attribute("NextRoomX").as_int(), map.attribute("NextRoomY").as_int());
	previous_room_coordinates = std::make_tuple(map.attribute("PreviousRoomX").as_int(), map.attribute("PreviousRoomY").as_int());
}

vector<Tile> Map::GetTiles()
{
	return tiles;
}

void Map::DrawMap()
{
	map_image_.draw(8, 32);
	npc.DrawNpc();
	item.DrawItem();
}

std::string Map::GetNextRoom()
{
	return next_room;
}

tuple<int, int> Map::GetNextRoomCoordinates()
{
	return next_room_coordinates;
}

std::string Map::GetPreviousRoom()
{
	return previous_room;
}

tuple<int, int> Map::GetPreviousRoomCoordinates()
{
	return previous_room_coordinates;
}

Npc& Map::GetNpc()
{
	return npc;
}

std::string Map::GetName()
{
	return name;
}
