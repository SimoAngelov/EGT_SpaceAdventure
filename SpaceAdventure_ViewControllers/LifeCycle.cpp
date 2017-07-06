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

//

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

//

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
    
    // Rect Background
    
    SDL_Rect rectBackground = createRect(0, 0, 1280, 720); // :)
    
    SDL_Event ev;
    
    // Load Textures
    
    Intro.SetBackgroundTexture(LoadTexture("background.png"));
    
    //
    
    bool quitCycle = false;
    
    while(quitCycle == false)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
            if(ev.type == SDL_QUIT)
            {
                quitCycle = true;
            }
            
            SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
            
            if(ev.type == SDL_MOUSEBUTTONDOWN)
            {
                rectBackground.x += 50;
                
                SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &rectBackground, NULL);
                
            }
            
            SDL_RenderPresent(rendererPtr);
            
        }
    }
    
}

//

void LifeCycle:: QuitGame()
{
    
}
