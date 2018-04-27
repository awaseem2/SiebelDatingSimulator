#pragma once
#include "map.h"
#include "ofMain.h"

class Player
{
private:
	ofImage character;
	//int pos_x = 11 * 32 + 8; //bottom right corner of screen accounting for offset to be in middle of tile
	int pos_x = 2 * 32 + 8;
	//int pos_y = 11 * 32; //bottom right corner
	int pos_y = 5 * 32;
	int kTileSize = 32;
	/*Tile current_tile;*/

public:
	void LoadCharacter();
	void DrawCharacter();
	void UpdatePosition(int key, Map map);
	int GetX();
	int GetY();
	std::tuple<int, int> GetNewCoordinates(int key);
	/*void SetCurrentTile(Tile tile);*/

};