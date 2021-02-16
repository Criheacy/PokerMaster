#pragma once
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "Card.h"
#include "Player.h"

enum GameState
{
	SHUFFLE = 1,
	DRAWCARD = 2,
	DEDUCTCARD = 3,
	GAMELOOP = 4,
	CHECKMARK = 5,
};

class Game
{
public:
	Game();
	~Game();

	void ShuffleCard();
	Card* DrawCard();

	class Player* East;
	class Player* West;
	class Player* North;
	class Player* South;

	class SubGame* subGame;

	std::vector<class Card*> cardSet;

private:
	void InitializeCards();
};