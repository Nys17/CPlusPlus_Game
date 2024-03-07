#pragma once

#include <SFML/Graphics.hpp> 
class GameManager
{
public:

	static constexpr float playableArea = 5000.f; /// size of the arena

	struct  Assets
	{
		sf::Texture playerTex;

		sf::Texture magicAttackTex;
		sf::Texture enemyMagicAttackTex;

		sf::Texture enemyMeleeTex;
		sf::Texture enemyRangedTex;

	
	};




	bool Load();

	void Render();

	void Update(float t);

	void ShutDown();
	
	template<typename T>
	T* SpawnCharacter();

private:
	Assets assets;
};

template <typename T>
T* GameManager::SpawnCharacter() {
	if (T* newCharacter = new T(*this))
	{
		
	}
}

