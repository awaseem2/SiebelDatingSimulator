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
	Player player;
	bool draw_npc_message = false;
	bool visited;
	
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mousePressed(int x, int y, int button);
};
