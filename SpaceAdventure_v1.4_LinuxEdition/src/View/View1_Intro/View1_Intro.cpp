//
//  View1_View1_Intro.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "View1_Intro.hpp"

View1_Intro::View1_Intro()
{
    
}

// Quit View 1

void View1_Intro:: QuitView1()
{
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(logoTexture);
    SDL_DestroyTexture(insertCreditPushedTexture);
    SDL_DestroyTexture(insertCreditTexture);
    SDL_DestroyTexture(loadGameTexture);
    SDL_DestroyTexture(loadGameTexturePushed);
    SDL_DestroyTexture(fileNotFoundTexture);
    SDL_DestroyTexture(infoTexture);
    SDL_DestroyTexture(payTableTexture);
    SDL_DestroyTexture(payTableTexturePushed);
    SDL_DestroyTexture(infoTexturePushed);
    SDL_DestroyTexture(volumeTexture);
    SDL_DestroyTexture(volumeTexture1);
    SDL_DestroyTexture(volumeTexture2);
    SDL_DestroyTexture(volumeTexture3);
    SDL_DestroyTexture(volumePlusButton);
    SDL_DestroyTexture(volumePlusButtonPushed);
    SDL_DestroyTexture(volumeMinusButton);
    SDL_DestroyTexture(volumeMinusButtonPushed);
    SDL_DestroyTexture(forwardButtonTexture);
    SDL_DestroyTexture(pushedForwardButtonTexture);
    SDL_DestroyTexture(spaceShipTexture);
    SDL_DestroyTexture(spaceShipButtonPlusPushed);
    SDL_DestroyTexture(spaceShipButtonPlus);
    SDL_DestroyTexture(spaceShipButtonOkPushed);
    SDL_DestroyTexture(spaceShipButtonOk);
    SDL_DestroyTexture(spaceShipButtonMinusPushed);
    SDL_DestroyTexture(spaceShipButtonMinus);
    SDL_DestroyTexture(rulesTexture);
    SDL_DestroyTexture(payTableTextureInfo);
    SDL_DestroyTexture(closeRulesButton);
    SDL_DestroyTexture(closePayTableButton);
    backgroundTexture = NULL;
    logoTexture = NULL;
    insertCreditTexture = NULL;
    insertCreditPushedTexture = NULL;
    loadGameTexture = NULL;
    loadGameTexturePushed = NULL;
    fileNotFoundTexture = NULL;
    infoTexture = NULL;
    payTableTexture = NULL;
    payTableTexturePushed = NULL;
    infoTexturePushed = NULL;
    volumeMinusButton = NULL;
    volumeMinusButtonPushed = NULL;
    volumePlusButton = NULL;
    volumePlusButtonPushed = NULL;
    volumeTexture = NULL;
    volumeTexture1 = NULL;
    volumeTexture2 = NULL;
    spaceShipTexture = NULL;
    spaceShipButtonPlus = NULL;
    spaceShipButtonPlusPushed = NULL;
    spaceShipButtonMinus = NULL;
    spaceShipButtonMinusPushed = NULL;
    spaceShipButtonOk = NULL;
    spaceShipButtonOkPushed = NULL;
    volumeTexture3 = NULL;
    forwardButtonTexture = NULL;
    pushedForwardButtonTexture = NULL;
    rulesTexture = NULL;
    payTableTextureInfo = NULL;
    closeRulesButton = NULL;
    closePayTableButton = NULL;

}

// Set Methods ->

void View1_Intro:: SetBackgroundTexture(SDL_Texture* texture)
{
    backgroundTexture = texture;
}

//

void View1_Intro:: SetLogoTexture(SDL_Texture* texture)
{
    logoTexture = texture;
}

//

void View1_Intro:: SetInsertCreditTexture(SDL_Texture* texture)
{
    insertCreditTexture = texture;
}

//

void View1_Intro:: SetInsertCreditPushedTextre(SDL_Texture* texture)
{
    insertCreditPushedTexture = texture;
}

