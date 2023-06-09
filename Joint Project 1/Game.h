// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file


class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	sf::RenderWindow window;

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();
	void setupSprite();
	void spawn();
	

	Player m_player;
	//EnemyOne m_enemyOne;
	EnemyTwo m_enemyTwo;

	EnemyOne m_flock[MAX_PTERADACTYL];


	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;

};
