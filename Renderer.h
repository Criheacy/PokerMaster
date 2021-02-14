#pragma once
#include "SDL.h"
#include "LTexture.h"
#include "LFont.h"
#include "Sprite.h"
#include "Settings.h"

class Renderer
{
public:
	Renderer(SDL_Renderer* renderer, class Gizmo* gizmo = NULL);
	~Renderer();

	void RenderGame(class Game* game);

private:
	SDL_Renderer* mRenderer;

	LTexture* tRedNumber;
	LTexture* tBlackNumber;

	LTexture* tMajorJoker;
	LTexture* tMinorJoker;

	LTexture* tColor;
	LTexture* tCard;
};
