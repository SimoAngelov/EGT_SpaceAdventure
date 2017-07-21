//
//  LifeCycle.hpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#ifndef LifeCycle_hpp
#define LifeCycle_hpp

// WINDOWS includes

//#include <iostream>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_mixer.h>
//#include <vector>

// MAC includes

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <vector>

#include "View1_Intro.hpp"
#include "View2_PayLines.hpp"
#include "View3_Slot.hpp"

// Struct for ALL Rects

typedef struct
{
    // Rects View 1 ->
    
    SDL_Rect rectBackground;
    
    SDL_Rect rectForwardButton;
    
    SDL_Rect rectLogo;
    
    SDL_Rect rectInsertCredit;
    
    SDL_Rect rectInfoButton;
    
    SDL_Rect rectVolume;
    
    SDL_Rect rectVolumePlusButton;
    
    SDL_Rect rectVolumeMinusButton;
    
    SDL_Rect rectSpaceShip;
    
    SDL_Rect rectSpaceShipButtonMinus;
    
    SDL_Rect rectSpaceShipButtonPlus;
    
    SDL_Rect rectSpaceShipButtonOk;
    
    SDL_Rect rectTextCredit;
    
    SDL_Rect rectRules;
    
    SDL_Rect rectCloseRulesButton;
    
    // Rects View 2 ->
    
    SDL_Rect rectBackButton;
    
    SDL_Rect rectTextCreditController2;
    
    SDL_Rect rectFirstLine;
    
    SDL_Rect rectSecondLine;
    
    SDL_Rect rectThirdLine;
    
    SDL_Rect rectFourthLine;
    
    SDL_Rect rectButtonPlay;
    
    // Rects View 3 ->
    
    SDL_Rect rectSlot;
    
    SDL_Rect rectMinusButtonLines;
    
    SDL_Rect rectPlusButtonLines;
    
    SDL_Rect rectMinusBetButton;
    
    SDL_Rect rectPlusBetButton;
    
    SDL_Rect rectMaxBetButton;
    
    SDL_Rect rectStartSpinButton;
    
    SDL_Rect rectCashOutButton;
    
    SDL_Rect rectWhiteScreen;
    
    // Rectangles for slot figures
    
    // Rectangles for FIRST row
    
    SDL_Rect rectFigure1Slot1;
    
    SDL_Rect rectFigure2Slot1;
    
    SDL_Rect rectFigure3Slot1;
    
    //Rectangles for SECOND row
    
    SDL_Rect rectFigure1Slot2;
    
    SDL_Rect rectFigure2Slot2;
    
    SDL_Rect rectFigure3Slot2;
    
    // Rectangles for THIRD row
    
    SDL_Rect rectFigure1Slot3;
    
    SDL_Rect rectFigure2Slot3;
    
    SDL_Rect rectFigure3Slot3;
    
    // Rectangles for FOURTH row
    
    SDL_Rect rectFigure1Slot4;
    
    SDL_Rect rectFigure2Slot4;
    
    SDL_Rect rectFigure3Slot4;
    
    //Rectangles for FIFTH row
    
    SDL_Rect rectFigure1Slot5;
    
    SDL_Rect rectFigure2Slot5;
    
    SDL_Rect rectFigure3Slot5;
    
} RectStruct;

class LifeCycle
{
    
private:
    
    const int m_nWidth = 1280; // Width WINDOW PROGRAM
    
    const int m_nHeight = 720; // Height WINDOW PROGRAM
    
    SDL_Window* windowPtr = NULL; // Window Pointer
    
    SDL_Renderer* rendererPtr = NULL; // Renderer Pointer
    
    TTF_Font* Xanadu = NULL; // Font -> "Xanadu.ttf"
    
    SDL_Color color = {180,230,230,0}; // Color -> Blue Cyan
    
    SDL_Surface* creditSurface = NULL; // Credit Surface (to texture)
    
    SDL_Texture* creditTexture = NULL; // Credit Texture
    
    Mix_Chunk* introMusic = NULL; // Intro Music
    
    Mix_Chunk* buttonSound = NULL; // Button Sound Effects
    
    Mix_Chunk* nextViewSound = NULL; // Next View Sound Effect
    
    Mix_Chunk* linesSound = NULL; // Lines Coming Sound Effect
    
    
    
    int m_nCredit = 0; // Game Credit
    
    int m_nLinesCounter = 1; // Lines Counter Game View 3
    
    
    
    vector<SDL_Texture*> m_vecSlotFigures; // Slot Figures Texture
    
    vector<SDL_Texture*>m_vecLines; // Slot Lines Texture
    
    vector<SDL_Texture*>vecAnimationCashOut; // Animation Cash Out Textures
    
    // Creating Objects
    
    Intro Intro;
    
    PayLines PayLines;
    
    Slot Slot;
    
    RectStruct Rect;
    
    // Logic Variables ->
    
    // Counter VIEW CONTROLLERS
    
    int counterViewControllers = 1;
    
    // Bool to quit LifeCycle
    
    bool quitCycle = false;
    
    // Bool SpaceShip is Hidden
    
    bool spaceShipHidden = true;
    
    // Bool OK SpaceShip Pushed
    
    bool okPushedSpaceShip = false;
    
    // Bool Credit Inserted
    
    bool creditInserted = false;
    
    // Counter Volume Music
    
    int counterVolume = 0;
    
    // Bool Info Texture SHOWN
    
    bool infoShown = false;
    
    // Credit TEXT (int to string)
    
    string creditText = "Insert Credit";
    
    // Mouse Coordinates xZ, yZ
    
    int xZ = 0;
    
    int yZ = 0;
    
    // Creating Object from SDL_EVENT
    
    SDL_Event ev;
    
public:
    
    LifeCycle();
    
    void InitMedia(); // Initialize Audio and Video, creating Window and Renderer...
    
    void Play(); // LIFECYCLE Program
    
    void QuitGame(); // Delete Memory and Free Pointers
    
    // Utility Methods ->
    
    SDL_Texture* LoadTexture(string path);
    
    SDL_Rect* operator = (SDL_Rect newObject) // Overload operator = To make Objects from SDL_Rect*
    {
        SDL_Rect* object;
        
        object->x = newObject.x;
        
        object->y = newObject.y;
        
        object->w = newObject.w;
        
        object->h = newObject.h;
        
        return object;
    }
    
    SDL_Rect createRect(int x, int y, int w, int h) // Method to construct Rectangles
    {
        SDL_Rect object;
        
        object.x = x;
        
        object.y = y;
        
        object.w = w;
        
        object.h = h;
        
        return object;
    }
    
    void PreparingTexturesView1(); // Loading Textures View 1
    
    void PreparingTexturesView2(); // Loading Textures View 2
    
    void PreparingTexturesView3(); // Loading Textures View 3
    
    void PreparingTexturesCashOutAnimation();
    
    void PreparingTextures(); // Loading all Textures
    
    void CashOutAnimation();
    
    void CreateRectsInStruct(); // Creating Rects in Struct
    
    void LoadMusic(); // Loading Music
    
    void PresentView1(); // Present View 1
    
};

#endif /* LifeCycle_hpp */
