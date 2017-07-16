/*
 * BonusGame.h
 *
 *  Created on: 9.07.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef CONTROLLER4_BONUSGAME_H_
#define CONTROLLER4_BONUSGAME_H_
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_Mixer.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

//Window dimension constants
const int m_nWindowWidth = 800; //WINDOW WIDTH
const int m_nWindowHeight = 600; //WINDOW HEIGHT

//Red and Black Button constants
const int m_nButtonWidth = 130;  //BUTTON WIDTH
const int m_nButtonHeight = 100;  //BUTTON HEIGHT
const int m_nTotalButtons = 2;

const int m_nCardWidth = 130;  //CARD WIDTH
const int m_nCardHeight = 180;  //CARD HEIGHT

//typedef enum LButtonSprite {
//	eBUTTON_SPRITE_MOUSE_OUT = 0,
//	eBUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
//	eBUTTON_SPRITE_MOUSE_DOWN = 2,
//	eBUTTON_SPRITE_MOUSE_UP = 3,
//	eBUTTON_SPRITE_TOTAL = 4
//};

class Bonus_Game {
public:
	Bonus_Game();
	virtual ~Bonus_Game();

	//Set Methods
	void SetBackgroundTexture(SDL_Texture* texture);
	void SetRedButtonTexture1(SDL_Texture* texture);
	void SetRedButtonTexture2(SDL_Texture* texture);
	void SetBlackButtonTexture1(SDL_Texture* texture);
	void SetBlackButtonTexture2(SDL_Texture* texture);
	void SetFaceDownCardTexture1(SDL_Texture* texture);
	void SetFaceDownCardTexture2(SDL_Texture* texture);
	void SetFaceUpCardTexture(SDL_Texture* texture);

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
	SDL_Texture* GetBackgroundTexture();
	SDL_Texture* GetRedButtonTexture1();
	SDL_Texture* GetRedButtonTexture2();
	SDL_Texture* GetBlackButtonTexture1();
	SDL_Texture* GetBlackButtonTexture2();
	SDL_Texture* GetFaceDownCardTexture1();
	SDL_Texture* GetFaceDownCardTexture2();
	SDL_Texture* GetFaceUpCardTexture();

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
	void PlayBonusGame();
	void QuitBonusGame(); //Frees media and shuts down SDL

	void SetGamble(int gamble);
	int GetGamble() const;

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

private:
	SDL_Texture* backgroundTexture = NULL;
	SDL_Texture* redButtonTexture1 = NULL;
	SDL_Texture* redButtonTexture2 = NULL;
	SDL_Texture* blackButtonTexture1 = NULL;
	SDL_Texture* blackButtonTexture2 = NULL;
	SDL_Texture* faceDownCardTexture1 = NULL;
	SDL_Texture* faceDownCardTexture2 = NULL;
	SDL_Texture* faceUpCardTexture = NULL;

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

	//Card sprites
	SDL_Rect gSpriteClips[25]; //Card sprites from the picture
	SDL_Texture* gSpriteSheetTexture;

	//The music that will be played
	Mix_Music* gMusic = NULL;
	//The sound effects that will be used
	//Mix_Chunck* g = NULL;
	//Mix_Chunck* g = NULL;
	//Mix_Chunck* g = NULL;

	int m_nGamble = 0;

	//
	TTF_Font* conthrax = NULL;
	SDL_Color color = { 252, 252, 252, 0 };

	SDL_Texture* gambleAmountTexture = NULL;  // Text: "GAMBLE AMOUNT: "
	SDL_Texture* gambleAmountDigitTexture = NULL;
	SDL_Texture* gambleToWinTexture = NULL;   // Text: "GAMBLE TO WIN: ";
	SDL_Texture* gambleToWinDigitTexture = NULL;
	SDL_Texture* gambleLeftTexture = NULL;  // Text: "GAMBLE ATTEMPTS LEFT: "
	SDL_Texture* gambleLeftDigitTexture = NULL;

	SDL_Surface* gambleSurface1 = NULL;
	SDL_Surface* gambleSurface2 = NULL;
	SDL_Surface* gambleSurface3 = NULL;
	SDL_Texture* gambleTexture1 = NULL;
	SDL_Texture* gambleTexture2 = NULL;
	SDL_Texture* gambleTexture3 = NULL;

};

#endif /* CONTROLLER4_BONUSGAME_H_ */
