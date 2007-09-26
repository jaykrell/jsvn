#include <QtGui>

#include "finddialog.h"

FindDialog::FindDialog(QWidget* parent)
:
	QDialog(parent),
	label(tr("Find &what:")),
	caseCheckBox(tr("Match &case")),
	backwardCheckBox(tr("Search &backward")),
	findButton(tr("&Find")),
	closeButton(tr("Close"))
{
	label.setBuddy(&lineEdit);
	findButton.setDefault(true);
	findButton.setEnabled(false);

	connect(&lineEdit, SIGNAL(textChanged(const QString&)),
		this, SLOT(enableFindButton(const QString&)));

	connect(&findButton, SIGNAL(clicked()),
		this, SLOT(findClicked()));

	connect(&closeButton, SIGNAL(clicked()),
		this, SLOT(close()));

	topLeftLayout.addWidget(&label);
	topLeftLayout.addWidget(&lineEdit);

	leftLayout.addLayout(&topLeftLayout);
	leftLayout.addWidget(&caseCheckBox);
	leftLayout.addWidget(&backwardCheckBox);

	rightLayout.addWidget(&findButton);
	rightLayout.addWidget(&closeButton);
	rightLayout.addStretch();

	mainLayout.addLayout(&leftLayout);
	mainLayout.addLayout(&rightLayout);
	setLayout(&mainLayout);

	setWindowTitle(tr("Find"));
	//setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked()
{
	QString text = lineEdit.text();
	Qt::CaseSensitivity cs = caseCheckBox.isChecked() ? Qt::CaseSensitive :  Qt::CaseInsensitive;
	if (backwardCheckBox.isChecked())
	{
		emit findPrevious(text, cs);
	}
	else
	{
		emit findNext(text, cs);
	}
}

void FindDialog::enableFindButton(const QString& text)
{
	findButton.setEnabled(!text.isEmpty());
}
