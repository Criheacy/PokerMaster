#include "Renderer.h"

void Renderer::Initialize(SDL_Renderer* renderer)
{
	if (this->mRenderer != NULL && this->mRenderer != mRenderer)
	{
		SDL_DestroyRenderer(this->mRenderer);
		this->mRenderer = NULL;
	}
	this->mRenderer = mRenderer;
}