/*
 * BonusGame.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#include "BonusGame.h"

//member field to increment the seed additionally each time srand is called
int BonusGame::m_iRandCounter = 0;

//member field to check if round2 is availabe
bool BonusGame::m_bContinueToRound2 = false;
BonusGame::BonusGame():
		m_playerChoice(eInvalid1),
		m_bonusGameResult(eInvalid2)
{
	// TODO Auto-generated constructor stub
}

bool BonusGame::IsBonusGame(int iBonusCounter) const
{
	return iBonusCounter == BONUS_GAME;
}

void BonusGame::SetBonusGameResult()
{
	srand(time(0) + (BonusGame::m_iRandCounter++));
	this->m_bonusGameResult = static_cast<COLOR>(rand()% eNUM_COLORS);
}

void BonusGame::PlayerSelectedBlack()
{
	this->m_playerChoice = eBlack;
}

void BonusGame::PlayerSelectedRed()
{
	this->m_playerChoice = eRed;
}

bool BonusGame::PlayerWon() const
{
	return this->m_playerChoice == this->m_bonusGameResult;
}

bool BonusGame::RoundOne(const COLOR& playerChoice)
{
	this->SetBonusGameResult();
	switch(playerChoice)
	{
	case eBlack:
		this->PlayerSelectedBlack();
		break;
	case eRed:
		this->PlayerSelectedRed();
		break;
	default:
		this->m_playerChoice = eInvalid1;
		break;
	}
	//ternary operator to check if the player continues to round two
	BonusGame::m_bContinueToRound2 =
			(this->PlayerWon) ? true: false;
	return this->PlayerWon();
}

bool BonusGame::RoundTwo(const COLOR& playerChoice)
{
	if(BonusGame::m_bContinueToRound2)
	{
		return this->RoundOne(playerChoice);
	} else
	{
		return false;
	}
}

BonusGame::~BonusGame()
{
	// TODO Auto-generated destructor stub
}

