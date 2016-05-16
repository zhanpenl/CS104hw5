#include "debug_window.h"

DebugWindow::DebugWindow(std::string filename) {
	setWindowTitle("debug");
	debugLayout = new QVBoxLayout();

	// code view
	codeList = new QListWidget();
	scrollArea = new QScrollArea();
	scrollArea->setWidget(codeList);
	debugLayout->addWidget(codeList);

	// debug button section
	debugButtonLayout = new QHBoxLayout();
	debugLayout->addLayout(debugButtonLayout);

	breakButton = new QPushButton("break");
	debugButtonLayout->addWidget(breakButton);
	continueButton = new QPushButton("continue");
	debugButtonLayout->addWidget(continueButton);
	stepButton = new QPushButton("step");
	debugButtonLayout->addWidget(stepButton);
	nextButton = new QPushButton("next");
	debugButtonLayout->addWidget(nextButton);

	connect(breakButton, SIGNAL(clicked()), this, SLOT(breakHighlight()));
	connect(stepButton, SIGNAL(clicked()), this, SLOT(step()));

	// other button section
	otherButtonLayout = new QHBoxLayout();
	debugLayout->addLayout(otherButtonLayout);

	inspectButton = new QPushButton("inspect");
	otherButtonLayout->addWidget(inspectButton);
	quitButton = new QPushButton("quit");
	otherButtonLayout->addWidget(quitButton);

	connect(inspectButton, SIGNAL(clicked()), this, SLOT(showInspect()));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
	
	setLayout(debugLayout);

	// error window 
	// [code duplicate, should implement windows that have error deriving from a class]
	errWin = new QWidget();
	errWin->setWindowTitle("debug error");
	QVBoxLayout* errorLayout = new QVBoxLayout();

	errorMsgLabel = new QLabel();
	errorLayout->addWidget(errorMsgLabel);

	errorConfirmButton = new QPushButton("confirm");
	errorLayout->addWidget(errorConfirmButton);
	connect(errorConfirmButton, SIGNAL(clicked()), this, SLOT(errorConfirm()));

	// inspect window
	inspectWin = new InspectWindow();
	connect(inspectWin, SIGNAL(stateUpdateRequired()), this, SLOT(setInspectValue()));

	// load up the program
	std::ifstream ifs(filename.c_str());
	parseProgram(ifs, program);
	ifs.close();
	state = new ProgramState(program.size() - 1);
}

DebugWindow::~DebugWindow() { 
	for (uint i = 0; i < program.size(); i++) {
		delete program[i];
	}
	delete state;
}

void DebugWindow::addItem2CodeList(const std::string& line) {
	codeList->addItem(QString::fromStdString(line));
}

void DebugWindow::breakHighlight() {
	int currLine = codeList->currentRow();
	QBrush qbrush(QColor(Qt::darkCyan));
	codeList->item(currLine)->setBackground(qbrush);
}

void DebugWindow::step() {
	// if terminated, start again
	if ( state->getLine() == -1 ) {
		delete state;
		state = new ProgramState(program.size() - 1);
	}
	program[state->getLine()]->execute(state, std::cout); // take a step of the program
	codeList->setCurrentRow(state->getLine() - 1);	// show the progress by selection of row
}

void DebugWindow::showInspect() {
	inspectWin->show();
}

// 1. pass, the pointer to the new created vector, to the inspect window
// 2. update the variable list
void DebugWindow::setInspectValue() {
	cout << "debug window: signal requireUpdateState(), received" << endl;
	inspectWin->importVariables(state->map2vector());
	inspectWin->updateVariables();
}

void DebugWindow::errorConfirm() {
	// to do what is needed
	errWin->hide();
}

void DebugWindow::quit() {
	QApplication::exit();
}
