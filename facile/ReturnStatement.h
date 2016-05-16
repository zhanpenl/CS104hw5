#ifndef RETURN_STATEMENT_H
#define RETURN_STATEMENT_H

#include "Statement.h"

class ReturnStatement : public Statement
{
public:
	ReturnStatement();
	void execute(ProgramState*, std::ostream&);
};

#endif