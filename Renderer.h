#pragma once
#include "SDL.h"
#include "LTexture.h"
#include "LFont.h"
#include "Sprite.h"
#include "Settings.h"
#include "Card.h"

class Renderer
{
public:
	Renderer(SDL_Renderer* renderer, class Gizmo* gizmo = NULL);
	~Renderer();

	void RenderGame(class Game* game);
	void RenderCard(class Card* card);

private:

	SDL_Renderer* mRenderer;
	LTexture* tTiledCard;
};
