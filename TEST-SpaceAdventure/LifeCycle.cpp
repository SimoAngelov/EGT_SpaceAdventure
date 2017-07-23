//
//  LifeCycle.cpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 06/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "LifeCycle.hpp"
#include <string>
#include <iostream>
#include <sstream>

LifeCycle::LifeCycle()
{

}

// Initialize Everything and Creating WINDOW, RENDERER AND FONT {Xanadu.ttf}

void LifeCycle::InitMedia()
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		cout << "Problem to INIZIALIZE MEDIA" << endl;
	}
	else
	{

		windowPtr = SDL_CreateWindow("Space Adventure", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, m_nWidth, m_nHeight, SDL_WINDOW_SHOWN);

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			cout << "Problem to load AUDIO" << endl;
		}

		if (windowPtr == NULL)
		{
			cout << "Problem to CREATE WINDOW" << endl;
		}
		else
		{
			rendererPtr = SDL_CreateRenderer(windowPtr, -1,
					SDL_RENDERER_ACCELERATED);

			if (rendererPtr == NULL)
			{
				cout << "Problem to CREATE RENDERER" << endl;
			}

			TTF_Init();

			Xanadu = TTF_OpenFont("Xanadu.ttf", 30);

			if (Xanadu == NULL)
			{
				cout << "Problem to OPEN FONT" << endl;
			}

		}
	}
}

// To load Texture from PATH

SDL_Texture* LifeCycle::LoadTexture(string path)
{
	SDL_Texture* textureToReturn = NULL;

	textureToReturn = IMG_LoadTexture(rendererPtr, path.c_str());

	if (textureToReturn == NULL)
	{
		cout << "Problem to load TEXTURE -> " << path << endl;
	}

	return textureToReturn;
}

// Cash Out Animation

void LifeCycle::CashOutAnimation()
{
	Slot Slot;

	bool animationFinished = false;

	int counterTextures = 0;

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

	vector<SDL_Texture*> vectorTextures =
	{ texture1, texture2, texture3, texture4, texture5, texture6, texture7,
			texture8, texture9, texture10, texture11, texture12, texture13,
			texture14, texture15, texture16, texture17, texture18, texture19,
			texture20, texture21, texture22, texture23, texture24, texture25,
			texture26, texture27, texture28, texture29, texture30, texture31,
			texture32, texture33, texture34, texture35, texture36, texture37,
			texture38, texture39, texture40, texture41, texture42, texture43,
			texture44, texture45, texture46, texture47, texture48, texture49,
			texture50, texture51, texture52, texture53, texture54, texture55,
			texture56, texture57, texture58, texture59, texture60, texture61,
			texture62, texture63, texture64, texture64, texture65, texture66,
			texture67, texture68, texture69, texture70, texture71, texture72,
			texture73, texture74, texture75, texture76, texture77, texture78,
			texture79, texture80, texture81, texture82, texture83, texture84,
			texture85, texture86, texture87, texture88, texture89, texture90,
			texture91, texture92 };

	while (animationFinished == false)
	{
		SDL_RenderCopy(rendererPtr, vectorTextures[counterTextures], NULL,
				NULL);

		SDL_RenderPresent(rendererPtr);

		SDL_Delay(50);

		counterTextures++;

		if (counterTextures > 91)
		{
			while (animationFinished == false)
			{

				SDL_RenderCopy(rendererPtr, vectorTextures[counterTextures],
						NULL, NULL);

				SDL_RenderPresent(rendererPtr);

				SDL_Delay(50);

				counterTextures--;

				if (counterTextures < 0)
				{
					animationFinished = true;
				}
			}

		}
	}
}

//While LifeCycle

void LifeCycle::Play()
{
	// Create Object from Controller1_Intro

	Intro Intro;

	// Create Object from Controller2_GameController

	GameController GameController;

	// Create Object from Controller3_Slot

	Slot Slot;

	// Creating objects from SDL_Rect and Custom Constructor -> createRect(int x, int y, int w, int h)

	SDL_Rect rectBackground = createRect(0, 0, 1280, 720);

	SDL_Rect rectForwardButton = createRect(650, 570, 200, 150);

	SDL_Rect rectBackButton = createRect(400, 570, 200, 150);

	SDL_Rect rectLogo = createRect(400, 10, 500, 250);

	SDL_Rect rectInsertCredit = createRect(450, 460, 450, 130);

	SDL_Rect rectInfoButton = createRect(10, 650, 50, 50);

	SDL_Rect rectVolume = createRect(1200, 670, 50, 50);

	SDL_Rect rectVolumePlusButton = createRect(1250, 685, 25, 25);

	SDL_Rect rectVolumeMinusButton = createRect(1170, 685, 25, 25);

	SDL_Rect rectSpaceShip = createRect(0, -500, 1280, 500);

	SDL_Rect rectSpaceShipButtonMinus = createRect(225, 400, 100, 100);

	SDL_Rect rectSpaceShipButtonPlus = createRect(970, 400, 100, 100);

	SDL_Rect rectSpaceShipButtonOk = createRect(570, 360, 150, 150);

	SDL_Rect rectTextCredit = createRect(365, 75, 550, 150);

	SDL_Rect rectTextCreditController2 = createRect(1290, 650, 200, 50);

	SDL_Rect rectFirstLine = createRect(100, -150, 1080, 150);

	SDL_Rect rectSecondLine = createRect(110, -150, 1060, 170);

	SDL_Rect rectThirdLine = createRect(90, -150, 1110, 170);

	SDL_Rect rectFourthLine = createRect(320, -150, 650, 170);

	SDL_Rect rectButtonPlay = createRect(860, 580, 140, 140);

	SDL_Rect rectSlot = createRect(720, 720, 1280, 650);

	SDL_Rect rectRules = createRect(0, -650, 1280, 650);

	//Adding rects for slot buttons

	SDL_Rect minusButtonLines = createRect(300, 595, 40, 40);

	SDL_Rect plusButtonLines = createRect(435, 595, 40, 40);

	SDL_Rect minusBetButton = createRect(505, 595, 40, 40);

	SDL_Rect plusBetButton = createRect(670, 595, 40, 40);

	SDL_Rect maxBetButton = createRect(730, 585, 60, 60);

	SDL_Rect startSpinButton = createRect(1100, 540, 120, 120);

	SDL_Rect rectCashOutButton = createRect(10, 540, 270, 100);

	SDL_Rect rectWhiteScreen = createRect(0, -730, 1280, 720);

	// Rectangles for slot figures

	// Rectangles for FIRST row - done!

	SDL_Rect rectFigure1Slot1 = createRect(170, 123, 105, 110);

	SDL_Rect rectFigure2Slot1 = createRect(170, 270, 105, 110);

	SDL_Rect rectFigure3Slot1 = createRect(170, 413, 105, 110);

	//Rectangles for second row - need to fix coordinates

	SDL_Rect rectFigure1Slot2 = createRect(370, 123, 105, 110);

	SDL_Rect rectFigure2Slot2 = createRect(370, 270, 105, 110);

	SDL_Rect rectFigure3Slot2 = createRect(370, 413, 105, 110);

	// Rectangles for THIRD row - need to fix coordinates

	SDL_Rect rectFigure1Slot3 = createRect(570, 123, 105, 110);

	SDL_Rect rectFigure2Slot3 = createRect(570, 270, 105, 110);

	SDL_Rect rectFigure3Slot3 = createRect(570, 413, 105, 110);

	// Rectangles for FOURTH row

	SDL_Rect rectFigure1Slot4 = createRect(790, 123, 105, 110);

	SDL_Rect rectFigure2Slot4 = createRect(790, 270, 105, 110);

	SDL_Rect rectFigure3Slot4 = createRect(790, 413, 105, 110);

	//Rectangles for FIFTH row

	SDL_Rect rectFigure1Slot5 = createRect(1020, 123, 105, 110);

	SDL_Rect rectFigure2Slot5 = createRect(1020, 270, 105, 110);

	SDL_Rect rectFigure3Slot5 = createRect(1020, 413, 105, 110);

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

	Intro.SetSpaceShipButtonPlusPushed(
			LoadTexture("spaceShipButtonPlusPushed.png"));

	Intro.SetSpaceShipButtonMinus(LoadTexture("spaceShipButtonMinus.png"));

	Intro.SetSpaceShipButtonMinusPushed(
			LoadTexture("spaceShipButtonMinusPushed.png"));

	Intro.SetSpaceShipButtonOk(LoadTexture("okButton.png"));

	Intro.SetSpaceShipButtonOkPushed(LoadTexture("okButtonPushed.png"));

//    Intro.SetRulesTexture(LoadTexture("rules.png"));

// Load Textures Controller 2 - Game Controller

	GameController.SetBackButtonTexture(LoadTexture("left.png"));

	GameController.SetFirstRow(LoadTexture("linesFirstLine.png"));

	GameController.SetSecondRow(LoadTexture("linesSecondLine.png"));

	GameController.SetThirdRow(LoadTexture("linesThirdLine.png"));

	GameController.SetFourthRow(LoadTexture("linesFourthLine.png"));

	GameController.SetPlayButtonTexture(LoadTexture("play.png"));

	GameController.SetPlayButtonTexturePushed(LoadTexture("playPushed.png"));

	// Load Textures Controller 3 - Slot Controller

	//Updating new texture

	//slot textures loading

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

	Slot.SetStartSpinButtonPushed(LoadTexture("startSpinpUSHED.png"));

	Slot.SetCashOutButton(LoadTexture("cashOut.png"));

	Slot.SetCashOutButtonPushed(LoadTexture("cashOutPushed.png"));

	Slot.SetWhiteScreenTexture(LoadTexture("whiteScreen.png"));

	//Loading slot figures

	Slot.SetFigure1(LoadTexture("figure1.png"));

	Slot.SetFigure2(LoadTexture("figure2.png"));

	Slot.SetFigure3(LoadTexture("figure3.png"));

	Slot.SetFigure4(LoadTexture("figure4.png"));

	Slot.SetFigure5(LoadTexture("figure5.png"));

	Slot.SetFigure6(LoadTexture("figure6.png"));

	Slot.SetFigure7(LoadTexture("figure7.png"));

	Slot.SetFigure8(LoadTexture("figure8.png"));

	Slot.SetFigure9(LoadTexture("figure9.png"));

	// Loading textures for 25 lines

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

	// initializing vectors

	m_vecSlotFigures =
	{	Slot.GetFigure1(), Slot.GetFigure2(), Slot.GetFigure3(), Slot.GetFigure4(),
		Slot.GetFigure5(), Slot.GetFigure6(), Slot.GetFigure7(),
		Slot.GetFigure8(), Slot.GetFigure9()

	};

	m_vecLines =

	{	Slot.GetSlotTexture(),Slot.GetLine1(), Slot.GetLine2(), Slot.GetLine3(), Slot.GetLine4(),
		Slot.GetLine5(), Slot.GetLine6(), Slot.GetLine7(), Slot.GetLine8(),
		Slot.GetLine9(),Slot.GetLine10(),Slot.GetLine11(), Slot.GetLine12(),
		Slot.GetLine13(),Slot.GetLine14(),Slot.GetLine15(),Slot.GetLine16(),
		Slot.GetLine17(),Slot.GetLine18(),Slot.GetLine19(),Slot.GetLine20(),
		Slot.GetLine21(),Slot.GetLine22(),Slot.GetLine23(),Slot.GetLine24(),
		Slot.GetLine25()
	};

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

	// Loading TTF Surface and Texture in SPACESHIP

	TTF_Init();

	creditSurface = TTF_RenderText_Solid(Xanadu, creditText.c_str(), color);

	creditTexture = SDL_CreateTextureFromSurface(rendererPtr, creditSurface);

	// Mouse Coordinates xZ, yZ

	int xZ = 0;

	int yZ = 0;

	// Intro Music

	introMusic = Mix_LoadWAV("intro.wav");

	buttonSound = Mix_LoadWAV("soundButton.wav");

	nextViewSound = Mix_LoadWAV("nextView.wav");

	linesSound = Mix_LoadWAV("linesSound.wav");

	if (buttonSound == NULL)
	{
		cout << "Problem to load ButtonSound" << endl;
	}

	while (quitCycle == false)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
			{
				quitCycle = true;
			}

			// View with all buttons normal

			SDL_GetMouseState(&xZ, &yZ);

			// Counter volume 0 and this code -> are same

			SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
					&rectBackground, NULL);

			// Playing music

			Mix_PlayChannel(-1, introMusic, 3);

			Mix_Volume(-1, counterVolume * 2);
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

			// VIEW 1 INTRO

			if (counterViewControllers == 1)
			{
				if (counterVolume == 0)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					if (okPushedSpaceShip == true)
					{
						//when pushing OK button - credits are saved in XML

						intrologic.SaveCredits();

						// check in credit;

						intrologic.PrintInfo();

						SDL_RenderCopy(rendererPtr,
								Intro.GetForwardButtonTexture(), NULL,
								&rectForwardButton);
					}

					SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL,
							&rectLogo);

					SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(),
					NULL, &rectInsertCredit);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL,
							&rectVolume);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

