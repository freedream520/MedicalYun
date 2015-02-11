#include "medicalyun.h"

MedicalYun::MedicalYun(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//_filetransfer = new filetransfer(this);
	//_filetransfer->filetransferExternalInterface("E:\\FileLoad", "E:/FileLoad/a.db");
}

MedicalYun::~MedicalYun()
{

}
