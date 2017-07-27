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
    
    Intro.SetLoadGameTexture(LoadTexture("loadGame.png"));
    
    Intro.SetLoadGamePushedTexture(LoadTexture("loadGamePushed.png"));
    
    Intro.SetFileNotFoundTexture(LoadTexture("fileNotFound.png"));
    
    Intro.SetInfoTexture(LoadTexture("infoButton.png"));
    
    Intro.SetInfoTexturePushed(LoadTexture("infoButtonPushed.png"));
    
    Intro.SetPayTableTexture(LoadTexture("payTable.png"));
    
    Intro.SetPayTableTexturePushed(LoadTexture("payTablePushed.png"));
    
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
    
    Intro.SetClosePayTableButton(LoadTexture("closeButton.png"));
    
    Intro.SetPayTableTextureInfo(LoadTexture("figureWeight.png"));

}

// Loading Textures View 2

void LifeCycle:: PreparingTexturesView2()
{
    PayLines.SetBackButtonTexture(LoadTexture("left.png"));
    
    PayLines.SetBackButtonTexturePushed(LoadTexture("leftPushed.png"));
    
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
    
    Slot.SetCashOutButton(LoadTexture("cashOut.png"));
    
    Slot.SetCashOutButtonPushed(LoadTexture("cashOutPushed.png"));
    
    // Loading Textures in Vector - FIGURES REEL
    
    m_vecSlotFigures = {Slot.GetFigure1(),Slot.GetFigure2(),Slot.GetFigure3(),Slot.GetFigure4(),Slot.GetFigure5(),Slot.GetFigure6(),Slot.GetFigure7(),Slot.GetFigure8(),Slot.GetFigure9()};
    
    Slot.SetLine1(LoadTexture("line1.png"));
    
    Slot.SetLine2(LoadTexture("line2.png"));
    
    Slot.SetLine3(LoadTexture("line3.png"));
    
    Slot.SetLine4(LoadTexture("line4.png"));
    
    Slot.SetLine5(LoadTexture("line5.png"));
    
    Slot.SetLine6(LoadTexture("line6.png"));
    
    Slot.SetLine7(LoadTexture("line7.png"));
    
    Slot.SetLine8(LoadTexture("line8.png"));
    
    Slot.SetLine9(LoadTexture("line9.png"));
    
    Slot.SetLine10(LoadTexture("line10.png"));
    
    Slot.SetLine11(LoadTexture("line11.png"));
    
    Slot.SetLine12(LoadTexture("line12.png"));
    
    Slot.SetLine13(LoadTexture("line13.png"));
    
    Slot.SetLine14(LoadTexture("line14.png"));
    
    Slot.SetLine15(LoadTexture("line15.png"));
    
    Slot.SetLine16(LoadTexture("line16.png"));
    
    Slot.SetLine17(LoadTexture("line17.png"));
    
    Slot.SetLine18(LoadTexture("line18.png"));
    
    Slot.SetLine19(LoadTexture("line19.png"));
    
    Slot.SetLine20(LoadTexture("line20.png"));
    
    Slot.SetLine21(LoadTexture("line21.png"));
    
    Slot.SetLine22(LoadTexture("line22.png"));
    
    Slot.SetLine23(LoadTexture("line23.png"));
    
    Slot.SetLine24(LoadTexture("line24.png"));
    
    Slot.SetLine25(LoadTexture("line25.png"));
    
    // Loading Textures in Vector LINES
    
    m_vecLines =
    
    {	Slot.GetSlotTexture(),Slot.GetLine1(), Slot.GetLine2(), Slot.GetLine3(), Slot.GetLine4(),
        Slot.GetLine5(), Slot.GetLine6(), Slot.GetLine7(), Slot.GetLine8(),
        Slot.GetLine9(),Slot.GetLine10(),Slot.GetLine11(), Slot.GetLine12(),
        Slot.GetLine13(),Slot.GetLine14(),Slot.GetLine15(),Slot.GetLine16(),
        Slot.GetLine17(),Slot.GetLine18(),Slot.GetLine19(),Slot.GetLine20(),
        Slot.GetLine21(),Slot.GetLine22(),Slot.GetLine23(),Slot.GetLine24(),
        Slot.GetLine25()
    };
    
     //Create Surface - Texture Info Table
    
    
    linesSurface = TTF_RenderText_Solid(Xanadu, gameController.NumberOfLinesAsString().c_str(), color);
    
    linesLabelSurface = TTF_RenderText_Solid(Xanadu, linesLabelText.c_str(), color);
    
    betLabelSurface = TTF_RenderText_Solid(Xanadu, betLabel.c_str(), color);
    
    betSurface = TTF_RenderText_Solid(Xanadu, gameController.BetPerLineAsString().c_str(), color);
    
    totalBetSurface = TTF_RenderText_Solid(Xanadu, gameController.TotalBetAsString().c_str(), color);
    
    creditSurface = TTF_RenderText_Solid(Xanadu, gameController.CreditsAsString().c_str(), color);
    
    winningPayLinesSurface = TTF_RenderText_Solid(Xanadu, winningPaylinesLabel.c_str(), color);
    
    winningLinesSurface = TTF_RenderText_Solid(Xanadu, winningPayLines.c_str(), color);
    
    linesTextureText = SDL_CreateTextureFromSurface(rendererPtr, linesSurface);
    
    linesLabelTexture = SDL_CreateTextureFromSurface(rendererPtr, linesLabelSurface);
    
    betLabelTexture = SDL_CreateTextureFromSurface(rendererPtr, betLabelSurface);
    
    betTextureText = SDL_CreateTextureFromSurface(rendererPtr, betSurface);
    
    totalBetTextureText = SDL_CreateTextureFromSurface(rendererPtr, totalBetSurface);
    
    creditTexture = SDL_CreateTextureFromSurface(rendererPtr, creditSurface);
    
    winningPayLinesTexture = SDL_CreateTextureFromSurface(rendererPtr, winningPayLinesSurface);
    
    winningLinesTexture = SDL_CreateTextureFromSurface(rendererPtr, winningLinesSurface);

    
    
}

void LifeCycle:: PreparingTexturesView4() // View 4 Bonus Game ->
{
    
    ViewBonusGame.SetBackgroundBonusGame(LoadTexture("backgroundBonusGame.png"));
    
    ViewBonusGame.SetRedButton(LoadTexture("redButton.png"));
    
    ViewBonusGame.SetBlackButton(LoadTexture("blackButton.png"));
    
    ViewBonusGame.SetCardTexture(LoadTexture("cardBack.png"));
    
    ViewBonusGame.SetBlackButtonPushed(LoadTexture("blackButtonPushed.png"));
    
    ViewBonusGame.SetRedButtonPushed(LoadTexture("redButtonPushed.png"));
    
    ViewBonusGame.SetRedCard1(LoadTexture("red1.png"));
    
    ViewBonusGame.SetRedCard2(LoadTexture("red2.png"));
    
    ViewBonusGame.SetRedCard3(LoadTexture("red3.png"));
    
    ViewBonusGame.SetRedCard4(LoadTexture("red4.png"));
    
    ViewBonusGame.SetRedCard5(LoadTexture("red5.png"));
    
    ViewBonusGame.SetBlackCard1(LoadTexture("black1.png"));
    
    ViewBonusGame.SetBlackCard2(LoadTexture("black2.png"));
    
    ViewBonusGame.SetBlackCard3(LoadTexture("black3.png"));
    
    ViewBonusGame.SetBlackCard4(LoadTexture("black4.png"));
    
    ViewBonusGame.SetBlackCard5(LoadTexture("black5.png"));
    
    ViewBonusGame.SetCloseBonusGameButton(LoadTexture("closeButton.png"));
    
    // View 4 TTFs
    
    selectCardSurface = TTF_RenderText_Solid(Xanadu, selectCardText.c_str(), color);
    
    selectCardTexture = SDL_CreateTextureFromSurface(rendererPtr, selectCardSurface);
    
    m_vecCards = {ViewBonusGame.GetBlackCard1(), ViewBonusGame.GetBlackCard2(), ViewBonusGame.GetBlackCard3(), ViewBonusGame.GetBlackCard4(), ViewBonusGame.GetBlackCard5(), ViewBonusGame.GetRedCard1(), ViewBonusGame.GetRedCard2(), ViewBonusGame.GetRedCard3(), ViewBonusGame.GetRedCard4(), ViewBonusGame.GetRedCard5()};
    
    
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
    
    // Loading Vector Textures Cash Out
    
    vecAnimationCashOut = {texture1,texture2,texture3,texture4,texture5,texture6,texture7,texture8,texture9,texture10,texture11,texture12,texture13,texture14,texture15,texture16,texture17,texture18,texture19,texture20,texture21,texture22,texture23,texture24,texture25,texture26,texture27,texture28,texture29,texture30,texture31,texture32,texture33,texture34,texture35,texture36,texture37,texture38,texture39,texture40,texture41,texture42,texture43,texture44,texture45,texture46,texture47,texture48,texture49,texture50,texture51,texture52,texture53,texture54,texture55,texture56,texture57,texture58,texture59,texture60,texture61,texture62,texture63,texture64,texture64,texture65,texture66,texture67,texture68,texture69,texture70,texture71,texture72,texture73,texture74,texture75,texture76,texture77,texture78,texture79,texture80,texture81,texture82,texture83,texture84,texture85,texture86,texture87,texture88,texture89,texture90,texture91,texture92};
}



// Loading all Textures

void LifeCycle:: PreparingTextures()
{
    PreparingTexturesView1();
    
    PreparingTexturesView2();
    
    PreparingTexturesView3();
    
    PreparingTexturesView4();
    
    PreparingTexturesCashOutAnimation();
}

// Refresh From Backup XML FILE

