#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include "Globals.h"   
#include "Player.h"

class EnemyOne
{
	
private:

	sf::Sprite m_enemy1Sprite;


public:
	static sf::Texture s_enemy1Texture;

	sf::Sprite getBody();
	void setupEnemyOneSprite();
	void update(Player& t_player);
	void spawn();
	void move(Player& t_player);

	float m_speed;

	sf::Vector2f m_enemyOnePosition{ 100,100 };
	Direction m_enemyOneFacing{ Direction::South };

	bool m_alive = false;

	int m_spawnTimer;

	sf::Vector2f m_spawnPoints[3] = { sf::Vector2f{10.0f,130.0f}, sf::Vector2f{510.0f,410.0f} ,sf::Vector2f{210.0f,510.0f} };

	sf::Sprite getSprite();

};