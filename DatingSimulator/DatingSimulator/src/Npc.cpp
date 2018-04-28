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
	npc_image_.load(path);

	pos_x_ = npc.attribute("x").as_int();
	pos_y_ = npc.attribute("y").as_int();
}

void Npc::DrawNpc()
{
	npc_image_.draw(pos_x_, pos_y_);
}

void Npc::DrawMessage()
{	
	ofSetColor(ofColor::white);
	ofDrawRectangle(pos_x_, pos_y_ + 32 * 5 + 8, 32 * 11, 32 * 2 + 8);
	
	ofSetColor(255, 255, 255);
	message_.loadFont("pacman_font.ttf", 32);
	message_.drawCenteredBoundingBox(phrases_[message_index], pos_x_, pos_y_ + 32 * 6 + 8, 10);

	/*string message = phrases_[message_index];
	ofDrawBitmapString(message, pos_x_ + 32, pos_y_ + 32 * 6 + 8);*/

	//reset color to prevent entire screen from being filled
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
}

void Npc::SetMessageIndex()
{
	message_index = GetRandInt();
}

int Npc::GetRandInt()
{
	int min = 0;
	int max = phrases_.size() - 1;
	int random = min + (rand() % static_cast<int>(max - min + 1));
	return random;
}

int Npc::GetX()
{
	return pos_x_;
}

int Npc::GetY()
{
	return pos_y_;
}

