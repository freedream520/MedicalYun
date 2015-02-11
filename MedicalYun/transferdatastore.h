#ifndef TRANSFERDATASTORE_H
#define TRANSFERDATASTORE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QFile>

class transferdatastore : public QObject
{
	Q_OBJECT

public:
	transferdatastore(QObject *parent);
	~transferdatastore();

public:
	bool createsqliteDB(QString sqlname);   //�������ݿ�
	bool createtablesqlite(QString tablename); //������
	bool createconnectsqlite(QString sqlname);   //�������ݿ�
	bool insertdatasqlite(QString tablename, QString _server_path, QString _local_path, int _file_size);   //��������
	bool deletedatasqlite(QString tablename, int _deletedata);   //ɾ������
	bool updatadatasqlite(QString tablename, QString _updatadata);  //��������
	QStringList finddatasqlite(QString tablename);   //��ѯ�������ļ��ľ���·����id��ţ��ļ����·�����ļ�����·�����ļ���С
	bool insertAlldatasqlite(QString tablename, QStringList filedata);   //������������
	
	void createmysql(); //����Mysql
	void createmysqlconnect();   //����Mysql
	void filepathstorexml();     //�洢�ļ�·������Ϣ
public:
	QString sqliteName;
	QString fileinfostorename;
	QSqlDatabase db;
	QSqlQuery query;
};

#endif // TRANSFERDATASTORE_H
