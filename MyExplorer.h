#pragma once
#include <qobject.h>
#include <iostream>
#include "util.h"
#include <string.h>
#include <qwidget.h>
#include "HistoryList.h"
#include "ui_MyExplorer.h"
using namespace std;
#pragma execution_character_set("utf-8")

class MyExplorer: public QWidget
{
	Q_OBJECT

public:
	MyExplorer(QWidget* parent = 0, string path="/");
	~MyExplorer();
	
	//根据path获取当前路径的文件，存放在fileList里
	virtual void getFileList();
	void clearHistory();
	virtual string getDirPath();
	virtual string getFilePath();
	virtual bool validPath() = 0;

signals:
	//void createUploadTask(string, string);
	//void createDownloadTask(string, string);

public slots:
	void enterDir(const string&);
	void outDir();
	void next();
	void previous();
	virtual void enterDirSlot(QModelIndex);
	void enterPress();
	//更新目录
	void updateFileList();

	virtual void acceptFileName(QString) = 0;
	virtual void acceptUrl(QUrl) = 0;

	virtual void menu(QPoint) = 0;

protected:
	bool isOutable();
	//设置前进后退按钮的可用性
	void setBtnStatus();
	string path;
	vector<MyFile> fileList;
	HistoryList history;
	Ui::MyExplorer ui;
};

