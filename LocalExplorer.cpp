#include "LocalExplorer.h"
#include <qcombobox.h>
#include <qdebug.h>
#include <qmenu.h>

LocalExplorer::LocalExplorer(QWidget* parent) :drive("C:"),
	MyExplorer(parent)
{
	updateFileList();
	box = new QComboBox(this);
	drives = new QDir();
	QFileInfoList list = drives->drives();
	for (int i = 0; i < list.size(); ++i) {
		box->addItem(QIcon("pic/drive.png"), list[i].filePath());
	}
	connect(box, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChangedSlot(int)));
	connect(ui.listWidget, SIGNAL(acceptFileName(QString)), this, SLOT(acceptFileName(QString)));
	connect(ui.listWidget, SIGNAL(acceptUrl(QUrl)), this, SLOT(acceptUrl(QUrl)));
	box->setGeometry(10, 20, 200, 30);
	box->show();
}


LocalExplorer::~LocalExplorer()
{
}

void LocalExplorer::getFileList()
{
	//qDebug() << (drive + path).c_str();
	QDir* dir = new QDir();
	dir->cd((drive + path).c_str());
	dir->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
	dir->setSorting(QDir::DirsFirst | QDir::Name);
	QFileInfoList list = dir->entryInfoList();
	for (int i = 0; i < list.size(); ++i) {
		if (hasSuffix(list[i].fileName().toStdString(), ".ft.nc")) continue;
		fileList.push_back(MyFile(list[i].isDir(), "", list[i].fileName().toStdString(), list[i].size(), list[i].created().toTime_t(), "*", list[i].absoluteFilePath().toStdString(), ""));
	}
}

string LocalExplorer::getDirPath()
{
	return drive + path;
}

string LocalExplorer::getFilePath()
{
	int row = ui.listWidget->currentRow();
	if (row != -1) {
		string filename = fileList[row].filename;
		return drive + path + filename;
	}
	return "";
}

int LocalExplorer::indexChangedSlot(int index) {
	//qDebug() << "indexChangedSlot" << " " << index << endl;
	drives = new QDir();
	QFileInfoList list = drives->drives();
	drive = list[index].filePath().toStdString();
	clearHistory();
	path = "/";
	history.push(path);
	updateFileList();
	return 0;
}


void LocalExplorer::acceptFileName(QString filename) {
	qDebug() << "Accept filename = " << filename;
	//QMessageBox::information(this, "δ���", "�����ļ���" + filename, QMessageBox::Yes);

	emit dragFileDownload(filename.toStdString());
}


void LocalExplorer::acceptUrl(QUrl url) {
	//qDebug() << "Accept url = " << url;
}

void LocalExplorer::menu(QPoint point)
{
	QMenu *cmenu = new QMenu(ui.listWidget);
	item = ui.listWidget->itemAt(point);

	//����Ҽ�������ǲ˵���
	if (item != NULL) {
		QAction *action1 = cmenu->addAction("�ϴ�");

		QAction *action2 = cmenu->addAction("��");

		QAction *action3 = cmenu->addAction("ɾ��");

		QAction *action4 = cmenu->addAction("����");

		connect(action1, SIGNAL(triggered(bool)), this, SLOT(uploadFile(bool)));

		connect(action2, SIGNAL(triggered(bool)), this, SLOT(openFile(bool)));

		connect(action3, SIGNAL(triggered(bool)), this, SLOT(delFile(bool)));

		connect(action4, SIGNAL(triggered(bool)), this, SLOT(openProperty(bool)));

		cmenu->exec(QCursor::pos());
	}
	//����Ҽ��հ״�
	else {

	}
}

void LocalExplorer::openFile(bool)
{
	QString pathname = QString::fromStdString(getDirPath()) + item->text();
	if (!QDesktopServices::openUrl(QUrl::fromLocalFile(pathname))) {
		QMessageBox::warning(this, "ʧ��", "�ļ���ʧ��", QMessageBox::Yes);
	}
}

void LocalExplorer::delFile(bool)
{
	if (QMessageBox::warning(this, "����", QString("����ɾ�� %1 ").arg(item->text()), QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) return;
	string filename = getDirPath() + item->text().toStdString();
	QString pathname = QString::fromStdString(filename);
	QTextCodec *code = QTextCodec::codecForName("GB2312");//�������·������
	std::string name = code->fromUnicode(pathname).data();

	qDebug() << name.c_str();
	if (!remove(name.c_str())) {
		updateFileList();
	}
	else {
		QMessageBox::warning(this, "ʧ��", "ɾ���ļ�ʧ��");
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
