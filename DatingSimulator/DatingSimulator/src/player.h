#pragma once
#include "map.h"
#include "ofMain.h"

class Player
{
	enum PlayerDirection {kUp = OF_KEY_UP, kDown = OF_KEY_DOWN, kLeft = OF_KEY_LEFT, kRight = OF_KEY_RIGHT, kNone = 0};
private:
	ofImage character;
	PlayerDirection current_direction_ = kNone;
	int pos_x = 12 * 32 + 8; // + 8 accounting for offset to be in middle of tile
	int pos_y = 12 * 32; 
	//int pos_x = 3 * 32 + 8;
	//int pos_y = 5 * 32;
	int kTileSize = 1;
	int offset = -8;
	ofRectangle player_rect;
	string curr_room_name;
	bool move_to_next_room = false;

public:
	void LoadCharacter();
	void DrawCharacter();
	void UpdatePosition(Map map);
	void SetCurrentDirection(int direction);
	std::tuple<int, int> GetNewCoordinates(int key);
	int GetX();
	int GetY();
	void SetCurrentRoomName();
	string GetCurrentRoomName();
	bool MoveToNextRoom();
	void SetMoveToNextRoom(bool next);
};