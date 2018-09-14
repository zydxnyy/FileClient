#pragma once
#include <qdialog.h>
#include <iostream>
#include <qmessagebox.h>
#include <iostream>
#include <Python.h>
#include <qdebug.h>
#include "util.h"
#include "ui_Login.h"
#pragma execution_character_set("utf-8")
using namespace std;


class Login: public QDialog
{
	Q_OBJECT
public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();

public slots:
	int login_slot();

private:
	Ui::Dialog ui;
};