//                    SDL_RenderCopy(rendererPtr, Intro.GetRulesTexture(), NULL, &rectRules);

				}

				// View with all buttons normal and volume 1

				if (counterVolume == 1)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					if (okPushedSpaceShip == true)
					{
						SDL_RenderCopy(rendererPtr,
								Intro.GetForwardButtonTexture(), NULL,
								&rectForwardButton);
					}

					SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL,
							&rectLogo);

					SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(),
					NULL, &rectInsertCredit);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL,
							&rectVolume);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);
				}

				// View with all buttons normal and volume 2

				if (counterVolume == 2)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					if (okPushedSpaceShip == true)
					{
						SDL_RenderCopy(rendererPtr,
								Intro.GetForwardButtonTexture(), NULL,
								&rectForwardButton);
					}

					SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL,
							&rectLogo);

					SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(),
					NULL, &rectInsertCredit);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL,
							&rectVolume);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);
				}

				// View with all buttons normal and volume 3

				if (counterVolume == 3)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					if (okPushedSpaceShip == true)
					{
						SDL_RenderCopy(rendererPtr,
								Intro.GetForwardButtonTexture(), NULL,
								&rectForwardButton);
					}

					SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(), NULL,
							&rectLogo);

					SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(),
					NULL, &rectInsertCredit);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL,
							&rectVolume);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);
				}

				// View with spaceShip present

				if ((spaceShipHidden == false && counterVolume == 0)
						|| (spaceShipHidden == false && counterVolume == 1)
						|| (spaceShipHidden == false && counterVolume == 2)
						|| (spaceShipHidden == false && counterVolume == 3))
				{

					if (m_nCredit <= 0)
					{
						creditInserted = false;

						creditSurface = TTF_RenderText_Solid(Xanadu,
								creditText.c_str(), color);

						creditTexture = SDL_CreateTextureFromSurface(
								rendererPtr, creditSurface);

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

						SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
						NULL, &rectLogo);

						//SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(), NULL,
								&rectVolumeMinusButton);

						SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipTexture(),
						NULL, &rectSpaceShip);

						SDL_RenderCopy(rendererPtr,
								Intro.GetSpaceShipButtonMinus(), NULL,
								&rectSpaceShipButtonMinus);

						SDL_RenderCopy(rendererPtr,
								Intro.GetSpaceShipButtonPlus(), NULL,
								&rectSpaceShipButtonPlus);

						SDL_RenderCopy(rendererPtr, creditTexture, NULL,
								&rectTextCredit);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}
					}
					else
					{
						creditInserted = true;

						creditSurface = TTF_RenderText_Solid(Xanadu,
								creditText.c_str(), color);

						creditTexture = SDL_CreateTextureFromSurface(
								rendererPtr, creditSurface);

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

						SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
						NULL, &rectLogo);

						//SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(), NULL,
								&rectVolumeMinusButton);

						SDL_RenderCopy(rendererPtr, Intro.GetSpaceShipTexture(),
						NULL, &rectSpaceShip);

						SDL_RenderCopy(rendererPtr,
								Intro.GetSpaceShipButtonMinus(), NULL,
								&rectSpaceShipButtonMinus);

						SDL_RenderCopy(rendererPtr,
								Intro.GetSpaceShipButtonPlus(), NULL,
								&rectSpaceShipButtonPlus);

						SDL_RenderCopy(rendererPtr,
								Intro.GetSpaceShipButtonOk(), NULL,
								&rectSpaceShipButtonOk);

						SDL_RenderCopy(rendererPtr, creditTexture, NULL,
								&rectTextCredit);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}
					}

				}

				// MOUSE CLICK

				if (ev.type == SDL_MOUSEBUTTONDOWN)
				{
					Mix_PlayChannel(1, buttonSound, 0);

					// Button FORWARD

					if (xZ >= rectForwardButton.x && xZ <= 850
							&& yZ >= rectForwardButton.y && yZ <= 650
							&& spaceShipHidden == true
							&& okPushedSpaceShip == true)
					{
						Mix_PlayChannel(0, nextViewSound, 0);

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
						NULL, &rectLogo);

						SDL_RenderCopy(rendererPtr,
								Intro.GetInsertCreditTexture(), NULL,
								&rectInsertCredit);

						SDL_RenderCopy(rendererPtr,
								Intro.GetPushedForwardButtonTexture(), NULL,
								&rectForwardButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(), NULL,
								&rectVolumeMinusButton);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}

						// Passing to View 2

						while (rectLogo.x >= -650)
						{
							rectLogo.x -= 5;

							rectInsertCredit.x -= 5;

							rectBackground.x += 1;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr,
									Intro.GetPushedForwardButtonTexture(), NULL,
									&rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						counterViewControllers += 1;

						if (counterViewControllers >= 2)
						{
							counterViewControllers = 2;
						}

						cout << counterViewControllers << endl;
					}

					// Button INSERT CREDIT

					if (xZ >= rectInsertCredit.x && xZ <= 900
							&& yZ >= rectInsertCredit.y && yZ <= 590
							&& spaceShipHidden == true)
					{

						okPushedSpaceShip = false;

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						if (okPushedSpaceShip == true)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetForwardButtonTexture(), NULL,
									&rectForwardButton);
						}

						SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
						NULL, &rectLogo);

						SDL_RenderCopy(rendererPtr,
								Intro.GetInsertCreditPushedTexture(), NULL,
								&rectInsertCredit);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(), NULL,
								&rectVolumeMinusButton);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}

						// While for Vertical LOGO effect

						while (rectLogo.y >= -260)
						{
							rectLogo.y -= 1;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							//SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						// While for ZOOM IN effect

						while (rectBackground.h >= 250)
						{
							rectBackground.h = rectBackground.h - 1;

							rectBackground.w = rectBackground.w - 2;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							// SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);

						}

						// Space Ship SHOWN

						while (rectSpaceShip.y <= 0)
						{
							rectSpaceShip.y = rectSpaceShip.y + 1;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							// SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipTexture(), NULL,
									&rectSpaceShip);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);

							spaceShipHidden = false;
						}

					}

					// Button PLUS SpaceShip

					if (spaceShipHidden == false
							&& xZ >= rectSpaceShipButtonPlus.x && xZ <= 1070
							&& yZ >= rectSpaceShipButtonPlus.y && yZ <= 500)
					{
						// FIRST LOGIC CONNECTION!!!
						// increasing credit func

						intrologic.PlayNewGame();

						m_nCredit = m_nCredit + 10000;

						/// increasing credits + 10 000

						intrologic.IncreaseCredits();

						//increasing credit -> gameLogic

//                    gamecontroller.IncreaseCredits();

						if (m_nCredit > 1000000)
						{
							m_nCredit = 1000000;
						}

						// c++ 14
						// creditText = to_string(m_nCredit);

						//casting to string in c++ 9

						stringstream ss;
						ss << m_nCredit;
						string str = ss.str();

						creditText = str;

						if (m_nCredit <= 0)
						{
							creditSurface = TTF_RenderText_Solid(Xanadu,
									creditText.c_str(), color);

							creditTexture = SDL_CreateTextureFromSurface(
									rendererPtr, creditSurface);

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							//SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipTexture(), NULL,
									&rectSpaceShip);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonMinus(), NULL,
									&rectSpaceShipButtonMinus);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonPlusPushed(), NULL,
									&rectSpaceShipButtonPlus);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCredit);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}
						}
						else
						{
							creditSurface = TTF_RenderText_Solid(Xanadu,
									creditText.c_str(), color);

							creditTexture = SDL_CreateTextureFromSurface(
									rendererPtr, creditSurface);

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							//SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipTexture(), NULL,
									&rectSpaceShip);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonMinus(), NULL,
									&rectSpaceShipButtonMinus);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonPlusPushed(), NULL,
									&rectSpaceShipButtonPlus);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonOk(), NULL,
									&rectSpaceShipButtonOk);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCredit);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}
						}
					}

					// Button MINUS SpaceShip

					if (spaceShipHidden == false
							&& xZ >= rectSpaceShipButtonMinus.x && xZ <= 335
							&& yZ >= rectSpaceShipButtonMinus.y && yZ <= 500)
					{

						m_nCredit = m_nCredit - 10000;

						//decreasing credits - 10 000;

						intrologic.DecreaseCredits();

						// casting to string in c++ 11+

						//						creditText = to_string(m_nCredit);
						//casting to string c++ 9

						stringstream ss;
						ss << m_nCredit;
						string str = ss.str();

						creditText = str;

						if (m_nCredit <= 0)
						{
							m_nCredit = 0;

							creditText = "Insert Credit";
						}

						if (m_nCredit <= 0)
						{
							creditSurface = TTF_RenderText_Solid(Xanadu,
									creditText.c_str(), color);

							creditTexture = SDL_CreateTextureFromSurface(
									rendererPtr, creditSurface);

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							//SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipTexture(), NULL,
									&rectSpaceShip);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonMinusPushed(), NULL,
									&rectSpaceShipButtonMinus);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonPlus(), NULL,
									&rectSpaceShipButtonPlus);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCredit);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}
						}
						else
						{
							creditSurface = TTF_RenderText_Solid(Xanadu,
									creditText.c_str(), color);

							creditTexture = SDL_CreateTextureFromSurface(
									rendererPtr, creditSurface);

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							//SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipTexture(), NULL,
									&rectSpaceShip);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonMinusPushed(), NULL,
									&rectSpaceShipButtonMinus);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonPlus(), NULL,
									&rectSpaceShipButtonPlus);

							SDL_RenderCopy(rendererPtr,
									Intro.GetSpaceShipButtonOk(), NULL,
									&rectSpaceShipButtonOk);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCredit);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}
						}
					}

					// Button OK SpaceShip

					if (spaceShipHidden == false
							&& xZ >= rectSpaceShipButtonOk.x && xZ <= 720
							&& yZ > +rectSpaceShipButtonOk.y && yZ <= 490
							&& creditInserted == true)
					{
						SDL_RenderCopy(rendererPtr,
								Intro.GetSpaceShipButtonOkPushed(), NULL,
								&rectSpaceShipButtonOk);

						if (ev.type == SDL_MOUSEBUTTONDOWN)
						{
							okPushedSpaceShip = true;
						}

						if (okPushedSpaceShip == true)
						{
							// SpaceShip Hidden

							while (rectSpaceShip.y >= -500)
							{
								rectSpaceShip.y = rectSpaceShip.y - 1;

								SDL_RenderCopy(rendererPtr,
										Intro.GetBackgroundTexture(),
										&rectBackground, NULL);

								//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetLogoTexture(), NULL,
										&rectLogo);

								// SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

								SDL_RenderCopy(rendererPtr,
										Intro.GetInfoTexture(), NULL,
										&rectInfoButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumePlusButton(), NULL,
										&rectVolumePlusButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeMinusButton(), NULL,
										&rectVolumeMinusButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetSpaceShipTexture(), NULL,
										&rectSpaceShip);

								if (counterVolume == 0)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture(), NULL,
											&rectVolume);
								}

								if (counterVolume == 1)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture1(), NULL,
											&rectVolume);
								}

								if (counterVolume == 2)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture2(), NULL,
											&rectVolume);
								}

								if (counterVolume == 3)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture3(), NULL,
											&rectVolume);
								}

								SDL_RenderPresent(rendererPtr);

								spaceShipHidden = true;
							}

							// Picture ZOOM OUT

							while (rectBackground.h <= 720)
							{
								rectBackground.h = rectBackground.h + 1;

								rectBackground.w = rectBackground.w + 2;

								SDL_RenderCopy(rendererPtr,
										Intro.GetBackgroundTexture(),
										&rectBackground, NULL);

								//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetLogoTexture(), NULL,
										&rectLogo);

								// SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditPushedTexture(), NULL, &rectInsertCredit);

								SDL_RenderCopy(rendererPtr,
										Intro.GetInfoTexture(), NULL,
										&rectInfoButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumePlusButton(), NULL,
										&rectVolumePlusButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeMinusButton(), NULL,
										&rectVolumeMinusButton);

								if (counterVolume == 0)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture(), NULL,
											&rectVolume);
								}

								if (counterVolume == 1)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture1(), NULL,
											&rectVolume);
								}

								if (counterVolume == 2)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture2(), NULL,
											&rectVolume);
								}

								if (counterVolume == 3)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture3(), NULL,
											&rectVolume);
								}

								SDL_RenderPresent(rendererPtr);

							}

							// Logo Back In VIEW

							while (rectLogo.y <= 10)
							{
								rectLogo.y += 1;

								SDL_RenderCopy(rendererPtr,
										Intro.GetBackgroundTexture(),
										&rectBackground, NULL);

								//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetLogoTexture(), NULL,
										&rectLogo);

								SDL_RenderCopy(rendererPtr,
										Intro.GetInsertCreditPushedTexture(),
										NULL, &rectInsertCredit);

								SDL_RenderCopy(rendererPtr,
										Intro.GetInfoTexture(), NULL,
										&rectInfoButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumePlusButton(), NULL,
										&rectVolumePlusButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeMinusButton(), NULL,
										&rectVolumeMinusButton);

								if (counterVolume == 0)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture(), NULL,
											&rectVolume);
								}

								if (counterVolume == 1)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture1(), NULL,
											&rectVolume);
								}

								if (counterVolume == 2)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture2(), NULL,
											&rectVolume);
								}

								if (counterVolume == 3)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture3(), NULL,
											&rectVolume);
								}

								SDL_RenderPresent(rendererPtr);
							}
						}
					}

					// Button INFO

					if (xZ >= rectInfoButton.x && xZ <= 60
							&& yZ >= rectInfoButton.y && yZ <= 700
							&& spaceShipHidden == true)
					{

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						if (okPushedSpaceShip == true)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetForwardButtonTexture(), NULL,
									&rectForwardButton);
						}

						SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
						NULL, &rectLogo);

						SDL_RenderCopy(rendererPtr,
								Intro.GetInsertCreditTexture(), NULL,
								&rectInsertCredit);

						SDL_RenderCopy(rendererPtr,
								Intro.GetInfoTexturePushed(), NULL,
								&rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(), NULL,
								&rectVolumeMinusButton);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}

						// Effect Rules Coming

						while (rectRules.y <= 0 && infoShown == false)
						{

							rectRules.y += 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetInfoTexturePushed(), NULL,
									&rectInfoButton);

