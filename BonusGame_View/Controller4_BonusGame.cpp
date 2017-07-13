/*
 * BonusGame.cpp
 *
 *  Created on: 9.07.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Controller4_BonusGame.h"

Bonus_Game::Bonus_Game() {
	// TODO Auto-generated constructor stub

}

Bonus_Game::~Bonus_Game() {
	// TODO Auto-generated destructor stub
}

void Bonus_Game::SetBackgroundTexture(SDL_Texture* texture) {
	backgroundTexture = texture;
}

SDL_Texture* Bonus_Game::GetBackgroundTexture() {
	return backgroundTexture;
}

void Bonus_Game::SetRedButtonTexture(SDL_Texture* texture) {
	redButtonTexture = texture;
}

SDL_Texture* Bonus_Game::GetRedButtonTexture() {
	return redButtonTexture;
}

void Bonus_Game::SetBlackButtonTexture(SDL_Texture* texture) {
	blackButtonTexture = texture;
}

SDL_Texture* Bonus_Game::GetBlackButtonTexture() {
	return blackButtonTexture;
}

void Bonus_Game::SetFacingDownCardRedTexture(SDL_Texture* texture) {
	facingDownCardRedTexture = texture;
}

SDL_Texture* Bonus_Game::GetFacingDownCardRedTexture() {
	return facingDownCardRedTexture;
}

void Bonus_Game::SetFacingDownCardBlackTexture(SDL_Texture* texture) {
	facingDownCardBlackTexture = texture;
}

SDL_Texture* Bonus_Game::GetFacingDownCardBlackTexture() {
	return facingDownCardBlackTexture;
}

//SDL_Texture* Bonus_Game::

void Bonus_Game::InitMedia() {
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
				cout << "Unable to CREATE RENDERER!\n";
			}
			TTF_Init();

			StarJedi = TTF_OpenFont("StarJedi.ttf", 30);

			if (StarJedi == NULL) {
				cout << "Unable to OPEN FONT!\n";
			}
		}
	}
}

SDL_Texture* Bonus_Game::LoadTexture(string path) {
	SDL_Texture* textureToReturn = NULL;

	textureToReturn = IMG_LoadTexture(rendererPtr, path.c_str());

	if (textureToReturn == NULL) {
		cout << "Unable to load media!\n" << path << endl;
	}
	return textureToReturn;
}

void Bonus_Game::PlayBonusGame() {

	Bonus_Game Bonus_Game;

	SDL_Rect rectBackground = createRect(0, 0, 2880, 1800);

	SDL_Rect rectRedButton = createRect(150, 350, 100, 100);

	SDL_Rect rectBlackButton = createRect(550, 350, 100, 100);

	SDL_Rect rectFacingDownCardRed = createRect(350, 300, 110, 180);

	SDL_Rect rectFacingDownCardBlack = createRect(320, 300, 100, 200);

	//

	SDL_Rect rectTextGamble1 = createRect(100, 250, 200, 50); // "GAMBLE AMOUNT"

	SDL_Rect rectTextGamble2 = createRect(500, 250, 200, 50); // "GAMBLE TO WIN";

	SDL_Rect rectTextGamble3 = createRect(320, 200, 200, 50); // "GAMBLE ATTEMPTS LEFT: "

	SDL_Rect rectTextGamble4 = createRect(320, 30, 200, 50); // "HISTORY"



	//Load Textures
	Bonus_Game.SetBackgroundTexture(LoadTexture("Background.png"));

	Bonus_Game.SetRedButtonTexture(LoadTexture("Rebellion logo.png"));

	Bonus_Game.SetBlackButtonTexture(LoadTexture("Galactic Empire logo.png"));

	Bonus_Game.SetFacingDownCardRedTexture(
			LoadTexture("FacingDownCard_Star Wars.png"));

	Bonus_Game.SetFacingDownCardBlackTexture(LoadTexture(""));

	int xZ = 0;

	int yZ = 0;

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	string gambleText1 = "GAMBLE AMOUNT";

	string gambleText2 = "GAMBLE TO WIN";

	string gambleText3 = "GAMBLE ATTEMPTS LEFT: ";

	string gambleText4 = "HISTORY";

	TTF_Init();

	gambleSurface = TTF_RenderText_Solid(StarJedi, gambleText1.c_str(), color);

	gambleSurface = TTF_RenderText_Solid(StarJedi, gambleText2.c_str(), color);

	gambleSurface = TTF_RenderText_Solid(StarJedi, gambleText3.c_str(), color);

	gambleSurface = TTF_RenderText_Solid(StarJedi, gambleText4.c_str(), color);

	gambleTexture = SDL_CreateTextureFromSurface(rendererPtr, gambleSurface);

	//While application is running
	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			SDL_GetMouseState(&xZ, &yZ);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetBackgroundTexture(),
					&rectBackground, NULL);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetRedButtonTexture(), NULL,
					&rectRedButton);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetBlackButtonTexture(),
					NULL, &rectBlackButton);

			SDL_RenderCopy(rendererPtr,
					Bonus_Game.GetFacingDownCardRedTexture(), NULL,
					&rectFacingDownCardRed);

			//SDL_RenderCopy(rendererPtr, Bonus_Game.GetFacingDownCardBlackTexture(), NULL, &rectFacingDownCardBlack);

			SDL_RenderCopy(rendererPtr, gambleTexture, NULL, &rectTextGamble1);

			SDL_RenderCopy(rendererPtr, gambleTexture, NULL, &rectTextGamble2);

			SDL_RenderCopy(rendererPtr, gambleTexture, NULL, &rectTextGamble3);

			SDL_RenderCopy(rendererPtr, gambleTexture, NULL, &rectTextGamble4);
		}
		//Update screen
		SDL_RenderPresent(rendererPtr);
	}

}

void Bonus_Game::QuitBonusGame() {

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}

