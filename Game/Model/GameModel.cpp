/*
 * GameModel.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#include "GameModel.h"

vector<Payline> GameModel::m_vecPaylines;

GameModel::GameModel(int iNumberOfLines, int iBetPerLine, int iWin,
		int iCredits, int iTotalBet) :
		m_iNumberOfLines(iNumberOfLines), m_iBetPerLine(iBetPerLine), m_iWin(
				iWin), m_iCredits(iCredits), m_iTotalBet(iTotalBet)
{
	this->SetITotalBet();
	this->InitDefaultReels();
}

//initialize the game reels with default values
void GameModel::InitDefaultReels()
{
	//vector to hold the current row
	vector<Figures> vecCurrentRow;
	//if the vector is not empty, erase its contents
	if (!vecCurrentRow.empty())
	{
		//cout << "Vector is not empty" << endl;
		vecCurrentRow.erase(vecCurrentRow.begin(), vecCurrentRow.end());
	}

	//vector, holding 3 vectors(rows), each holding 5 elements(figures)
	//a single column represent a reel

	for (int iRow = 0; iRow < GAME_ROWS; iRow++)
	{
		for (int iCol = 0; iCol < GAME_REELS; iCol++)
		{
			vecCurrentRow.push_back(eInvalidFigure);
		}
		this->m_matrixGameReels.push_back(vecCurrentRow);
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

//return an element of the game reel
const Figures GameModel::GetReelElement(int iRow, int iCol) const
{
	//if the iRow is valid
	bool bValidRow = iRow >= 0 && iRow < GAME_ROWS;
	//if the iCol argument is valid
	bool bValidCol = iCol >= 0 && iCol < GAME_REELS;
	//if both are valid get the current element
	if (bValidRow && bValidCol)
	{
		return this->m_matrixGameReels[iRow][iCol];
	}
	else
	{
		return eInvalidFigure;
	}
}

//function to set a single element of the game reel
//takes 3 parameters: a Figure, an int Row and int Col
void GameModel::SetReelElement(const Figures& figure, int iRow, int iCol)
{
	//if the iRow is valid
	bool bValidRow = iRow >= 0 && iRow < GAME_ROWS;
	//if the iCol argument is valid
	bool bValidCol = iCol >= 0 && iCol < GAME_REELS;
	//if both are valid set the current element
	if (bValidRow && bValidCol)
	{
		this->m_matrixGameReels[iRow][iCol] = figure;
	}
}

//set the game reels
void GameModel::SetMatrixGameReels(
		const vector<vector<Figures> >& matrixGameReels)
{
	m_matrixGameReels = matrixGameReels;
}

//return the game reels
const vector<vector<Figures> >& GameModel::GetMatrixGameReels() const
{
	return m_matrixGameReels;
}

int GameModel::GetIBetPerLine() const
{
	return m_iBetPerLine;
}

//the bet perLine must have a value between 1 and 2000
void GameModel::SetIBetPerLine(int iBetPerLine)
{
	if (iBetPerLine >= 1 && iBetPerLine <= MAX_BET)
	{
		m_iBetPerLine = iBetPerLine;
		//update the total bet
		this->SetITotalBet();
	}
}

int GameModel::GetICredits() const
{
	return m_iCredits;
}

//avoid Setting a negative credit ammount
void GameModel::SetICredits(int iCredits)
{
	m_iCredits = iCredits;
}

int GameModel::GetINumberOfLines() const
{
	return m_iNumberOfLines;
}

//the lines must have a value between 1 and 25
void GameModel::SetINumberOfLines(int iNumberOfLines)
{
	if (iNumberOfLines >= 1 && iNumberOfLines <= MAX_PAYLINES)
	{
		m_iNumberOfLines = iNumberOfLines;
		//update the total bet
		this->SetITotalBet();
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
	if (iWin >= 0)
	{
		m_iWin = iWin;
	}
}

//add a payline to the vector of paylines
void GameModel::AddPayline(const Payline& payline)
{
	this->m_vecPaylines.push_back(payline);
}

//return the vector of paylines
vector<Payline>& GameModel::GetVecPaylines() const
{
	return this->m_vecPaylines;
}

//print
void GameModel::PrintReels() const
{
	cout << "Game Reels: \n";
	for (int iRow = 0; iRow < GAME_ROWS; iRow++)
	{
		for (int iCol = 0; iCol < GAME_REELS; iCol++)
		{
			cout << this->GetMatrixGameReels()[iRow][iCol] << "\t";
		}
		cout << endl;
	}
	//cout << "End Print Get() XO\n\n";
}
