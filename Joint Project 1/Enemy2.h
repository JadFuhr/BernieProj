#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include "Globals.h"   
#include "Player.h"

class EnemyTwo
{

private:



public:

	sf::Sprite getSecondEnemySprite();
	void setupEnemyTwoSprite();
	void moveEnemyTwo(Player& t_player);

	sf::Sprite m_enemy2Sprite;
	sf::Texture m_enemy2Texture;

	sf::Vector2f m_enemyTwoPosition{ 1400,100 };
	Direction m_enemeyTwoFacing{ Direction::South };

	bool m_isAlive;

	bool m_canMove;

};