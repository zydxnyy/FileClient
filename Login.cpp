#include "Login.h"
#include <qsettings.h>

Login::Login(QWidget *parent): QDialog(parent)
{
	ui.setupUi(this);
	QSettings* setting = new QSettings("win.ini", QSettings::IniFormat);
	bool rem = setting->value("remeberPassword").toBool();
	if (rem) {
		ui.checkBox->setChecked(true);
		QString email = setting->value("email", "").toString();
		QString password = setting->value("password", "").toString();
		ui.email_edit->setText(email);
		ui.password_edit->setText(password);
	}
}


Login::~Login()
{
}

int Login::login_slot()
{
	string email = ui.email_edit->text().toStdString();
	string password = ui.password_edit->text().toStdString();

	bool remeberPassword = ui.checkBox->isChecked();
	QSettings* setting = new QSettings("win.ini", QSettings::IniFormat);
	setting->setValue("remeberPassword", remeberPassword);


	//email = "123@qq.com";
	//password = "12345";


	if (email.empty() || password.empty()) {
		QMessageBox::warning(NULL, "WARNING", QString("邮箱或密码不能为空"));
		return -1;
	}

	Py_Ret rtn = login(email, password);
	int status = rtn.status;
	char* ret_str = (char*)rtn.str.c_str();
	int uid = rtn.extra;
	if (status == 0) {
		my_token = ret_str;
		my_uid = uid;
		my_email = email;

		//写入记录配置文件
		if (!remeberPassword) {
			setting->remove("email");
			setting->remove("password");
		}
		else {
			setting->setValue("email", email.c_str());
			setting->setValue("password", password.c_str());
		}

		//QMessageBox::information(NULL, "OK", QString(ret_str));
		accept();
	}
	else {
		QMessageBox::warning(NULL, "WARNING", QString(ret_str));
	}

	return 0;
}
