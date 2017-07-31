/*
 * BonusGame.h
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#ifndef BONUSGAME_H_
#define BONUSGAME_H_
#include "../../Globals/Globals.h"
#include "../../Model/GameModel.h"

class BonusGame
{
private:
	static int m_iRandCounter;
	static COLOR m_playerChoice;
	static COLOR m_bonusGameResult;
	static int m_iCredits;
	static int m_iBet;
	static int m_iBonusWin;
	static bool m_bWonRound1;
	static int m_iRound;
	static bool m_bQuitBonusGame;

public:
	BonusGame();
	//if 5 special figures have appeared
	static bool IsBonusGame(int);
	//initialize the member fields
	static void InitBonusGame();
	//get the bonus game result
	static COLOR GetBonusGameResult();
	//get the player choice
	static COLOR GetPlayerChoice();
	//return the bonus win
	static int GetBonustWin();
	//if the plater selected black
	static void PlayerSelectedBlack();
	//if the player selected red
	static void PlayerSelectedRed();
	//if the player won
	static bool PlayerWon();
	//check if valid round
	static bool IsValidRound();
	//play a bonus game round
	static void PlayBonusRound();
	//gamble amount
	static string GambleAmount();
	//amount to win
	static string GambleToWin();
	//return the bonus amount as string
	static string BonusWinAsString();
	//return the status of the quit member field
	static bool IsQuitBonusGame();
	//quit the bonus game
	static void QuitBonusGame();
	//test methods
	static void PrintInfo();
	static string TestStringPlayerChoice();
	static string TestStringBonusGameResult();
	static string TestStringPlayerWon();
	virtual ~BonusGame();
private:
	//set a random color as the bonus game result
	static void SetBonusGameResult();
	//check if the bet is valid
	static bool IsValidBet();
	//try to double up the wins from the game controller
	static void DoubleUpWins();
	//update the win and credits
	static void UpdateWinAndCredits(bool);
	//save the win and credits to xml
	static void SaveWinAndCredits();
	//set player choice and bonus game result to defaul
	static void SetDefault();
};

#endif /* BONUSGAME_H_ */
