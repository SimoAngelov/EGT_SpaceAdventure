/*
 * BonusGame.h
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#ifndef BONUSGAME_H_
#define BONUSGAME_H_
#include "..\..\Globals\Globals.h"
#include "..\..\Model\GameModel.h"

class BonusGame
{
private:
	static GameModel* m_baseGamePtr;
	static int m_iRandCounter;
	static COLOR m_playerChoice;
	static COLOR m_bonusGameResult;
	static int m_iCredits;
	static int m_iBet;
	static int m_iGameWin;
	static int m_iBonusWin;
	static bool m_bWonRound1;
	static int m_iRound;
	static bool m_bQuitBonusGame;

public:
	BonusGame();
	//if 5 special figures have appeared
	static bool IsBonusGame(int);
	//initialize the member fields
	static void InitBonusGame(GameModel*);
	//get the bonus game result
	static COLOR GetBonusGameResult();
	//get the player choice
	static COLOR GetPlayerChoice();
	//return the bonus win
	static int GetWin();
	//if the plater selected black
	static void PlayerSelectedBlack();
	//if the player selected red
	static void PlayerSelectedRed();
	//play a bonus game round
	static void PlayBonusRound();
	//gamble amount
	static string GambleAmount();
	//amount to win
	static string GambleToWin();
	//return the status of the quit member field
	static bool IsQuitBonusGame();
	//quit the bonus game
	static void QuitBonusGame();
	virtual ~BonusGame();
private:
	//set a random color as the bonus game result
	static void SetBonusGameResult();
	//if the player won
	static bool PlayerWon();
	//set a value for the bonus game result
	static void UpdateIfWin();
	//update the win and credits in case of a loss
	static void UpdateIfLoss();
	//check if the bet is valid
	static bool IsValidBet();
	//try to double up the wins from the game controller
	static void DoubleUpWins();
	//update the win and credits
	static void UpdateWinAndCredits();
	//set player choice and bonus game result to defaul
	static void SetDefault();
};

#endif /* BONUSGAME_H_ */

