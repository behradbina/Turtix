#pragma once
using namespace std;

constexpr unsigned short SCREEN_HEIGHT = 800;
constexpr unsigned short SCREEN_WIDTH = 1600;
constexpr unsigned short PAUSE_SCREEN_HEIGHT = 800;
constexpr unsigned short PAUSE_SCREEN_WIDTH = 1600;
constexpr unsigned char SHIELD_PERIOD_TIME = 3;
constexpr unsigned char CELL_SIZE = 175;
constexpr float TURTLE_WALK_SPEED = 20;
constexpr float ENEMY_WALK_SPEED = 5;
constexpr float BABY_TURTLE_WALK_SPEED = 5;
constexpr float GRAVITY = 0.25f;
constexpr float TURTlE_JUMP_SPEED = -CELL_SIZE - CELL_SIZE/2;
constexpr unsigned char MARIO_JUMP_TIMER = 8;
const int DAIMOND_SCORE = 1000;
const int STAR_SCORE = 500;
constexpr unsigned char NUMBER_OF_ENEMY_LIVE = 2;
constexpr unsigned char NUMBER_OF_TURTLE_LIVE = 11;

enum Cell
{
	Portal,
	Daimond,
	Star,
	Empty,
	Wall,
	Rope,
	Ladder,
	Blade
};

enum Collision_dierction
{
	Up,
	Down,
	Right,
	Left
};
