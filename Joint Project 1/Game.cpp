// Name: 
// Login: 
// Date: 
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description: TEMPLATE
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib")


#include "Enemy1.h"
#include "Enemy2.h"
#include "Player.h"
#include "Game.h"   // include Game header file


int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}


sf::Texture EnemyOne::s_enemy1Texture;

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
	// int x = sf::Texture::getMaximumSize(); // check max texture size
	setupSprite();
	m_player.setupSprite();
	if (!EnemyOne::s_enemy1Texture.loadFromFile("ASSETS\\IMAGES\\enemy1.png"))
	{
		std::cout << "Error Loading Enemy One" << std::endl;
	}
	for (int i = 0; i < MAX_PTERADACTYL; i++)
	{
		m_flock[i].setupEnemyOneSprite();
	}
	m_enemyTwo.setupEnemyTwoSprite();

}

void Game::loadContent()
// Load the font file & setup the message string
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen

}


void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand((int)time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	
	m_player.update();
	for (int i = 0; i < MAX_PTERADACTYL; i++)
	{
		m_flock[i].update(m_player);
	}
	
	// update any game variables here ...

}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	m_message.setString("Game Play");
	window.draw(m_message);  // write message to the screen
	window.draw(m_backgroundSprite);
	window.draw(m_player.getSprite());
	for (int i = 0; i < MAX_PTERADACTYL; i++)
	{
		if (m_flock[i].m_alive)
		{
			window.draw(m_flock[i].getBody());
			
		}
	}
	
	window.draw(m_enemyTwo.getSecondEnemySprite());

	window.display();
}

void Game::setupSprite()
{

	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\floor.png"))
	{
		std::cout << "Error" << std::endl;
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setOrigin(400, 300);
	m_backgroundSprite.setPosition(750, 400);
	m_backgroundSprite.setScale(2.0f, 2.0f);

}

void Game::spawn()
{
}




