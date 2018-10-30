#include "RemoteExplorer.h"
#include <qmessagebox.h>
#include <qmenu.h>
#include "FileProp.h"

RemoteExplorer::RemoteExplorer(Proj_Container* proteinProjects, Proj_Container* drugProjects, Proj_Container* animalProjects, QWidget* parent):
	MyExplorer(parent), proteinProjects(proteinProjects), drugProjects(drugProjects), animalProjects(animalProjects), setting("win.ini", QSettings::IniFormat)
{
	updateFileList();
	connect(ui.listWidget, SIGNAL(acceptFileName(QString)), this, SLOT(acceptFileName(QString)));
	connect(ui.listWidget, SIGNAL(acceptUrl(QUrl)), this, SLOT(acceptUrl(QUrl)));
	ui.pathEdit->setText(setting.value("remotePath", "C:/").toString());
	enterPress();
}


RemoteExplorer::~RemoteExplorer()
{
	setting.setValue("remotePath", QString(path.c_str()));
}

bool RemoteExplorer::validPath() {
	string p = ui.pathEdit->text().toStdString();
	int slashCnt = 0;
	string type, projectname;
	int slashPos = -1;
	for (int i = 0; i < p.size(); ++i) {
		if (p.at(i) == '/') ++slashCnt;
	}
	switch (slashCnt) {
	case 1:
		/* 根目录 */
		if (p.size() != 1) return false;
		return true;
	case 2:
		if (p.front() != '/' || p.back() != '/') return false;
		type = p.substr(1, p.size() - 2);
		//不属于三类
		if (type != TYPE[0] && type != TYPE[1] && type != TYPE[2]) return false;
		return true;
	case 3:
		if (p.front() != '/' || p.back() != '/') return false;
		slashPos = p.find('/', 1);
		type = p.substr(1, slashPos - 1);
		projectname = p.substr(slashPos + 1, p.size() - slashPos - 2);
		if (type == TYPE[0]) projects = proteinProjects;
		else if (type == TYPE[1]) projects = drugProjects;
		else if (type == TYPE[2]) projects = animalProjects;
		else return false;
		//没有找到项目名
		for (int i = 0; i < projects->size(); ++i) if (projectname == projects->at(i)->name) return true;
		return false;
	default:
		return false;
	}
}

void RemoteExplorer::getFileList()
{
	int slashCnt = 0;
	int typeId;
	string type, projname;
	int slashPos = -1;
	for (int i = 0; i < path.size(); ++i) {
		if (path.at(i) == '/') ++slashCnt;
	}
	//根目录，显示所有的种类
	if (slashCnt == 1) {
		for (int i = 0; i < 3; ++i) {
			type = TYPE[i];
			int filesize = 0;
			bool isDir = true;
			fileList.push_back(MyFile(isDir, NO_TYPE, "", type, filesize, 0, "*", "/" + type + "/", "*"));
		}
	}
	//二级目录，显示type类型下所有的project
	else if (slashCnt == 2) {
		type = path.substr(1, path.size() - 2);
		if (type == TYPE[0]) { projects = proteinProjects; typeId = PROTEIN; }
		else if (type == TYPE[1]) { projects = drugProjects; typeId = DRUG; }
		else if (type == TYPE[2]) { projects = animalProjects; typeId = ANIMAL; }
		else return;
		for (int i = 0; i < projects->size(); ++i) {
			string projname = projects->at(i)->name;
			int filesize = 0;
			bool isDir = true;
			MyFile f(isDir, typeId, "", projname, filesize, 0, "*", "/" + projname + "/", "*");
			if (my_uid == projects->at(i)->uid) f.extra = 1;
			fileList.push_back(f);
		}
	}
	//三级目录，显示project里的文件
	else {
		slashPos = path.find('/', 1);
		type = path.substr(1, slashPos - 1);
		projname = path.substr(slashPos + 1, path.size() - 2 - slashPos);
		if (type == TYPE[0]) { projects = proteinProjects; typeId = PROTEIN; }
		else if (type == TYPE[1]) { projects = drugProjects; typeId = DRUG; }
		else if (type == TYPE[2]) { projects = animalProjects; typeId = ANIMAL; }
		else return;
		qDebug() << "Type=" << type.c_str() << "projname=" << projname.c_str();
		for (int i = 0; i < projects->size(); ++i) {
			if (projname != projects->at(i)->name) continue;

			for (int j = 0; j < projects->at(i)->files.size(); ++j) {
				bool isDir = false;
				string projname = projects->at(i)->files[j].projname;
				string filename = projects->at(i)->files[j].filename;
				int filesize = projects->at(i)->files[j].filesize;
				time_t created = projects->at(i)->files[j].uploadtime;
				string email = projects->at(i)->files[j].email;
				string path = projects->at(i)->files[j].path;
				string fileHash = projects->at(i)->files[j].fileHash;
				fileList.push_back(MyFile(false, typeId, projname, filename, filesize, created, email, path, fileHash));
			}
			break;
		}
	}
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

	int slashCnt = 0;
	int typeId;
	string type, projname;
	Proj* cur = NULL;
	int slashPos = -1;
	for (int i = 0; i < path.size(); ++i) {
		if (path.at(i) == '/') ++slashCnt;
	}
	//只有在项目文件夹下才能删除文件
	if (slashCnt != 3) {
		QMessageBox::warning(this, "没有权限", "您没有这个目录的删除权限", QMessageBox::Yes);
		return;
	}
	string filename = item->text().toStdString();
	slashPos = path.find('/', 1);
	type = path.substr(1, slashPos - 1);
	projname = path.substr(slashPos + 1, path.size() - 2 - slashPos);
	if (type == TYPE[0]) { projects = proteinProjects; typeId = PROTEIN; }
	else if (type == TYPE[1]) { projects = drugProjects; typeId = DRUG; }
	else if (type == TYPE[2]) { projects = animalProjects; typeId = ANIMAL; }
	else return;

	int sel = -1;
	for (int i = 0; i < projects->size(); ++i) {
		if (projname == projects->at(i)->name) {
			cur = projects->at(i);
			for (int j = 0; j < projects->at(i)->files.size(); ++j) {
				if (projects->at(i)->files.at(j).filename == filename) {
					sel = j;
					break;
				}
			}
			break;
		}
	}

	if (cur->files.at(sel).extra!=1) {
		QMessageBox::warning(this, "没有权限", "您没有这个目录的删除权限", QMessageBox::Yes);
		return;
	}
	if (QMessageBox::warning(this, "警告", QString("即将删除 %1 ").arg(item->text()), QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) return;
	struct addrinfo hints, *peer, *local;
	qDebug() << "DEL" << path.c_str() << filename.c_str() << projname.c_str();

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
	FileRequest msg((char)DEL, my_email.c_str(), my_token.c_str(), TYPE[typeId].c_str(), projname.c_str(), filename.c_str(), 0);
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
		emit takeFile(type, projname, filename);
	}
	else {
		QMessageBox::warning(this, "", "删除失败\n" + QString(rpy.extra), QMessageBox::Yes);
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