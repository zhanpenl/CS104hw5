#include "ReturnStatement.h"

ReturnStatement::ReturnStatement() {}

void ReturnStatement::execute(ProgramState* state, std::ostream& outf) {
	int gotoLine = state->popLine();
	if ( gotoLine == -1 ) outf << "No place to return\n";
	state->setLine(gotoLine);
}