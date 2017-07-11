/*
 * GameController_PrivateMethods.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: SimoAngelov
 */
#include "GameController.h"

//set default values for the member fields
void GameController::SetDefault()
{
	this->SetTotalBet();
	this->m_baseGame.m_iWin = 0;
}

//insert credits in order to play the game
void GameController::InsertCredits(int iCredits)
{
	//if the credits are within legal range
	if (iCredits >= MIN_CREDITS && iCredits <= MAX_CREDITS)
	{
		this->m_baseGame.SetICredits(iCredits);
	}
}

//intialize the reels for the currentGame
void GameController::InitCurrentReels()
{
	this->InitRandomReels();
	this->SetSpecialFigure();

//	this->SetUniqueFigures();

//	this->SetTheSameFigures();
}

//initialize the game reels with random values
void GameController::InitRandomReels()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each reel
	for (int iCol = 0; iCol < GAME_REELS; iCol++)
	{
//traverse each element of the reel
		for (int iRow = 0; iRow < GAME_ROWS; iRow++)
		{
			//choose a figure between 1 and 8
			Figures randomFigure = static_cast<Figures>(rand() % eFigure9);
			//GameModel::m_iGameReels[iRow][iCol] = randomFigure;
			this->m_baseGame.SetReelElement(randomFigure, iRow, iCol);
		} //end row for
	} // end reel for
}

//set the special figure in each game reel
void GameController::SetSpecialFigure()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each reel
	for (int iCol = 0; iCol < GAME_REELS; iCol++)
	{
//traverse each element of the reel
		for (int iRow = 0; iRow < GAME_ROWS; iRow++)
		{
			Figures randomFigure = static_cast<Figures>(rand() % eNUM_FIGURES);
			if (randomFigure == eFigure9)
			{
				//if the current figure is 9 aka special, break the inner loop
				//GameModel::m_iGameReels[iRow][iCol] = randomFigure;
				this->m_baseGame.SetReelElement(randomFigure, iRow, iCol);
				//test cout
				cout << "Hooray" << endl;
				GameController::m_iBonusCounter++;
				break;
			} //end if
		} //end row for
	} //end reel for
}

//set unique figures per each reel
void GameController::SetUniqueFigures()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each reel
	for (int iCol = 0; iCol < GAME_REELS; iCol++)
	{
//traverse each element of the reel
		for (int iRow = 0; iRow < GAME_ROWS; iRow++)
		{
			//while the current element has an invalid value
			while (this->m_baseGame.GetReelElement(iRow, iCol)
					== eInvalidFigure)
			{
				//pick a random figure
				Figures randomFigure = static_cast<Figures>(rand() % eFigure9);
				//check to see if it hasn't been selected
				if (m_bFigureIsSelected[randomFigure] == false)
				{
					//if it hasn't been selected, set the bool value to true
					this->m_baseGame.SetReelElement(randomFigure, iRow, iCol);
					m_bFigureIsSelected[randomFigure] = true;
					//if the selected figure is Special
					if (randomFigure == eFigure9)
					{
						GameController::m_iBonusCounter++;
					}
				}
			} //end while
			  //set the figureIsSelected to false for the next reel
			GameController::m_bFigureIsSelected[eNUM_FIGURES] = false;
		} //end row for
	} // end reel for
}
//set unique figures per each reel
void GameController::SetTheSameFigures()
{
	//seed a random sequence of numbers
	srand(time(0));
	Figures randFigure = static_cast<Figures>(rand() % eNUM_FIGURES);
//traverse each reel
	for (int iCol = 0; iCol < GAME_REELS; iCol++)
	{
//traverse each element of the reel
		for (int iRow = 0; iRow < GAME_ROWS; iRow++)
		{
			this->m_baseGame.SetReelElement(randFigure, iRow, iCol);
		} //end row for
	} // end reel for
}

//Function to initialize the lines
void GameController::InitCurrentPaylines()
{
	//empty the vector of the old lines
	ErasePaylines();
	//initialize the new lines
	InitPayline1();
	InitPayline2();
	InitPayline3();
	InitPayline4();
	InitPayline5();
	InitPayline6();
	InitPayline7();
	InitPayline8();
	InitPayline9();
	InitPayline10();
	InitPayline11();
	InitPayline12();
	InitPayline13();
	InitPayline14();
	InitPayline15();
	InitPayline16();
	InitPayline17();
	InitPayline18();
	InitPayline19();
	InitPayline20();
	InitPayline21();
	InitPayline22();
	InitPayline23();
	InitPayline24();
	InitPayline25();
}

//set the total bet
void GameController::SetTotalBet()
{
	this->m_baseGame.SetITotalBet();
}

