// ProgramState.h
//
// CS 104 / Spring 2016
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include "stackint.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>

class ProgramState
{
public:
	ProgramState(int numLines);
	~ProgramState();

	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.

	int getNumLines();
	int getLine();
	void setLine(int line);

	bool containsVariable(std::string);
	int getValue(std::string);
	void setValue(std::string, int);

	void printAll(std::ostream& outf);

	void pushLine(int);
	int popLine();
	// convert the var-val map into vector of pairs of variable and value
	// Alternative: can make DebugWindow a friend class so that it can acess the map
	std::vector< std::pair<std::string, int> > * map2vector();

private:
	int m_numLines;
	int m_currentLine;
	std::map<std::string, int> * varMap;
	StackInt * programStack;
};

#endif
