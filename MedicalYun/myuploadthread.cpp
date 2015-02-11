#include "myuploadthread.h"

myuploadthread::myuploadthread()
	: QThread()
{
	_filetransfer = new filetransfer(this);
	_filetransfer->filetransferExternalInterface("E:\\FileLoad", "E:/FileLoad/a.db");
}

myuploadthread::~myuploadthread()
{

}

void myuploadthread::run()
{
	
	exec();
}
