#include "ofApp.h"

void ofApp::setup() {
	ofSetWindowTitle("Siebel Dating Simulator");
	ofBackground(0, 0, 0);

	player_.LoadCharacter();
	map_.LoadNewMap(GlobalConstants::kStartingRoomPath);
	visited_ = player_.RoomVisited(map_.GetName());

	charisma_.loadFont(GlobalConstants::kFontName, GlobalConstants::kSmallTextSize);
	romance_.loadFont(GlobalConstants::kFontName, GlobalConstants::kSmallTextSize);
}

void ofApp::update() {
	player_.UpdatePosition(map_);

	if (player_.TalkToNpc() && !visited_)
	{
		draw_npc_message_ = true;
		player_.SetTalkToNpc(false);
	}
	else
	{
		draw_npc_message_ = false;
	}

	if (player_.MoveToNextRoom())
	{
		player_.SetMoveToNextRoom(false);
		map_.LoadNewMap(map_.GetNextRoom());
		visited_ = player_.RoomVisited(map_.GetName());
	}
	else if (player_.MoveToPreviousRoom())
	{
		player_.SetMoveToPreviousRoom(false);
		map_.LoadNewMap(map_.GetPreviousRoom());
		visited_ = player_.RoomVisited(map_.GetName());
	}

}

void ofApp::draw() {
	map_.DrawMap();
	player_.DrawCharacter();

	if (draw_npc_message_)
	{
		map_.GetNpc().DrawMessage();
	}

	drawInfoBars();
}

void ofApp::drawInfoBars()
{
	//Charisma and Romance labels
	ofSetColor(255, 255, 255);
	charisma_.drawStringCentered("Charisma", ofVec2f(ofGetWindowWidth() - GlobalConstants::kStatsLabelsX,
		ofGetWindowHeight() - GlobalConstants::kCharismaLabelY));
	romance_.drawStringCentered("Romance", ofVec2f(ofGetWindowWidth() - GlobalConstants::kStatsLabelsX,
		ofGetWindowHeight() - GlobalConstants::kRomanceLabelY));

	//White background of the stat bars
	ofDrawRectangle(ofGetWindowWidth() - GlobalConstants::kStatsBarsX,
		ofGetWindowHeight() - GlobalConstants::kCharismaBarY, GlobalConstants::kStatsBarsLength, GlobalConstants::kStatsBarsWidth);
	ofDrawRectangle(ofGetWindowWidth() - GlobalConstants::kStatsBarsX,
		ofGetWindowHeight() - GlobalConstants::kRomanceBarY, GlobalConstants::kStatsBarsLength, GlobalConstants::kStatsBarsWidth);

	//Red progress of the charisma and romance stats
	ofSetColor(255, 0, 0);
	ofDrawRectangle(ofGetWindowWidth() - GlobalConstants::kStatsBarsX,
		ofGetWindowHeight() - GlobalConstants::kCharismaBarY, player_.GetPercentCharisma(), GlobalConstants::kStatsBarsWidth);
	ofDrawRectangle(ofGetWindowWidth() - GlobalConstants::kStatsBarsX,
		ofGetWindowHeight() - GlobalConstants::kRomanceBarY, player_.GetPercentRomance(), GlobalConstants::kStatsBarsWidth);

	//Undo color to prevent entire screen being filled
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
}

void ofApp::keyPressed(int key) {
	if (key == OF_KEY_DOWN || key == OF_KEY_UP || key == OF_KEY_RIGHT || OF_KEY_LEFT)
	{
		player_.SetCurrentDirection(key);
	}
}

void ofApp::keyReleased(int key) {
	player_.SetCurrentDirection(0);
}

void ofApp::mousePressed(int x, int y, int button) {
	bool option_chosen = map_.GetNpc().OptionChosen();
	if (!option_chosen)
	{ 
		ofRectangle option_1 = map_.GetNpc().GetOption1Rect();
		ofRectangle option_2 = map_.GetNpc().GetOption2Rect();

		if (option_1.inside(x, y))
		{
			map_.GetNpc().SetOptionChosen(true, 1);
			map_.GetNpc().SetShowOptions(false);
			player_.SetStats(map_.GetNpc().GetStatsChange());
		}
		else if (option_2.inside(x, y))
		{
			map_.GetNpc().SetOptionChosen(true, 2);
			map_.GetNpc().SetShowOptions(false);
			player_.SetStats(map_.GetNpc().GetStatsChange());
		}
	}
}