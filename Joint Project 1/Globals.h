// Contains the game globals
#pragma once

//The direction the sprite is moving in
enum class Direction
{
	None,
	North,
	South,
	West,
	East,
	NorthWest,
	NorthEast,
	SouthWest,
	SouthEast
};


const float SCREEN_WIDTH = 1500;   // the size of the screen in pixels used in the game
const float SCREEN_HEIGHT = 800;