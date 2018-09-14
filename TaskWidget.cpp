#include "TaskWidget.h"
#include <time.h>


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
	if (taskItem->getOp() == UPLOAD) op = "�ϴ�";
	else op = "����";
	if (status == MY_NO_ERROR) {
		//�ϴ��ɹ�������Ŀ¼
		if (taskItem->getOp() == UPLOAD) {
			string pname = taskItem->getProjectName();
			string fname = taskItem->getFilename();
			size_t fsize = taskItem->getFilesize();
			string fileHash = taskItem->getFileHash();
			time_t created = time(NULL);
			string email = my_email;
			string path = "/" + pname + "/" + fname;
			emit updateFileDir(QString::fromStdString(pname), new MyFile(false, pname, fname, fsize, created, email, path, fileHash));
		}
		emit appendHistory(QString("%1����%2 ����ɹ�, ��ʱ %3\n").arg(op).arg(taskItem->getFilename().c_str()).arg(timeUsed));
	}
	else {
		emit appendHistory(QString("%1����%2 ����ʧ�� `%3`\n").arg(op).arg(taskItem->getFilename().c_str()).arg(ERROR_STR[status].c_str()));
	}
	//else if (status == 8) emit appendHistory(QString("%1����%2 ��������б���ֹ\n").arg(op).arg(taskItem->getFilename().c_str()));
	//else if (status == 7) emit appendHistory(QString("%1����%2 ����ʧ�ܣ��û���֤���ڣ���������֤\n").arg(op).arg(taskItem->getFilename().c_str()));
	//else emit appendHistory(QString("%1����%2 ����ʧ��, ������� %3\n").arg(op).arg(taskItem->getFilename().c_str()).arg(status));
	ui.listWidget->takeItem(ui.listWidget->row(listItem));
	emit updateFileDir();
	return 0;
}

void TaskWidget::addUploadTask(const string& path, const string& projName) {
	QListWidgetItem* pItem = new QListWidgetItem(ui.listWidget);
	pItem->setSizeHint(QSize(-1, 70));
	ui.listWidget->addItem(pItem);
	UploadTaskItem* pNewItem = new UploadTaskItem(path, projName, pItem, this);
	ui.listWidget->setItemWidget(pItem, pNewItem);
	connect(pNewItem, SIGNAL(done(TaskItem*, QListWidgetItem*, int)), this, SLOT(doneSlot(TaskItem*, QListWidgetItem*, int)));
}

void TaskWidget::addDownloadTask(const string& projName, const string& filename, const string& path) {
	QListWidgetItem* pItem = new QListWidgetItem(ui.listWidget);
	pItem->setSizeHint(QSize(-1, 70));
	ui.listWidget->addItem(pItem);
	DownloadTastItem* pNewItem = new DownloadTastItem(path, projName, filename, 0, pItem, this);
	ui.listWidget->setItemWidget(pItem, pNewItem);
	connect(pNewItem, SIGNAL(done(TaskItem*, QListWidgetItem*, int)), this, SLOT(doneSlot(TaskItem*, QListWidgetItem*, int)));
}