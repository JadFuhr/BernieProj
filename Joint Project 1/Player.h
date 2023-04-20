// Player class declaration
#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"

class Player
{
	// private data members


public:

	void setupSprite();
	void movePlayer();
	sf::Sprite getSprite();
	void getDirection();
	void update();
	sf::Vector2f getPosition();

	sf::Sprite m_characterSprite;
	sf::Texture m_characterTexture;

	Direction m_facing{ Direction::South };
	sf::Vector2f m_playerPosition{ 750,400 };

private:

	

};