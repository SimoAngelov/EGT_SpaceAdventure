/*
 * BonusGame.h
 *
 *  Created on: 9.07.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef VIEW4_BONUSGAME_H_
#define VIEW4_BONUSGAME_H_
#include <stdio.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

//Window dimension constants
const int m_nWindowWidth = 800; //WINDOW WIDTH
const int m_nWindowHeight = 600; //WINDOW HEIGHT

//const int m_nScreenWidth = 800;  //SCREEN WIDTH for Bonus Win Splash
//const int m_nScreenHeight = 600;  //SCREEN HEIGHT for Bonus Win Splash

//Falling money animation
const int FALLING_MONEY_ANIMATION = 8;

//Red and Black Button constants
const int m_nButtonWidth = 130;  //BUTTON WIDTH
const int m_nButtonHeight = 130;  //BUTTON HEIGHT
//const int m_nTotalButtons = 2;

const int m_nCardWidth = 130;  //CARD WIDTH
const int m_nCardHeight = 180;  //CARD HEIGHT

const int m_nFigureWidth = 50;  //FIGURES WIDTH
const int m_nFigureHeight = 50;  //FIGURES HEIGHT

//typedef enum LButtonSprite {
//	eBUTTON_SPRITE_MOUSE_OUT = 0,
//	eBUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
//	eBUTTON_SPRITE_MOUSE_DOWN = 2,
//	eBUTTON_SPRITE_MOUSE_UP = 3,
//	eBUTTON_SPRITE_TOTAL = 4
//};

class Bonus_Game {
private:
	bool isPresentBonusGame = false;

	//Angle of rotation
	double degrees = 0;

	//For Bonus Win Splash Texture
	SDL_Texture* bonusWinSplashTexture = NULL;

	//For Bonus Game
	SDL_Texture* backgroundTexture = NULL;
	SDL_Texture* redButtonTexture1 = NULL;
	SDL_Texture* redButtonTexture2 = NULL;
	SDL_Texture* redButtonTexture3 = NULL; //*****
	SDL_Texture* blackButtonTexture1 = NULL;
	SDL_Texture* blackButtonTexture2 = NULL;
	SDL_Texture* blackButtonTexture3 = NULL; //*****
	SDL_Texture* faceDownCardTexture1 = NULL;
	SDL_Texture* faceDownCardTexture2 = NULL;
	SDL_Texture* faceUpCardTexture = NULL;
	SDL_Texture* redCardTexture1 = NULL;
	SDL_Texture* redCardTexture2 = NULL;
	SDL_Texture* redCardTexture3 = NULL;
	SDL_Texture* redCardTexture4 = NULL;
	SDL_Texture* redCardTexture5 = NULL;
	SDL_Texture* redCardTexture6 = NULL;
	SDL_Texture* blackCardTexture7 = NULL;
	SDL_Texture* blackCardTexture8 = NULL;
	SDL_Texture* blackCardTexture9 = NULL;
	SDL_Texture* blackCardTexture10 = NULL;
	SDL_Texture* blackCardTexture11 = NULL;
	SDL_Texture* blackCardTexture12 = NULL;
	SDL_Texture* fourCardsTexture = NULL;

	vector<SDL_Texture*> m_vecRedBlackCards;

	//club, diamond, heart, spade
	SDL_Texture* clubTexture = NULL;
	SDL_Texture* diamondTexture = NULL;
	SDL_Texture* heartTexture = NULL;
	SDL_Texture* spadeTexture = NULL;

	//SDL_Surface* image = NULL;
	//SDL_RWops* rwop = NULL;

	//The window we'll be rendering to
	SDL_Window* windowPtr = NULL;
	//SDL_Surface* gXOutPtr = NULL;

	//The window renderer
	SDL_Renderer* rendererPtr = NULL;

	//Falling money animation
	SDL_Rect gSpriteClips[FALLING_MONEY_ANIMATION];
	SDL_Texture* gSpriteSheetTexture;

	//The music that will be played
	Mix_Chunk* gMusic = NULL;

	//The sound effects that will be used
	Mix_Chunk* gButtonMotion = NULL;
	Mix_Chunk* gButtonClick = NULL;
	Mix_Chunk* gCardMoove = NULL;
	Mix_Chunk* gCardOpen = NULL;
	Mix_Chunk* gCardWrong = NULL;
	Mix_Chunk* gCongrat = NULL;
	Mix_Chunk* gWinBonus = NULL;

	//
	int m_nGambleAmount = 0;  //Bonus Game Gamble Amount
	int m_nGambleToWin = 0;  //Bonus Game Gamble To Win
	int m_nGambleLeft = 0;  //Bonus Game Gamble To Left
	//
	TTF_Font* conthrax = NULL;
	SDL_Color color = { 250, 200, 50, 0 };

	//For Bonus Win Splash and Double Up Win Splash - Textures
	SDL_Texture* earnedAmountTexture = NULL;  //Text: "YOU HAVE WON:  "
	SDL_Texture* earnedAmountDigitTexture = NULL;  //Digits
	//For Bonus Win Splash and Double Up Win Splash - Surfaces
	SDL_Surface* earnedAmountSurface = NULL;
	SDL_Surface* earnedAmountDigitSurface = NULL;

	//For Bonus Game Textures
	SDL_Texture* gambleAmountTexture = NULL;  // Text: "GAMBLE AMOUNT: "
	SDL_Texture* gambleAmountDigitTexture = NULL;  //Digits
	SDL_Texture* gambleToWinTexture = NULL;   // Text: "GAMBLE TO WIN: "
	SDL_Texture* gambleToWinDigitTexture = NULL;  //Digits
	SDL_Texture* gambleLeftTexture = NULL;  // Text: "GAMBLE ATTEMPTS LEFT: "
	SDL_Texture* gambleLeftDigitTexture = NULL;  //Digits
	//For Bonus Game Surfaces
	SDL_Surface* gambleAmountSurface = NULL;
	SDL_Surface* gambleAmountDigitSurface = NULL;
	SDL_Surface* gambleToWinSurface = NULL;
	SDL_Surface* gambleToWinDigitSurface = NULL;
	SDL_Surface* gambleLeftSurface = NULL;
	SDL_Surface* gambleLeftDigitSurface = NULL;

public:
	Bonus_Game();
	virtual ~Bonus_Game();

	//Set Methods
	void SetBonusWinSplashTexture(SDL_Texture* texture);  //For Bonus Win Splash Texture

	void SetBackgroundTexture(SDL_Texture* texture);
	void SetRedButtonTexture1(SDL_Texture* texture);
	void SetRedButtonTexture2(SDL_Texture* texture);
	void SetRedButtonTexture3(SDL_Texture* texture);  //*****
	void SetBlackButtonTexture1(SDL_Texture* texture);
	void SetBlackButtonTexture2(SDL_Texture* texture);
	void SetBlackButtonTexture3(SDL_Texture* texture);  //*****
	void SetFaceDownCardTexture1(SDL_Texture* texture);
	void SetFaceDownCardTexture2(SDL_Texture* texture);
	void SetFaceUpCardTexture(SDL_Texture* texture);
	void SetRedCardTexture1(SDL_Texture* texture);
	void SetRedCardTexture2(SDL_Texture* texture);
	void SetRedCardTexture3(SDL_Texture* texture);
	void SetRedCardTexture4(SDL_Texture* texture);
	void SetRedCardTexture5(SDL_Texture* texture);
	void SetRedCardTexture6(SDL_Texture* texture);
	void SetBlackCardTexture7(SDL_Texture* texture);
	void SetBlackCardTexture8(SDL_Texture* texture);
	void SetBlackCardTexture9(SDL_Texture* texture);
	void SetBlackCardTexture10(SDL_Texture* texture);
	void SetBlackCardTexture11(SDL_Texture* texture);
	void SetBlackCardTexture12(SDL_Texture* texture);
	void SetFourCardsTexture(SDL_Texture* texture);

	//For Bonus Win Splash Texture
	void SetEarnedAmountTexture(SDL_Texture* texture);
	void SetEarnedAmountDigitTexture(SDL_Texture* texture);

	//For Bonus Game
	void SetGambleAmountTexture(SDL_Texture* texture);
	void SetGambleAmountDigitTexture(SDL_Texture* texture);
	void SetGambleToWinTexture(SDL_Texture* texture);
	void SetGambleToWinDigitTexture(SDL_Texture* texture);
	void SetGambleLeftTexture(SDL_Texture* texture);
	void SetGambleLeftDigitTexture(SDL_Texture* texture);

	void SetClubTexture(SDL_Texture* texture);
	void SetDiamondTexture(SDL_Texture* texture);
	void SetHeartTexture(SDL_Texture* texture);
	void SetSpadeTexture(SDL_Texture* texture);

	//Get Methods
	SDL_Texture* GetBonusWinSplashTexture();

	SDL_Texture* GetBackgroundTexture();
	SDL_Texture* GetRedButtonTexture1();
	SDL_Texture* GetRedButtonTexture2();
	SDL_Texture* GetRedButtonTexture3();  //******
	SDL_Texture* GetBlackButtonTexture1();
	SDL_Texture* GetBlackButtonTexture2();
	SDL_Texture* GetBlackButtonTexture3();  //******
	SDL_Texture* GetFaceDownCardTexture1();
	SDL_Texture* GetFaceDownCardTexture2();
	SDL_Texture* GetFaceUpCardTexture();
	SDL_Texture* GetRedCardTexture1();
	SDL_Texture* GetRedCardTexture2();
	SDL_Texture* GetRedCardTexture3();
	SDL_Texture* GetRedCardTexture4();
	SDL_Texture* GetRedCardTexture5();
	SDL_Texture* GetRedCardTexture6();
	SDL_Texture* GetBlackCardTexture7();
	SDL_Texture* GetBlackCardTexture8();
	SDL_Texture* GetBlackCardTexture9();
	SDL_Texture* GetBlackCardTexture10();
	SDL_Texture* GetBlackCardTexture11();
	SDL_Texture* GetBlackCardTexture12();
	SDL_Texture* GetFourCardsTexture();

	//For Bonus Win Splash Texture
	SDL_Texture* GetEarnedAmountTexture();
	SDL_Texture* GetEarnedAmountDigitTexture();

	//For Bonus Game
	SDL_Texture* GetGambleAmountTexture();
	SDL_Texture* GetGambleAmountDigitTexture();
	SDL_Texture* GetGambleToWinTexture();
	SDL_Texture* GetGambleToWinDigitTexture();
	SDL_Texture* GetGambleLeftTexture();
	SDL_Texture* GetGambleLeftDigitTexture();

	SDL_Texture* GetClubTexture();
	SDL_Texture* GetDiamondTexture();
	SDL_Texture* GetHeartTexture();
	SDL_Texture* GetSpadeTexture();

	//
	void InitMedia();  //Starts up SDL and creates window
	void LoadFromFile(string path); //Load sprite sheet texture
	//void PresentBonusWinSplash();  //When we have 5 Special figures +++++
	void PlayBonusGame();  //Playing Double Up Bonus Game
	//void PresentDoubleUpWinSplash();  //When the player is winning +++++
	void QuitBonusGame(); //Frees media and shuts down SDL

	//
	void SetGambleAmount(int gambleAmount);
	int GetGambleAmount() const;

	void SetGambleToWin(int gambleToWin);
	int GetGambleToWin() const;

	void SetGambleLeft(int gambleLeft);
	int GetGambleLeft() const;

	//bool m_bIsClicked(int unPosX = 0, int unPosY = 0);

	SDL_Texture* LoadTexture(string path);
	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();

	SDL_Rect* operator =(SDL_Rect newObject) { //Operator overload
		SDL_Rect* object;
		object->x = newObject.x;
		object->y = newObject.y;
		object->w = newObject.w;
		object->h = newObject.h;

		return object;
	}

	SDL_Rect createRect(int x, int y, int w, int h) {
		SDL_Rect object;
		object.x = x;
		object.y = y;
		object.w = w;
		object.h = h;

		return object;
	}

};

#endif /* VIEW4_BONUSGAME_H_ */