void LifeCycle:: RefreshFromBackup(bool IsGameSaved)
{
    if(IsGameSaved == true)
    {
        gameController.LoadGame(); // Loading and Refreshing all Logic
        
        gameController.NewGame(); // Reading Credits from XML and Save In Info Menu
        
        counterViewControllers = gameRecovery.LoadView();
        
        counterVolume = gameRecovery.LoadVolume(); // Loading Volume before Save
        
        m_nCredit = gameRecovery.LoadCredits(); // Loading Credits
        
        // Loading all Figures before Save
        
        row1fig1 = gameController.GetGameReels()[0][0];
        
        row1fig2 = gameController.GetGameReels()[1][0];
        
        row1fig3 = gameController.GetGameReels()[2][0];
        
        row2fig1 = gameController.GetGameReels()[0][1];
        
        row2fig2 = gameController.GetGameReels()[1][1];
        
        row2fig3 = gameController.GetGameReels()[2][1];
        
        row3fig1 = gameController.GetGameReels()[0][2];
        
        row3fig2 = gameController.GetGameReels()[1][2];
        
        row3fig3 = gameController.GetGameReels()[2][2];
        
        row4fig1 = gameController.GetGameReels()[0][3];
        
        row4fig2 = gameController.GetGameReels()[1][3];
        
        row4fig3 = gameController.GetGameReels()[2][3];
        
        row5fig1 = gameController.GetGameReels()[0][4];
        
        row5fig2 = gameController.GetGameReels()[1][4];
        
        row5fig3 = gameController.GetGameReels()[2][4];
        
        if(row1fig1 == -1) // Initialize ROWS If Matrix from GameController returns -1
        {
            row1fig1 = 0;
            row1fig2 = 1;
            row1fig3 = 2;
            row2fig1 = 3;
            row2fig2 = 4;
            row2fig3 = 5;
            row3fig1 = 6;
            row3fig2 = 7;
            row3fig3 = 8;
            row4fig1 = 0;
            row4fig2 = 1;
            row4fig3 = 2;
            row5fig1 = 3;
            row5fig2 = 4;
            row5fig3 = 5;
        }
        
        // Loading all TTFs for Info Menu Credits, Lines, Bet, TotalBet and Bonus Game
        
        creditSurface = TTF_RenderText_Solid(Xanadu, to_string(m_nCredit).c_str(), color);
        
        creditTexture = SDL_CreateTextureFromSurface(rendererPtr, creditSurface);
        
        linesSurface = TTF_RenderText_Solid(Xanadu, gameController.NumberOfLinesAsString().c_str(), color);
        
        betSurface = TTF_RenderText_Solid(Xanadu, gameController.BetPerLineAsString().c_str(), color);
        
        linesTextureText = SDL_CreateTextureFromSurface(rendererPtr, linesSurface);
        
        betTextureText = SDL_CreateTextureFromSurface(rendererPtr, betSurface);
        
        totalBetSurface = TTF_RenderText_Solid(Xanadu, gameController.TotalBetAsString().c_str(), color);
        
        totalBetTextureText = SDL_CreateTextureFromSurface(rendererPtr, totalBetSurface);
        
        cout << "Game Recovery Refreshed " << endl;
    }
    else
    {
        cout << "XML FILE NOT FOUND For Refreshing Game" << endl;
    }
}

// Initializing Reels from PLAY BUTTON View 2

void LifeCycle:: InitializingReel()
{
    // Logic Starting REELS Before Spin in Play Button view 2
    
     row1fig1 = 0;
     row1fig2 = 1;
     row1fig3 = 2;
     row2fig1 = 3;
     row2fig2 = 4;
     row2fig3 = 5;
     row3fig1 = 6;
     row3fig2 = 7;
     row3fig3 = 8;
     row4fig1 = 0;
     row4fig2 = 1;
     row4fig3 = 2;
     row5fig1 = 3;
     row5fig2 = 4;
     row5fig3 = 5;
    
    // Loading all TTFs for Info Menu Credits, Lines, Bet, TotalBet
    
    creditSurface = TTF_RenderText_Solid(Xanadu, to_string(m_nCredit).c_str(), color);
    
    creditTexture = SDL_CreateTextureFromSurface(rendererPtr, creditSurface);
    
    linesSurface = TTF_RenderText_Solid(Xanadu, gameController.NumberOfLinesAsString().c_str(), color);
    
    betSurface = TTF_RenderText_Solid(Xanadu, gameController.BetPerLineAsString().c_str(), color);
    
    linesTextureText = SDL_CreateTextureFromSurface(rendererPtr, linesSurface);
    
    betTextureText = SDL_CreateTextureFromSurface(rendererPtr, betSurface);
    
    totalBetSurface = TTF_RenderText_Solid(Xanadu, gameController.TotalBetAsString().c_str(), color);
    
    totalBetTextureText = SDL_CreateTextureFromSurface(rendererPtr, totalBetSurface);

}

// Cash Out Animation

void LifeCycle:: CashOutAnimation()
{
    PreparingTexturesCashOutAnimation();
    
    bool animationFinished = false;
    
    int counterTextures = 0;
    
    string finalCreditText = "Total Winnings: " + to_string(gameController.GetCredits()) + " BGN";
    
    finalCredit = TTF_RenderText_Solid(Xanadu, finalCreditText.c_str(), black);
    
    finalCreditTexture = SDL_CreateTextureFromSurface(rendererPtr, finalCredit);
    
    while(animationFinished == false)
    {
        SDL_RenderCopy(rendererPtr, vecAnimationCashOut[counterTextures], NULL, NULL);
        
        SDL_RenderPresent(rendererPtr);
        
        SDL_Delay(50);
        
        counterTextures++;
        
        if(counterTextures > 91)
        {
            SDL_RenderCopy(rendererPtr, finalCreditTexture, NULL, &Rect.rectFinalCreditText);
            
            SDL_RenderPresent(rendererPtr);
            
            SDL_Delay(5000);
            
            m_nCredit = gameController.GetCredits();
            
//            while(m_nCredit > 0) // Effect Counting Down Credit
//            {
//                m_nCredit -= 500;
//                
//                if(m_nCredit <= 0)
//                {
//                    m_nCredit = 0;
//                }
//                
//                finalCreditText = "Total Winnings: " + to_string(m_nCredit) + " BGN";
//                
//                finalCredit = TTF_RenderText_Solid(Xanadu, finalCreditText.c_str(), black);
//                
//                finalCreditTexture = SDL_CreateTextureFromSurface(rendererPtr, finalCredit);
//                
//                SDL_RenderCopy(rendererPtr, vecAnimationCashOut[counterTextures], NULL, NULL);
//                
//                SDL_RenderCopy(rendererPtr, finalCreditTexture, NULL, &Rect.rectFinalCreditText);
//                
//                SDL_RenderPresent(rendererPtr);
//            }
            
            SDL_Delay(2000);
            
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
}

void LifeCycle:: WhiteScreenAndCashOutAnimation()
{
    
    while(Rect.rectWhiteScreen.y <= 0) // White Screen Coming
    {
        Rect.rectWhiteScreen.y += 3;
        
        SDL_RenderCopy(rendererPtr, Slot.GetWhiteScreenTexture(), NULL, &Rect.rectWhiteScreen);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    CashOutAnimation(); // Coins Falling
    
    while(Rect.rectBackground.x >= 0) // Back To View 1 Backgorund
    {
        Rect.rectBackground.x -= 1;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    gameController.SetNullCredits();
    
    counterViewControllers = 1;
    
    gameRecovery.UpdateView(counterViewControllers);
    
    okPushedSpaceShip = false;
    
    Rect.rectLogo.x = 400;
    
    Rect.rectInsertCredit.x = 450;
    
    Rect.rectLoadGame.x = -450;
    
    Rect.rectFirstLine.y = -150;
    
    Rect.rectSecondLine.x = 110;
    
    Rect.rectSecondLine.y = -150;
    
    Rect.rectThirdLine.x = 90;
    
    Rect.rectThirdLine.y = -150;
    
    Rect.rectFourthLine.y = -150;
    
    Rect.rectSlot.x = 720;
    
    Rect.rectSlot.y = 720;
    
    Rect.rectWhiteScreen.y = -730;
    
    m_nCredit = 0;
    
    creditText = "INSERT CREDIT";
    
    SDL_FreeSurface(finalCredit);
    
    SDL_DestroyTexture(finalCreditTexture);
    
}

// Struct for ALL Rects

void LifeCycle:: CreateRectsInStruct()
{
    // Rects View 1 ->
    
    Rect.rectBackground = createRect(0, 0, 1280, 720);
    
    Rect.rectForwardButton = createRect(650, 570, 200, 150);
    
    Rect.rectBackButton = createRect(400, 570, 200, 150);
    
    Rect.rectLogo = createRect(400, 10, 500, 250);
    
    Rect.rectInsertCredit = createRect(750, 460, 450, 130);
    
    Rect.rectLoadGame = createRect(80, 460, 450, 130);
    
    Rect.rectInfoButton = createRect(10, 650, 50, 50);
    
    Rect.rectPayTableButton = createRect(65, 650, 60, 60);
    
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
    
    Rect.rectPayTable = createRect(0, -650, 1280, 650);
    
    Rect.rectClosePayTableButton = createRect(1200, -630, 50, 50);
    
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
    
    Rect.rectFinalCreditText = createRect(40, 100, 1200, 150);
    
    // Rects for Slot figures
    
    // Rectangles for FIRST row
    
    Rect.rectFigure1Slot1 = createRect(170, 120, 105, 110);
    
    Rect.rectFigure2Slot1 = createRect(170, 267, 105, 110);
    
    Rect.rectFigure3Slot1 = createRect(170, 410, 105, 110);
    
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
    
    // Info Panel
    
    Rect.rectLinesText = createRect(365, 595, 40, 40);
    
    Rect.rectLinesShow = createRect(343, 548, 75, 30);
    
    Rect.rectBetLabel = createRect(580, 548, 60, 30);
    
    Rect.rectBetText = createRect(580, 595, 40, 40);
    
    Rect.rectTotalBetText = createRect(875, 605, 90, 30);
    
    // Winning PayLines Label and Text
    
    Rect.rectWinningPayLinesLabel = createRect(700, 548, 235, 30);
    
    Rect.rectWinningPayLines = createRect(950, 548, 100, 30);
    
    // View 4 Bonus Game ->
    
    Rect.rectBackgroundBonusGame = createRect(120, -660, 1050, 600);
    
    Rect.rectRedButton = createRect(200, 300, 200, 200);
    
    Rect.rectBlackButton = createRect(900, 300, 200, 200);
    
    Rect.rectCardTexture = createRect(550, 300, 200, 300);
    
    Rect.rectSelectText = createRect(300, 110, 700, 50);
    
    Rect.rectWinLose = createRect(400, 180, 500, 50);
    
    Rect.rectCloseButtonBonusGame = createRect(1100, 80, 50, 50);
    
}

// Load Music

void LifeCycle:: LoadMusic()
{
    introMusic = Mix_LoadWAV("intro.wav");
    
    buttonSound = Mix_LoadWAV("soundButton.wav");
    
    nextViewSound = Mix_LoadWAV("nextView.wav");
    
    //linesSound = Mix_LoadWAV("linesSound.wav");
    
    stopReel = Mix_LoadWAV("stopReel.wav");
    
    startButtonSound = Mix_LoadWAV("comingShip.wav");
    
    viewSound = Mix_LoadWAV("viewSound.wav");
    
    lineSound = Mix_LoadWAV("linesComing.wav");
    
    linesWin = Mix_LoadWAV("linesWin.wav");
    
    bonusGameMusic = Mix_LoadWAV("bonusGameMusic.wav");
    
//    if(introMusic || buttonSound || nextViewSound || linesSound == NULL)
//    {
//        cerr << "Problem to LOAD MUSIC" << endl;
//    }
}

// Present View 1

void LifeCycle:: PresentView1()
{
    
    Mix_PlayChannel(-1, introMusic, 2);
    
    SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),&Rect.rectBackground , NULL);
    
    if(counterViewControllers == 1)
    {
        SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &Rect.rectLogo);
        
        SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(), NULL, &Rect.rectInsertCredit);
        
        SDL_RenderCopy(rendererPtr, Intro.GetLoadGameTexture(), NULL, &Rect.rectLoadGame);
        
        if(okPushedSpaceShip == true)
        {
            SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &Rect.rectForwardButton);
        }
    }
    
    SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL, &Rect.rectInfoButton);
    
    SDL_RenderCopy(rendererPtr, Intro.GetPayTableTexture(), NULL, &Rect.rectPayTableButton);
    
    SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL, &Rect.rectVolumePlusButton);
    
    SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL, &Rect.rectVolumeMinusButton);
    
    SDL_RenderCopy(rendererPtr, Intro.GetRulesTexture(), NULL, &Rect.rectRules);
    
    SDL_RenderCopy(rendererPtr, Intro.GetPayTableTextureInfo(), NULL, &Rect.rectPayTable);
    
    SDL_RenderCopy(rendererPtr, Intro.GetCloseRulesButton(), NULL, &Rect.rectCloseRulesButton);
    
    SDL_RenderCopy(rendererPtr, Intro.GetClosePayTableButton(), NULL, &Rect.rectClosePayTableButton);
    
    
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

