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

void EnemyTwo::moveEnemyTwo(Player& t_player)
{
	sf::Vector2f move{ 0.0f,0.0f };

	float chaseSpeed = 1.5f;

	if (t_player.getPosition().x > m_enemyTwoPosition.x)
	{
		move.x = 1;
	}
	if (t_player.getPosition().x < m_enemyTwoPosition.x)
	{
		move.x = -1;
	}
	if (t_player.getPosition().x == m_enemyTwoPosition.x)
	{
		m_canMove = false;
	}

	move *= chaseSpeed;
	m_enemyTwoPosition += move;
	m_enemy2Sprite.setPosition(m_enemyTwoPosition);

}
