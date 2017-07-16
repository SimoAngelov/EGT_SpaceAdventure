/*
 * GameRecovery.h
 *
 *  Created on: Jul 16, 2017
 *      Author: SimoAngelov
 */

#ifndef CONTROLLER_GAMERECOVERY_GAMERECOVERY_H_
#define CONTROLLER_GAMERECOVERY_GAMERECOVERY_H_

#include "XML/pugixml.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class GameRecovery
{
private:
	static pugi::xml_document m_doc;
	static pugi::xml_node m_rootNode;
public:
	GameRecovery();
	//creates a blank save
	static void CreateBlankSave();
	//updates the document
	static bool Update();
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
