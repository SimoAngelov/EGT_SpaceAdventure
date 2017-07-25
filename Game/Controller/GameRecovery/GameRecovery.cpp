/*
 * GameRecovery.cpp
 *
 *  Created on: Jul 16, 2017
 *      Author: SimoAngelov
 */

//TODO recovery randomly crashes when program finishes executing
#include "GameRecovery.h"

//XML node names
const char* STR_ROOT = "Game";
const char* STR_VIEW = "View";
const char* STR_VOLUME = "Volume";
const char* STR_REELS = "Reels";
const char* STR_ROW = "Row";
const char* STR_FIGURE = "Figure";
const char* STR_NUMBER_OF_PAYLINES = "Number_Of_Paylines";
const char* STR_BET_PER_LINE = "Bet_Per_Line";
const char* STR_TOTAL_BET = "Total_Bet";
const char* STR_WIN = "Win";
const char* STR_CREDITS = "Credits";
const char* STR_BONUS_GAME = "Bonus_Game";
const char* STR_PLAYER_CHOICE = "Player_Choice";
//XML attribute names
const char* STR_INDEX = "Index";
const char* STR_VALUE = "Value";


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

//check if an xml save document exists
bool GameRecovery::IsSaveGame()
{
	//create an xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//check if the document loads
	bool result = docPtr->load_file(XML_FILE_PATH.c_str());
	//delete the doc pointer
	delete docPtr;
	docPtr = NULL;
	return result;
}

//create a blank save
void GameRecovery::CreateBlankSave()
{
	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//append root node to the xml_document*
	pugi::xml_node rootNode = docPtr->append_child(STR_ROOT);
	//append the necessary nodes to the root node
	GameRecovery::AddViewToRoot(rootNode);
	GameRecovery::AddVolumeToRoot(rootNode);
	GameRecovery::AddReelsToRoot(rootNode);
	GameRecovery::AddNumberOfPaylinesToRoot(rootNode);
	GameRecovery::AddBetPerLineToRoot(rootNode);
	GameRecovery::AddTotalBetToRoot(rootNode);
	GameRecovery::AddWinToRoot(rootNode);
	GameRecovery::AddCreditsToRoot(rootNode);
	GameRecovery::AddBonusGameToRoot(rootNode);
	//save document to file
	GameRecovery::UpdateDoc(docPtr);
}

//add view node to root node
void GameRecovery::AddViewToRoot(pugi::xml_node& rootNode)
{
	//append view number to the root node
	pugi::xml_node viewNode = rootNode.append_child(STR_VIEW);
	//append value attribute to the view node
	viewNode.append_attribute(STR_VALUE) = 1;
}

//add volume node to root node
void GameRecovery::AddVolumeToRoot(pugi::xml_node& rootNode)
{
	//append music volume to the root node
	pugi::xml_node volumeNode = rootNode.append_child(STR_VOLUME);
	//append value attribute to the volume node
	volumeNode.append_attribute(STR_VALUE) = 1;
}

//add reels node to root node
void GameRecovery::AddReelsToRoot(pugi::xml_node& rootNode)
{
	//append the game reels to the root node
	pugi::xml_node reelsNode = rootNode.append_child(STR_REELS);
	//append individual rows to the reelsNode
	for (int i = 0; i < GAME_ROWS; i++)
	{
		//append a reel node to the reels node
		pugi::xml_node reelNode = reelsNode.append_child(STR_ROW);
		//append an index attribute to the current reel node
		reelNode.append_attribute(STR_INDEX) = i;
		//append figures to the current reel node
		for (int j = 0; j < GAME_REELS; j++)
		{
			//create a new figure node
			pugi::xml_node figureNode = reelNode.append_child(STR_FIGURE);
			//append default attributes
			figureNode.append_attribute(STR_INDEX) = j;
			figureNode.append_attribute(STR_VALUE) = eInvalidFigure;
			//delete
		}	//end figure for

	}	// end row for
}



