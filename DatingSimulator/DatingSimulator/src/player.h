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
	ofImage character;
	PlayerDirection current_direction_ = kNone;
	int pos_x = GlobalConstants::kStartingPosX;
	int pos_y = GlobalConstants::kStartingPosY;
	int offset = -8;
	int charisma_pts = 50;
	int romance_pts = 50;
	int percent_charisma_;
	int percent_romance_;

	ofxCenteredTrueTypeFont charisma_;
	ofxCenteredTrueTypeFont romance_;
	ofRectangle charisma_bar_bg;
	ofRectangle romance_bar_bg;
	ofRectangle charisma_bar_progress;
	ofRectangle romance_bar_progress;

	bool move_to_next_room = false;
	bool move_to_previous_room = false;
	bool talk_to_npc = false;

	std::vector<std::string> rooms_visited;

public:
	void LoadCharacter();
	void DrawCharacter();
	void DrawInfoBars();
	void UpdatePosition(Map map);
	void SetCurrentDirection(int direction);
	void UpdateStats();
	std::tuple<int, int> GetNewCoordinates(int key);

	int GetX();
	int GetY();

	void SetStats(std::tuple<int, int> stats);
	bool RoomVisited(std::string room);
	bool MoveToNextRoom();
	void SetMoveToNextRoom(bool next);
	bool MoveToPreviousRoom();
	void SetMoveToPreviousRoom(bool prev);
	bool TalkToNpc();
	void SetTalkToNpc(bool talk);
};