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

void Intro:: SetInsertCreditPushedTextre(SDL_Texture* texture)
{
    insertCreditPushedTexture = texture;
}

//

void Intro:: SetInfoTexture(SDL_Texture* texture)
{
    infoTexture = texture;
}

//

void Intro:: SetInfoTexturePushed(SDL_Texture* texture)
{
    infoTexturePushed = texture;
}

//

void Intro:: SetVolumeTexture(SDL_Texture* texture)
{
    volumeTexture = texture;
}

//

void Intro:: SetVolumeTexture1(SDL_Texture* texture)
{
    volumeTexture1 = texture;
}

//

void Intro:: SetVolumeTexture2(SDL_Texture* texture)
{
    volumeTexture2 = texture;
}

//

void Intro:: SetVolumeTexture3(SDL_Texture* texture)
{
    volumeTexture3 = texture;
}

//

void Intro:: SetVolumePlusButton(SDL_Texture* texture)
{
    volumePlusButton = texture;
}

//

void Intro:: SetVolumePlusButtonPushed(SDL_Texture* texture)
{
    volumePlusButtonPushed = texture;
}

//

void Intro:: SetVolumeMinusButton(SDL_Texture* texture)
{
    volumeMinusButton = texture;
}

//

void Intro:: SetVolumeMinusButtonPushed(SDL_Texture* texture)
{
    volumeMinusButtonPushed = texture;
}

//

void Intro:: SetForwardButtonTexture(SDL_Texture* texture)
{
    forwardButtonTexture = texture;
}

//

void Intro:: SetPushedForwardButtonTexture(SDL_Texture* texture)
{
    pushedForwardButtonTexture = texture;
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

SDL_Texture* Intro:: GetInsertCreditPushedTexture()
{
    return insertCreditPushedTexture;
}

//

SDL_Texture* Intro:: GetInfoTexture()
{
    return infoTexture;
}

//

SDL_Texture* Intro:: GetInfoTexturePushed()
{
    return infoTexturePushed;
}

//

SDL_Texture* Intro:: GetVolumeTexture()
{
    return volumeTexture;
}

//

SDL_Texture* Intro:: GetVolumeTexture1()
{
    return volumeTexture1;
}

//

SDL_Texture* Intro:: GetVolumeTexture2()
{
    return volumeTexture2;
}

//

SDL_Texture* Intro:: GetVolumeTexture3()
{
    return volumeTexture3;
}

//

SDL_Texture* Intro:: GetVolumePlusButton()
{
    return volumePlusButton;
}

//

SDL_Texture* Intro:: GetVolumePlusButtonPushed()
{
    return volumePlusButtonPushed;
}

//

SDL_Texture* Intro:: GetVolumeMinusButton()
{
    return volumeMinusButton;
}

//

SDL_Texture* Intro:: GetVolumeMinusButtonPushed()
{
    return volumeMinusButtonPushed;
}

//

SDL_Texture* Intro:: GetForwardButtonTexture()
{
    return forwardButtonTexture;
}

//

SDL_Texture* Intro:: GetPushedForwardButtonTexture()
{
    return pushedForwardButtonTexture;
}

