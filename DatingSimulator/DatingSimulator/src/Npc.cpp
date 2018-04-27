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
	
}

int Npc::GetX()
{
	return pos_x;
}

int Npc::GetY()
{
	return pos_y;
}

