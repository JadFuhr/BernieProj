#include <iostream>
#include "Enemy1.h"
#include "Player.h" 

sf::Sprite EnemyOne::getBody()
{


	return m_enemy1Sprite;
}

void EnemyOne::setupEnemyOneSprite()
{



	m_enemy1Sprite.setTexture(s_enemy1Texture);
	m_enemy1Sprite.setOrigin(32, 32);
	m_spawnTimer = (rand() % 200) + 100;
	m_enemyOnePosition.x = (rand() % 400) + 100;
	m_enemyOnePosition.y = (rand() % 100) + 50;
	m_enemy1Sprite.setPosition(m_enemyOnePosition);
	m_enemy1Sprite.setScale(2.0f, 2.0f);
	m_enemy1Sprite.setTextureRect(sf::IntRect(0, 0, 75, 75));
	m_speed = ((rand() % 10) + 10)/8.0f;
}

void EnemyOne::move(Player& t_player)
{
	sf::Vector2f move{ 0.0f,0.0f };

	float chaseSpeed = 0.75f;

	if (t_player.getPosition().x > m_enemy1Sprite.getPosition().x + 5)
	{
		move.x = m_speed;

		m_enemy1Sprite.setTextureRect(sf::IntRect(0, 150, 75, 75));

	}
	if (t_player.getPosition().x < m_enemy1Sprite.getPosition().x - 5)
	{
		move.x = -m_speed;

		m_enemy1Sprite.setTextureRect(sf::IntRect(0, 75, 75, 75));

	}
	if (t_player.getPosition().y < m_enemy1Sprite.getPosition().y - 5)
	{
		move.y = -m_speed/2.0f;

		m_enemy1Sprite.setTextureRect(sf::IntRect(0, 225, 75, 75));

	}
	if (t_player.getPosition().y > m_enemy1Sprite.getPosition().y + 5)
	{
		move.y = m_speed/2.0f;

		m_enemy1Sprite.setTextureRect(sf::IntRect(0, 0, 75, 75));

	}
	

	move *= chaseSpeed;
	m_enemyOnePosition += move;
	m_enemy1Sprite.setPosition(m_enemyOnePosition);

}

void EnemyOne::spawn()
{



}

void EnemyOne::update(Player& t_player)
{

	if (m_alive)
	{
		move(t_player);
	}
	else
	{
		m_spawnTimer--;
		if (m_spawnTimer < 0)
		{
			m_alive = true;
			m_enemyOnePosition = m_spawnPoints[rand() % 3];
			m_enemy1Sprite.setPosition(m_enemyOnePosition);
		}
	}
}


