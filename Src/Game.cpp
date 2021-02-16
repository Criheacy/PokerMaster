#include "Game.h"

Game::Game()
{

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