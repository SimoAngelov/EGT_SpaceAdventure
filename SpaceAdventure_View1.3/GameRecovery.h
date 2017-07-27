/*
 * GameRecovery.h
 *
 *  Created on: Jul 16, 2017
 *      Author: SimoAngelov
 */

#ifndef CONTROLLER_GAMERECOVERY_GAMERECOVERY_H_
#define CONTROLLER_GAMERECOVERY_GAMERECOVERY_H_

#include "pugixml.hpp"
#include "Globals.h"
#include "GameModel.h"


class GameRecovery
{
public:
	GameRecovery();
	//check if an xml save document exists
	static bool IsSaveGame();
	//creates a blank save
	static void CreateBlankSave();
	//loads the document
	static void LoadDoc(pugi::xml_document*);
	//updates the document
	static void UpdateDoc(pugi::xml_document*);
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
	//update the game mode;
	static void UpdateGameModel(const GameModel*);
	//load functions
	static int LoadView();
	static int LoadVolume();
	static void LoadReels(GameModel*);
	static int LoadNumberOfPaylines();
	static int LoadBetPerPayline();
	static int LoadTotalBet();
	static int LoadWin();
	static int LoadCredits();
	static void LoadGameModel(GameModel*);
	virtual ~GameRecovery();
private:
	//add view node to root node
	static void AddViewToRoot(pugi::xml_node&);
	//add volume node to root node
	static void AddVolumeToRoot(pugi::xml_node&);
	//add reels node to root node
	static void AddReelsToRoot(pugi::xml_node&);
	//add paylines node to root node
	static void AddPaylinesToRoot(pugi::xml_node&);
	//add number of paylines node to root node
	static void AddNumberOfPaylinesToRoot(pugi::xml_node&);
	//add bet per line node to root node
	static void AddBetPerLineToRoot(pugi::xml_node&);
	//add total bet node to root node
	static void AddTotalBetToRoot(pugi::xml_node&);
	//add win node to root node
	static void AddWinToRoot(pugi::xml_node&);
	//add credits node to rood node
	static void AddCreditsToRoot(pugi::xml_node&);
};

#endif /* CONTROLLER_GAMERECOVERY_GAMERECOVERY_H_ */
