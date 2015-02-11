#ifndef DATACHANGE_H
#define DATA_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextCodec>
#include <QByteArray>
#include <QCryptographicHash>

class datachange : public QObject
{
	Q_OBJECT

public:
	datachange(QObject *parent);
	~datachange();
	void writeINI(QString filewatchpath);   //��ȡINI�ļ�
	void setwriteINI();   //��һ�μ���
	QString valueReadINI();//��һ�μ���
	QString readINI(QString filewatchpath);    //дINI�ļ�
	bool fileExist(QString path);  //�ļ��Ƿ����
	void fileWatchPath(QString filewatchpath);//�޸��ļ�����·��
	QByteArray getFileMd5(QString filePath);   //��ȡ�ļ�MD5�룬������
	QString FileDigest(QString FilePath);     //��ȡ�ļ�MD5��

private:
	
};

#endif // DATACHANGE_H
