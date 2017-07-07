//
//  LifeCycle.cpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 06/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "LifeCycle.hpp"

LifeCycle::LifeCycle()
{
    
}

// Initialize Everything and Creating WINDOW AND RENDERER

void LifeCycle:: InitMedia()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        cout << "Problem to INIZIALIZE MEDIA" << endl;
    }
    else
    {
        windowPtr = SDL_CreateWindow("Space Adventure", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_nWidth, m_nHeight, SDL_WINDOW_SHOWN);
        
        if(windowPtr == NULL)
        {
            cout << "Problem to CREATE WINDOW" << endl;
        }
        else
        {
            rendererPtr = SDL_CreateRenderer(windowPtr, -1, SDL_RENDERER_ACCELERATED);
            
            if(rendererPtr == NULL)
            {
                cout << "Problem to CREATE RENDERER" << endl;
            }
        }
    }
}

// To load Texture from PATH

SDL_Texture* LifeCycle:: LoadTexture(string path)
{
    SDL_Texture* textureToReturn = NULL;
    
    textureToReturn = IMG_LoadTexture(rendererPtr, path.c_str());
    
    if(textureToReturn == NULL)
    {
        cout << "Problem to load TEXTURE -> " << path << endl;
    }
    
    return textureToReturn;
}

//While LifeCycle

