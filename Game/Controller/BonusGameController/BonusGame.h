/*
 * BonusGame.h
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#ifndef BONUSGAME_H_
#define BONUSGAME_H_
#include "..\..\Globals.h"
class BonusGame
{
private :
	static int m_iRandCounter;
	COLOR m_playerChoice;
	COLOR m_bonusGameResult;
	static int m_iCredits;
	static int m_iBet;
	static int m_iGameWin;
	static int m_iBonusWin;
	static bool m_bIsRound[eNUM_ROUNDS];
	static bool m_bQuitBonusGame;

	static void UpdateIfWin();
	static void UpdateIfLoss();
public:
	BonusGame();
	//if 5 special figures have appeared
	static bool IsBonusGame(int);
	//initialize the member fields
	static void InitBonusGame(int, int);
	//return the bonus win
	static int GetBonusWin();
	//set a value for the bonus game result
	void SetBonusGameResult();
	//if the plater selected black
	void PlayerSelectedBlack();
	//if the player selected red
	void PlayerSelectedRed();
	//if the player won
	bool PlayerWon() const;
	//attempt at doubling the wins
	bool RoundOne(const COLOR&);
	//attempt at try at quadrupling the wins
	bool RoundTwo(const COLOR&);
	//play a bonus game round
	void PlayBonusRound();
	//return the status of the quit member field
	static bool IsQuitBonusGame();
	//quit the bonus game
	static void QuitBonusGame();
	virtual ~BonusGame();
};

#endif /* BONUSGAME_H_ */
