//
//  View2_PayLines.hpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#ifndef View2_PayLines_hpp
#define View2_PayLines_hpp

#include <iostream>

#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>

#include <stdio.h>

using namespace std;

class PayLines
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
    
    PayLines();
    
    ///// Set Methods ->
    
    void SetBackButtonTexture(SDL_Texture* texture);
    
    void SetBackButtonTexturePushed(SDL_Texture* texture);
    
    void SetPlayButtonTexture(SDL_Texture* texture);
    
    void SetPlayButtonTexturePushed(SDL_Texture* texture);
    
    void SetTextCreditView2(SDL_Texture* texture);
    
    void SetFirstRow(SDL_Texture* texture);
    
    void SetSecondRow(SDL_Texture* texture);
    
    void SetThirdRow(SDL_Texture* texture);
    
    void SetFourthRow(SDL_Texture* texture);
    
    ////// Get Methods ->
    
    SDL_Texture* GetBackButtonTexture();
    
    SDL_Texture* GetBackButtonTexturePushed();
    
    SDL_Texture* GetPlayButtonTexture();
    
    SDL_Texture* GetPlayButtonTexturePushed();
    
    SDL_Texture* GetTextCreditView2();
    
    SDL_Texture* GetFirstRow();
    
    SDL_Texture* GetSecondRow();
    
    SDL_Texture* GetThirdRow();
    
    SDL_Texture* GetFourthRow();
    
};

#endif /* View2_PayLines_hpp */
