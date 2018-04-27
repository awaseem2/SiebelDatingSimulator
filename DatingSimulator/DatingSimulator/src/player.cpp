#include "player.h"


void Player::LoadCharacter()
{
	character.load("../data/MainCharacter.png");
}

void Player::DrawCharacter()
{
	character.draw(pos_x, pos_y);
}

void Player::UpdatePosition(Map map)
{
	std::tuple<int, int> new_coordinates = GetNewCoordinates(current_direction_);
	int new_x = std::get<0>(new_coordinates);
	int new_y = std::get<1>(new_coordinates);
	int x_modified = (new_x - 8);
	int x_coord = x_modified / 32;
	int y_coord = (new_y - 32) / 32;
	int tile_number = (15 * y_coord) + x_coord;
	Tile next_tile = map.GetTiles()[tile_number];

	if (next_tile.CanWalkThrough())
	{
		pos_x = new_x;
		pos_y = new_y;
	}

}

void Player::SetCurrentDirection(int direction)
{
	current_direction_ = static_cast<PlayerDirection>(direction);
}

int Player::GetX()
{
	return pos_x;
}

int Player::GetY()
{
	return pos_y;
}

std::tuple<int, int> Player::GetNewCoordinates(int key)
{
	int new_y = pos_y;
	int new_x = pos_x;

	switch (key)
	{
	case kDown:
		new_y = pos_y + kTileSize;
		break;

	case kUp:
		new_y = pos_y - kTileSize;
		break;

	case kRight:
		new_x = pos_x + kTileSize;
		break;

	case kLeft:
		new_x = pos_x - kTileSize;
		break;
	}

	return std::make_tuple(new_x, new_y);
}
