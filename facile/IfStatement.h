#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include "Statement.h"
#include <string>

class IfStatement : public Statement {
public:
	IfStatement(const std::string&, const std::string&, int, int);
	void execute(ProgramState *, std::ostream&);

private:
	std::string m_variableName, m_operatorSymbol;
	int m_value, m_gotoLine;
};

#endif