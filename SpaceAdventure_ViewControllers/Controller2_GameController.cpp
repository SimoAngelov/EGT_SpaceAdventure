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



