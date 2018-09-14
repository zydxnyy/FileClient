#include "UploadWidget.h"


UploadWidget::UploadWidget(Proj_Container* pProjects, QWidget* parent):
	QWidget(parent), pProjects(pProjects)
{
	ui.setupUi(this);
	localExplorer = new LocalExplorer(this);
	remoteExplorer = new RemoteExplorer(pProjects, this);
	localExplorer->setGeometry(0, 0, 530, 540);
	remoteExplorer->setGeometry(630, 0, 530, 540);
	localExplorer->show();
	remoteExplorer->show();
	
	ui.uploadBtn->setIcon(QIcon("pic/right.png"));
	ui.downloadBtn->setIcon(QIcon("pic/left.png"));

	connect(remoteExplorer, SIGNAL(dragFileUpload(string)), this, SLOT(dragFileUploadSlot(string)));
	connect(remoteExplorer, SIGNAL(dragUrlUpload(QUrl)), this, SLOT(dragUrlUploadSlot(QUrl)));
	connect(remoteExplorer, SIGNAL(takeFile(string ,string)), this, SLOT(takeFileSlot(string, string)));
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
	//���Զ��Ŀ¼û�н���Ϸ�Ŀ¼
	if (remotePath.size() < 2 || remotePath[remotePath.size()-2] != '*') {
		QMessageBox::warning(this, "����", "��û�������Ŀ���ϴ�Ȩ��", QMessageBox::Yes);
		return;
	}
	string projname = remotePath.substr(1, remotePath.size()-3);
	emit addUploadTask(localPath, projname);
	emit appendHistory(QString("��������ϴ� %1 ����Ŀ %2\n").arg(get_file_name(localPath).c_str()).arg(projname.c_str()));
	QMessageBox::information(this, "��ӳɹ�", QString("��������ϴ� %1 ����Ŀ %2").arg(get_file_name(localPath).c_str()).arg(projname.c_str()),
		QMessageBox::Yes);
}

void UploadWidget::createDownloadTaskSlot(string localPath, string remotePath) {
	qDebug() << localPath.c_str() << " " << remotePath.c_str();
	if (isDir(remotePath.c_str())) {
		QMessageBox::warning(this, "����", "���������ļ���", QMessageBox::Yes);
		return;
	}
	//���û��ѡ���ļ�
	if (remotePath == "") {
		QMessageBox::warning(this, "����", "��ѡ��Ҫ���ص��ļ�", QMessageBox::Yes);
		return;
	}
	int slashPos = remotePath.find('/', 1);
	//���Զ��Ŀ¼û�н���Ϸ�Ŀ¼
	if (slashPos == -1) {
		QMessageBox::warning(this, "����", "��û�������Ŀ������Ȩ��", QMessageBox::Yes);
		return;
	}

	string projname;
	if (remotePath.find('*') != -1) {
		projname = remotePath.substr(1, slashPos - 2);
	}
	else {
		projname = remotePath.substr(1, slashPos - 1);
	}
	string filename = remotePath.substr(slashPos + 1);
	qDebug() << projname.c_str() << " " << filename.c_str() << " to " << localPath.c_str() << endl;
	emit addDownloadTask(projname, filename, localPath);
	emit appendHistory(QString("����������� %1 ��Ŀ�ļ� %2 ������·�� %3\n").arg(projname.c_str()).arg(filename.c_str()).arg(localPath.c_str()));
	QMessageBox::information(this, "��ӳɹ�", QString("����������� %1 ��Ŀ�ļ� %2 ������·�� %3\n").arg(projname.c_str()).arg(filename.c_str()).arg(localPath.c_str()),
		QMessageBox::Yes);
}

void UploadWidget::refreshDir()
{
	remoteExplorer->updateFileList();
	localExplorer->updateFileList();
}

void UploadWidget::takeFileSlot(string pn, string fn)
{
	emit takeFile(pn, fn);
}

void UploadWidget::downloadSlot() {
	string localPath = localExplorer->getDirPath();
	string remotePath = remoteExplorer->getFilePath();

	createDownloadTaskSlot(localPath, remotePath);
}
