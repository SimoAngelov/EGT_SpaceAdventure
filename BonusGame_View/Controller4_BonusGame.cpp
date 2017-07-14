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

//void Bonus_Game::SetFaceDownCardTexture(SDL_Texture* texture) {
//	faceDownCardTexture = texture;
//}
//
//SDL_Texture* Bonus_Game::GetFaceDownCardTexture() {
//	return faceDownCardTexture;
//}
//
//void Bonus_Game::SetFaceUpCardTexture(SDL_Texture* texture) {
//	faceUpCardTexture = texture;
//}
//
//SDL_Texture* Bonus_Game::GetFaceUpCardTexture() {
//	return faceUpCardTexture;
//}

void Bonus_Game::LoadFromFile(string path) {

}

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

			conthrax = TTF_OpenFont("conthrax.ttf", 30);

			if (conthrax == NULL) {
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

	SDL_Rect rectBackground = createRect(0, 0, 2880, 1800);  // Background

	SDL_Rect rectRedButton = createRect(100, 350, 130, 100);  // Red Button

	SDL_Rect rectBlackButton = createRect(560, 350, 130, 100);  // Black Button

	//SDL_Rect rectFaceDownCard = createRect(330, 300, 110, 180); // Face Down Card

	//SDL_Rect rectFaceUpCard = createRect(350, 300, 110, 180);  // Face Up Card

	//

	SDL_Rect rectTextGamble1 = createRect(50, 250, 200, 40); // "GAMBLE AMOUNT"

	SDL_Rect rectTextGamble2 = createRect(500, 250, 200, 40); // "GAMBLE TO WIN";

	SDL_Rect rectTextGamble3 = createRect(250, 180, 290, 40); // "GAMBLE ATTEMPTS LEFT: "

	//SDL_Rect rectTextGamble4 = createRect(320, 30, 200, 50); // "HISTORY"

	//Load Textures

	Bonus_Game.SetBackgroundTexture(LoadTexture("Background.png"));

	Bonus_Game.SetRedButtonTexture(LoadTexture("Red Button.png"));

	Bonus_Game.SetRedButtonTexture(LoadTexture("Red Button_Dark.png"));

	Bonus_Game.SetBlackButtonTexture(LoadTexture("Black Button.png"));

	Bonus_Game.SetBlackButtonTexture(LoadTexture("Black Button_Blue.png"));

//	Bonus_Game.SetFaceDownCardTexture(
//			LoadTexture("FacingDownCard_Star Wars.png"));

	//Bonus_Game.SetFaceUpCardTexture(LoadTexture(""));

	SDL_Surface* image;
	SDL_RWops* rwop;
	rwop = SDL_RWFromFile("graphics star wars.gif", "rb");
	image = IMG_LoadGIF_RW(rwop);
	if (!image) {
		printf("IMG_LoadGif_RW: %s/n", IMG_GetError());

	}

	int xZ = 0;

	int yZ = 0;

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	string gambleText1 = "GAMBLE AMOUNT:";

	string gambleText2 = "GAMBLE TO WIN:";

	string gambleText3 = "GAMBLE ATTEMPTS LEFT: ";

	//string gambleText4 = "HISTORY";

	TTF_Init();

	gambleSurface1 = TTF_RenderText_Solid(conthrax, gambleText1.c_str(), color);

	gambleSurface2 = TTF_RenderText_Solid(conthrax, gambleText2.c_str(), color);

	gambleSurface3 = TTF_RenderText_Solid(conthrax, gambleText3.c_str(), color);

	//gambleSurface = TTF_RenderText_Solid(conthrax, gambleText4.c_str(), color);

	gambleTexture1 = SDL_CreateTextureFromSurface(rendererPtr, gambleSurface1);

	gambleTexture2 = SDL_CreateTextureFromSurface(rendererPtr, gambleSurface2);

	gambleTexture3 = SDL_CreateTextureFromSurface(rendererPtr, gambleSurface3);

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

			//SDL_RenderCopy(rendererPtr, Bonus_Game.GetFaceDownCardTexture(),
			//NULL, &rectFaceDownCard);

			//SDL_RenderCopy(rendererPtr, Bonus_Game.GetFaceUpCardTexture(), NULL, &rectFaceUpCard);

			SDL_RenderCopy(rendererPtr, gambleTexture1, NULL, &rectTextGamble1);

			SDL_RenderCopy(rendererPtr, gambleTexture2, NULL, &rectTextGamble2);

			SDL_RenderCopy(rendererPtr, gambleTexture3, NULL, &rectTextGamble3);

			//SDL_RenderCopy(rendererPtr, gambleTexture, NULL, &rectTextGamble4);

			//if(!gSpriteSheetTexture->loadFromFile("")){

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