// Present View 2

void LifeCycle:: PresentView2()
{
    if(counterViewControllers == 2)
    {
        
        Rect.rectTextCreditController2.x = 120;
        
        Rect.rectFirstLine.y = 0;
        
        Rect.rectSecondLine.y = 120;
        
        Rect.rectThirdLine.y = 280;
        
        Rect.rectFourthLine.y = 420;
        
        Rect.rectBackground.x = 391;
        
        Rect.rectLogo.x = -1555;
        
        Rect.rectInsertCredit.x = -1205;
        
        Rect.rectLoadGame.x = -1875;

        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetThirdRow(), NULL, &Rect.rectThirdLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFourthRow(), NULL, &Rect.rectFourthLine);
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetBackButtonTexture(), NULL, &Rect.rectBackButton);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetPlayButtonTexture(), NULL, &Rect.rectButtonPlay);
        
        SDL_RenderCopy(rendererPtr, Intro.GetRulesTexture(), NULL, &Rect.rectRules);
        
        SDL_RenderCopy(rendererPtr, Intro.GetPayTableTextureInfo(), NULL, &Rect.rectPayTable);
        
        SDL_RenderCopy(rendererPtr, Intro.GetCloseRulesButton(), NULL, &Rect.rectCloseRulesButton);
        
        SDL_RenderCopy(rendererPtr, Intro.GetClosePayTableButton(), NULL, &Rect.rectClosePayTableButton);
        
        
    }
}

void LifeCycle:: PresentView3()
{
    
    if(counterViewControllers == 3)
    {
        Rect.rectBackground.x = 1150;
        
        Rect.rectSlot.x = 0;
        
        Rect.rectSlot.y = 0;
        
        Rect.rectTextCreditController2.x = 120;
        
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row1fig1], NULL, &Rect.rectFigure1Slot1); // Fig 1  // Slot 1
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row1fig2], NULL, &Rect.rectFigure2Slot1); // Fig 2
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row1fig3], NULL, &Rect.rectFigure3Slot1); // Fig 3
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row2fig1], NULL, &Rect.rectFigure1Slot2); // Fig 1  // Slot 2
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row2fig2], NULL, &Rect.rectFigure2Slot2); // Fig 2
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row2fig3], NULL, &Rect.rectFigure3Slot2); // Fig 3
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row3fig1], NULL, &Rect.rectFigure1Slot3); // Fig 1  // Slot 3
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row3fig2], NULL, &Rect.rectFigure2Slot3); // Fig 2
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row3fig3], NULL, &Rect.rectFigure3Slot3); // Fig 3
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row4fig1], NULL, &Rect.rectFigure1Slot4); // Fig 1  // Slot 4
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row4fig2], NULL, &Rect.rectFigure2Slot4); // Fig 2
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row4fig3], NULL, &Rect.rectFigure3Slot4); // Fig 3
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row5fig1], NULL, &Rect.rectFigure1Slot5); // Fig 1  // Slot 5
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row5fig2], NULL, &Rect.rectFigure2Slot5); // Fig 2
        
        SDL_RenderCopy(rendererPtr, m_vecSlotFigures[row5fig3], NULL, &Rect.rectFigure3Slot5); // Fig 3
        
        SDL_RenderCopy(rendererPtr, Slot.GetSlotTexture(), NULL, &Rect.rectSlot);
        
        if(startPressed == false)
        {
            SDL_RenderCopy(rendererPtr, m_vecLines[gameController.GetNumberOfLines()], NULL, &Rect.rectSlot);
        }
        
        SDL_RenderCopy(rendererPtr, linesTextureText, NULL, &Rect.rectLinesText);
        
        SDL_RenderCopy(rendererPtr, linesLabelTexture, NULL, &Rect.rectLinesShow);
        
        SDL_RenderCopy(rendererPtr, betLabelTexture, NULL, &Rect.rectBetLabel);
        
        SDL_RenderCopy(rendererPtr, betTextureText, NULL, &Rect.rectBetText);
        
        SDL_RenderCopy(rendererPtr, totalBetTextureText, NULL, &Rect.rectTotalBetText);
        
        SDL_RenderCopy(rendererPtr, winningPayLinesTexture, NULL, &Rect.rectWinningPayLinesLabel);
        
        SDL_RenderCopy(rendererPtr, winningLinesTexture, NULL, &Rect.rectWinningPayLines);
        
        SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonLines(), NULL, &Rect.rectMinusButtonLines);
        
        SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButton(), NULL, &Rect.rectPlusButtonLines);
        
        SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBet(), NULL, &Rect.rectMinusBetButton);
        
        SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBet(), NULL, &Rect.rectPlusBetButton);
        
        SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButton(), NULL, &Rect.rectMaxBetButton);
        
        SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButton(), NULL, &Rect.rectStartSpinButton);
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, Slot.GetCashOutButton(), NULL, &Rect.rectCashOutButton);
        
        SDL_RenderCopy(rendererPtr, Intro.GetRulesTexture(), NULL, &Rect.rectRules);
        
        SDL_RenderCopy(rendererPtr, Intro.GetPayTableTextureInfo(), NULL, &Rect.rectPayTable);
        
        SDL_RenderCopy(rendererPtr, Intro.GetCloseRulesButton(), NULL, &Rect.rectCloseRulesButton);
        
        SDL_RenderCopy(rendererPtr, Intro.GetClosePayTableButton(), NULL, &Rect.rectClosePayTableButton);
    }
}

void LifeCycle:: PresentView4() // Present View 4
{
    if(IsBonusGamePresent == true)
    {
        
        SDL_RenderCopy(rendererPtr, ViewBonusGame.GetBackgroundBonusGame(), NULL, &Rect.rectBackgroundBonusGame);
        
        if(PresentingBonusGameEffect == true) // Present After Show EFFECT
        {
            SDL_RenderCopy(rendererPtr, ViewBonusGame.GetRedButton(), NULL, &Rect.rectRedButton);
            
            SDL_RenderCopy(rendererPtr, ViewBonusGame.GetBlackButton(), NULL, &Rect.rectBlackButton);
            
            SDL_RenderCopy(rendererPtr, ViewBonusGame.GetCardTexture(), NULL, &Rect.rectCardTexture);
            
            SDL_RenderCopy(rendererPtr, selectCardTexture, NULL, &Rect.rectSelectText);
            
            SDL_RenderCopy(rendererPtr, ViewBonusGame.GetCloseBonusGameButton(), NULL, &Rect.rectCloseButtonBonusGame);
            
        }
    
    }
}

// Presenting View 4

void LifeCycle:: PresentingBonusGame(bool presentingBonusGame)
{
    if(presentingBonusGame == true)
    {
        
        while(Rect.rectBackgroundBonusGame.y < 60)
        {
            Rect.rectBackgroundBonusGame.y += 5;
            
            PresentView3();
            
            PresentView4();
            
            SDL_RenderPresent(rendererPtr);
        }
        
        PresentingBonusGameEffect = true;
        
        Mix_Pause(-1);
        
        Mix_PlayChannel(1, bonusGameMusic, 3);
    
        
    }
}

