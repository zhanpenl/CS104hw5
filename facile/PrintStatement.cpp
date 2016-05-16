// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	/* 
	might be variable name not declared. In this case, just print 0, not making a pair
	*/
	
	outf << state->getValue(m_variableName) << std::endl;
	
	state->setLine(state->getLine() + 1);
	// std::cout << "After printing, line: " << state->getLine() << std::endl;
}


