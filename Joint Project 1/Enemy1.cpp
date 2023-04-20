#include <iostream>
#include "Enemy1.h"
#include "Player.h" 

sf::Sprite EnemyOne::getFirstEnemySprite()
{


	return m_enemy1Sprite;
}

void EnemyOne::setupEnemyOneSprite()
{

	if (!m_enemy1Texture.loadFromFile("ASSETS\\IMAGES\\enemy1.png"))
	{
		std::cout << "Error Loading Enemy One" << std::endl;
	}

	m_enemy1Sprite.setTexture(m_enemy1Texture);
	m_enemy1Sprite.setOrigin(32, 32);
	m_enemy1Sprite.setPosition(m_enemyOnePosition);
	m_enemy1Sprite.setScale(2.0f, 2.0f);
	m_enemy1Sprite.setTextureRect(sf::IntRect(0, 0, 75, 75));
}

void EnemyOne::moveEnemyOne(Player& t_player)
{
	sf::Vector2f move{ 0.0f,0.0f };

	float chaseSpeed = 0.75f;

	if (t_player.getPosition().x > m_enemy1Sprite.getPosition().x)
	{
		move.x = 1;

		m_enemy1Sprite.setTextureRect(sf::IntRect(0, 150, 75, 75));

	}
	if (t_player.getPosition().x < m_enemy1Sprite.getPosition().x)
	{
		move.x = -1;

		m_enemy1Sprite.setTextureRect(sf::IntRect(0, 75, 75, 75));

	}
	if (t_player.getPosition().y < m_enemy1Sprite.getPosition().y)
	{
		move.y = -1;

	}
	if (t_player.getPosition().y > m_enemy1Sprite.getPosition().y)
	{
		move.y = 1;

		m_enemy1Sprite.setTextureRect(sf::IntRect(0, 0, 75, 75));

	}
	

	move *= chaseSpeed;
	m_enemyOnePosition += move;
	m_enemy1Sprite.setPosition(m_enemyOnePosition);

}


