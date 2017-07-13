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

class Bonus_Game {
private:
	//Screen dimension constants
	const int m_nWidth = 800; // SCREEN_WIDTH
	const int m_nHeight = 600; // SCREEN_HEIGHT

	SDL_Texture* backgroundTexture = NULL;

	SDL_Texture* redButtonTexture = NULL;

	SDL_Texture* blackButtonTexture = NULL;

	SDL_Texture* facingDownCardRedTexture = NULL;

	SDL_Texture* facingDownCardBlackTexture = NULL;

	SDL_Window* windowPtr = NULL;

	SDL_Surface* gXOutPtr = NULL;

	SDL_Renderer* rendererPtr = NULL;

	//The music that will be played

	Mix_Music* gMusic = NULL;

	//The sound effects that will be used

	//Mix_Chunck* g = NULL;

	//Mix_Chunck* g = NULL;

	//Mix_Chunck* g = NULL;

	TTF_Font* StarJedi = NULL;

	SDL_Color color = {252, 252, 252, 0};

	SDL_Surface* gambleSurface = NULL;

	SDL_Texture* gambleTexture = NULL;



public:
	Bonus_Game();
	virtual ~Bonus_Game();

	//Set Methods

	void SetBackgroundTexture(SDL_Texture* texture);

	void SetRedButtonTexture(SDL_Texture* texture);

	void SetBlackButtonTexture(SDL_Texture* texture);

	void SetFacingDownCardRedTexture(SDL_Texture* texture);

	void SetFacingDownCardBlackTexture(SDL_Texture* texture);

	//Get Methods

	SDL_Texture* GetBackgroundTexture();

	SDL_Texture* GetRedButtonTexture();

	SDL_Texture* GetBlackButtonTexture();

	SDL_Texture* GetFacingDownCardRedTexture();

	SDL_Texture* GetFacingDownCardBlackTexture();

	//

	void InitMedia();

	SDL_Texture* LoadTexture(string path);

	void PlayBonusGame();

	void QuitBonusGame();

	SDL_Window* GetWindow();

	SDL_Renderer* GetRenderer();



	SDL_Rect* operator =(SDL_Rect newObject) {
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

#endif /* CONTROLLER4_BONUSGAME_H_ */
