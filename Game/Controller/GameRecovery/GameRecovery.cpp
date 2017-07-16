/*
 * GameRecovery.cpp
 *
 *  Created on: Jul 16, 2017
 *      Author: SimoAngelov
 */

#include "GameRecovery.h"

// Generate new XML document within memory
pugi::xml_document GameRecovery::m_doc;

//the root node of the xml document
pugi::xml_node GameRecovery::m_rootNode;

//constructor
GameRecovery::GameRecovery()
{
	// TODO Auto-generated constructor stub

}

//destructor
GameRecovery::~GameRecovery()
{
	// TODO Auto-generated destructor stub
}

//create a blank save
void GameRecovery::CreateBlankSave()
{
	//append root node to the xml_document
	m_rootNode = m_doc.append_child("Game");
	//append the necessary nodes to the root node
	GameRecovery::AddViewToRoot();
	GameRecovery::AddVolumeToRoot();
	GameRecovery::AddReelsToRoot();
	GameRecovery::AddPaylinesToRoot();
	GameRecovery::AddNumberOfPaylinesToRoot();
	GameRecovery::AddBetPerLineToRoot();
	GameRecovery::AddTotalBetToRoot();
	GameRecovery::AddWinToRoot();
	GameRecovery::AddCreditsToRoot();
	GameRecovery::AddBonusGameToRoot();
	// test cout
	//save document to file
	std::cout << "Saving result... ";
	GameRecovery::UpdateDoc();
	// end::code[]
}

//add view node to root node
void GameRecovery::AddViewToRoot()
{
	//append view number to the root node
	pugi::xml_node viewNode = m_rootNode.append_child("View");
	//append value attribute to the view node
	viewNode.append_attribute("Value") = 1;
}

//add volume node to root node
void GameRecovery::AddVolumeToRoot()
{
	//append music volume to the root node
	pugi::xml_node volumeNode = m_rootNode.append_child("Volume");
	//append value attribute to the volume node
	volumeNode.append_attribute("Value") = 1;
}

//add reels node to root node
void GameRecovery::AddReelsToRoot()
{
	//append the game reels to the root node
	pugi::xml_node reelsNode = m_rootNode.append_child("Reels");
	//append individual reels to the reelsNode
	for (int i = 0; i < GAME_REELS; i++)
	{
		//append a reel node to the reels node
		pugi::xml_node reelNode = reelsNode.append_child("Reel");
		//append an index attribute to the current reel node
		reelNode.append_attribute("Index") = i;
		//append figures to the current reel node
		for (int j = 0; j < GAME_ROWS; j++)
		{
			//create a new figure node
			pugi::xml_node figureNode = reelNode.append_child("Figure");
			//append default attributes
			figureNode.append_attribute("Index") = j;
			figureNode.append_attribute("Value") = Figures::eInvalidFigure;
		}	//end figure for
	}	// end reel for

}

//add paylines node to root node
void GameRecovery::AddPaylinesToRoot()
{
	//append a paylines node to the root node
	pugi::xml_node paylinesNode = m_rootNode.append_child("Paylines");
	//append 25 nodes of type payline
	for (int i = 0; i < MAX_PAYLINES; i++)
	{
		//append the current payline node to the paylines node
		pugi::xml_node paylineNode = paylinesNode.append_child("Payline");
		//append index attribute to the current payline node
		paylineNode.append_attribute("Index") = i;
		//append 5 elements to each payline
		for (int j = 0; j < GAME_REELS; j++)
		{
			pugi::xml_node figureNode = paylineNode.append_child("Figure");
			//append index attribute to the current figure node
			figureNode.append_attribute("Index") = j;
			//append value attribute to the figure node
			figureNode.append_attribute("Value") = Figures::eInvalidFigure;
		} // end figure for
	} // end paylines for
}

//add number of paylines node to root node
void GameRecovery::AddNumberOfPaylinesToRoot()
{
	//append number of paylines to the root node
	pugi::xml_node numberOfPaylinesNode = m_rootNode.append_child(
			"Number_Of_Paylines");
	//append value attribute for number of paylines node
	numberOfPaylinesNode.append_attribute("Value") = MIN_PAYLINES;
}

//add bet per line node to root node
void GameRecovery::AddBetPerLineToRoot()
{
	//append  bet per line to the root node
	pugi::xml_node betPerLineNode = m_rootNode.append_child("Bet_Per_Line");
	//append value attribute for bet per line node
	betPerLineNode.append_attribute("Value") = MIN_BET;
}

