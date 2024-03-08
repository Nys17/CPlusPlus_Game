#pragma once

#include <SFML/Graphics.hpp> 

class Character;
	class Player;


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

	
	const Assets& GetAssets() const { return assets; }

	
	template<typename T>
	T* SpawnCharacter();

private:
	Assets assets;

	Player* player = nullptr;

	std::vector<Character*> characters;
	std::vector<Character*> charactersToAdd; 
};

template <typename T>
T* GameManager::SpawnCharacter() {
	if (T* newCharacter = new T(*this))
	{
		charactersToAdd.push_back(newCharacter);
		return newCharacter;
	}
	return nullptr;
}

