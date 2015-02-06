#ifndef MEDICALYUN_H
#define MEDICALYUN_H

#include <QtGui/QMainWindow>
#include "ui_medicalyun.h"

class MedicalYun : public QMainWindow
{
	Q_OBJECT

public:
	MedicalYun(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MedicalYun();

private:
	Ui::MedicalYunClass ui;
};

#endif // MEDICALYUN_H
