#include "netwatch.h"

netwatch::netwatch()
	: QThread()
{
	//_netwatch = new QNetworkConfigurationManager();
	m_bServerConnected = false;  

	m_pTcpSocket = new QTcpSocket;  
	connect(m_pTcpSocket, SIGNAL(connected()), this, SLOT(OnSocketConnected()));  
	connect(m_pTcpSocket, SIGNAL(disconnected()), this, SLOT(OnSocketDisconnected()));  
	connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnSocketError(QAbstractSocket::SocketError)));  

	connect(&m_timer, SIGNAL(timeout()), this, SLOT(ConnectServer()));  
	m_timer.setInterval(3000);  
	m_timer.start();  

	moveToThread(this);//must be the last executed  
}

void netwatch::run()
{
	//while(true)
	//{
	//	Sleep(1000);
	//	//QNetworkConfigurationManager _netwatch;
	//	if(!_netwatch->isOnline())
	//	{
	//		//QMessageBox::information(this,"warning","new close");
	//		qDebug()<<"���������ж�";
	//	}
	//}
	exec();
}

void netwatch::OnSocketConnected()  
{  
	emit ShowStatus("Server connected");  
	m_bServerConnected = true;  
	qDebug()<<"�������ӳɹ�";
}  

void netwatch::OnSocketDisconnected()  
{  
	emit ShowStatus("Server disconnected");  
	m_bServerConnected = false;  
	qDebug()<<"���������ж�";
}  

void netwatch::OnSocketError(QAbstractSocket::SocketError error)  
{  
	emit ShowStatus(m_pTcpSocket->errorString());  
	qDebug()<<"�������Ӵ���";
}  

void netwatch::ConnectServer()  
{  
	if(!m_bServerConnected)  
	{  
		m_pTcpSocket->connectToHost("192.168.1.45", 19842);  
		//m_pTcpSocket->waitForConnected(2000);//���������䣬����Ῠ��  
	}  
}  

netwatch::~netwatch()
{

}
