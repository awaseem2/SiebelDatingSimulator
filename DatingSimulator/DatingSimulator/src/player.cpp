#include "player.h"


void Player::LoadCharacter()
{
	character.load("../data/MainCharacter.png");
	charisma_.loadFont("pacman_font.ttf", 35);
	romance_.loadFont("pacman_font.ttf", 35);
}

void Player::DrawCharacter()
{
	character.draw(pos_x, pos_y);
	DrawInfoBars();
}

void Player::DrawInfoBars()
{
	ofSetColor(255, 255, 255);
	charisma_.drawStringCentered("Charisma", ofVec2f(ofGetWindowWidth() - 32 * 7 - 16, ofGetWindowHeight() - 32 * 3 - 16));
	romance_.drawStringCentered("Romance", ofVec2f(ofGetWindowWidth() - 32 * 7 - 16, ofGetWindowHeight() - 32 * 2));

	int charisma_bar_length = 32 * 8;
	ofDrawRectangle(ofGetWindowWidth() - (32 * 9), ofGetWindowHeight() - (32 * 3), 32 * 8, 16);
	ofDrawRectangle(ofGetWindowWidth() - (32 * 9), ofGetWindowHeight() - (32 * 2) + 16, 32 * 8, 16);

	if (charisma_pts > 100)
	{
		charisma_pts = 100;
	}
	else if(charisma_pts < 0)
	{
	charisma_pts = 0;
	}

	if (romance_pts > 100)
	{
		romance_pts = 100;
	}
	else if (romance_pts < 0)
	{
		romance_pts = 0;
	}

	ofSetColor(255, 0, 0);
	int percent_charisma = (charisma_pts / 100.0) * charisma_bar_length;
	int percent_romance = (romance_pts / 100.0) * charisma_bar_length;
	ofDrawRectangle(ofGetWindowWidth() - (32 * 9), ofGetWindowHeight() - (32 * 3), percent_charisma, 16);
	ofDrawRectangle(ofGetWindowWidth() - (32 * 9), ofGetWindowHeight() - (32 * 2) + 16, percent_romance, 16);

	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
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

	if (next_tile.NextRoom())
	{
		move_to_next_room = true;
		pos_x = std::get<0>(map.GetNextRoomCoordinates());
		pos_y = std::get<1>(map.GetNextRoomCoordinates());
	}
	else if (next_tile.PreviousRoom())
	{
		move_to_previous_room = true;
		pos_x = std::get<0>(map.GetPreviousRoomCoordinates());
		pos_y = std::get<1>(map.GetPreviousRoomCoordinates());
	}
	else if (next_tile.CanWalkThrough())
	{
		pos_x = new_x - offset;
		pos_y = new_y - offset;
	}

	talk_to_npc = next_tile.HasNpc();
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
		new_y = pos_y + 1;
		break;

	case kUp:
		new_y = pos_y - 1;
		break;

	case kRight:
		new_x = pos_x + 1;
		break;

	case kLeft:
		new_x = pos_x - 1;
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

bool Player::MoveToNextRoom()
{
	return move_to_next_room;
}

void Player::SetMoveToNextRoom(bool next)
{
	move_to_next_room = next;
}

bool Player::MoveToPreviousRoom()
{
	return move_to_previous_room;
}

void Player::SetMoveToPreviousRoom(bool prev)
{
	move_to_previous_room = prev;
}

bool Player::TalkToNpc()
{
	return talk_to_npc;
}

void Player::SetTalkToNpc(bool talk)
{
	talk_to_npc = talk;
}

void Player::SetStats(std::tuple<int, int> stats)
{
	charisma_pts += std::get<0>(stats);
	romance_pts += std::get<1>(stats);
}
