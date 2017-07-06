//
//  Controller1_Intro.hpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 06/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#ifndef Controller1_Intro_hpp
#define Controller1_Intro_hpp

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
    
    SDL_Texture* infoTexture = NULL;
    
    SDL_Texture* volumeTexture = NULL;
    
    SDL_Texture* forwardButtonTexture = NULL;
    
    SDL_Texture* pushedForwardButtonTexture = NULL;
    
public:
    
    Intro();
    
    /////
    
    void SetBackgroundTexture(SDL_Texture* texture);
    
    void SetLogoTexture(SDL_Texture* texture);
    
    void SetInsertCreditTexture(SDL_Texture* texture);
    
    void SetInfoTexture(SDL_Texture* texture);
    
    void SetVolumeTexture(SDL_Texture* texture);
    
    void SetForwardButtonTexture(SDL_Texture* texture);
    
    void SetPushedForwardButtonTexture(SDL_Texture* texture);
    
    /////

    SDL_Texture* GetBackgroundTexture();
    
    SDL_Texture* GetLogoTexture();
    
    SDL_Texture* GetInsertCreditTexture();
    
    SDL_Texture* GetInfoTexture();
    
    SDL_Texture* GetVolumeTexture();
    
    SDL_Texture* GetForwardButtonTexture();
    
    SDL_Texture* GetPushedForwardButtonTexture();
    
};
#endif /* Controller1_Intro_hpp */
