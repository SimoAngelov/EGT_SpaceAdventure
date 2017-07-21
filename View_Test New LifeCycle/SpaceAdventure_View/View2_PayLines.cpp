//
//  View2_PayLines.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "View2_PayLines.hpp"

PayLines::PayLines()
{
    
}

// Set Methods ->

void PayLines:: SetBackButtonTexture(SDL_Texture* texture)
{
    backButtonTexture = texture;
}

//

void PayLines:: SetBackButtonTexturePushed(SDL_Texture* texture)
{
    backButtonTexturePushed = texture;
}

//

void PayLines:: SetPlayButtonTexture(SDL_Texture* texture)
{
    playButtonTexture = texture;
}

//

void PayLines:: SetPlayButtonTexturePushed(SDL_Texture* texture)
{
    playButtonTexturePushed = texture;
}

//

void PayLines:: SetFirstRow(SDL_Texture* texture)
{
    firstRow = texture;
}

//

void PayLines:: SetSecondRow(SDL_Texture* texture)
{
    secondRow = texture;
}

//

void PayLines:: SetThirdRow(SDL_Texture* texture)
{
    thirdRow = texture;
}

//

void PayLines:: SetFourthRow(SDL_Texture* texture)
{
    fourthRow = texture;
}

// Get Methods ->

SDL_Texture* PayLines:: GetBackButtonTexture()
{
    return backButtonTexture;
}

//

SDL_Texture* PayLines:: GetBackButtonTexturePushed()
{
    return backButtonTexturePushed;
}

//

SDL_Texture* PayLines:: GetPlayButtonTexture()
{
    return playButtonTexture;
}

//

SDL_Texture* PayLines:: GetPlayButtonTexturePushed()
{
    return playButtonTexturePushed;
}

//

SDL_Texture* PayLines:: GetFirstRow()
{
    return firstRow;
}

//

SDL_Texture* PayLines:: GetSecondRow()
{
    return secondRow;
}

//

SDL_Texture* PayLines:: GetThirdRow()
{
    return thirdRow;
}

//

SDL_Texture* PayLines:: GetFourthRow()
{
    return fourthRow;
}
