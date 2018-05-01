#include "map.h"

void Map::LoadNewMap(const std::string &file_name)
{
	tiles_.clear();
	ParseFile(file_name);

	std::ifstream file(map_collisions_);
	std::string curr_coordinates;

	for (int row = 0; row < number_of_rows_; row++)
	{
		for (int col = 0; col < number_of_cols_; col++)
		{
			file >> curr_coordinates;
			Tile tile(col, row, GlobalConstants::kTileSize, GlobalConstants::kTileSize, curr_coordinates[0]);
			tiles_.push_back(tile);
		}
	}

	npc_.LoadNpc(file_name);
	item_.LoadItem(file_name);
}

void Map::ParseFile(const std::string &file_name)
{
	pugi::xml_document doc;
	doc.load_file(file_name.c_str());

	auto map_ = doc.first_child();

	map_collisions_ = map_.attribute("Collisions").value();
	map_image_.load(map_.attribute("MapImagePath").value());
	name_ = map_.attribute("Name").value();
	next_room_ = map_.attribute("NextRoomPath").value();
	previous_room_ = map_.attribute("PreviousRoomPath").value();

	number_of_rows_ = map_.attribute("Rows").as_int();
	number_of_cols_ = map_.attribute("Columns").as_int();

	next_room_coordinates_ = std::make_tuple(map_.attribute("NextRoomX").as_int(), map_.attribute("NextRoomY").as_int());
	previous_room_coordinates_ = std::make_tuple(map_.attribute("PreviousRoomX").as_int(), map_.attribute("PreviousRoomY").as_int());
}

vector<Tile> Map::GetTiles()
{
	return tiles_;
}

void Map::DrawMap()
{
	map_image_.draw(8, 32);
	npc_.DrawNpc();
	item_.DrawItem();
}

std::string Map::GetNextRoom()
{
	return next_room_;
}

tuple<int, int> Map::GetNextRoomCoordinates()
{
	return next_room_coordinates_;
}

std::string Map::GetPreviousRoom()
{
	return previous_room_;
}

tuple<int, int> Map::GetPreviousRoomCoordinates()
{
	return previous_room_coordinates_;
}

Npc& Map::GetNpc()
{
	return npc_;
}

std::string Map::GetName()
{
	return name_;
}
