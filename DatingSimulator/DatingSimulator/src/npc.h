#pragma once
#include "ofMain.h"
#include "pugixml.hpp"
#include <string>
#include <vector>

using std::vector;

class Npc
{

private:
	vector<std::string> phrases_; 
	pugi::xml_node curr_room;
	pugi::xml_node npc;
	ofImage npc_image;
	int pos_x = 64 + 8;
	int pos_y = 192;

public:
	void LoadNpc(const std::string &file_name);
	void DrawNpc();
	void DrawMessage();
	int GetX();
	int GetY();
};

