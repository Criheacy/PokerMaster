#pragma once
#include <vector>

class Player
{
public:
	Player();
	~Player();

private:
	std::vector<class Card*> hand;
	
};