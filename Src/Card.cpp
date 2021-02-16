#include "Card.h"

CardValue::CardValue(CardNumber number, CardColor color)
{
	this->color = color;
	this->number = number;
}

Card::Card(class CardValue value,
	bool isFlipped, bool isSelected, bool isActive) :
	Object {}
{
	this->value = new CardValue(value.number, value.color);

	this->isFlipped = isFlipped;
	this->isSelected = isSelected;
	this->isActive = isActive;
}

Card::~Card()
{
	this->value = NULL;
}