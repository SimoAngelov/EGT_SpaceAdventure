//
//  View1_Intro.hpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#ifndef View1_Intro_hpp
#define View1_Intro_hpp

#include <iostream>

#include <SDL2/SDL.h>

#include <SDL2_image/SDL_image.h>

using namespace std;

class Intro
{
    
private:
    
    SDL_Texture* backgroundTexture = NULL;
    
    SDL_Texture* logoTexture = NULL;
    
    SDL_Texture* insertCreditTexture = NULL;
    
    SDL_Texture* insertCreditPushedTexture = NULL;
    
    SDL_Texture* loadGameTexture = NULL;
    
    SDL_Texture* loadGameTexturePushed = NULL;
    
    SDL_Texture* fileNotFoundTexture = NULL;
    
    SDL_Texture* infoTexture = NULL;
    
    SDL_Texture* payTableTexture = NULL;
    
    SDL_Texture* payTableTexturePushed = NULL;
    
    SDL_Texture* infoTexturePushed = NULL;
    
    SDL_Texture* volumeTexture = NULL;
    
    SDL_Texture* volumeTexture1 = NULL;
    
    SDL_Texture* volumeTexture2 = NULL;
    
    SDL_Texture* volumeTexture3 = NULL;
    
    SDL_Texture* volumePlusButton = NULL;
    
    SDL_Texture* volumePlusButtonPushed = NULL;
    
    SDL_Texture* volumeMinusButton = NULL;
    
    SDL_Texture* volumeMinusButtonPushed = NULL;
    
    SDL_Texture* forwardButtonTexture = NULL;
    
    SDL_Texture* pushedForwardButtonTexture = NULL;
    
    SDL_Texture* spaceShipTexture = NULL;
    
    SDL_Texture* spaceShipButtonPlus = NULL;
    
    SDL_Texture* spaceShipButtonPlusPushed = NULL;
    
    SDL_Texture* spaceShipButtonMinus = NULL;
    
    SDL_Texture* spaceShipButtonMinusPushed = NULL;
    
    SDL_Texture* spaceShipButtonOk = NULL;
    
    SDL_Texture* spaceShipButtonOkPushed = NULL;
    
    SDL_Texture* rulesTexture = NULL;
    
    SDL_Texture* payTableTextureInfo = NULL;
    
    SDL_Texture* closeRulesButton = NULL;
    
    SDL_Texture* closePayTableButton = NULL;
    
public:
    
    Intro();
    
    ///// Set Methods ->
    
    void SetBackgroundTexture(SDL_Texture* texture);
    
    void SetLogoTexture(SDL_Texture* texture);
    
    void SetInsertCreditTexture(SDL_Texture* texture);
    
    void SetInsertCreditPushedTextre(SDL_Texture* texture);
    
    void SetLoadGameTexture(SDL_Texture* texture);
    
    void SetLoadGamePushedTexture(SDL_Texture* texture);
    
    void SetFileNotFoundTexture(SDL_Texture* texture);
    
    void SetInfoTexture(SDL_Texture* texture);
    
    void SetInfoTexturePushed(SDL_Texture* texture);
    
    void SetPayTableTexture(SDL_Texture* texture);
    
    void SetPayTableTexturePushed(SDL_Texture* texture);
    
    void SetVolumeTexture(SDL_Texture* texture);
    
    void SetVolumeTexture1(SDL_Texture* texture);
    
    void SetVolumeTexture2(SDL_Texture* texture);
    
    void SetVolumeTexture3(SDL_Texture* texture);
    
    void SetVolumePlusButton(SDL_Texture* texture);
    
    void SetVolumePlusButtonPushed(SDL_Texture* texture);
    
    void SetVolumeMinusButton(SDL_Texture* texture);
    
    void SetVolumeMinusButtonPushed(SDL_Texture* texture);
    
    void SetForwardButtonTexture(SDL_Texture* texture);
    
    void SetPushedForwardButtonTexture(SDL_Texture* texture);
    
    void SetSpaceShipTexture(SDL_Texture* texture);
    
    void SetSpaceShipButtonPlus(SDL_Texture* texture);
    
    void SetSpaceShipButtonPlusPushed(SDL_Texture* texture);
    
    void SetSpaceShipButtonMinus(SDL_Texture* texture);
    
    void SetSpaceShipButtonMinusPushed(SDL_Texture* texture);
    
    void SetSpaceShipButtonOk(SDL_Texture* texture);
    
    void SetSpaceShipButtonOkPushed(SDL_Texture* texture);
    
    void SetRulesTexture(SDL_Texture* texture);
    
    void SetCloseRulesButton(SDL_Texture* texture);
    
    void SetClosePayTableButton(SDL_Texture* texture);
    
    void SetPayTableTextureInfo(SDL_Texture* texture);
    
    ///// Get Mehtods ->
    
    SDL_Texture* GetBackgroundTexture();
    
    SDL_Texture* GetLogoTexture();
    
    SDL_Texture* GetInsertCreditTexture();
    
    SDL_Texture* GetInsertCreditPushedTexture();
    
    SDL_Texture* GetPayTableTexture();
    
    SDL_Texture* GetPayTableTexturePushed();
    
    SDL_Texture* GetLoadGameTexture();
    
    SDL_Texture* GetLoadGamePushedTexture();
    
    SDL_Texture* GetFileNotFoundTexture();
    
    SDL_Texture* GetInfoTexture();
    
    SDL_Texture* GetInfoTexturePushed();
    
    SDL_Texture* GetVolumeTexture();
    
    SDL_Texture* GetVolumeTexture1();
    
    SDL_Texture* GetVolumeTexture2();
    
    SDL_Texture* GetVolumeTexture3();
    
    SDL_Texture* GetVolumePlusButton();
    
    SDL_Texture* GetVolumePlusButtonPushed();
    
    SDL_Texture* GetVolumeMinusButton();
    
    SDL_Texture* GetVolumeMinusButtonPushed();
    
    SDL_Texture* GetForwardButtonTexture();
    
    SDL_Texture* GetPushedForwardButtonTexture();
    
    SDL_Texture* GetSpaceShipTexture();
    
    SDL_Texture* GetSpaceShipButtonPlus();
    
    SDL_Texture* GetSpaceShipButtonPlusPushed();
    
    SDL_Texture* GetSpaceShipButtonMinus();
    
    SDL_Texture* GetSpaceShipButtonMinusPushed();
    
    SDL_Texture* GetSpaceShipButtonOk();
    
    SDL_Texture* GetSpaceShipButtonOkPushed();
    
    SDL_Texture* GetRulesTexture();
    
    SDL_Texture* GetCloseRulesButton();
    
    SDL_Texture* GetClosePayTableButton();
    
    SDL_Texture* GetPayTableTextureInfo();
};

#endif /* View1_Intro_hpp */