// Hide View 4

void LifeCycle:: HideBonusGame(bool presentingBonusGame)
{
    if(presentingBonusGame == true && PresentingBonusGameEffect == true)
    {
        while(Rect.rectBackgroundBonusGame.y > -660)
        {
            Rect.rectBackgroundBonusGame.y -= 5;
            
            PresentView3();
            
            SDL_RenderCopy(rendererPtr, ViewBonusGame.GetBackgroundBonusGame(), NULL, &Rect.rectBackgroundBonusGame);
            
            SDL_RenderPresent(rendererPtr);
        }
        
        PresentingBonusGameEffect = false;
        
        IsBonusGamePresent = false;
        
        CounterRedBlackPressed = 0;
        
        selectCardText = "Select RED / BLACK Button";
        
        selectCardSurface = TTF_RenderText_Solid(Xanadu, selectCardText.c_str(), color);
        
        selectCardTexture = SDL_CreateTextureFromSurface(rendererPtr, selectCardSurface);
        
        Mix_Pause(1);
        
        Mix_PlayChannel(0, introMusic, 3);
    }
}

// Effect Credit Menu

void LifeCycle:: CreditMenu(bool startCreditMenu)
{
    if(startCreditMenu == true)
    {
        while(Rect.rectLogo.y >= -260) // Logo Vertical Effect
        {
            Rect.rectLogo.y -= 1;
            
            PresentView1();
            
            SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &Rect.rectInsertCredit);
            
            SDL_RenderPresent(rendererPtr);
        }
        
        while(Rect.rectBackground.h >= 250) // Zoom In Effect
        {
            Rect.rectBackground.h -= 1;
            
            Rect.rectBackground.w -= 2;
            
            SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
            
            SDL_RenderPresent(rendererPtr);
        }
        
        Mix_PlayChannel(0, startButtonSound, 0);
        
        Mix_Volume(0, 30);
        
        while(Rect.rectSpaceShip.y <= 0) // SpaceShipShown
        {
            Rect.rectSpaceShip.y += 1;
            
            SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
            
            SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipTexture(), NULL, &Rect.rectSpaceShip);
            
            SDL_RenderPresent(rendererPtr);
        }
        
        presentSpaceShip = true;
    }
}

// Show Game Rules

void LifeCycle:: ShowGameRules()
{
    while(Rect.rectRules.y < 0)
    {
        Rect.rectRules.y += 5;
        
        Rect.rectCloseRulesButton.y += 5;
        
        PresentView1();
        
        SDL_RenderPresent(rendererPtr);
    }
    
    infoShown = true;
}

// Hide Game Rules

void LifeCycle:: HideGameRules()
{
    while(Rect.rectRules.y > -650)
    {
        Rect.rectRules.y -= 5;
        
        Rect.rectCloseRulesButton.y -= 5;
        
        PresentView1();
        
        SDL_RenderPresent(rendererPtr);
    }
    
     infoShown = false;
}

// Show PayTable

void LifeCycle:: ShowPayTable()
{
    
    while(Rect.rectPayTable.y < 0)
    {
        Rect.rectPayTable.y += 5;
        
        Rect.rectClosePayTableButton.y += 5;
        
        PresentView1();
        
        SDL_RenderPresent(rendererPtr);
    }
    
    payTableShown = true;
}

// Hide PayTable

void LifeCycle:: HidePayTable()
{
    while(Rect.rectPayTable.y > -650)
    {
        Rect.rectPayTable.y -= 5;
        
        Rect.rectClosePayTableButton.y -= 5;
        
        PresentView1();
        
        SDL_RenderPresent(rendererPtr);
    }
    
    payTableShown = false;
}

// Present SpaceShip

void LifeCycle:: PresentCreditMenu(bool presentSpaceShip)
{
    if(presentSpaceShip == true)
    {
        creditText = to_string(m_nCredit);
        
        if(m_nCredit == 0)
        {
            creditText = "Insert Credit";
        }
        
        creditSurface = TTF_RenderText_Solid(Xanadu, creditText.c_str(), color);
        
        creditTexture = SDL_CreateTextureFromSurface(rendererPtr, creditSurface);
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipTexture(), NULL, &Rect.rectSpaceShip);
        
        SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipButtonPlus(), NULL, &Rect.rectSpaceShipButtonPlus);
        
        SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipButtonMinus(), NULL, &Rect.rectSpaceShipButtonMinus);
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCredit);
        
        if(m_nCredit != 0)
        {
            SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipButtonOk(), NULL, &Rect.rectSpaceShipButtonOk);
        }
    }
}

// Effect Credit Menu Zoom Out

void LifeCycle:: CreditMenuZoomOut(bool okPushed)
{
    if(okPushed == true)
    {
        while(Rect.rectSpaceShip.y >= -500) // SpaceShip Vertical Effect Gone
        {
            Rect.rectSpaceShip.y -= 1;
            
            SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
            
            SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipTexture(), NULL, &Rect.rectSpaceShip);
            
            SDL_RenderPresent(rendererPtr);
        }
        
        while(Rect.rectBackground.h <= 720) // Background Zoom Out Effect
        {
            Rect.rectBackground.h += 1;
            
            Rect.rectBackground.w += 2;
            
            SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
            
            SDL_RenderPresent(rendererPtr);
        }
        
        while(Rect.rectLogo.y <= 10) // Logo Vertical Effect Coming
        {
            Rect.rectLogo.y += 1;
            
            SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
            
            SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL, &Rect.rectLogo);
            
            SDL_RenderPresent(rendererPtr);
        }
        
        StartCreditMenuEffect = false;
        
        presentSpaceShip = false;
        
    }
}

// Passing to View 2

