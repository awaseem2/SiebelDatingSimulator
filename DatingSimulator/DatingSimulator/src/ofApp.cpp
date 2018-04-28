#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowTitle("Siebel Dating Simulator");
	ofBackground(255, 255, 255);
	map.LoadMap("C:/Users/aly53/Downloads/openFrameworks/of_v0.9.8_vs_release/126 Final Project/DatingSimulator/DatingSimulator/bin/data/assets/MapLayout.xml");
	npc.LoadNpc("C:/Users/aly53/Downloads/openFrameworks/of_v0.9.8_vs_release/126 Final Project/DatingSimulator/DatingSimulator/bin/data/assets/MapLayout.xml");
	player.LoadCharacter();
	LoadRectangles();
	map_image.load("assets/OutsideSiebelMap.png");
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

}

//--------------------------------------------------------------
void ofApp::draw() {
	map_image.draw(8, 32);
	npc.DrawNpc();
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