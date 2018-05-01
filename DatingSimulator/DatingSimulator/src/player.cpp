#include "player.h"


void Player::LoadCharacter()
{
	character_.load("../data/MainCharacter.png");
}

void Player::DrawCharacter()
{
	character_.draw(pos_x_, pos_y_);
	UpdateStats();
}

void Player::UpdatePosition(Map map)
{
	std::tuple<int, int> new_coordinates = GetNewCoordinates(current_direction_);
	int new_x = std::get<0>(new_coordinates) - GlobalConstants::kOffset;
	int new_y = std::get<1>(new_coordinates) - GlobalConstants::kOffset;
	Tile next_tile = GetNextTile(map, new_x, new_y);

	if (next_tile.NextRoom())
	{
		move_to_next_room_ = true;
		pos_x_ = std::get<0>(map.GetNextRoomCoordinates());
		pos_y_ = std::get<1>(map.GetNextRoomCoordinates());
	}
	else if (next_tile.PreviousRoom())
	{
		move_to_previous_room_ = true;
		pos_x_ = std::get<0>(map.GetPreviousRoomCoordinates());
		pos_y_ = std::get<1>(map.GetPreviousRoomCoordinates());
	}
	else if (next_tile.CanWalkThrough())
	{
		pos_x_ = new_x + GlobalConstants::kOffset;
		pos_y_ = new_y + GlobalConstants::kOffset;
	}

	talk_to_npc_ = next_tile.HasNpc();
}

Tile Player::GetNextTile(Map map, int new_x, int new_y)
{
	int x_coord = new_x / GlobalConstants::kTileSize;
	int y_coord = (new_y - GlobalConstants::kTileSize) / GlobalConstants::kTileSize;
	int tile_number = (GlobalConstants::kNumOfRows * y_coord) + x_coord;
	Tile next_tile = map.GetTiles()[tile_number];

	return next_tile;
}

void Player::SetCurrentDirection(int direction)
{
	current_direction_ = static_cast<PlayerDirection>(direction);
}

void Player::UpdateStats()
{
	if (charisma_pts_ > 100)
	{
		charisma_pts_ = 100;
	}
	else if (charisma_pts_ < 0)
	{
		charisma_pts_ = 0;
	}

	if (romance_pts_ > 100)
	{
		romance_pts_ = 100;
	}
	else if (romance_pts_ < 0)
	{
		romance_pts_ = 0;
	}

	percent_charisma_ = (charisma_pts_ / 100.0) * GlobalConstants::kStatsBarsLength;
	percent_romance_ = (romance_pts_ / 100.0) * GlobalConstants::kStatsBarsLength;
}

std::tuple<int, int> Player::GetNewCoordinates(int key)
{
	int new_y = pos_y_;
	int new_x = pos_x_;

	switch (key)
	{
	case kDown:
		new_y = pos_y_ + 1;
		break;

	case kUp:
		new_y = pos_y_ - 1;
		break;

	case kRight:
		new_x = pos_x_ + 1;
		break;

	case kLeft:
		new_x = pos_x_ - 1;
		break;
	}

	return std::make_tuple(new_x, new_y);
}

void Player::SetStats(std::tuple<int, int> stats)
{
	charisma_pts_ += std::get<0>(stats);
	romance_pts_ += std::get<1>(stats);
}

bool Player::RoomVisited(std::string room)
{
	//check to see if room hasn't been visited
	if (std::find(rooms_visited.begin(), rooms_visited.end(), room) == rooms_visited.end())
	{
		rooms_visited.push_back(room);
		return false;
	}

	return true;
}

int Player::GetX()
{
	return pos_x_;
}

int Player::GetY()
{
	return pos_y_;
}

int Player::GetPercentCharisma()
{
	return percent_charisma_;
}

int Player::GetPercentRomance()
{
	return percent_romance_;
}

bool Player::MoveToNextRoom()
{
	return move_to_next_room_;
}

void Player::SetMoveToNextRoom(bool next)
{
	move_to_next_room_ = next;
}

bool Player::MoveToPreviousRoom()
{
	return move_to_previous_room_;
}

void Player::SetMoveToPreviousRoom(bool prev)
{
	move_to_previous_room_ = prev;
}

bool Player::TalkToNpc()
{
	return talk_to_npc_;
}

void Player::SetTalkToNpc(bool talk)
{
	talk_to_npc_ = talk;
}