//                            SDL_RenderCopy(rendererPtr, Intro.GetRulesTexture(), NULL, &rectRules);

							SDL_RenderPresent(rendererPtr);
						}

						if (infoShown == true)
						{
							while (rectRules.y >= -650)
							{
								rectRules.y -= 3;

								SDL_RenderCopy(rendererPtr,
										Intro.GetBackgroundTexture(),
										&rectBackground,
										NULL);

								if (okPushedSpaceShip == true)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetForwardButtonTexture(),
											NULL, &rectForwardButton);
								}

								SDL_RenderCopy(rendererPtr,
										Intro.GetLogoTexture(),
										NULL, &rectLogo);

								SDL_RenderCopy(rendererPtr,
										Intro.GetInsertCreditTexture(), NULL,
										&rectInsertCredit);

								SDL_RenderCopy(rendererPtr,
										Intro.GetInfoTexturePushed(), NULL,
										&rectInfoButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumePlusButton(),
										NULL, &rectVolumePlusButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeMinusButton(), NULL,
										&rectVolumeMinusButton);

								if (counterVolume == 0)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture(), NULL,
											&rectVolume);
								}

								if (counterVolume == 1)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture1(), NULL,
											&rectVolume);
								}

								if (counterVolume == 2)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture2(), NULL,
											&rectVolume);
								}

								if (counterVolume == 3)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture3(), NULL,
											&rectVolume);
								}

