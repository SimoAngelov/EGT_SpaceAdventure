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

SDL_Texture* Bonus_Game::GetBackgroundTexture(){
	return backgroundTexture;
}

void Bonus_Game::SetRedButtonTexture(SDL_Texture* texture){
	redButtonTexture = texture;
}

SDL_Texture* Bonus_Game::GetRedButtonTexture(){
	return redButtonTexture;
}

void Bonus_Game::SetBlackButtonTexture(SDL_Texture* texture){
	blackButtonTexture = texture;
}

SDL_Texture* Bonus_Game::GetBlackButtonTexture(){
	return blackButtonTexture;
}

void Bonus_Game::SetFacingDownCardTexture(SDL_Texture* texture) {
	facingDownCardTexture = texture;
}

SDL_Texture* Bonus_Game::GetFacingDownCardTexture() {
	return facingDownCardTexture;
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
			//TTF_Init();

			//Xanadu = TTF_OpenFont("Xanadu.ttf", 30);

			if(Xanadu == NULL){
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

	SDL_Rect rectBackground = createRect(0, 0, 1920, 1200);

	SDL_Rect rectRedButton = createRect(150, 380, 100, 100);

	SDL_Rect rectBlackButton = createRect(550, 380, 100, 100);

	SDL_Rect rectFacingDownCard = createRect(350, 300, 100, 200);

	//Load Textures
	Bonus_Game.SetBackgroundTexture(LoadTexture("BlackBackground.png"));

	Bonus_Game.SetRedButtonTexture(LoadTexture("Rebellion logo.png"));

	Bonus_Game.SetBlackButtonTexture(LoadTexture("Galactic Empire logo.png"));

	Bonus_Game.SetFacingDownCardTexture(LoadTexture("FacingDownCard_Star Wars.png"));

	int xZ = 0;

	int yZ = 0;

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//TTF_Init();

	//While application is running
	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			SDL_GetMouseState(&xZ, &yZ);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetBackgroundTexture(), &rectBackground, NULL);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetRedButtonTexture(), NULL, &rectRedButton);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetBlackButtonTexture(), NULL, &rectBlackButton);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetFacingDownCardTexture(), NULL, &rectFacingDownCard);

		}
		//Update screen
		SDL_RenderPresent(rendererPtr);
	}

}

void Bonus_Game::QuitBonusGame() {

}

