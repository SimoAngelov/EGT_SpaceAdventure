/*
 * GameModel.h
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#ifndef GAMEMODEL_H_
#define GAMEMODEL_H_

#include "..\..\Globals.h"
class GameModel
{
	friend class GameController;
private:
	//vector of vectors to hold the reels
	vector<vector<Figures> > m_matrixGameReels;
	int m_iNumberOfLines;
	int m_iBetPerLine;
	int m_iWin;
	int m_iCredits;
	int m_iTotalBet;
protected:
	static vector<Payline> m_vecPaylines;

public:
	GameModel(int iNumberOfLines = 1, int iBetPerLine = 1, int iWin = 0,
			int iCredits = 0, int iTotalBet = 1);
	void InitDefaultReels();
	void SetReelElement(const Figures&, int, int);
	const Figures GetReelElement(int, int) const;
	static void InitVecPaylines();
	virtual ~GameModel();
	const vector<vector<Figures> >& GetMatrixGameReels() const;
	int GetIBetPerLine() const;
	void SetIBetPerLine(int iBetPerLine);
	int GetICredits() const;
	void SetICredits(int iCredits);
	int GetINumberOfLines() const;
	void SetINumberOfLines(int iNumberOfLines);
	int GetITotalBet() const;
	void SetITotalBet();
	int GetIWin() const;
	void SetIWin(int iWin);

	//print
	void PrintReels() const;

};

#endif /* GAMEMODEL_H_ */
