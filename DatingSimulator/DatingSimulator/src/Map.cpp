#include "map.h"

void Map::LoadMap(const std::string &file_name)
{
	pugi::xml_document doc;
	doc.load_file(file_name.c_str());

	auto first_node = doc.first_child();

	std::string map_name = first_node.attribute("Name").value();
	std::string level_path = first_node.attribute("Path").value();
	std::string tile_sheet_path = first_node.attribute("TileSheetPath").value();
	int number_of_rows = first_node.attribute("Rows").as_int();
	int number_of_cols = first_node.attribute("Columns").as_int();

	std::ifstream file(level_path);
	std::string curr_coordinates;

	for (int row = 0; row < number_of_rows; row++)
	{
		for (int col = 0; col < number_of_cols; col++)
		{
			file >> curr_coordinates;
			Tile tile((col) * kTileSize, (row) * kTileSize, width, height, curr_coordinates[0], tile_sheet_path);
			tiles.push_back(tile);
		}
	}
}

vector<Tile> Map::GetTiles()
{
	return tiles;
}
