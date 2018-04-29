#include "map.h"

void Map::LoadMap(const std::string &file_name)
{
	tiles.clear();
	pugi::xml_document doc;
	doc.load_file(file_name.c_str());

	auto first_node = doc.first_child();

	std::string map_name = first_node.attribute("Name").value();
	map_collisions = first_node.attribute("Collisions").value();
	map_image_.load(first_node.attribute("MapImagePath").value());
	next_room = first_node.attribute("NextRoom").value();
	previous_room = first_node.attribute("PreviousRoom").value();

	int number_of_rows = first_node.attribute("Rows").as_int();
	int number_of_cols = first_node.attribute("Columns").as_int();

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

std::string Map::GetPreviousRoom()
{
	return previous_room;
}

Npc Map::GetNpc()
{
	return npc;
}
