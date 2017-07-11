//
//  Controller3_Slot.cpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 11/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "Controller3_Slot.hpp"

Slot::Slot()
{
    
}

// Set Methods

void Slot:: SetSlotTexture(SDL_Texture* texture)
{
    slotTexture = texture;
}

// Get Methods;

SDL_Texture* Slot:: GetSlotTexture()
{
    return slotTexture;
}

