//
//  View4_BonusGame.hpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 26/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#ifndef View4_BonusGame_hpp
#define View4_BonusGame_hpp

// WINDOWS includes

//#include <iostream>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>

// LINUX Includes

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>

class View4_BonusGame
{
    
    
private:
    
    SDL_Texture* backgroundBonusGame = NULL;
    
    SDL_Texture* blackButton = NULL;
    
    SDL_Texture* blackButtonPushed = NULL;
    
    SDL_Texture* redButton = NULL;
    
    SDL_Texture* redButtonPushed = NULL;
    
    SDL_Texture* cardTexture = NULL;
    
    SDL_Texture* redCard1 = NULL;
    
    SDL_Texture* redCard2 = NULL;
    
    SDL_Texture* redCard3 = NULL;
    
    SDL_Texture* redCard4 = NULL;
    
    SDL_Texture* redCard5 = NULL;
    
    SDL_Texture* blackCard1 = NULL;
    
    SDL_Texture* blackCard2 = NULL;
    
    SDL_Texture* blackCard3 = NULL;
    
    SDL_Texture* blackCard4 = NULL;
    
    SDL_Texture* blackCard5 = NULL;
    
    SDL_Texture* closeBonusGameButton = NULL;
    
public:
    
    View4_BonusGame();
    
    // SetMethods
    
    void SetBackgroundBonusGame(SDL_Texture* texture);
    
    void SetBlackButton(SDL_Texture* texture);
    
    void SetBlackButtonPushed(SDL_Texture* texture);
    
    void SetRedButton(SDL_Texture* texture);
    
    void SetRedButtonPushed(SDL_Texture* texture);
    
    void SetCardTexture(SDL_Texture* texture);
    
    void SetCloseBonusGameButton(SDL_Texture* texture);
    
    // Red Cards
    
    void SetRedCard1(SDL_Texture* texture);
    
    void SetRedCard2(SDL_Texture* texture);
    
    void SetRedCard3(SDL_Texture* texture);
    
    void SetRedCard4(SDL_Texture* texture);
    
    void SetRedCard5(SDL_Texture* texture);
    
    // Black Cards
    
    void SetBlackCard1(SDL_Texture* texture);
    
    void SetBlackCard2(SDL_Texture* texture);
    
    void SetBlackCard3(SDL_Texture* texture);
    
    void SetBlackCard4(SDL_Texture* texture);
    
    void SetBlackCard5(SDL_Texture* texture);
    
    // Get Methods
    
    SDL_Texture* GetBackgroundBonusGame();
    
    SDL_Texture* GetBlackButton();
    
    SDL_Texture* GetBlackButtonPushed();
    
    SDL_Texture* GetRedButton();
    
    SDL_Texture* GetRedButtonPushed();
    
    SDL_Texture* GetCardTexture();
    
    SDL_Texture* GetCloseBonusGameButton();
    
    // Red Cards
    
    SDL_Texture* GetRedCard1();
    
    SDL_Texture* GetRedCard2();
    
    SDL_Texture* GetRedCard3();
    
    SDL_Texture* GetRedCard4();
    
    SDL_Texture* GetRedCard5();
    
    // Black Cards
    
    SDL_Texture* GetBlackCard1();
    
    SDL_Texture* GetBlackCard2();
    
    SDL_Texture* GetBlackCard3();
    
    SDL_Texture* GetBlackCard4();
    
    SDL_Texture* GetBlackCard5();
    
    
    
};

#endif /* View4_BonusGame_hpp */
