#pragma once
#include <qwidget.h>
#include "MyExplorer.h"
#include "util.h"
#include "udt.h"
#pragma execution_character_set("utf-8")

class RemoteExplorer :
	public MyExplorer
{
	Q_OBJECT
public:
	RemoteExplorer(Proj_Container* proteinProjects, Proj_Container* drugProjects, Proj_Container* animalProjects, QWidget* parent = 0);
	~RemoteExplorer();
	virtual bool validPath();

signals:
	void dragFileUpload(string);
	void dragUrlUpload(QUrl);
	void takeFile(string, string, string);
	void menuFileDownload(string);

public slots:
	virtual void acceptFileName(QString);
	virtual void acceptUrl(QUrl);
	virtual void menu(QPoint);

	void delFile(bool);
	void downloadFile(bool); 
	void openProperty(bool);
	 
	virtual void getFileList();
private:
	Proj_Container* proteinProjects;
	Proj_Container* drugProjects;
	Proj_Container* animalProjects;
	Proj_Container* projects;
	QListWidgetItem* item;
};

