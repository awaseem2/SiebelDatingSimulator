#pragma once
#include "pugixml.hpp"
#include"ofMain.h"
class Item
{
	ofImage item_image_;
	int x_;
	int y_;
	bool item_exists_ = false;

public:
	void LoadItem(std::string file_name);
	void DrawItem();
};

