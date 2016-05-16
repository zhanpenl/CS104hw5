#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED 

#include "MathStatement.h"

class SubStatement : public MathStatement
{
public:
	SubStatement(std::string variableName, int val);
	SubStatement(std::string variableName, std::string variableNameRHS);
	virtual void execute(ProgramState * state, std::ostream &outf);
};


#endif