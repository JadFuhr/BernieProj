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

const float SCREEN_TOP_BORDER = 20;
const float SCREEN_LEFT_BORDER = 20;
const float SCREEN_BOTTOM_BORDER = 740;
const float SCREEN_RIGHT_BORDER = 1455;

const int MAX_DRAGON_ENEMY = 3;
const int MAX_RUNNING_ENEMY = 1;
