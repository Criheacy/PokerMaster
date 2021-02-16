#include "Renderer.h"

Renderer::Renderer(SDL_Renderer* renderer, class Gizmo* gizmo)
{
	if (this->mRenderer != NULL && this->mRenderer != mRenderer)
	{
		SDL_DestroyRenderer(this->mRenderer);
		this->mRenderer = NULL;
	}
	this->mRenderer = renderer;

	tTiledCard = new LTexture();
	tTiledCard->LoadFromFile(mRenderer, TEX_TILED_CARD_PATH);
	tTiledCard->SetTileSize(TEX_TILED_CARD_TILEWIDTH, TEX_TILED_CARD_TILEHEIGHT);
}

Renderer::~Renderer()
{
	
}

void Renderer::RenderGame(class Game* game)
{
	
}

void Renderer::RenderCard(class Card* card)
{
	// TODO: Refactor numbers to constants
	int tileNumber;
	if (card->isFlipped)
		tileNumber = 55;
	else if (card->value->number == CardNumber::MAJORJOKER && card->value->color == CardColor::None)
		tileNumber = 13;
	else if (card->value->number == CardNumber::MINORJOKER && card->value->color == CardColor::None)
		tileNumber = 27;
	else if (card->value->number != CardNumber::MAJORJOKER && card->value->number != CardNumber::MINORJOKER)
		tileNumber = (card->value->color - 1) * 14 + (card->value->number - 1);
	else
		tileNumber = 41;

	tTiledCard->RenderTile(card->transform->GetX() + 100, card->transform->GetY() + 100,
		tileNumber, card->transform->GetScale() * 3, card->transform->GetAngle());

}
