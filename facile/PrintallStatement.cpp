#include "PrintallStatement.h"

PrintallStatement::PrintallStatement() {}

void PrintallStatement::execute(ProgramState * state, std::ostream &outf) {
	state->printAll(outf);
	state->setLine(state->getLine() + 1);
}