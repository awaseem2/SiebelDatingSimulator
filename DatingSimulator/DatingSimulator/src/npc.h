#pragma once
#include "ofMain.h"
#include "pugixml.hpp"
#include <string>
#include <vector>
#include "ofxCenteredTrueTypeFont.h"

using std::vector;

class Npc
{

private:
	std::string greeting; 
	pugi::xml_node curr_room;
	pugi::xml_node npc;
	ofImage npc_image_;
	int pos_x_ = 0;
	int pos_y_ = 0;
	int message_index = 0;
	bool npc_exists = false;
	ofxCenteredTrueTypeFont message_;

public:
	void LoadNpc(const std::string &file_name);
	void DrawNpc();
	void DrawMessage();
	void DrawItems();
	void SetMessageIndex();
	int GetRandInt();
	int GetX();
	int GetY();
};

