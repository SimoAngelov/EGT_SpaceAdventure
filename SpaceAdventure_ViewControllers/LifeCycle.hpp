//
//  LifeCycle.hpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 06/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#ifndef LifeCycle_hpp
#define LifeCycle_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Controller1_Intro.hpp"

#include "Controller2_GameController.hpp"

#include "Controller3_Slot.hpp"

using namespace std;

class LifeCycle
{
    
private:
    
    const int m_nWidth = 1280; // Width WINDOW PROGRAM
    
    const int m_nHeight = 720; // Height WINDOW PROGRAM
    
    int m_nCredit = 0; // Game Credit
    
    SDL_Window* windowPtr = NULL;
    
    SDL_Renderer* rendererPtr = NULL;
    
    TTF_Font* Xanadu = NULL;
    
    SDL_Color color = {180,230,230,0};
    
    SDL_Surface* creditSurface = NULL;
    
    SDL_Texture* creditTexture = NULL;
    
    
    
    
public:
    
    LifeCycle();
    
    //
    
    void InitMedia(); // To initialize EVERYTHING
    
    SDL_Texture* LoadTexture(string path); // To load Texture from PATH
    
    void Play(); // LifeCycle Program
    
    void QuitGame(); // To delete POINTERS and QUIT GAME
    
    //
    
    void SetCredit(int credit);
    
    //
    
    int GetCredit();
    
    SDL_Window* GetWindow();
    
    SDL_Renderer* GetRenderer();
    
    // OverLoad operator =
    
    SDL_Rect* operator = (SDL_Rect newObject)
    {
        SDL_Rect* object;
        
        object->x = newObject.x;
        
        object->y = newObject.y;
        
        object->w = newObject.w;
        
        object->h = newObject.h;
        
        return object;
    }
    
    // Func to construct rectangles
    
    SDL_Rect createRect(int x, int y, int w, int h)
    {
        SDL_Rect object;
        
        object.x = x;
        
        object.y = y;
        
        object.w = w;
        
        object.h = h;
        
        return object;
    }
    
    

};

#endif /* LifeCycle_hpp */
