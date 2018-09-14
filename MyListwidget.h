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
	//��д����������������ɴӸò�������ק��ȥ�Ĳ���.
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	//��д����������������ɽ���������ק�Ĳ���.
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);

private:
	//��¼��ק�����.
	QPoint m_dragPoint;
	//��¼����ק����.
	QListWidgetItem *m_dragItem;
};

