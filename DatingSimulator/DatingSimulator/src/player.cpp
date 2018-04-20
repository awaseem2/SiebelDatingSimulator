#include "player.h"


void Player::LoadCharacter()
{
	character.load("../data/MainCharacter.png");
}

void Player::DrawCharacter()
{
	character.draw(pos_x, pos_y);
}

void Player::UpdatePosition(int key, Map map)
{
	Tile curr_tile = map.GetTiles()[((pos_x - 8) % 32) * (pos_y % 32)];
	switch (key)
	{
	case OF_KEY_DOWN:
		//if (curr_tile.CanWalkThrough())
		//{
			pos_y += kTileSize;
		//}
		break;

	case OF_KEY_UP:
		//if (curr_tile.CanWalkThrough())
		//{
			pos_y -= kTileSize;
		//}
		break;

	case OF_KEY_RIGHT:
		//if (curr_tile.CanWalkThrough())
		//{
			pos_x += kTileSize;
		//}
		break;

	case OF_KEY_LEFT:
		//if (curr_tile.CanWalkThrough())
		//{
			pos_x -= kTileSize;
		//}
		break;
	}

}

int Player::GetX()
{
	return pos_x;
}

int Player::GetY()
{
	return pos_y;
}

//void Player::SetCurrentTile(Tile tile)
//{
//	current_tile = tile;
//}