#ifndef MEDICALYUN_H
#define MEDICALYUN_H

#include <QtGui/QMainWindow>
#include "ui_medicalyun.h"
#include "filetransfer.h"

class MedicalYun : public QMainWindow
{
	Q_OBJECT

public:
	MedicalYun(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MedicalYun();

private:
	filetransfer *_filetransfer;
	Ui::MedicalYunClass ui;
};

#endif // MEDICALYUN_H
