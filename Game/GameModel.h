/*
 * GameModel.h
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#ifndef GAMEMODEL_H_
#define GAMEMODEL_H_

#include "Globals.h"
class GameModel
{
friend class GameController;
private:
	int m_iBet;
	int m_iMaxBet;
	int m_iWin;
	int m_iCredits;

protected:
	static int m_iGameReels[GAME_ROWS][GAME_REELS];
	static vector<Payline> m_vecPaylines;

public:
	GameModel(int iBet = 0, int iMax = 0,
			int iWin = 0, int iCredits = 0);
	static void InitReels();
	static void InitVecPaylines();
	virtual ~GameModel();
};

#endif /* GAMEMODEL_H_ */
