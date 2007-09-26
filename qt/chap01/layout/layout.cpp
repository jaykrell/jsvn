#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int
main(
	int argc,
	char** argv
	)
{
	QApplication App(argc, argv);

	QWidget Window;
	Window.setWindowTitle("Enter Your Age");

	QSpinBox SpinBox;
	QSlider Slider(Qt::Horizontal);
	SpinBox.setRange(0, 130);
	Slider.setRange(0, 130);

	QObject::connect(&SpinBox, SIGNAL(valueChanged(int)),
			&Slider, SLOT(setValue(int)));
	QObject::connect(&Slider, SIGNAL(valueChanged(int)),
			&SpinBox, SLOT(setValue(int)));
	SpinBox.setValue(35);

	QHBoxLayout Layout;
	Layout.addWidget(&SpinBox);
	Layout.addWidget(&Slider);
	Window.setLayout(&Layout);

	Window.show();

	return App.exec();
}
