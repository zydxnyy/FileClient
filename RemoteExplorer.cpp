#include "RemoteExplorer.h"
#include <qmessagebox.h>
#include <qmenu.h>
#include "FileProp.h"

RemoteExplorer::RemoteExplorer(Proj_Container* pProj, QWidget* parent):
	MyExplorer(parent)
{
	pProjects = pProj;
	updateFileList();
	connect(ui.listWidget, SIGNAL(acceptFileName(QString)), this, SLOT(acceptFileName(QString)));
	connect(ui.listWidget, SIGNAL(acceptUrl(QUrl)), this, SLOT(acceptUrl(QUrl)));
}


RemoteExplorer::~RemoteExplorer()
{
}

bool RemoteExplorer::validPath() {
	int slashCnt = 0;
	string type, projectname;
	int slashPos = -1;
	for (int i = 0; i < path.size(); ++i) {
		if (path.at(i) == '/') ++slashCnt;
	}
	switch (slashCnt) {
	case 1:
		/* 根目录 */
		if (path.size() != 1) return false;
		return true;
	case 2:
		if (path.front() != '/' || path.back() != '/') return false;
		type = path.substr(1, path.size() - 2);
		//不属于三类
		if (type != TYPE[0] && type != TYPE[1] && type != TYPE[2]) return false;
		return true;
	case 3:
		if (path.front() != '/' || path.back() != '/') return false;
		slashPos = path.find('/', 1);
		type = path.substr(1, slashPos - 1);
		projectname = path.substr(slashPos + 1, path.size() - slashPos - 2);
		//不属于三类
		if (type != TYPE[0] && type != TYPE[1] && type != TYPE[2]) return false;
		//没有找到项目名
		for (int i = 0; i < pProjects->size(); ++i) if (projectname == pProjects->at(i)->name) return true;
		return false;
	default:
		return false;
	}
}

void RemoteExplorer::getFileList()
{
	int slashPos = path.find('/', 1);
	//根目录，显示所有的project
	if (slashPos == -1) {
		for (int i = 0; i < pProjects->size(); ++i) {
			string projname = pProjects->at(i)->name;
			int filesize = 0;
			bool isDir = true;
			if (my_uid == pProjects->at(i)->uid) projname += "*";
			fileList.push_back(MyFile(isDir, "", projname, filesize, 0, "*", "/"+projname+"/", "*"));
		}
	}
	else {
		string projname = path.substr(1, slashPos-1);
		if (projname[projname.size() - 1] == '*') projname = projname.substr(0, projname.size() - 1);
		for (int i = 0; i < pProjects->size(); ++i) {
			if (projname != pProjects->at(i)->name) continue;

			for (int j = 0; j < pProjects->at(i)->files.size(); ++j) {
				bool isDir = false;
				string projname = pProjects->at(i)->files[j].projname;
				string filename = pProjects->at(i)->files[j].filename;
				int filesize = pProjects->at(i)->files[j].filesize;
				time_t created = pProjects->at(i)->files[j].uploadtime;
				string email = pProjects->at(i)->files[j].email;
				string path = pProjects->at(i)->files[j].path;
				string fileHash = pProjects->at(i)->files[j].fileHash;
				fileList.push_back(MyFile(false, projname, filename, filesize, created, email, path, fileHash));
			}
		}
	}
}

Proj * RemoteExplorer::getProject()
{
	int slashPos = path.find('/', 1);
	if (slashPos == -1) {
		return NULL;
	}
	else {
		string projname = path.substr(1, slashPos - 1);
		if (projname[projname.size() - 1] == '*') projname = projname.substr(0, projname.size() - 1);
		for (int i = 0; i < pProjects->size(); ++i) {
			if (projname != pProjects->at(i)->name) continue;

			for (int j = 0; j < pProjects->at(i)->files.size(); ++j) {

			}
		}
	}
	return nullptr;
}

