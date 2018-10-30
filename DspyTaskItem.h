#pragma once

#include <QWidget>
#include <qlistwidget.h>
#include "ui_DspyTaskItem.h"
#include "TaskItem.h"
#pragma execution_character_set("utf-8")

class DspyTaskItem : public QWidget
{
	Q_OBJECT

public:
	DspyTaskItem(QListWidgetItem* p, std::string filename, QWidget *parent = Q_NULLPTR);
	~DspyTaskItem();

signals:
	int done(QListWidgetItem*);
public slots:
	int update_pb_slot(int);
	int complete_slot(TaskItem*, QListWidgetItem*, int);
	int close_slot();
private:
	bool isPause;
	Ui::DspyTaskItemForm ui;
	QListWidgetItem* p;
};