//

void View1_Intro:: SetLoadGameTexture(SDL_Texture* texture)
{
    loadGameTexture = texture;
}

//

void View1_Intro:: SetLoadGamePushedTexture(SDL_Texture* texture)
{
    loadGameTexturePushed = texture;
}

//

void View1_Intro:: SetFileNotFoundTexture(SDL_Texture* texture)
{
    fileNotFoundTexture = texture;
}

//

void View1_Intro:: SetInfoTexture(SDL_Texture* texture)
{
    infoTexture = texture;
}

//

void View1_Intro:: SetInfoTexturePushed(SDL_Texture* texture)
{
    infoTexturePushed = texture;
}

//

void View1_Intro:: SetPayTableTexture(SDL_Texture* texture)
{
    payTableTexture = texture;
}

//

void View1_Intro:: SetPayTableTexturePushed(SDL_Texture* texture)
{
    payTableTexturePushed = texture;
}

//

void View1_Intro:: SetVolumeTexture(SDL_Texture* texture)
{
    volumeTexture = texture;
}

//

void View1_Intro:: SetVolumeTexture1(SDL_Texture* texture)
{
    volumeTexture1 = texture;
}

//

void View1_Intro:: SetVolumeTexture2(SDL_Texture* texture)
{
    volumeTexture2 = texture;
}

//

void View1_Intro:: SetVolumeTexture3(SDL_Texture* texture)
{
    volumeTexture3 = texture;
}

//

void View1_Intro:: SetVolumePlusButton(SDL_Texture* texture)
{
    volumePlusButton = texture;
}

//

void View1_Intro:: SetVolumePlusButtonPushed(SDL_Texture* texture)
{
    volumePlusButtonPushed = texture;
}

//

void View1_Intro:: SetVolumeMinusButton(SDL_Texture* texture)
{
    volumeMinusButton = texture;
}

//

void View1_Intro:: SetVolumeMinusButtonPushed(SDL_Texture* texture)
{
    volumeMinusButtonPushed = texture;
}

//

void View1_Intro:: SetForwardButtonTexture(SDL_Texture* texture)
{
    forwardButtonTexture = texture;
}

//

void View1_Intro:: SetPushedForwardButtonTexture(SDL_Texture* texture)
{
    pushedForwardButtonTexture = texture;
}

//

void View1_Intro:: SetSpaceShipTexture(SDL_Texture* texture)
{
    spaceShipTexture = texture;
}

//

void View1_Intro:: SetSpaceShipButtonPlus(SDL_Texture* texture)
{
    spaceShipButtonPlus = texture;
}

//

void View1_Intro:: SetSpaceShipButtonPlusPushed(SDL_Texture* texture)
{
    spaceShipButtonPlusPushed = texture;
}

//

void View1_Intro:: SetSpaceShipButtonMinus(SDL_Texture* texture)
{
    spaceShipButtonMinus = texture;
}

//

void View1_Intro:: SetSpaceShipButtonMinusPushed(SDL_Texture* texture)
{
    spaceShipButtonMinusPushed = texture;
}

//

void View1_Intro:: SetSpaceShipButtonOk(SDL_Texture* texture)
{
    spaceShipButtonOk = texture;
}

//

void View1_Intro:: SetSpaceShipButtonOkPushed(SDL_Texture* texture)
{
    spaceShipButtonOkPushed = texture;
}

//

void View1_Intro:: SetRulesTexture(SDL_Texture* texture)
{
    rulesTexture = texture;
}

//

void View1_Intro:: SetCloseRulesButton(SDL_Texture* texture)
{
    closeRulesButton = texture;
}

//

void View1_Intro:: SetClosePayTableButton(SDL_Texture* texture)
{
    closePayTableButton = texture;
}

//

void View1_Intro:: SetPayTableTextureInfo(SDL_Texture* texture)
{
    payTableTextureInfo = texture;
}


