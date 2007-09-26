#pragma once

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class FindDialog : public QDialog
{
	Q_OBJECT

public:

	FindDialog(QWidget* = 0);

signals:

	void findNext(const QString&, Qt::CaseSensitivity);
	void findPrevious(const QString&, Qt::CaseSensitivity);

private slots:

	void findClicked();
	void enableFindButton(const QString&);

private:

	QLabel label;
	QLineEdit lineEdit;
	QCheckBox caseCheckBox;
	QCheckBox backwardCheckBox;
	QPushButton findButton;
	QPushButton closeButton;
	QHBoxLayout topLeftLayout;
	QVBoxLayout leftLayout;
	QVBoxLayout rightLayout;
	QHBoxLayout mainLayout;
};

