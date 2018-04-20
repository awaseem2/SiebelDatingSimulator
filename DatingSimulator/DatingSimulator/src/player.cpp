#include "player.h"


void Player::LoadCharacter()
{
	character.load("../data/MainCharacter.png");
	character.draw(starting_pos_x, starting_pos_y);
}

void Player::DrawCharacter()
{
	character.draw(pos_x, pos_y);
}

void Player::UpdatePosition(int key)
{
	switch (key)
	{
		case OF_KEY_DOWN:
			pos_y += kTileSize;
			break;
		
		case OF_KEY_UP:
			pos_y -= kTileSize;
			break;

		case OF_KEY_RIGHT:
			pos_x += kTileSize;
			break;

		case OF_KEY_LEFT:
			pos_x -= kTileSize;
			break;
	}
	
}


