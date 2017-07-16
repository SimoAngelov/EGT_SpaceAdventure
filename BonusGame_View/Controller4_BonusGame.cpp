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

void Bonus_Game::SetRedButtonTexture1(SDL_Texture* texture) {
	redButtonTexture1 = texture;
}

SDL_Texture* Bonus_Game::GetRedButtonTexture1() {
	return redButtonTexture1;
}

void Bonus_Game::SetRedButtonTexture2(SDL_Texture* texture) {
	redButtonTexture1 = texture;
}

SDL_Texture* Bonus_Game::GetRedButtonTexture2() {
	return redButtonTexture1;
}

void Bonus_Game::SetBlackButtonTexture1(SDL_Texture* texture) {
	blackButtonTexture1 = texture;
}

SDL_Texture* Bonus_Game::GetBlackButtonTexture1() {
	return blackButtonTexture1;
}

void Bonus_Game::SetBlackButtonTexture2(SDL_Texture* texture) {
	blackButtonTexture2 = texture;
}

SDL_Texture* Bonus_Game::GetBlackButtonTexture2() {
	return blackButtonTexture2;
}

void Bonus_Game::SetFaceDownCardTexture1(SDL_Texture* texture) {
	faceDownCardTexture1 = texture;
}

SDL_Texture* Bonus_Game::GetFaceDownCardTexture1() {
	return faceDownCardTexture1;
}

void Bonus_Game::SetFaceDownCardTexture2(SDL_Texture* texture) {
	faceDownCardTexture2 = texture;
}

SDL_Texture* Bonus_Game::GetFaceDownCardTexture2() {
	return faceDownCardTexture2;
}

void Bonus_Game::SetFaceUpCardTexture(SDL_Texture* texture) {
	faceUpCardTexture = texture;
}

SDL_Texture* Bonus_Game::GetFaceUpCardTexture() {
	return faceUpCardTexture;
}

void Bonus_Game::SetGambleAmountTexture(SDL_Texture* texture) {
	gambleAmountTexture = texture;
}

SDL_Texture* Bonus_Game::GetGambleAmountTexture() {
	return gambleAmountTexture;
}

void Bonus_Game::SetGambleAmountDigitTexture(SDL_Texture* texture) {
	gambleAmountDigitTexture = texture;
}

SDL_Texture* Bonus_Game::GetGambleAmountDigitTexture() {
	return gambleAmountDigitTexture;
}

void Bonus_Game::SetGambleToWinTexture(SDL_Texture* texture) {
	gambleToWinTexture = texture;
}

SDL_Texture* Bonus_Game::GetGambleToWinTexture() {
	return gambleToWinTexture;
}

void Bonus_Game::SetGambleToWinDigitTexture(SDL_Texture* texture) {
	gambleToWinDigitTexture = texture;
}

SDL_Texture* Bonus_Game::GetGambleToWinDigitTexture() {
	return gambleToWinDigitTexture;
}

void Bonus_Game::SetGambleLeftTexture(SDL_Texture* texture) {
	gambleLeftTexture = texture;
}

SDL_Texture* Bonus_Game::GetGambleLeftTexture() {
	return gambleLeftTexture;
}

void Bonus_Game::SetGambleLeftDigitTexture(SDL_Texture* texture) {
	gambleLeftDigitTexture = texture;
}

SDL_Texture* Bonus_Game::GetGambleLeftDigitTexture() {
	return gambleLeftDigitTexture;
}

void Bonus_Game::SetGamble(int gamble) {
	m_nGamble = gamble;
}

int Bonus_Game::GetGamble() const {
	return m_nGamble;
}

//club, diamond, heart, spade
void Bonus_Game::SetClubTexture(SDL_Texture* texture) {
	clubTexture = texture;
}

SDL_Texture* Bonus_Game::GetClubTexture() {
	return clubTexture;
}

void Bonus_Game::SetDiamondTexture(SDL_Texture* texture) {
	diamondTexture = texture;
}

SDL_Texture* Bonus_Game::GetDiamondTexture(){
	return diamondTexture;
}

void Bonus_Game::SetHeartTexture(SDL_Texture* texture){
	heartTexture = texture;
}

SDL_Texture* Bonus_Game::GetHeartTexture(){
	return heartTexture;
}

void Bonus_Game::SetSpadeTexture(SDL_Texture* texture){
	spadeTexture = texture;
}

SDL_Texture* Bonus_Game::GetSpadeTexture(){
	return spadeTexture;
}


