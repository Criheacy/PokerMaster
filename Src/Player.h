#pragma once
#include "Object.h"
#include <vector>

class Player : public Object
{
public:
	Player();
	~Player();
//	void SetPlayerState(class Player* left, class Player* opposite, class Player* right);

private:
	std::vector<class Card*> hand;

	Player* mLeft;
	Player* mRight;
	Player* mOpposite;
};