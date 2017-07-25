//
//  View1_Intro.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "View1_Intro.hpp"

Intro::Intro()
{
    
}

// Set Methods ->

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

void Intro:: SetLoadGameTexture(SDL_Texture* texture)
{
    loadGameTexture = texture;
}

//

void Intro:: SetLoadGamePushedTexture(SDL_Texture* texture)
{
    loadGameTexturePushed = texture;
}

//

void Intro:: SetFileNotFoundTexture(SDL_Texture* texture)
{
    fileNotFoundTexture = texture;
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

void Intro:: SetPayTableTexture(SDL_Texture* texture)
{
    payTableTexture = texture;
}

//

void Intro:: SetPayTableTexturePushed(SDL_Texture* texture)
{
    payTableTexturePushed = texture;
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

void Intro:: SetSpaceShipTexture(SDL_Texture* texture)
{
    spaceShipTexture = texture;
}

//

void Intro:: SetSpaceShipButtonPlus(SDL_Texture* texture)
{
    spaceShipButtonPlus = texture;
}

//

void Intro:: SetSpaceShipButtonPlusPushed(SDL_Texture* texture)
{
    spaceShipButtonPlusPushed = texture;
}

//

void Intro:: SetSpaceShipButtonMinus(SDL_Texture* texture)
{
    spaceShipButtonMinus = texture;
}

//

void Intro:: SetSpaceShipButtonMinusPushed(SDL_Texture* texture)
{
    spaceShipButtonMinusPushed = texture;
}

//

void Intro:: SetSpaceShipButtonOk(SDL_Texture* texture)
{
    spaceShipButtonOk = texture;
}

//

void Intro:: SetSpaceShipButtonOkPushed(SDL_Texture* texture)
{
    spaceShipButtonOkPushed = texture;
}

//

void Intro:: SetRulesTexture(SDL_Texture* texture)
{
    rulesTexture = texture;
}

//

void Intro:: SetCloseRulesButton(SDL_Texture* texture)
{
    closeRulesButton = texture;
}

//

void Intro:: SetClosePayTableButton(SDL_Texture* texture)
{
    closePayTableButton = texture;
}

//

void Intro:: SetPayTableTextureInfo(SDL_Texture* texture)
{
    payTableTextureInfo = texture;
}


// Get Methods ->

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

SDL_Texture* Intro:: GetLoadGameTexture()
{
    return loadGameTexture;
}

//

SDL_Texture* Intro:: GetLoadGamePushedTexture()
{
    return loadGameTexturePushed;
}

//

SDL_Texture* Intro::GetFileNotFoundTexture()
{
    return fileNotFoundTexture;
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

SDL_Texture* Intro:: GetPayTableTexture()
{
    return payTableTexture;
}

//

SDL_Texture* Intro:: GetPayTableTexturePushed()
{
    return payTableTexturePushed;
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

//

SDL_Texture* Intro:: GetSpaceShipTexture()
{
    return spaceShipTexture;
}

//

SDL_Texture* Intro:: GetSpaceShipButtonPlus()
{
    return spaceShipButtonPlus;
}

//

SDL_Texture* Intro:: GetSpaceShipButtonPlusPushed()
{
    return spaceShipButtonPlusPushed;
}

//

SDL_Texture* Intro:: GetSpaceShipButtonMinus()
{
    return spaceShipButtonMinus;
}

//

SDL_Texture* Intro:: GetSpaceShipButtonMinusPushed()
{
    return spaceShipButtonMinusPushed;
}

//

SDL_Texture* Intro:: GetSpaceShipButtonOk()
{
    return spaceShipButtonOk;
}

//

SDL_Texture* Intro:: GetSpaceShipButtonOkPushed()
{
    return spaceShipButtonOkPushed;
}

//

SDL_Texture* Intro:: GetRulesTexture()
{
    return rulesTexture;
}

//

SDL_Texture* Intro:: GetCloseRulesButton()
{
    return closeRulesButton;
}

//

SDL_Texture* Intro:: GetClosePayTableButton()
{
    return closePayTableButton;
}

//

SDL_Texture* Intro:: GetPayTableTextureInfo()
{
    return payTableTextureInfo;
}
