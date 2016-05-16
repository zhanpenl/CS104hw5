#include "AddStatement.h"

AddStatement::AddStatement(std::string variableName, int val)
: MathStatement(variableName, val)
{}

AddStatement::AddStatement(std::string variableName, std::string variableNameRHS)
: MathStatement(variableName, variableNameRHS)
{}

void AddStatement::execute(ProgramState * state, std::ostream &outf) {
	int res = state->getValue(m_variableName);
	// risky part
	res += m_value;
	if (m_variableNameRHS != ""){
		res += state->getValue(m_variableNameRHS);
	}
	state->setValue(m_variableName, res);

	state->setLine(state->getLine() + 1);
}
