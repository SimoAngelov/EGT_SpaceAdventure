//
//  LifeCycle.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "LifeCycle.hpp"

LifeCycle::LifeCycle()
{
    
}

// Initialize Audio and Video, creating Window, Renderer and FONT...

void LifeCycle:: InitMedia()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        cerr << "Problem to INITIALIZE MEDIA" << endl;
    }
    else
    {
        windowPtr = SDL_CreateWindow("Space Adventure" ,SDL_WINDOWPOS_CENTERED ,SDL_WINDOWPOS_CENTERED , m_nWidth, m_nHeight, SDL_WINDOW_SHOWN);
        
        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            cerr << "Problem to load AUDIO" << endl;
        }
        
        if(windowPtr == NULL)
        {
            cerr << "Problem to CREATE WINDOW" << endl;
        }
        else
        {
            rendererPtr = SDL_CreateRenderer(windowPtr, -1, SDL_RENDERER_ACCELERATED);
            
            if (rendererPtr == NULL)
            {
                cerr << "Problem to CREATE RENDERER" << endl;
            }
            
            TTF_Init(); // Initalize TTF
            
            Xanadu = TTF_OpenFont("Xanadu.ttf", 30);
            
            if (Xanadu == NULL)
            {
                cerr << "Problem to OPEN FONT" << endl;
            }
        }
    }
}

// Load Texture from PATH

SDL_Texture* LifeCycle:: LoadTexture(string path)
{
    SDL_Texture* textureToReturn = NULL;
    
    textureToReturn = IMG_LoadTexture(rendererPtr, path.c_str());
    
    if (textureToReturn == NULL)
    {
        cerr << "Problem to load TEXTURE -> " << path << endl;
    }
    
    return textureToReturn;
}

// Loading Textures View 1

void LifeCycle:: PreparingTexturesView1()
{
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
    
    Intro.SetSpaceShipButtonMinusPushed(LoadTexture("spaceShipButtonMinusPushed.png"));
    
    Intro.SetSpaceShipButtonOk(LoadTexture("okButton.png"));
    
    Intro.SetSpaceShipButtonOkPushed(LoadTexture("okButtonPushed.png"));
        
    Intro.SetRulesTexture(LoadTexture("rules.png"));
        
    Intro.SetCloseRulesButton(LoadTexture("closeButton.png"));
    
    creditSurface = TTF_RenderText_Solid(Xanadu, creditText.c_str(), color);
    
    creditTexture = SDL_CreateTextureFromSurface(rendererPtr, creditSurface);
}

// Loading Textures View 2

void LifeCycle:: PreparingTexturesView2()
{
    PayLines.SetBackButtonTexture(LoadTexture("left.png"));
    
    PayLines.SetFirstRow(LoadTexture("linesFirstLine.png"));
    
    PayLines.SetSecondRow(LoadTexture("linesSecondLine.png"));
    
    PayLines.SetThirdRow(LoadTexture("linesThirdLine.png"));
    
    PayLines.SetFourthRow(LoadTexture("linesFourthLine.png"));
    
    PayLines.SetPlayButtonTexture(LoadTexture("play.png"));
    
    PayLines.SetPlayButtonTexturePushed(LoadTexture("playPushed.png"));
}

// Loading Textures View 3

void LifeCycle:: PreparingTexturesView3()
{
    Slot.SetSlotTexture(LoadTexture("currentReel.png"));
    
    Slot.SetMinusButtonLines(LoadTexture("minusReel.png"));
    
    Slot.SetPlusLinesButton(LoadTexture("plusReel.png"));

    Slot.SetPlusLinesButtonPushed(LoadTexture("plusReelPushed.png"));
    
    Slot.SetMinusButtonLinesPushed(LoadTexture("minusReelPushed.png"));
    
    Slot.SetMinusButtonBet(LoadTexture("minusReel.png"));
    
    Slot.SetMinusButtonBetPushed(LoadTexture("minusReelPushed.png"));
    
    Slot.SetPlusButtonBet(LoadTexture("plusReel.png"));
    
    Slot.SetPlusButtonBetPushed(LoadTexture("plusReelPushed.png"));
    
    Slot.SetMaxBetButton(LoadTexture("maxBet.png"));
    
    Slot.SetMaxBetButtonPushed(LoadTexture("maxBetPushed.png"));
    
    Slot.SetStartSpinButton(LoadTexture("startSpin1.png"));
    
    Slot.SetStartSpinButtonPushed(LoadTexture("startSpinPushed.png"));
    
    Slot.SetWhiteScreenTexture(LoadTexture("whiteScreen.png"));
    
    Slot.SetFigure1(LoadTexture("figure1.png"));
    
    Slot.SetFigure2(LoadTexture("figure2.png"));
    
    Slot.SetFigure3(LoadTexture("figure3.png"));
    
    Slot.SetFigure4(LoadTexture("figure4.png"));
    
    Slot.SetFigure5(LoadTexture("figure5.png"));
    
    Slot.SetFigure6(LoadTexture("figure6.png"));
    
    Slot.SetFigure7(LoadTexture("figure7.png"));
        
    Slot.SetFigure8(LoadTexture("figure8.png"));
        
    Slot.SetFigure9(LoadTexture("figure9.png"));
}