void RemoteExplorer::acceptFileName(QString filename) {
	emit dragFileUpload(filename.toStdString());
}


void RemoteExplorer::acceptUrl(QUrl url) {
	emit dragUrlUpload(url);
}

void RemoteExplorer::menu(QPoint point) {
	QMenu *cmenu = new QMenu(ui.listWidget);
	item = ui.listWidget->itemAt(point);
	//如果右键点击的是菜单项
	if (item != NULL) {
		QAction *action1 = cmenu->addAction("下载");

		QAction *action2 = cmenu->addAction("删除");

		QAction *action3 = cmenu->addAction("属性");

		connect(action1, SIGNAL(triggered(bool)), this, SLOT(downloadFile(bool)));

		connect(action2, SIGNAL(triggered(bool)), this, SLOT(delFile(bool)));

		connect(action3, SIGNAL(triggered(bool)), this, SLOT(openProperty(bool)));

		cmenu->exec(QCursor::pos());
	}
	//如果右键空白处
	else {

	}
}

void RemoteExplorer::delFile(bool)
{
	string remotePath = getDirPath();
	string filename = item->text().toStdString();
	if (remotePath.size() < 2 || remotePath.at(remotePath.size() - 2) != '*') {
		QMessageBox::warning(this, "没有权限", "您没有这个目录的删除权限", QMessageBox::Yes);
		return;
	}
	if (QMessageBox::warning(this, "警告", QString("即将删除 %1 ").arg(item->text()), QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) return;
	string projname = remotePath.substr(1, remotePath.size() - 3);
	struct addrinfo hints, *peer, *local;
	qDebug() << "DEL" << remotePath.c_str() << filename.c_str() << projname.c_str();

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	UDTSOCKET fhandle = UDT::socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
	int timeout = 10000;
	UDT::setsockopt(fhandle, 0, UDT_SNDTIMEO, (char*)&timeout, sizeof(int));
	UDT::setsockopt(fhandle, 0, UDT_RCVTIMEO, (char*)&timeout, sizeof(int));
	if (0 != getaddrinfo(SERVER_IP, SERVER_PORT, &hints, &peer))
	{
		qDebug() << "incorrect server/peer address. " << SERVER_IP << ":" << SERVER_PORT << endl;
		return;
	}
	// connect to the server, implict bind
	if (UDT::ERROR == UDT::connect(fhandle, peer->ai_addr, peer->ai_addrlen))
	{
		qDebug() << "connect: " << UDT::getlasterror().getErrorMessage() << endl;
		return;
	}
	//FileRequest(char op, const char* email, const char* token, const char* project_name, const char* file_name, size_t file_size, size_t offset = 0)
	FileRequest msg((char)DEL, my_email.c_str(), my_token.c_str(), projname.c_str(), filename.c_str(), 0);
	if (UDT::ERROR == UDT::send(fhandle, (char*)&msg, sizeof(msg), 0)) {
		qDebug() << "send: " << UDT::getlasterror().getErrorMessage() << endl;
		return;
	}
	FileReply rpy;
	if (UDT::ERROR == UDT::recv(fhandle, (char*)&rpy, sizeof(rpy), 0)) {
		qDebug() << "recv: " << UDT::getlasterror().getErrorMessage() << endl;
		return;
	}
	if (rpy.error_flag == MY_NO_ERROR) {
		qDebug() << "Delete successfully";
		emit takeFile(projname, filename);
	}
	else {
		qDebug() << "DEL failed :" <<  rpy.extra << endl;
	}
}

void RemoteExplorer::downloadFile(bool)
{
	emit menuFileDownload(item->text().toStdString());
}

void RemoteExplorer::openProperty(bool) {
	string filename = item->text().toStdString();
	for (int i = 0; i < fileList.size(); ++i) {
		if (fileList.at(i).filename == filename) {
			FileProp* p = new FileProp(fileList.at(i));
			p->show();
		}
	}
}