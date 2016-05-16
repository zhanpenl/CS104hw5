#ifndef MATH_STATEMENT_INCLUDED
#define MATH_STATEMENT_INCLUDED 

#include "Statement.h"

class MathStatement : public Statement
{
protected: // these members should be accessed by Add/Sub/Mult/Div subclasses
	std::string m_variableName;
	int m_value;
	std::string m_variableNameRHS;


public:
	MathStatement(std::string variableName, int val)
	: m_variableName( variableName ), m_value( val ), m_variableNameRHS( "" )
	{}

	MathStatement(std::string variableName, std::string variableNameRHS)
	: m_variableName( variableName ), m_value( 0 ), m_variableNameRHS( variableNameRHS )
	{}
	// mind the MULT/DIV cases, where m_value should be set to 1 after constructed

	// function execute not declared in MathStatement: OK, because implicitly inherit
	// from Statement
	// virtual void execute(ProgramState * state, std::ostream &outf) = 0; 
	
};

#endif