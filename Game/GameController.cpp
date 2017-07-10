/*
 * GameController.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#include "GameController.h"

//member field to control the number of betting steps
int GameController::m_iBetStep = 0;

//member field to hold the bets at each step
vector<BET> GameController::m_vecBetPerStep
{ eBet1, eBet2, eBet3, eBet4, eBet5, eBet6, eBet7, eBet8, eBet9, eBet10, eBet11,
		eBet12, eBet13, eBet14, eBet15 };

//member field to keep track of which figures are selected at each reel
bool GameController::m_bFigureIsSelected[eNUM_FIGURES] =
{ false };

//member field to keep track of the number of special figures per reel
int GameController::m_iBonusCounter = 0;

//member field to keep track of the choice the player made during the bonus game
COLOR GameController::m_playerChoice = eInvalid1;
//member field to keep track if the player wants to keep the bonus game
bool GameController::m_bQuitBonusGame = false;
//constructor
GameController::GameController() :
		m_baseGame()
{
	// TODO Auto-generated constructor stub
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

//Increase the credits
void GameController::IncreaseCredits()
{
	//increment the existing credits by 10000
	int iNewCredits = this->m_baseGame.GetICredits() + CREDIT_STEP;
	//check to make sure the new amount doesn't exceed the max value
	if (iNewCredits <= MAX_CREDITS)
	{
		this->InsertCredits(iNewCredits);
	} // end if
}

//Decrease Credits
void GameController::DecreaseCredits()
{
	//decrement the existing credits by 10000
	int iNewCredits = this->m_baseGame.GetICredits() - CREDIT_STEP;
	//check to make sure the new amount doesn't go below the min amount
	if (iNewCredits >= MIN_CREDITS)
	{
		this->InsertCredits(iNewCredits);
	}

}
//spin the reels and set the paylines
void GameController::Spin()
{
	//if there was a win, add it to the credits
	if(this->GetWin() > 0)
	{
		//add the win to the credits
		int iCurrCredits = this->GetCredits();
		int iCurrWin = this->GetWin();
		int iNewCredits = iCurrCredits + iCurrWin;
		this->m_baseGame.SetICredits(iNewCredits);
		//set the win to 0
		this->m_baseGame.SetIWin(0);
	}
//only spin if the total bet is above 0
	if (this->GetTotalBet() > 0
			&&this->GetTotalBet() < this->GetCredits())
	{
		//take the bet out of the credits
		int iCurrCredits = this->GetCredits();
		int iCurrTotalBet = this->GetTotalBet();
		int iNewCredits = iCurrCredits - iCurrTotalBet;
		this->m_baseGame.SetICredits(iNewCredits);

		//init the reels and set the paylines
		this->InitCurrentReels();
		this->InitCurrentPaylines();

		//Calculate the winnings from the spin
		this->SetTotalWin();
	} // end if
}

//intialize the reels for the currentGame
void GameController::InitCurrentReels()
{
//	this->InitRandomReels();
//	this->SetSpecialFigure();
//	this->SetUniqueFigures();

	this->SetTheSameFigures();
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
			GameModel::m_iGameReels[iRow][iCol] = randomFigure;
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
				GameModel::m_iGameReels[iRow][iCol] = randomFigure;
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
			while (GameModel::m_iGameReels[iRow][iCol] == eInvalidFigure)
			{
				//pick a random figure
				Figures randomFigure = static_cast<Figures>(rand() % eFigure9);
				//check to see if it hasn't been selected
				if (m_bFigureIsSelected[randomFigure] == false)
				{
					//if it hasn't been selected, set the bool value to true
					GameModel::m_iGameReels[iRow][iCol] = randomFigure;
					m_bFigureIsSelected[randomFigure] = true;
					//if the selected figure is Special
					if(randomFigure == eFigure9)
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
			GameModel::m_iGameReels[iRow][iCol] = randFigure;
		} //end row for
	} // end reel for
}

//Function to initialize the lines
void GameController::InitCurrentPaylines()
{
	//empty the vector of lines
	this->m_baseGame.m_vecPaylines.erase(m_baseGame.m_vecPaylines.begin(),
			m_baseGame.m_vecPaylines.end());
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

GameController::~GameController()
{
// TODO Auto-generated destructor stub
}

//set the total bet
void GameController::SetTotalBet()
{
	this->m_baseGame.SetITotalBet();
}

//set the number of paylines for the current game
void GameController::SetNumberOfPaylines(int iNumberOfPaylines)
{
	this->m_baseGame.SetINumberOfLines(iNumberOfPaylines);
}

//increase the number of paylines
void GameController::IncreasePaylines()
{
	int iNumPayLines = this->m_baseGame.GetINumberOfLines();

//check if the number of paylines doesn't exceed the max value
	if (iNumPayLines < MAX_PAYLINES)
	{
		int iLineIncrement = iNumPayLines + 1;
//check if the payLines don't cause the total bet to exceed the
//current amount of credits
		if (!(this->PaylinesExceedCredits(iLineIncrement)))
		{
			this->SetNumberOfPaylines(++iNumPayLines);
			this->SetTotalBet();
		}

	}
}

//decrease the number of paylines
void GameController::DecreasePaylines()
{
	int iNumPayLines = this->m_baseGame.GetINumberOfLines();
	if (iNumPayLines > MIN_PAYLINES)
	{
		this->SetNumberOfPaylines(--iNumPayLines);
		this->SetTotalBet();
	}
}

//set the bet per line, depending on the number of steps
void GameController::SetBetPerPayline(int iStep)
{
	int iBet = this->m_vecBetPerStep[iStep];
	this->m_baseGame.SetIBetPerLine(iBet);
}

//increase the bet by 1 step
void GameController::IncreaseBet()
{
	int iCurrentStep = GameController::m_iBetStep;
//check if the betting step doesn't exceed the max value
	if (iCurrentStep <= MAX_BET_STEP)
	{
		int iNextStep = iCurrentStep + 1;
//check if the incremented step doesn't cause
//total bet to exceed the current amount of credits
		if (!(this->BetExceedsCredits(iNextStep)))
		{
			GameController::m_iBetStep++;
			this->SetBetPerPayline(GameController::m_iBetStep);
			this->SetTotalBet();
		}
	}
}

//decrease the bet by 1 step
void GameController::DecreaseBet()
{
	if (GameController::m_iBetStep > 0)
	{
		GameController::m_iBetStep--;
		this->SetBetPerPayline(GameController::m_iBetStep);
		this->SetTotalBet();
	}

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

//set the total winnnings from the paylines and bonus game
void GameController::SetTotalWin()
{
	this->WinFromPaylines();

}


//calculate the win from the selected paylines
void GameController::WinFromPaylines()
{
	int winFromPaylines = 0;
	for (int i = 0; i < this->GetNumberOfLines(); i++)
	{
		Payline currentPayline = this->m_baseGame.m_vecPaylines[i];
		winFromPaylines += this->WinFromSinglePayline(currentPayline);
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

//quit the bonus game
bool GameController::QuitBonusGame()
{
	GameController::m_bQuitBonusGame = true;
	return GameController::m_bQuitBonusGame;
}
//bonus game round1
void GameController::BonusWin1(const COLOR& playerChoice)
{
	int newWin = -1;
	if(this->m_bonusGame.RoundOne(playerChoice))
	{
		newWin = 2 * this->GetWin();
	} else
	{
		newWin = 0;
	}
	this->m_baseGame.SetIWin(newWin);
	//TODO Update Credits

}

//bonus game round2
void GameController::BonusWin2(const COLOR& playerChoice)
{
	int newWin = -1;
	if(this->m_bonusGame.RoundTwo(playerChoice))
	{
		newWin = 2 * this->GetWin();
	} else
	{
		newWin = 0;
	}
	this->m_baseGame.SetIWin(newWin);
	//TODO Update Credits
}

//if player wants to play bonus game round 1
void GameController::PlayBonusRoundOne()
{
	//if the player choice is valid
	if(GameController::m_playerChoice == eBlack
			|| GameController::m_playerChoice == eRed)
	{
		this->BonusWin1(GameController::m_playerChoice);
	}

}

//if player wants to play bonus game round 2
void GameController::PlayBonusRoundTwo()
{

}

//if player selected a black card
void GameController::SelectBlackCard()
{
	GameController::m_playerChoice = eBlack;
}

//if the player selected a red card
void GameController::SelectRedCard()
{
	GameController::m_playerChoice = eRed;
}

//Getters
int GameController::GetBetPerLine() const
{
	return this->m_baseGame.GetIBetPerLine();
}

int GameController::GetCredits() const
{
	return this->m_baseGame.GetICredits();
}

int GameController::GetNumberOfLines() const
{
	return this->m_baseGame.GetINumberOfLines();
}

int GameController::GetTotalBet() const
{
	return this->m_baseGame.GetITotalBet();
}

int GameController::GetWin() const
{
	return this->m_baseGame.GetIWin();
}

//printing functions
void GameController::PrintReels() const
{
	for (int iRow = 0; iRow < GAME_ROWS; iRow++)
	{
		for (int iCol = 0; iCol < GAME_REELS; iCol++)
		{
			cout << GameModel::m_iGameReels[iRow][iCol] << "\t";
		}
		cout << endl;
	}
}

void GameController::PrintPayline(const Payline& payline) const
{
	for (int i = 0; i < GAME_REELS; i++)
	{
		cout << payline.figure[i] << "\t";
	}
	cout << endl;
}

void GameController::PrintPaylines() const
{
	for (int i = 0; i < this->m_baseGame.m_vecPaylines.size(); i++)
	{
		cout << "PayLine " << i + 1 << ":\t";
		this->PrintPayline(this->m_baseGame.m_vecPaylines[i]);
	}
}

void GameController::PrintCredits() const
{
	cout << "Credits: " << this->m_baseGame.GetICredits() << endl;
}

void GameController::PrintBetPerLine() const
{
	cout << "BetPerLine: " << this->m_baseGame.GetIBetPerLine() << endl;
}

void GameController::PrintNumLines() const
{
	cout << "Number of Paylines: " << this->m_baseGame.GetINumberOfLines() << endl;
}

void GameController::PrintTotalBet() const
{
	cout << "Total Bet: " << this->m_baseGame.GetITotalBet() << endl;
}

void GameController::PrintWin() const
{
	cout << "Win: " << this->m_baseGame.GetIWin() << endl;
}
//initialize each payline individually
void GameController::InitPayline1()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[1][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[1][2],
			this->m_baseGame.m_iGameReels[1][3],
			this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline2()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[0][0], this->m_baseGame.m_iGameReels[0][1],
			this->m_baseGame.m_iGameReels[0][2],
			this->m_baseGame.m_iGameReels[0][3],
			this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline3()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[2][0], this->m_baseGame.m_iGameReels[2][1],
			this->m_baseGame.m_iGameReels[2][2],
			this->m_baseGame.m_iGameReels[2][3],
			this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline4()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[0][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[2][2],
			this->m_baseGame.m_iGameReels[1][3],
			this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline5()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[2][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[0][2],
			this->m_baseGame.m_iGameReels[1][3],
			this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline6()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[0][2], this->m_baseGame.m_iGameReels[0][1],
			this->m_baseGame.m_iGameReels[1][2],
			this->m_baseGame.m_iGameReels[0][3],
			this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline7()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[2][0], this->m_baseGame.m_iGameReels[2][1],
			this->m_baseGame.m_iGameReels[1][2],
			this->m_baseGame.m_iGameReels[2][3],
			this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline8()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[1][0], this->m_baseGame.m_iGameReels[0][1],
			this->m_baseGame.m_iGameReels[0][2],
			this->m_baseGame.m_iGameReels[0][3],
			this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline9()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[1][0], this->m_baseGame.m_iGameReels[2][1],
			this->m_baseGame.m_iGameReels[2][2],
			this->m_baseGame.m_iGameReels[2][3],
			this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline10()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[1][0], this->m_baseGame.m_iGameReels[0][1],
			this->m_baseGame.m_iGameReels[1][2],
			this->m_baseGame.m_iGameReels[0][3],
			this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline11()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[1][0], this->m_baseGame.m_iGameReels[2][1],
			this->m_baseGame.m_iGameReels[1][2],
			this->m_baseGame.m_iGameReels[2][3],
			this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline12()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[0][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[0][2],
			this->m_baseGame.m_iGameReels[1][3],
			this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline13()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[2][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[2][2],
			this->m_baseGame.m_iGameReels[1][3],
			this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline14()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[1][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[0][2],
			this->m_baseGame.m_iGameReels[1][3],
			this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline15()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[1][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[2][2],
			this->m_baseGame.m_iGameReels[1][3],
			this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline16()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[0][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[1][2],
			this->m_baseGame.m_iGameReels[1][3],
			this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline17()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[2][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[1][2],
			this->m_baseGame.m_iGameReels[1][3],
			this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline18()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[0][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[2][2],
			this->m_baseGame.m_iGameReels[2][3],
			this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline19()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[2][0], this->m_baseGame.m_iGameReels[1][1],
			this->m_baseGame.m_iGameReels[0][2],
			this->m_baseGame.m_iGameReels[0][3],
			this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline20()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[0][0], this->m_baseGame.m_iGameReels[2][1],
			this->m_baseGame.m_iGameReels[0][2],
			this->m_baseGame.m_iGameReels[2][3],
			this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline21()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[2][0], this->m_baseGame.m_iGameReels[0][1],
			this->m_baseGame.m_iGameReels[2][2],
			this->m_baseGame.m_iGameReels[0][3],
			this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline22()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[1][0], this->m_baseGame.m_iGameReels[0][1],
			this->m_baseGame.m_iGameReels[2][2],
			this->m_baseGame.m_iGameReels[0][3],
			this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline23()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[1][0], this->m_baseGame.m_iGameReels[2][1],
			this->m_baseGame.m_iGameReels[0][2],
			this->m_baseGame.m_iGameReels[2][3],
			this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline24()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[0][0], this->m_baseGame.m_iGameReels[0][1],
			this->m_baseGame.m_iGameReels[1][2],
			this->m_baseGame.m_iGameReels[2][3],
			this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline25()
{
	Payline line =
	{ this->m_baseGame.m_iGameReels[2][0], this->m_baseGame.m_iGameReels[2][1],
			this->m_baseGame.m_iGameReels[1][2],
			this->m_baseGame.m_iGameReels[0][3],
			this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}
