#include "player.h"


void Player::LoadCharacter()
{
	character.load("../data/MainCharacter.png");
	player_rect.setX(pos_x);
	player_rect.setY(pos_y);
	player_rect.setSize(32, 32);
	curr_room_name = "Outside Siebel";
}

void Player::DrawCharacter()
{
	character.draw(pos_x, pos_y);
}

void Player::UpdatePosition(Map map)
{
	std::tuple<int, int> new_coordinates = GetNewCoordinates(current_direction_);
	int new_x = std::get<0>(new_coordinates) + offset;
	int new_y = std::get<1>(new_coordinates) + offset;
	int x_coord = new_x / 32;
	int y_coord = (new_y - 32) / 32;
	int tile_number = (15 * y_coord) + x_coord;
	Tile next_tile = map.GetTiles()[tile_number];
	ofRectangle next_tile_rect = next_tile.GetRectangle();

	if (next_tile.CanWalkThrough())
	{
		pos_x = new_x - offset;
		pos_y = new_y - offset;

		player_rect.setX(pos_x);
		player_rect.setY(pos_y);

		if (next_tile.NextRoom())
		{
			move_to_next_room = true;
			pos_x = 12 * 32 + 8;
			pos_y = 12 * 32;
		}
	}
}

void Player::SetCurrentDirection(int direction)
{
	current_direction_ = static_cast<PlayerDirection>(direction);
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

int Player::GetX()
{
	return pos_x;
}

int Player::GetY()
{
	return pos_y;
}

void Player::SetCurrentRoomName()
{
}

string Player::GetCurrentRoomName()
{
	return curr_room_name;
}

bool Player::MoveToNextRoom()
{
	return move_to_next_room;
}

void Player::SetMoveToNextRoom(bool next)
{
	move_to_next_room = next;
}
