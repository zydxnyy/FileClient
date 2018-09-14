#include "HistoryWidget.h"



HistoryWidget::HistoryWidget(QWidget* parent):
	QWidget(parent)
{
	ui.setupUi(this);
}


HistoryWidget::~HistoryWidget()
{
}

void HistoryWidget::appendHistory(QString& text) {
	ui.textEdit->append(text);
}