//add total bet node to root node
void GameRecovery::AddTotalBetToRoot()
{
	//append the total bet to the root node
	pugi::xml_node totalBetNode = m_rootNode.append_child("Total_Bet");
	//append value attribute to the total bet node
	totalBetNode.append_attribute("Value") = MIN_BET * MIN_PAYLINES;
}

//add win node to root node
void GameRecovery::AddWinToRoot()
{
	//append the win node to the root node
	pugi::xml_node winNode = m_rootNode.append_child("Win");
	//append value attribute to the win node
	winNode.append_attribute("Value") = 0;
}

//add credits node to rood node
void GameRecovery::AddCreditsToRoot()
{
	//append the credits node to the root node
	pugi::xml_node creditsNode = m_rootNode.append_child("Credits");
	//append value attribute to the credits node
	creditsNode.append_attribute("Value") = 0;
}

//add bonus game node to root node
void GameRecovery::AddBonusGameToRoot()
{
	//append bonus game node to the root node
	pugi::xml_node bonusGameNode = m_rootNode.append_child("Bonus_Game");
	//append the game result to the bonus game node
	pugi::xml_node gameResultNode = bonusGameNode.append_child("Game_Result");
	//append value attribute the game result node
	gameResultNode.append_attribute("Value") = COLOR::eInvalidColor;
	//append player choice node to the bonus game node
	pugi::xml_node playerChoiceNode = bonusGameNode.append_child(
			"Player_Choice");
	//append value attribute to the player choice node
	playerChoiceNode.append_attribute("Value") = COLOR::eInvalidColor;
}

//load the document
void GameRecovery::LoadDoc()
{
	//open the document
	if (!(m_doc.load_file(XML_FILE_PATH.c_str())))
	{
		cerr << "Failed to open " << XML_FILE_PATH.c_str() << endl;
	}	//end update if
}

//updates the document
void GameRecovery::UpdateDoc()
{
	//save the document
	if (!(m_doc.save_file(XML_FILE_PATH.c_str())))
	{
		cerr << "Failed to update " << XML_FILE_PATH.c_str() << endl;
	}	//end update if
}

//update functions
//update the view
void GameRecovery::UpdateView(int iView)
{
	//test cout
	cout << "GameRecovery::UpdateView" << endl;
	//open the file
	GameRecovery::LoadDoc();
	//create a view node
	pugi::xml_node viewNode = m_doc.child("Game").child("View");
	//take the attribute of the view node
	pugi::xml_attribute valueAttribute = viewNode.attribute("Value");
	//test cout
	cout << "before view update: " << valueAttribute.as_int() << endl;
	//update the attribute
	if (!valueAttribute.set_value(iView))
	{
		cerr << "Failed to update the view!" << endl;
	} //end attribute if

	//update the document
	GameRecovery::UpdateDoc();
	//test cout
	cout << "after view update: " << valueAttribute.as_int() << endl;
}

