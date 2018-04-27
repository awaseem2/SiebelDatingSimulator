#pragma once
#include <vector>;
#include "ofMain.h"
#include "map.h"
#include "player.h"
#include "npc.h"

using std::vector;

class ofApp : public ofBaseApp {

private:
	Map map;
	Npc npc;
	ofRectangle npc_rect;
	Player player;
	ofRectangle player_rect;
	
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void LoadRectangles();
	void UpdatePlayerRectangle();
};
