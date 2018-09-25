#include "Login.h"
#include <qmovie.h>
#include <qsettings.h>

Login::Login(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
	QSettings* setting = new QSettings("win.ini", QSettings::IniFormat);
	bool rem = setting->value("remeberPassword", false).toBool();
	if (rem) {
		ui.checkBox->setChecked(true);
		QString email = setting->value("email", "").toString();
		QString password = setting->value("password", "").toString();
		ui.email_edit->setText(email);
		ui.password_edit->setText(password);
	}
	QMovie* gif = new QMovie("pic/loading3.gif");
	gif->setScaledSize(QSize(100, 100));
	ui.loadingLabel->setMovie(gif);
	gif->start();
	ui.loadingLabel->hide();

	connect(this, SIGNAL(loginDone(Py_Ret)), this, SLOT(loginDoneSlot(Py_Ret)));
}


Login::~Login()
{
}

int Login::login_slot()
{
	///
	accept();
	///

	ui.loadingLabel->show();
	this->setDisabled(true);

	string email = ui.email_edit->text().toStdString();
	string password = ui.password_edit->text().toStdString();

	bool remeberPassword = ui.checkBox->isChecked();
	QSettings* setting = new QSettings("win.ini", QSettings::IniFormat);

	//email = "123@qq.com";
	//password = "12345";


	if (email.empty() || password.empty()) {
		QMessageBox::warning(NULL, "WARNING", QString("��������벻��Ϊ��"));
		this->setEnabled(true);
		ui.loadingLabel->hide();
		return -1;
	}

	std::thread t{ [this, email, password, remeberPassword, setting] {
		Py_Ret rtn = login(email, password);
		int status = rtn.status;
		char* ret_str = (char*)rtn.str.c_str();
		int uid = rtn.extra;
		if (status == 0) {
			my_token = ret_str;
			my_uid = uid;
			my_email = email;

			//д���¼�����ļ�
			setting->setValue("remeberPassword", remeberPassword);
			if (!remeberPassword) {
				setting->remove("email");
				setting->remove("password");
			}
			else {
				setting->setValue("email", email.c_str());
				setting->setValue("password", password.c_str());
			}
			//emit loginDone(1);
			//QMessageBox::information(NULL, "OK", QString(ret_str));
			//accept();
		}
		else {
			//emit loginDone(0);
			//QMessageBox::warning(NULL, "WARNING", QString(ret_str));
		}
		emit loginDone(rtn);
	} };
	t.detach();

	return 0;
}

void Login::loginDoneSlot(Py_Ret ret) {
	if (ret.status == 0) {
		accept();
	}
	else {
		this->setEnabled(true);
		ui.loadingLabel->hide();
		QMessageBox::warning(NULL, "WARNING", QString(ret.str.c_str()));
	}
}
