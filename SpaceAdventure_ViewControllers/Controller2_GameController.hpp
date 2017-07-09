//
//  Controller2_GameController.hpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 09/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#ifndef Controller2_GameController_hpp
#define Controller2_GameController_hpp

#include <iostream>

#include <SDL2/SDL.h>

#include <SDL2_image/SDL_image.h>

using namespace std;

class GameController
{
    
private:
    
    SDL_Texture* backButtonTexture = NULL;
    
    SDL_Texture* backButtonTexturePushed = NULL;
    
public:
    
    GameController();
    
    /////
    
    void SetBackButtonTexture(SDL_Texture* texture);
    
    void SetBackButtonTexturePushed(SDL_Texture* texture);
    
    //////
    
    SDL_Texture* GetBackButtonTexture();
    
    SDL_Texture* GetBackButtonTexturePushed();
    
    
    
};

#endif /* Controller2_GameController_hpp */
