#include "IfStatement.h"

IfStatement::IfStatement(const std::string& variableName, const std::string& oprSymbol,  int val, int line) : 
m_variableName(variableName), m_operatorSymbol(oprSymbol), m_value(val), m_gotoLine(line)
{}


void IfStatement::execute(ProgramState * state, std::ostream& outf) {
	bool isConditionSatisfied = false, isUnrecognizedSymbol = false;
	int lhs = state->getValue(m_variableName);

	isConditionSatisfied = (m_operatorSymbol == "<" && lhs < m_value) ||
					 	   (m_operatorSymbol == "<=" && lhs <= m_value) ||
					 	   (m_operatorSymbol == ">" && lhs > m_value) ||
					 	   (m_operatorSymbol == ">=" && lhs >= m_value) ||
					 	   (m_operatorSymbol == "=" && lhs == m_value) ||
					 	   (m_operatorSymbol == "<>" && lhs != m_value);

    isUnrecognizedSymbol = m_operatorSymbol != "<" && m_operatorSymbol != "<=" &&
    					   m_operatorSymbol != ">" && m_operatorSymbol != ">=" &&
    					   m_operatorSymbol != "=" && m_operatorSymbol != "<>";

    if ( isUnrecognizedSymbol ) {
    	state->setLine(-1);
    	outf << "Unexpected operator\n";
    }
    else if ( isConditionSatisfied ) {
    	if ( m_gotoLine < 1 || m_gotoLine > state->getNumLines() ) {
			outf << "Illegal jump instruction\n";
			state->setLine(-1);
			return; 
		}
    	else state->setLine(m_gotoLine);
    }
    else {
    	state->setLine(state->getLine() + 1);
    }
}