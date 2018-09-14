#pragma once
#include <qlistwidget.h>
#include <qmouseeventtransition.h>
#include <QListWidget>
#include <QtGui>
#include <QApplication>
#include <iostream>
#pragma execution_character_set("utf-8")
using namespace std;

class MyListwidget :
	public QListWidget
{
	Q_OBJECT
public:
	MyListwidget(QWidget* parent = 0);
	~MyListwidget();

signals:
	void acceptFileName(QString);
	void acceptUrl(QUrl);

protected:
	//重写下面两个函数来完成从该部件中拖拽出去的操作.
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	//重写下面三个函数来完成接受外来拖拽的操作.
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);

private:
	//记录拖拽的起点.
	QPoint m_dragPoint;
	//记录被拖拽的项.
	QListWidgetItem *m_dragItem;
};

