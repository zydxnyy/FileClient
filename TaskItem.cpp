#include "TaskItem.h"
#include <qmessagebox.h>

TaskItem::TaskItem(OP_TYPE op, const string& filename, size_t filesize, QListWidgetItem* p, const string& path, int typeId, const string& projName, QWidget* parent):
	QWidget(parent), op(op), filename(filename), filesize(filesize), pause(false), stop(false), start_time(time(NULL)), pWidgetItem(p), path(path),typeId(typeId), projectName(projName)
{

	ui.setupUi(this);
	if (op == UPLOAD) ui.iconLabel->setPixmap(QPixmap("pic/upload.png"));
	else ui.iconLabel->setPixmap(QPixmap("pic/download.png"));
	timeElapsed = 0;
	ui.stopBtn->setIcon(QIcon("pic/stop.png"));
	ui.pauseBtn->setIcon(QIcon("pic/pause.png"));

	if (filesize < 1024) ui.filenameLabel->setText(QString("%1:%2B").arg(filename.c_str()).arg(filesize));
	else if (filesize < 1024*1024) ui.filenameLabel->setText(QString("%1:%2K").arg(filename.c_str()).arg(QString::number((double)filesize / 1024, 'f', 2)));
	else if (filesize < 1024*1024*1024) ui.filenameLabel->setText(QString("%1:%2M").arg(filename.c_str()).arg(QString::number((double)filesize / 1024 / 1024, 'f', 2)));
	else  ui.filenameLabel->setText(QString("%1:%2G").arg(filename.c_str()).arg(QString::number((double)filesize / 1024 / 1024 / 1024, 'f', 2)));

	connect(this, SIGNAL(update_speed(double, int)), this, SLOT(update_speed_slot(double, int)));
	connect(this, SIGNAL(update_pb(int)), this, SLOT(update_pb_slot(int)));
	connect(this, SIGNAL(complete(int)), this, SLOT(complete_slot(int)));
	connect(this, SIGNAL(updateFilesize(size_t)), this, SLOT(updateFilesizeSlot(size_t)));
	// fileHash = hashFile(path.c_str());
}


TaskItem::~TaskItem()
{
}

void TaskItem::updateFilesizeSlot(size_t filesize) {
	if (filesize < 1024) ui.filenameLabel->setText(QString("%1:%2B").arg(filename.c_str()).arg(filesize));
	else if (filesize < 1024 * 1024) ui.filenameLabel->setText(QString("%1:%2K").arg(filename.c_str()).arg(QString::number((double)filesize / 1024, 'f', 2)));
	else if (filesize < 1024 * 1024 * 1024) ui.filenameLabel->setText(QString("%1:%2M").arg(filename.c_str()).arg(QString::number((double)filesize / 1024 / 1024, 'f', 2)));
	else  ui.filenameLabel->setText(QString("%1:%2G").arg(filename.c_str()).arg(QString::number((double)filesize / 1024 / 1024 / 1024, 'f', 2)));

}

void TaskItem::start()
{
	std::thread t{ &TaskItem::task, this };
	t.detach();
}

int TaskItem::toggleSlot()
{
	if (pause) {
		ui.pauseBtn->setIcon(QIcon("pic/pause.png"));
	}
	else {
		ui.pauseBtn->setIcon(QIcon("pic/play.png"));
	}
	pause = !pause;
	return 0;
}

int TaskItem::stopSlot()
{
	stop = true;
	return 0;
}


int TaskItem::update_speed_slot(double speed, int remain_sec) {
	ui.speedLabel->setText(QString("速度:") + QString::number(speed/8, 'f', 2) + QString("MB/s"));
	if (!pause) timeElapsed += difftime(time(NULL), record_time);
	//qDebug() << timeElapsed << " " << difftime(time(NULL), record_time);
	int tmp = timeElapsed;
	int hour = tmp / 3600; tmp %= 3600;
	int mins = tmp / 60; tmp %= 60;
	int sec = tmp;
	ui.elapsedTimelabel->setText(QString("用时: %1:%2:%3").arg(hour).arg(mins).arg(sec));
	if (!pause) {
		if (remain_sec >= 0) {
			hour = remain_sec / 3600; remain_sec %= 3600;
			mins = remain_sec / 60; remain_sec %= 60;
			sec = remain_sec;
			ui.remainTimeLabel->setText(QString("剩余: %1:%2:%3").arg(hour).arg(mins).arg(sec));
		}
		else {
			ui.remainTimeLabel->setText(QString("剩余: -:-:-"));
		}
	}
	else {
		ui.remainTimeLabel->setText(QString("剩余: -:-:-"));
		ui.speedLabel->setText(QString("速度:") + QString::number(0, 'f', 2) + QString("MB/s"));
	}
	record_time = time(NULL);
	return 0;
}

int TaskItem::update_pb_slot(int pct) {
	if (pct > 100) pct = 100;
	ui.progressBar->setValue(pct);
	return 0;
}


int TaskItem::complete_slot(int status) {
	end_time = time(NULL);
	qDebug() << "Complete status = " << status;
	emit done(this, pWidgetItem, status);
	return 0;
}
