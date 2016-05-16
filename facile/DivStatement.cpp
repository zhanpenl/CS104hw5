#include "DivStatement.h"

DivStatement::DivStatement(std::string variableName, int val)
: MathStatement(variableName, val)
{}

DivStatement::DivStatement(std::string variableName, std::string variableNameRHS)
: MathStatement(variableName, variableNameRHS)
{ 
	m_value = 1; // to correct the add/sub convention, which sets m_value to 0 by default
}

void DivStatement::execute(ProgramState * state, std::ostream &outf) {
	int res = state->getValue(m_variableName);
	if (m_value == 0) {
		outf << "Divide by zero exception" << std::endl;
		state->setLine(-1);
		return;
	}
	res /= m_value;
	if (m_variableNameRHS != ""){
		// the right hand side variable might not be stored in the map
		// if that is the case, getValue() returns 0 by default, 
		// which is not a desired behavior
		if (state->containsVariable(m_variableNameRHS)){
			if (state->getValue(m_variableNameRHS) == 0) {
			outf << "Divide by zero exception\n"; // 
			state->setLine(-1);
			return;
			}
			else {
			res /= state->getValue(m_variableNameRHS);
			}	
		}
	}
	state->setValue(m_variableName, res);

	state->setLine(state->getLine() + 1);
}