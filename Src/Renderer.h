#pragma once
#include "SDL.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	void Initialize(SDL_Renderer* renderer);

	void RenderGame(class Game* game);

private:
	SDL_Renderer* mRenderer;
};
