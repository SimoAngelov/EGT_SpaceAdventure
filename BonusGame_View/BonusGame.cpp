/*
 * BonusGame.cpp
 *
 *  Created on: 9.07.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "BonusGame.h"

Bonus_Game::Bonus_Game() {
	// TODO Auto-generated constructor stub

}

Bonus_Game::~Bonus_Game() {
	// TODO Auto-generated destructor stub
}

void Bonus_Game::SetMoonlightTexture(SDL_Texture* texture) {
	moonlightTexture = texture;
}

SDL_Texture* Bonus_Game::GetMoonlightTexture(){
	return moonlightTexture;
}

void Bonus_Game::SetRedCardTexture(SDL_Texture* texture){
	redCardTexture = texture;
}

SDL_Texture* Bonus_Game::GetRedCardTexture(){
	return redCardTexture;
}

void Bonus_Game::SetBlackCardTexture(SDL_Texture* texture){
	blackCardTexture = texture;
}

SDL_Texture* Bonus_Game::GetBlackCardTexture(){
	return blackCardTexture;
}
