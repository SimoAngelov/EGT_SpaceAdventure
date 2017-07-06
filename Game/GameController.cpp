/*
 * GameController.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#include "GameController.h"

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
			int figure = rand() % eFigure8;
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
			int figure = 7 + rand() % eFigure9;
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
	for(int i = 0; i < GAME_REELS; i++)
	{
		cout << payline.figure[i] << "\t";
	}
	cout << endl;
}
void GameController::PrintPaylines() const
{
	for(int i = 0; i < this->m_baseGame.m_vecPaylines.size(); i++)
	{
		this->PrintPayline(this->m_baseGame.m_vecPaylines[i]);
	}
}

GameController::~GameController()
{
	// TODO Auto-generated destructor stub
}

//Functions to initialize the lines
void GameController::InitCurrentPayLines()
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

void GameController::InitPayline1()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[1][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[1][2],
					this->m_baseGame.m_iGameReels[1][3],
					this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline2()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[0][0],
					this->m_baseGame.m_iGameReels[0][1],
					this->m_baseGame.m_iGameReels[0][2],
					this->m_baseGame.m_iGameReels[0][3],
					this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline3()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[2][0],
					this->m_baseGame.m_iGameReels[2][1],
					this->m_baseGame.m_iGameReels[2][2],
					this->m_baseGame.m_iGameReels[2][3],
					this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline4()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[0][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[2][2],
					this->m_baseGame.m_iGameReels[1][3],
					this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline5()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[2][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[0][2],
					this->m_baseGame.m_iGameReels[1][3],
					this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline6()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[0][2],
					this->m_baseGame.m_iGameReels[0][1],
					this->m_baseGame.m_iGameReels[1][2],
					this->m_baseGame.m_iGameReels[0][3],
					this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline7()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[2][0],
					this->m_baseGame.m_iGameReels[2][1],
					this->m_baseGame.m_iGameReels[1][2],
					this->m_baseGame.m_iGameReels[2][3],
					this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline8()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[1][0],
					this->m_baseGame.m_iGameReels[0][1],
					this->m_baseGame.m_iGameReels[0][2],
					this->m_baseGame.m_iGameReels[0][3],
					this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline9()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[1][0],
					this->m_baseGame.m_iGameReels[2][1],
					this->m_baseGame.m_iGameReels[2][2],
					this->m_baseGame.m_iGameReels[2][3],
					this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline10()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[1][0],
					this->m_baseGame.m_iGameReels[0][1],
					this->m_baseGame.m_iGameReels[1][2],
					this->m_baseGame.m_iGameReels[0][3],
					this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline11()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[1][0],
					this->m_baseGame.m_iGameReels[2][1],
					this->m_baseGame.m_iGameReels[1][2],
					this->m_baseGame.m_iGameReels[2][3],
					this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline12()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[0][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[0][2],
					this->m_baseGame.m_iGameReels[1][3],
					this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline13()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[2][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[2][2],
					this->m_baseGame.m_iGameReels[1][3],
					this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline14()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[1][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[0][2],
					this->m_baseGame.m_iGameReels[1][3],
					this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline15()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[1][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[2][2],
					this->m_baseGame.m_iGameReels[1][3],
					this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline16()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[0][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[1][2],
					this->m_baseGame.m_iGameReels[1][3],
					this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline17()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[2][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[1][2],
					this->m_baseGame.m_iGameReels[1][3],
					this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline18()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[0][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[2][2],
					this->m_baseGame.m_iGameReels[2][3],
					this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline19()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[2][0],
					this->m_baseGame.m_iGameReels[1][1],
					this->m_baseGame.m_iGameReels[0][2],
					this->m_baseGame.m_iGameReels[0][3],
					this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline20()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[0][0],
					this->m_baseGame.m_iGameReels[2][1],
					this->m_baseGame.m_iGameReels[0][2],
					this->m_baseGame.m_iGameReels[2][3],
					this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline21()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[2][0],
					this->m_baseGame.m_iGameReels[0][1],
					this->m_baseGame.m_iGameReels[2][2],
					this->m_baseGame.m_iGameReels[0][3],
					this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline22()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[1][0],
					this->m_baseGame.m_iGameReels[0][1],
					this->m_baseGame.m_iGameReels[2][2],
					this->m_baseGame.m_iGameReels[0][3],
					this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline23()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[1][0],
					this->m_baseGame.m_iGameReels[2][1],
					this->m_baseGame.m_iGameReels[0][2],
					this->m_baseGame.m_iGameReels[2][3],
					this->m_baseGame.m_iGameReels[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline24()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[0][0],
					this->m_baseGame.m_iGameReels[0][1],
					this->m_baseGame.m_iGameReels[1][2],
					this->m_baseGame.m_iGameReels[2][3],
					this->m_baseGame.m_iGameReels[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline25()
{
	Payline line =
			{ this->m_baseGame.m_iGameReels[2][0],
					this->m_baseGame.m_iGameReels[2][1],
					this->m_baseGame.m_iGameReels[1][2],
					this->m_baseGame.m_iGameReels[0][3],
					this->m_baseGame.m_iGameReels[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}
