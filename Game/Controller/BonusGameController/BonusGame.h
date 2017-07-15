/*
 * BonusGame.h
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#ifndef BONUSGAME_H_
#define BONUSGAME_H_
#include "..\..\Globals.h"
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
	static bool m_bIsRound[eNUM_ROUNDS];
	static int m_iRound;
	static bool m_bQuitBonusGame;

public:
	BonusGame();
	//if 5 special figures have appeared
	static bool IsBonusGame(int);
	//initialize the member fields
	static void InitBonusGame(GameModel*);
	//return the bonus win
	static int GetWin();
	//if the plater selected black
	static void PlayerSelectedBlack();
	//if the player selected red
	static void PlayerSelectedRed();
	//play a bonus game round
	static void PlayBonusRound();
	//TEST: win the bonus round
	static void WinBonusRound();
	//return the status of the quit member field
	static bool IsQuitBonusGame();
	//quit the bonus game
	static void QuitBonusGame();
	virtual ~BonusGame();
private:
	static void SetBonusGameResult();
	//update the win and credits in case of a win
	//if the player won
	static bool PlayerWon();
	//update the win and credits of the bonus game and game model
	//parameter is a boolean value to check for a win
	static void UpdateGameModel();
	//set a value for the bonus game result
	static void UpdateIfWin();
	//update the win and credits in case of a loss
	static void UpdateIfLoss();
	//check if the bet is valid
	static bool IsValidBet();
	//attempt at doubling the wins
	static void RoundOne();
	//attempt at try at quadrupling the wins
	static void RoundTwo();
	//try to double up the wins from the game controller
	static void DoubleUpWins();
	//update the win and credits
	static void UpdateWinAndCredits();
};

#endif /* BONUSGAME_H_ */
