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
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

//#include "Controller1_Intro.hpp"
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>
#include <vector>

#include "Controller1_Intro.hpp"

#include "Controller2_GameController.hpp"

#include "Controller3_Slot.hpp"

#include "GameControllerLogic.hpp"

using namespace std;

class LifeCycle
{
    
private:
    
    const int m_nWidth = 1280; // Width WINDOW PROGRAM
    
    const int m_nHeight = 720; // Height WINDOW PROGRAM
    
    int m_nCredit = 0; // Game Credit
    
    int m_nLinesCounter = 1; // Lines Counter Game View 3
    
    SDL_Window* windowPtr = NULL;
    
    SDL_Renderer* rendererPtr = NULL;
    
    TTF_Font* Xanadu = NULL;
    
    SDL_Color color = {180,230,230,0};
    
    SDL_Surface* creditSurface = NULL;
    
    SDL_Texture* creditTexture = NULL;
    
    Mix_Chunk* introMusic = NULL;
    
    Mix_Chunk* buttonSound = NULL;
    
    Mix_Chunk* nextViewSound = NULL;
    
    Mix_Chunk* linesSound = NULL;
    
    vector<SDL_Texture*> m_vecSlotFigures;
    
    vector<SDL_Texture*>m_vecLines;

    
    
    
public:
    
    GameControllerLogic gameLogic;
    
    LifeCycle();
    
    //
    
    void InitMedia(); // To initialize EVERYTHING
    
    SDL_Texture* LoadTexture(string path); // To load Texture from PATH
    
    // Load and PREARE Textures
    
    void PrepareTextures();
    
    void CashOutAnimation();
    
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
