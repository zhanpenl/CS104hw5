#ifndef LOAD_WINDOW_H
#define LOAD_WINDOW_H 

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QApplication>

#include <fstream>
#include <iostream>
#include <string>

#include "debug_window.h"


class LoadWindow : public QWidget {
Q_OBJECT

public:
	LoadWindow();
	~LoadWindow();

private slots:
	void loadProgram();
	void errorConfirm();
	void quit();

private:
	// Layout
	QVBoxLayout* loadLayout;

	// load field
	QLabel* filenameLabel;
	QLineEdit* filenameInput;
	QPushButton* loadButton;
	QPushButton* quitButton;

	// error window
	QWidget* errWin;
	QLabel* errorMsgLabel;
	QPushButton* errorConfirmButton;

	// debug window
	DebugWindow* debugWin;
};


#endif