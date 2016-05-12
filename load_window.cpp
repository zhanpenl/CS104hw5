#include "load_window.h"

LoadWindow::LoadWindow() {
	loadLayout = new QVBoxLayout();

	filenameLabel = new QLabel("pleae specify a file name:");
	loadLayout->addWidget(filenameLabel);

	filenameInput = new QLineEdit();
	loadLayout->addWidget(filenameInput);

	loadButton = new QPushButton("load");
	loadLayout->addWidget(loadButton);
	connect(loadButton, SIGNAL(clicked()), this, SLOT(loadProgram()));

	quitButton = new QPushButton("quit");
	loadLayout->addWidget(quitButton);
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));

	setLayout(loadLayout);

	// error window
	errWin = new QWidget();
	QVBoxLayout* errorLayout = new QVBoxLayout();

	errorMsgLabel = new QLabel();
	errorLayout->addWidget(errorMsgLabel);

	errorConfirmButton = new QPushButton("confirm");
	errorLayout->addWidget(errorConfirmButton);
	connect(errorConfirmButton, SIGNAL(clicked()), this, SLOT(errorConfirm())); // why this

	errWin->setLayout(errorLayout);

	// debug window
}

LoadWindow::~LoadWindow() {
	delete filenameLabel;
	delete filenameInput;
	delete loadButton;
	delete quitButton;
	delete loadLayout;

	delete errorMsgLabel;
	delete errorConfirmButton;
	// delete errorLayout; why?
	delete errWin;
}

void LoadWindow::loadProgram() {
	std::string filename = filenameInput->text().toStdString();
	std::ifstream ifs(filename.c_str());

	if ( !ifs.is_open() ) {
		errorMsgLabel->setText(QString::fromStdString("Error occurs when openning" + filename));
		errWin->show();
		return;
	}

}

void LoadWindow::errorConfirm() {
	errWin->hide();
	filenameInput->setText("");
}

void LoadWindow::quit() {
	QApplication::exit();
}