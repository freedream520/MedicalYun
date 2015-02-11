#include "parameters.h"

Parameters::Parameters(QObject *parent)
	: QObject(parent)
{

}

void Parameters::CreatTrayMenu()  
{  
	miniSizeAction = new QAction("Min(&N)",this);  
	maxSizeAction = new QAction("Max(&X)",this);  
	restoreWinAction = new QAction("Restore(&R)",this);  
	quitAction = new QAction("Quit(&Q)",this);  
	this->connect(miniSizeAction,SIGNAL(triggered()),this,SLOT(hide()));  
	this->connect(maxSizeAction,SIGNAL(triggered()),this,SLOT(showMaximized()));  
	this->connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));  
	this->connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));  
	myMenu = new QMenu((QWidget*)QApplication::desktop());  
	myMenu->addAction(miniSizeAction);  
	myMenu->addAction(maxSizeAction);  
	myMenu->addAction(restoreWinAction);  
	myMenu->addSeparator();     //����һ�������  
	myMenu->addAction(quitAction);  
}  

void Parameters::CreatTrayIcon()
{
	CreatTrayMenu();  
	if (!QSystemTrayIcon::isSystemTrayAvailable())      //�ж�ϵͳ�Ƿ�֧��ϵͳ����ͼ��  
	{  
		return;  
	}  
	myTrayIcon = new QSystemTrayIcon(this);  
	myTrayIcon->setIcon(QIcon("VIRSIMlogo.ico"));   //����ͼ��ͼƬ  
	setWindowIcon(QIcon("VIRSIMlogo.ico"));  //��ͼƬ���õ�������  
	myTrayIcon->setToolTip("UpLoad V1.0");    //����ʱ��������ȥ����ʾ��Ϣ  
	myTrayIcon->showMessage("server","server",QSystemTrayIcon::Information,10000);  
	myTrayIcon->setContextMenu(myMenu);     //�������������Ĳ˵�  
	myTrayIcon->show();  
	this->connect(myTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));  
}

void Parameters::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch(reason)
	{
	case QSystemTrayIcon::Trigger:
	case QSystemTrayIcon::DoubleClick:  
		showNormal(); 
		break; 
	case QSystemTrayIcon::MiddleClick:  
		myTrayIcon->showMessage("server","server",QSystemTrayIcon::Information,10000);  
		break;  
	default:  
		break;
	}
}

void Parameters::closeEvent(QCloseEvent *event)  
{  
	if (myTrayIcon->isVisible())  
	{  
		myTrayIcon->showMessage("server","hide",QSystemTrayIcon::Information,5000);  

		hide();     //��С��  
		event->ignore();  
	}  
	else  
		event->accept();  
} 

Parameters::~Parameters()
{

}
