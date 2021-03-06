#include "npc.h"

void Npc::LoadNpc(const std::string & file_name)
{
	pugi::xml_document doc;
	doc.load_file(file_name.c_str());

	curr_room_ = doc.first_child();
	npc_ = curr_room_.first_child();

	if (npc_.empty())
	{
		npc_exists_ = false;
		show_options_ = false;
	}
	else
	{
		npc_exists_ = true;
		show_options_ = true;

		greeting_ = npc_.child("Greeting").text().as_string();

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
	greeting_ttf_.loadFont(GlobalConstants::kFontName, GlobalConstants::kBigTextSize);
	option_1_ttf_.loadFont(GlobalConstants::kFontName, GlobalConstants::kMediumTextSize);
	option_2_ttf_.loadFont(GlobalConstants::kFontName, GlobalConstants::kMediumTextSize);
	outcome_ttf_.loadFont(GlobalConstants::kFontName, GlobalConstants::kBigTextSize);
}

void Npc::LoadOptions()
{
	option_chosen_ = false;
	option_1_chosen_ = false;
	option_2_chosen_ = false;

	auto choices = npc_.first_child();
	option_1_ = choices.child("Option1");
	option_1_text_ = option_1_.attribute("text").as_string();
	outcome_1_ = option_1_.child("Outcome").text().as_string();
	charisma_1_ = option_1_.attribute("charisma").as_int();
	romance_1_ = option_1_.attribute("romance").as_int();

	option_2_ = choices.child("Option2");
	option_2_text_ = option_2_.attribute("text").as_string();
	outcome_2_ = option_2_.child("Outcome").text().as_string();
	charisma_2_ = option_2_.attribute("charisma").as_int();
	romance_2_ = option_2_.attribute("romance").as_int();

}

void Npc::DrawNpc()
{
	if (npc_exists_)
	{
		npc_image_.draw(pos_x_, pos_y_);
	}
}

void Npc::DrawMessage()
{	
	ofSetColor(255, 255, 255);

	if (show_options_)
	{
		greeting_ttf_.drawStringCentered(greeting_, ofVec2f(greeting_x_, greeting_y_));

		DrawOptions();
	}
	else if (option_chosen_)
	{
		int charisma_change = std::get<0>(GetStatsChange());
		int romance_change = std::get<1>(GetStatsChange());
		ofxCenteredTrueTypeFont result_ttf;
		result_ttf.loadFont(GlobalConstants::kFontName, GlobalConstants::kSmallTextSize);

		if (option_1_chosen_)
		{
			outcome_ttf_.drawStringCentered(outcome_1_, ofVec2f(greeting_x_, greeting_y_));
		}
		else if (option_2_chosen_)
		{
			outcome_ttf_.drawStringCentered(outcome_2_, ofVec2f(greeting_x_, greeting_y_));
		}

		std::string result = std::to_string(charisma_change) + " charisma \n" + std::to_string(romance_change) + " romance";
		result_ttf.drawStringCentered(result, greeting_x_, ofGetWindowHeight() - GlobalConstants::kResultLabelY);
	}

	//reset color to prevent entire screen from being filled
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
}

void Npc::DrawOptions()
{
	option_1_ttf_.drawStringCentered(option_1_text_, ofVec2f(greeting_x_, option_1_y_));
	option_2_ttf_.drawStringCentered(option_2_text_, ofVec2f(greeting_x_, option_2_y_));
}

void Npc::SetOptionChosen(bool boolean, int option)
{
	option_chosen_ = boolean;

	switch (option)
	{
	case 1:
		option_1_chosen_ = true;
		option_2_chosen_ = false;
		GetStatsChange();
		break;

	case 2:
		option_1_chosen_ = false;
		option_2_chosen_ = true;
		GetStatsChange();
		break;
	}
}

void Npc::SetShowOptions(bool boolean)
{
	show_options_ = boolean;
}

tuple<int, int> Npc::GetStatsChange()
{
	tuple<int, int> stat_increases;

	if (option_1_chosen_)
	{
		stat_increases = std::make_tuple(charisma_1_, romance_1_);
	}
	else if (option_2_chosen_)
	{
		stat_increases = std::make_tuple(charisma_2_, romance_2_);
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
	return option_chosen_;
}


