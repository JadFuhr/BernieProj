
#include <iostream>
#include "Player.h"   // include Player header file

// Player function definitions here


void Player::update()
{
	movePlayer();
	getDirection();
	collision();
}

sf::Vector2f Player::getPosition()
{
	return m_playerPosition;
}

void Player::setupSprite()
{

	if (!m_characterTexture.loadFromFile("ASSETS\\IMAGES\\player.png"))
	{
		std::cout << "Error loading player" << std::endl;
	}

	m_characterSprite.setTexture(m_characterTexture);
	m_characterSprite.setOrigin(32, 32);
	m_characterSprite.setPosition(m_playerPosition);
	m_characterSprite.setScale(1.5f, 1.5f);
	m_characterSprite.setTextureRect(sf::IntRect(0, 0, 80, 80));

}

void Player::movePlayer()
{

	sf::Vector2f move{ 0.0f,0.0f };

	float moveSpeed = 3.2f;

	if (canMove = true)
	{
		switch (m_facing)
		{
		case Direction::None:
			break;
		case Direction::North:
			move.y = -1.0f;
			break;
		case Direction::West:
			move.x = -1.0f;
			break;
		case Direction::South:
			move.y = 1.0f;
			break;
		case Direction::East:
			move.x = 1.0f;
			break;
		case Direction::NorthWest:
			move.x = -0.8f;
			move.y = -0.8f;
			break;
		case Direction::NorthEast:
			move.x = 0.8f;
			move.y = -0.8f;
			break;
		case Direction::SouthWest:
			move.x = -0.8f;
			move.y = 0.8f;
			break;
		case Direction::SouthEast:
			move.x = 0.8f;
			move.y = 0.8f;
			break;
		default:
			break;
		}
	}
	

	move *= moveSpeed;

	m_playerPosition += move;
	m_characterSprite.setPosition(m_playerPosition);

}

void Player::collision()
{


	if (m_playerPosition.x < SCREEN_LEFT_BORDER)
	{
		canMove = false;

		m_playerPosition.x = SCREEN_LEFT_BORDER;
	}
	if (m_playerPosition.x > SCREEN_RIGHT_BORDER)
	{
		canMove = false;

		m_playerPosition.x = SCREEN_RIGHT_BORDER;
	}
	if (m_playerPosition.y < SCREEN_TOP_BORDER)
	{
		canMove = false;

		m_playerPosition.y = SCREEN_TOP_BORDER;
	}
	if (m_playerPosition.y > SCREEN_BOTTOM_BORDER)
	{
		canMove = false;

		m_playerPosition.y = SCREEN_BOTTOM_BORDER;
	}
}

sf::Sprite Player::getSprite()
{

	return m_characterSprite;
}

void Player::getDirection()
{

	m_facing = Direction::None;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_facing = Direction::North;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_facing = Direction::NorthWest;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_facing = Direction::NorthEast;
		}

		m_characterSprite.setTextureRect(sf::IntRect(0,250,80,80));

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_facing = Direction::West;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_facing = Direction::SouthWest;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_facing = Direction::NorthWest;
		}

		m_characterSprite.setTextureRect(sf::IntRect(0, 80, 80, 80));

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_facing = Direction::East;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_facing = Direction::NorthEast;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_facing = Direction::SouthEast;
		}

		m_characterSprite.setTextureRect(sf::IntRect(0, 160, 80, 80));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_facing = Direction::South;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_facing = Direction::SouthEast;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_facing = Direction::SouthWest;
		}

		m_characterSprite.setTextureRect(sf::IntRect(0,0,80,80));

	}

}

void Player::playerGetDamaged()
{


	
}
