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
	return res;
}
