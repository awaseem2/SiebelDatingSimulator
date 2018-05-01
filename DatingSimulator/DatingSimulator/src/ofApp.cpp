#include "ofApp.h"

void ofApp::setup() {
	ofSetWindowTitle("Siebel Dating Simulator");
	ofBackground(0, 0, 0);

	player.LoadCharacter();
	map.LoadNewMap(GlobalConstants::kStartingRoomPath);
	visited = player.RoomVisited(map.GetName());
}

void ofApp::update() {
	player.UpdatePosition(map);

	if (player.TalkToNpc() && !visited)
	{
		draw_npc_message = true;
		player.SetTalkToNpc(false);
	}
	else
	{
		draw_npc_message = false;
	}

	if (player.MoveToNextRoom())
	{
		player.SetMoveToNextRoom(false);
		map.LoadNewMap(map.GetNextRoom());
		visited = player.RoomVisited(map.GetName());
	}
	else if (player.MoveToPreviousRoom())
	{
		player.SetMoveToPreviousRoom(false);
		map.LoadNewMap(map.GetPreviousRoom());
		visited = player.RoomVisited(map.GetName());
	}

}

void ofApp::draw() {
	map.DrawMap();
	player.DrawCharacter();

	if (draw_npc_message)
	{
		map.GetNpc().DrawMessage();
	}
}

void ofApp::keyPressed(int key) {
	if (key == OF_KEY_DOWN || key == OF_KEY_UP || key == OF_KEY_RIGHT || OF_KEY_LEFT)
	{
		player.SetCurrentDirection(key);
	}
}

void ofApp::keyReleased(int key) {
	player.SetCurrentDirection(0);
}

void ofApp::mousePressed(int x, int y, int button) {
	bool option_chosen = map.GetNpc().OptionChosen();
	if (!option_chosen)
	{ 
		ofRectangle option_1 = map.GetNpc().GetOption1Rect();
		ofRectangle option_2 = map.GetNpc().GetOption2Rect();

		if (option_1.inside(x, y))
		{
			map.GetNpc().SetOptionChosen(true, 1);
			map.GetNpc().SetShowOptions(false);
			player.SetStats(map.GetNpc().GetStatsChange());
		}
		else if (option_2.inside(x, y))
		{
			map.GetNpc().SetOptionChosen(true, 2);
			map.GetNpc().SetShowOptions(false);
			player.SetStats(map.GetNpc().GetStatsChange());
		}
	}
}