//

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
		SDL_WINDOWPOS_CENTERED, m_nWindowWidth, m_nWindowHeight,
				SDL_WINDOW_SHOWN);

		if (windowPtr == NULL) {
			printf("Window could not be created! SDL_Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			//Create renderer for window
			rendererPtr = SDL_CreateRenderer(windowPtr, -1,
					SDL_RENDERER_ACCELERATED);
			if (rendererPtr == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			} else {
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf(
							"SDL_image could not initialize! SDL_mage Error: %s\n",
							IMG_GetError());
					success = false;
				}
			}
			TTF_Init();
			conthrax = TTF_OpenFont("conthrax.ttf", 30);
			if (conthrax == NULL) {
				cout << "Unable to OPEN FONT!\n";
			}
		}
	}
}

//

SDL_Texture* Bonus_Game::LoadTexture(string path) {
	SDL_Texture* textureToReturn = NULL;
	textureToReturn = IMG_LoadTexture(rendererPtr, path.c_str());

	if (textureToReturn == NULL) {
		cout << "Failed to load media!\n" << path << endl;
		if (gSpriteSheetTexture == NULL) {
			printf("Failed to load sprite sheet texture!\n");
		} else {
			int step = 130 + 16;
			for (int i = 0; i < 7; i++) {
				gSpriteClips[i].x = i * step;
				gSpriteClips[i].y = 0;
				gSpriteClips[i].w = 130;
				gSpriteClips[i].h = 178;
			}
			for (int i = 0; i < 7; i++) {
				gSpriteClips[i + 7].x = i * step;
				gSpriteClips[i + 7].y = 178 + 16;
				gSpriteClips[i + 7].w = 130;
				gSpriteClips[i + 7].h = 178;
			}
			for (int i = 0; i < 7; i++) {
				gSpriteClips[i + 2 * 7].x = i * step;
				gSpriteClips[i + 2 * 7].y = 178 + 2 * 16;
				gSpriteClips[i + 2 * 7].w = 130;
				gSpriteClips[i + 2 * 7].h = 178;
			}
			for (int i = 0; i < 7; i++) {
				gSpriteClips[i + 3 * 7].x = i * step;
				gSpriteClips[i + 3 * 7].y = 178 + 3 * 16;
				gSpriteClips[i + 3 * 7].w = 130;
				gSpriteClips[i + 3 * 7].h = 178;
			}
		}
	}
	return textureToReturn;
}

