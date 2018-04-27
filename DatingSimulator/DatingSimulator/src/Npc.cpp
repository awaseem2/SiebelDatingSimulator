#include "npc.h"

void Npc::LoadNpc(const std::string & file_name)
{
	pugi::xml_document doc;
	doc.load_file(file_name.c_str());

	curr_room = doc.first_child();
	npc = curr_room.first_child();
	auto all_phrases = npc.children("Phrase");

	for (auto phrase : all_phrases)
	{
		phrases_.push_back(phrase.attribute("Message").value());
	}

	auto path = npc.attribute("Path").value();
	npc_image.load(path);
}

void Npc::DrawNpc()
{
	npc_image.draw(pos_x, pos_y);
}

void Npc::DrawMessage()
{	
	ofSetColor(ofColor::white);
	ofDrawRectangle(pos_x, pos_y + 32 * 5 + 8, 32 * 11, 32 * 2 + 8);
	
	string message = phrases_[message_number];
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(message, pos_x + 32, pos_y + 32 * 6 + 8);

	message_number++;
	if (message_number > phrases_.size())
	{
		message_number = 0;
	}

	//reset color to prevent entire screen from being filled
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
}

int Npc::GetX()
{
	return pos_x;
}

int Npc::GetY()
{
	return pos_y;
}

