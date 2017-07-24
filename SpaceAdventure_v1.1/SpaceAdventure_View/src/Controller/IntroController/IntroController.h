/*
 * IntroController.h
 *
 *  Created on: Jul 21, 2017
 *      Author: SimoAngelov
 */

#ifndef SRC_CONTROLLER_INTROCONTROLLER_INTROCONTROLLER_H_
#define SRC_CONTROLLER_INTROCONTROLLER_INTROCONTROLLER_H_

#include "../../Globals/Globals.h"
#include "../GameRecovery/GameRecovery.h"
class IntroController
{
private:
	static int m_iCredits;
public:
	IntroController();
	//create a blank xml save
	static void PlayNewGame();
	//increase the credits by 10 000 each time the method is called
	static void IncreaseCredits();
	//decrease the credits by 10 000 each time the method is called
	static void DecreaseCredits();
	//save the credits to the blank xml file
	static void SaveCredits();
	//print the current credits
	static void PrintInfo();
	virtual ~IntroController();
};

#endif /* SRC_CONTROLLER_INTROCONTROLLER_INTROCONTROLLER_H_ */