// Loading Textures Cash Out Animation

void LifeCycle:: PreparingTexturesCashOutAnimation()
{
    SDL_Texture* texture1 = IMG_LoadTexture(rendererPtr, "1.png");
    SDL_Texture* texture2 = IMG_LoadTexture(rendererPtr, "2.png");
    SDL_Texture* texture3 = IMG_LoadTexture(rendererPtr, "3.png");
    SDL_Texture* texture4 = IMG_LoadTexture(rendererPtr, "4.png");
    SDL_Texture* texture5 = IMG_LoadTexture(rendererPtr, "5.png");
    SDL_Texture* texture6 = IMG_LoadTexture(rendererPtr, "6.png");
    SDL_Texture* texture7 = IMG_LoadTexture(rendererPtr, "7.png");
    SDL_Texture* texture8 = IMG_LoadTexture(rendererPtr, "8.png");
    SDL_Texture* texture9 = IMG_LoadTexture(rendererPtr, "9.png");
    SDL_Texture* texture10 = IMG_LoadTexture(rendererPtr, "10.png");
    SDL_Texture* texture11 = IMG_LoadTexture(rendererPtr, "11.png");
    SDL_Texture* texture12 = IMG_LoadTexture(rendererPtr, "12.png");
    SDL_Texture* texture13 = IMG_LoadTexture(rendererPtr, "13.png");
    SDL_Texture* texture14 = IMG_LoadTexture(rendererPtr, "14.png");
    SDL_Texture* texture15 = IMG_LoadTexture(rendererPtr, "15.png");
    SDL_Texture* texture16 = IMG_LoadTexture(rendererPtr, "16.png");
    SDL_Texture* texture17 = IMG_LoadTexture(rendererPtr, "17.png");
    SDL_Texture* texture18 = IMG_LoadTexture(rendererPtr, "18.png");
    SDL_Texture* texture19 = IMG_LoadTexture(rendererPtr, "19.png");
    SDL_Texture* texture20 = IMG_LoadTexture(rendererPtr, "20.png");
    SDL_Texture* texture21 = IMG_LoadTexture(rendererPtr, "21.png");
    SDL_Texture* texture22 = IMG_LoadTexture(rendererPtr, "22.png");
    SDL_Texture* texture23 = IMG_LoadTexture(rendererPtr, "23.png");
    SDL_Texture* texture24 = IMG_LoadTexture(rendererPtr, "24.png");
    SDL_Texture* texture25 = IMG_LoadTexture(rendererPtr, "25.png");
    SDL_Texture* texture26 = IMG_LoadTexture(rendererPtr, "26.png");
    SDL_Texture* texture27 = IMG_LoadTexture(rendererPtr, "27.png");
    SDL_Texture* texture28 = IMG_LoadTexture(rendererPtr, "28.png");
    SDL_Texture* texture29 = IMG_LoadTexture(rendererPtr, "29.png");
    SDL_Texture* texture30 = IMG_LoadTexture(rendererPtr, "30.png");
    SDL_Texture* texture31 = IMG_LoadTexture(rendererPtr, "31.png");
    SDL_Texture* texture32 = IMG_LoadTexture(rendererPtr, "32.png");
    SDL_Texture* texture33 = IMG_LoadTexture(rendererPtr, "33.png");
    SDL_Texture* texture34 = IMG_LoadTexture(rendererPtr, "34.png");
    SDL_Texture* texture35 = IMG_LoadTexture(rendererPtr, "35.png");
    SDL_Texture* texture36 = IMG_LoadTexture(rendererPtr, "36.png");
    SDL_Texture* texture37 = IMG_LoadTexture(rendererPtr, "37.png");
    SDL_Texture* texture38 = IMG_LoadTexture(rendererPtr, "38.png");
    SDL_Texture* texture39 = IMG_LoadTexture(rendererPtr, "39.png");
    SDL_Texture* texture40 = IMG_LoadTexture(rendererPtr, "40.png");
    SDL_Texture* texture41 = IMG_LoadTexture(rendererPtr, "41.png");
    SDL_Texture* texture42 = IMG_LoadTexture(rendererPtr, "42.png");
    SDL_Texture* texture43 = IMG_LoadTexture(rendererPtr, "43.png");
    SDL_Texture* texture44 = IMG_LoadTexture(rendererPtr, "44.png");
    SDL_Texture* texture45 = IMG_LoadTexture(rendererPtr, "45.png");
    SDL_Texture* texture46 = IMG_LoadTexture(rendererPtr, "46.png");
    SDL_Texture* texture47 = IMG_LoadTexture(rendererPtr, "47.png");
    SDL_Texture* texture48 = IMG_LoadTexture(rendererPtr, "48.png");
    SDL_Texture* texture49 = IMG_LoadTexture(rendererPtr, "49.png");
    SDL_Texture* texture50 = IMG_LoadTexture(rendererPtr, "50.png");
    SDL_Texture* texture51 = IMG_LoadTexture(rendererPtr, "51.png");
    SDL_Texture* texture52 = IMG_LoadTexture(rendererPtr, "52.png");
    SDL_Texture* texture53 = IMG_LoadTexture(rendererPtr, "53.png");
    SDL_Texture* texture54 = IMG_LoadTexture(rendererPtr, "54.png");
    SDL_Texture* texture55 = IMG_LoadTexture(rendererPtr, "55.png");
    SDL_Texture* texture56 = IMG_LoadTexture(rendererPtr, "56.png");
    SDL_Texture* texture57 = IMG_LoadTexture(rendererPtr, "57.png");
    SDL_Texture* texture58 = IMG_LoadTexture(rendererPtr, "58.png");
    SDL_Texture* texture59 = IMG_LoadTexture(rendererPtr, "59.png");
    SDL_Texture* texture60 = IMG_LoadTexture(rendererPtr, "60.png");
    SDL_Texture* texture61 = IMG_LoadTexture(rendererPtr, "61.png");
    SDL_Texture* texture62 = IMG_LoadTexture(rendererPtr, "62.png");
    SDL_Texture* texture63 = IMG_LoadTexture(rendererPtr, "63.png");
    SDL_Texture* texture64 = IMG_LoadTexture(rendererPtr, "64.png");
    SDL_Texture* texture65 = IMG_LoadTexture(rendererPtr, "65.png");
    SDL_Texture* texture66 = IMG_LoadTexture(rendererPtr, "66.png");
    SDL_Texture* texture67 = IMG_LoadTexture(rendererPtr, "67.png");
    SDL_Texture* texture68 = IMG_LoadTexture(rendererPtr, "68.png");
    SDL_Texture* texture69 = IMG_LoadTexture(rendererPtr, "69.png");
    SDL_Texture* texture70 = IMG_LoadTexture(rendererPtr, "70.png");
    SDL_Texture* texture71 = IMG_LoadTexture(rendererPtr, "71.png");
    SDL_Texture* texture72 = IMG_LoadTexture(rendererPtr, "72.png");
    SDL_Texture* texture73 = IMG_LoadTexture(rendererPtr, "73.png");
    SDL_Texture* texture74 = IMG_LoadTexture(rendererPtr, "74.png");
    SDL_Texture* texture75 = IMG_LoadTexture(rendererPtr, "75.png");
    SDL_Texture* texture76 = IMG_LoadTexture(rendererPtr, "76.png");
    SDL_Texture* texture77 = IMG_LoadTexture(rendererPtr, "77.png");
    SDL_Texture* texture78 = IMG_LoadTexture(rendererPtr, "78.png");
    SDL_Texture* texture79 = IMG_LoadTexture(rendererPtr, "79.png");
    SDL_Texture* texture80 = IMG_LoadTexture(rendererPtr, "80.png");
    SDL_Texture* texture81 = IMG_LoadTexture(rendererPtr, "81.png");
    SDL_Texture* texture82 = IMG_LoadTexture(rendererPtr, "82.png");
    SDL_Texture* texture83 = IMG_LoadTexture(rendererPtr, "83.png");
    SDL_Texture* texture84 = IMG_LoadTexture(rendererPtr, "84.png");
    SDL_Texture* texture85 = IMG_LoadTexture(rendererPtr, "85.png");
    SDL_Texture* texture86 = IMG_LoadTexture(rendererPtr, "86.png");
    SDL_Texture* texture87 = IMG_LoadTexture(rendererPtr, "87.png");
    SDL_Texture* texture88 = IMG_LoadTexture(rendererPtr, "88.png");
    SDL_Texture* texture89 = IMG_LoadTexture(rendererPtr, "89.png");
    SDL_Texture* texture90 = IMG_LoadTexture(rendererPtr, "90.png");
    SDL_Texture* texture91 = IMG_LoadTexture(rendererPtr, "91.png");
    SDL_Texture* texture92 = IMG_LoadTexture(rendererPtr, "92.png");
    
    vecAnimationCashOut = {texture1,texture2,texture3,texture4,texture5,texture6,texture7,texture8,texture9,texture10,texture11,texture12,texture13,texture14,texture15,texture16,texture17,texture18,texture19,texture20,texture21,texture22,texture23,texture24,texture25,texture26,texture27,texture28,texture29,texture30,texture31,texture32,texture33,texture34,texture35,texture36,texture37,texture38,texture39,texture40,texture41,texture42,texture43,texture44,texture45,texture46,texture47,texture48,texture49,texture50,texture51,texture52,texture53,texture54,texture55,texture56,texture57,texture58,texture59,texture60,texture61,texture62,texture63,texture64,texture64,texture65,texture66,texture67,texture68,texture69,texture70,texture71,texture72,texture73,texture74,texture75,texture76,texture77,texture78,texture79,texture80,texture81,texture82,texture83,texture84,texture85,texture86,texture87,texture88,texture89,texture90,texture91,texture92};
}



