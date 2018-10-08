#pragma once
#include <qwidget.h>
#include <atomic>
#include <thread>
#include <QMetaType>
#include <qlistwidget.h>
#include "ui_TaskItem.h"
#include "util.h"
using namespace std;
#pragma execution_character_set("utf-8")

class TaskItem :public QWidget
{
	Q_OBJECT
public:
	TaskItem(OP_TYPE op, const string& filename, size_t filesize, QListWidgetItem* p, const string& path, int typeId, const string& projName, QWidget* parent = 0);
	~TaskItem();

	void start();

signals:
	int update_speed(double, int);
	int update_pb(int);
	int complete(int);
	void updateFilesize(size_t);

	int done(TaskItem*, QListWidgetItem*, int);
public slots:
	int update_speed_slot(double, int);
	int update_pb_slot(int);
	int complete_slot(int);

	int toggleSlot();
	int stopSlot();
	void updateFilesizeSlot(size_t);

public:
	string getFilename() { return filename; }
	int getTimeElapsed() { return timeElapsed; }
	OP_TYPE getOp() { return op; }
	string getProjectName() { return projectName; }
	size_t getFilesize() { return filesize; }
	string getFileHash() { return fileHash; }
	int getType() { return typeId; }
protected:
	//ÉÏ´«/ÏÂÔØroutine
	virtual void task() = 0;

	Ui::TaskItemWidget ui;
	OP_TYPE op;
	atomic_bool pause, stop;
	string filename;
	size_t filesize;
	time_t start_time, end_time, record_time;
	int timeElapsed;
	QListWidgetItem* pWidgetItem;

	string projectName;
	int typeId;
	string path;

	string fileHash;
};

//Q_DECLARE_METATYPE(TaskItem)
