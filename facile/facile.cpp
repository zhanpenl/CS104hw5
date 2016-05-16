#include "facile.h"

using namespace std;

void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL); // 0th line, null statement
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var;
	string var_rhs;
	int val, gotoLine;
	bool isRhsDigit;

	ss << line;
	ss >> type;
	
	if (type == "LET")
	{
		ss >> var;
		ss >> val;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal Facile program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}

	if (type == "PRINT") {
		ss >> var;
		statement = new PrintStatement(var);
	}

	if (type == "PRINTALL") {
		statement = new PrintallStatement();
	}

	if (type == "ADD") {
		parseMathOperation(ss, var, val, var_rhs, isRhsDigit);
		if (isRhsDigit)
			statement = new AddStatement(var, val);
		else
			statement = new AddStatement(var, var_rhs);
	}

	if (type == "SUB") {
		parseMathOperation(ss, var, val, var_rhs, isRhsDigit);
		if (isRhsDigit)
			statement = new SubStatement(var, val);
		else
			statement = new SubStatement(var, var_rhs);
	}


	if (type == "MULT") {
		parseMathOperation(ss, var, val, var_rhs, isRhsDigit);
		if (isRhsDigit)
			statement = new MultStatement(var, val);
		else
			statement = new MultStatement(var, var_rhs);
	}

	if (type == "DIV") {
		parseMathOperation(ss, var, val, var_rhs, isRhsDigit);
		if (isRhsDigit)
			statement = new DivStatement(var, val);
		else
			statement = new DivStatement(var, var_rhs);
	}

	if (type == "GOTO") {
		ss >> gotoLine;
		// cout << "Parse GOTO: gotoLine = " << gotoLine << endl;
		statement = new GotoStatement(gotoLine);
	}

	if (type == "IF") {
		string oprSymbol, then;
		ss >> var;
		ss >> oprSymbol;
		ss >> val;
		ss >> then;	// don't check the string "THEN"
		ss >> gotoLine;

		statement = new IfStatement(var, oprSymbol, val, gotoLine);
	}

	if (type == "GOSUB") {
		ss >> gotoLine;
		statement = new GosubStatement(gotoLine);
	}

	if (type == "RETURN") {
		statement = new ReturnStatement();
	}


	if (type == "END" || type[0] == '.') {
		statement = new EndStatement();
	}

	// static int count = 1;
	// cout << count << ": " << type << endl;
	// count++;

	// if none of the above if statement is entered, null statement would return
	// causing seg-fault when deleting
	return statement;
}


void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;
	parseProgram( inf, program );

	// Continuing part
	ProgramState * state = new ProgramState(program.size() - 1); // there is a null statement at head

	cout << "Lines of program: " << state->getNumLines() << endl << endl;

	while (state->getLine() > 0 && state->getLine() <= state->getNumLines()) {
		program[state->getLine()]->execute(state, outf);
		cout << "After execution, Line number: " << state->getLine() << endl;
	}

	for (uint i = 1; i < program.size(); i++) {
		// cout << "the " << i << "th time:" << endl;
		delete program[i];
	}
	delete state;
}

void parseMathOperation(stringstream &ss,
	string &var, int &val, string &var_rhs, bool &isRhsDigit) {

	ss >> var;
	// check digit or variable, alternative way is to read in string and use strtoi
	while (ss.peek() == ' ' || ss.peek() == '\t') ss.get();
	if (isdigit(ss.peek()) || ss.peek() == '-') {
		ss >> val;
		isRhsDigit = true;
	}
	else {
		ss >> var_rhs;
		isRhsDigit = false;
	}
}