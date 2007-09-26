#include <QApplication>
#include <QPushButton>

int
main(
	int argc,
	char** argv
	)
{
	QApplication App(argc, argv);
	QPushButton Button("Quit");
	QObject::connect(&Button, SIGNAL(clicked()), &App, SLOT(quit()));
	Button.show();
	return App.exec();
}
