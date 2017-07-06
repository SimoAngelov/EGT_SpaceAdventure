//
//  Controller1_Intro.cpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 06/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "Controller1_Intro.hpp"

Intro::Intro()
{
    
}
//

void Intro:: SetBackgroundTexture(SDL_Texture* texture)
{
    backgroundTexture = texture;
}

//

void Intro:: SetLogoTexture(SDL_Texture* texture)
{
    logoTexture = texture;
}

//

void Intro:: SetInsertCreditTexture(SDL_Texture* texture)
{
    insertCreditTexture = texture;
}

//

void Intro:: SetInfoTexture(SDL_Texture* texture)
{
    infoTexture = texture;
}

//

void Intro:: SetVolumeTexture(SDL_Texture* texture)
{
    volumeTexture = texture;
}

//

void Intro:: SetForwardButtonTexture(SDL_Texture* texture)
{
    forwardButtonTexture = texture;
}

//

SDL_Texture* Intro:: GetBackgroundTexture()
{
    return backgroundTexture;
}

//

SDL_Texture* Intro:: GetLogoTexture()
{
    return logoTexture;
}

//

SDL_Texture* Intro:: GetInsertCreditTexture()
{
    return insertCreditTexture;
}

//

SDL_Texture* Intro:: GetInfoTexture()
{
    return infoTexture;
}

//

SDL_Texture* Intro:: GetVolumeTexture()
{
    return volumeTexture;
}

//

SDL_Texture* Intro:: GetForwardButtonTexture()
{
    return forwardButtonTexture;
}

