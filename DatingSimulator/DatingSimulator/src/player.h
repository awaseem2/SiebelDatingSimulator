#pragma once
#include "map.h"
#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"

class Player
{
	enum PlayerDirection {kUp = OF_KEY_UP, kDown = OF_KEY_DOWN, kLeft = OF_KEY_LEFT, kRight = OF_KEY_RIGHT, kNone = 0};
private:
	ofImage character;
	PlayerDirection current_direction_ = kNone;
	int pos_x = 12 * 32 + 8; // + 8 accounting for offset to be in middle of tile
	int pos_y = 12 * 32;
	int kTileSize = 1;
	int offset = -8;
	int charisma_pts = 50;
	int romance_pts = 50;

	ofxCenteredTrueTypeFont charisma_;
	ofxCenteredTrueTypeFont romance_;
	ofRectangle charisma_bar_bg;
	ofRectangle romance_bar_bg;
	ofRectangle charisma_bar_progress;
	ofRectangle romance_bar_progress;

	bool move_to_next_room = false;
	bool move_to_previous_room = false;
	bool talk_to_npc = false;

public:
	void LoadCharacter();
	void DrawCharacter();
	void DrawInfoBars();
	void UpdatePosition(Map map);
	void SetCurrentDirection(int direction);
	std::tuple<int, int> GetNewCoordinates(int key);

	int GetX();
	int GetY();

	bool MoveToNextRoom();
	void SetMoveToNextRoom(bool next);
	bool MoveToPreviousRoom();
	void SetMoveToPreviousRoom(bool prev);
	bool TalkToNpc();
	void SetTalkToNpc(bool talk);
};