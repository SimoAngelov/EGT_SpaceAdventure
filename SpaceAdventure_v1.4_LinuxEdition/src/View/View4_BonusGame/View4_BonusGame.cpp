//
//  View4_BonusGame.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 26/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "View4_BonusGame.hpp"

View4_BonusGame::View4_BonusGame()
{
    
}

// Set Methods

void View4_BonusGame:: SetBackgroundBonusGame(SDL_Texture* texure)
{
    backgroundBonusGame = texure;
}

void View4_BonusGame:: SetRedButton(SDL_Texture* texture)
{
    redButton = texture;
}

void View4_BonusGame:: SetRedButtonPushed(SDL_Texture* texture)
{
    redButtonPushed = texture;
}

void View4_BonusGame:: SetBlackButton(SDL_Texture* texture)
{
    blackButton = texture;
}

void View4_BonusGame:: SetBlackButtonPushed(SDL_Texture* texture)
{
    blackButtonPushed = texture;
}

void View4_BonusGame:: SetCardTexture(SDL_Texture* texture)
{
    cardTexture = texture;
}

void View4_BonusGame:: SetCloseBonusGameButton(SDL_Texture* texture)
{
    closeBonusGameButton = texture;
}

// Red Card

void View4_BonusGame::SetRedCard1(SDL_Texture* texture)
{
    redCard1 = texture;
    
}
void View4_BonusGame::SetRedCard2(SDL_Texture* texture)
{
    redCard2 = texture;
    
}
void View4_BonusGame::SetRedCard3(SDL_Texture* texture)
{
    redCard3 = texture;
    
}
void View4_BonusGame::SetRedCard4(SDL_Texture* texture)
{
    redCard4 = texture;
    
}
void View4_BonusGame::SetRedCard5(SDL_Texture* texture)
{
    redCard5 = texture;
    
}

// Black Cards

void View4_BonusGame::SetBlackCard1(SDL_Texture* texture)
{
    blackCard1 = texture;
    
}
void View4_BonusGame::SetBlackCard2(SDL_Texture* texture)
{
    blackCard2 = texture;
    
}
void View4_BonusGame::SetBlackCard3(SDL_Texture* texture)
{
    blackCard3 = texture;
    
}
void View4_BonusGame::SetBlackCard4(SDL_Texture* texture)
{
    blackCard4 = texture;
    
}
void View4_BonusGame::SetBlackCard5(SDL_Texture* texture)
{
    blackCard5 = texture;
    
}



// Get Methods

SDL_Texture* View4_BonusGame:: GetBackgroundBonusGame()
{
    return backgroundBonusGame;
}

SDL_Texture* View4_BonusGame:: GetRedButton()
{
    return redButton;
}

SDL_Texture* View4_BonusGame:: GetRedButtonPushed()
{
    return redButtonPushed;
}

SDL_Texture* View4_BonusGame:: GetBlackButton()
{
    return blackButton;
}

SDL_Texture* View4_BonusGame:: GetBlackButtonPushed()
{
    return blackButtonPushed;
}

SDL_Texture* View4_BonusGame:: GetCardTexture()
{
    return cardTexture;
}

// Red Cards

SDL_Texture* View4_BonusGame::GetRedCard1()
{
    return redCard1;
    
}
SDL_Texture* View4_BonusGame::GetRedCard2()
{
    return redCard2;
    
}
SDL_Texture* View4_BonusGame::GetRedCard3()
{
    return redCard3;
    
}
SDL_Texture* View4_BonusGame::GetRedCard4()
{
    return redCard4;
    
}
SDL_Texture* View4_BonusGame::GetRedCard5()
{
    return redCard5;
    
}

SDL_Texture* View4_BonusGame::GetCloseBonusGameButton()
{
    return closeBonusGameButton;
}

// Black Cards

SDL_Texture* View4_BonusGame::GetBlackCard1()
{
    return blackCard1;
    
}
SDL_Texture* View4_BonusGame::GetBlackCard2()
{
    return blackCard2;
    
}
SDL_Texture* View4_BonusGame::GetBlackCard3()
{
    return blackCard3;
    
}
SDL_Texture* View4_BonusGame::GetBlackCard4()
{
    return blackCard4;
    
}
SDL_Texture* View4_BonusGame::GetBlackCard5()
{
    return blackCard5;
    
}