// Get Methods ->

SDL_Texture* View1_Intro:: GetBackgroundTexture()
{
    return backgroundTexture;
}

//

SDL_Texture* View1_Intro:: GetLogoTexture()
{
    return logoTexture;
}

//

SDL_Texture* View1_Intro:: GetInsertCreditTexture()
{
    return insertCreditTexture;
}

//

SDL_Texture* View1_Intro:: GetInsertCreditPushedTexture()
{
    return insertCreditPushedTexture;
}

//

SDL_Texture* View1_Intro:: GetLoadGameTexture()
{
    return loadGameTexture;
}

//

SDL_Texture* View1_Intro:: GetLoadGamePushedTexture()
{
    return loadGameTexturePushed;
}

//

SDL_Texture* View1_Intro::GetFileNotFoundTexture()
{
    return fileNotFoundTexture;
}

//

SDL_Texture* View1_Intro:: GetInfoTexture()
{
    return infoTexture;
}

//

SDL_Texture* View1_Intro:: GetInfoTexturePushed()
{
    return infoTexturePushed;
}

//

SDL_Texture* View1_Intro:: GetPayTableTexture()
{
    return payTableTexture;
}

//

SDL_Texture* View1_Intro:: GetPayTableTexturePushed()
{
    return payTableTexturePushed;
}

//

SDL_Texture* View1_Intro:: GetVolumeTexture()
{
    return volumeTexture;
}

//

SDL_Texture* View1_Intro:: GetVolumeTexture1()
{
    return volumeTexture1;
}

//

SDL_Texture* View1_Intro:: GetVolumeTexture2()
{
    return volumeTexture2;
}

//

SDL_Texture* View1_Intro:: GetVolumeTexture3()
{
    return volumeTexture3;
}

//

SDL_Texture* View1_Intro:: GetVolumePlusButton()
{
    return volumePlusButton;
}

//

SDL_Texture* View1_Intro:: GetVolumePlusButtonPushed()
{
    return volumePlusButtonPushed;
}

//

SDL_Texture* View1_Intro:: GetVolumeMinusButton()
{
    return volumeMinusButton;
}

//

SDL_Texture* View1_Intro:: GetVolumeMinusButtonPushed()
{
    return volumeMinusButtonPushed;
}

//

SDL_Texture* View1_Intro:: GetForwardButtonTexture()
{
    return forwardButtonTexture;
}

//

SDL_Texture* View1_Intro:: GetPushedForwardButtonTexture()
{
    return pushedForwardButtonTexture;
}

//

SDL_Texture* View1_Intro:: GetSpaceShipTexture()
{
    return spaceShipTexture;
}

//

SDL_Texture* View1_Intro:: GetSpaceShipButtonPlus()
{
    return spaceShipButtonPlus;
}

//

SDL_Texture* View1_Intro:: GetSpaceShipButtonPlusPushed()
{
    return spaceShipButtonPlusPushed;
}

//

SDL_Texture* View1_Intro:: GetSpaceShipButtonMinus()
{
    return spaceShipButtonMinus;
}

//

SDL_Texture* View1_Intro:: GetSpaceShipButtonMinusPushed()
{
    return spaceShipButtonMinusPushed;
}

//

SDL_Texture* View1_Intro:: GetSpaceShipButtonOk()
{
    return spaceShipButtonOk;
}

//

SDL_Texture* View1_Intro:: GetSpaceShipButtonOkPushed()
{
    return spaceShipButtonOkPushed;
}

//

SDL_Texture* View1_Intro:: GetRulesTexture()
{
    return rulesTexture;
}

//

SDL_Texture* View1_Intro:: GetCloseRulesButton()
{
    return closeRulesButton;
}

//

SDL_Texture* View1_Intro:: GetClosePayTableButton()
{
    return closePayTableButton;
}

//

SDL_Texture* View1_Intro:: GetPayTableTextureInfo()
{
    return payTableTextureInfo;
}
