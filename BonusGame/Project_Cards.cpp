//============================================================================
// Name        : Project_Cards.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "BonusGame.h"
#include "LifeCycleBonusGame.h"
using namespace std;

int main(int argc, char* args[]) {

	LifeCycle_BonusGame lifeCycleBonusGame;

	lifeCycleBonusGame.InitMedia();

	lifeCycleBonusGame.PlayBonusGame();


	return 0;
}
