#pragma once
#include "Object.h"

enum CardNumber
{
	None = 0,
	A = 1,
	N2 = 2,
	N3 = 3,
	N4 = 4,
	N5 = 5,
	N6 = 6,
	N7 = 7,
	N8 = 8,
	N9 = 9,
	N10 = 10,
	J = 11,
	Q = 12,
	K = 13,
	MINORJOKER = 14,
	MAJORJOKER = 15,
};

enum CardColor
{
	None = 0,
	Heart = 1,
	Diamond = 2,
	Spade = 3,
	Club = 4,
};

class CardValue
{
public:
	CardValue(CardNumber number, CardColor color);

	CardNumber number;
	CardColor color;
};

class Card : public Object
{
public:
	Card(class Transform* transform, class CardValue value,
		bool isFlipped = false, bool isSelected = false, bool isActive = true);
	~Card();

	CardValue* value;

	bool isFlipped;
	bool isSelected;
	bool isActive;
};