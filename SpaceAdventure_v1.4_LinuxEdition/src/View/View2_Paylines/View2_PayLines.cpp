//
//  View2_PayLines.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "View2_PayLines.hpp"

View2_PayLines::View2_PayLines()
{
    
}

// Quit View 2

void View2_PayLines::QuitView2()
{
    SDL_DestroyTexture(backButtonTexture);
    SDL_DestroyTexture(backButtonTexturePushed);
    SDL_DestroyTexture(playButtonTexture);
    SDL_DestroyTexture(playButtonTexturePushed);
    SDL_DestroyTexture(firstRow);
    SDL_DestroyTexture(secondRow);
    SDL_DestroyTexture(thirdRow);
    SDL_DestroyTexture(fourthRow);
    backButtonTexture = NULL;
    playButtonTexture = NULL;
    backButtonTexturePushed = NULL;
    playButtonTexturePushed = NULL;
    firstRow = NULL;
    secondRow = NULL;
    thirdRow = NULL;
    fourthRow = NULL;
}

// Set Methods ->

void View2_PayLines:: SetBackButtonTexture(SDL_Texture* texture)
{
    backButtonTexture = texture;
}

//

void View2_PayLines:: SetBackButtonTexturePushed(SDL_Texture* texture)
{
    backButtonTexturePushed = texture;
}

//

void View2_PayLines:: SetPlayButtonTexture(SDL_Texture* texture)
{
    playButtonTexture = texture;
}

//

void View2_PayLines:: SetPlayButtonTexturePushed(SDL_Texture* texture)
{
    playButtonTexturePushed = texture;
}

//

void View2_PayLines:: SetFirstRow(SDL_Texture* texture)
{
    firstRow = texture;
}

//

void View2_PayLines:: SetSecondRow(SDL_Texture* texture)
{
    secondRow = texture;
}

//

void View2_PayLines:: SetThirdRow(SDL_Texture* texture)
{
    thirdRow = texture;
}

//

void View2_PayLines:: SetFourthRow(SDL_Texture* texture)
{
    fourthRow = texture;
}

// Get Methods ->

SDL_Texture* View2_PayLines:: GetBackButtonTexture()
{
    return backButtonTexture;
}

//

SDL_Texture* View2_PayLines:: GetBackButtonTexturePushed()
{
    return backButtonTexturePushed;
}

//

SDL_Texture* View2_PayLines:: GetPlayButtonTexture()
{
    return playButtonTexture;
}

//

SDL_Texture* View2_PayLines:: GetPlayButtonTexturePushed()
{
    return playButtonTexturePushed;
}

//

SDL_Texture* View2_PayLines:: GetFirstRow()
{
    return firstRow;
}

//

SDL_Texture* View2_PayLines:: GetSecondRow()
{
    return secondRow;
}

//

SDL_Texture* View2_PayLines:: GetThirdRow()
{
    return thirdRow;
}

//

SDL_Texture* View2_PayLines:: GetFourthRow()
{
    return fourthRow;
}
