#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED 

#include "MathStatement.h"

class AddStatement : public MathStatement
{
public:
	AddStatement(std::string variableName, int val);
	AddStatement(std::string variableName, std::string variableNameRHS);
	virtual void execute(ProgramState * state, std::ostream &outf);
	
};

#endif