//update the volume
void GameRecovery::UpdateVolume(int iVolume)
{
	//test cout
	cout << "GameRecovery::UpdateVolume" << endl;
	//load the document
	GameRecovery::LoadDoc();

	//create a volume node
	pugi::xml_node volumeNode = m_doc.child("Game").child("Volume");
	//take the attribute of the volume node
	pugi::xml_attribute valueAttribute = volumeNode.attribute("Value");
	//test cout
	cout << "before volume update: " << valueAttribute.as_int() << endl;
	//update the attribute
	if (!valueAttribute.set_value(iVolume))
	{
		cerr << "Failed to update the view!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc();

	//test cout
	cout << "after volume update: " << valueAttribute.as_int() << endl;
}

//TODO
void GameRecovery::UpdateReels(const vector<vector<Figures> >& gameReels)
{
}

//TODO
void GameRecovery::UpdatePaylines(const vector<Payline>& vecPaylines)
{
}

void GameRecovery::UpdateNumberOfPaylines(int iNumberOfPaylines)
{
	//load the document
	GameRecovery::LoadDoc();

	//create a number of paylines node
	pugi::xml_node viewNode = m_doc.child("Game").child("Number_Of_Paylines");
	//take the attribute of the number of paylines node
	pugi::xml_attribute valueAttribute = viewNode.attribute("Value");
	//test cout
	cout << "before number of paylines update: " << valueAttribute.as_int()
			<< endl;
	//update the attribute
	if (!valueAttribute.set_value(iNumberOfPaylines))
	{
		cerr << "Failed to update the number of paylines!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc();

	//test cout
	cout << "after number of paylines update: " << valueAttribute.as_int()
			<< endl;
}

void GameRecovery::UpdateBetPerPayline(int int iBetPerLine)
{
	//load the document
	GameRecovery::LoadDoc();

	//create a bet per line node
	pugi::xml_node betPerLineNode = m_doc.child("Game").child("Bet_Per_Line");
	//take the attribute of the bet per line node
	pugi::xml_attribute valueAttribute = betPerLineNode.attribute("Value");
	//test cout
	cout << "before number of bet per line update: " << valueAttribute.as_int()
			<< endl;
	//update the attribute
	if (!valueAttribute.set_value(iBetPerLine))
	{
		cerr << "Failed to update the bet per line!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc();

	//test cout
	cout << "after bet per line update: " << valueAttribute.as_int() << endl;
}

void GameRecovery::UpdateTotalBet(int iTotalBet)
{
	//load the document
	GameRecovery::LoadDoc();

	//create a total bet node
	pugi::xml_node totalBetNode = m_doc.child("Game").child("Total_Bet");
	//take the attribute of the total bet node
	pugi::xml_attribute valueAttribute = totalBetNode.attribute("Value");
	//test cout
	cout << "before total bet update: " << valueAttribute.as_int() << endl;
	//update the attribute
	if (!valueAttribute.set_value(iTotalBet))
	{
		cerr << "Failed to update the total bet!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc();

	//test cout
	cout << "after total bet update: " << valueAttribute.as_int() << endl;
}

void GameRecovery::UpdateWin(int iWin)
{
	//load the document
	GameRecovery::LoadDoc();

	//create a win node
	pugi::xml_node winNode = m_doc.child("Game").child("Win");
	//take the attribute of the win node
	pugi::xml_attribute valueAttribute = winNode.attribute("Value");
	//test cout
	cout << "before win update: " << valueAttribute.as_int() << endl;
	//update the attribute
	if (!valueAttribute.set_value(iWin))
	{
		cerr << "Failed to update the win!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc();

	//test cout
	cout << "after win update: " << valueAttribute.as_int() << endl;
}

void GameRecovery::UpdateCredits(int iCredits)
{
	//load the document
	GameRecovery::LoadDoc();

	//create a credits node
	pugi::xml_node creditsNode = m_doc.child("Game").child("Credits");
	//take the attribute of the credits node
	pugi::xml_attribute valueAttribute = creditsNode.attribute("Value");
	//test cout
	cout << "before credits update: " << valueAttribute.as_int() << endl;
	//update the attribute
	if (!valueAttribute.set_value(iCredits))
	{
		cerr << "Failed to update the credits!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc();

	//test cout
	cout << "after credits update: " << valueAttribute.as_int() << endl;
}

void GameRecovery::UpdateBonusGameResult(const COLOR& bonusGameResult)
{
	//load the document
	GameRecovery::LoadDoc();

	//create a bonus game result node
	pugi::xml_node bonusGameResultNode =
			m_doc.child("Game").child("Bonus_Game").child("Game_Result");
	//take the attribute of the bonus game result node
	pugi::xml_attribute valueAttribute = bonusGameResultNode.attribute("Value");
	//test cout
	cout << "before bonus game result update: " << valueAttribute.as_int()
			<< endl;
	//update the attribute
	if (!valueAttribute.set_value(bonusGameResult))
	{
		cerr << "Failed to update the bonus game result!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc();

	//test cout
	cout << "after bonus game result update: " << valueAttribute.as_int()
			<< endl;
}

void GameRecovery::UpdateBonusPlayerChoice(const COLOR& playerChoice)
{
	//load the document
	GameRecovery::LoadDoc();

	//create a player choice node
	pugi::xml_node playerChoiceNode =
			m_doc.child("Game").child("Bonus_Game").child("Player_Choice");
	//take the attribute of the player node
	pugi::xml_attribute valueAttribute = playerChoiceNode.attribute("Value");
	//test cout
	cout << "before player choice update: " << valueAttribute.as_int()
			<< endl;
	//update the attribute
	if (!valueAttribute.set_value(playerChoice))
	{
		cerr << "Failed to update the player choice!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc();

	//test cout
	cout << "after player choice update: " << valueAttribute.as_int()
			<< endl;
}

//load functions

