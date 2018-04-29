#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowTitle("Siebel Dating Simulator");
	ofBackground(0, 0, 0);

	player.LoadCharacter();
	map.LoadMap("C:/Users/aly53/Downloads/openFrameworks/of_v0.9.8_vs_release/126 Final Project/DatingSimulator/DatingSimulator/bin/data/assets/OutsideSiebel.xml");
	npc.LoadNpc("C:/Users/aly53/Downloads/openFrameworks/of_v0.9.8_vs_release/126 Final Project/DatingSimulator/DatingSimulator/bin/data/assets/OutsideSiebel.xml");
	
	LoadRectangles();
}

//--------------------------------------------------------------
void ofApp::update() {
	player.UpdatePosition(map);
	UpdatePlayerRectangle();

	if (player_rect.intersects(npc_rect))
	{
		draw_npc_message = true;
	}
	else
	{
		draw_npc_message = false;
		npc.SetMessageIndex();
	}

	if (player.MoveToNextRoom())
	{
		player.SetMoveToNextRoom(false);
		map.LoadMap(map.GetNextRoom());
		npc.LoadNpc(map.GetNextRoom());
	}
	else if (player.MoveToPreviousRoom())
	{
		player.SetMoveToPreviousRoom(false);
		map.LoadMap(map.GetPreviousRoom());
		npc.LoadNpc(map.GetPreviousRoom());
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	map.DrawMap();
	npc.DrawNpc();
	npc.DrawItems();
	player.DrawCharacter();

	if (draw_npc_message)
	{
		npc.DrawMessage();
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

void ofApp::LoadRectangles()
{
	player_rect.setX(player.GetX());
	player_rect.setY(player.GetY());
	player_rect.setSize(32, 32);

	npc_rect.setX(npc.GetX());
	npc_rect.setY(npc.GetY());
	npc_rect.setSize(32, 32);
}

void ofApp::UpdatePlayerRectangle()
{
	player_rect.setX(player.GetX());
	player_rect.setY(player.GetY());
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