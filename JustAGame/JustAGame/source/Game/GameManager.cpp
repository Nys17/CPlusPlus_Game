#include "GameManager.h"
#include "Player.h"
#include <SFML/Graphics.hpp> 


bool GameManager::Load()
{
	bool success = true;

	/// load assets

	success &= assets.playerTex.loadFromFile("./Assets/WanderMageSpriteSheet.png");

	player = SpawnCharacter<Player>();

	

	return success;
}

void GameManager::Render()
{

	
	/*for (Character* character: characters)
	{
		if (character!= nullptr&& !character->IsDead())
		{
			character->Render();
		}
	}*/

}

void GameManager::Update(float t)
{
}

void GameManager::ShutDown()
{
}
