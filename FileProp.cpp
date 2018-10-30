#include "FileProp.h"
#include <thread>
#include "udt.h"


FileProp::FileProp(MyFile file, QDialog* parent) :
	QDialog(parent)
{
	ui.setupUi(this);
	ui.filenameEdit->setText(QString::fromStdString(file.filename));
	ui.projnameEdit->setText(QString::fromStdString(file.projname));

	if (file.filesize < 1024) ui.filesizeEdit->setText(QString("%1B").arg(file.filesize));
	else if (file.filesize < 1024 * 1024) ui.filesizeEdit->setText(QString("%2K").arg(QString::number((double)file.filesize / 1024, 'f', 2)));
	else if (file.filesize < 1024 * 1024 * 1024) ui.filesizeEdit->setText(QString("%2M").arg(QString::number((double)file.filesize / 1024 / 1024, 'f', 2)));
	else  ui.filesizeEdit->setText(QString("%2G").arg(QString::number((double)file.filesize / 1024 / 1024 / 1024, 'f', 2)));

	string time;
	API_TimeToString(time, file.uploadtime);
	ui.createdEdit->setText(QString::fromStdString(time));
	ui.pathEdit->setText(QString::fromStdString(file.path));
	ui.emailEdit->setText(QString::fromStdString(file.email));
	qDebug() << "hash = " << file.fileHash.c_str();
	if (file.fileHash != "") {
		ui.fileHashEdit->setText(QString::fromStdString(file.fileHash.c_str()));
		//qDebug() << "!!!Hashing " << file.path.c_str();
	}
	else {
		ui.fileHashEdit->setText("MD5¼ÆËãÖÐ...");
		// ui.fileHashEdit->setText(QString::fromStdString(hashFile(file.path.c_str())));
		string filepath = file.path;
		std::thread t([this, filepath]() {
			ui.fileHashEdit->setText(QString::fromStdString(hashFile(filepath.c_str())));
		});
		t.detach();
		//qDebug() << "Hashing " << file.path.c_str();
	}
}


FileProp::~FileProp()
{
}
