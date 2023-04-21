#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include "Globals.h"   
#include "Player.h"


class Player;

class EnemyOne
{
	
private:



public:

	sf::Sprite getBody();
	void setupEnemyOneSprite();
	void moveEnemyOne(Player& t_player);
	void update(Player& t_player);

	sf::Sprite m_enemyOneSprite;
	sf::Texture m_enemyOneTexture;

	Direction m_enemyOneFacing{ Direction::South };

	sf::Vector2f m_enemyOnePosition;

	sf::Vector2f m_spawnLocations[3] = { sf::Vector2f{100,100},sf::Vector2f{1000,300},sf::Vector2f{300,500} };

	int m_spawnTimer;

	float m_speed[3] = { 0.50f,1.0f,2.0f };

	bool m_isAlive;

};