//add number of paylines node to root node
void GameRecovery::AddNumberOfPaylinesToRoot(pugi::xml_node& rootNode)
{
	//append number of paylines to the root node
	pugi::xml_node numberOfPaylinesNode = rootNode.append_child(
			STR_NUMBER_OF_PAYLINES);
	//append value attribute for number of paylines node
	numberOfPaylinesNode.append_attribute(STR_VALUE) = MIN_PAYLINES;
}

//add bet per line node to root node
void GameRecovery::AddBetPerLineToRoot(pugi::xml_node& rootNode)
{
	//append  bet per line to the root node
	pugi::xml_node betPerLineNode = rootNode.append_child(STR_BET_PER_LINE);
	//append value attribute for bet per line node
	betPerLineNode.append_attribute(STR_VALUE) = MIN_BET;
}

//add total bet node to root node
void GameRecovery::AddTotalBetToRoot(pugi::xml_node& rootNode)
{
	//append the total bet to the root node
	pugi::xml_node totalBetNode = rootNode.append_child(STR_TOTAL_BET);
	//append value attribute to the total bet node
	totalBetNode.append_attribute(STR_VALUE) = MIN_BET * MIN_PAYLINES;
}

//add win node to root node
void GameRecovery::AddWinToRoot(pugi::xml_node& rootNode)
{
	//append the win node to the root node
	pugi::xml_node winNode = rootNode.append_child(STR_WIN);
	//append value attribute to the win node
	winNode.append_attribute(STR_VALUE) = 0;
}

//add credits node to rood node
void GameRecovery::AddCreditsToRoot(pugi::xml_node& rootNode)
{
	//append the credits node to the root node
	pugi::xml_node creditsNode = rootNode.append_child(STR_CREDITS);
	//append value attribute to the credits node
	creditsNode.append_attribute(STR_VALUE) = 0;
}

//add bonus game node to root node
void GameRecovery::AddBonusGameToRoot(pugi::xml_node& rootNode)
{
	//append bonus game node to the root node
	pugi::xml_node bonusGameNode = rootNode.append_child(STR_BONUS_GAME);
	//append player choice node to the bonus game node
	pugi::xml_node playerChoiceNode = bonusGameNode.append_child(
			STR_PLAYER_CHOICE);
	//append value attribute to the player choice node
	playerChoiceNode.append_attribute(STR_VALUE) = eInvalidColor;
}

//load the document
void GameRecovery::LoadDoc(pugi::xml_document* docPtr)
{
	//open the document
	if (!(docPtr->load_file(XML_FILE_PATH.c_str())))
	{
		cerr << "Failed to open " << XML_FILE_PATH.c_str() << endl;
	}	//end update if
}

//updates the document
void GameRecovery::UpdateDoc(pugi::xml_document* docPtr)
{
	//save the docPtrument
	if (!(docPtr->save_file(XML_FILE_PATH.c_str())))
	{
		cerr << "Failed to update " << XML_FILE_PATH.c_str() << endl;
	}	//end update if
	//call the xml_document* destructor
	delete docPtr;
	docPtr = NULL;
}

//update functions
//update the view
void GameRecovery::UpdateView(int iView)
{
	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//open the file
	GameRecovery::LoadDoc(docPtr);

	//create a view node
	pugi::xml_node viewNode = docPtr->child(STR_ROOT).child(STR_VIEW);
	//take the attribute of the view node
	pugi::xml_attribute  valueAttribute = viewNode.attribute(STR_VALUE);
	if (!valueAttribute.set_value(iView))
	{
		cerr << "Failed to update the view!" << endl;
	} //end attribute if

	//update the document
	GameRecovery::UpdateDoc(docPtr);
}

