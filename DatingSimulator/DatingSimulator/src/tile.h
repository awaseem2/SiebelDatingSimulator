#pragma once
#include <string>
#include "ofMain.h"

class Tile
{

private:
	int x_;
	int y_;
	int width_;
	int height_;
	bool can_walk_through_ = false;
	bool next_room_ = false;
	bool previous_room_ = false;
	bool has_npc_ = false;

public:
	Tile(int x, int y, int width, int height, char collision_type);
	bool CanWalkThrough();
	bool NextRoom();
	bool PreviousRoom();
	bool HasNpc();
};

