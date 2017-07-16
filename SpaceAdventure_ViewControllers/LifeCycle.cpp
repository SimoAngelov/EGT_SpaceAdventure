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
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "Problem to INIZIALIZE MEDIA" << endl;
	}
	else
	{

		windowPtr = SDL_CreateWindow("Space Adventure", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, m_nWidth, m_nHeight, SDL_WINDOW_SHOWN);

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

	//Adding rects for slot buttons

	SDL_Rect minusButtonLines = createRect(300, 595, 40, 40);

	SDL_Rect plusButtonLines = createRect(435, 595, 40, 40);

	SDL_Rect minusBetButton = createRect(505, 595, 40, 40);

	SDL_Rect plusBetButton = createRect(670, 595, 40, 40);

	SDL_Rect maxBetButton = createRect(730, 585, 60, 60);

	SDL_Rect startSpinButton = createRect(1100, 540, 120, 120);

	// Rectangles for slot figures

	SDL_Rect rectFigure1Slot1 = createRect(170, 123, 105, 110);

	SDL_Rect rectFigure2Slot1 = createRect(170, 270, 105, 110);

	SDL_Rect rectFigure3Slot1 = createRect(170, 413, 105, 110);

	//Rectangles for second row - need to fix coordinates

	SDL_Rect rectFigure1Slot2 = createRect(370, 223, 105, 110);

	SDL_Rect rectFigure2Slot2 = createRect(370, 370, 105, 110);

	SDL_Rect rectFigure3Slot2 = createRect(370, 513, 105, 110);

	// Rectangles for THIRD row - need to fix coordinates

	SDL_Rect rectFigure1Slot3 = createRect(570, 323, 105, 110);

	SDL_Rect rectFigure2Slot3 = createRect(570, 470, 105, 110);

	SDL_Rect rectFigure3Slot3 = createRect(570, 613, 105, 110);

	// Rectangles for FOURTH row

	SDL_Rect rectFigure1Slot4 = createRect(770, 423, 105, 110);

	SDL_Rect rectFigure2Slot4 = createRect(770, 570, 105, 110);

	SDL_Rect rectFigure3Slot4 = createRect(770, 713, 105, 110);

	//Rectangles for FIFTH row

	SDL_Rect rectFigure1Slot5 = createRect(1020, 523, 105, 110);

	SDL_Rect rectFigure2Slot5 = createRect(1020, 670, 105, 110);

	SDL_Rect rectFigure3Slot5 = createRect(1020, 813, 105, 110);

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

	// initializing vector

	m_vecSlotFigures =
	{	Slot.GetFigure1(), Slot.GetFigure2(), Slot.GetFigure3(), Slot.GetFigure4(),
		Slot.GetFigure5(), Slot.GetFigure6(), Slot.GetFigure7(),
		Slot.GetFigure8(), Slot.GetFigure9()

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

	// Credit TEXT (int to string)

	string creditText = "Insert Credit";

	// Loading TTF Surface and Texture in SPACESHIP

	TTF_Init();

	creditSurface = TTF_RenderText_Solid(Xanadu, creditText.c_str(), color);

	creditTexture = SDL_CreateTextureFromSurface(rendererPtr, creditSurface);

	// Mouse Coordinates xZ, yZ

	int xZ = 0;

	int yZ = 0;

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
					// Button FORWARD

					if (xZ >= rectForwardButton.x && xZ <= 850
							&& yZ >= rectForwardButton.y && yZ <= 650
							&& spaceShipHidden == true
							&& okPushedSpaceShip == true)
					{
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

						m_nCredit = m_nCredit + 10000;

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
					}

					// Button VOLUME MINUS

					if (xZ >= rectVolumeMinusButton.x && xZ <= 1195
							&& yZ >= rectVolumeMinusButton.y && yZ <= 710
							&& spaceShipHidden == true)
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
							&& spaceShipHidden == true)
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
						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						// SDL_RenderCopy(rendererPtr, Intro.GetForwardButtonTexture(), NULL, &rectForwardButton);

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
						&rectFigure3Slot4);

				//FIGURE 11

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[1], NULL,
						&rectFigure2Slot4);

				//FIGURE 12

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[2], NULL,
						&rectFigure1Slot4);

				//FIGURE 13

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[3], NULL,
						&rectFigure3Slot5);

				//FIGURE 14

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[4], NULL,
						&rectFigure2Slot5);

				//FIGURE 15

				SDL_RenderCopy(rendererPtr, m_vecSlotFigures[5], NULL,
						&rectFigure1Slot5);

				SDL_RenderCopy(rendererPtr, Slot.GetSlotTexture(), NULL,
						&rectSlot);

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

			}
			//click buttons on the reel

			if (ev.type == SDL_MOUSEBUTTONDOWN)
			{

				// button MINUS LINE REEL
				if (xZ >= minusButtonLines.x && xZ <= 340
						&& yZ >= minusButtonLines.y && yZ <= 635)
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

					SDL_RenderCopy(rendererPtr, Slot.GetPlusLinesButtonPushed(),
					NULL, &plusButtonLines);

					SDL_RenderCopy(rendererPtr, Slot.GetMinusButtonBet(), NULL,
							&minusBetButton);

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

					while (rectFigure1Slot1.y <= 520
							&& rectFigure1Slot2.y <= 620
							&& rectFigure1Slot3.y <= 820
							&& rectFigure1Slot4.y <= 920
							&& rectFigure1Slot5.y <= 1020)
					{
						rectFigure1Slot1.y += 5; // speed in pixels

						rectFigure2Slot1.y += 5;

						rectFigure3Slot1.y += 5;

						//row 2

						rectFigure1Slot2.y += 5;

						rectFigure2Slot2.y += 5;

						rectFigure3Slot2.y += 5;

						// row 3

						rectFigure1Slot3.y += 5;

						rectFigure2Slot3.y += 5;

						rectFigure3Slot3.y += 5;

						//row 4

						rectFigure1Slot4.y += 5;

						rectFigure2Slot4.y += 5;

						rectFigure3Slot4.y += 5;

						//row 5

						rectFigure1Slot5.y += 5;

						rectFigure2Slot5.y += 5;

						rectFigure3Slot5.y += 5;

						// FIRST ROW CHEKC IN-s

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

						if (rectFigure3Slot2.y >= 620)
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

						if (rectFigure2Slot2.y >= 620)
						{
							rectFigure2Slot2.y = 13;

							spinCounter5++;

							if (spinCounter5 > 5)
							{
								spinCounter5 = 3;

							}

						}

						if (rectFigure1Slot2.y >= 620)
						{
							rectFigure1Slot2.y = 13;

							spinCounter4++;

							if (spinCounter4 > 2)
							{
								spinCounter4 = 0;

							}
						}

						// row 3

						if (rectFigure3Slot3.y >= 720)
						{
							rectFigure3Slot3.y = 13;

							spinRolls3++;

							//counting 3 spins for figure

							spinCounter9++;

							if (spinCounter9 > 8)
							{
								spinCounter9 = 6;

							}

						}

						if (rectFigure2Slot3.y >= 720)
						{
							rectFigure2Slot3.y = 13;

							spinCounter8++;

							if (spinCounter8 > 5)
							{
								spinCounter8 = 3;

							}

						}

						if (rectFigure1Slot1.y >= 720)
						{
							rectFigure1Slot1.y = 13;

							spinCounter7++;

							if (spinCounter7 > 2)
							{
								spinCounter7 = 0;

							}
						}

						//ROW 4

						if (rectFigure3Slot4.y >= 820)
						{
							rectFigure3Slot4.y = 13;

							spinRolls4++;

							//counting 3 spins for figure

							spinCounter12++;

							if (spinCounter12 > 8)
							{
								spinCounter12 = 6;

							}

						}

						if (rectFigure2Slot4.y >= 820)
						{
							rectFigure2Slot4.y = 13;

							spinCounter11++;

							if (spinCounter11 > 5)
							{
								spinCounter11 = 3;

							}

						}

						if (rectFigure1Slot4.y >= 820)
						{
							rectFigure1Slot4.y = 13;

							spinCounter10++;

							if (spinCounter10 > 2)
							{
								spinCounter10 = 0;

							}
						}

						// ROW 5

						if (rectFigure3Slot5.y >= 920)
						{
							rectFigure3Slot5.y = 13;

							spinRolls5++;

							//counting 3 spins for figure

							spinCounter15++;

							if (spinCounter15 > 8)
							{
								spinCounter15 = 6;

							}

						}

						if (rectFigure2Slot5.y >= 920)
						{
							rectFigure2Slot5.y = 13;

							spinCounter14++;

							if (spinCounter14 > 5)
							{
								spinCounter14 = 3;

							}

						}

						if (rectFigure1Slot5.y >= 920)
						{
							rectFigure1Slot5.y = 13;

							spinCounter13++;

							if (spinCounter13 > 2)
							{
								spinCounter10 = 0;

							}
						}

						// presenting after SPIN

						SDL_RenderCopy(rendererPtr,
								Intro.GetBackgroundTexture(), &rectBackground,
								NULL);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter3], NULL,
								&rectFigure3Slot1);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter2], NULL,
								&rectFigure2Slot1);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter1], NULL,
								&rectFigure1Slot1);

						// ROW 2 ---------

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter6], NULL,
								&rectFigure3Slot2);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter5], NULL,
								&rectFigure2Slot2);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter4], NULL,
								&rectFigure1Slot2);

						//ROW 3

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter9], NULL,
								&rectFigure3Slot3);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter8], NULL,
								&rectFigure3Slot3);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter7], NULL,
								&rectFigure3Slot3);

						//ROW 4

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter3], NULL,
								&rectFigure3Slot4);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter2], NULL,
								&rectFigure3Slot4);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter1], NULL,
								&rectFigure3Slot4);

						//ROW 5

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter6], NULL,
								&rectFigure3Slot5);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter5], NULL,
								&rectFigure3Slot5);

						SDL_RenderCopy(rendererPtr,
								m_vecSlotFigures[spinCounter4], NULL,
								&rectFigure3Slot5);

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

						SDL_RenderPresent(rendererPtr);

						if (spinRolls > 9 && spinRolls2 > 9 && spinRolls3 > 9
								&& spinRolls4 > 9 && spinRolls5 > 9)
						{

							//killing while loop

							break;

						}

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
