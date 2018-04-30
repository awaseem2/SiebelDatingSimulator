#include "npc.h"

void Npc::LoadNpc(const std::string & file_name)
{
	pugi::xml_document doc;
	doc.load_file(file_name.c_str());

	curr_room = doc.first_child();

	npc = curr_room.first_child();

	if (npc.empty())
	{
		npc_exists = false;
	}
	else
	{
		npc_exists = true;

		greeting = npc.first_child().text().as_string();

		auto path = npc.attribute("Path").value();
		npc_image_.load(path);

		pos_x_ = npc.attribute("x").as_int();
		pos_y_ = npc.attribute("y").as_int();
	}
}

void Npc::DrawNpc()
{
	if (npc_exists)
	{
		npc_image_.draw(pos_x_, pos_y_);
	}
}

void Npc::DrawMessage()
{	
	ofSetColor(255, 255, 255);
	message_.loadFont("pacman_font.ttf", 40);
	message_.drawStringCentered(greeting, ofVec2f(greeting_x_, greeting_y_));

	//reset color to prevent entire screen from being filled
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
}

int Npc::GetX()
{
	return pos_x_;
}

int Npc::GetY()
{
	return pos_y_;
}

