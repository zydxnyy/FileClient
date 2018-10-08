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
	void updateFileDir(string type, QString&, MyFile*);
	int get_projects();
	void takeFile(string, string, string);

	//刷新目录
	void refresh();
	//重新认证
	void reVerify();
	//切换用户
	void switchUser();
	//退出
	void exitExe();
private:
	Ui::FileClientClass ui;
	Proj_Container proteinProjects;
	Proj_Container drugProjects;
	Proj_Container animalProjects;
	UploadWidget* uploadWidget;
	TaskWidget* taskWidget;
	HistoryWidget* historyWidget;
};
