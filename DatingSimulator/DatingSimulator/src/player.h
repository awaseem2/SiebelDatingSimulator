#pragma once
#include "tile.h"
#include "ofMain.h"

class Player
{
private:
	ofImage character;
	int pos_x = 12 * 32 + 8; //bottom right corner of screen accounting for offset to be in middle of tile
	int pos_y = 12 * 32; //bottom right corner
	int kTileSize = 32;
	/*Tile current_tile;*/

public:
	void LoadCharacter();
	void DrawCharacter();
	void UpdatePosition(int key);
	int GetX();
	int GetY();
	/*void SetCurrentTile(Tile tile);*/

};