#pragma once
#include "ofMain.h"
class Player
{
private:
	ofImage character;
	int pos_x = 13 * 32 + 8; //bottom right corner of screen accounting for offset to be in middle of tile
	int pos_y = 12 * 32; //bottom right corner
	int kTileSize = 32;

public:
	void LoadCharacter();
	void DrawCharacter();
	void UpdatePosition(int key);

};

