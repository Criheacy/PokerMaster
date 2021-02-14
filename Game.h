#pragma once
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "Card.h"
#include "Player.h"

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

	CardColor* majorColor;
	CardNumber* majorNumber;

private:
	int drawCounter;
	std::vector<class Card> cardSet;
};