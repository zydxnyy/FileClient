#include "FileClient.h"

FileClient::FileClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	for (int i = 0; i < 5; ++i) {
		if (get_projects() != -1) break;
		else if (i == 4) {
			QMessageBox::warning(NULL, "ALL WARNING", "��ȡԶ��Ŀ¼ʧ��");
			exit(-1);
		}
	}

	uploadWidget = new UploadWidget(&proteinProjects, &drugProjects, &animalProjects, this);
	taskWidget = new TaskWidget(this);
	historyWidget = new HistoryWidget(this);
	ui.tabWidget->addTab(uploadWidget, QString("���"));
	ui.tabWidget->addTab(taskWidget, QString("����"));
	ui.tabWidget->addTab(historyWidget, QString("��ʷ��¼"));

	QAction* action1 = new QAction("ˢ��");
	QAction* action2 = new QAction("������֤");
	QAction* action3 = new QAction("�л��û�");
	QAction* action4 = new QAction("�˳�");
	ui.mainToolBar->addAction(action1);
	ui.mainToolBar->addAction(action2);
	ui.mainToolBar->addAction(action3);
	ui.mainToolBar->addAction(action4);
	connect(action1, SIGNAL(triggered(bool)), this, SLOT(refresh()));
	connect(action2, SIGNAL(triggered(bool)), this, SLOT(reVerify()));
	connect(action3, SIGNAL(triggered(bool)), this, SLOT(switchUser()));
	connect(action4, SIGNAL(triggered(bool)), this, SLOT(exitExe()));

	connect(uploadWidget, SIGNAL(addUploadTask(const string&, const int&, const string&, DspyTaskItem*)), taskWidget, SLOT(addUploadTask(const string&, const int&, const string&, DspyTaskItem*)));
	connect(uploadWidget, SIGNAL(addDownloadTask(const int&, const string&, const string&, const string&, DspyTaskItem*)), taskWidget, SLOT(addDownloadTask(const int&, const string&, const string&, const string&, DspyTaskItem*)));
	connect(uploadWidget, SIGNAL(appendHistory(QString&)), historyWidget, SLOT(appendHistory(QString&)));
	connect(taskWidget, SIGNAL(appendHistory(QString&)), historyWidget, SLOT(appendHistory(QString&)));
	connect(taskWidget, SIGNAL(updateFileDir(string, QString&, MyFile*)), this, SLOT(updateFileDir(string, QString&, MyFile*)));
	connect(uploadWidget, SIGNAL(takeFile(string, string, string)), this, SLOT(takeFile(string, string, string)));
	//for (int i = 0; i < self_projects.size(); ++i) {
	//	Proj* p = self_projects[i];
	//	qDebug() << p->name.c_str() << endl;
	//	for (int j = 0; j < p->files.size(); ++j) {
	//		qDebug() << p->files[j].name.c_str() << " " << p->files[j].size << endl;
	//	}
	//}
}

