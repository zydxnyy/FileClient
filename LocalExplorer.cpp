#include "LocalExplorer.h"
#include <qcombobox.h>
#include <qdebug.h>
#include <qmenu.h>
#include <qsettings.h>

LocalExplorer::LocalExplorer(QWidget* parent) :drive("C:"), setting("win.ini", QSettings::IniFormat),
	MyExplorer(parent, "C:/")
{
	updateFileList();
	connect(ui.listWidget, SIGNAL(acceptFileName(QString)), this, SLOT(acceptFileName(QString)));
	connect(ui.listWidget, SIGNAL(acceptUrl(QUrl)), this, SLOT(acceptUrl(QUrl)));
	ui.pathEdit->setText(setting.value("localPath", "C:/").toString());
	enterPress();
}


LocalExplorer::~LocalExplorer()
{
	setting.setValue("localPath", QString(path.c_str()));
	qDebug() << path.c_str();
}

void LocalExplorer::getFileList()
{
	//显示所有系统盘盘
	if (path.empty()) {
		QFileInfoList list = drives->drives();
		for (int i = 0; i < list.size(); ++i) {
			fileList.push_back(MyFile(list[i].isDir(), NO_TYPE, "", list[i].filePath().mid(0, list[i].filePath().size()-1).toStdString(), list[i].size(), list[i].created().toTime_t(), "*", list[i].absoluteFilePath().toStdString(), "*", true));
		}
		return;
	}

	//qDebug() << (drive + path).c_str();
	QDir* dir = new QDir();
	dir->cd(path.c_str());
	dir->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries | QDir::Drives);
	dir->setSorting(QDir::DirsFirst | QDir::Name | QDir::Time);
	QFileInfoList list = dir->entryInfoList();
	for (int i = 0; i < list.size(); ++i) {
		if (hasSuffix(list[i].fileName().toStdString(), ".ft.nc")) continue;
		if(list[i].isDir()) fileList.push_back(MyFile(list[i].isDir(), NO_TYPE, "*", list[i].fileName().toStdString(), list[i].size(), list[i].created().toTime_t(), "*", list[i].absoluteFilePath().toStdString(), "*"));
		else  fileList.push_back(MyFile(list[i].isDir(), NO_TYPE, "*", list[i].fileName().toStdString(), list[i].size(), list[i].created().toTime_t(), "*", list[i].absoluteFilePath().toStdString(), ""));
	}
}

string LocalExplorer::getDirPath()
{
	return path;
}

string LocalExplorer::getFilePath()
{
	int row = ui.listWidget->currentRow();
	if (row != -1) {
		string filename = fileList[row].filename;
		return path + filename;
	}
	return "";
}

int LocalExplorer::indexChangedSlot(int index) {
	//qDebug() << "indexChangedSlot" << " " << index << endl;
	//QFileInfoList list = drives->drives();
	//drive = list[index].filePath().toStdString();
	//clearHistory();
	//path = "/";
	//history.push(path);
	//updateFileList();
	return 0;
}


void LocalExplorer::acceptFileName(QString filename) {
	qDebug() << "Accept filename = " << filename;
	//QMessageBox::information(this, "未完成", "下载文件：" + filename, QMessageBox::Yes);

	emit dragFileDownload(filename.toStdString());
}


void LocalExplorer::acceptUrl(QUrl url) {
	//qDebug() << "Accept url = " << url;
}

void LocalExplorer::menu(QPoint point)
{
	QMenu *cmenu = new QMenu(ui.listWidget);
	item = ui.listWidget->itemAt(point);

	//如果右键点击的是菜单项
	if (item != NULL) {
		QAction *action1 = cmenu->addAction("上传");

		QAction *action2 = cmenu->addAction("打开");

		QAction *action3 = cmenu->addAction("删除");

		QAction *action4 = cmenu->addAction("属性");

		connect(action1, SIGNAL(triggered(bool)), this, SLOT(uploadFile(bool)));

		connect(action2, SIGNAL(triggered(bool)), this, SLOT(openFile(bool)));

		connect(action3, SIGNAL(triggered(bool)), this, SLOT(delFile(bool)));

		connect(action4, SIGNAL(triggered(bool)), this, SLOT(openProperty(bool)));

		cmenu->exec(QCursor::pos());
	}
	//如果右键空白处
	else {

	}
}

bool LocalExplorer::validPath() {
	QString p = ui.pathEdit->text().replace('\\', '/');
	if (p.isEmpty()) return true;
	if (p.back() != '/') return false;
	return QFileInfo(p).isDir();
}

void LocalExplorer::openFile(bool)
{
	QString pathname = QString::fromStdString(getDirPath()) + item->text();
	if (!QDesktopServices::openUrl(QUrl::fromLocalFile(pathname))) {
		QMessageBox::warning(this, "失败", "文件打开失败", QMessageBox::Yes);
	}
}

void LocalExplorer::delFile(bool)
{
	if (QMessageBox::warning(this, "警告", QString("即将删除 %1 ").arg(item->text()), QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) return;
	string filename = getDirPath() + item->text().toStdString();
	QString pathname = QString::fromStdString(filename);
	QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
	std::string name = code->fromUnicode(pathname).data();

	qDebug() << name.c_str();
	if (!remove(name.c_str())) {
		updateFileList();
	}
	else {
		QMessageBox::warning(this, "失败", "删除文件失败");
	}
}

void LocalExplorer::enterDirSlot(QModelIndex index) {
	int row = index.row();
	if (row < 0) return;
	if (!fileList[row].isDir) {
		item = ui.listWidget->item(row);
		openFile(true);
	}
	else {
		enterDir(fileList[row].filename);
	}
}

void LocalExplorer::uploadFile(bool)
{
	emit menuFileUpload(item->text().toStdString());
}

void LocalExplorer::openProperty(bool) {
	string filename = item->text().toStdString();
	for (int i = 0; i < fileList.size(); ++i) {
		if (fileList.at(i).filename == filename) {
			qDebug() << "Open p of " << filename.c_str() << fileList.at(i).path.c_str() << fileList.at(i).fileHash.c_str();
			FileProp* p = new FileProp(fileList.at(i));
			p->show();
			break;
		}
	}
}
