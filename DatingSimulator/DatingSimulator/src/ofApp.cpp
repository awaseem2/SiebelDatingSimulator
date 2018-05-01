#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowTitle("Siebel Dating Simulator");
	ofBackground(0, 0, 0);

	player.LoadCharacter();
	map.LoadNewMap("C:/Users/aly53/Downloads/openFrameworks/of_v0.9.8_vs_release/126 Final Project/DatingSimulator/DatingSimulator/bin/data/assets/OutsideSiebel.xml");
	visited = player.RoomVisited(map.GetName());
}

//--------------------------------------------------------------
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

//--------------------------------------------------------------
void ofApp::draw() {
	map.DrawMap();
	player.DrawCharacter();

	if (draw_npc_message)
	{
		map.GetNpc().DrawMessage();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_DOWN || key == OF_KEY_UP || key == OF_KEY_RIGHT || OF_KEY_LEFT)
	{
		player.SetCurrentDirection(key);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	player.SetCurrentDirection(0);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
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

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}