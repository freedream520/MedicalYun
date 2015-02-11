/************************************************************************/
/*                 �ļ�����ģ��                                                                     */
/************************************************************************/
#ifndef FILETRANSFER_H
#define FILETRANSFER_H

#include <QObject>
#include <QDialog>  
#include <QtNetwork/QAbstractSocket>  
//#include <QPushButton>  
//#include <QProgressBar>   
#include <QtNetwork/QTcpSocket>  
#include <QtNetwork/QHostAddress>  
//#include <QtGui/QDialogButtonBox>  
#include <QFile>  
#include <QString>  
#include <QByteArray>  
#include <QFileDialog>  
#include <QApplication>  
#include <QMessageBox>  
#include <QDebug>  
//#include <QHBoxLayout>  
//#include <QVBoxLayout> 
//#include <QThread>

class filetransfer : public QObject
{
	Q_OBJECT

public:
	void filetransferExternalInterface(QString _watchpath, QString _filename);

signals:
	/*������Ϣ*/
	void transferErrorSignal(QString _filename, int _fileid, QString errorinfo);
	/*��������е���Ϣ*/
	void transferDataSignal(QString,QString,QString,QString,QString);
	/*������ɺ����Ϣ*/
	void transferOkSignal();

public slots:
	/*��ʼ����*/
	void start();  
	void startTransfer();  
	void updateClientProgress(qint64 numBytes); 
	/*�������*/
	void displayError(QAbstractSocket::SocketError socketError);  

public:
	filetransfer(QObject *parent);
	~filetransfer();

private:
	QTcpSocket *tcpClient;  //
	bool isOpenFile;
	qint64 TotalBytes;  
	qint64 bytesWritten;  
	qint64 bytesToWrite;  
	qint64 loadSize;    //����ʼ��Ϊһ��4k�ĳ����������ܽ�һ���ϴ���ļ��ָÿ�η���4kb��С
	QString m_fileName;  //�ļ�����·������
	QFile *localFile;  
	QByteArray outBlock; 

	QString clientMessage;
	bool blIsopenfile;     //�ļ��ѱ���
	QString m_watchpath;   //�ļ�����·��
};

#endif // FILETRANSFER_H
