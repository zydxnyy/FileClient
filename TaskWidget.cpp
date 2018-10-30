#include "TaskWidget.h"
#include <time.h>
#include <qmessagebox.h>

TaskWidget::TaskWidget(QWidget* parent):
	QWidget(parent)
{
	ui.setupUi(this);
}


TaskWidget::~TaskWidget()
{
}

int TaskWidget::doneSlot(TaskItem* taskItem, QListWidgetItem* listItem, int status)
{
	QString op;
	int diff = taskItem->getTimeElapsed();
	//qDebug() << "Used second = " << diff;
	int hour = diff / 3600; diff %= 3600;
	int mins = diff / 60; diff %= 60;
	int sec = diff;
	QString timeUsed = QString("%1:%2:%3").arg(hour).arg(mins).arg(sec);
	if (taskItem->getOp() == UPLOAD) op = "上传";
	else op = "下载";
	if (status == MY_NO_ERROR) {
		//上传成功，更新目录
		if (taskItem->getOp() == UPLOAD) {
			string type = TYPE[taskItem->getType()];
			string pname = taskItem->getProjectName();
			string fname = taskItem->getFilename();
			size_t fsize = taskItem->getFilesize();
			string fileHash = taskItem->getFileHash();
			time_t created = time(NULL);
			string email = my_email;
			string path = "/" + type + "/" + pname + "/" + fname;
			emit updateFileDir(type, QString::fromStdString(pname), new MyFile(false,taskItem->getType(), pname, fname, fsize, created, email, path, fileHash));
		}
		else {
			emit updateFileDir("", QString(""), nullptr);
		}
		emit appendHistory(QString("%1任务：%2 传输成功, 用时 %3\n").arg(op).arg(taskItem->getFilename().c_str()).arg(timeUsed));
	}
	else if (status == TOKEN_EXPIRE) {
		QMessageBox::warning(this, "", "用户已过期，请重新验证", QMessageBox::Yes);
		emit updateFileDir("", QString(""), nullptr);
	}
	else {
		emit updateFileDir("", QString(""), nullptr);
		emit appendHistory(QString("%1任务：%2 传输失败 `%3`\n").arg(op).arg(taskItem->getFilename().c_str()).arg(ERROR_STR[status].c_str()));
	}
	ui.listWidget->takeItem(ui.listWidget->row(listItem));
	return 0;
}

void TaskWidget::addUploadTask(const string& path, const int& typeId, const string& projName, DspyTaskItem* p) {
	QListWidgetItem* pItem = new QListWidgetItem(ui.listWidget);
	pItem->setSizeHint(QSize(-1, 70));
	ui.listWidget->insertItem(0, pItem);
	UploadTaskItem* pNewItem = new UploadTaskItem(path, typeId, projName, pItem, this);
	ui.listWidget->setItemWidget(pItem, pNewItem);
	connect(pNewItem, SIGNAL(done(TaskItem*, QListWidgetItem*, int)), this, SLOT(doneSlot(TaskItem*, QListWidgetItem*, int)));
	connect(pNewItem, SIGNAL(update_pb(int)), p, SLOT(update_pb_slot(int)));
	connect(pNewItem, SIGNAL(done(TaskItem*, QListWidgetItem*, int)), p, SLOT(complete_slot(TaskItem*, QListWidgetItem*, int)));
}

void TaskWidget::addDownloadTask(const int& typeId, const string& projName, const string& filename, const string& path, DspyTaskItem* p) {
	QListWidgetItem* pItem = new QListWidgetItem(ui.listWidget);
	pItem->setSizeHint(QSize(-1, 70));
	ui.listWidget->insertItem(0, pItem);
	DownloadTastItem* pNewItem = new DownloadTastItem(path, typeId, projName, filename, 0, pItem, this);
	ui.listWidget->setItemWidget(pItem, pNewItem);
	connect(pNewItem, SIGNAL(done(TaskItem*, QListWidgetItem*, int)), this, SLOT(doneSlot(TaskItem*, QListWidgetItem*, int)));
	connect(pNewItem, SIGNAL(update_pb(int)), p, SLOT(update_pb_slot(int)));
	connect(pNewItem, SIGNAL(done(TaskItem*, QListWidgetItem*, int)), p, SLOT(complete_slot(TaskItem*, QListWidgetItem*, int)));
}