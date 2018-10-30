#include "UploadWidget.h"

UploadWidget::UploadWidget(Proj_Container* proteinProjects, Proj_Container* drugProjects, Proj_Container* animalProjects, QWidget* parent):
	QWidget(parent), proteinProjects(proteinProjects), drugProjects(drugProjects), animalProjects(animalProjects)
{
	ui.setupUi(this);
	localExplorer = new LocalExplorer(this);
	remoteExplorer = new RemoteExplorer(proteinProjects, drugProjects, animalProjects, this);
	localExplorer->setGeometry(0, 0, 490, 500);
	remoteExplorer->setGeometry(560, 0, 490, 500);
	localExplorer->show();
	remoteExplorer->show();
	
	ui.uploadBtn->setIcon(QIcon("pic/right.png"));
	ui.downloadBtn->setIcon(QIcon("pic/left.png"));

	connect(remoteExplorer, SIGNAL(dragFileUpload(string)), this, SLOT(dragFileUploadSlot(string)));
	connect(remoteExplorer, SIGNAL(dragUrlUpload(QUrl)), this, SLOT(dragUrlUploadSlot(QUrl)));
	connect(remoteExplorer, SIGNAL(takeFile(string ,string, string)), this, SLOT(takeFileSlot(string, string, string)));
	connect(localExplorer, SIGNAL(dragFileDownload(string)), this, SLOT(dragFileDownloadSlot(string)));
	connect(localExplorer, SIGNAL(menuFileUpload(string)), this, SLOT(dragFileUploadSlot(string)));
	connect(remoteExplorer, SIGNAL(menuFileDownload(string)), this, SLOT(dragFileDownloadSlot(string)));
}


UploadWidget::~UploadWidget()
{
}


void UploadWidget::uploadSlot() {
	string localPath = localExplorer->getFilePath();
	string remotePath = remoteExplorer->getDirPath();

	createUploadTaskSlot(localPath, remotePath);
}

void UploadWidget::dragFileUploadSlot(string localFileName) {
	string localPath = localExplorer->getDirPath() + localFileName;
	string remotePath = remoteExplorer->getDirPath();

	createUploadTaskSlot(localPath, remotePath);
}

void UploadWidget::dragFileDownloadSlot(string filename) {
	string remotePath = remoteExplorer->getDirPath() + filename;

	string localPath = localExplorer->getDirPath();
	createDownloadTaskSlot(localPath, remotePath);
}

void UploadWidget::dragUrlUploadSlot(QUrl url) {
	QString fileName = url.toLocalFile();
	string localPath = fileName.toStdString();
	string remotePath = remoteExplorer->getDirPath();

	createUploadTaskSlot(localPath, remotePath);
}

void UploadWidget::createUploadTaskSlot(string localPath, string remotePath) {

	string type, projname;
	int typeId;
	int slashCnt = 0, slashPos = -1;
	for (int i = 0; i < remotePath.size(); ++i) {
		if (remotePath[i] == '/') ++slashCnt;
	}
	if (slashCnt != 3) {
		QMessageBox::warning(this, "����", "��û������ļ��е��ϴ�Ȩ��", QMessageBox::Yes);
		return;
	}
	slashPos = remotePath.find('/', 1);
	if (slashPos == -1 || remotePath[0] != '/' || remotePath.back() != '/') {
		QMessageBox::warning(this, "����", "��û������ļ��е��ϴ�Ȩ��", QMessageBox::Yes);
		return;
	}
	type = remotePath.substr(1, slashPos - 1);
	projname = remotePath.substr(slashPos + 1, remotePath.size() - 2 - slashPos);
	qDebug() << localPath.c_str() << " " << remotePath.c_str();
	if (isDir(localPath.c_str())) {
		QMessageBox::warning(this, "����", "�����ϴ��ļ���", QMessageBox::Yes);
		return;
	}
	//�������û��ѡ���ļ�
	if (localPath == "") {
		QMessageBox::warning(this, "����", "��ѡ��Ҫ�ϴ����ļ�", QMessageBox::Yes);
		return;
	}
	vector<Proj*>* projects;
	if (type == TYPE[0]) projects = proteinProjects, typeId = 0;
	else if (type == TYPE[1]) projects = drugProjects, typeId = 1;
	else if (type == TYPE[2]) projects = animalProjects, typeId = 2;
	else {
		QMessageBox::warning(this, "����", "���ʹ���", QMessageBox::Yes);
		return;
	}
	for (int i = 0; i < projects->size(); ++i) {
		if (projname == projects->at(i)->name) {
			if (projects->at(i)->uid != my_uid) {
				QMessageBox::warning(this, "����", "��û�������Ŀ���ϴ�Ȩ��", QMessageBox::Yes);
				return;
			}
		}
	}
	string filename = get_file_name(localPath);
	QListWidgetItem* pItem = new QListWidgetItem();
	pItem->setSizeHint(QSize(700, 40));
	DspyTaskItem* pDItem = new DspyTaskItem(pItem, filename, this);
	ui.listWidget->insertItem(0, pItem);
	ui.listWidget->setItemWidget(pItem, pDItem);
	connect(pDItem, SIGNAL(done(QListWidgetItem*)), this, SLOT(doneSlots(QListWidgetItem*)));

	emit addUploadTask(localPath, typeId, projname, pDItem);
	emit appendHistory(QString("��������ϴ� %1 ����Ŀ %2\n").arg(get_file_name(localPath).c_str()).arg(projname.c_str()));
	//QMessageBox::information(this, "��ӳɹ�", QString("��������ϴ� %1 ����Ŀ %2").arg(get_file_name(localPath).c_str()).arg(projname.c_str()),
	//	QMessageBox::Yes);
}

