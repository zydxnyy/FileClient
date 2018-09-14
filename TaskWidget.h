#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <iostream>
#include <time.h>
#include "ui_TaskWidget.h"
#include "UploadTaskItem.h"
#include "DownloadTastItem.h"
#include "TaskItem.h"
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
	void updateFileDir(QString& s = QString(""), MyFile* f = NULL);
public slots:
	void addUploadTask(const string& path, const string& projName);
	void addDownloadTask(const string& projName, const string& filename, const string& path);
	int doneSlot(TaskItem*, QListWidgetItem*, int status);

private:
	Ui::TaskWidget ui;
};

