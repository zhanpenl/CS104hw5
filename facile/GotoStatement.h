#ifndef GOTO_STATEMENT
#define GOTO_STATEMENT 

#include "Statement.h"

class GotoStatement : public Statement
{
public:
	GotoStatement(int line);
	void execute(ProgramState * state, std::ostream &outf);

private:
	int m_gotoLine;
};

#endif