//update the volume
void GameRecovery::UpdateVolume(int iVolume)
{
	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load the document
	GameRecovery::LoadDoc(docPtr);

	//create a volume node
	pugi::xml_node volumeNode = docPtr->child(STR_ROOT).child(STR_VOLUME);
	//take the attribute of the volume node
	pugi::xml_attribute  valueAttribute = volumeNode.attribute(STR_VALUE);
	//update the attribute
	if (!valueAttribute.set_value(iVolume))
	{
		cerr << "Failed to update the view!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc(docPtr);
}

void GameRecovery::UpdateReels(const vector<vector<Figures> >& gameReels)
{
	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc
	GameRecovery::LoadDoc(docPtr);

	//create a reels node
	pugi::xml_node reelsNode = docPtr->child(STR_ROOT).child(STR_REELS);
	//a node for a single row
	pugi::xml_node rowNode;
	//traverse the PaylinesNode
	for (rowNode = reelsNode.child(STR_ROW); rowNode;
			rowNode = rowNode.next_sibling(STR_ROW))
	{
		//get the index of the current row
		int iRowIndex = rowNode.attribute(STR_INDEX).as_int();
		//get the current payline using the index
		vector<Figures> currentRow = gameReels[iRowIndex];
		pugi::xml_node figureNode;
		//traverse the elements of a single reel
		for (pugi::xml_node figureNode = rowNode.child(STR_FIGURE); figureNode;
				figureNode = figureNode.next_sibling(STR_FIGURE))
		{
			//get the index of the current figure
			int iFigureIndex = figureNode.attribute(STR_INDEX).as_int();
			//get the current figure from the reel, using the index
			Figures currFigure = currentRow[iFigureIndex];
			//take the value attribute of the figure
			pugi::xml_attribute  valueAttribute = figureNode.attribute(STR_VALUE);
			if (!valueAttribute.set_value(currFigure))
			{
				cerr << "Failed to update the reels!" << endl;
			}// end attribute if
		}// end figure traversal
		if (!currentRow.empty())
		{
			currentRow.erase(currentRow.begin(), currentRow.end());
		}	// end if not empty
	} // end reels traversal

	  //update doc
	GameRecovery::UpdateDoc(docPtr);
}


void GameRecovery::UpdateNumberOfPaylines(int iNumberOfPaylines)
{
	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load the document
	GameRecovery::LoadDoc(docPtr);

	//create a number of paylines node
	pugi::xml_node numberOfPaylinesNode = docPtr->child(STR_ROOT).child(STR_NUMBER_OF_PAYLINES);
	//take the attribute of the number of paylines node
	pugi::xml_attribute  valueAttribute = numberOfPaylinesNode.attribute(STR_VALUE);
	//update the attribute
	if (!valueAttribute.set_value(iNumberOfPaylines))
	{
		cerr << "Failed to update the number of paylines!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc(docPtr);
}

void GameRecovery::UpdateBetPerPayline(int iBetPerLine)
{
	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load the document
	GameRecovery::LoadDoc(docPtr);

	//create a bet per line node
	pugi::xml_node betPerLineNode = docPtr->child(STR_ROOT).child(STR_BET_PER_LINE);
	//take the attribute of the bet per line node
	pugi::xml_attribute  valueAttribute = betPerLineNode.attribute(STR_VALUE);
	//update the attribute
	if (!valueAttribute.set_value(iBetPerLine))
	{
		cerr << "Failed to update the bet per line!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc(docPtr);
}

void GameRecovery::UpdateTotalBet(int iTotalBet)
{
	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load the document
	GameRecovery::LoadDoc(docPtr);

	//create a total bet node
	pugi::xml_node totalBetNode = docPtr->child(STR_ROOT).child(STR_TOTAL_BET);
	//take the attribute of the total bet node
	pugi::xml_attribute  valueAttribute = totalBetNode.attribute(STR_VALUE);
	//update the attribute
	if (!valueAttribute.set_value(iTotalBet))
	{
		cerr << "Failed to update the total bet!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc(docPtr);
}

void GameRecovery::UpdateWin(int iWin)
{	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//open the document
	GameRecovery::LoadDoc(docPtr);
	//create a win node
	pugi::xml_node winNode = docPtr->child(STR_ROOT).child(STR_WIN);
	//take the attribute of the win node
	pugi::xml_attribute  valueAttribute = winNode.attribute(STR_VALUE);
	//update the attribute
	if (!valueAttribute.set_value(iWin))
	{
		cerr << "Failed to update the win!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc(docPtr);
}

void GameRecovery::UpdateCredits(int iCredits)
{	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//open the document
	GameRecovery::LoadDoc(docPtr);

	//create a credits node
	pugi::xml_node creditsNode = docPtr->child(STR_ROOT).child(STR_CREDITS);
	//take the attribute of the credits node
	pugi::xml_attribute  valueAttribute = creditsNode.attribute(STR_VALUE);
	//update the attribute
	if (!valueAttribute.set_value(iCredits))
	{
		cerr << "Failed to update the credits!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc(docPtr);
}



void GameRecovery::UpdateBonusPlayerChoice(const COLOR& playerChoice)
{
	//create xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();

	//open the document
	GameRecovery::LoadDoc(docPtr);

	//create a player choice node
	pugi::xml_node playerChoiceNode =
			docPtr->child(STR_ROOT).child(STR_BONUS_GAME).child(STR_PLAYER_CHOICE);
	//take the attribute of the player node
	pugi::xml_attribute  valueAttribute = playerChoiceNode.attribute(STR_VALUE);
	//update the attribute
	if (!valueAttribute.set_value(playerChoice))
	{
		cerr << "Failed to update the player choice!" << endl;
	}	// end attribute if

	//update the document
	GameRecovery::UpdateDoc(docPtr);
}

//update the game mode;
void GameRecovery::UpdateGameModel(const GameModel* gameModelPtr)
{
	GameRecovery::UpdateReels(gameModelPtr->GetMatrixGameReels());
	GameRecovery::UpdateNumberOfPaylines(gameModelPtr->GetINumberOfLines());
	GameRecovery::UpdateBetPerPayline(gameModelPtr->GetIBetPerLine());
	GameRecovery::UpdateTotalBet(gameModelPtr->GetITotalBet());
	GameRecovery::UpdateWin(gameModelPtr->GetIWin());
	GameRecovery::UpdateCredits(gameModelPtr->GetICredits());
}

//load functions
int GameRecovery::LoadView()
{
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc
	GameRecovery::LoadDoc(docPtr);
	pugi::xml_attribute valueAttribute = docPtr->child(STR_ROOT).child(STR_VIEW).attribute(STR_VALUE);
	int res = valueAttribute.as_int();
	delete docPtr;
	docPtr = NULL;
	return res;
}

int GameRecovery::LoadVolume()
{
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc
	GameRecovery::LoadDoc(docPtr);
	pugi::xml_attribute  valueAttribute = docPtr->child(STR_ROOT).child(STR_VOLUME).attribute(STR_VALUE);
	int res = valueAttribute.as_int();
	//delete the docPtr, calling its destructor and destroy set the reference to NULL
	delete docPtr;
	docPtr = NULL;
	return res;
}

//parameter is the game model in order to access its ModifyReelElement method
void GameRecovery::LoadReels(GameModel* gameModelPtr)
{
	//create an xml document in memory
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc
	GameRecovery::LoadDoc(docPtr);
	//root node
	pugi::xml_node rootNode = docPtr->child(STR_ROOT);
	pugi::xml_node reelsNode = rootNode.child(STR_REELS);
	int iRow = 0;
	int iCol = 0;
	//traverse the rows
	for(pugi::xml_node rowNode = reelsNode.child(STR_ROW); rowNode;
			rowNode = rowNode.next_sibling(STR_ROW))
	{
		//row index
		iRow = rowNode.attribute(STR_INDEX).as_int();
		//access the figures of the the current row
		for(pugi::xml_node figureNode = rowNode.child(STR_FIGURE);
				figureNode; figureNode = figureNode.next_sibling(STR_FIGURE))
		{
			//column index
			iCol = figureNode.attribute(STR_INDEX).as_int();
			//get the current element from the xml file
			//static cast from int to COLOR
			Figures currFigure =
					static_cast<Figures>(figureNode.attribute(STR_VALUE).as_int());
			//update the current element of the game reels vector
			gameModelPtr->SetReelElement(currFigure,iRow, iCol);
		}
	}

	//delete the docPtr, calling its destructor and destroy set the reference to NULL
	delete docPtr;
	docPtr = NULL;
}

int GameRecovery::LoadNumberOfPaylines()
{
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc
	GameRecovery::LoadDoc(docPtr);
	pugi::xml_attribute  valueAttribute = docPtr->child(STR_ROOT).child(STR_NUMBER_OF_PAYLINES).attribute(STR_VALUE);
	int res = valueAttribute.as_int();
	//delete the docPtr, calling its destructor and destroy set the reference to NULL
	delete docPtr;
	docPtr = NULL;
	return res;
}

int GameRecovery::LoadBetPerPayline()
{
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc
	GameRecovery::LoadDoc(docPtr);
	pugi::xml_attribute  valueAttribute = docPtr->child(STR_ROOT).child(STR_BET_PER_LINE).attribute(STR_VALUE);
	int res = valueAttribute.as_int();
	//delete the docPtr, calling its destructor and destroy set the reference to NULL
	delete docPtr;
	docPtr = NULL;
	return res;
}

int GameRecovery::LoadTotalBet()
{
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc
	GameRecovery::LoadDoc(docPtr);
	pugi::xml_attribute  valueAttribute = docPtr->child(STR_ROOT).child(STR_TOTAL_BET).attribute(STR_VALUE);
	int res = valueAttribute.as_int();
	//delete the docPtr, calling its destructor and destroy set the reference to NULL
	delete docPtr;
	docPtr = NULL;
	return res;
}

int GameRecovery::LoadWin()
{
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc
	GameRecovery::LoadDoc(docPtr);
	pugi::xml_attribute  valueAttribute = docPtr->child(STR_ROOT).child(STR_WIN).attribute(STR_VALUE);
	int res = valueAttribute.as_int();
	//delete the docPtr, calling its destructor and destroy set the reference to NULL
	delete docPtr;
	docPtr = NULL;
	return res;
}

int GameRecovery::LoadCredits()
{
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc1
	GameRecovery::LoadDoc(docPtr);
	pugi::xml_attribute  valueAttribute = docPtr->child(STR_ROOT).child(STR_CREDITS).attribute(STR_VALUE);
	int res = valueAttribute.as_int();
	//delete the docPtr, calling its destructor and destroy set the reference to NULL
	delete docPtr;
	docPtr = NULL;
	return res;
}

void GameRecovery::LoadGameModel(GameModel* gameModelPtr)
{
	int iNumberOfLines = GameRecovery::LoadNumberOfPaylines();
	int iBetPerLine = GameRecovery::LoadBetPerPayline();
	int iWin = GameRecovery::LoadWin();
	int iCredits = GameRecovery::LoadCredits();

	//update the game model
	GameRecovery::LoadReels(gameModelPtr);
	gameModelPtr->SetINumberOfLines(iNumberOfLines);
	gameModelPtr->SetIBetPerLine(iBetPerLine);
	gameModelPtr->SetITotalBet();
	gameModelPtr->SetIWin(iWin);
	gameModelPtr->SetICredits(iCredits);
}

COLOR GameRecovery::LoadBonusPlayerChoice()
{
	pugi::xml_document* docPtr = new pugi::xml_document();
	//load doc
	GameRecovery::LoadDoc(docPtr);
	pugi::xml_attribute valueAttribute =
			docPtr->child(STR_PLAYER_CHOICE).child(STR_CREDITS).attribute(STR_VALUE);
	//static cast from int to COLOR
	COLOR res = static_cast<COLOR>(valueAttribute.as_int());
	//delete the docPtr, calling its destructor and destroy set the reference to NULL
	delete docPtr;
	docPtr = NULL;
	return res;
}
