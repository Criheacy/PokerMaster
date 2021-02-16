#include "Game.h"

Game::Game()
{
	InitializeCards();
}

void Game::InitializeCards()
{
	for (auto it = cardSet.begin(); it != cardSet.end(); it++)
	{
		delete* it;
	}
	cardSet.clear();

	Card* newCard = NULL;
	for (int number = 1; number <= 13; number++)
	{
		for (int color = 1; color <= 4; color++)
		{
			newCard = new Card(CardValue((CardNumber)number, (CardColor)color));
			newCard->transform->MoveTo(number * 30, color * 100);
			cardSet.push_back(newCard);
		}
	}
	newCard = new Card(CardValue(CardNumber::MAJORJOKER, CardColor::None));
	newCard->transform->MoveTo(500, 500);
	cardSet.push_back(newCard);
	newCard = new Card(CardValue(CardNumber::MINORJOKER, CardColor::None));
	newCard->transform->MoveTo(600, 500);
	cardSet.push_back(newCard);

}

int randint(int i, int j)
{
	if (i < j) std::swap(i, j);
	return i + rand() % (j - i + 1);
}

void Game::ShuffleCard()
{
	Transform* temp;
	Card* card;
	int setLength = cardSet.size();
	
	for (int i = 0; i < setLength; i++)
	{
		int r = randint(i, setLength - 1);
		// Swap object transform
		temp = cardSet[i]->transform;
		cardSet[i]->transform = cardSet[r]->transform;
		cardSet[r]->transform = temp;
		// Swap index in cardset
		std::swap(cardSet[i], cardSet[r]);
	}
}