// Loading all Textures

void LifeCycle:: PreparingTextures()
{
    PreparingTexturesView1();
    
    PreparingTexturesView2();
    
    PreparingTexturesView3();
    
    PreparingTexturesCashOutAnimation();
}

// Cash Out Animation

void LifeCycle:: CashOutAnimation()
{
    bool animationFinished = false;
    
    int counterTextures = 0;
    
    SDL_RenderCopy(rendererPtr, vecAnimationCashOut[counterTextures], NULL, NULL);
    
    SDL_RenderPresent(rendererPtr);
    
    SDL_Delay(50);
    
    counterTextures++;
    
    if(counterTextures > 91)
    {
        while(animationFinished == false)
        {
            
            SDL_RenderCopy(rendererPtr, vecAnimationCashOut[counterTextures], NULL, NULL);
            
            SDL_RenderPresent(rendererPtr);
            
            SDL_Delay(50);
            
            counterTextures--;
            
            if(counterTextures < 0)
            {
                animationFinished = true;
            }
        }
        
    }
}

// Struct for ALL Rects

void LifeCycle:: CreateRectsInStruct()
{
    // Rects View 1 ->
    
    Rect.rectBackground = createRect(0, 0, 1280, 720);
    
    Rect.rectForwardButton = createRect(650, 570, 200, 150);
    
    Rect.rectBackButton = createRect(400, 570, 200, 150);
    
    Rect.rectLogo = createRect(400, 10, 500, 250);
    
    Rect.rectInsertCredit = createRect(450, 460, 450, 130);
    
    Rect.rectInfoButton = createRect(10, 650, 50, 50);
    
    Rect.rectVolume = createRect(1200, 670, 50, 50);
    
    Rect.rectVolumePlusButton = createRect(1250, 685, 25, 25);
    
    Rect.rectVolumeMinusButton = createRect(1170, 685, 25, 25);
    
    Rect.rectSpaceShip = createRect(0, -500, 1280, 500);
    
    Rect.rectSpaceShipButtonMinus = createRect(225, 400, 100, 100);
    
    Rect.rectSpaceShipButtonPlus = createRect(970, 400, 100, 100);
    
    Rect.rectSpaceShipButtonOk = createRect(570, 360, 150, 150);
    
    Rect.rectTextCredit = createRect(365, 75, 550, 150);
    
    Rect.rectRules = createRect(0, -650, 1280, 650);
    
    Rect.rectCloseRulesButton = createRect(1200, -630, 50, 50);
    
    // Rects View 2 ->
    
    Rect.rectBackButton = createRect(400, 570, 200, 150);
    
    Rect.rectTextCreditController2 = createRect(1290, 650, 200, 50);
    
    Rect.rectFirstLine = createRect(100, -150, 1080, 150);
    
    Rect.rectSecondLine = createRect(110, -150, 1060, 170);
    
    Rect.rectThirdLine = createRect(90, -150, 1110, 170);
    
    Rect.rectFourthLine = createRect(320, -150, 650, 170);
    
    Rect.rectButtonPlay = createRect(860, 580, 140, 140);
    
    // Rects View 3 ->
    
    Rect.rectSlot = createRect(720, 720, 1280, 650);
    
    Rect.rectMinusButtonLines = createRect(300, 595, 40, 40);
    
    Rect.rectPlusButtonLines = createRect(435, 595, 40, 40);
    
    Rect.rectMinusBetButton = createRect(505, 595, 40, 40);
    
    Rect.rectPlusBetButton = createRect(670, 595, 40, 40);
    
    Rect.rectMaxBetButton = createRect(730, 585, 60, 60);
    
    Rect.rectStartSpinButton = createRect(1100, 540, 120, 120);
    
    Rect.rectCashOutButton = createRect(10, 540, 270, 100);
    
    Rect.rectWhiteScreen = createRect(0, -730, 1280, 720);
    
    // Rects for Slot figures
    
    // Rectangles for FIRST row
    
    Rect.rectFigure1Slot1 = createRect(170, 123, 105, 110);
    
    Rect.rectFigure2Slot1 = createRect(170, 270, 105, 110);
    
    Rect.rectFigure3Slot1 = createRect(170, 413, 105, 110);
    
    // Rectangles for SECOND row
    
    Rect.rectFigure1Slot2 = createRect(370, 123, 105, 110);
    
    Rect.rectFigure2Slot2 = createRect(370, 270, 105, 110);
    
    Rect.rectFigure3Slot2 = createRect(370, 413, 105, 110);
    
    // Rectangles for THIRD row
    
    Rect.rectFigure1Slot3 = createRect(570, 123, 105, 110);
    
    Rect.rectFigure2Slot3 = createRect(570, 270, 105, 110);
    
    Rect.rectFigure3Slot3 = createRect(570, 413, 105, 110);
    
    // Rectangles for FOURTH row
    
    Rect.rectFigure1Slot4 = createRect(790, 123, 105, 110);
    
    Rect.rectFigure2Slot4 = createRect(790, 270, 105, 110);
    
    Rect.rectFigure3Slot4 = createRect(790, 413, 105, 110);
    
    //Rectangles for FIFTH row
    
    Rect.rectFigure1Slot5 = createRect(1020, 123, 105, 110);
    
    Rect.rectFigure2Slot5 = createRect(1020, 270, 105, 110);
    
    Rect.rectFigure3Slot5 = createRect(1020, 413, 105, 110);
    

}

