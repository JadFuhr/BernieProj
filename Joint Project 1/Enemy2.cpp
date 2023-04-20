#include <iostream>
#include "Enemy2.h"
#include "Player.h"

sf::Sprite EnemyTwo::getSecondEnemySprite()
{
	return m_enemy2Sprite;
}

void EnemyTwo::setupEnemyTwoSprite()
{

	if (!m_enemy2Texture.loadFromFile("ASSETS\\IMAGES\\enemy2_down.png"))
	{
		std::cout << "Error Loading Enemy Two" << std::endl;
	}

	m_enemy2Sprite.setTexture(m_enemy2Texture);
	m_enemy2Sprite.setOrigin(32, 32);
	m_enemy2Sprite.setPosition(m_enemyTwoPosition);
	m_enemy2Sprite.setScale(1.75f, 1.75f);

}

void EnemyTwo::moveEnemyTwo()
{
	


}
