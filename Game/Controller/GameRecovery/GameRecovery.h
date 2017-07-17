/*
 * GameRecovery.h
 *
 *  Created on: Jul 16, 2017
 *      Author: SimoAngelov
 */

#ifndef CONTROLLER_GAMERECOVERY_GAMERECOVERY_H_
#define CONTROLLER_GAMERECOVERY_GAMERECOVERY_H_

#include "XML/pugixml.hpp"
#include "../../Globals/Globals.h"
#include "../../Model/GameModel.h"
class GameRecovery
{
private:
	static pugi::xml_node m_rootNode;
public:
	GameRecovery();
	//creates a blank save
	static void CreateBlankSave();
	//loads the document
	static void LoadDoc(pugi::xml_document&);
	//updates the document
	static void UpdateDoc(pugi::xml_document&);
	//update the view
	static void UpdateView(int);
	//update the volume
	static void UpdateVolume(int);
	//update the reels
	static void UpdateReels(const vector<vector <Figures> >&);
	//update the paylines
	static void UpdatePaylines(const vector<Payline> &);
	//update the number of paylines
	static void UpdateNumberOfPaylines(int);
	//update the bet per payline
	static void UpdateBetPerPayline(int);
	//update the total bet
	static void UpdateTotalBet(int);
	//update the win
	static void UpdateWin(int);
	//update the credits
	static void UpdateCredits(int);
	//update the bonus game
	static void UpdateBonusGameResult(const COLOR&);
	static void UpdateBonusPlayerChoice(const COLOR&);
	//update the game mode;
	static void UpdateGameModel(const GameModel*);
	virtual ~GameRecovery();
private:
	//add view node to root node
	static void AddViewToRoot();
	//add volume node to root node
	static void AddVolumeToRoot();
	//add reels node to root node
	static void AddReelsToRoot();
	//add paylines node to root node
	static void AddPaylinesToRoot();
	//add number of paylines node to root node
	static void AddNumberOfPaylinesToRoot();
	//add bet per line node to root node
	static void AddBetPerLineToRoot();
	//add total bet node to root node
	static void AddTotalBetToRoot();
	//add win node to root node
	static void AddWinToRoot();
	//add credits node to rood node
	static void AddCreditsToRoot();
	//add bonus game node to root node
	static void AddBonusGameToRoot();
};

#endif /* CONTROLLER_GAMERECOVERY_GAMERECOVERY_H_ */
