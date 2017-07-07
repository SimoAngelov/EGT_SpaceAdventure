/*
 * GameController.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#include "GameController.h"

//member field to control the number of betting steps
int GameController::m_iBetStep = 0;

GameController::GameController() :
		m_baseGame()
{
	// TODO Auto-generated constructor stub
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
			int iRandomFigure = rand() % eFigure8;
			Figures figure = (Figures) iRandomFigure;
			GameModel::m_iGameReels[iRow][iCol] = figure;
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
			int iRandomFigure = 7 + rand() % eFigure9;
			Figures figure = (Figures) iRandomFigure;
			if (figure == eFigure9)
			{
				//if the current figure is 9 aka special, break the inner loop
				GameModel::m_iGameReels[iRow][iCol] = figure;
				cout << "Hooray" << endl;
				break;
			} //end if
		} //end row for
	} //end reel for
}

GameController::~GameController()
{
	// TODO Auto-generated destructor stub
}
void GameController::Spin()
{
	if (this->m_baseGame.m_iTotalBet > 0)
	{
		this->InitCurrentReels();
		this->InitCurrentPaylines();
	}
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

//set the number of paylines for the current game
void GameController::SetNumberOfPaylines(int iNumberOfPaylines)
{
	this->m_baseGame.SetINumberOfLines(iNumberOfPaylines);
}

//set the bet per line, depending on the number of steps
void GameController::SetBetPerPayline(int iStep)
{
	int iBet = 0;
	switch (iStep)
	{
	case 1:
		iBet = 2;
		break;
	case 2:
		iBet = 5;
		break;
	case 3:
		iBet = 10;
		break;
	case 4:
		iBet = 25;
		break;
	case 5:
		iBet = 50;
		break;
	case 6:
		iBet = 75;
		break;
	case 7:
		iBet = 100;
		break;
	case 8:
		iBet = 250;
		break;
	case 9:
		iBet = 500;
		break;
	case 10:
		iBet = 750;
		break;
	case 11:
		iBet = 1000;
		break;
	case 12:
		iBet = 1250;
		break;
	case 13:
		iBet = 1500;
		break;
	case 14:
		iBet = 1750;
		break;
	case 15:
		iBet = MAX_BET;
		break;
	default:
		iBet = 1;
		break;
	}
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
		cout << "Win for line" << i << ": "
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
	}//end for

	//return the winnings from the line
	int winningsPerLine = this->WinPerFigure(bestFigure, iBestOccurrence);
	return winningsPerLine;
}

//calculate the win from a figure based on its weight
int GameController::WinPerFigure(const Figures& figure, int iOccurrences)
{
	int winnings = 0;
	int coefficient = 0;
	switch (iOccurrences)
	{
	case 0:
	case 1:
	case 2:
		coefficient = 0;
		winnings = 0;
		break;
	case 3:
		coefficient = 10 * iOccurrences;
		break;
	case 4:
		coefficient = 20 * iOccurrences;
		break;
	case 5:
		coefficient = 30 * iOccurrences;
		break;
	default:
		coefficient = 0;
		winnings = 0;
		break;
	}

	winnings = (1 + figure) * coefficient;
	return winnings;
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
