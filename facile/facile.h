#ifndef FACILE_H
#define FACILE_H


#include "ProgramState.h"
#include "Statement.h"
#include "LetStatement.h"
#include "PrintStatement.h"
#include "PrintallStatement.h"
#include "AddStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "GotoStatement.h"
#include "IfStatement.h"
#include "GosubStatement.h"
#include "ReturnStatement.h"
#include "EndStatement.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>

#include <iostream> // added 


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);

void parseMathOperation(stringstream &ss, string &var, 
	int &val, string &var_rhs, bool &isRhsDigit);


#endif