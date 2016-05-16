#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED 

#include "MathStatement.h"

class DivStatement : public MathStatement
{
public:
	DivStatement(std::string variableName, int val);
	DivStatement(std::string variableName, std::string variableNameRHS);
	virtual void execute(ProgramState * state, std::ostream &outf);
	
};

#endif