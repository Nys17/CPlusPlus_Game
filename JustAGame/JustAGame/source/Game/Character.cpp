#include "Character.h"
#include <cmath>

Character::Character(GameManager& manager, const sf::Texture texture) : manager(manager), sprite (texture)
{
	sprite.setOrigin(sf::Vector2f(texture.getSize()) * 0.5f);
	image = sprite.getTexture()->copyToImage();
}

void Character::Destroy()
{
	// add death animation if sprites are avaliable
	// PlayDeathAnimation();
	OnDestroy();
}

void Character::Update(float t)
{

	onUpdate(t);
}

void Character::Render(sf::RenderTexture& renderTex)
{

}

void Character::ApplyDamage(const Character* source, float damage)
{
	onApplyDamage(source, damage);

	currentHealth -= damage;
	currentHealth = std::min(maxHealth, std::max(currentHealth, 0.0f)); /// clamp	health
}