//                                SDL_RenderCopy(rendererPtr, Intro.GetRulesTexture(), NULL, &rectRules);

								SDL_RenderPresent(rendererPtr);
							}

						}
					}

					// Button VOLUME MINUS

					if (xZ >= rectVolumeMinusButton.x && xZ <= 1195
							&& yZ >= rectVolumeMinusButton.y && yZ <= 710
							&& spaceShipHidden == true && infoShown == false)
					{
						counterVolume = counterVolume - 1;

						if (counterVolume <= 0)
						{
							counterVolume = 0;
						}

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							if (okPushedSpaceShip == true)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetForwardButtonTexture(), NULL,
										&rectForwardButton);
							}

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							if (okPushedSpaceShip == true)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetForwardButtonTexture(), NULL,
										&rectForwardButton);
							}

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButtonPushed(), NULL,
									&rectVolumeMinusButton);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							if (okPushedSpaceShip == true)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetForwardButtonTexture(), NULL,
										&rectForwardButton);
							}

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButtonPushed(), NULL,
									&rectVolumeMinusButton);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							if (okPushedSpaceShip == true)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetForwardButtonTexture(), NULL,
										&rectForwardButton);
							}

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButtonPushed(), NULL,
									&rectVolumeMinusButton);
						}
					}

					// Button VOLUME PLUS

					if (xZ >= rectVolumePlusButton.x && xZ <= 1275
							&& yZ >= rectVolumePlusButton.y && yZ <= 710
							&& spaceShipHidden == true && infoShown == false)
					{
						counterVolume = counterVolume + 1;

						if (counterVolume >= 3)
						{
							counterVolume = 3;
						}

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							if (okPushedSpaceShip == true)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetForwardButtonTexture(), NULL,
										&rectForwardButton);
							}

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButtonPushed(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							if (okPushedSpaceShip == true)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetForwardButtonTexture(), NULL,
										&rectForwardButton);
							}

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButtonPushed(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							if (okPushedSpaceShip == true)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetForwardButtonTexture(), NULL,
										&rectForwardButton);
							}

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButtonPushed(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							if (okPushedSpaceShip == true)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetForwardButtonTexture(), NULL,
										&rectForwardButton);
							}

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButtonPushed(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);
						}

					}

				}
			}

			// View 2 GAME CONTROLLER

			if (counterViewControllers == 2)
			{
				// Effect Left to Right Texture

				while (rectTextCreditController2.x >= 120)
				{
					rectTextCreditController2.x -= 3;

					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

					SDL_RenderCopy(rendererPtr,
							GameController.GetBackButtonTexture(), NULL,
							&rectBackButton);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					SDL_RenderCopy(rendererPtr, creditTexture, NULL,
							&rectTextCreditController2);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

					SDL_RenderPresent(rendererPtr);

				}

				// Effect Up to Down Lines Texture

				// Effect First Line

				while (rectFirstLine.y <= 0)
				{
					rectFirstLine.y += 3;

					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

					SDL_RenderCopy(rendererPtr,
							GameController.GetBackButtonTexture(), NULL,
							&rectBackButton);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					SDL_RenderCopy(rendererPtr, creditTexture, NULL,
							&rectTextCreditController2);

					SDL_RenderCopy(rendererPtr, GameController.GetFirstRow(),
					NULL, &rectFirstLine);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

					Mix_PlayChannel(2, linesSound, 0);

					SDL_RenderPresent(rendererPtr);
				}

				// Effect Second Line

				while (rectSecondLine.y <= 120)
				{
					rectSecondLine.y += 3;

					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

					SDL_RenderCopy(rendererPtr,
							GameController.GetBackButtonTexture(), NULL,
							&rectBackButton);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					SDL_RenderCopy(rendererPtr, creditTexture, NULL,
							&rectTextCreditController2);

					SDL_RenderCopy(rendererPtr, GameController.GetFirstRow(),
					NULL, &rectFirstLine);

					SDL_RenderCopy(rendererPtr, GameController.GetSecondRow(),
					NULL, &rectSecondLine);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

					SDL_RenderPresent(rendererPtr);
				}

				// Effect Third Line

				while (rectThirdLine.y <= 280)
				{
					rectThirdLine.y += 3;

					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

					SDL_RenderCopy(rendererPtr,
							GameController.GetBackButtonTexture(), NULL,
							&rectBackButton);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					SDL_RenderCopy(rendererPtr, creditTexture, NULL,
							&rectTextCreditController2);

					SDL_RenderCopy(rendererPtr, GameController.GetFirstRow(),
					NULL, &rectFirstLine);

					SDL_RenderCopy(rendererPtr, GameController.GetSecondRow(),
					NULL, &rectSecondLine);

					SDL_RenderCopy(rendererPtr, GameController.GetThirdRow(),
					NULL, &rectThirdLine);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

					SDL_RenderPresent(rendererPtr);
				}

				// Effect Fourth Line

				while (rectFourthLine.y <= 420)
				{
					rectFourthLine.y += 3;

					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

					SDL_RenderCopy(rendererPtr,
							GameController.GetBackButtonTexture(), NULL,
							&rectBackButton);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					SDL_RenderCopy(rendererPtr, creditTexture, NULL,
							&rectTextCreditController2);

					SDL_RenderCopy(rendererPtr, GameController.GetFirstRow(),
					NULL, &rectFirstLine);

					SDL_RenderCopy(rendererPtr, GameController.GetSecondRow(),
					NULL, &rectSecondLine);

					SDL_RenderCopy(rendererPtr, GameController.GetThirdRow(),
					NULL, &rectThirdLine);

					SDL_RenderCopy(rendererPtr, GameController.GetFourthRow(),
					NULL, &rectFourthLine);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

					SDL_RenderPresent(rendererPtr);
				}

				SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
						&rectBackground, NULL);

				//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

				SDL_RenderCopy(rendererPtr,
						GameController.GetBackButtonTexture(), NULL,
						&rectBackButton);

				SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
						&rectInfoButton);

				SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL,
						&rectVolumePlusButton);

				SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL,
						&rectVolumeMinusButton);

				SDL_RenderCopy(rendererPtr, creditTexture, NULL,
						&rectTextCreditController2);

				SDL_RenderCopy(rendererPtr, GameController.GetFirstRow(), NULL,
						&rectFirstLine);

				SDL_RenderCopy(rendererPtr, GameController.GetSecondRow(), NULL,
						&rectSecondLine);

				SDL_RenderCopy(rendererPtr, GameController.GetThirdRow(), NULL,
						&rectThirdLine);

				SDL_RenderCopy(rendererPtr, GameController.GetFourthRow(), NULL,
						&rectFourthLine);

				SDL_RenderCopy(rendererPtr,
						GameController.GetPlayButtonTexture(), NULL,
						&rectButtonPlay);

