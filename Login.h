#pragma once
#include <qdialog.h>
#include <iostream>
#include <qmessagebox.h>
#include <iostream>
#include <Python.h>
#include <qdebug.h>
#include <thread>
#include "util.h"
#include "ui_Login.h"
#include <qsettings.h>
#pragma execution_character_set("utf-8")
using namespace std;


class Login: public QDialog
{
	Q_OBJECT
public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();

signals:
	void loginDone(Py_Ret);

public slots:
	int login_slot();
	void loginDoneSlot(Py_Ret);

private:
	Ui::Dialog ui;
	QSettings setting;
};

