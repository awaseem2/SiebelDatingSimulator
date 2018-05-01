#include "npc.h"

void Npc::LoadNpc(const std::string & file_name)
{
	pugi::xml_document doc;
	doc.load_file(file_name.c_str());

	curr_room = doc.first_child();
	npc_ = curr_room.first_child();

	if (npc_.empty())
	{
		npc_exists = false;
		show_options = false;
	}
	else
	{
		npc_exists = true;
		show_options = true;

		greeting = npc_.child("Greeting").text().as_string();

		auto path = npc_.attribute("Path").value();
		npc_image_.load(path);

		pos_x_ = npc_.attribute("x").as_int();
		pos_y_ = npc_.attribute("y").as_int();
	}

	LoadText();
	LoadOptions();
}

void Npc::LoadText()
{
	greeting_ttf.loadFont("pacman_font.ttf", 40);
	option_1_ttf.loadFont("pacman_font.ttf", 38);
	option_2_ttf.loadFont("pacman_font.ttf", 38);
	outcome_ttf.loadFont("pacman_font.ttf", 40);
}

void Npc::LoadOptions()
{
	option_chosen = false;
	option_1_chosen = false;
	option_2_chosen = false;

	auto choices = npc_.first_child();
	option_1_ = choices.child("Option1");
	option_1_text = option_1_.attribute("text").as_string();
	outcome_1 = option_1_.child("Outcome").text().as_string();
	charisma_1 = option_1_.attribute("charisma").as_int();
	romance_1 = option_1_.attribute("romance").as_int();

	option_2_ = choices.child("Option2");
	option_2_text = option_2_.attribute("text").as_string();
	outcome_2 = option_2_.child("Outcome").text().as_string();
	charisma_2 = option_2_.attribute("charisma").as_int();
	romance_2 = option_2_.attribute("romance").as_int();

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

	if (show_options)
	{
		greeting_ttf.drawStringCentered(greeting, ofVec2f(greeting_x_, greeting_y_));

		DrawOptions();
	}
	else if (option_chosen)
	{
		int charisma_change = std::get<0>(GetStatsChange());
		int romance_change = std::get<1>(GetStatsChange());
		ofxCenteredTrueTypeFont result_ttf;
		result_ttf.loadFont("pacman_font.ttf", 35);

		if (option_1_chosen)
		{
			outcome_ttf.drawStringCentered(outcome_1, ofVec2f(greeting_x_, greeting_y_));
		}
		else if (option_2_chosen)
		{
			outcome_ttf.drawStringCentered(outcome_2, ofVec2f(greeting_x_, greeting_y_));
		}

		std::string result = std::to_string(charisma_change) + " charisma \n" + std::to_string(romance_change) + " romance";
		result_ttf.drawStringCentered(result, greeting_x_, ofGetWindowHeight() - (32 * 5));
	}

	//reset color to prevent entire screen from being filled
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
}

void Npc::DrawOptions()
{
	option_1_ttf.drawStringCentered(option_1_text, ofVec2f(greeting_x_, option_1_y_));
	option_2_ttf.drawStringCentered(option_2_text, ofVec2f(greeting_x_, option_2_y_));
}

void Npc::SetOptionChosen(bool boolean, int option)
{
	option_chosen = boolean;

	switch (option)
	{
	case 1:
		option_1_chosen = true;
		option_2_chosen = false;
		GetStatsChange();
		break;

	case 2:
		option_1_chosen = false;
		option_2_chosen = true;
		GetStatsChange();
		break;
	}
}

void Npc::SetShowOptions(bool boolean)
{
	show_options = boolean;
}

tuple<int, int> Npc::GetStatsChange()
{
	tuple<int, int> stat_increases;

	if (option_1_chosen)
	{
		stat_increases = std::make_tuple(charisma_1, romance_1);
	}
	else if (option_2_chosen)
	{
		stat_increases = std::make_tuple(charisma_2, romance_2);
	}
	
	return stat_increases;
}

int Npc::GetX()
{
	return pos_x_;
}

int Npc::GetY()
{
	return pos_y_;
}

ofRectangle Npc::GetOption1Rect()
{
	ofRectangle rect;
	rect.set(greeting_x_ - (options_width_ / 2), option_1_y_ - (options_height_ / 2), options_width_, options_height_);
	return rect;
}

ofRectangle Npc::GetOption2Rect()
{
	ofRectangle rect;
	rect.set(greeting_x_ - (options_width_ / 2), option_2_y_ - (options_height_ / 2), options_width_, options_height_);
	return rect;
}

bool Npc::OptionChosen()
{
	return option_chosen;
}