void UploadWidget::createDownloadTaskSlot(string localPath, string remotePath) {

	string type, projname, filename;
	int typeId;
	int slashCnt = 0, slashPos1, slashPos2;
	for (int i = 0; i < remotePath.size(); ++i) {
		if (remotePath[i] == '/') ++slashCnt;
	}
	if (slashCnt != 3) {
		QMessageBox::warning(this, "����", "��û������ļ��е�����Ȩ��", QMessageBox::Yes);
		return;
	}
	slashPos1 = remotePath.find('/', 1);
	slashPos2 = remotePath.find('/', slashPos1 + 1);
	if (slashPos1 == -1 || remotePath[0] != '/' || slashPos2 == remotePath.size()-1) {
		QMessageBox::warning(this, "����", "��û������ļ��е�����Ȩ��", QMessageBox::Yes);
		return;
	}
	type = remotePath.substr(1, slashPos1 - 1);
	projname = remotePath.substr(slashPos1 + 1, slashPos2 - slashPos1 - 1);
	filename = remotePath.substr(slashPos2 + 1);
	if (type == TYPE[0]) typeId = 0;
	else if (type == TYPE[1]) typeId = 1;
	else if (type == TYPE[2]) typeId = 2;
	else {
		QMessageBox::warning(this, "����", "���ʹ���", QMessageBox::Yes);
		return;
	}

	qDebug() << localPath.c_str() << " " << remotePath.c_str();
	//���û��ѡ���ļ�
	if (remotePath == "") {
		QMessageBox::warning(this, "����", "��ѡ��Ҫ���ص��ļ�", QMessageBox::Yes);
		return;
	}

	QListWidgetItem* pItem = new QListWidgetItem();
	pItem->setSizeHint(QSize(700, 40));
	DspyTaskItem* pDItem = new DspyTaskItem(pItem, filename, this);
	ui.listWidget->insertItem(0, pItem);
	ui.listWidget->setItemWidget(pItem, pDItem);
	connect(pDItem, SIGNAL(done(QListWidgetItem*)), this, SLOT(doneSlots(QListWidgetItem*)));

	qDebug() << projname.c_str() << " " << filename.c_str() << " to " << localPath.c_str() << endl;
	emit addDownloadTask(typeId, projname, filename, localPath, pDItem);
	emit appendHistory(QString("����������� %1 ��Ŀ�ļ� %2 ������·�� %3\n").arg(projname.c_str()).arg(filename.c_str()).arg(localPath.c_str()));
	//QMessageBox::information(this, "��ӳɹ�", QString("����������� %1 ��Ŀ�ļ� %2 ������·�� %3\n").arg(projname.c_str()).arg(filename.c_str()).arg(localPath.c_str()),
	//	QMessageBox::Yes);
}

void UploadWidget::refreshDir()
{
	remoteExplorer->updateFileList();
	localExplorer->updateFileList();
}

void UploadWidget::takeFileSlot(string type, string pn, string fn)
{
	emit takeFile(type, pn, fn);
}

void UploadWidget::doneSlots(QListWidgetItem *p)
{
	for (int i = 0; i < ui.listWidget->count(); ++i) {
		if (ui.listWidget->item(i) == p) {
			ui.listWidget->takeItem(i);
			break;
		}
	}
}

void UploadWidget::downloadSlot() {
	string localPath = localExplorer->getDirPath();
	string remotePath = remoteExplorer->getFilePath();

	createDownloadTaskSlot(localPath, remotePath);
}
