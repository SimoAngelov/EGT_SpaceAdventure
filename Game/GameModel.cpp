/*
 * GameModel.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#include "GameModel.h"

int GameModel::m_iGameReels[3][5] = {-1};
vector<Payline> GameModel::m_vecPaylines;


GameModel::GameModel(int iBet, int iMaxBet, int iWin, int iCredits) :
		m_iBet(iBet), m_iMaxBet(iMaxBet), m_iWin(iWin), m_iCredits(iCredits)
{
}

//initialize the game reels with default values
void GameModel::InitReels()
{
	for(int iRow = 0; iRow < GAME_ROWS; iRow++)
	{
		for(int iCol = 0; iCol < GAME_REELS; iCol++)
		{
			GameModel::m_iGameReels[iRow][iCol] = -1;
		}
	}
}

//initialize the game lines with default values
void GameModel::InitVecPaylines()
{
	for(int i = 0; i < MAX_PAYLINES; i++)
	{
		Payline line = {-1};
		GameModel::m_vecPaylines.push_back(line);
	}
}

GameModel::~GameModel()
{
	// TODO Auto-generated destructor stub
}

