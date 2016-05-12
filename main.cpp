#include "load_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	LoadWindow loadWindow;

	loadWindow.show();

	return app.exec();
}