/*
 * GameModel.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#include "GameModel.h"

Figures GameModel::m_iGameReels[3][5] =
{ eInvalidFigure };
vector<Payline> GameModel::m_vecPaylines;

GameModel::GameModel(int iNumberOfLines, int iBetPerLine, int iWin,
		int iCredits, int iTotalBet) :
		m_iNumberOfLines(iNumberOfLines), m_iBetPerLine(iBetPerLine),
		m_iWin(iWin), m_iCredits(iCredits), m_iTotalBet(iTotalBet)
{
	this->SetITotalBet();
}

//initialize the game reels with default values
void GameModel::InitReels()
{
	for (int iRow = 0; iRow < GAME_ROWS; iRow++)
	{
		for (int iCol = 0; iCol < GAME_REELS; iCol++)
		{
			GameModel::m_iGameReels[iRow][iCol] = eInvalidFigure;
		}
	}
}

//initialize the game lines with default values
void GameModel::InitVecPaylines()
{
	for (int i = 0; i < MAX_PAYLINES; i++)
	{
		Payline line =
		{ eInvalidFigure };
		GameModel::m_vecPaylines.push_back(line);
	}
}

GameModel::~GameModel()
{
	// TODO Auto-generated destructor stub
}

int GameModel::GetIBetPerLine() const
{
	return m_iBetPerLine;
}

//the bet perLine must have a value between 1 and 2000
void GameModel::SetIBetPerLine(int iBetPerLine)
{
	if(iBetPerLine >= 1 && iBetPerLine <= MAX_BET)
	{
	m_iBetPerLine = iBetPerLine;
	}
}

int GameModel::GetICredits() const
{
	return m_iCredits;
}

//avoid Setting a negative credit ammount
void GameModel::SetICredits(int iCredits)
{
	if(iCredits >= 0)
	{
	m_iCredits = iCredits;
	}
}

int GameModel::GetINumberOfLines() const
{
	return m_iNumberOfLines;
}

//the lines must have a value between 1 and 25
void GameModel::SetINumberOfLines(int iNumberOfLines)
{
	if(iNumberOfLines >= 1 && iNumberOfLines <= MAX_PAYLINES)
	{
	m_iNumberOfLines = iNumberOfLines;
	}
}

int GameModel::GetITotalBet() const
{
	return m_iTotalBet;
}

//the total bet is the product of the bet per line and the number of lines
void GameModel::SetITotalBet()
{
	m_iTotalBet = this->GetIBetPerLine() * this->m_iNumberOfLines;
}

int GameModel::GetIWin() const
{
	return m_iWin;
}

void GameModel::SetIWin(int iWin)
{
	if(iWin >= 0)
	{
	m_iWin = iWin;
	}
}
