//
//  View4_BonusGame.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 26/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "View4_BonusGame.hpp"

ViewBonusGame::ViewBonusGame()
{
    
}

// Set Methods

void ViewBonusGame:: SetBackgroundBonusGame(SDL_Texture* texure)
{
    backgroundBonusGame = texure;
}

void ViewBonusGame:: SetRedButton(SDL_Texture* texture)
{
    redButton = texture;
}

void ViewBonusGame:: SetRedButtonPushed(SDL_Texture* texture)
{
    redButtonPushed = texture;
}

void ViewBonusGame:: SetBlackButton(SDL_Texture* texture)
{
    blackButton = texture;
}

void ViewBonusGame:: SetBlackButtonPushed(SDL_Texture* texture)
{
    blackButtonPushed = texture;
}

void ViewBonusGame:: SetCardTexture(SDL_Texture* texture)
{
    cardTexture = texture;
}

void ViewBonusGame:: SetCloseBonusGameButton(SDL_Texture* texture)
{
    closeBonusGameButton = texture;
}

// Red Card

void ViewBonusGame::SetRedCard1(SDL_Texture* texture)
{
    redCard1 = texture;
    
}
void ViewBonusGame::SetRedCard2(SDL_Texture* texture)
{
    redCard2 = texture;
    
}
void ViewBonusGame::SetRedCard3(SDL_Texture* texture)
{
    redCard3 = texture;
    
}
void ViewBonusGame::SetRedCard4(SDL_Texture* texture)
{
    redCard4 = texture;
    
}
void ViewBonusGame::SetRedCard5(SDL_Texture* texture)
{
    redCard5 = texture;
    
}

// Black Cards

void ViewBonusGame::SetBlackCard1(SDL_Texture* texture)
{
    blackCard1 = texture;
    
}
void ViewBonusGame::SetBlackCard2(SDL_Texture* texture)
{
    blackCard2 = texture;
    
}
void ViewBonusGame::SetBlackCard3(SDL_Texture* texture)
{
    blackCard3 = texture;
    
}
void ViewBonusGame::SetBlackCard4(SDL_Texture* texture)
{
    blackCard4 = texture;
    
}
void ViewBonusGame::SetBlackCard5(SDL_Texture* texture)
{
    blackCard5 = texture;
    
}



// Get Methods

SDL_Texture* ViewBonusGame:: GetBackgroundBonusGame()
{
    return backgroundBonusGame;
}

SDL_Texture* ViewBonusGame:: GetRedButton()
{
    return redButton;
}

SDL_Texture* ViewBonusGame:: GetRedButtonPushed()
{
    return redButtonPushed;
}

SDL_Texture* ViewBonusGame:: GetBlackButton()
{
    return blackButton;
}

SDL_Texture* ViewBonusGame:: GetBlackButtonPushed()
{
    return blackButtonPushed;
}

SDL_Texture* ViewBonusGame:: GetCardTexture()
{
    return cardTexture;
}

// Red Cards

SDL_Texture* ViewBonusGame::GetRedCard1()
{
    return redCard1;
    
}
SDL_Texture* ViewBonusGame::GetRedCard2()
{
    return redCard2;
    
}
SDL_Texture* ViewBonusGame::GetRedCard3()
{
    return redCard3;
    
}
SDL_Texture* ViewBonusGame::GetRedCard4()
{
    return redCard4;
    
}
SDL_Texture* ViewBonusGame::GetRedCard5()
{
    return redCard5;
    
}

SDL_Texture* ViewBonusGame::GetCloseBonusGameButton()
{
    return closeBonusGameButton;
}

// Black Cards

SDL_Texture* ViewBonusGame::GetBlackCard1()
{
    return blackCard1;
    
}
SDL_Texture* ViewBonusGame::GetBlackCard2()
{
    return blackCard2;
    
}
SDL_Texture* ViewBonusGame::GetBlackCard3()
{
    return blackCard3;
    
}
SDL_Texture* ViewBonusGame::GetBlackCard4()
{
    return blackCard4;
    
}
SDL_Texture* ViewBonusGame::GetBlackCard5()
{
    return blackCard5;
    
}
