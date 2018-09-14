#pragma once
#include <qwidget.h>
#include <qmessagebox.h>
#include "ui_UploadWidget.h"
#include "LocalExplorer.h"
#include "RemoteExplorer.h"
#include "util.h"
#pragma execution_character_set("utf-8")

class UploadWidget: public QWidget
{
	Q_OBJECT
public:
	UploadWidget(Proj_Container* pProjects, QWidget* parent = 0);
	~UploadWidget();

signals:
	void addUploadTask(const string& path, const string& projName);
	void addDownloadTask(const string& projname, const string& filename, const string& localpath);
	void appendHistory(QString&);
	void takeFile(string, string);

public slots:
	void uploadSlot();
	void dragFileUploadSlot(string localFileName);
	void dragFileDownloadSlot(string);
	void dragUrlUploadSlot(QUrl url);
	void downloadSlot();

	void createUploadTaskSlot(string localPath, string remotePath);
	void createDownloadTaskSlot(string localPath, string remotePath);

	void refreshDir();

	void takeFileSlot(string, string);

private:
	Ui::UploadWidget ui;
	LocalExplorer* localExplorer;
	RemoteExplorer* remoteExplorer;
	Proj_Container* pProjects;
};

