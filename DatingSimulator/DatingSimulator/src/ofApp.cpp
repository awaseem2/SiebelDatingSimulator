#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowTitle("Siebel Dating Simulator");
	ofBackground(0, 0, 0);

	player.LoadCharacter();
	map.LoadMap("C:/Users/aly53/Downloads/openFrameworks/of_v0.9.8_vs_release/126 Final Project/DatingSimulator/DatingSimulator/bin/data/assets/OutsideSiebel.xml");
}

//--------------------------------------------------------------
void ofApp::update() {
	player.UpdatePosition(map);

	if (player.TalkToNpc())
	{
		draw_npc_message = true;
		player.SetTalkToNpc(false);
	}
	else
	{
		draw_npc_message = false;
		//map.GetNpc().SetMessageIndex();
	}

	if (player.MoveToNextRoom())
	{
		player.SetMoveToNextRoom(false);
		map.LoadMap(map.GetNextRoom());
	}
	else if (player.MoveToPreviousRoom())
	{
		player.SetMoveToPreviousRoom(false);
		map.LoadMap(map.GetPreviousRoom());
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	map.DrawMap();
	//npc.DrawItems();
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