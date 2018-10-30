#include "DspyTaskItem.h"
#include <string>
#include <qdebug.h>

DspyTaskItem::DspyTaskItem(QListWidgetItem* p, std::string filename, QWidget *parent)
	: QWidget(parent), p(p)
{
	ui.setupUi(this);
	ui.filenameLabel->setText(QString::fromStdString(filename));
	ui.closeBtn->hide();
	isPause = false;
}

DspyTaskItem::~DspyTaskItem()
{
}

int DspyTaskItem::update_pb_slot(int pct) {
	ui.pctLabel->setText(QString("%1%").arg(pct));
	return 0;
}

int DspyTaskItem::complete_slot(TaskItem*, QListWidgetItem*, int status) {

	if (status == MY_NO_ERROR) {
		ui.pctLabel->setText(QString("%1%").arg(100));
		emit done(p);
	}
	else {
		ui.closeBtn->show();
		ui.noteLabel->setText("´«ÊäÊ§°Ü");
	}
	return 0;
}

int DspyTaskItem::close_slot()
{
	emit done(p);
	return 0;
}
