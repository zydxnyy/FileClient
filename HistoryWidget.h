#pragma once
#include <qwidget.h>
#include "ui_HistoryWidget.h"
#pragma execution_character_set("utf-8")
class HistoryWidget :
	public QWidget
{
	Q_OBJECT
public:
	HistoryWidget(QWidget* parent = 0);
	~HistoryWidget();

public slots:
	void appendHistory(QString&);

private:
	Ui::HistoryWidget ui;
};

