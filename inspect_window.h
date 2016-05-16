#ifndef INSPECT_WINDOW_H
#define INSPECT_WINDOW_H 

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QRadioButton>
#include <QStringList>
#include <QString>
#include <string>

#include "msort/msort.h"

class InspectWindow : public QWidget {
Q_OBJECT

public:
	InspectWindow();
	~InspectWindow();

	// functions called by the debug window
	void importVariables(std::vector< std::pair<std::string, int> > *);
	void sortVariables();
	void updateVariables();

private slots:
	void hideInspect();
	void sendUpdateRequire();

signals:
	void stateUpdateRequired();

private:
	// overall layout
	QVBoxLayout* inspectLayout;

	// variable-value view
	QTreeWidget * varValView;

	// button
	QHBoxLayout * buttonLayout;
	QPushButton * hideButton;
	QPushButton * updateButton;

	// radio button
	QVBoxLayout * radioButtonsLayout;
	QRadioButton * nameAscButton;
	QRadioButton * nameDescButton;
	QRadioButton * valueAscButton;
	QRadioButton * valueDescButton;


	// member vector that stores var-val pairs
	std::vector< std::pair<std::string, int> > * varValList;
};

#endif