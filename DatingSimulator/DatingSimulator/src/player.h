#pragma once
#include "map.h"
#include "ofMain.h"

class Player
{
	enum PlayerDirection {kUp = OF_KEY_UP, kDown = OF_KEY_DOWN, kLeft = OF_KEY_LEFT, kRight = OF_KEY_RIGHT, kNone = 0};
private:
	ofImage character;
	PlayerDirection current_direction_ = kNone;
	int pos_x = 8 * 32 + 8; // + 8 accounting for offset to be in middle of tile
	int pos_y = 6 * 32; 
	int kTileSize = 32;

public:
	void LoadCharacter();
	void DrawCharacter();
	void UpdatePosition(Map map);
	void SetCurrentDirection(int direction);
	int GetX();
	int GetY();
	std::tuple<int, int> GetNewCoordinates(int key);
};