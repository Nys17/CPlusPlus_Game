#pragma once
#include "GameManager.h"
#include <cmath>

#include <SFML/Graphics.hpp>

/// <summary>
///  base class for the characters of the game (player & enemies)
/// </summary>
/// 
float constexpr Pi =  3.14159265358979323846f;
class Character
{
public:
	Character(GameManager& manager, const sf::Texture texture);

	virtual ~Character() {};

	void Destroy();

	void Update(float t);
	void Render(sf::RenderTexture& renderTex); 

	void SetPosition(const sf::Vector2f& pos) { position = pos; }
	const sf::Vector2f GetPosition() { return position; }

	void SetRotation(float angleInRad) { sprite.setRotation(angleInRad * (180/Pi)); }
	float const GetRotation() { return sprite.getRotation() * (Pi / 180); }

	void SetMaxHealth(float maxH) { maxHealth = maxH; }
	float GetMaxHealth() { return maxHealth; }

	void SetCurrentHealth(float health) { currentHealth = health; }
	float GetCurrentHealth() { return currentHealth; }

	void Kill() { currentHealth = 0.f; }

	bool IsDead() const { return currentHealth <= FLT_EPSILON; }

	GameManager& GetManager() const { return manager; }

	sf::Sprite& GetSprite() { return sprite; }
protected:
	//ovveride for custom event on character being destroyed
	virtual void OnDestroy() {};

	virtual void onUpdate(float t) {};

	virtual void onRender(sf::RenderTexture& renderTex) {};
	// responsible for character taking damage
	virtual void onApplyDamage(const Character* sourceOfDamage, float damage) {};

private:
	GameManager& manager;

	sf::Sprite sprite;
	sf::Image image;

	sf::Vector2f position = sf::Vector2f(0.0f, 0.0f);

	float maxHealth = 100.0f;
	float currentHealth = 100.0f;
};