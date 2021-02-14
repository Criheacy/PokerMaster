#include "Renderer.h"

Renderer::Renderer(SDL_Renderer* renderer, class Gizmo* gizmo)
{
	if (this->mRenderer != NULL && this->mRenderer != mRenderer)
	{
		SDL_DestroyRenderer(this->mRenderer);
		this->mRenderer = NULL;
	}
	this->mRenderer = mRenderer;

	tRedNumber = new LTexture();
	tRedNumber->LoadFromFile(mRenderer, TEX_NUMBER_PATH, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00);

	tBlackNumber = new LTexture();
	tBlackNumber->LoadFromFile(mRenderer, TEX_NUMBER_PATH);

	tColor = new LTexture();
	tColor->LoadFromFile(mRenderer, TEX_COLOR_PATH);

	tMajorJoker = new LTexture();
	tMajorJoker->LoadFromFile(mRenderer, TEX_JOKER_PATH, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF);

	tMinorJoker = new LTexture();
	tMinorJoker->LoadFromFile(mRenderer, TEX_JOKER_PATH);

	tCard = new LTexture();
	tCard->LoadFromFile(mRenderer, TEX_CARD_PATH);
}

void Renderer::RenderGame(class Game* game)
{
	
}
