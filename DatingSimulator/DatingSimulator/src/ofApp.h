#pragma once
#include <vector>;
#include "ofMain.h"
#include "map.h"
#include "player.h"
#include "npc.h"

using std::vector;

enum GameState {
	INTRODUCTION,
	IN_PROGRESS
};

class ofApp : public ofBaseApp {

private:
	GameState current_state_ = INTRODUCTION;
	Map map_;
	Player player_;
	bool draw_npc_message_ = false;
	bool visited_;

	ofxCenteredTrueTypeFont introduction_ttf_;
	ofxCenteredTrueTypeFont continue_ttf_;
	ofxCenteredTrueTypeFont charisma_;
	ofxCenteredTrueTypeFont romance_;
	ofRectangle charisma_bar_bg_;
	ofRectangle romance_bar_bg_;
	ofRectangle charisma_bar_progress_;
	ofRectangle romance_bar_progress_;

public:
	void setup();
	void LoadText();
	void update();
	void draw();
	void drawInfoBars();
	void drawIntro();

	void keyPressed(int key);
	void keyReleased(int key);
	void mousePressed(int x, int y, int button);
};
