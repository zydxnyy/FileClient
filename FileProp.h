#pragma once
#include <qwidget.h>
#include <qdialog.h>
#include "ui_FileProperty.h"
#include "util.h"
#pragma execution_character_set("utf-8")
class FileProp :
	public QDialog
{
	Q_OBJECT
public:
	FileProp(MyFile m, QDialog* parent = 0);
	~FileProp();

private:
	Ui::FilePropDialog ui;
};

