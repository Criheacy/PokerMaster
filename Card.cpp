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
	this->value->color = value.color;
	this->value->number = value.number;

	this->isFlipped = isFlipped;
	this->isSelected = isSelected;
	this->isActive = isActive;
}