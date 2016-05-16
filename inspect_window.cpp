#include "inspect_window.h"

InspectWindow::InspectWindow() {
	setWindowTitle("inspect");
	// overall layout
	inspectLayout = new QVBoxLayout();

	// variable-value view
	varValView = new QTreeWidget();
	inspectLayout->addWidget(varValView);
	varValView->setColumnCount(2);
	// QStringList headerLabels;
	varValView->setHeaderLabels(QStringList() << "variable" << "value");

	// test
	// varValView->addTopLevelItem(new QTreeWidgetItem(QStringList() << "aa" << QString().setNum(130)));


	// button
	buttonLayout = new QHBoxLayout();
	inspectLayout->addLayout(buttonLayout);
	hideButton = new QPushButton("hide");
	buttonLayout->addWidget(hideButton);
	updateButton = new QPushButton("update");
	buttonLayout->addWidget(updateButton);

	connect(updateButton, SIGNAL(clicked()), this, SLOT(sendUpdateRequire()));
	connect(hideButton, SIGNAL(clicked()), this, SLOT(hideInspect()));

	// radio button
	radioButtonsLayout = new QVBoxLayout();
	inspectLayout->addLayout(radioButtonsLayout);
	nameAscButton = new QRadioButton("sort by name(ascending)");
	radioButtonsLayout->addWidget(nameAscButton);
	nameDescButton = new QRadioButton("sort by name(descending)");
	radioButtonsLayout->addWidget(nameDescButton);
	valueAscButton = new QRadioButton("sort by value(ascending)");
	radioButtonsLayout->addWidget(valueAscButton);
	valueDescButton = new QRadioButton("sort by value(descending)");
	radioButtonsLayout->addWidget(valueDescButton);

	setLayout(inspectLayout);

	// set the pointer of the vector to NULL
	varValList = NULL;
}

InspectWindow::~InspectWindow() {
	delete varValList;
}

void InspectWindow::importVariables(std::vector< std::pair<std::string, int> > * varlist) {
	if (varValList != NULL) delete varValList;
	varValList = varlist;
}

void InspectWindow::sortVariables() {
	PairFirstCompAsc comp1;
	PairFirstCompDesc comp2;
	PairSecondCompAsc comp3;
	PairSecondCompDesc comp4;

	if ( nameDescButton->isChecked() )
		mergeSort(*varValList, comp2);
	else if ( valueAscButton->isChecked() )
		mergeSort(*varValList, comp3);
	else if ( valueDescButton->isChecked() )
		mergeSort(*varValList, comp4);
	else
		mergeSort(*varValList, comp1);
}

void InspectWindow::updateVariables() {
	// delete the items
	varValView->clear();
	// sort
	sortVariables();
	std::vector< std::pair<std::string, int> >::iterator it;
	for (it = varValList->begin(); it != varValList->end(); ++it)
	{
		std::string var = it->first;
		int val = it->second;
		varValView->addTopLevelItem(new QTreeWidgetItem(QStringList() << var.c_str() << QString().setNum(val)));
	}
}

void InspectWindow::hideInspect() {
	this->hide();
}

void InspectWindow::sendUpdateRequire() {
	emit stateUpdateRequired();
}