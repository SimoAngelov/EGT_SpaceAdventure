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

#include <SDL2_image/SDL_image.h>

class Slot
{
    
private:
    
    SDL_Texture* slotTexture = NULL;
    
public:
    
    Slot();
    
    /////
    
    void SetSlotTexture(SDL_Texture* texture);
    
    /////
    
    SDL_Texture* GetSlotTexture();
    
};

#endif /* Controller3_Slot_hpp */
