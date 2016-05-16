#ifndef  MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED 

#include "MathStatement.h"

class MultStatement : public MathStatement
{
public:
	MultStatement(std::string variableName, int val);
	MultStatement(std::string variableName, std::string variableNameRHS);
	virtual void execute(ProgramState * state, std::ostream &outf);
	
};

#endif