//subtract the total bet from the credits
void GameController::AddTotalBetToCredits()
{
	if (!(this->TotalBetExceedsCredits()))
	{
		//take the bet out of the credits
		int iCurrCredits = this->GetCredits();
		int iCurrTotalBet = this->GetTotalBet();
		int iNewCredits = iCurrCredits - iCurrTotalBet;
		this->m_baseGame.SetICredits(iNewCredits);
	}

}

//set the number of paylines for the current game
void GameController::SetNumberOfPaylines(int iNumberOfPaylines)
{
	this->m_baseGame.SetINumberOfLines(iNumberOfPaylines);
}

//set the bet per line, depending on the number of steps
void GameController::SetBetPerPayline(int iStep)
{
	int iBet = this->m_vecBetPerStep[iStep];
	this->m_baseGame.SetIBetPerLine(iBet);
}

//check if the bet increase exceeds the current amount of credits
bool GameController::BetExceedsCredits(int iNextStep)
{
	int iAvailableCredits = this->m_baseGame.GetICredits();
	int iCurrNumLines = this->m_baseGame.GetINumberOfLines();
	int iNewBet = this->m_vecBetPerStep[iNextStep];
	int iNewTotalBet = iCurrNumLines * iNewBet;
	return iNewTotalBet > iAvailableCredits;
}

//check if the payline increase exceeds the current amount of credits
bool GameController::PaylinesExceedCredits(int iNextStep)
{
	int iAvailableCredits = this->m_baseGame.GetICredits();
	int iNewNumLines = iNextStep;
	int iCurrBet = this->m_baseGame.GetIBetPerLine();
	int iNewBet = iNewNumLines * iCurrBet;
	return iNewBet > iAvailableCredits;
}


//calculate the win from the selected paylines
void GameController::WinFromPaylines()
{
	int winFromPaylines = 0;
	for (int i = 0; i < this->GetNumberOfLines(); i++)
	{
		Payline currentPayline = this->m_baseGame.m_vecPaylines[i];
		winFromPaylines += this->WinFromSinglePayline(currentPayline);
		//test cout
		if(this->WinFromSinglePayline(currentPayline) > 0)
		cout << "Win for line" << i + 1 << ": "
				<< this->WinFromSinglePayline(currentPayline) << endl;
	}
	int currentWinnings = this->GetWin();
	int newWinnings = currentWinnings + winFromPaylines;
	this->m_baseGame.SetIWin(newWinnings);
}

//calculate the win from a single line based on the figures
int GameController::WinFromSinglePayline(const Payline& payline)
{
//this function finds the maximum sequence of equal figures
	Figures bestFigure = eInvalidFigure;
	int iBestOccurrence = 0;

//initialize the bestFigure with the first element of the line
	Figures currentFigure = payline.figure[0];
	int iCurrentOccurrence = 1;

//traverse the rest of the line
	for (int i = 1; i < GAME_REELS; i++)
	{
//increment the occurrence of the figure
		if (payline.figure[i] == currentFigure)
		{
			iCurrentOccurrence++;
		}
//first occurrence of the figure in the sequence
		else
		{
			currentFigure = payline.figure[i];
			iCurrentOccurrence = 1;
		}

		if (iCurrentOccurrence >= iBestOccurrence)
		{
			iBestOccurrence = iCurrentOccurrence;
			bestFigure = currentFigure;
		}
	} //end for

//return the winnings from the line
	int iFigCoeff = this->FigureCoefficient(bestFigure, iBestOccurrence);
	int iBet = this->m_baseGame.GetIBetPerLine();
	int winningsPerLine = iFigCoeff * iBet;
	return winningsPerLine;
}

//calculate the coefficient of a figure based on its weight
int GameController::FigureCoefficient(const Figures& figure, int iOccurrences)
{
	int iWeight = 0;
	int iCoefficient = 0;
	switch (iOccurrences)
	{
	case 0:
	case 1:
	case 2:
		iWeight = 0;
		iCoefficient = 0;
		break;
	case 3:
		iWeight = 10 * iOccurrences;
		break;
	case 4:
		iWeight = 20 * iOccurrences;
		break;
	case 5:
		iWeight = 30 * iOccurrences;
		break;
	default:
		iWeight = 0;
		iCoefficient = 0;
		break;
	}

	iCoefficient = (1 + figure) * iWeight;
	return iCoefficient;
}

//Add the win from the paylines to the credits
void GameController::AddWinToCredits()
{
	//if there was a win, add it to the credits
	if (this->GetWin() > 0)
	{
		//test cout
		cout << "THERE IS A WIN" << endl;
		//add the win to the credits
		int iCurrCredits = this->GetCredits();
		int iCurrWin = this->GetWin();
		int iNewCredits = iCurrCredits + iCurrWin;
		this->m_baseGame.SetICredits(iNewCredits);
	}
}