//                SDL_RenderCopy(rendererPtr, Intro.GetRulesTexture(), NULL, &rectRules);

				if (counterVolume == 0)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL,
							&rectVolume);
				}

				if (counterVolume == 1)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL,
							&rectVolume);
				}

				if (counterVolume == 2)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL,
							&rectVolume);
				}

				if (counterVolume == 3)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL,
							&rectVolume);
				}

				// MOUSE CLICK

				if (ev.type == SDL_MOUSEBUTTONDOWN)
				{
					// Button INFO

					if (xZ >= rectInfoButton.x && xZ <= 60
							&& yZ >= rectInfoButton.y && yZ <= 700)
					{
						if (infoShown == true)
						{
							infoShown = false;
						}
						else
						{
							infoShown = true;
						}

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						SDL_RenderCopy(rendererPtr,
								GameController.GetBackButtonTexture(), NULL,
								&rectBackButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetInfoTexturePushed(), NULL,
								&rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(), NULL,
								&rectVolumeMinusButton);

						SDL_RenderCopy(rendererPtr,
								GameController.GetFirstRow(), NULL,
								&rectFirstLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetSecondRow(), NULL,
								&rectSecondLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetThirdRow(), NULL,
								&rectThirdLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetFourthRow(), NULL,
								&rectFourthLine);

						SDL_RenderCopy(rendererPtr, creditTexture, NULL,
								&rectTextCreditController2);

						SDL_RenderCopy(rendererPtr,
								GameController.GetPlayButtonTexture(), NULL,
								&rectButtonPlay);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}

						// Effect Coming Rules Texture

						while (rectRules.y <= 0 && infoShown == false)
						{

							rectRules.y += 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetInfoTexturePushed(), NULL,
									&rectInfoButton);

//                            SDL_RenderCopy(rendererPtr, Intro.GetRulesTexture(), NULL, &rectRules);

							SDL_RenderPresent(rendererPtr);
						}

						// Effect Going Rules Texture

						if (infoShown == true)
						{
							while (rectRules.y >= -650)
							{
								rectRules.y -= 3;

								SDL_RenderCopy(rendererPtr,
										Intro.GetBackgroundTexture(),
										&rectBackground,
										NULL);

								SDL_RenderCopy(rendererPtr,
										GameController.GetBackButtonTexture(),
										NULL, &rectBackButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetInfoTexturePushed(), NULL,
										&rectInfoButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumePlusButton(),
										NULL, &rectVolumePlusButton);

								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeMinusButton(), NULL,
										&rectVolumeMinusButton);

								SDL_RenderCopy(rendererPtr,
										GameController.GetFirstRow(), NULL,
										&rectFirstLine);

								SDL_RenderCopy(rendererPtr,
										GameController.GetSecondRow(), NULL,
										&rectSecondLine);

								SDL_RenderCopy(rendererPtr,
										GameController.GetThirdRow(), NULL,
										&rectThirdLine);

								SDL_RenderCopy(rendererPtr,
										GameController.GetFourthRow(), NULL,
										&rectFourthLine);

								SDL_RenderCopy(rendererPtr, creditTexture, NULL,
										&rectTextCreditController2);

								SDL_RenderCopy(rendererPtr,
										GameController.GetPlayButtonTexture(),
										NULL, &rectButtonPlay);

								if (counterVolume == 0)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture(), NULL,
											&rectVolume);
								}

								if (counterVolume == 1)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture1(), NULL,
											&rectVolume);
								}

								if (counterVolume == 2)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture2(), NULL,
											&rectVolume);
								}

								if (counterVolume == 3)
								{
									SDL_RenderCopy(rendererPtr,
											Intro.GetVolumeTexture3(), NULL,
											&rectVolume);
								}

