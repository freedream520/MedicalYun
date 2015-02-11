#ifndef MYUPLOADTHREAD_H
#define MYUPLOADTHREAD_H

#include "filetransfer.h"
#include <QObject>
#include <QThread>

class myuploadthread : public QThread
{
	Q_OBJECT

private:
	void run();    //线程执行函数
public:
	myuploadthread();
	~myuploadthread();

private:
	filetransfer *_filetransfer;
};

#endif // MYUPLOADTHREAD_H
