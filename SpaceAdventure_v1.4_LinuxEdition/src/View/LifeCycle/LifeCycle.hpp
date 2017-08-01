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

//LINUX includes

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <map>

#include "../View1_Intro/View1_Intro.hpp"
#include "../View2_Paylines/View2_PayLines.hpp"
#include "../View3_Slot/View3_Slot.hpp"
#include "../View4_BonusGame/View4_BonusGame.hpp"
#include "../../Globals/Globals.h"
#include "../../Controller/IntroController/IntroController.h"
#include "../../Controller/GameController/GameController.h"
#include "../../Controller/GameRecovery/GameRecovery.h"
#include "../../Controller/BonusGameController/BonusGameController.h"


// Struct for ALL Rects

typedef struct
{
    // Rects View 1 ->
    
    SDL_Rect rectBackground;
    
    SDL_Rect rectForwardButton;
    
    SDL_Rect rectLogo;
    
    SDL_Rect rectInsertCredit;
    
    SDL_Rect rectLoadGame;
    
    SDL_Rect rectInfoButton;
    
    SDL_Rect rectPayTableButton;
    
    SDL_Rect rectVolume;
    
    SDL_Rect rectVolumePlusButton;
    
    SDL_Rect rectVolumeMinusButton;
    
    SDL_Rect rectSpaceShip;
    
    SDL_Rect rectSpaceShipButtonMinus;
    
    SDL_Rect rectSpaceShipButtonPlus;
    
    SDL_Rect rectSpaceShipButtonOk;
    
    SDL_Rect rectTextCredit;
    
    SDL_Rect rectRules;
    
    SDL_Rect rectPayTable;
    
    SDL_Rect rectCloseRulesButton;
    
    SDL_Rect rectClosePayTableButton;
    
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
    
    SDL_Rect rectFinalCreditText;
    
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
    
    // Info Panel
    
    SDL_Rect rectLinesText;
    
    SDL_Rect rectLinesShow;
    
    SDL_Rect rectBetText;
    
    SDL_Rect rectBetLabel;
    
    SDL_Rect rectTotalBetText;
    
    SDL_Rect rectGoodLuckText;
    
    SDL_Rect rectWinText;
    
    SDL_Rect rectWinningPayLinesLabel;
    
    SDL_Rect rectWinningPayLines;
    
    // View 4 Bonus Game ->
    
    SDL_Rect rectBackgroundBonusGame;
    
    SDL_Rect rectBlackButton;
    
    SDL_Rect rectRedButton;
    
    SDL_Rect rectCardTexture;
    
    SDL_Rect rectSelectText;
    
    SDL_Rect rectWinLose;
    
    SDL_Rect rectCloseButtonBonusGame;
    
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
    
    SDL_Color black = {0,0,0,0};
    
    SDL_Surface* creditSurface = NULL; // Credit Surface (to texture)
    
    SDL_Texture* creditTexture = NULL; // Credit Texture
    
    SDL_Surface* finalCredit = NULL; // Final Credit Surface (to texture)
    
    SDL_Texture* finalCreditTexture = NULL; // Final Credit Texture
    
    // Music and Chunk
    
    Mix_Chunk* introMusic = NULL; // Intro Music
    
    Mix_Chunk* buttonSound = NULL; // Button Sound Effects
    
    Mix_Chunk* nextViewSound = NULL; // Next View Sound Effect
    
    Mix_Chunk* stopReel = NULL; // Stopping Reels
    
    Mix_Chunk* startButtonSound = NULL; // Start Spinning Sound
    
    Mix_Chunk* viewSound = NULL; // Changing View Sound
    
    Mix_Chunk* lineSound = NULL; // Lines Sound
    
    Mix_Chunk* linesWin = NULL; // Lines WIN
    
    Mix_Chunk* bonusGameMusic = NULL; // Music Bonus Game
    
    
    // Information Table ->
    
    // Lines Info
    
    string linesLabelText = "LINES";
    
    string linesText = "";
    
    SDL_Surface* linesLabelSurface = NULL;
    
    SDL_Texture* linesLabelTexture = NULL;
    
    SDL_Surface* linesSurface = NULL;
    
    SDL_Texture* linesTextureText = NULL;
    
    // Bet Info
    
    int betCounter = 0;
    
    string betLabel = "BET";
    
    string betText = "1";
    
    SDL_Surface* betLabelSurface = NULL;
    
    SDL_Texture* betLabelTexture = NULL;
    
    SDL_Surface* betSurface = NULL;
    
    SDL_Texture* betTextureText = NULL;
    
    // Good Luck Panel
    
    string goodLuck = "";
    
    SDL_Surface* goodLuckSurface = NULL;
    
    SDL_Texture* goodLuckTextureText = NULL;
    
    // Total Bet Info
    
    int totalBetCalc = 1;
    
    string totalBetText = "1";
    
    SDL_Surface* totalBetSurface = NULL;
    
    SDL_Texture* totalBetTextureText = NULL;
    
    // Winning Paylines Label and Text
    
    string winningPaylinesLabel = "Winning PayLines- ";
    
    SDL_Surface* winningPayLinesSurface = NULL;
    
    SDL_Texture* winningPayLinesTexture = NULL;
    
    string winningPayLines;
    
    SDL_Surface* winningLinesSurface = NULL;
    
    SDL_Texture* winningLinesTexture = NULL;
    
    // Win Panel
    
    string win = "";
    
    SDL_Surface* winSurface = NULL;
    
    SDL_Texture* winTextureText = NULL;
    
    // Bonus Game
    
    string selectCardText = "Select RED / BLACK Button";
    
    SDL_Surface* selectCardSurface = NULL;
    
    SDL_Texture* selectCardTexture = NULL;
    
    
    int m_nCredit = 0; // Game Credit
    
    int m_nLinesCounter = 1; // Lines Counter Game View 3
    
    
    
    vector<SDL_Texture*> m_vecSlotFigures; // Slot Figures Texture
    
    vector<SDL_Texture*>m_vecLines; // Slot Lines Texture
    
    vector<SDL_Texture*>vecAnimationCashOut; // Animation Cash Out Textures
    
    vector<SDL_Texture*>m_vecCards; // Vector of Black And Red Cards;
    
    
    // Creating Objects
    
    View1_Intro Intro;
    
    View2_PayLines PayLines;
    
    View3_Slot Slot;
    
    View4_BonusGame ViewBonusGame;
    
    RectStruct Rect;
    
    // Logic Object
    
    IntroController introController;
    
    GameController gameController;
    
    GameRecovery gameRecovery;
    
    // Logic Variables ->
    
    // Counter VIEW CONTROLLERS
    
    int counterViewControllers = 1;
    
    // Bool to quit LifeCycle
    
    bool quitCycle = false;
    
    // Is Save Game, Existing XML FILE
    
    bool IsSaveGameExist = false;
    
    // Bool SpaceShip is Hidden
    
    bool spaceShipHidden = true;
    
    // Start Credit Menu Effect
    
    bool StartCreditMenuEffect = false;
    
    // Bool Present SpaceShip
    
    bool presentSpaceShip = false;
    
    // Bool OK SpaceShip Pushed
    
    bool okPushedSpaceShip = false;
    
    // Bool Credit Inserted
    
    bool creditInserted = false;
    
    // Counter Volume Music
    
    int counterVolume = 0;
    
    // Bool Info Texture SHOWN
    
    bool infoShown = false;
    
    // Bool PayTabe Texture SHOWN
    
    bool payTableShown = false;
    
    // Bool Hide Lines Texture In View 3
    
    bool startPressed = false;
    
    // Credit TEXT (int to string)
    
    string creditText = "Insert Credit";
    
    // Bool Is BonusGame Present
    
    bool IsBonusGamePresent = false;
    
    // Bool Presenting Bonus Game EFFECT
    
    bool PresentingBonusGameEffect = false;
    
    // Counter Red Black Bonus Game
    
    int CounterRedBlackPressed = 0;
    
    // Mouse Coordinates xZ, yZ
    
    int xZ = 0;
    
    int yZ = 0;
    
    // Logic Starting REELS Before Spin
    
    int row1fig1 = 0;
    int row1fig2 = 1;
    int row1fig3 = 2;
    int row2fig1 = 3;
    int row2fig2 = 4;
    int row2fig3 = 5;
    int row3fig1 = 6;
    int row3fig2 = 7;
    int row3fig3 = 8;
    int row4fig1 = 0;
    int row4fig2 = 1;
    int row4fig3 = 2;
    int row5fig1 = 3;
    int row5fig2 = 4;
    int row5fig3 = 5;
    
    // Creating Object from SDL_EVENT
    
    SDL_Event ev;
    
public:
    
    LifeCycle();
    
    //
    
    void InitMedia(); // Initialize Audio and Video, creating Window and Renderer...
    
    void Play(); // LIFECYCLE Program
    
    void QuitGame(); // Delete Memory and Free Pointers
    
    // Buttons Methods ->
    
    // View 1
    
    bool IsInsertCreditPressed(int x, int y);
    
    bool IsLoadGamePressed(int x, int y);
    
    bool IsInfoPressed(int x, int y);
    
    bool IsPayTablePressed(int x, int y);
    
    bool IsCloseRulesPressed(int x, int y);
    
    bool IsClosePayTablePressed(int x, int y);
    
    bool IsVolumePlusPressed(int x, int y);
    
    bool IsVolumeMinusPressed(int x, int y);
    
    bool IsForwardPressed(int x, int y);
    
    // View SpaceShip
    
    bool IsShipVolumeMinusPressed(int x, int y);
    
    bool IsShipOkPressed(int x, int y);
    
    bool IsShipVolumePlusPressed(int x, int y);
    
    // View 2
    
    bool IsBackPressed(int x, int y);
    
    bool IsPlayPressed(int x, int y);
    
    // View 3
    
    bool IsStartSpinPressed(int x, int y);
    
    bool IsMinusLinesPressed(int x, int y);
    
    bool IsPlusLinesPressed(int x, int y);
    
    bool IsMinusBetPressed(int x, int y);
    
    bool IsPlusBetPressed(int x, int y);
    
    bool IsMaxBetPressed(int x, int y);
    
    bool IsCashOutPressed(int x, int y);
    
    // View 4
    
    bool IsRedPressed(int x, int y);
    
    bool IsBlackPressed(int x, int y);
    
    bool IsCloseBonusGamePressed(int x, int y);
    
    
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
    
    void PreparingTexturesView4(); // Loading Texture View 4
    
    void PreparingTexturesCashOutAnimation(); // Preparing Cash Out Texture;
    
    void PreparingTextures(); // Loading all Textures
    
    void CreateRectsInStruct(); // Creating Rects in Struct
    
    void ShowGameRules(); // Rules Texture Coming
    
    void HideGameRules(); // Hide Texture Rules
    
    void ShowPayTable(); // PayTable Coming
    
    void HidePayTable(); // Hide PayTable
    
    void RefreshFromBackup(bool IsGameSaved); // Checking if file XML Exist and Recover The Game
    
    void InitializingReel(); // Initialize Reels and TTFs info Menu
    
    void LoadMusic(); // Loading Music
    
    void PresentView1(); // Present View 1
    
    void CreditMenu(bool spaceShipHidden); // Effect Credit Menu
    
    void PresentCreditMenu(bool presentSpaceShip);
    
    void CreditMenuZoomOut(bool okPushed); // Effect Credit Menu Zoom Out
    
    void PassingToView2(); // Passing to View 2 Animation
    
    void PresentView2(); // Present View 2
    
    void LinesEffectComing(); // Effect Lines View 2 Coming
    
    void BackToView1(); // Effects Lines View 2 Gone and Back to View 1
    
    void PassingToView3(); // Effects Lines 1,2,3,4 View 2 GONE and Slot View 3 Coming
    
    void PresentView3(); // Presenting View 3
    
    void WinningLines();
    
    void SpinningReels(); // Spinning REELS
    
    void CashOutAnimation(); // Cash Out Animation
    
    void WhiteScreenAndCashOutAnimation(); // FULL ANIMATION Cash Out
    
    void PresentView4(); // Present View 4 BonusGame
    
    void PresentingBonusGame(bool IsBonusGamePresent); // Showing View 4
    
    void HideBonusGame(bool IsBonusGamePresent); // Hide View 4
    
    void WinBonusGame(); // Check if we have a WIN
    
};

#endif /* LifeCycle_hpp */