// Load Music

void LifeCycle:: LoadMusic()
{
    introMusic = Mix_LoadWAV("intro.wav");
    
    buttonSound = Mix_LoadWAV("soundButton.wav");
    
    nextViewSound = Mix_LoadWAV("nextView.wav");
    
    linesSound = Mix_LoadWAV("linesSound.wav");
    
    if(introMusic || buttonSound || nextViewSound || linesSound == NULL)
    {
        cerr << "Problem to LOAD MUSIC" << endl;
    }
}

// Present View 1

void LifeCycle:: PresentView1()
{
    
    Mix_PlayChannel(-1, introMusic, 2);
    
    SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),&Rect.rectBackground , NULL);
    
    SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &Rect.rectLogo);
    
    SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &Rect.rectInsertCredit);
    
    SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &Rect.rectInfoButton);
    
    SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &Rect.rectForwardButton);
    
    SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &Rect.rectVolumePlusButton);
    
    SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &Rect.rectVolumeMinusButton);
    
    if (counterVolume == 0)
    {
        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL, &Rect.rectVolume);
    }
    if (counterVolume == 1)
    {
        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL, &Rect.rectVolume);
    }
    if (counterVolume == 2)
    {
        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL, &Rect.rectVolume);
    }
    if (counterVolume == 3)
    {
        SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL, &Rect.rectVolume);
    }
    
}

// Play While LifeCycle

void LifeCycle:: Play()
{
    InitMedia();
    
    PreparingTextures();
    
    CreateRectsInStruct();
    
    LoadMusic();
    
    while(quitCycle == false)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
            if(ev.type == SDL_QUIT)
            {
                quitCycle = true;
            }
            
            SDL_GetMouseState(&xZ, &yZ);
            
            PresentView1();
            
            SDL_RenderPresent(rendererPtr);
            
        }
    }
}


