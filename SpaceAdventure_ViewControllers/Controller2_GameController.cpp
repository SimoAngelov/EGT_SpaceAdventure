//
//  Controller2_GameController.cpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 09/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "Controller2_GameController.hpp"

GameController::GameController()
{
    
}

// Set Methods

void GameController:: SetBackButtonTexture(SDL_Texture* texture)
{
    backButtonTexture = texture;
}

//

void GameController:: SetBackButtonTexturePushed(SDL_Texture* texture)
{
    backButtonTexturePushed = texture;
}

//

void GameController:: SetPlayButtonTexture(SDL_Texture* texture)
{
    playButtonTexture = texture;
}

//

void GameController:: SetPlayButtonTexturePushed(SDL_Texture* texture)
{
    playButtonTexturePushed = texture;
}

//

void GameController:: SetFirstRow(SDL_Texture* texture)
{
    firstRow = texture;
}

//

void GameController:: SetSecondRow(SDL_Texture* texture)
{
    secondRow = texture;
}

//

void GameController:: SetThirdRow(SDL_Texture* texture)
{
    thirdRow = texture;
}

//

void GameController:: SetFourthRow(SDL_Texture* texture)
{
    fourthRow = texture;
}

// Get Methods

SDL_Texture* GameController:: GetBackButtonTexture()
{
    return backButtonTexture;
}

//

SDL_Texture* GameController:: GetBackButtonTexturePushed()
{
    return backButtonTexturePushed;
}

//

SDL_Texture* GameController:: GetPlayButtonTexture()
{
    return playButtonTexture;
}

//

SDL_Texture* GameController:: GetPlayButtonTexturePushed()
{
    return playButtonTexturePushed;
}

//

SDL_Texture* GameController:: GetFirstRow()
{
    return firstRow;
}

//

SDL_Texture* GameController:: GetSecondRow()
{
    return secondRow;
}

//

SDL_Texture* GameController:: GetThirdRow()
{
    return thirdRow;
}

//

SDL_Texture* GameController:: GetFourthRow()
{
    return fourthRow;
}



