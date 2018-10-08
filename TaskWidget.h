#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <iostream>
#include <time.h>
#include "ui_TaskWidget.h"
#include "UploadTaskItem.h"
#include "DownloadTastItem.h"
#include "TaskItem.h"
#include "DspyTaskItem.h"
using namespace std;
#pragma execution_character_set("utf-8")

class TaskWidget :
	public QWidget
{
	Q_OBJECT
public:
	TaskWidget(QWidget* paretn = 0);
	~TaskWidget();

signals:
	void appendHistory(QString&);
	void updateFileDir(string ss = string(""), QString& s = QString(""), MyFile* f = NULL);
public slots:
	void addUploadTask(const string& path, const int& typeId, const string& projName, DspyTaskItem* p);
	void addDownloadTask(const int& typeId, const string& projName, const string& filename, const string& path, DspyTaskItem* p);
	int doneSlot(TaskItem*, QListWidgetItem*, int status);

private:
	Ui::TaskWidget ui;
};

