#include "medicalyun.h"
#include "myuploadthread.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	myuploadthread *_myuploadthread = new myuploadthread();
	_myuploadthread->start();
	MedicalYun w;
	w.show();
	return a.exec();
}
