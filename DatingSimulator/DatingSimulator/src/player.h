#pragma once
#include "map.h"
#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"
#include <string>
#include <tuple>
#include <vector>

class Player
{
	enum PlayerDirection {kUp = OF_KEY_UP, kDown = OF_KEY_DOWN, kLeft = OF_KEY_LEFT, kRight = OF_KEY_RIGHT, kNone = 0};
private:
	ofImage character_;
	PlayerDirection current_direction_ = kNone;
	int pos_x_ = GlobalConstants::kStartingPosX;
	int pos_y_ = GlobalConstants::kStartingPosY;
	int charisma_pts_ = 50;
	int romance_pts_ = 50;
	int percent_charisma_;
	int percent_romance_;

	bool move_to_next_room_ = false;
	bool move_to_previous_room_ = false;
	bool talk_to_npc_ = false;

	std::vector<std::string> rooms_visited;

public:
	void LoadCharacter();
	void DrawCharacter();
	void UpdatePosition(Map map);
	Tile GetNextTile(Map map, int new_x, int new_y);
	void SetCurrentDirection(int direction);
	void UpdateStats();
	std::tuple<int, int> GetNewCoordinates(int key);

	void SetStats(std::tuple<int, int> stats);
	bool RoomVisited(std::string room);

	int GetX();
	int GetY();
	int GetPercentCharisma();
	int GetPercentRomance();
	bool MoveToNextRoom();
	void SetMoveToNextRoom(bool next);
	bool MoveToPreviousRoom();
	void SetMoveToPreviousRoom(bool prev);
	bool TalkToNpc();
	void SetTalkToNpc(bool talk);
};