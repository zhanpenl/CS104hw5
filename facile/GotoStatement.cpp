#include "GotoStatement.h"

GotoStatement::GotoStatement(int line) : m_gotoLine(line) {}

void GotoStatement::execute(ProgramState * state, std::ostream &outf) {
	if ( m_gotoLine < 1 || m_gotoLine > state->getNumLines() ) {
		outf << "Illegal jump instruction\n";
		state->setLine(-1);
		return; 
	}
	
	state->setLine(m_gotoLine);
}