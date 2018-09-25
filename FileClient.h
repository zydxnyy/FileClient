#pragma once

#include <QtWidgets/QMainWindow>
#include <iostream>
#include <vector>
#include <qmessagebox.h>
#include <json/json.h>
#include <qdebug.h>
#include "TaskWidget.h"
#include "UploadWidget.h"
#include "HistoryWidget.h"
#include "ui_FileClient.h"
#include "util.h"
#include "Login.h"

#pragma execution_character_set("utf-8")
using namespace std;


class FileClient : public QMainWindow
{
	Q_OBJECT

public:
	FileClient(QWidget *parent = Q_NULLPTR);
public slots:
	void updateFileDir(QString&, MyFile*);
	int get_projects();
	void takeFile(string, string);

	//ˢ��Ŀ¼
	void refresh();
	//������֤
	void reVerify();
	//�л��û�
	void switchUser();
	//�˳�
	void exitExe();
private:
	Ui::FileClientClass ui;
	Proj_Container projects;
	Proj_Container self_projects;
	UploadWidget* uploadWidget;
	TaskWidget* taskWidget;
	HistoryWidget* historyWidget;
};
