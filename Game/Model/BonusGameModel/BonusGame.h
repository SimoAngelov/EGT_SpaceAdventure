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
	static bool m_bContinueToRound2;
public:
	BonusGame();
	//if 5 special figures have appeared
	bool IsBonusGame(int) const;
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
	virtual ~BonusGame();
};

#endif /* BONUSGAME_H_ */
