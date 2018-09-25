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
	RemoteExplorer(Proj_Container* pProj, QWidget* parent = 0);
	~RemoteExplorer();
	virtual bool validPath();

signals:
	void dragFileUpload(string);
	void dragUrlUpload(QUrl);
	void takeFile(string, string);
	void menuFileDownload(string);

public slots:
	virtual void acceptFileName(QString);
	virtual void acceptUrl(QUrl);
	virtual void menu(QPoint);

	void delFile(bool);
	void downloadFile(bool); 
	void openProperty(bool);
	 
	virtual void getFileList();
	Proj* getProject();
private:
	Proj_Container* pProjects;
	QListWidgetItem* item;

	const string TYPE[3] = { "Protein", "P1", "P2" };
};