void LifeCycle:: PassingToView2()
{
    Rect.rectInsertCredit.x = 750;
    
    Mix_PlayChannel(0, viewSound, 0);
    
    while(Rect.rectInsertCredit.x > -1205) // Effect Going LEFT Logo, InsertCredit, Background
    {
        Rect.rectLogo.x -= 5;
        
        Rect.rectInsertCredit.x -= 5;
        
        Rect.rectLoadGame.x -= 5;
        
        Rect.rectBackground.x += 1;
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, Intro.GetPushedForwardButtonTexture(), NULL, &Rect.rectForwardButton);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    counterViewControllers += 1;
    
    while(Rect.rectTextCreditController2.x >= 120) // Credit Coming Left To Right
    {
        Rect.rectTextCreditController2.x -= 3;
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    LinesEffectComing();
    
    counterViewControllers = 2;
}

void LifeCycle:: LinesEffectComing() // Lines Effect Coming in View 2
{
    Mix_PlayChannel(0, lineSound, 0); // linesComing
    
    while(Rect.rectFirstLine.y <= 0)// First Line
    {
        Rect.rectFirstLine.y += 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    Mix_PlayChannel(0, lineSound, 0); // linesComing
    
    while(Rect.rectSecondLine.y <= 120) // Second Line
    {
        Rect.rectSecondLine.y += 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    while(Rect.rectThirdLine.y <= 280) // Third Line
    {
        Rect.rectThirdLine.y += 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetThirdRow(), NULL, &Rect.rectThirdLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    Mix_PlayChannel(0, lineSound, 0); // linesComing
    
    while(Rect.rectFourthLine.y <= 420) // Fourth Line
    {
        Rect.rectFourthLine.y += 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetThirdRow(), NULL, &Rect.rectThirdLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFourthRow(), NULL, &Rect.rectFourthLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    Mix_PlayChannel(0, lineSound, 0); // linesComing
    
}

void LifeCycle::BackToView1() // Effect Lines Gone and Back To View 1
{
    while(Rect.rectFourthLine.y >= -150) // Fourth Line
    {
        Rect.rectFourthLine.y -= 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetThirdRow(), NULL, &Rect.rectThirdLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFourthRow(), NULL, &Rect.rectFourthLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    while(Rect.rectThirdLine.y >= -150) // Third Line
    {
        Rect.rectThirdLine.y -= 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetThirdRow(), NULL, &Rect.rectThirdLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    while(Rect.rectSecondLine.y >= -150) // Second Line
    {
        Rect.rectSecondLine.y -= 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    while(Rect.rectFirstLine.y >= -150)// First Line
    {
        Rect.rectFirstLine.y -= 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    while(Rect.rectTextCreditController2.x <= 1290) // Credit Gone Right To Left
    {
        Rect.rectTextCreditController2.x += 3;
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    counterViewControllers -= 1;
    
    Mix_PlayChannel(0, viewSound, 0);
    
    while(Rect.rectLoadGame.x < 80) // Effect Coming LEFT Logo, InsertCredit, Background
    {
        Rect.rectLogo.x += 5;
        
        Rect.rectInsertCredit.x += 5;
        
        Rect.rectLoadGame.x += 5;
        
        Rect.rectBackground.x -= 1;
        
        PresentView1();
        
        SDL_RenderPresent(rendererPtr);
    }
    
    counterViewControllers = 1;
}

void LifeCycle:: PassingToView3() // Passing To View 3
{
    while(Rect.rectFirstLine.y >= -150) // First Line Going UP
    {
        Rect.rectFirstLine.y -= 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFirstRow(), NULL, &Rect.rectFirstLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetThirdRow(), NULL, &Rect.rectThirdLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFourthRow(), NULL, &Rect.rectFourthLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    while(Rect.rectFourthLine.y <= 730) // Fourth Line Going DOWN
    {
        Rect.rectFourthLine.y += 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetThirdRow(), NULL, &Rect.rectThirdLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetFourthRow(), NULL, &Rect.rectFourthLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    while(Rect.rectSecondLine.x >= -1190) // Second and Third Lines Goind LEFT And RIGHT
    {
        Rect.rectSecondLine.x -= 3;
        
        Rect.rectThirdLine.x += 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderCopy(rendererPtr, creditTexture, NULL, &Rect.rectTextCreditController2);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetSecondRow(), NULL, &Rect.rectSecondLine);
        
        SDL_RenderCopy(rendererPtr, PayLines.GetThirdRow(), NULL, &Rect.rectThirdLine);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    Mix_PlayChannel(0, viewSound, 0);
    
    while(Rect.rectBackground.x <= 1150) // Backround Effect RIGHT
    {
        Rect.rectBackground.x += 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView1();
        
        SDL_RenderPresent(rendererPtr);
    }
    
    while(Rect.rectSlot.x >= 0) // Rect Slot View 3 COMING
    {
        if(Rect.rectSlot.y > 0)
        {
            Rect.rectSlot.y -= 3;
        }
        
        Rect.rectSlot.x -= 3;
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        SDL_RenderCopy(rendererPtr, Slot.GetSlotTexture(), NULL, &Rect.rectSlot);
        
        SDL_RenderPresent(rendererPtr);
    }
    
    counterViewControllers += 1;
}

void LifeCycle:: SpinningReels() // Effect Spinning REELS
{
    
    int spinCounter1 = 0; // 0-1-2 figures
    
    int spinCounter2 = 3; // 3-4-5 figures
    
    int spinCounter3 = 6; // 6-7-8 figures
    
    int spinRolls = 1; // counting spins for each roll
    
    // counters for second row
    
    int spinCounter4 = 0; // 0-1-2 figures - row 2
    
    int spinCounter5 = 3; // 3-4-5 figures - row 2
    
    int spinCounter6 = 6; // 6-7-8 figures - row 2
    
    int spinRolls2 = 1; // spinning second row
    
    //counters for the third row
    
    int spinCounter7 = 0; // 0-1-2 figures - row 3
    
    int spinCounter8 = 3; // 3-4-5 figures - row 3
    
    int spinCounter9 = 6; // 6-7-8 figures - row 3
    
    int spinRolls3 = 1; // spinning counter row 3
    
    //counters for FOURTH row
    
    int spinCounter10 = 0; // 0-1-2 figures row - 4
    
    int spinCounter11 = 3; // 3-4-5 figure row - 4
    
    int spinCounter12 = 6; // 6-7-8 figures row - 4
    
    int spinRolls4 = 1; // spinning rows counter
    
    //counter for FIFTH row
    
    int spinCounter13 = 0; // 0-1-2 figures row 5
    
    int spinCounter14 = 3; // 3-4-5 figure row 5
    
    int spinCounter15 = 6; // 6-7-8 figures row 5
    
    int spinRolls5 = 1;
    
    while(Rect.rectFigure1Slot1.y && Rect.rectFigure1Slot2.y && Rect.rectFigure1Slot3.y && Rect.rectFigure1Slot4.y && Rect.rectFigure1Slot5.y <= 520) // Effect SPINNING REELS
    {
        // row 1
        
        if(spinRolls <= 9)
        {
            Rect.rectFigure1Slot1.y += 5; // speed in pixels
            
            Rect.rectFigure2Slot1.y += 5;
            
            Rect.rectFigure3Slot1.y += 5;
        }
        
        //row 2
        
        if(spinRolls2 <= 11)
        {
            Rect.rectFigure1Slot2.y += 5; // speed in pixels
            
            Rect.rectFigure2Slot2.y += 5;
            
            Rect.rectFigure3Slot2.y += 5;
        }
        
        // row 3
        
        if(spinRolls3 <= 13)
        {
            Rect.rectFigure1Slot3.y += 5; // speed in pixels
            
            Rect.rectFigure2Slot3.y += 5;
            
            Rect.rectFigure3Slot3.y += 5;
        }
        
        //row 4
        
        if(spinRolls4 <= 15)
        {
            Rect.rectFigure1Slot4.y += 5; // speed in pixels
            
            Rect.rectFigure2Slot4.y += 5;
            
            Rect.rectFigure3Slot4.y += 5;
        }
        
        //row 5
        
        if(spinRolls5 <= 17)
        {
            Rect.rectFigure1Slot5.y += 5; // speed in pixels
            
            Rect.rectFigure2Slot5.y += 5;
            
            Rect.rectFigure3Slot5.y += 5;
        }
        
        // FIRST ROW CHECK IN-s
        
        if (Rect.rectFigure3Slot1.y >= 520)
        {
            Rect.rectFigure3Slot1.y = 13;
            
            spinRolls++;
            
            //counting 3 spins for figure
            
            spinCounter3++;
            
            if (spinCounter3 > 8)
            {
                spinCounter3 = 6;
                
            }
            
        }
        
        if (Rect.rectFigure2Slot1.y >= 520)
        {
            Rect.rectFigure2Slot1.y = 13;
            
            spinCounter2++;
            
            if (spinCounter2 > 5)
            {
                spinCounter2 = 3;
                
            }
            
        }
        
        if (Rect.rectFigure1Slot1.y >= 520)
        {
            Rect.rectFigure1Slot1.y = 13;
            
            spinCounter1++;
            
            if (spinCounter1 > 2)
            {
                spinCounter1 = 0;
                
            }
        }
        
        // Row 2 -----
        
        if (Rect.rectFigure3Slot2.y >= 520) //  620
        {
            Rect.rectFigure3Slot2.y = 13;
            
            spinRolls2++;
            
            spinCounter6++;
            
            if (spinCounter6 > 8)
            {
                spinCounter6 = 6;
                
            }
            
        }
        
        if (Rect.rectFigure2Slot2.y >= 520) // 620
        {
            Rect.rectFigure2Slot2.y = 13;
            
            spinCounter5++;
            
            if (spinCounter5 > 5)
            {
                spinCounter5 = 3;
                
            }
            
        }
        
        if (Rect.rectFigure1Slot2.y >= 520) // 620
        {
            Rect.rectFigure1Slot2.y = 13;
            
            spinCounter4++;
            
            if (spinCounter4 > 2)
            {
                spinCounter4 = 0;
                
            }
        }
        
        // row 3
        
        if (Rect.rectFigure3Slot3.y >= 520) // 720
        {
            Rect.rectFigure3Slot3.y = 13;
            
            //counting 3 spins for figure
            
            spinCounter9++;
            
            if (spinCounter9 > 8)
            {
                spinCounter9 = 6;
                
            }
            
        }
        
        if (Rect.rectFigure2Slot3.y >= 520) // 720
        {
            Rect.rectFigure2Slot3.y = 13;
            
            spinCounter8++;
            
            if (spinCounter8 > 5)
            {
                spinCounter8 = 3;
                
            }
            
        }
        
        if (Rect.rectFigure1Slot3.y >= 520) // 720
        {
            Rect.rectFigure1Slot3.y = 13;
            
            spinRolls3++;
            
            spinCounter7++;
            
            if (spinCounter7 > 2)
            {
                spinCounter7 = 0;
                
            }
        }
        
        //ROW 4
        
        if (Rect.rectFigure3Slot4.y >= 520) // 820
        {
            Rect.rectFigure3Slot4.y = 13;
            
            //counting 3 spins for figure
            
            spinCounter12++;
            
            if (spinCounter12 > 8)
            {
                spinCounter12 = 6;
                
            }
            
        }
        
        if (Rect.rectFigure2Slot4.y >= 520) // 820
        {
            Rect.rectFigure2Slot4.y = 13;
            
            spinCounter11++;
            
            if (spinCounter11 > 5)
            {
                spinCounter11 = 3;
                
            }
            
        }
        
        if (Rect.rectFigure1Slot4.y >= 520) // 820
        {
            Rect.rectFigure1Slot4.y = 13;
            
            spinCounter10++;
            
            spinRolls4++;
            
            if (spinCounter10 > 2)
            {
                spinCounter10 = 0;
                
            }
        }
        
        // ROW 5
        
        if (Rect.rectFigure3Slot5.y >= 520) // 920
        {
            Rect.rectFigure3Slot5.y = 13;
            
            //counting 3 spins for figure
            
            spinCounter15++;
            
            if (spinCounter15 > 8)
            {
                spinCounter15 = 6;
                
            }
            
        }
        
        if (Rect.rectFigure2Slot5.y >= 520) // 920
        {
            Rect.rectFigure2Slot5.y = 13;
            
            spinCounter14++;
            
            if (spinCounter14 > 5)
            {
                spinCounter14 = 3;
                
            }
            
        }
        
        if (Rect.rectFigure1Slot5.y >= 520) // 920
        {
            Rect.rectFigure1Slot5.y = 13;
            
            spinCounter13++;
            
            spinRolls5++;
            
            if (spinCounter13 > 2)
            {
                spinCounter10 = 0;
                
            }
        }
        
        SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(), &Rect.rectBackground, NULL);
        
        PresentView3();
        
        SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButtonPushed(), NULL, &Rect.rectStartSpinButton);
        
        if (spinRolls == 9)
        {
            Mix_PlayChannel(-1, stopReel, 0);
            
            Rect.rectFigure1Slot1.y = 123;
            
            Rect.rectFigure2Slot1.y = 270;
            
            Rect.rectFigure3Slot1.y = 413;
            
            row1fig1 = gameController.GetGameReels()[0][0];
            
            row1fig2 = gameController.GetGameReels()[1][0];
            
            row1fig3 = gameController.GetGameReels()[2][0];
            
            
        }
        
        if (spinRolls2 > 11)
        {
            
            Rect.rectFigure1Slot2.y = 123;
            
            Rect.rectFigure2Slot2.y = 270;
            
            Rect.rectFigure3Slot2.y = 413;
            
            row2fig1 = gameController.GetGameReels()[0][1];
            
            row2fig2 = gameController.GetGameReels()[1][1];
            
            row2fig3 = gameController.GetGameReels()[2][1];
        }
        
        if (spinRolls3 > 13)
        {
            Rect.rectFigure1Slot3.y = 123;
            
            Rect.rectFigure2Slot3.y = 270;
            
            Rect.rectFigure3Slot3.y = 413;
            
            row3fig1 = gameController.GetGameReels()[0][2];
            
            row3fig2 = gameController.GetGameReels()[1][2];
            
            row3fig3 = gameController.GetGameReels()[2][2];
            
        }
        
        if (spinRolls4 > 15)
        {
            Rect.rectFigure1Slot4.y = 123;
            
            Rect.rectFigure2Slot4.y = 270;
            
            Rect.rectFigure3Slot4.y = 413;
            
            row4fig1 = gameController.GetGameReels()[0][3];
            
            row4fig2 = gameController.GetGameReels()[1][3];
            
            row4fig3 = gameController.GetGameReels()[2][3];
        }
        
        if (spinRolls5 > 17)
        {
            Mix_PlayChannel(-1, stopReel, 0);
            
            Rect.rectFigure1Slot5.y = 123;
            
            Rect.rectFigure2Slot5.y = 270;
            
            Rect.rectFigure3Slot5.y = 413;
            
            row5fig1 = gameController.GetGameReels()[0][4];
            
            row5fig2 = gameController.GetGameReels()[1][4];
            
            row5fig3 = gameController.GetGameReels()[2][4];
            
            break;
        }
        
        SDL_RenderPresent(rendererPtr);

    }
    
    creditSurface = TTF_RenderText_Solid(Xanadu, gameController.CreditsAsString().c_str(), color);
    
    creditTexture = SDL_CreateTextureFromSurface(rendererPtr, creditSurface);
    
    winningLinesSurface = TTF_RenderText_Solid(Xanadu, gameController.WinningPaylinesAsString().c_str(), color);
    
    winningLinesTexture = SDL_CreateTextureFromSurface(rendererPtr, winningLinesSurface);
    
}

// Check if we have a WIN Bonus Game View 4

void LifeCycle:: WinBonusGame()
{
    if(IsRedPressed(xZ, yZ) == true && BonusGame::GetBonusGameResult() == eBlack)
    {
        
        selectCardText = "You Lose !";
        
        selectCardSurface = TTF_RenderText_Solid(Xanadu, selectCardText.c_str(), color);
       
        selectCardTexture = SDL_CreateTextureFromSurface(rendererPtr, selectCardSurface);
        
        SDL_RenderCopy(rendererPtr, selectCardTexture, NULL, &Rect.rectWinLose);
        
        SDL_RenderPresent(rendererPtr);
        
        SDL_Delay(1500);
        
        HideBonusGame(IsBonusGamePresent);
        
        selectCardText = "Select RED / BLACK Button";
    }
    
    else if(IsRedPressed(xZ, xZ) == true && BonusGame::GetBonusGameResult() == eRed)
    {
        selectCardText = "You WIN ! " + gameController.CreditsAsString();
        
        selectCardSurface = TTF_RenderText_Solid(Xanadu, selectCardText.c_str(), color);
        
        selectCardTexture = SDL_CreateTextureFromSurface(rendererPtr, selectCardSurface);
        
        SDL_RenderCopy(rendererPtr, selectCardTexture, NULL, &Rect.rectWinLose);
        
        SDL_RenderPresent(rendererPtr);
        
        SDL_Delay(1500);
        
        HideBonusGame(IsBonusGamePresent);
        
        selectCardText = "Select RED / BLACK Button";
    }
    
    else if(IsBlackPressed(xZ, yZ) == true && BonusGame::GetBonusGameResult() == eRed)
    {
        selectCardText = "You Lose !";
        
        selectCardSurface = TTF_RenderText_Solid(Xanadu, selectCardText.c_str(), color);
        
        selectCardTexture = SDL_CreateTextureFromSurface(rendererPtr, selectCardSurface);
        
        SDL_RenderCopy(rendererPtr, selectCardTexture, NULL, &Rect.rectWinLose);
        
        SDL_RenderPresent(rendererPtr);
        
        SDL_Delay(1500);
        
        HideBonusGame(IsBonusGamePresent);
        
        selectCardText = "Select RED / BLACK Button";
    }
    
    else if(IsBlackPressed(xZ, yZ) == true && BonusGame::GetBonusGameResult() == eBlack)
    {
        selectCardText = "You WIN ! " + gameController.CreditsAsString();
        
        selectCardSurface = TTF_RenderText_Solid(Xanadu, selectCardText.c_str(), color);
        
        selectCardTexture = SDL_CreateTextureFromSurface(rendererPtr, selectCardSurface);
        
        SDL_RenderCopy(rendererPtr, selectCardTexture, NULL, &Rect.rectWinLose);
        
        SDL_RenderPresent(rendererPtr);
        
        SDL_Delay(1500);
        
        HideBonusGame(IsBonusGamePresent);
        
        selectCardText = "Select RED / BLACK Button";
    }
}

// Buttons

// View 1 ->

bool LifeCycle:: IsInsertCreditPressed(int x, int y) // Insert Credit / Start New Game
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(x >= Rect.rectInsertCredit.x && x <= (Rect.rectInsertCredit.x + Rect.rectInsertCredit.w) && y >= Rect.rectInsertCredit.y && y <= (Rect.rectInsertCredit.y + Rect.rectInsertCredit.h)  && StartCreditMenuEffect == false && presentSpaceShip == false && counterViewControllers == 1 && infoShown == false &&     payTableShown == false && IsBonusGamePresent == false)
        {
            m_nCredit = 0;
            
            introController.PlayNewGame(); // Create Blank XML FIle
            
            gameRecovery.UpdateView(counterViewControllers); // Update Counter VIEW CONTROLLER in XML
            
            StartCreditMenuEffect = true;
            
            okPushedSpaceShip = false;
            
            PresentView1();
            
            SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &Rect.rectInsertCredit);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            CreditMenu(StartCreditMenuEffect); // Credit Menu Effect
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsLoadGamePressed(int x, int y) // Load Game Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(x >= Rect.rectLoadGame.x && x <= (Rect.rectLoadGame.x + Rect.rectLoadGame.w) && y >= Rect.rectLoadGame.y && y <= (Rect.rectLoadGame.y + Rect.rectLoadGame.h)  && StartCreditMenuEffect == false && presentSpaceShip == false && counterViewControllers == 1 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            // Checking if Exist XML FILE
            
            IsSaveGameExist = gameRecovery.IsSaveGame();
            
            RefreshFromBackup(IsSaveGameExist);
            
            
            PresentView1();
            
            SDL_RenderCopy(rendererPtr, Intro.GetLoadGamePushedTexture(), NULL, &Rect.rectLoadGame);
            
            if(IsSaveGameExist == false)
            {
                SDL_RenderCopy(rendererPtr, Intro.GetFileNotFoundTexture(), NULL, &Rect.rectLoadGame);
            }
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            
            
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsInfoPressed(int x, int y) // Info Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(x >= Rect.rectInfoButton.x && x <= (Rect.rectInfoButton.x + Rect.rectInfoButton.w) && y >= Rect.rectInfoButton.y && y <= (Rect.rectInfoButton.y + Rect.rectInfoButton.w) && presentSpaceShip == false && payTableShown == false && IsBonusGamePresent == false)
        {
            PresentView1();
            
            SDL_RenderCopy(rendererPtr, Intro.GetInfoTexturePushed(), NULL, &Rect.rectInfoButton);
            
            ShowGameRules();
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsPayTablePressed(int x, int y) // PayTable Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(x >= Rect.rectPayTableButton.x && x <= (Rect.rectPayTableButton.x + Rect.rectPayTableButton.w) && y >= Rect.rectPayTableButton.y && y <= (Rect.rectPayTableButton.y + Rect.rectPayTableButton.w) && presentSpaceShip == false && infoShown == false && IsBonusGamePresent == false)
        {
            PresentView1();
            
            SDL_RenderCopy(rendererPtr, Intro.GetPayTableTexturePushed(), NULL, &Rect.rectPayTableButton);
            
            ShowPayTable();
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsCloseRulesPressed(int x, int y) // Close Rules Texture
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(x >= Rect.rectCloseRulesButton.x && x <= (Rect.rectCloseRulesButton.x + Rect.rectCloseRulesButton.w) && y >= Rect.rectCloseRulesButton.y && y <= (Rect.rectCloseRulesButton.y + Rect.rectCloseRulesButton.w) && presentSpaceShip == false && payTableShown == false && IsBonusGamePresent == false)
        {
            PresentView1();
            
            HideGameRules(); // Hide Game Rules
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsClosePayTablePressed(int x, int y) // Close PayTable Texture
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(x >= Rect.rectClosePayTableButton.x && x <= (Rect.rectClosePayTableButton.x + Rect.rectClosePayTableButton.w) && y >= Rect.rectClosePayTableButton.y && y <= (Rect.rectClosePayTableButton.y + Rect.rectClosePayTableButton.w) && presentSpaceShip == false && infoShown == false && IsBonusGamePresent == false)
        {
            PresentView1();
            
            HidePayTable(); // Hide Game Rules
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsVolumeMinusPressed(int x, int y) // Volume Minus
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(x >= Rect.rectVolumeMinusButton.x && x <= (Rect.rectVolumeMinusButton.x + Rect.rectVolumeMinusButton.w) && y >= Rect.rectVolumeMinusButton.y && y <= (Rect.rectVolumeMinusButton.y + Rect.rectVolumeMinusButton.w)  && presentSpaceShip == false && IsBonusGamePresent == false)
        {
            counterVolume -= 1;
            
            if(counterVolume < 0)
            {
                counterVolume = 0;
            }
            
            gameRecovery.UpdateVolume(counterVolume); // Updating Volume in XML
            
            PresentView1();
            
            SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButtonPushed(), NULL, &Rect.rectVolumeMinusButton);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsVolumePlusPressed(int x, int y) // Volume Plus
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(x >= Rect.rectVolumePlusButton.x && x <= (Rect.rectVolumePlusButton.x + Rect.rectVolumePlusButton.w) && y >= Rect.rectVolumePlusButton.y && y <= (Rect.rectVolumePlusButton.y + Rect.rectVolumePlusButton.w) && presentSpaceShip == false && IsBonusGamePresent == false)
        {
            counterVolume += 1;
            
            if(counterVolume > 3)
            {
                counterVolume = 3;
            }
            
            gameRecovery.UpdateVolume(counterVolume); // Updating Volume in XML
            
            PresentView1();
            
            SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButtonPushed(), NULL, &Rect.rectVolumePlusButton);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsForwardPressed(int x, int y) // Forward Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(x >= Rect.rectForwardButton.x && x <= (Rect.rectForwardButton.x + Rect.rectForwardButton.w) && y >= Rect.rectForwardButton.y && y <= (Rect.rectForwardButton.y + Rect.rectForwardButton.h) && presentSpaceShip == false && okPushedSpaceShip == true && counterViewControllers == 1 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            PresentView1();
            
            SDL_RenderCopy(rendererPtr, Intro.GetPushedForwardButtonTexture(), NULL, &Rect.rectForwardButton);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            PassingToView2();
            
            gameRecovery.UpdateView(counterViewControllers); // Update VIEW CONTROLLER in XML
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

// SpaceShip Buttons ->

bool LifeCycle:: IsShipVolumePlusPressed(int x, int y) // Plus Button SpaceShip
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectSpaceShipButtonPlus.x && xZ <= (Rect.rectSpaceShipButtonPlus.x + Rect.rectSpaceShipButtonPlus.w) && yZ >= Rect.rectSpaceShipButtonPlus.y && yZ <= (Rect.rectSpaceShipButtonPlus.y + Rect.rectSpaceShipButtonPlus.h) && presentSpaceShip == true && IsBonusGamePresent == false)
        {
            introController.IncreaseCredits(); // Increase Credit LOGIC
            
            m_nCredit += 10000;
            
            if(m_nCredit > 1000000)
            {
                m_nCredit = 1000000;
            }
            
            PresentCreditMenu(presentSpaceShip);
            
            SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipButtonPlusPushed(), NULL, &Rect.rectSpaceShipButtonPlus);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsShipVolumeMinusPressed(int x, int y) // Minus Button SpaceShip
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectSpaceShipButtonMinus.x && xZ <= (Rect.rectSpaceShipButtonMinus.x + Rect.rectSpaceShipButtonMinus.w) && yZ >= Rect.rectSpaceShipButtonMinus.y && yZ <= (Rect.rectSpaceShipButtonMinus.y + Rect.rectSpaceShipButtonMinus.h) && presentSpaceShip == true && IsBonusGamePresent == false)
        {
            introController.DecreaseCredits(); // Decrease Credit LOGIC
            
            m_nCredit -= 10000;
            
            if(m_nCredit < 0)
            {
                m_nCredit = 0;
            }
            
            PresentCreditMenu(presentSpaceShip);
            
            SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipButtonMinusPushed(), NULL, &Rect.rectSpaceShipButtonMinus);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsShipOkPressed(int x, int y)
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectSpaceShipButtonOk.x && xZ <= (Rect.rectSpaceShipButtonOk.x + Rect.rectSpaceShipButtonOk.w) && yZ >= Rect.rectSpaceShipButtonMinus.y && yZ <= (Rect.rectSpaceShipButtonOk.y + (Rect.rectSpaceShipButtonOk.h - 50)) && presentSpaceShip == true && (m_nCredit > 0) && IsBonusGamePresent == false)
        {
            introController.SaveCredits(); // Save Current credit in XML File
            
            introController.PrintInfo(); // Prints in Console
            
            PresentCreditMenu(presentSpaceShip);
            
            SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipButtonOkPushed(), NULL, &Rect.rectSpaceShipButtonOk);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            okPushedSpaceShip = true;
            
            CreditMenuZoomOut(okPushedSpaceShip); // SpaceShipGone
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

// View 2 ->

bool LifeCycle:: IsBackPressed(int x, int y)
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectBackButton.x && xZ <= (Rect.rectBackButton.x + Rect.rectBackButton.w) && yZ >= Rect.rectBackButton.y && yZ <= (Rect.rectBackButton.y + Rect.rectBackButton.h) && counterViewControllers == 2 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            okPushedSpaceShip = true;
            
            SDL_RenderCopy(rendererPtr, PayLines.GetBackButtonTexturePushed(), NULL, &Rect.rectBackButton);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            BackToView1();
            
            gameRecovery.UpdateView(counterViewControllers); // Update VIEW CONTROLLER in XML
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsPlayPressed(int x, int y)
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectButtonPlay.x && xZ <= (Rect.rectButtonPlay.x + Rect.rectButtonPlay.w) && yZ >= Rect.rectButtonPlay.y && yZ <= (Rect.rectButtonPlay.y + Rect.rectButtonPlay.h) && counterViewControllers == 2 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            
            SDL_RenderCopy(rendererPtr, PayLines.GetPlayButtonTexturePushed(), NULL, &Rect.rectButtonPlay);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            gameController.NewGame(); // Reading Credits from XML and Save In Info Menu
            
            InitializingReel(); // Initialize Reels in View 3
            
            PassingToView3();
            
            gameRecovery.UpdateView(counterViewControllers); // Update VIEW CONTROLLER in XML
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

// View 3 ->

bool LifeCycle:: IsStartSpinPressed(int x, int y) // Start Spin Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectStartSpinButton.x && xZ <= (Rect.rectStartSpinButton.x + Rect.rectStartSpinButton.w) && yZ >= Rect.rectStartSpinButton.y && yZ <= (Rect.rectStartSpinButton.y + Rect.rectStartSpinButton.h) && counterViewControllers == 3 && gameController.TotalBetExceedsCredits() == false && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            Rect.rectWinningPayLines.x = 950;
            
            Rect.rectWinningPayLines.y = 548;
            
            Rect.rectWinningPayLines.w = 100;
            
            Rect.rectWinningPayLines.h = 30;
            
            gameController.Spin(); // Init Current reels, paylines, calculate bet
            
            startPressed = true;
            
            SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButtonPushed(), NULL, &Rect.rectStartSpinButton);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            SpinningReels();
            
            IsBonusGamePresent = gameController.IsBonusGame();
            
            if(!gameController.GetWinningPaylines().empty())
            {
                
                if(IsBonusGamePresent == false)
                {
                    
                    Mix_PlayChannel(0, linesWin, 0);
                    
                    while(Rect.rectWinningPayLines.x >= 440)
                    {
                        Rect.rectWinningPayLines.x -= 5;
                        
                        Rect.rectWinningPayLines.y -= 3;
                        
                        Rect.rectWinningPayLines.w = 450;
                        
                        Rect.rectWinningPayLines.h = 150;
                        
                        PresentView3();
                        
                        SDL_RenderCopy(rendererPtr, winningPayLinesTexture, NULL, &Rect.rectWinningPayLines);
                        
                        SDL_RenderPresent(rendererPtr);
                    }
            
                }
                else if(IsBonusGamePresent == true)
                {
                    BonusGame::InitBonusGame();
                    
                    while(Rect.rectWinningPayLines.x >= 440)
                    {
                        Rect.rectWinningPayLines.x -= 5;
                        
                        Rect.rectWinningPayLines.y -= 3;
                        
                        Rect.rectWinningPayLines.w = 450;
                        
                        Rect.rectWinningPayLines.h = 150;
                        
                    }
                    
                }
                
            }
            
            PresentingBonusGame(IsBonusGamePresent);
            
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsMinusLinesPressed(int x, int y) // Minus Lines Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectMinusButtonLines.x && xZ <= (Rect.rectMinusButtonLines.x + Rect.rectMinusButtonLines.w) && yZ >= Rect.rectMinusButtonLines.y && yZ <= (Rect.rectMinusButtonLines.y + Rect.rectMinusButtonLines.h) && counterViewControllers == 3 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            gameController.DecreasePaylines();
            
            startPressed = false;
            
            //DECREASE LINES
            
            linesSurface = TTF_RenderText_Solid(Xanadu, gameController.NumberOfLinesAsString().c_str(), color);
            
            linesTextureText = SDL_CreateTextureFromSurface(rendererPtr, linesSurface);
            
            totalBetSurface = TTF_RenderText_Solid(Xanadu, gameController.TotalBetAsString().c_str(), color);
            
            totalBetTextureText = SDL_CreateTextureFromSurface(rendererPtr, totalBetSurface);
            
            PresentView3();
            
            SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonLinesPushed(), NULL, &Rect.rectMinusButtonLines);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle::IsPlusLinesPressed(int x, int y) // Plus Lines Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectPlusButtonLines.x && xZ <= (Rect.rectPlusButtonLines.x + Rect.rectPlusButtonLines.w) && yZ >= Rect.rectPlusButtonLines.y && yZ <= (Rect.rectPlusButtonLines.y + Rect.rectPlusButtonLines.h) && counterViewControllers == 3 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            gameController.IncreasePaylines();
            
            startPressed = false;
            
            //ADDING LINES
            
            linesSurface = TTF_RenderText_Solid(Xanadu, gameController.NumberOfLinesAsString().c_str(), color);
            
            linesTextureText = SDL_CreateTextureFromSurface(rendererPtr, linesSurface);
            
            totalBetSurface = TTF_RenderText_Solid(Xanadu, gameController.TotalBetAsString().c_str(), color);
            
            totalBetTextureText = SDL_CreateTextureFromSurface(rendererPtr, totalBetSurface);
            
            PresentView3();
            
            SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButtonPushed(), NULL, &Rect.rectPlusButtonLines);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsCashOutPressed(int x, int y) // Cash Out Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectCashOutButton.x && xZ <= (Rect.rectCashOutButton.x + Rect.rectCashOutButton.w) && yZ >= Rect.rectCashOutButton.y && yZ <= (Rect.rectCashOutButton.y + Rect.rectCashOutButton.h) && counterViewControllers == 3 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            WhiteScreenAndCashOutAnimation();
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsMinusBetPressed(int x, int y) // Minus Bet Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectMinusBetButton.x && xZ <= (Rect.rectMinusBetButton.x + Rect.rectMinusBetButton.w) && yZ >= Rect.rectMinusBetButton.y && yZ <= (Rect.rectMinusBetButton.y + Rect.rectMinusBetButton.h) && counterViewControllers == 3 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            gameController.DecreaseBet();
            
            betSurface = TTF_RenderText_Solid(Xanadu, gameController.BetPerLineAsString().c_str(), color);
            
            betTextureText = SDL_CreateTextureFromSurface(rendererPtr, betSurface);
            
            totalBetSurface = TTF_RenderText_Solid(Xanadu, gameController.TotalBetAsString().c_str(), color);
            
            totalBetTextureText = SDL_CreateTextureFromSurface(rendererPtr, totalBetSurface);
            
            PresentView3();
            
            SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBetPushed(), NULL, &Rect.rectMinusBetButton);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsPlusBetPressed(int x, int y) // Plus Bet Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectPlusBetButton.x && xZ <= (Rect.rectPlusBetButton.x + Rect.rectPlusBetButton.w) && yZ >= Rect.rectPlusBetButton.y && yZ <= (Rect.rectPlusBetButton.y + Rect.rectPlusBetButton.h) && counterViewControllers == 3 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            gameController.IncreaseBet();
            
            betSurface = TTF_RenderText_Solid(Xanadu, gameController.BetPerLineAsString().c_str(), color);
            
            betTextureText = SDL_CreateTextureFromSurface(rendererPtr, betSurface);
            
            totalBetSurface = TTF_RenderText_Solid(Xanadu, gameController.TotalBetAsString().c_str(), color);
            
            totalBetTextureText = SDL_CreateTextureFromSurface(rendererPtr, totalBetSurface);
            
            PresentView3();
            
            SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBetPushed(), NULL, &Rect.rectPlusBetButton);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsMaxBetPressed(int x, int y) // Max Bet Button
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectMaxBetButton.x && xZ <= (Rect.rectMaxBetButton.x + Rect.rectMaxBetButton.w) && yZ >= Rect.rectMaxBetButton.y && yZ <= (Rect.rectMaxBetButton.y + Rect.rectMaxBetButton.h) && counterViewControllers == 3 && infoShown == false && payTableShown == false && IsBonusGamePresent == false)
        {
            gameController.MaxBet();
            
            linesSurface = TTF_RenderText_Solid(Xanadu, gameController.NumberOfLinesAsString().c_str(), color);
            
            linesTextureText = SDL_CreateTextureFromSurface(rendererPtr, linesSurface);
            
            betSurface = TTF_RenderText_Solid(Xanadu, gameController.BetPerLineAsString().c_str(), color);
            
            betTextureText = SDL_CreateTextureFromSurface(rendererPtr, betSurface);
            
            totalBetSurface = TTF_RenderText_Solid(Xanadu, gameController.TotalBetAsString().c_str(), color);
            
            totalBetTextureText = SDL_CreateTextureFromSurface(rendererPtr, totalBetSurface);

            PresentView3();
            
            SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButtonPushed(), NULL, &Rect.rectMaxBetButton);
            
            Mix_PlayChannel(0, buttonSound, 0);
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

// View 4 ->

bool LifeCycle:: IsRedPressed(int x, int y) // Red Button View 4
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectRedButton.x && xZ <= (Rect.rectRedButton.x + Rect.rectRedButton.w) && yZ >= Rect.rectRedButton.y && yZ <= (Rect.rectRedButton.y + Rect.rectRedButton.h) && IsBonusGamePresent == true && (CounterRedBlackPressed < 2))
        {
            CounterRedBlackPressed++;
            
            int cardRand = 0;
            
            BonusGame::PlayerSelectedRed();
            
            BonusGame::PlayBonusRound();
            
            if(BonusGame::GetBonusGameResult() == eBlack)
            {
                cardRand = rand() % 5;
            }
            else if(BonusGame::GetBonusGameResult() == eRed)
            {
                cardRand = (rand() % 5) + 5;
            }
            
            PresentView4();
            
            SDL_RenderCopy(rendererPtr, ViewBonusGame.GetRedButtonPushed(), NULL, &Rect.rectRedButton);
            
            SDL_RenderCopy(rendererPtr, m_vecCards[cardRand], NULL, &Rect.rectCardTexture);
            
            WinBonusGame();
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsBlackPressed(int x, int y) // Black Button View 4
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectBlackButton.x && xZ <= (Rect.rectBlackButton.x + Rect.rectBlackButton.w) && yZ >= Rect.rectBlackButton.y && yZ <= (Rect.rectBlackButton.y + Rect.rectBlackButton.h) && IsBonusGamePresent == true && (CounterRedBlackPressed < 2))
        {
            CounterRedBlackPressed++;
            
            int cardRand = 0;
            
            BonusGame::PlayerSelectedBlack();
            
            BonusGame::PlayBonusRound();
            
            if(BonusGame::GetBonusGameResult() == eBlack)
            {
                cardRand = rand() % 5;
            }
            else if(BonusGame::GetBonusGameResult() == eRed)
            {
                cardRand = (rand() % 5) + 5;
            }
            
            PresentView4();
            
            SDL_RenderCopy(rendererPtr, ViewBonusGame.GetBlackButtonPushed(), NULL, &Rect.rectBlackButton);
            
            SDL_RenderCopy(rendererPtr, m_vecCards[cardRand], NULL, &Rect.rectCardTexture);
            
            WinBonusGame();
            
            return true;
        }
        
        return false;
    }
    
    return false;
}

bool LifeCycle:: IsCloseBonusGamePressed(int x, int y) // Close Button Bonus Game View 4
{
    if(ev.type == SDL_MOUSEBUTTONDOWN)
    {
        if(xZ >= Rect.rectCloseButtonBonusGame.x && xZ <= (Rect.rectCloseButtonBonusGame.x + Rect.rectCloseButtonBonusGame.w) && yZ >= Rect.rectCloseButtonBonusGame.y && yZ <= (Rect.rectCloseButtonBonusGame.y + Rect.rectCloseButtonBonusGame.h) && IsBonusGamePresent == true)
        {
            HideBonusGame(IsBonusGamePresent);
            
            
            
            return true;
        }
        
        return false;
    }
    
    return false;

}


// Quit Game

void LifeCycle:: QuitGame()
{
    SDL_DestroyRenderer(rendererPtr);
    SDL_DestroyWindow(windowPtr);
    rendererPtr = NULL;
    windowPtr = NULL;
    
    Intro.QuitView1();
    PayLines.QuitView2();
    
    SDL_DestroyTexture(creditTexture);
    SDL_DestroyTexture(finalCreditTexture);
    SDL_DestroyTexture(linesLabelTexture);
    SDL_DestroyTexture(linesTextureText);
    SDL_DestroyTexture(betLabelTexture);
    SDL_DestroyTexture(betTextureText);
    SDL_DestroyTexture(goodLuckTextureText);
    SDL_DestroyTexture(totalBetTextureText);
    SDL_DestroyTexture(winningPayLinesTexture);
    SDL_DestroyTexture(winningLinesTexture);
    SDL_DestroyTexture(winTextureText);
    
    creditTexture = NULL;
    finalCreditTexture = NULL;
    linesLabelTexture = NULL;
    linesTextureText = NULL;
    betLabelTexture = NULL;
    betTextureText = NULL;
    goodLuckTextureText = NULL;
    totalBetTextureText = NULL;
    winningPayLinesTexture = NULL;
    winningLinesTexture = NULL;
    winTextureText = NULL;
    Xanadu = NULL;
    creditSurface = NULL;
    finalCredit = NULL;
    introMusic = NULL;
    buttonSound = NULL;
    nextViewSound = NULL;
    stopReel = NULL;
    startButtonSound = NULL;
    viewSound = NULL;
    lineSound = NULL;
    linesLabelSurface = NULL;
    linesSurface = NULL;
    betLabelSurface = NULL;
    betSurface = NULL;
    goodLuckSurface = NULL;
    totalBetSurface = NULL;
    winningPayLinesSurface = NULL;
    winningLinesSurface = NULL;
    winSurface = NULL;
    
    IMG_Quit();
    SDL_Quit();
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
            
            Mix_Volume(-1, counterVolume * 4);
    
            // View 1
            
            PresentView1();
            
            PresentCreditMenu(presentSpaceShip);
            
            IsShipVolumePlusPressed(xZ, yZ);
            
            IsShipVolumeMinusPressed(xZ, yZ);
            
            IsInsertCreditPressed(xZ, yZ);
            
            IsLoadGamePressed(xZ, yZ);
            
            IsShipOkPressed(xZ, xZ);
            
            IsInfoPressed(xZ, yZ);
            
            IsPayTablePressed(xZ, yZ);
            
            IsCloseRulesPressed(xZ, yZ);
            
            IsClosePayTablePressed(xZ, yZ);
            
            IsVolumeMinusPressed(xZ, yZ);
            
            IsVolumePlusPressed(xZ, yZ);
            
            IsForwardPressed(xZ, yZ);
            
            // View 2
            
            PresentView2();
            
            IsBackPressed(xZ, yZ);
            
            IsPlayPressed(xZ, yZ);
            
            // View 3
            
            PresentView3();
            
            IsStartSpinPressed(xZ, yZ);
            
            IsMinusLinesPressed(xZ, yZ);
            
            IsPlusLinesPressed(xZ, yZ);
            
            IsCashOutPressed(xZ, yZ);
            
            IsMinusBetPressed(xZ, yZ);
            
            IsPlusBetPressed(xZ, yZ);
            
            IsMaxBetPressed(xZ, yZ);
            
            // View 4
            
            PresentView4();
            
            IsRedPressed(xZ, yZ);
            
            IsBlackPressed(xZ, xZ);
            
            IsCloseBonusGamePressed(xZ, yZ);
            
            SDL_RenderPresent(rendererPtr);
            
        }
    }
}


