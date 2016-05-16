#include "GosubStatement.h"

GosubStatement::GosubStatement(int line) : m_gotoLine(line) {}

void GosubStatement::execute(ProgramState* state, std::ostream& outf) {
	if ( m_gotoLine < 1 || m_gotoLine > state->getNumLines() ) {
		outf << "Illegal jump instruction\n";
		state->setLine(-1);
		return; 
	}

	state->pushLine(state->getLine() + 1); // the next line to be executed
	state->setLine(m_gotoLine);
}
