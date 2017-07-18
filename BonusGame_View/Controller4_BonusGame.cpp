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
	redButtonTexture2 = texture;
}

SDL_Texture* Bonus_Game::GetRedButtonTexture2() {
	return redButtonTexture2;
}

void Bonus_Game::SetRedButtonTexture3(SDL_Texture* texture) {
	redButtonTexture3 = texture;
}

SDL_Texture* Bonus_Game::GetRedButtonTexture3() {
	return redButtonTexture3;
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

void Bonus_Game::SetBlackButtonTexture3(SDL_Texture* texture) {
	blackButtonTexture3 = texture;
}

SDL_Texture* Bonus_Game::GetBlackButtonTexture3() {
	return blackButtonTexture3;
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
//*************
void Bonus_Game::SetRedCardTexture1(SDL_Texture* texture) {
	redCardTexture1 = texture;
}

SDL_Texture* Bonus_Game::GetRedCardTexture1() {
	return redCardTexture1;
}

void Bonus_Game::SetRedCardTexture2(SDL_Texture* texture) {
	redCardTexture1 = texture;
}

SDL_Texture* Bonus_Game::GetRedCardTexture2() {
	return redCardTexture2;
}

void Bonus_Game::SetRedCardTexture3(SDL_Texture* texture) {
	redCardTexture3 = texture;
}

SDL_Texture* Bonus_Game::GetRedCardTexture3() {
	return redCardTexture3;
}

void Bonus_Game::SetRedCardTexture4(SDL_Texture* texture) {
	redCardTexture4 = texture;
}

SDL_Texture* Bonus_Game::GetRedCardTexture4() {
	return redCardTexture4;
}

void Bonus_Game::SetRedCardTexture5(SDL_Texture* texture) {
	redCardTexture5 = texture;
}

SDL_Texture* Bonus_Game::GetRedCardTexture5() {
	return redCardTexture5;
}

void Bonus_Game::SetRedCardTexture6(SDL_Texture* texture) {
	redCardTexture6 = texture;
}

SDL_Texture* Bonus_Game::GetRedCardTexture6() {
	return redCardTexture6;
}

void Bonus_Game::SetBlackCardTexture7(SDL_Texture* texture) {
	blackCardTexture7 = texture;
}

SDL_Texture* Bonus_Game::GetBlackCardTexture7() {
	return blackCardTexture7;
}

void Bonus_Game::SetBlackCardTexture8(SDL_Texture* texture) {
	blackCardTexture8 = texture;
}

SDL_Texture* Bonus_Game::GetBlackCardTexture8() {
	return blackCardTexture8;
}

void Bonus_Game::SetBlackCardTexture9(SDL_Texture* texture) {
	blackCardTexture9 = texture;
}

SDL_Texture* Bonus_Game::GetBlackCardTexture9() {
	return blackCardTexture9;
}

void Bonus_Game::SetBlackCardTexture10(SDL_Texture* texture) {
	blackCardTexture10 = texture;
}

SDL_Texture* Bonus_Game::GetBlackCardTexture10() {
	return blackCardTexture10;
}

void Bonus_Game::SetBlackCardTexture11(SDL_Texture* texture) {
	blackCardTexture11 = texture;
}

SDL_Texture* Bonus_Game::GetBlackCardTexture11() {
	return blackCardTexture11;
}

void Bonus_Game::SetBlackCardTexture12(SDL_Texture* texture) {
	blackCardTexture12 = texture;
}

SDL_Texture* Bonus_Game::GetBlackCardTexture12() {
	return blackCardTexture12;
}

void Bonus_Game::SetChooseCardTexture(SDL_Texture* texture) {
	chooseCardTexture = texture;
}

SDL_Texture* Bonus_Game::GetChooseCardTexture() {
	return chooseCardTexture;
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

//GambleAmount, GambleToWin, GambleLeft
void Bonus_Game::SetGambleAmount(int gambleAmount) {
	m_nGambleAmount = gambleAmount;
}

int Bonus_Game::GetGambleAmount() const {
	return m_nGambleAmount;
}

void Bonus_Game::SetGambleToWin(int gambleToWin) {
	m_nGambleToWin = gambleToWin;
}

int Bonus_Game::GetGambleToWin() const {
	return m_nGambleToWin;
}

void Bonus_Game::SetGambleLeft(int gambleLeft) {
	m_nGambleLeft = gambleLeft;
}

int Bonus_Game::GetGambleLeft() const {
	return m_nGambleLeft;
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

SDL_Texture* Bonus_Game::GetDiamondTexture() {
	return diamondTexture;
}

void Bonus_Game::SetHeartTexture(SDL_Texture* texture) {
	heartTexture = texture;
}

SDL_Texture* Bonus_Game::GetHeartTexture() {
	return heartTexture;
}

void Bonus_Game::SetSpadeTexture(SDL_Texture* texture) {
	spadeTexture = texture;
}

SDL_Texture* Bonus_Game::GetSpadeTexture() {
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

			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
				printf("SDL_mixer clould nit initialize! SDL_mixer Error: %s\n",
				Mix_GetError());
				success = false;
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

			for (int i = 0; i < 6; i++) {
				gSpriteClips[i].x = i * step;
				gSpriteClips[i].y = 0;
				gSpriteClips[i].w = m_nCardWidth;
				gSpriteClips[i].h = m_nCardHeight;
			}
			for (int i = 0; i < 6; i++) {
				gSpriteClips[i + 6].x = i * step;
				gSpriteClips[i + 6].y = m_nCardHeight + 16;
				gSpriteClips[i + 6].w = m_nCardWidth;
				gSpriteClips[i + 6].h = m_nCardHeight;
			}
			for (int i = 0; i < 6; i++) {
				gSpriteClips[i + 2 * 6].x = i * step;
				gSpriteClips[i + 2 * 6].y = m_nCardHeight + 2 * 16;
				gSpriteClips[i + 2 * 6].w = m_nCardWidth;
				gSpriteClips[i + 2 * 6].h = m_nCardHeight;
			}
			for (int i = 0; i < 6; i++) {
				gSpriteClips[i + 3 * 6].x = i * step;
				gSpriteClips[i + 3 * 6].y = m_nCardHeight + 3 * 16;
				gSpriteClips[i + 3 * 6].w = m_nCardWidth;
				gSpriteClips[i + 3 * 6].h = m_nCardHeight;
			}
//			faceDownCard.x = 6*m_nCardWidth + 6*16;
//			faceDownCard.y = 4*m_nCardHeight+
		}
	}
	return textureToReturn;
}

void Bonus_Game::PlayBonusGame() {
	Bonus_Game Bonus_Game;
	SDL_Rect rectBackground = createRect(0, 0, 2880, 1800);  // Background
	SDL_Rect rectRedButton = createRect(100, 350, 130, 100);  // Red Button
	SDL_Rect rectRedButtonClick = createRect(90, 340, 150, 120); //*********************
	SDL_Rect rectBlackButton = createRect(570, 350, 130, 100);  // Black Button
	SDL_Rect rectBlackButtonClick = createRect(560, 340, 150, 120); //*******************
	SDL_Rect rectFaceDownCard1 = createRect(310, 300, 130, 180); // Face Down Card
	SDL_Rect rectFaceDownCard2 = createRect(350, 320, 130, 180); // Face Down Card
	SDL_Rect rectFaceUpCard = createRect(390, 340, 130, 180);  // Face Up Card
	SDL_Rect rectRedCard1 = createRect(390, 340, 130, 180);
	SDL_Rect rectRedCard2 = createRect(390, 340, 130, 180);
	SDL_Rect rectRedCard3 = createRect(390, 340, 130, 180);
	SDL_Rect rectRedCard4 = createRect(390, 340, 130, 180);
	SDL_Rect rectRedCard5 = createRect(390, 340, 130, 180);
	SDL_Rect rectRedCard6 = createRect(390, 340, 130, 180);
	SDL_Rect rectBlackCard7 = createRect(390, 340, 130, 180);
	SDL_Rect rectBlackCard8 = createRect(390, 340, 130, 180);
	SDL_Rect rectBlackCard9 = createRect(390, 340, 130, 180);
	SDL_Rect rectBlackCard10 = createRect(390, 340, 130, 180);
	SDL_Rect rectBlackCard11 = createRect(390, 340, 130, 180);
	SDL_Rect rectBlackCard12 = createRect(390, 340, 130, 180);
	SDL_Rect rectChooseCard = createRect(320, 10, 130, 130);

//
	SDL_Rect rectClub = createRect(10, 10, 50, 50); //Club
	SDL_Rect rectDiamond = createRect(740, 10, 50, 50); //Diamond
	SDL_Rect rectHeart = createRect(10, 540, 50, 50); //Heart
	SDL_Rect rectSpade = createRect(740, 540, 50, 50); //Spade

//
	SDL_Rect rectGambleAmountText = createRect(50, 250, 210, 40); // "GAMBLE AMOUNT: "
	SDL_Rect rectGambleAmountDigit = createRect(250, 250, 70, 40);
	SDL_Rect rectGambleToWinText = createRect(500, 250, 210, 40); // "GAMBLE TO WIN: ";
	SDL_Rect rectGambleToWinDigit = createRect(700, 250, 70, 40);
	SDL_Rect rectGambleLeftText = createRect(250, 180, 290, 40); // "GAMBLE ATTEMPTS LEFT: "
	SDL_Rect rectGambleLeftDigit = createRect(540, 180, 20, 40);

//Load Textures - Resources
	Bonus_Game.SetBackgroundTexture(LoadTexture("Background.png"));
	Bonus_Game.SetRedButtonTexture1(LoadTexture("Red Button_Dark.png"));
	Bonus_Game.SetRedButtonTexture2(LoadTexture("Red Button.png"));
	Bonus_Game.SetRedButtonTexture3(LoadTexture("Red Button.png")); //******
	Bonus_Game.SetBlackButtonTexture1(LoadTexture("Black Button.png"));
	Bonus_Game.SetBlackButtonTexture2(LoadTexture("Black Button_Blue.png"));
	Bonus_Game.SetBlackButtonTexture3(LoadTexture("Black Button_Blue.png")); //*******

//From Cards
	Bonus_Game.SetFaceDownCardTexture1(LoadTexture("2.png"));
	Bonus_Game.SetFaceDownCardTexture2(LoadTexture("2.png"));
	Bonus_Game.SetFaceUpCardTexture(LoadTexture("FaceUpCard.png"));
	Bonus_Game.SetRedCardTexture1(LoadTexture("RedJDiamond.png"));  // NEW CARDS

	Bonus_Game.SetRedCardTexture2(LoadTexture("RedJHeart.png"));
	Bonus_Game.SetRedCardTexture3(LoadTexture("RedKDiamond.png"));
	Bonus_Game.SetRedCardTexture4(LoadTexture("RedKHeart.png"));
	Bonus_Game.SetRedCardTexture5(LoadTexture("RedQDiamond.png"));
	Bonus_Game.SetRedCardTexture6(LoadTexture("RedQHeart.png"));
	Bonus_Game.SetBlackCardTexture7(LoadTexture("BlackJClub.png"));
	Bonus_Game.SetBlackCardTexture8(LoadTexture("BlackJSpade.png"));
	Bonus_Game.SetBlackCardTexture9(LoadTexture("BlackKClub.png"));
	Bonus_Game.SetBlackCardTexture10(LoadTexture("BlackKSpade.png"));
	Bonus_Game.SetBlackCardTexture11(LoadTexture("BlackQClub.png"));
	Bonus_Game.SetBlackCardTexture12(LoadTexture("QSpadeBlack.png"));
	Bonus_Game.SetChooseCardTexture(LoadTexture("choose card4.png")); ///////////////////

//club, diamond, heart, spade
	Bonus_Game.SetClubTexture(LoadTexture("Club.png"));
	Bonus_Game.SetDiamondTexture(LoadTexture("Diamond.png"));
	Bonus_Game.SetHeartTexture(LoadTexture("Heart.png"));
	Bonus_Game.SetSpadeTexture(LoadTexture("Spade.png"));

//
	string gambleAmountText = "GAMBLE AMOUNT:  ";
	string gambleToWinText = "GAMBLE TO WIN:  ";
	string gambleLeftText = "GAMBLE ATTEMPTS LEFT:  ";

	string gambleAmountDigit = "0'000";
	string gambleToWinDigit = "0'000";
	string gambleLeftDigit = "0";

	TTF_Init();
	gambleAmountSurface = TTF_RenderText_Solid(conthrax,
			gambleAmountText.c_str(), color);
	gambleAmountDigitSurface = TTF_RenderText_Solid(conthrax,
			gambleAmountDigit.c_str(), color);
	gambleToWinSurface = TTF_RenderText_Solid(conthrax, gambleToWinText.c_str(),
			color);
	gambleToWinDigitSurface = TTF_RenderText_Solid(conthrax,
			gambleToWinDigit.c_str(), color);
	gambleLeftSurface = TTF_RenderText_Solid(conthrax, gambleLeftText.c_str(),
			color);
	gambleLeftDigitSurface = TTF_RenderText_Solid(conthrax,
			gambleLeftDigit.c_str(), color);

//
	gambleAmountTexture = SDL_CreateTextureFromSurface(rendererPtr,
			gambleAmountSurface);
	gambleAmountDigitTexture = SDL_CreateTextureFromSurface(rendererPtr,
			gambleAmountDigitSurface);
	gambleToWinTexture = SDL_CreateTextureFromSurface(rendererPtr,
			gambleToWinSurface);
	gambleToWinDigitTexture = SDL_CreateTextureFromSurface(rendererPtr,
			gambleToWinDigitSurface);
	gambleLeftTexture = SDL_CreateTextureFromSurface(rendererPtr,
			gambleLeftSurface);
	gambleLeftDigitTexture = SDL_CreateTextureFromSurface(rendererPtr,
			gambleLeftDigitSurface);

//Music

//	SDL_Surface* image;
//	SDL_RWops* rwop;
//	rwop = SDL_RWFromFile("graphics star wars.gif", "rb");
//	image = IMG_LoadGIF_RW(rwop);
//	if (!image) {
//		printf("IMG_LoadGif_RW: %s/n", IMG_GetError());
//	}

//Mouse coordinates xZ, yZ
	int xZ = 0;
	int yZ = 0;

//Loop flag
	bool quit = false;

//Event handler
	SDL_Event e;

//While application is running
	while (quit == false) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
				quit = true;
			}

			// View with all buttons normal

			SDL_GetMouseState(&xZ, &yZ);

			//
			//while(){

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

			SDL_RenderCopy(rendererPtr, Bonus_Game.GetChooseCardTexture(), NULL,
					&rectChooseCard);

			//club, diamond, heart, spade pictures
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetClubTexture(), NULL,
					&rectClub);
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetDiamondTexture(), NULL,
					&rectDiamond);
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetHeartTexture(), NULL,
					&rectHeart);
			SDL_RenderCopy(rendererPtr, Bonus_Game.GetSpadeTexture(), NULL,
					&rectSpade);

			//all texts
			SDL_RenderCopy(rendererPtr, gambleAmountTexture, NULL,
					&rectGambleAmountText);
			SDL_RenderCopy(rendererPtr, gambleAmountDigitTexture, NULL,
					&rectGambleAmountDigit);
			SDL_RenderCopy(rendererPtr, gambleToWinTexture, NULL,
					&rectGambleToWinText);
			SDL_RenderCopy(rendererPtr, gambleToWinDigitTexture, NULL,
					&rectGambleToWinDigit);
			SDL_RenderCopy(rendererPtr, gambleLeftTexture, NULL,
					&rectGambleLeftText);
			SDL_RenderCopy(rendererPtr, gambleLeftDigitTexture, NULL,
					&rectGambleLeftDigit);
		}

		//Mouse events MOTION
		//MOUSE MOTION Red Button
		if (e.type == SDL_MOUSEMOTION) {

			if ((xZ >= rectRedButton.x) && (xZ <= 230)
					&& (yZ >= rectRedButton.y) && (yZ <= 450)) {

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetBackgroundTexture(),
						&rectBackground,
						NULL);

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetRedButtonTexture2(),
				NULL, &rectRedButton);

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetBlackButtonTexture1(),
				NULL, &rectBlackButton);

				//
				SDL_RenderCopy(rendererPtr,
						Bonus_Game.GetFaceDownCardTexture1(),
						NULL, &rectFaceDownCard1);

				SDL_RenderCopy(rendererPtr,
						Bonus_Game.GetFaceDownCardTexture2(),
						NULL, &rectFaceDownCard2);

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetChooseCardTexture(),
				NULL, &rectChooseCard);

				//club, diamond, heart, spade pictures
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetClubTexture(),
				NULL, &rectClub);
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetDiamondTexture(),
				NULL, &rectDiamond);
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetHeartTexture(),
				NULL, &rectHeart);
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetSpadeTexture(),
				NULL, &rectSpade);

				//all texts
				SDL_RenderCopy(rendererPtr, gambleAmountTexture, NULL,
						&rectGambleAmountText);
				SDL_RenderCopy(rendererPtr, gambleAmountDigitTexture, NULL,
						&rectGambleAmountDigit);
				SDL_RenderCopy(rendererPtr, gambleToWinTexture, NULL,
						&rectGambleToWinText);
				SDL_RenderCopy(rendererPtr, gambleToWinDigitTexture, NULL,
						&rectGambleToWinDigit);
				SDL_RenderCopy(rendererPtr, gambleLeftTexture, NULL,
						&rectGambleLeftText);
				SDL_RenderCopy(rendererPtr, gambleLeftDigitTexture, NULL,
						&rectGambleLeftDigit);
			}

			//MOUSE MOTION Black Button
			if ((xZ >= rectBlackButton.x) && (xZ <= 700)
					&& (yZ >= rectBlackButton.y) && (yZ <= 450)) {
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetBackgroundTexture(),
						&rectBackground,
						NULL);

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetRedButtonTexture1(),
				NULL, &rectRedButton);

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetBlackButtonTexture2(),
				NULL, &rectBlackButton);

				//
				SDL_RenderCopy(rendererPtr,
						Bonus_Game.GetFaceDownCardTexture1(),
						NULL, &rectFaceDownCard1);

				SDL_RenderCopy(rendererPtr,
						Bonus_Game.GetFaceDownCardTexture2(),
						NULL, &rectFaceDownCard2);

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetChooseCardTexture(),
				NULL, &rectChooseCard);

				//club, diamond, heart, spade pictures
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetClubTexture(),
				NULL, &rectClub);
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetDiamondTexture(),
				NULL, &rectDiamond);
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetHeartTexture(),
				NULL, &rectHeart);
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetSpadeTexture(),
				NULL, &rectSpade);

				//all texts
				SDL_RenderCopy(rendererPtr, gambleAmountTexture,
				NULL, &rectGambleAmountText);
				SDL_RenderCopy(rendererPtr, gambleAmountDigitTexture,
				NULL, &rectGambleAmountDigit);
				SDL_RenderCopy(rendererPtr, gambleToWinTexture,
				NULL, &rectGambleToWinText);
				SDL_RenderCopy(rendererPtr, gambleToWinDigitTexture,
				NULL, &rectGambleToWinDigit);
				SDL_RenderCopy(rendererPtr, gambleLeftTexture, NULL,
						&rectGambleLeftText);
				SDL_RenderCopy(rendererPtr, gambleLeftDigitTexture,
				NULL, &rectGambleLeftDigit);
			}
			//SDL_RenderPresent(rendererPtr);
		}
		//********************************

		//MOUSEBUTTONDOWN - Red Button is clicked
		if (e.type == SDL_MOUSEBUTTONDOWN) {

			if ((xZ >= rectRedButton.x) && (xZ <= 230)
					&& (yZ >= rectRedButton.y) && (yZ <= 450)) {

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetBackgroundTexture(),
						&rectBackground,
						NULL);

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetRedButtonTexture3(),
				NULL, &rectRedButtonClick);  //*********

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetBlackButtonTexture1(),
				NULL, &rectBlackButton);

				SDL_RenderCopy(rendererPtr,
						Bonus_Game.GetFaceDownCardTexture1(),
						NULL, &rectFaceDownCard1);

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetFaceUpCardTexture(),
				NULL, &rectFaceUpCard);

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetChooseCardTexture(),
				NULL, &rectChooseCard);

				//club, diamond, heart, spade
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetClubTexture(),
				NULL, &rectClub);
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetDiamondTexture(),
				NULL, &rectDiamond);
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetHeartTexture(),
				NULL, &rectHeart);
				SDL_RenderCopy(rendererPtr, Bonus_Game.GetSpadeTexture(),
				NULL, &rectSpade);

				//all Texts
				SDL_RenderCopy(rendererPtr, gambleAmountTexture,
				NULL, &rectGambleAmountText);
				SDL_RenderCopy(rendererPtr, gambleAmountDigitTexture,
				NULL, &rectGambleAmountDigit);
				SDL_RenderCopy(rendererPtr, gambleToWinTexture,
				NULL, &rectGambleToWinText);
				SDL_RenderCopy(rendererPtr, gambleToWinDigitTexture,
				NULL, &rectGambleToWinDigit);
				SDL_RenderCopy(rendererPtr, gambleLeftTexture,
				NULL, &rectGambleLeftText);
				SDL_RenderCopy(rendererPtr, gambleLeftDigitTexture,
				NULL, &rectGambleLeftDigit);
			}

			//MOUSEBUTTONDOWN - Black Button is clicked
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				if ((xZ >= rectBlackButton.x) && (xZ <= 700)
						&& (yZ >= rectBlackButton.y) && (yZ <= 450)) {

					SDL_RenderCopy(rendererPtr,
							Bonus_Game.GetBackgroundTexture(), &rectBackground,
							NULL);

					SDL_RenderCopy(rendererPtr,
							Bonus_Game.GetRedButtonTexture1(),
							NULL, &rectRedButton);

					SDL_RenderCopy(rendererPtr,
							Bonus_Game.GetBlackButtonTexture3(),
							NULL, &rectBlackButtonClick);  //*********

				SDL_RenderCopy(rendererPtr, Bonus_Game.GetFaceUpCardTexture(),
				NULL, &rectFaceUpCard);

					//Effect to the Face Down Card Texture 1

					//while(){


					SDL_RenderCopy(rendererPtr,
							Bonus_Game.GetChooseCardTexture(),
							NULL, &rectChooseCard);

					//club, diamond, heart, spade
					SDL_RenderCopy(rendererPtr, Bonus_Game.GetClubTexture(),
					NULL, &rectClub);
					SDL_RenderCopy(rendererPtr, Bonus_Game.GetDiamondTexture(),
					NULL, &rectDiamond);
					SDL_RenderCopy(rendererPtr, Bonus_Game.GetHeartTexture(),
					NULL, &rectHeart);
					SDL_RenderCopy(rendererPtr, Bonus_Game.GetSpadeTexture(),
					NULL, &rectSpade);

					SDL_RenderCopy(rendererPtr, gambleAmountTexture,
					NULL, &rectGambleAmountText);
					SDL_RenderCopy(rendererPtr, gambleAmountDigitTexture,
					NULL, &rectGambleAmountDigit);
					SDL_RenderCopy(rendererPtr, gambleToWinTexture,
					NULL, &rectGambleToWinText);
					SDL_RenderCopy(rendererPtr, gambleToWinDigitTexture,
					NULL, &rectGambleToWinDigit);
					SDL_RenderCopy(rendererPtr, gambleLeftTexture,
					NULL, &rectGambleLeftText);
					SDL_RenderCopy(rendererPtr, gambleLeftDigitTexture,
					NULL, &rectGambleLeftDigit);

				}
				//SDL_RenderPresent(rendererPtr);

			}

		}

//Update screen
		SDL_RenderPresent(rendererPtr);
	}
}

void Bonus_Game::QuitBonusGame() {

}

