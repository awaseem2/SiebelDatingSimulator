#include "map.h"

void Map::LoadMap(std::string file_name)
{
	std::ifstream file(file_name);
	std::string curr_coordinates;

	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 13; col++)
		{
			file >> curr_coordinates;
			Tile tile((curr_coordinates[0] - '0') * 32, (curr_coordinates[2] - '0') * 32, (col) * 32, (row) * 32, 
				32, 32, curr_coordinates[3]);
			tiles.push_back(tile);
		}
	}
}

void Map::DrawMap()
{
	for (auto tile : tiles)
	{
		tile.Draw();
	}
}



