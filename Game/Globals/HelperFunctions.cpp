/*
 * HelperFunctions.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: SimoAngelov
 */

#include "Globals.h"
#include <iostream>
#include <sstream>
using std::stringstream;
using std::ostringstream;
using std::string;

//converts an integer into a constant character array
string itos(int nArg)
{
	//use the string output stream
	ostringstream stream;
	//save the integer argument into the stream
	stream << nArg;
	//return the const char* representation of the stream string method
	string res = stream.str();
	//test cout
	//cout << "string res = " << res << endl;
	//cout << "const char* res = " << res.c_str() << endl;
	//const char* resCon = res.c_str();
	//cout << "resCon = " << resCon << endl;
	return res;
}
