#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include "Globals.h"   
#include "Player.h"

class EnemyOne
{
	
private:



public:

	sf::Sprite getFirstEnemySprite();
	void setupEnemyOneSprite();
	void moveEnemyOne(Player& t_player);

	sf::Sprite m_enemy1Sprite;
	sf::Texture m_enemy1Texture;

	sf::Vector2f m_enemyOnePosition{ 100,100 };
	Direction m_enemyOneFacing{ Direction::South };

	sf::Sprite getSprite();

};