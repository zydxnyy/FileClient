#pragma once
#include <qwidget.h>
#include <qmessagebox.h>
#include "ui_UploadWidget.h"
#include "LocalExplorer.h"
#include "RemoteExplorer.h"
#include "DspyTaskItem.h"
#include "util.h"
#pragma execution_character_set("utf-8")

class UploadWidget: public QWidget
{
	Q_OBJECT
public:
	UploadWidget(Proj_Container* proteinProjects, Proj_Container* drugProjects, Proj_Container* animalProjects, QWidget* parent = 0);
	~UploadWidget();

signals:
	void addUploadTask(const string& path, const int& typeId, const string& projName, DspyTaskItem*);
	void addDownloadTask(const int& type, const string& projname, const string& filename, const string& localpath, DspyTaskItem*);
	void appendHistory(QString&);
	void takeFile(string, string, string);

public slots:
	void uploadSlot();
	void dragFileUploadSlot(string localFileName);
	void dragFileDownloadSlot(string);
	void dragUrlUploadSlot(QUrl url);
	void downloadSlot();

	void createUploadTaskSlot(string localPath, string remotePath);
	void createDownloadTaskSlot(string localPath, string remotePath);

	void refreshDir();

	void takeFileSlot(string, string, string);
	void doneSlots(QListWidgetItem*);

private:
	Ui::UploadWidget ui;
	LocalExplorer* localExplorer;
	RemoteExplorer* remoteExplorer;
	Proj_Container* proteinProjects;
	Proj_Container* drugProjects;
	Proj_Container* animalProjects;
};

