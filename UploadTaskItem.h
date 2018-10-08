#pragma once
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <qlistwidget.h>
#include "udt.h"
#include "util.h"
#include "TaskItem.h"
using namespace std;
#pragma execution_character_set("utf-8")

class UploadTaskItem :
	public TaskItem
{
public:
	UploadTaskItem(const string& path, int typeId, const string& projName, QListWidgetItem* p, QWidget* parent = 0);
	~UploadTaskItem();

	virtual void task();

private:
};