int FileClient::get_projects() {
	proteinProjects.clear();
	drugProjects.clear();
	animalProjects.clear();
	string email = my_email;
	string token = my_token;
	if (email.empty() || token.empty()) {
		QMessageBox::warning(NULL, "WARNING", QString("�û���Ϣ���������µ�½"));
		this->close();
	}

	Py_Ret rtn = get_all_project(email, token);
		//string result = PyString_AsString(pRet);
	string& result = rtn.str;
	int status = rtn.status;
	if (status!=0) {
		QMessageBox::warning(NULL, "ALL WARNING", QString(result.c_str()));
		return -1;
	}
	else {
		//QMessageBox::information(NULL, "OK", QString(result));
		Json::Value vvv;
		qDebug() << result.c_str() << endl;
		if (json_parse(result, vvv)) {
			Json::Value root;
			//ȡ����������Ŀ����
			root = vvv["Protein"];
			for (int i = 0; i < root.size(); ++i) {
				Proj* proj = new Proj;
				proj->name = root[i]["name"].asCString();
				proj->uid = root[i]["user"].asInt();
				proj->typeId = PROTEIN;
				Json::Value pdata = root[i]["pdata"];
				for (int i = 0; i < pdata["data"].size(); ++i) {
					string filename = pdata["data"][i]["name"].asCString();
					unsigned int filesize = pdata["data"][i]["size"].asUInt();
					string email = pdata["data"][i]["email"].asCString();
					unsigned int created = pdata["data"][i]["created"].asUInt();
					string projname = pdata["data"][i]["projname"].asCString();
					string fileHash = pdata["data"][i]["fileHash"].asCString();
					string path = "/Protein/" + projname + "/" + filename;
					proj->files.push_back(MyFile(false, PROTEIN, projname, filename, filesize, created, email, path, fileHash));
				}
				proteinProjects.push_back(proj);
			}
			//ȥ��ҩ����Ŀ����
			root = vvv["Drug"];
			for (int i = 0; i < root.size(); ++i) {
				Proj* proj = new Proj;
				proj->name = root[i]["name"].asCString();
				proj->uid = root[i]["user"].asInt();
				proj->typeId = DRUG;
				Json::Value pdata = root[i]["pdata"];
				for (int i = 0; i < pdata["data"].size(); ++i) {
					string filename = pdata["data"][i]["name"].asCString();
					unsigned int filesize = pdata["data"][i]["size"].asUInt();
					string email = pdata["data"][i]["email"].asCString();
					unsigned int created = pdata["data"][i]["created"].asUInt();
					string projname = pdata["data"][i]["projname"].asCString();
					string fileHash = pdata["data"][i]["fileHash"].asCString();
					string path = "/Drug/" + projname + "/" + filename;
					proj->files.push_back(MyFile(false, DRUG, projname, filename, filesize, created, email, path, fileHash));
				}
				drugProjects.push_back(proj);
			}
			//ȡ��������Ŀ����
			root = vvv["Animal"];
			for (int i = 0; i < root.size(); ++i) {
				Proj* proj = new Proj;
				proj->name = root[i]["name"].asCString();
				proj->uid = root[i]["user"].asInt();
				proj->typeId = ANIMAL;
				Json::Value pdata = root[i]["pdata"];
				for (int i = 0; i < pdata["data"].size(); ++i) {
					string filename = pdata["data"][i]["name"].asCString();
					unsigned int filesize = pdata["data"][i]["size"].asUInt();
					string email = pdata["data"][i]["email"].asCString();
					unsigned int created = pdata["data"][i]["created"].asUInt();
					string projname = pdata["data"][i]["projname"].asCString();
					string fileHash = pdata["data"][i]["fileHash"].asCString();
					string path = "/Animal" + projname + "/" + filename;
					proj->files.push_back(MyFile(false, ANIMAL, projname, filename, filesize, created, email, path, fileHash));
				}
				animalProjects.push_back(proj);
			}
		}
	}

	return 0;
}

void FileClient::takeFile(string type, string projname, string filename)
{
	vector<Proj*>* p;

	if (type == TYPE[0]) p = &proteinProjects;
	else if (type == TYPE[1]) p = &drugProjects;
	else if (type == TYPE[2]) p = &animalProjects;
	else return;

	for (int i = 0; i < p->size(); ++i) {
		if (p->at(i)->name == projname) {
			File_Container::iterator itr = p->at(i)->files.begin();
			for (itr; itr != p->at(i)->files.end(); ++itr) {
				if (itr->filename == filename) {
					p->at(i)->files.erase(itr);
					break;
				}
			}
		}
	}
	this->uploadWidget->refreshDir();
}

void FileClient::refresh()
{
	this->setDisabled(true);
	for (int i = 0; i < 5; ++i) {
		if (get_projects() != -1) break;
		else {
			QMessageBox::warning(NULL, "ALL WARNING", "ˢ��ʧ��");
		}
	}
	this->uploadWidget->refreshDir();
	//QMessageBox::warning(NULL, "ALL WARNING", "ˢ�³ɹ�");
	this->setEnabled(true);
}

void FileClient::reVerify()
{
	Login* l = new Login(this);
	l->exec();
	//refresh();
}

void FileClient::switchUser()
{
	Login* l = new Login(this);
	l->exec();
	refresh();
}

void FileClient::exitExe()
{
	if (QMessageBox::warning(this, "�������˳�", "ȷ��Ҫ�˳���", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
		this->close();
}

void FileClient::updateFileDir(string type, QString& _projname, MyFile* pfile) {
	if (pfile == nullptr) {
		this->uploadWidget->refreshDir();
		return;
	}

	string projname = _projname.toStdString();

	vector<Proj*>* p;

	if (type == TYPE[0]) p = &proteinProjects;
	else if (type == TYPE[1]) p = &drugProjects;
	else if (type == TYPE[2]) p = &animalProjects;
	else return;

	for (int i = 0; i < p->size(); ++i) {
		if (p->at(i)->name == projname) {
			p->at(i)->files.push_back(*pfile);
			break;
		}
	}
	this->uploadWidget->refreshDir();
}