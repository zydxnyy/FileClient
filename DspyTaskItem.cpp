#include "DspyTaskItem.h"
#include <string>
#include <qdebug.h>

DspyTaskItem::DspyTaskItem(QListWidgetItem* p, std::string filename, QWidget *parent)
	: QWidget(parent), p(p)
{
	ui.setupUi(this);
	ui.filenameLabel->setText(QString::fromStdString(filename));
	isPause = false;
}

DspyTaskItem::~DspyTaskItem()
{
}

int DspyTaskItem::update_pb_slot(int pct) {
	ui.pctLabel->setText(QString("%1%").arg(pct));
	return 0;
}

int DspyTaskItem::complete_slot() {
	ui.pctLabel->setText(QString("%1%").arg(100));
	qDebug() << "CompleteSlot";
	emit done(p);
	return 0;
}
