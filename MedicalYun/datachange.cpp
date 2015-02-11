#include "datachange.h"

datachange::datachange(QObject *parent)
	: QObject(parent)
{
}

void datachange::writeINI(QString filewatchpath)
{ 
	//QSettings���캯���ĵ�һ��������ini�ļ���·��,�ڶ���������ʾ���ini�ļ�,��������������ȱʡ  
	QSettings *configIniWrite = new QSettings("Setting.ini", QSettings::IniFormat);  
	//configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));
	//��ini�ļ���д������,setValue���������������Ǽ�ֵ��  
	configIniWrite->setValue("/watchpath/first", filewatchpath);  
	configIniWrite->setValue("/watchpath/second", "1"); 
	//д����ɺ�ɾ��ָ��  
	delete configIniWrite;  
}

void datachange::setwriteINI()
{
	//QSettings���캯���ĵ�һ��������ini�ļ���·��,�ڶ���������ʾ���ini�ļ�,��������������ȱʡ  
	QSettings *configIniWrite = new QSettings("Setting.ini", QSettings::IniFormat);  
	//configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));
	//��ini�ļ���д������,setValue���������������Ǽ�ֵ��  
	configIniWrite->setValue("/watchpath/second", "2");  
	//д����ɺ�ɾ��ָ��  
	delete configIniWrite; 
}

QString datachange::valueReadINI()
{
	QSettings *configIniRead = new QSettings("Setting.ini", QSettings::IniFormat);  
	//configIniRead->setIniCodec(QTextCodec::codecForName("GB2312"));
	//����ȡ����ini�ļ�������QString�У���ȡֵ��Ȼ��ͨ��toString()����ת����QString����   
	QString pathResult = configIniRead->value("/watchpath/second").toString();    
	//��ӡ�õ��Ľ��   
	qDebug() << pathResult;    
	//��������ɺ�ɾ��ָ��   
	delete configIniRead;
	return pathResult;
}

QString datachange::readINI(QString filewatchpath)
{
	QSettings *configIniRead = new QSettings("Setting.ini", QSettings::IniFormat);  
	//configIniRead->setIniCodec(QTextCodec::codecForName("GB2312"));
	//����ȡ����ini�ļ�������QString�У���ȡֵ��Ȼ��ͨ��toString()����ת����QString����   
	QString pathResult = configIniRead->value("/watchpath/first").toString();    
	//��ӡ�õ��Ľ��   
	qDebug() << pathResult;    
	//��������ɺ�ɾ��ָ��   
	delete configIniRead;
	return pathResult;
}

bool datachange::fileExist(QString path)
{
	QFileInfo fileinfo(path);
	if(fileinfo.isFile());
	{
		if(fileinfo.exists())
		{
			return true;
		}
	}
	return false;
}

void datachange::fileWatchPath(QString filewatchpath)
{
	//QString dirs = QFileDialog::getExistingDirectory(this,tr("����ļ���"),"/home",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
}

QByteArray datachange::getFileMd5(QString filePath)
{
	QFile localFile(filePath);

	if (!localFile.open(QFile::ReadOnly))
	{
		qDebug() << "file open error.";
		return 0;
	}
	QCryptographicHash ch(QCryptographicHash::Md5);
	quint64 totalBytes = 0;
	quint64 bytesWritten = 0;
	quint64 bytesToWrite = 0;
	quint64 loadSize = 1024 * 4;
	QByteArray buf;
	totalBytes = localFile.size();
	bytesToWrite = totalBytes;
	while (1)
	{
		if(bytesToWrite > 0)
		{
			buf = localFile.read(qMin(bytesToWrite, loadSize));
			ch.addData(buf);
			bytesWritten += buf.length();
			bytesToWrite -= buf.length();
			buf.resize(0);
		}
		else
		{
			break;
		}

		if(bytesWritten == totalBytes)
		{
			break;
		}
	}
	localFile.close();
	QByteArray md5 = ch.result();
	return md5;
}

QString datachange::FileDigest(QString FilePath)  
{  
	QFile file(FilePath);
	QString macmd5 = "";
	if(file.exists(FilePath))
	{
		file.open(QIODevice::ReadOnly);
		QTextStream stream(&file);
		//stream.setCodec(code);//�����������
		QString txt="";
		txt=stream.readAll();
		QByteArray byte;
		byte = txt.toAscii();
		macmd5=QCryptographicHash::hash(byte,QCryptographicHash::Md5).toHex().constData();
	}
	return macmd5;
} 

datachange::~datachange()
{

}
