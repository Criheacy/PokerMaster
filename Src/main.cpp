#pragma once
#include <cstdio>
#include <string>
#include <algorithm>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Game.h"
#include "Card.h"
#include "Renderer.h"

#include "Gizmo.h"
#include "Settings.h"

Gizmo* gizmo = new Gizmo();

bool Init(SDL_Window*& mainWindow, SDL_Renderer*& mainRenderer)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	//Set texture filtering to nearest
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

	//Create window
	mainWindow = SDL_CreateWindow("Pac Man", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (mainWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	/*SDL_Surface* iconSurface = IMG_Load("Assets/icon.png");
	if (iconSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", "Assets/icon.png", IMG_GetError());
		return false;
	}
	SDL_SetWindowIcon(mainWindow, iconSurface);*/

	//Create renderer for window
	mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mainRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	//Initialize renderer color
	SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	return true;
}

void Close(SDL_Window*& mainWindow, SDL_Renderer*& mainRenderer)
{
	//Destroy window	
	SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyWindow(mainWindow);
	mainWindow = NULL;
	mainRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char** argv) 
{
	SDL_Window* mainWindow = NULL;
	SDL_Renderer* mainRenderer = NULL;
	Init(mainWindow, mainRenderer);

	Game* game = new Game();

	Renderer* renderer = new Renderer(mainRenderer);

	SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(mainRenderer);

	for (auto it = game->cardSet.begin(); it != game->cardSet.end(); it++)
	{
		renderer->RenderCard(*it);
		SDL_RenderPresent(mainRenderer);
		SDL_RenderPresent(mainRenderer);
	}
	

	// Enable Gizmo
	gizmo->SetBrush(mainRenderer);
	gizmo->SetGizmoColor(0xFF, 0x00, 0x00);

	// Game Loop
	bool quitFlag = false;
	SDL_Event evt;
	while (!quitFlag)
	{
		while (SDL_PollEvent(&evt) != 0)
		{
			//User requests quit
			if (evt.type == SDL_QUIT)
			{
				quitFlag = true;
			}
			if (evt.type == SDL_KEYDOWN && evt.key.repeat == 0)
			{
				//Adjust the velocity
				switch (evt.key.keysym.sym)
				{
				default: break;
				}
			}
		}

//		renderer->RenderGame(game);
	}

	Close(mainWindow, mainRenderer);
	return 0;
}