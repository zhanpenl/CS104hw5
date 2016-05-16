#ifndef GOSUB_STATEMENT_H
#define GOSUB_STATEMENT_H 

#include "Statement.h"

class GosubStatement : public Statement {
public:
	GosubStatement(int);
	void execute(ProgramState*, std::ostream&);

private:
	int m_gotoLine;
};

#endif