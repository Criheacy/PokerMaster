#include "Renderer.h"

Renderer::Renderer(SDL_Renderer* renderer, class Gizmo* gizmo)
{
	if (this->mRenderer != NULL && this->mRenderer != mRenderer)
	{
		SDL_DestroyRenderer(this->mRenderer);
		this->mRenderer = NULL;
	}
	this->mRenderer = mRenderer;

	tTiledCard = new LTexture();
	tTiledCard->LoadFromFile(mRenderer, TEX_TILED_CARD_PATH);
	tTiledCard->SetTileSize(TEX_TILED_CARD_TILEWIDTH, TEX_TILED_CARD_TILEHEIGHT);
}

void Renderer::RenderGame(class Game* game)
{
	
}

void Renderer::RenderCard(class Card* card)
{
	// TODO: Refactor numbers to constants
	int tileNumber;
	if (card->isFlipped)
		tileNumber = 56;
	else if (card->value->number == CardNumber::MAJORJOKER && card->value->color == CardColor::None)
		tileNumber = 14;
	else if (card->value->number == CardNumber::MINORJOKER && card->value->color == CardColor::None)
		tileNumber = 28;
	else if (card->value->number != CardNumber::MAJORJOKER && card->value->number != CardNumber::MINORJOKER)
		tileNumber = ((card->value->color) - 1) * 14 + (card->value->number);
	else
		tileNumber = 55;

	tTiledCard->RenderTile(card->transform->GetX(), card->transform->GetY(),
		tileNumber, card->transform->GetScale(), card->transform->GetAngle());

	SDL_RenderPresent(mRenderer);
}
