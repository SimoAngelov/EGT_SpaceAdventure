/*
 * TestRecovery.h
 *
 *  Created on: Jul 16, 2017
 *      Author: SimoAngelov
 */

#ifndef TEST_TESTRECOVERY_H_
#define TEST_TESTRECOVERY_H_
#include "../Controller/GameRecovery/GameRecovery.h"

class TestRecovery
{
private:
	static GameRecovery m_gameSave;
public:
	TestRecovery();
	static void TestBlankSave();
	static void TestViewUpdate();
	static void TestVolumeUpdate();

	static void Test();
	virtual ~TestRecovery();
};

#endif /* TEST_TESTRECOVERY_H_ */
