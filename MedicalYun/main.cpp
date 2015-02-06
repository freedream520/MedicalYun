#include "medicalyun.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MedicalYun w;
	w.show();
	return a.exec();
}
