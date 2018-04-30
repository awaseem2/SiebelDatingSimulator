#include "item.h"

void Item::LoadItem(std::string file_name)
{
	pugi::xml_document doc;
	doc.load_file(file_name.c_str());

	auto curr_room = doc.first_child();

	auto item = curr_room.child("Item");

	if (item.empty())
	{
		item_exists = false;
	}
	else
	{
		item_exists = true;
		auto path = item.attribute("Path").value();
		item_image_.load(path);

		x_ = item.attribute("x").as_int();
		y_ = item.attribute("y").as_int();
	}
}

void Item::DrawItem()
{
	if (item_exists)
	{
		item_image_.draw(x_, y_);
	}
}
