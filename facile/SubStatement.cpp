#include "SubStatement.h"

SubStatement::SubStatement(std::string variableName, int val)
: MathStatement(variableName, val)
{}

SubStatement::SubStatement(std::string variableName, std::string variableNameRHS)
: MathStatement(variableName, variableNameRHS)
{}

void SubStatement::execute(ProgramState * state, std::ostream &outf) {
	int res = state->getValue(m_variableName);
	res -= m_value;
	if (m_variableNameRHS != ""){
		res -= state->getValue(m_variableNameRHS);
	}
	state->setValue(m_variableName, res);

	state->setLine(state->getLine() + 1);
}