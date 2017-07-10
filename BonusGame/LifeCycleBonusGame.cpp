/*
 * LifeCycleBonusGame.cpp
 *
 *  Created on: 9.07.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "LifeCycleBonusGame.h"

LifeCycle_BonusGame::LifeCycle_BonusGame() {
	// TODO Auto-generated constructor stub
}

void LifeCycle_BonusGame::InitMedia() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Create window
		windowPtr = SDL_CreateWindow("Bonus Game", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, m_nWidth, m_nHeight, SDL_WINDOW_SHOWN);

		if (windowPtr == NULL) {
			printf("Window could not be created! SDL_Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			rendererPtr = SDL_CreateRenderer(windowPtr, -1,
					SDL_RENDERER_ACCELERATED);

			if (rendererPtr == NULL) {
				cout << "Could not CREATE RENDERER" << endl;
			}
		}
	}
}

SDL_Texture* LifeCycle_BonusGame::LoadTexture(string path) {
	SDL_Texture* textureToReturn = NULL;

	textureToReturn = IMG_LoadTexture(rendererPtr, path.c_str());

	if (textureToReturn == NULL) {
		cout << "Unable to load media!\n" << path << endl;
	}
	return textureToReturn;
}

void LifeCycle_BonusGame::PlayBonusGame() {

	Bonus_Game Bonus_Game;

	SDL_Rect rectMoonlight = createRect(0, 0, 1280, 720);

	//SDL_Rect rectRedCard = createRect(200, 200, 100, 50);

	//SDL_Rect rectBlackCard = createRect(840, 200, 100, 50);

	//Load Textures

	Bonus_Game.SetMoonlightTexture(LoadTexture("moonlight.png"));

	//Bonus_Game.SetRedCardTexture(LoadTexture(""));

	//Bonus_Game.SetBlackCardTexture(LoadTexture(""));

	int xZ = 0;

	int yZ = 0;

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			SDL_GetMouseState(&xZ, &yZ);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetMoonlightTexture(), &rectMoonlight, NULL);
		}
		//Update screen
		SDL_RenderPresent(rendererPtr);
	}

}

void LifeCycle_BonusGame::QuitBonusGame() {

}
