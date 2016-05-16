#ifndef DEBUG_WINDOW_H
#define DEBUG_WINDOW_H

#include <Qt>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QListWidget>
#include <QApplication>

#include <QBrush>
#include <QColor>
#include <QString>
#include <string>
#include <vector>

#include "inspect_window.h"
#include "facile/Statement.h"
#include "facile/ProgramState.h"
#include "facile/facile.h"

class DebugWindow : public QWidget {
Q_OBJECT
public:
	DebugWindow(std::string);
	~DebugWindow();

	void addItem2CodeList(const std::string& line);

private slots:
void breakHighlight();
void step();

void errorConfirm();

void showInspect();
void setInspectValue(); 
void quit();


private:
	// overal layout
	QVBoxLayout* debugLayout;

	// code view
	QListWidget* codeList;
	QScrollArea* scrollArea;

	// debug button section
	QHBoxLayout* debugButtonLayout;
	QPushButton* breakButton;
	QPushButton* continueButton;
	QPushButton* stepButton;
	QPushButton* nextButton;

	// other button section
	QHBoxLayout* otherButtonLayout;
	QPushButton* inspectButton;
	QPushButton* quitButton;
	
	// error window
	QWidget * errWin;
	QLabel* errorMsgLabel;
	QPushButton* errorConfirmButton;

	// inspect window
	InspectWindow * inspectWin;

	// Program associated with the file
	std::vector<Statement* > program;
	std::vector<int> breakpoints;
	ProgramState * state;
};

#endif