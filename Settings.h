#pragma once
#include <string>

// how many pixels in game window
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const double GROUND_SCALE = 2;

// where is the map from
const std::string TEX_NUMBER_PATH = "Assets/numbers.png";
const std::string TEX_COLOR_PATH = "Assets/colors.png";
const std::string TEX_CARD_PATH = "Assets/card.png";
const std::string TEX_JOKER_PATH = "Assets/joker.png";

// These are how many pixels in a tile of raw texture
const int WALL_WIDTH = 8;
const int WALL_HEIGHT = 8;

const int PACMAN_WIDTH = 16;
const int PACMAN_HEIGHT = 16;

const int GHOST_WIDTH = 16;
const int GHOST_HEIGHT = 16;

const int FOOD_WIDTH = 16;
const int FOOD_HEIGHT = 16;

// Font
const int FONT_WIDTH = 8;
const int FONT_HEIGHT = 8;

const int NUMBER_FONT_WIDTH = 6;
const int NUMBER_FONT_HEIGHT = 8;

// How many tile are there in font map
const int FONT_TILE_WIDTH = 0x10;
const int FONT_TILE_HEIGHT = 0x08;

// Player
const double PLAYER_ANIMATION_SPEED = 20;
const double PLAYER_FADING_ANIMATION_SPEED = 12;
const Uint32 PLAYER_DELAY_AFTER_DEATH = 1000;

// Player controller
// Max error distance allow to turn after corner (optimize feeling)
const int PLAYER_AFTER_TURN_TOLERANCE = 150;

const int PLAYER_TURNING_TOLERANCE = 8000;

const double BUMP_CHECK_DISTANCE = 0.6;

const bool DRAW_GHOST_GIZMO = false;
//Ghost
const double GHOST_ANIMATION_SPEED = 20;

//Ghost color

const Uint8 SHADOW_COLOR[] = { 0xD7, 0x00, 0x00 };
const Uint8 SPEEDY_COLOR[] = { 0xFF, 0xD7, 0x00 };
const Uint8 BASHFUL_COLOR[] = { 0x00, 0xCD, 0xFF };
const Uint8 POKEY_COLOR[] = { 0xFF, 0xA5, 0xA5 };
