#pragma once
#include "map.h"
#include "ofMain.h"

class Player
{
	enum PlayerDirection {kUp = OF_KEY_UP, kDown = OF_KEY_DOWN, kLeft = OF_KEY_LEFT, kRight = OF_KEY_RIGHT, kNone = 0};
private:
	ofImage character;
	PlayerDirection current_direction_ = kNone;
	int pos_x = 13 * 32 + 8; //bottom right corner of screen accounting for offset to be in middle of tile
	//int pos_x = 2 * 32 + 8;
	int pos_y = 13 * 32; //bottom right corner
	//int pos_y = 5 * 32;
	int kTileSize = 32;
	/*Tile current_tile;*/

public:
	void LoadCharacter();
	void DrawCharacter();
	void UpdatePosition(Map map);
	void SetCurrentDirection(int direction);
	int GetX();
	int GetY();
	std::tuple<int, int> GetNewCoordinates(int key);
	/*void SetCurrentTile(Tile tile);*/

};