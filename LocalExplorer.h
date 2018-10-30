#pragma once
#include "MyExplorer.h"
#include <qwidget.h>
#include <iostream>
#include <QDir>
#include <qmessagebox.h>
#include <qsettings.h>
#include "FileProp.h"
using namespace std;
#pragma execution_character_set("utf-8")

class LocalExplorer: public MyExplorer
{
	Q_OBJECT
public:
	LocalExplorer(QWidget* parent = 0);
	~LocalExplorer();
	virtual bool validPath();

	virtual void getFileList();

	void setDrive(const string& s) { drive = s; }

	virtual string getDirPath();
	virtual string getFilePath();

signals:
	void dragFileDownload(string);
	void menuFileUpload(string);

public slots:
	int indexChangedSlot(int);
	virtual void acceptFileName(QString);
	virtual void acceptUrl(QUrl);
	virtual void menu(QPoint);
	virtual void enterDirSlot(QModelIndex);

	void uploadFile(bool);
	void openFile(bool);
	void delFile(bool);
	void openProperty(bool);
private:
	QDir *drives;
	QComboBox* box;
	string drive;
	QListWidgetItem* item;
	QSettings setting;
};

