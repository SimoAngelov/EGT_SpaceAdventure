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

#include <SDL2_image/SDL_image.h>

#include "Controller1_Intro.hpp"

using namespace std;

class LifeCycle
{
    
private:
    
    const int m_nWidth = 1280; // Width WINDOW PROGRAM
    
    const int m_nHeight = 720; // Height WINDOW PROGRAM
    
    SDL_Window* windowPtr = NULL;
    
    SDL_Renderer* rendererPtr = NULL;
    
    
public:
    
    LifeCycle();
    
    //
    
    void InitMedia(); // INITIALIZING EVERYTHING
    
    SDL_Texture* LoadTexture(string path); // LOADING TEXTURE FROM THE PATH
    
    void Play(); // LIFECYCLE PROGRAM
    
    void QuitGame(); // DELETING POINTERS AND QUITING THE GAME
    
    //
    
    SDL_Window* GetWindow();
    
    SDL_Renderer* GetRenderer();
    
    // OVERLOADED OPERATOR (=)
    
    SDL_Rect* operator = (SDL_Rect newObject)
    {
        SDL_Rect* object;
        
        object->x = newObject.x;
        
        object->y = newObject.y;
        
        object->w = newObject.w;
        
        object->h = newObject.h;
        
        return object;
    }
    
    // FUNCTION FOR CREATING RECTANGLES
    
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
