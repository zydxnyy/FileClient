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

void RemoteExplorer::getFileList()
{
	int slashPos = path.find('/', 1);
	//��Ŀ¼����ʾ���е�project
	if (slashPos == -1) {
		for (int i = 0; i < pProjects->size(); ++i) {
			string projname = pProjects->at(i)->name;
			int filesize = 0;
			bool isDir = true;
			if (my_uid == pProjects->at(i)->uid) projname += "*";
			fileList.push_back(MyFile(isDir, "", projname, filesize, 0, "", "/"+projname+"/", "*"));
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
	//����Ҽ�������ǲ˵���
	if (item != NULL) {
		QAction *action1 = cmenu->addAction("����");

		QAction *action2 = cmenu->addAction("ɾ��");

		QAction *action3 = cmenu->addAction("����");

		connect(action1, SIGNAL(triggered(bool)), this, SLOT(downloadFile(bool)));

		connect(action2, SIGNAL(triggered(bool)), this, SLOT(delFile(bool)));

		connect(action3, SIGNAL(triggered(bool)), this, SLOT(openProperty(bool)));

		cmenu->exec(QCursor::pos());
	}
	//����Ҽ��հ״�
	else {

	}
}

void RemoteExplorer::delFile(bool)
{
	string remotePath = getDirPath();
	string filename = item->text().toStdString();
	if (remotePath.size() < 2 || remotePath.at(remotePath.size() - 2) != '*') {
		QMessageBox::warning(this, "û��Ȩ��", "��û�����Ŀ¼��ɾ��Ȩ��", QMessageBox::Yes);
		return;
	}
	if (QMessageBox::warning(this, "����", QString("����ɾ�� %1 ").arg(item->text()), QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) return;
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