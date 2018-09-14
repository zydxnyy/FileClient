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
		QMessageBox::warning(this, "错误", "不能上传文件夹", QMessageBox::Yes);
		return;
	}
	//如果本地没有选中文件
	if (localPath == "") {
		QMessageBox::warning(this, "错误", "请选择要上传的文件", QMessageBox::Yes);
		return;
	}
	//如果远程目录没有进入合法目录
	if (remotePath.size() < 2 || remotePath[remotePath.size()-2] != '*') {
		QMessageBox::warning(this, "错误", "你没有这个项目的上传权限", QMessageBox::Yes);
		return;
	}
	string projname = remotePath.substr(1, remotePath.size()-3);
	emit addUploadTask(localPath, projname);
	emit appendHistory(QString("添加任务：上传 %1 到项目 %2\n").arg(get_file_name(localPath).c_str()).arg(projname.c_str()));
	QMessageBox::information(this, "添加成功", QString("添加任务：上传 %1 到项目 %2").arg(get_file_name(localPath).c_str()).arg(projname.c_str()),
		QMessageBox::Yes);
}

void UploadWidget::createDownloadTaskSlot(string localPath, string remotePath) {
	qDebug() << localPath.c_str() << " " << remotePath.c_str();
	if (isDir(remotePath.c_str())) {
		QMessageBox::warning(this, "错误", "不能下载文件夹", QMessageBox::Yes);
		return;
	}
	//如果没有选中文件
	if (remotePath == "") {
		QMessageBox::warning(this, "错误", "请选择要下载的文件", QMessageBox::Yes);
		return;
	}
	int slashPos = remotePath.find('/', 1);
	//如果远程目录没有进入合法目录
	if (slashPos == -1) {
		QMessageBox::warning(this, "错误", "你没有这个项目的下载权限", QMessageBox::Yes);
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
	emit appendHistory(QString("添加任务：下载 %1 项目文件 %2 到本地路径 %3\n").arg(projname.c_str()).arg(filename.c_str()).arg(localPath.c_str()));
	QMessageBox::information(this, "添加成功", QString("添加任务：下载 %1 项目文件 %2 到本地路径 %3\n").arg(projname.c_str()).arg(filename.c_str()).arg(localPath.c_str()),
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
