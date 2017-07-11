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
    
    SDL_Texture* playButtonTexture = NULL;
    
    SDL_Texture* playButtonTexturePushed = NULL;
    
    SDL_Texture* firstRow = NULL;
    
    SDL_Texture* secondRow = NULL;
    
    SDL_Texture* thirdRow = NULL;
    
    SDL_Texture* fourthRow = NULL;
    
public:
    
    GameController();
    
    /////
    
    void SetBackButtonTexture(SDL_Texture* texture);
    
    void SetBackButtonTexturePushed(SDL_Texture* texture);
    
    void SetPlayButtonTexture(SDL_Texture* texture);
    
    void SetPlayButtonTexturePushed(SDL_Texture* texture);
    
    void SetFirstRow(SDL_Texture* texture);
    
    void SetSecondRow(SDL_Texture* texture);
    
    void SetThirdRow(SDL_Texture* texture);
    
    void SetFourthRow(SDL_Texture* texture);
    
    
    //////
    
    SDL_Texture* GetBackButtonTexture();
    
    SDL_Texture* GetBackButtonTexturePushed();
    
    SDL_Texture* GetPlayButtonTexture();
    
    SDL_Texture* GetPlayButtonTexturePushed();
    
    SDL_Texture* GetFirstRow();
    
    SDL_Texture* GetSecondRow();
    
    SDL_Texture* GetThirdRow();
    
    SDL_Texture* GetFourthRow();
    
    
    
};

#endif /* Controller2_GameController_hpp */