//                                SDL_RenderCopy(rendererPtr, Intro.GetRulesTexture(), NULL, &rectRules);

								SDL_RenderPresent(rendererPtr);
							}
						}

					}

					// Button VOLUME MINUS

					if (xZ >= rectVolumeMinusButton.x && xZ <= 1195
							&& yZ >= rectVolumeMinusButton.y && yZ <= 710)
					{
						counterVolume = counterVolume - 1;

						if (counterVolume <= 0)
						{
							counterVolume = 0;
						}

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						//  SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

						SDL_RenderCopy(rendererPtr,
								GameController.GetBackButtonTexture(), NULL,
								&rectBackButton);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButtonPushed(), NULL,
								&rectVolumeMinusButton);

						SDL_RenderCopy(rendererPtr,
								GameController.GetFirstRow(), NULL,
								&rectFirstLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetSecondRow(), NULL,
								&rectSecondLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetThirdRow(), NULL,
								&rectThirdLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetFourthRow(), NULL,
								&rectFourthLine);

						SDL_RenderCopy(rendererPtr, creditTexture, NULL,
								&rectTextCreditController2);

						SDL_RenderCopy(rendererPtr,
								GameController.GetPlayButtonTexture(), NULL,
								&rectButtonPlay);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}

					}

					// Button VOLUME PLUS

					if (xZ >= rectVolumePlusButton.x && xZ <= 1275
							&& yZ >= rectVolumePlusButton.y && yZ <= 710)
					{
						counterVolume = counterVolume + 1;

						if (counterVolume >= 3)
						{
							counterVolume = 3;
						}

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						//  SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

						SDL_RenderCopy(rendererPtr,
								GameController.GetBackButtonTexture(), NULL,
								&rectBackButton);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumePlusButtonPushed(), NULL,
								&rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(), NULL,
								&rectVolumeMinusButton);

						SDL_RenderCopy(rendererPtr,
								GameController.GetFirstRow(), NULL,
								&rectFirstLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetSecondRow(), NULL,
								&rectSecondLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetThirdRow(), NULL,
								&rectThirdLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetFourthRow(), NULL,
								&rectFourthLine);

						SDL_RenderCopy(rendererPtr, creditTexture, NULL,
								&rectTextCreditController2);

						SDL_RenderCopy(rendererPtr,
								GameController.GetPlayButtonTexture(), NULL,
								&rectButtonPlay);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}
					}

					// Button PLAY

					if (xZ >= rectButtonPlay.x && xZ <= 1000
							&& yZ >= rectButtonPlay.y && yZ <= 720)
					{
						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						//  SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

						SDL_RenderCopy(rendererPtr,
								GameController.GetBackButtonTexture(), NULL,
								&rectBackButton);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(), NULL,
								&rectVolumeMinusButton);

						SDL_RenderCopy(rendererPtr,
								GameController.GetFirstRow(), NULL,
								&rectFirstLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetSecondRow(), NULL,
								&rectSecondLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetThirdRow(), NULL,
								&rectThirdLine);

						SDL_RenderCopy(rendererPtr,
								GameController.GetFourthRow(), NULL,
								&rectFourthLine);

						SDL_RenderCopy(rendererPtr, creditTexture, NULL,
								&rectTextCreditController2);

						SDL_RenderCopy(rendererPtr,
								GameController.GetPlayButtonTexturePushed(),
								NULL, &rectButtonPlay);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}

						// Effect UP Line 1

						while (rectFirstLine.y >= -150)
						{
							rectFirstLine.y -= 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//  SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetBackButtonTexture(), NULL,
									&rectBackButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFirstRow(), NULL,
									&rectFirstLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetSecondRow(), NULL,
									&rectSecondLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetThirdRow(), NULL,
									&rectThirdLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFourthRow(), NULL,
									&rectFourthLine);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCreditController2);

							SDL_RenderCopy(rendererPtr,
									GameController.GetPlayButtonTexturePushed(),
									NULL, &rectButtonPlay);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						// Effect DOWN Line 4

						while (rectFourthLine.y <= 730)
						{
							rectFourthLine.y += 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//  SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetBackButtonTexture(), NULL,
									&rectBackButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFirstRow(), NULL,
									&rectFirstLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetSecondRow(), NULL,
									&rectSecondLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetThirdRow(), NULL,
									&rectThirdLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFourthRow(), NULL,
									&rectFourthLine);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCreditController2);

							SDL_RenderCopy(rendererPtr,
									GameController.GetPlayButtonTexturePushed(),
									NULL, &rectButtonPlay);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						// Effect Lines 2 and 3

						while (rectSecondLine.x >= -1190)
						{
							rectSecondLine.x -= 3;

							rectThirdLine.x += 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//  SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetBackButtonTexture(), NULL,
									&rectBackButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFirstRow(), NULL,
									&rectFirstLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetSecondRow(), NULL,
									&rectSecondLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetThirdRow(), NULL,
									&rectThirdLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFourthRow(), NULL,
									&rectFourthLine);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCreditController2);

							SDL_RenderCopy(rendererPtr,
									GameController.GetPlayButtonTexturePushed(),
									NULL, &rectButtonPlay);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						// Effect PASSING TO CONTROLLER 3 SLOT

						while (rectBackground.x <= 1150)
						{
							rectBackground.x += 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						counterViewControllers = counterViewControllers + 1;

						cout << counterViewControllers << endl;
					}

					// Button BACK

					if (xZ >= rectBackButton.x && xZ <= 600
							&& yZ >= rectBackButton.y && yZ <= 720)
					{

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

						SDL_RenderCopy(rendererPtr,
								GameController.GetBackButtonTexturePushed(),
								NULL, &rectBackButton);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(), NULL,
								&rectVolumeMinusButton);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(), NULL,
									&rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(), NULL,
									&rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(), NULL,
									&rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(), NULL,
									&rectVolume);
						}

						// Back to Controller 1

						// Effect Fourth Line Back

						while (rectFourthLine.y >= -150)
						{
							rectFourthLine.y -= 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetBackButtonTexture(), NULL,
									&rectBackButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCreditController2);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFirstRow(), NULL,
									&rectFirstLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetSecondRow(), NULL,
									&rectSecondLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetThirdRow(), NULL,
									&rectThirdLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFourthRow(), NULL,
									&rectFourthLine);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						// Effect Third Line Back

						while (rectThirdLine.y >= -150)
						{
							rectThirdLine.y -= 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetBackButtonTexture(), NULL,
									&rectBackButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCreditController2);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFirstRow(), NULL,
									&rectFirstLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetSecondRow(), NULL,
									&rectSecondLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetThirdRow(), NULL,
									&rectThirdLine);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						// Effect Second Line Back

						while (rectSecondLine.y >= -150)
						{
							rectSecondLine.y -= 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetBackButtonTexture(), NULL,
									&rectBackButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCreditController2);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFirstRow(), NULL,
									&rectFirstLine);

							SDL_RenderCopy(rendererPtr,
									GameController.GetSecondRow(), NULL,
									&rectSecondLine);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						// Effect First Line Back

						while (rectFirstLine.y >= -150)
						{
							rectFirstLine.y -= 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetBackButtonTexture(), NULL,
									&rectBackButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCreditController2);

							SDL_RenderCopy(rendererPtr,
									GameController.GetFirstRow(), NULL,
									&rectFirstLine);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						// Effect Text Credit Left to Right

						while (rectTextCreditController2.x <= 1290)
						{
							rectTextCreditController2.x += 3;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							//SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetBackButtonTexturePushed(),
									NULL, &rectBackButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr, creditTexture, NULL,
									&rectTextCreditController2);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);

						}

						while (rectLogo.x <= 400)
						{
							rectLogo.x += 5;

							rectInsertCredit.x += 5;

							rectBackground.x -= 1;

							SDL_RenderCopy(rendererPtr,
									Intro.GetBackgroundTexture(),
									&rectBackground, NULL);

							SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
							NULL, &rectLogo);

							SDL_RenderCopy(rendererPtr,
									Intro.GetInsertCreditTexture(), NULL,
									&rectInsertCredit);

							SDL_RenderCopy(rendererPtr,
									Intro.GetPushedForwardButtonTexture(), NULL,
									&rectForwardButton);

							SDL_RenderCopy(rendererPtr,
									GameController.GetBackButtonTexturePushed(),
									NULL, &rectBackButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumePlusButton(), NULL,
									&rectVolumePlusButton);

							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeMinusButton(), NULL,
									&rectVolumeMinusButton);

							SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
							NULL, &rectInfoButton);

							if (counterVolume == 0)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture(), NULL,
										&rectVolume);
							}

							if (counterVolume == 1)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture1(), NULL,
										&rectVolume);
							}

							if (counterVolume == 2)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture2(), NULL,
										&rectVolume);
							}

							if (counterVolume == 3)
							{
								SDL_RenderCopy(rendererPtr,
										Intro.GetVolumeTexture3(), NULL,
										&rectVolume);
							}

							SDL_RenderPresent(rendererPtr);
						}

						counterViewControllers -= 1;

						if (counterViewControllers <= 1)
						{
							counterViewControllers = 1;
						}

						cout << counterViewControllers << endl;

					}

				}

			}

			// Starting view THREE

			if (counterViewControllers == 3)
			{
				// Coming SLOT Effect

				while (rectSlot.x >= 0)
				{
					if (rectSlot.y > 0)
					{
						rectSlot.y -= 3;
					}

					rectSlot.x -= 3;

					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					SDL_RenderCopy(rendererPtr, Slot.GetSlotTexture(), NULL,
							&rectSlot);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

					SDL_RenderPresent(rendererPtr);
				}

				SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
						&rectBackground, NULL);

				// Figure1

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[0], NULL,
						&rectFigure1Slot1);

				//Figure 2

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[1], NULL,
						&rectFigure2Slot1);

				//FIGURE 3

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[2], NULL,
						&rectFigure3Slot1);

				// FIGURE 4

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[3], NULL,
						&rectFigure1Slot2);

				//FIGURE 5

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[4], NULL,
						&rectFigure2Slot2);

				// FIGURE 6

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[5], NULL,
						&rectFigure3Slot2);

				// FIGURE 7

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[6], NULL,
						&rectFigure1Slot3);

				//FIGURE 8

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[7], NULL,
						&rectFigure2Slot3);

				//FIGURE 9

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[8], NULL,
						&rectFigure3Slot3);

				//FIGURE 10

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[0], NULL,
						&rectFigure1Slot4);

				//FIGURE 11

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[1], NULL,
						&rectFigure2Slot4);

				//FIGURE 12

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[2], NULL,
						&rectFigure3Slot4);

				//FIGURE 13

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[3], NULL,
						&rectFigure1Slot5);

				//FIGURE 14

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[4], NULL,
						&rectFigure2Slot5);

				//FIGURE 15

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[5], NULL,
						&rectFigure3Slot5);

				//ADDING LINES

				SDL_RenderCopy(rendererPtr, m_vecLines[m_nLinesCounter],
				NULL, &rectSlot);

				SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
						&rectInfoButton);

				SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(), NULL,
						&rectVolumePlusButton);

				SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(), NULL,
						&rectVolumeMinusButton);

				// addding buttons to reel

				SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonLines(), NULL,
						&minusButtonLines);

				//increasing lines button

				SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButton(), NULL,
						&plusButtonLines);

				//decreasing bet button

				SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBet(), NULL,
						&minusBetButton);

				// increasing BET button

				SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBet(), NULL,
						&plusBetButton);

				//MAX BET button

				SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButton(), NULL,
						&maxBetButton);

				//START SPIN button

				SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButton(), NULL,
						&startSpinButton);

				if (counterVolume == 0)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(), NULL,
							&rectVolume);
				}

				if (counterVolume == 1)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(), NULL,
							&rectVolume);
				}

				if (counterVolume == 2)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(), NULL,
							&rectVolume);
				}

				if (counterVolume == 3)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(), NULL,
							&rectVolume);
				}

				// Cash Out Button

				SDL_RenderCopy(rendererPtr, Slot.GetCashOutButton(), NULL,
						&rectCashOutButton);

			}
			//click buttons on the reel

			if (ev.type == SDL_MOUSEBUTTONDOWN)
			{

				// button MINUS LINE REEL
				if (xZ >= minusButtonLines.x && xZ <= 340
						&& yZ >= minusButtonLines.y && yZ <= 635)
				{
					//DECREASING LINES

					// LOGIC CONNECTION -> decreasing lines

					// game controll logic
					// decreasing paylines when button minus is pressed

					gamecontroller.DecreasePaylines();
					std::cout << "CHECK decreasing PAYLINES" << std::endl;

					m_nLinesCounter--;

					if (m_nLinesCounter < 0)
					{
						m_nLinesCounter = 0;

					}
					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					// VECTOR FOR LIENS -ADDING AND DECREASING

					SDL_RenderCopy(rendererPtr, m_vecLines[m_nLinesCounter],
					NULL, &rectSlot);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					// addding buttons to reel

					SDL_RenderCopy(rendererPtr,
							Slot.GetMinusButtonLinesPushed(),
							NULL, &minusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBet(), NULL,
							&plusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButton(), NULL,
							&plusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBet(), NULL,
							&minusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButton(),
					NULL, &maxBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButton(), NULL,
							&startSpinButton);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

				}
				//PLUS REEL LINE button

				if (xZ >= plusButtonLines.x && xZ <= 475
						&& yZ >= plusButtonLines.y && yZ <= 635)
				{

					{

						//ADDING LINES
						//Increasing lines button ->

						gamecontroller.IncreasePaylines();

						std::cout << "CHECK INCREASING PAYLINES" << std::endl;
						gamecontroller.IncreasePaylines();

						m_nLinesCounter++;

						if (m_nLinesCounter > 25)
						{
							m_nLinesCounter = 25;

						}

						//						cout << "COUNTER LINES" << m_nLinesCounter << endl;

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						SDL_RenderCopy(rendererPtr, m_vecLines[m_nLinesCounter],
						NULL, &rectSlot);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(),
								NULL, &rectVolumeMinusButton);

						// addding buttons to reel

						SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonLines(),
						NULL, &minusButtonLines);

						SDL_RenderCopy(rendererPtr,
								Slot.GetPlusLinesButtonPushed(),
								NULL, &plusButtonLines);

						SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBet(),
						NULL, &minusBetButton);

						SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBet(),
						NULL, &plusBetButton);

						SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButton(),
						NULL, &maxBetButton);

						SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButton(),
						NULL, &startSpinButton);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(),
									NULL, &rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(),
									NULL, &rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(),
									NULL, &rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(),
									NULL, &rectVolume);
						}

					}

				}
				// MINUS BET button pushed

				if (xZ >= minusBetButton.x && xZ <= 545
						&& yZ >= minusBetButton.y && yZ <= 635)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					SDL_RenderCopy(rendererPtr, Slot.GetSlotTexture(), NULL,
							&rectSlot);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					// addding buttons to reel

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonLines(),
					NULL, &minusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButton(), NULL,
							&plusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBetPushed(),
					NULL, &minusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBet(), NULL,
							&plusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButton(),
					NULL, &maxBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButton(), NULL,
							&startSpinButton);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

				}

				//PLUS BET button  pushed

				if (xZ >= plusBetButton.x && xZ <= 710 && yZ >= plusBetButton.y
						&& yZ <= 635)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					SDL_RenderCopy(rendererPtr, Slot.GetSlotTexture(), NULL,
							&rectSlot);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					// addding buttons to reel

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonLines(),
					NULL, &minusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButton(), NULL,
							&plusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBet(),
					NULL, &minusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBetPushed(),
					NULL, &plusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButton(),
					NULL, &maxBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButton(), NULL,
							&startSpinButton);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

				}

				// MAX BET button pushed

				if (xZ >= maxBetButton.x && xZ <= 790 && yZ >= plusBetButton.y
						&& yZ <= 645)
				{
					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					SDL_RenderCopy(rendererPtr, Slot.GetSlotTexture(), NULL,
							&rectSlot);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					// addding buttons to reel

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonLines(),
					NULL, &minusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButton(), NULL,
							&plusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBet(),
					NULL, &minusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBet(),
					NULL, &plusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButtonPushed(),
					NULL, &maxBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButton(), NULL,
							&startSpinButton);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

				}

				// Cash Out Button

				if (xZ >= rectCashOutButton.x && xZ <= 280
						&& yZ >= rectCashOutButton.y && yZ <= 640)
				{

					SDL_RenderCopy(rendererPtr, Slot.GetCashOutButtonPushed(),
							NULL, &rectCashOutButton);

					while (rectWhiteScreen.y <= 0)
					{
						rectWhiteScreen.y += 3;

						SDL_RenderCopy(rendererPtr,
								Slot.GetWhiteScreenTexture(), NULL,
								&rectWhiteScreen);

						SDL_RenderPresent(rendererPtr);
					}

					CashOutAnimation();

					while (rectBackground.x >= 0)
					{
						rectBackground.x -= 1;

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						SDL_RenderPresent(rendererPtr);
					}

					counterViewControllers = 1;

					okPushedSpaceShip = false;

					rectLogo.x = 400;

					rectInsertCredit.x = 450;

					rectFirstLine.y = -150;

					rectSecondLine.x = 110;

					rectSecondLine.y = -150;

					rectThirdLine.x = 90;

					rectThirdLine.y = -150;

					rectFourthLine.y = -150;

					rectSlot.x = 720;

					rectSlot.y = 720;

					rectWhiteScreen.y = -730;

					m_nCredit = 0;

					creditText = "INSERT CREDIT";

					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					SDL_RenderCopy(rendererPtr, Intro.GetLogoTexture(),
					NULL, &rectLogo);

					SDL_RenderCopy(rendererPtr, Intro.GetInsertCreditTexture(),
							NULL, &rectInsertCredit);

					SDL_RenderCopy(rendererPtr,
							GameController.GetBackButtonTexturePushed(),
							NULL, &rectBackButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
							NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
							NULL, &rectVolumeMinusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
					NULL, &rectInfoButton);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
								NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
								NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
								NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
								NULL, &rectVolume);
					}

				}

				//START SPIN BUTTON pushed

				if (xZ >= startSpinButton.x && xZ <= 1200
						&& yZ >= startSpinButton.y && yZ <= 660)
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

					SDL_RenderCopy(rendererPtr, Intro.GetBackgroundTexture(),
							&rectBackground, NULL);

					SDL_RenderCopy(rendererPtr, Slot.GetSlotTexture(), NULL,
							&rectSlot);

					SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(), NULL,
							&rectInfoButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
					NULL, &rectVolumePlusButton);

					SDL_RenderCopy(rendererPtr, Intro.GetVolumeMinusButton(),
					NULL, &rectVolumeMinusButton);

					// addding buttons to reel

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonLines(),
					NULL, &minusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButton(), NULL,
							&plusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBet(),
					NULL, &minusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBet(),
					NULL, &plusBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButton(),
					NULL, &maxBetButton);

					SDL_RenderCopy(rendererPtr, Slot.GetStartSpinButtonPushed(),
					NULL, &startSpinButton);

					if (counterVolume == 0)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture(),
						NULL, &rectVolume);
					}

					if (counterVolume == 1)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture1(),
						NULL, &rectVolume);
					}

					if (counterVolume == 2)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture2(),
						NULL, &rectVolume);
					}

					if (counterVolume == 3)
					{
						SDL_RenderCopy(rendererPtr, Intro.GetVolumeTexture3(),
						NULL, &rectVolume);
					}

					//Spining figures loop

					while (rectFigure1Slot1.y && rectFigure1Slot2.y
							&& rectFigure1Slot3.y && rectFigure1Slot4.y
							&& rectFigure1Slot5.y <= 520)
					{

						// row 1

						if (spinRolls <= 9)
						{
							rectFigure1Slot1.y += 5; // speed in pixels

							rectFigure2Slot1.y += 5;

							rectFigure3Slot1.y += 5;
						}

						//row 2

						if (spinRolls2 <= 11)
						{
							rectFigure1Slot2.y += 5; // speed in pixels

							rectFigure2Slot2.y += 5;

							rectFigure3Slot2.y += 5;
						}

						// row 3

						if (spinRolls3 <= 13)
						{
							rectFigure1Slot3.y += 5; // speed in pixels

							rectFigure2Slot3.y += 5;

							rectFigure3Slot3.y += 5;
						}

						//row 4

						if (spinRolls4 <= 15)
						{
							rectFigure1Slot4.y += 5; // speed in pixels

							rectFigure2Slot4.y += 5;

							rectFigure3Slot4.y += 5;
						}

						//row 5

						if (spinRolls5 <= 17)
						{
							rectFigure1Slot5.y += 5; // speed in pixels

							rectFigure2Slot5.y += 5;

							rectFigure3Slot5.y += 5;
						}

						// FIRST ROW CHECK IN-s

						if (rectFigure3Slot1.y >= 520)
						{
							rectFigure3Slot1.y = 13;

							spinRolls++;

							//counting 3 spins for figure

							spinCounter3++;

							if (spinCounter3 > 8)
							{
								spinCounter3 = 6;

							}

						}

						if (rectFigure2Slot1.y >= 520)
						{
							rectFigure2Slot1.y = 13;

							spinCounter2++;

							if (spinCounter2 > 5)
							{
								spinCounter2 = 3;

							}

						}

						if (rectFigure1Slot1.y >= 520)
						{
							rectFigure1Slot1.y = 13;

							spinCounter1++;

							if (spinCounter1 > 2)
							{
								spinCounter1 = 0;

							}
						}

						// row 2 -----

						if (rectFigure3Slot2.y >= 520) //  620
						{
							rectFigure3Slot2.y = 13;

							spinRolls2++;

							//counting 3 spins for figure

							spinCounter6++;

							if (spinCounter6 > 8)
							{
								spinCounter6 = 6;

							}

						}

						if (rectFigure2Slot2.y >= 520) // 620
						{
							rectFigure2Slot2.y = 13;

							spinCounter5++;

							if (spinCounter5 > 5)
							{
								spinCounter5 = 3;

							}

						}

						if (rectFigure1Slot2.y >= 520) // 620
						{
							rectFigure1Slot2.y = 13;

							spinCounter4++;

							if (spinCounter4 > 2)
							{
								spinCounter4 = 0;

							}
						}

						// row 3

						if (rectFigure3Slot3.y >= 520) // 720
						{
							rectFigure3Slot3.y = 13;

							//counting 3 spins for figure

							spinCounter9++;

							if (spinCounter9 > 8)
							{
								spinCounter9 = 6;

							}

						}

						if (rectFigure2Slot3.y >= 520) // 720
						{
							rectFigure2Slot3.y = 13;

							spinCounter8++;

							if (spinCounter8 > 5)
							{
								spinCounter8 = 3;

							}

						}

						if (rectFigure1Slot3.y >= 520) // 720
						{
							rectFigure1Slot3.y = 13;

							spinRolls3++;

							spinCounter7++;

							if (spinCounter7 > 2)
							{
								spinCounter7 = 0;

							}
						}

						//ROW 4

						if (rectFigure3Slot4.y >= 520) // 820
						{
							rectFigure3Slot4.y = 13;

							//counting 3 spins for figure

							spinCounter12++;

							if (spinCounter12 > 8)
							{
								spinCounter12 = 6;

							}

						}

						if (rectFigure2Slot4.y >= 520) // 820
						{
							rectFigure2Slot4.y = 13;

							spinCounter11++;

							if (spinCounter11 > 5)
							{
								spinCounter11 = 3;

							}

						}

						if (rectFigure1Slot4.y >= 520) // 820
						{
							rectFigure1Slot4.y = 13;

							spinCounter10++;

							spinRolls4++;

							if (spinCounter10 > 2)
							{
								spinCounter10 = 0;

							}
						}

						// ROW 5

						if (rectFigure3Slot5.y >= 520) // 920
						{
							rectFigure3Slot5.y = 13;

							//counting 3 spins for figure

							spinCounter15++;

							if (spinCounter15 > 8)
							{
								spinCounter15 = 6;

							}

						}

						if (rectFigure2Slot5.y >= 520) // 920
						{
							rectFigure2Slot5.y = 13;

							spinCounter14++;

							if (spinCounter14 > 5)
							{
								spinCounter14 = 3;

							}

						}

						if (rectFigure1Slot5.y >= 520) // 920
						{
							rectFigure1Slot5.y = 13;

							spinCounter13++;

							spinRolls5++;

							if (spinCounter13 > 2)
							{
								spinCounter10 = 0;

							}
						}

						// presenting after SPIN

						//ROW 1 ---------

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter3],
								NULL, &rectFigure3Slot1);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter2],
								NULL, &rectFigure2Slot1);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter1],
								NULL, &rectFigure1Slot1);

						// ROW 2 ---------

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter3],
								NULL, &rectFigure3Slot2);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter2],
								NULL, &rectFigure2Slot2);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter1],
								NULL, &rectFigure1Slot2);

						//ROW 3

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter3],
								NULL, &rectFigure3Slot3);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter2],
								NULL, &rectFigure2Slot3);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter1],
								NULL, &rectFigure1Slot3);

						//ROW 4

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter3],
								NULL, &rectFigure3Slot4);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter2],
								NULL, &rectFigure2Slot4);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter1],
								NULL, &rectFigure1Slot4);

						//ROW 5

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter3],
								NULL, &rectFigure3Slot5);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter2],
								NULL, &rectFigure2Slot5);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter1],
								NULL, &rectFigure1Slot5);

						SDL_RenderCopy(rendererPtr, Slot.GetSlotTexture(), NULL,
								&rectSlot);

						SDL_RenderCopy(rendererPtr, Intro.GetInfoTexture(),
						NULL, &rectInfoButton);

						SDL_RenderCopy(rendererPtr, Intro.GetVolumePlusButton(),
						NULL, &rectVolumePlusButton);

						SDL_RenderCopy(rendererPtr,
								Intro.GetVolumeMinusButton(),
								NULL, &rectVolumeMinusButton);

						// addding buttons to reel

						SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonLines(),
						NULL, &minusButtonLines);

						SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButton(),
						NULL, &plusButtonLines);

						SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBet(),
						NULL, &minusBetButton);

						SDL_RenderCopy(rendererPtr, Slot.GetPlusButtonBet(),
						NULL, &plusBetButton);

						SDL_RenderCopy(rendererPtr, Slot.GetMaxBetButton(),
						NULL, &maxBetButton);

						SDL_RenderCopy(rendererPtr,
								Slot.GetStartSpinButtonPushed(),
								NULL, &startSpinButton);

						if (counterVolume == 0)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture(),
									NULL, &rectVolume);
						}

						if (counterVolume == 1)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture1(),
									NULL, &rectVolume);
						}

						if (counterVolume == 2)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture2(),
									NULL, &rectVolume);
						}

						if (counterVolume == 3)
						{
							SDL_RenderCopy(rendererPtr,
									Intro.GetVolumeTexture3(),
									NULL, &rectVolume);
						}

						if (spinRolls == 9)
						{

							rectFigure1Slot1.y = 123;

							rectFigure2Slot1.y = 270;

							rectFigure3Slot1.y = 413;

						}

						if (spinRolls2 > 11)
						{

							rectFigure1Slot2.y = 123;

							rectFigure2Slot2.y = 270;

							rectFigure3Slot2.y = 413;

						}

						if (spinRolls3 > 13)
						{
							rectFigure1Slot3.y = 123;

							rectFigure2Slot3.y = 270;

							rectFigure3Slot3.y = 413;

						}

						if (spinRolls4 > 15)
						{
							rectFigure1Slot4.y = 123;

							rectFigure2Slot4.y = 270;

							rectFigure3Slot4.y = 413;
						}

						if (spinRolls5 > 17)
						{
							rectFigure1Slot5.y = 123;

							rectFigure2Slot5.y = 270;

							rectFigure3Slot5.y = 413;

							break;
						}

						SDL_RenderPresent(rendererPtr);

					}

				}

			}

			SDL_RenderPresent(rendererPtr);

		}
	}

}

//

void LifeCycle::QuitGame()
{

}
