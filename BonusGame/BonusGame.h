/*
 * BonusGame.h
 *
 *  Created on: 9.07.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef BONUSGAME_H_
#define BONUSGAME_H_

#include <iostream>
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>

class Bonus_Game {
private:
	SDL_Texture* moonlightTexture = NULL;

	SDL_Texture* redCardTexture = NULL;

	SDL_Texture* blackCardTexture = NULL;

public:
	Bonus_Game();
	virtual ~Bonus_Game();

	void SetMoonlightTexture(SDL_Texture* texture);

	void SetRedCardTexture(SDL_Texture* texture);

	void SetBlackCardTexture(SDL_Texture* texture);

	SDL_Texture* GetMoonlightTexture();

	SDL_Texture* GetRedCardTexture();

	SDL_Texture* GetBlackCardTexture();
};

#endif /* BONUSGAME_H_ */
