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

#include "View4_BonusGame.h"
using namespace std;

int main(int argc, char* args[])
{

	Bonus_Game BonusGame;

	BonusGame.InitMedia();

	BonusGame.PlayBonusGame();

	return 0;
}
