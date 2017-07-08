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

//constructor
GameController::GameController() :
		m_baseGame()
{
	// TODO Auto-generated constructor stub
}

//insert credits in order to play the game
void GameController::InsertCredits(int iCredits)
{
	if (iCredits > 0)
	{
		int currentCredits = this->m_baseGame.GetICredits();
		int newCredits = iCredits + currentCredits;
		this->m_baseGame.SetICredits(newCredits);
	}
}

void GameController::Spin()
{
	if (this->m_baseGame.m_iTotalBet > 0)
	{
		this->InitCurrentReels();
		this->InitCurrentPaylines();
	}
}

//intialize the reels for the currentGame
void GameController::InitCurrentReels()
{
	this->InitRandomReels();
	this->SetSpecialFigure();
}

//initialize the game reels with random values
void GameController::InitRandomReels()
{
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
				break;
			} //end if
		} //end row for
	} //end reel for
}

//Function to initialize the lines
void GameController::InitCurrentPaylines()
{
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

//set the number of paylines for the current game
void GameController::SetNumberOfPaylines(int iNumberOfPaylines)
{
	this->m_baseGame.SetINumberOfLines(iNumberOfPaylines);
}

//increase the number of paylines
void GameController::IncreasePaylines()
{
	int iNumPayLines = this->m_baseGame.GetINumberOfLines();
	if(iNumPayLines < MAX_PAYLINES)
	{
		this->m_baseGame.SetINumberOfLines(++iNumPayLines);
	}
}

//decrease the number of paylines
void GameController::DecreasePaylines()
{
	int iNumPayLines = this->m_baseGame.GetINumberOfLines();
	if(iNumPayLines > MIN_PAYLINES)
	{
		this->m_baseGame.SetINumberOfLines(--iNumPayLines);
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

	if (GameController::m_iBetStep <= MAX_BET_STEP)
	{
		GameController::m_iBetStep++;
	}
	this->SetBetPerPayline(GameController::m_iBetStep);
}

//decrease the bet by 1 step
void GameController::DecreaseBet()
{
	if (GameController::m_iBetStep >= 0)
	{
		GameController::m_iBetStep--;
	}
	this->SetBetPerPayline(GameController::m_iBetStep);
}

void GameController::WinFromPaylines()
{
	int winFromPaylines = 0;
	for (int i = 0; i < this->m_baseGame.GetINumberOfLines(); i++)
	{
		Payline currentPayline = this->m_baseGame.m_vecPaylines[i];
		winFromPaylines += this->WinFromSinglePayline(currentPayline);
		cout << "Win for line" << i + 1 << ": "
				<< this->WinFromSinglePayline(currentPayline) << endl;
	}
	int currentWinnings = this->m_baseGame.GetIWin();
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