void LifeCycle:: Play()
{
    // Create Object from Controller1_Intro
    
    Intro Intro;
    
    // Creating objects from SDL_Rect and Custom Constructor -> createRect(int x, int y, int w, int h)
    
    SDL_Rect rectBackground = createRect(0, 0, 1280, 720);
    
    SDL_Rect rectForwardButton = createRect(650, 570, 200, 150);
    
    SDL_Rect rectLogo = createRect(400, 10, 500, 250);
    
    SDL_Rect rectInsertCredit = createRect(450, 330, 400, 130);
    
    SDL_Rect rectInfoButton = createRect(10, 650, 50, 50);
    
    SDL_Rect rectVolume = createRect(1100, 600, 100, 100);
    
    SDL_Rect rectVolumePlusButton = createRect(1210, 630, 50, 50);
    
    SDL_Rect rectVolumeMinusButton = createRect(1030, 630, 50, 50);
    
    SDL_Rect rectSpaceShip = createRect(0, -500, 1280, 500);
    
    SDL_Rect rectSpaceShipButtonMinus = createRect(225, 400, 100, 100);
    
    SDL_Rect rectSpaceShipButtonPlus = createRect(970, 400, 100, 100);
    
    // Event Object
    
    SDL_Event ev;
    
    // Load Textures
    
    Intro.SetBackgroundTexture(LoadTexture("background.png"));
    
    Intro.SetForwardButtonTexture(LoadTexture("right.png"));
    
    Intro.SetPushedForwardButtonTexture(LoadTexture("rightPushed.png"));
    
    Intro.SetLogoTexture(LoadTexture("logo.png"));
    
    Intro.SetInsertCreditTexture(LoadTexture("insertCredit.png"));
    
    Intro.SetInsertCreditPushedTextre(LoadTexture("insertCreditPushed.png"));
    
    Intro.SetInfoTexture(LoadTexture("infoButton.png"));
    
    Intro.SetInfoTexturePushed(LoadTexture("infoButtonPushed.png"));
    
    Intro.SetVolumeTexture(LoadTexture("volume.png"));
    
    Intro.SetVolumeTexture1(LoadTexture("volume1.png"));
    
    Intro.SetVolumeTexture2(LoadTexture("volume2.png"));
    
    Intro.SetVolumeTexture3(LoadTexture("volume3.png"));
    
    Intro.SetVolumePlusButton(LoadTexture("plusButton.png"));
    
    Intro.SetVolumePlusButtonPushed(LoadTexture("plusButtonPushed.png"));
    
    Intro.SetVolumeMinusButton(LoadTexture("minusButton.png"));
    
    Intro.SetVolumeMinusButtonPushed(LoadTexture("minusButtonPushed.png"));
    
    Intro.SetSpaceShipTexture(LoadTexture("spaceShip.png"));
    
    Intro.SetSpaceShipButtonPlus(LoadTexture("spaceShipButtonPlus.png"));
    
    Intro.SetSpaceShipButtonPlusPushed(LoadTexture("spaceShipButtonPlusPushed.png"));
    
    Intro.SetSpaceShipButtonMinus(LoadTexture("spaceShipButtonMinus.png"));
    
    Intro.SetSpaceShupButtonMinusPushed(LoadTexture("spaceShipButtonMinusPushed.png"));
    
    
    // Bool to quit LifeCycle
    
    bool quitCycle = false;
    
    // Bool SpaceShip is Hidden
    
    bool spaceShipHidden = true;
    
    // Counter Volume Music
    
    int counterVolume = 0;
    
    // Mouse Coordinates xZ, yZ
    
    int xZ = 0;
    
    int yZ = 0;
    
    while(quitCycle == false)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
            if(ev.type == SDL_QUIT)
            {
                quitCycle = true;
            }
            
            // View with all buttons normal
            
            SDL_GetMouseState(&xZ, &yZ);
            
            // Counter volume 0 and this code -> are same

//            SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
//            
//            SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
//            
//            SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
//            
//            SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);
//            
//            SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
//            
//            SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
//            
//            SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
//            
//            SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
            
            
            // View with all buttons normal and volume MUTE
            
            if(counterVolume == 0)
            {
                SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                
                SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                
                
            }
            
            // View with all buttons normal and volume 1
            
            if(counterVolume == 1)
            {
                SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                
                SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL, &rectVolume);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
            }
            
            // View with all buttons normal and volume 2
            
            if(counterVolume == 2)
            {
                SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                
                SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL, &rectVolume);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
            }
            
            // View with all buttons normal and volume 3
            
            if(counterVolume == 3)
            {
                SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                
                SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL, &rectVolume);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
            }
            
            if((spaceShipHidden == false && counterVolume == 0) || (spaceShipHidden == false && counterVolume == 1) || (spaceShipHidden == false && counterVolume == 2) || (spaceShipHidden == false && counterVolume == 3))
            {
                SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                
                SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);
                
                SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                
                SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipTexture(), NULL, &rectSpaceShip);
                
                SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipButtonMinus(), NULL, &rectSpaceShipButtonMinus);
                
                SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipButtonPlus(), NULL, &rectSpaceShipButtonPlus);
            
            }
            
            if(ev.type == SDL_MOUSEBUTTONDOWN)
            {
                // Button FORWARD
                
                if(xZ >= rectForwardButton.x && xZ <= 900 && yZ >= rectForwardButton.y && yZ <= 650)
                {
                    SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetPushedForwardButtonTexture(), NULL, &rectForwardButton);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                    
                    if(counterVolume == 0)
                    {
                       SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                    }
                    
                    if(counterVolume == 1)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL, &rectVolume);
                    }
                    
                    if(counterVolume == 2)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL, &rectVolume);
                    }
                    
                    if(counterVolume == 3)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL, &rectVolume);
                    }
                }
                
                // Button INSERT CREDIT
                
                if(xZ >= rectInsertCredit.x && xZ <= 850 && yZ >= rectInsertCredit.y && yZ <= 460 && spaceShipHidden == true)
                {
                    SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                    
                    if(counterVolume == 0)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                    }
                    
                    if(counterVolume == 1)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL, &rectVolume);
                    }
                    
                    if(counterVolume == 2)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL, &rectVolume);
                    }
                    
                    if(counterVolume == 3)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL, &rectVolume);
                    }
                    
                    // While for Vertical LOGO effect
                    
                    while(rectLogo.y >= -260)
                    {
                        rectLogo.y -= 1;
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                        
                        SDL_RenderPresent(rendererPtr);
                    }
                    
                    // While for ZOOM IN effect
                    
                    while(rectBackground.h >= 250)
                    {
                        rectBackground.h = rectBackground.h - 1;
                        
                        rectBackground.w = rectBackground.w - 2;
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                        
                        SDL_RenderPresent(rendererPtr);
                        
                    }
                    
                    // Space Ship SHOWN
                    
                    while(rectSpaceShip.y <= 0)
                    {
                        rectSpaceShip.y = rectSpaceShip.y + 1;
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipTexture(), NULL, &rectSpaceShip);
                        
                        SDL_RenderPresent(rendererPtr);
                        
                        spaceShipHidden = false;
                    }
                    
                }
                
                // Button INFO
                
                if(xZ >= rectInfoButton.x && xZ <= 60 && yZ >= rectInfoButton.y && yZ <= 700)
                {
                    SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetInfoTexturePushed(), NULL, &rectInfoButton);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                    
                    SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                    
                    if(counterVolume == 0)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                    }
                    
                    if(counterVolume == 1)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL, &rectVolume);
                    }
                    
                    if(counterVolume == 2)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL, &rectVolume);
                    }
                    
                    if(counterVolume == 3)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL, &rectVolume);
                    }
                }
                
                // Button VOLUME MINUS
                
                if(xZ >= rectVolumeMinusButton.x && xZ <= 1080 && yZ >= rectVolumeMinusButton.y && yZ <= 680)
                {
                    counterVolume = counterVolume - 1;
                    
                    if(counterVolume <= 0)
                    {
                        counterVolume = 0;
                    }
                    
                    if(counterVolume == 0)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                    }
                    
                    if(counterVolume == 1)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButtonPushed(), NULL, &rectVolumeMinusButton);
                    }
                    
                    if(counterVolume == 2)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButtonPushed(), NULL, &rectVolumeMinusButton);
                    }
                    
                    if(counterVolume == 3)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButtonPushed(), NULL, &rectVolumeMinusButton);
                    }
                }
                
                // Button VOLUME PLUS
                
                if(xZ >= rectVolumePlusButton.x && xZ <= 1260 && yZ >= rectVolumePlusButton.y && yZ <= 680)
                {
                    counterVolume = counterVolume + 1;
                    
                    if(counterVolume >= 3)
                    {
                        counterVolume = 3;
                    }
                    
                    if(counterVolume == 0)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButtonPushed(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                    }
                    
                    if(counterVolume == 1)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButtonPushed(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                    }
                    
                    if(counterVolume == 2)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButtonPushed(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                    }
                    
                    if(counterVolume == 3)
                    {
                        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &rectLogo);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &rectInsertCredit);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &rectInfoButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL, &rectVolume);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButtonPushed(), NULL, &rectVolumePlusButton);
                        
                        SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &rectVolumeMinusButton);
                    }
                    
                    
                    
                }
                
            }
            
            SDL_RenderPresent(rendererPtr);
            
        }
    }
    
}

//

void LifeCycle:: QuitGame()
{
    
}
