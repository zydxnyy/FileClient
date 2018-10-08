#include "MyExplorer.h"
#include <qdir.h>
#include <qlistwidget.h>


MyExplorer::MyExplorer(QWidget* parent, string path):
	QWidget(parent), path(path)
{
	ui.setupUi(this);
	history.push(path);

	ui.nextBtn->setIcon(QIcon("pic/前进.png"));
	ui.prevBtn->setIcon(QIcon("pic/后退.png"));
	ui.outBtn->setIcon(QIcon("pic/上.png"));

}


MyExplorer::~MyExplorer()
{
}

void MyExplorer::getFileList()
{
	//qDebug() << "MyExplorer getFileList()" << endl;
}

void MyExplorer::clearHistory()
{
	history.clearHistory();
}

string MyExplorer::getDirPath() {
	return path;
}

string MyExplorer::getFilePath() {
	int row = ui.listWidget->currentRow();
	if (row != -1) {
		string filename = fileList[row].filename;
		return path + filename;
	}
	return "";
}

bool MyExplorer::isOutable()
{
	if (path.find('/', 1) == -1) return false;
	return true;
}

void MyExplorer::setBtnStatus()
{
	isOutable() ? ui.outBtn->setEnabled(true) : ui.outBtn->setEnabled(false);
	history.hasNext() ? ui.nextBtn->setEnabled(true) : ui.nextBtn->setEnabled(false);
	history.hasPrevious() ? ui.prevBtn->setEnabled(true) : ui.prevBtn->setEnabled(false);
}

QPixmap setFileIcon(MyFile file)
{
	if (file.isDrive) {
		return QPixmap("pic/drive.png");
	}
	if (file.isDir) {
		return QPixmap("pic/文件夹.png");
	}
	int dotPos = file.filename.find('.');
	string suffix = file.filename.substr(dotPos + 1);

	if (dotPos == -1) {
		return QPixmap("pic/文件.png");
	}
	else if (compareIgnoreCase(suffix, "txt")) {
		return QPixmap("pic/文本.png");
	}
	else if (compareIgnoreCase(suffix, "pdf")) {
		return QPixmap("pic/pdf.png");
	}
	else if (compareIgnoreCase(suffix, "img") || compareIgnoreCase(suffix, "png") ||
		compareIgnoreCase(suffix, "bmp") || compareIgnoreCase(suffix, "gif")) {
		return QPixmap("pic/图片.png");
	}
	else {
		return QPixmap("pic/文件.png");
	}
}

void MyExplorer::updateFileList()
{
	ui.pathEdit->setText(QString::fromStdString(path));
	fileList.clear();
	ui.listWidget->clear();
	getFileList();
	for (int i = 0; i < fileList.size(); ++i) {
		string name;
		if (fileList[i].extra == 1 && fileList[i].isDir) name = fileList[i].filename + "*";
		else name = fileList[i].filename;
		QListWidgetItem* pNewItem = new QListWidgetItem(QString::fromStdString(name));
		pNewItem->setIcon(QIcon(setFileIcon(fileList[i])));
		ui.listWidget->addItem(pNewItem);
	}
	setBtnStatus();
}

void MyExplorer::enterDir(const string & dirName)
{
	path.append(dirName + "/");
	history.push(path);
	updateFileList();
}

void MyExplorer::enterDirSlot(QModelIndex index) {
	int row = index.row();
	if (row < 0) return;
	if (!fileList[row].isDir) return;
	enterDir(fileList[row].filename);
}

void MyExplorer::outDir()
{
	path = path.substr(0, path.size() - 1);
	int slashPos = path.find_last_of('/');
	if (slashPos != -1) path = path.substr(0, slashPos+1);
	else path.clear();
	history.push(path);
	updateFileList();
}

void MyExplorer::next()
{
	path = history.next();
	updateFileList();
}

void MyExplorer::previous()
{
	path = history.previous();
	updateFileList();
}


void MyExplorer::enterPress() {
	QString p = ui.pathEdit->text();
	if (p.back() != '/' && p.back() != '\\') p.append('/');
	ui.pathEdit->setText(p);
	if (validPath()) {
		path = ui.pathEdit->text().replace('\\', "/").toStdString();
		history.push(path);
		updateFileList();
	}
	else {
		ui.pathEdit->setText(path.c_str());
	}
}