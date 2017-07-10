/*
 * LifeCycleBonusGame.h
 *
 *  Created on: 9.07.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef LIFECYCLEBONUSGAME_H_
#define LIFECYCLEBONUSGAME_H_

#include <stdio.h>
#include <iostream>
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "BonusGame.h"
using namespace std;

class LifeCycle_BonusGame {
private:
	//Screen dimension constants
	const int m_nWidth = 1280; // SCREEN_WIDTH
	const int m_nHeight = 720; // SCREEN_HEIGHT

	SDL_Window* windowPtr = NULL;
	SDL_Surface* gXOutPtr = NULL;
	SDL_Renderer* rendererPtr = NULL;

public:
	LifeCycle_BonusGame();

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

#endif /* LIFECYCLEBONUSGAME_H_ */
