//
//  Controller3_Slot.hpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 11/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#ifndef Controller3_Slot_hpp
#define Controller3_Slot_hpp

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
class Slot
{
    
private:
    
    SDL_Texture* slotTexture = NULL;
    
    //Adding buttons


    SDL_Texture* startSpinButton = NULL;
    SDL_Texture* startSpinButtonPushed = NULL;
    SDL_Texture* maxBetButton = NULL;
    SDL_Texture* maxBetButtonPushed = NULL;
    SDL_Texture* plusLinesButton = NULL;
    SDL_Texture* plusLinesButtonPushed = NULL;
    SDL_Texture* minusButtonLines = NULL;
    SDL_Texture* minusButtonLinesPushed = NULL;
    SDL_Texture* minusButtonBet = NULL;
    SDL_Texture* minusButtonBetPushed = NULL;
    SDL_Texture* plusButtonBet = NULL;
    SDL_Texture* plusButtonBetPushed = NULL;



public:
    
    Slot();
    
    /////
    //texture setters
    
    void SetSlotTexture(SDL_Texture* texture);
    
    void SetStartSpinButton(SDL_Texture* texture);
    void SetStartSpinButtonPushed(SDL_Texture* texture);
    void SetMaxBetButton(SDL_Texture* texture);
    void SetMaxBetButtonPushed(SDL_Texture* texture);
    void SetPlusLinesButton(SDL_Texture* texture);
    void SetPlusLinesButtonPushed(SDL_Texture* texture);
    void SetMinusButtonLines(SDL_Texture* texture);
    void SetMinusButtonLinesPushed(SDL_Texture* texture);
    void SetMinusButtonBet(SDL_Texture* texture);
    void SetMinusButtonBetPushed(SDL_Texture* texture);
    void SetPlusButtonBet(SDL_Texture* texture);
    void SetPlusButtonBetPushed(SDL_Texture* texture);


    /////
    //texture getters
    
    SDL_Texture* GetSlotTexture();
    SDL_Texture* GetStartSpinButton();
    SDL_Texture* GetStartSpinButtonPushed();
    SDL_Texture* GetMaxBetButton();
    SDL_Texture* GetMaxBetButtonPushed();
    SDL_Texture* GetPlusLinesButton();
    SDL_Texture* GetPlusLinesButtonPushed();
    SDL_Texture* GetMinusButtonLines();
    SDL_Texture* GetMinusButtonLinesPushed();
    SDL_Texture* GetMinusButtonBet();
    SDL_Texture* GetMinusButtonBetPushed();
    SDL_Texture* GetPlusButtonBet();
    SDL_Texture* GetPlusButtonBetPushed();
    
};

#endif /* Controller3_Slot_hpp */
