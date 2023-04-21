#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Enemy1.h"
#include "Player.h" 

void EnemyOne::update(Player& t_player)
{

	if (m_isAlive)
	{
		moveEnemyOne(t_player);
	}
	else
	{

		m_spawnTimer--;

		if (m_spawnTimer < 0)
		{
			m_isAlive = true;
			m_enemyOnePosition = m_spawnLocations[rand() % 3];
			m_enemyOneSprite.setPosition(m_enemyOnePosition);
		}
	}
		
	
	


}


sf::Sprite EnemyOne::getBody()
{


	return m_enemyOneSprite;
}

void EnemyOne::setupEnemyOneSprite()
{

	srand(time(nullptr));

	if (!m_enemyOneTexture.loadFromFile("ASSETS\\IMAGES\\enemy1.png"))
	{
		std::cout << "Error Loading Enemy One" << std::endl;
	}
	m_enemyOneSprite.setTexture(m_enemyOneTexture);
	m_enemyOneSprite.setOrigin(32, 32);

	m_enemyOnePosition = m_spawnLocations[rand() % 3];
	m_enemyOneSprite.setPosition(m_enemyOnePosition);



	m_enemyOneSprite.setScale(2.0f, 2.0f);
	m_enemyOneSprite.setTextureRect(sf::IntRect(0, 0, 75, 75));
}

void EnemyOne::moveEnemyOne(Player& t_player)
{
	sf::Vector2f move{ 0.0f,0.0f };

	float m_chaseSpeed = m_speed[rand()%3];

	if (t_player.getPosition().x > m_enemyOneSprite.getPosition().x + 5)
	{
		move.x = 1;

		m_enemyOneSprite.setTextureRect(sf::IntRect(0, 150, 75, 75));

	}
	if (t_player.getPosition().x < m_enemyOneSprite.getPosition().x - 5)
	{
		move.x = -1;

		m_enemyOneSprite.setTextureRect(sf::IntRect(0, 75, 75, 75));

	}
	if (t_player.getPosition().y < m_enemyOneSprite.getPosition().y-5)
	{
		move.y = -1;

		m_enemyOneSprite.setTextureRect(sf::IntRect(0, 225, 75, 75));

	}
	if (t_player.getPosition().y > m_enemyOneSprite.getPosition().y+5)
	{
		move.y = 1;

		m_enemyOneSprite.setTextureRect(sf::IntRect(0, 0, 75, 75));

	}
	

	move *= m_chaseSpeed;
	m_enemyOnePosition += move;
	m_enemyOneSprite.setPosition(m_enemyOnePosition);

}