void Bonus_Game::PlayBonusGame() {
	Bonus_Game Bonus_Game;
	SDL_Rect rectBackground = createRect(0, 0, 2880, 1800);  // Background
	SDL_Rect rectRedButton = createRect(100, 350, 130, 100);  // Red Button
	SDL_Rect rectBlackButton = createRect(570, 350, 130, 100);  // Black Button
	SDL_Rect rectFaceDownCard1 = createRect(320, 300, 110, 180); // Face Down Card
	SDL_Rect rectFaceDownCard2 = createRect(350, 320, 110, 180); // Face Down Card
	SDL_Rect rectFaceUpCard = createRect(380, 340, 110, 180);  // Face Up Card

	//
	SDL_Rect rectClub = createRect(10, 10, 50, 50); //Club
	SDL_Rect rectDiamond = createRect(740, 10, 50, 50); //Diamond
	SDL_Rect rectHeart = createRect(10, 540, 50, 50); //Heart
	SDL_Rect rectSpade = createRect(740, 540, 50, 50); //Spade

	//
	SDL_Rect rectTextGamble1 = createRect(50, 250, 200, 40); // "GAMBLE AMOUNT: "
	SDL_Rect rectDigitGamble1 = createRect(250, 250, 50, 40);
	SDL_Rect rectTextGamble2 = createRect(500, 250, 200, 40); // "GAMBLE TO WIN: ";
	SDL_Rect rectDigitGamble2 = createRect(700, 250, 50, 40);
	SDL_Rect rectTextGamble3 = createRect(250, 180, 290, 40); // "GAMBLE ATTEMPTS LEFT: "
	SDL_Rect rectDigitGamble3 = createRect(540, 180, 50, 40);
	//SDL_Rect rectTextGamble4 = createRect(320, 30, 200, 50); // "HISTORY"

	//Load Textures - Resources
	Bonus_Game.SetBackgroundTexture(LoadTexture("Background.png"));
	Bonus_Game.SetRedButtonTexture1(LoadTexture("Red Button.png"));
	Bonus_Game.SetRedButtonTexture2(LoadTexture("Red Button_Dark.png"));
	Bonus_Game.SetBlackButtonTexture1(LoadTexture("Black Button.png"));
	Bonus_Game.SetBlackButtonTexture2(LoadTexture("Black Button_Blue.png"));

	//From Cards
	Bonus_Game.SetFaceDownCardTexture1(
			LoadTexture("REBEL-EMPIRE-ALL-CARDS.png"));
	Bonus_Game.SetFaceDownCardTexture2(
			LoadTexture("REBEL-EMPIRE-ALL-CARDS.png"));
	Bonus_Game.SetFaceUpCardTexture(LoadTexture("REBEL-EMPIRE-ALL-CARDS.png"));

	//club, diamond, heart, spade
	Bonus_Game.SetClubTexture(LoadTexture("Club.png"));
	Bonus_Game.SetDiamondTexture(LoadTexture("Diamond.png"));
	Bonus_Game.SetHeartTexture(LoadTexture("Heart.png"));
	Bonus_Game.SetSpadeTexture(LoadTexture("Spade.png"));

	//
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

//	SDL_Surface* image;
//	SDL_RWops* rwop;
//	rwop = SDL_RWFromFile("graphics star wars.gif", "rb");
//	image = IMG_LoadGIF_RW(rwop);
//	if (!image) {
//		printf("IMG_LoadGif_RW: %s/n", IMG_GetError());
//	}

	int xZ = 0;
	int yZ = 0;

	//Loop flag
	bool quit = false;

	bool redButtonIsClicked = false;

	bool blackButtonIsClicked = false;

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
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetBackgroundTexture(),
					&rectBackground, NULL);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetRedButtonTexture1(), NULL,
					&rectRedButton);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetBlackButtonTexture1(),
			NULL, &rectBlackButton);

			//
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetFaceDownCardTexture1(),
			NULL, &rectFaceDownCard1);

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetFaceDownCardTexture2(),
			NULL, &rectFaceDownCard2);

			//club, diamond, heart, spade
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetClubTexture(), NULL, &rectClub);
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetDiamondTexture(), NULL, &rectDiamond);
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetHeartTexture(), NULL, &rectHeart);
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetSpadeTexture(), NULL, &rectSpade);

			SDL_RenderCopy(rendererPtr, gambleTexture1, NULL, &rectTextGamble1);
			SDL_RenderCopy(rendererPtr, gambleTexture2, NULL, &rectTextGamble2);
			SDL_RenderCopy(rendererPtr, gambleTexture3, NULL, &rectTextGamble3);
			//SDL_RenderCopy(rendererPtr, gambleTexture, NULL, &rectTextGamble4);

			SDL_GetMouseState(&xZ, &yZ);

			//Click on the Buttons
			if ((redButtonIsClicked == true)
					|| (blackButtonIsClicked == true)) {
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetFaceUpCardTexture(),
				NULL, &rectFaceUpCard);
			}

			//Mouse events
			if (e.type == SDL_MOUSEBUTTONDOWN) {  //130x100

//				rectRedButton.x = 100;
//				rectRedButton.y = 350;
//				rectBlackButton.x = 570;
//				rectBlackButton.y = 350;

				if (xZ >= rectRedButton.x && xZ <= 230 && yZ >= rectRedButton.y
						&& yZ <= 450 && redButtonIsClicked == true) {

					SDL_RenderCopy(rendererPtr,
							Bonus_Game.GetBackgroundTexture(), &rectBackground,
							NULL);

					SDL_RenderCopy(rendererPtr,
							Bonus_Game.GetRedButtonTexture2(), NULL,
							&rectRedButton);

					SDL_RenderCopy(rendererPtr,
							Bonus_Game.GetBlackButtonTexture1(),
							NULL, &rectBlackButton);

					SDL_RenderCopy(rendererPtr,
							Bonus_Game.GetFaceUpCardTexture(), NULL,
							&rectFaceUpCard);
				} else {
					if (xZ >= rectBlackButton.x && xZ <= 700
							&& yZ >= rectBlackButton.y && yZ <= 450
							&& blackButtonIsClicked == true) {

						SDL_RenderCopy(rendererPtr,
								Bonus_Game.GetBackgroundTexture(),
								&rectBackground, NULL);

						SDL_RenderCopy(rendererPtr,
								Bonus_Game.GetRedButtonTexture1(), NULL,
								&rectRedButton);

						SDL_RenderCopy(rendererPtr,
								Bonus_Game.GetBlackButtonTexture2(),
								NULL, &rectBlackButton);

						SDL_RenderCopy(rendererPtr,
								Bonus_Game.GetFaceUpCardTexture(), NULL,
								&rectFaceUpCard);
					}
				}
			}
		}
		//Update screen
		SDL_RenderPresent(rendererPtr);
	}

}

void Bonus_Game::QuitBonusGame() {

}

