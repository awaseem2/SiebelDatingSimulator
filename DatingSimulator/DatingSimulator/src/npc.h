#pragma once
#include "ofMain.h"
#include "pugixml.hpp"
#include "globalConstants.h"
#include <string>
#include <vector>
#include <tuple>
#include "ofxCenteredTrueTypeFont.h"

using std::vector;
using std::tuple;

class Npc
{

private:
	int pos_x_ = 0;
	int pos_y_ = 0;
	int greeting_x_ = 32 * 20;
	int greeting_y_ = 32 * 4 + 8;
	int option_1_y_ = greeting_y_ + 32 * 4;
	int option_2_y_ = greeting_y_ + 32 * 5.5;
	int options_height_ = 32;
	int options_width_ = ofGetWindowWidth() - 32 * 22;
	int message_index_ = 0;
	bool npc_exists_ = false;
	bool show_options_ = false;
	bool option_chosen_;
	
	
	std::string greeting_; 
	pugi::xml_node curr_room_;
	pugi::xml_node npc_;
	ofImage npc_image_;

	ofxCenteredTrueTypeFont greeting_ttf_;
	pugi::xml_node option_1_;
	pugi::xml_node option_2_;
	ofxCenteredTrueTypeFont option_1_ttf_;
	ofxCenteredTrueTypeFont option_2_ttf_;
	std::string option_1_text_;
	std::string option_2_text_;
	bool option_1_chosen_ = false;
	bool option_2_chosen_ = false;
	std::string outcome_1_;
	std::string outcome_2_;
	int charisma_1_;
	int charisma_2_;
	int romance_1_;
	int romance_2_;
	ofxCenteredTrueTypeFont outcome_ttf_;

public:
	void LoadNpc(const std::string &file_name);
	void LoadText();
	void LoadOptions();
	void DrawNpc();
	void DrawMessage();
	void DrawOptions();
	void SetOptionChosen(bool boolean, int option);
	void SetShowOptions(bool boolean);
	
	tuple<int, int> GetStatsChange();
	int GetX();
	int GetY();
	ofRectangle GetOption1Rect();
	ofRectangle GetOption2Rect();
	bool OptionChosen();
};

